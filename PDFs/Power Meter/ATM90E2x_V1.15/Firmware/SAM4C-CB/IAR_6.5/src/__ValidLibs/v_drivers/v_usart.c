// $asf_license$

/*! \file *********************************************************************
 *
 * \brief USART driver for SAM3.
 *
 * \par Purpose
 *
 * This file contains basic functions for the SAM3S USART, with support for all
 * modes, settings and clock speeds.
 *
 * \par Usage
 *
 * -# Enable the USART peripheral clock in the PMC.
 * -# Enable the required USART PIOs (see pio.h).
 * -# Configure the USART by calling usart_Configure.
 * -# Enable the transmitter and/or the receiver of the USART using
 *    usart_SetTransmitterEnabled and usart_SetReceiverEnabled.
 * -# Send data through the USART using the usart_write and
 *    usart_write_buffer methods.
 * -# Receive data from the USART using the usart_read and
 *    usart_read_buffer functions; the availability of data can be polled
 *    with usart_isDataAvailable.
 * -# Disable the transmitter and/or the receiver of the USART with
 *    usart_setTransmitterEnabled and usart_setReceiverEnabled.
 
 * - Compiler:           IAR EWARM and GNU GCC for SAM3
 * - Supported devices:  All SAM3 devices with a USART module can be used.
 * - AppNote:
 *
 * \author               Atmel Corporation: http://www.atmel.com \n
 *                       Support and FAQ: http://support.atmel.no/
 *
 ******************************************************************************/


// ****************************************************************************
// first release based on USART driver : //ERr USART driver
// ****************************************************************************



#include  "v_usart.h"

/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
extern "C" {
#endif
/**INDENT-ON**/
/// @endcond


/**
 * \brief Configure USART with the specified parameters.
 * The PMC are PIO must be configured first.
 *
 * \param usart Pointer to the USART peripheral to configure.
 * \param p_usart_opt Pointer to sam_usart_opt_t instance.
 *
 * \retval 0 Success.
 * \retval 1 Bad baud rate generator value.
 */
extern uint32_t usart_init( Usart *usart, const sam_usart_opt_t *p_usart_opt )
{
    uint32_t cd = 0;
	
    /* Reset and disable receiver & transmitter */
    usart->US_CR = US_CR_RSTRX | US_CR_RSTTX
                   | US_CR_RXDIS | US_CR_TXDIS;

    /* Check and configure baudrate */
    /* Asynchronous, no oversampling */
    
	cd = (p_usart_opt->dw_mck*10) / (p_usart_opt->dw_baudrate*16); //ERr
        cd = (cd%10<5?cd/10:cd/10+1);                               //ERr
        
	if (cd < 1 || cd > 65535)
		return 1;

    usart->US_BRGR = cd;
    /* Configure mode */
    //usart->US_MR = p_usart_opt->dw_mode;
    usart->US_MR = p_usart_opt->dw_mode | p_usart_opt->dw_chmode; //ERr

    
    /* Disable PDC channel */
#ifndef SAMA5 //ERr SAMA5
    usart->US_PTCR = US_PTCR_RXTDIS | US_PTCR_TXTDIS;
#endif //ERr SAMA5

    
    /* Enable receiver and transmitter */
    usart->US_CR = US_CR_RXEN | US_CR_TXEN;

	return 0;
}

/**
 * \brief Enable USART transmitter.
 *
 * \param usart Pointer to an USART peripheral.
 */
extern void usart_enable_tx( Usart *usart )
{
	/* Enable transmitter */ 
	usart->US_CR = US_CR_TXEN;
}

/**
 * \brief Disable USART transmitter.
 *
 * \param usart Pointer to an USART peripheral.
 */
extern void usart_disable_tx( Usart *usart )
{
	/* Disable transmitter */ 
	usart->US_CR = US_CR_TXDIS;
}

/**
 * \brief Immediately stop and disable USART transmitter.
 *
 * \param usart Pointer to an USART peripheral.
 */
extern void usart_reset_tx( Usart *usart )
{
    /* Reset transmitter */
    usart->US_CR = US_CR_TXDIS;
}

/**
 * \brief Enable USART receiver.
 *
 * \param usart Pointer to an USART peripheral.
 */
extern void usart_enable_rx( Usart *usart )
{
	/* Enable receiver */ 
	usart->US_CR = US_CR_RXEN;
}

/**
 * \brief Disable USART receiver.
 *
 * \param usart Pointer to an USART peripheral.
 */
extern void usart_disable_rx( Usart *usart )
{
	/* Disable receiver */ 
	usart->US_CR = US_CR_RXDIS;
}

/**
 * \brief Immediately stop and disable USART receiver.
 *
 * \param usart Pointer to an USART peripheral.
 */
extern void usart_reset_rx( Usart *usart )
{
    /* Reset receiver */
    usart->US_CR = US_CR_RXDIS;
}

/**
 * \brief Enable USART receiver and transmitter.
 *
 * \param usart Pointer to an USART peripheral.
 */
extern void usart_enable( Usart *usart )
{
    /* Enable receiver and transmitter */
    usart->US_CR = US_CR_RXEN | US_CR_TXEN;
}

/**
 * \brief Disable USART receiver and transmitter.
 *
 * \param usart Pointer to an USART peripheral.
 */
extern void usart_disable( Usart *usart )
{
    /* Disable receiver and transmitter */
    usart->US_CR = US_CR_RXDIS | US_CR_TXDIS;
}

/**
 * \brief Reset USART receiver and transmitter.
 *
 * \param usart Pointer to an USART peripheral.
 */
extern void usart_reset( Usart *usart )
{
    /* Reset and disable receiver & transmitter */
    usart->US_CR = US_CR_RSTRX | US_CR_RSTTX
                   | US_CR_RXDIS | US_CR_TXDIS;
}

/** \brief Enable USART interrupts.
 *
 *  \param usart pointer to an Usart instance.
 *  \param dw_sources interrupt sources bit map.
 */
extern void usart_enable_interrupt( Usart *usart,uint32_t dw_sources )
{
	usart->US_IER = dw_sources;
}

/** \brief Disable USART interrupts.
 *
 *  \param usart pointer to an Usart instance.
 *  \param dw_sources interrupt sources bit map.
 */
extern void usart_disable_interrupt( Usart *usart,uint32_t dw_sources )
{
	usart->US_IDR = dw_sources;
}

/** \brief Read USART interrupt mask.
 *
 *  \param usart pointer to an Usart instance.
 *
 *  \return The interrupt mask value.
 */
extern uint32_t usart_get_interrupt_mask( Usart *usart )
{
	return usart->US_IMR;
}

/**
 * \brief   Get current status.
 *
 * \param usart Pointer to an Usart instance.
 *
 * \return The current USART status.
 */
extern uint32_t usart_get_status( Usart *usart )
{
	return usart->US_CSR;
}

/** 
 * \brief Check if Transmit is Ready.
 * Check if Data has been loaded in US_THR and is waiting to be loaded in the Transmit Shift Register (TSR).
 *
 * \param usart Pointer to an Usart instance.
 *
 * \retval 0 Transmit is not ready, data pending.
 * \retval 1 Data has been transmitted.
 */
extern uint32_t usart_is_tx_ready( Usart *usart )
{
	return (usart->US_CSR & US_CSR_TXRDY) > 0;
}

/** 
 * \brief Check if Transmit Hold Register is empty.
 * Check if Last data written in US_THR has been loaded in TSR and last data loaded in TSR has been transmitted.
 *
 * \param usart Pointer to an Usart instance.
 *
 * \retval 0 Transmit is not emtpy.
 * \retval 1 Transmit is emtpy.
 */
extern uint32_t usart_is_tx_empty( Usart *usart )
{
	return (usart->US_CSR & US_CSR_TXEMPTY) > 0;
}

/** 
 * \brief Check if Received data is ready.
 * Check if Data has been received and loaded in US_RHR.
 *
 * \param usart Pointer to an Usart instance.
 *
 * \retval 0 No data has been received.
 * \retval 1 One data has been received.
 */
extern uint32_t usart_is_rx_ready( Usart *usart )
{
	return (usart->US_CSR & US_CSR_RXRDY) > 0;
}

#if (sam3s || sam3n)
/** 
 * \brief Check if one receive buffer is filled.
 *
 * \param usart Pointer to an Usart instance.
 *
 * \retval 0 Receive is still pending.
 * \retval 1 Receive complete.
 */
extern uint32_t usart_is_rx_buf_end( Usart *usart )
{
	return (usart->US_CSR & US_CSR_ENDRX) > 0;
}

/** 
 * \brief Check if one transmit buffer is sent out.
 *
 * \param usart Pointer to an Usart instance.
 *
 * \retval 0 Transmit is still pending.
 * \retval 1 Transmit complete.
 */
extern uint32_t usart_is_tx_buf_end( Usart *usart )
{
	return (usart->US_CSR & US_CSR_ENDTX) > 0;
}

/** \brief Check if both receive buffers are full.
 *
 *  \param usart Pointer to an Usart instance.
 *
 * \retval 0 Receive buffers are not full.
 * \retval 1 Receive buffers are full.
 */
extern uint32_t usart_is_rx_buf_full( Usart *usart )
{
	return (usart->US_CSR & US_CSR_RXBUFF) > 0;
}

/** 
 * \brief Check if both transmit buffers are sent out.
 *
 * \param usart Pointer to an Usart instance.
 *
 * \retval 0 Transmit buffer is not empty.
 * \retval 1 Transmit buffer is empty.
 */
extern uint32_t usart_is_tx_buf_empty( Usart *usart )
{
	return (usart->US_CSR & US_CSR_TXEMPTY) > 0;
}
#endif

/** 
 * \brief Write to USART Transmit Holding Register
 *
 * \param usart Pointer to an USART peripheral.
 * \param data Data to be sent.
 *
 * \retval 0 Success.
 * \retval 1 I/O Failure, USART is not ready.
 */
extern uint32_t usart_write( Usart *usart, const uint8_t data )
{
    /* Check if the transmitter is ready */
    if ( !(usart->US_CSR & US_CSR_TXRDY) )
		return 1;

    /* Send character */
    usart->US_THR = data ;
	return 0;
}

/** 
 * \brief Read from USART Receive Holding Register.
 *
 * \param usart Pointer to an USART peripheral.
 *
 * \retval 0 Success.
 * \retval 1 I/O Failure, USART is not ready.
 */
extern uint32_t usart_read( Usart *usart, uint8_t *data )
{
    /* Check if the receiver is ready */
    if ( (usart->US_CSR & US_CSR_RXRDY) == 0 )
		return 1;

	/* Read character */
    *data = usart->US_RHR ;
	return 0;
}

#if (sam3s || sam3n)
/** 
 * \brief Get PDC registers base address
 *
 * \param usart Pointer to an USART peripheral.
 *
 * \return PDC registers base for PDC driver to access.
 */
extern Pdc *usart_get_pdc_base( Usart *usart )
{
	if (usart == USART0)
		return PDC_USART0;
	if (usart == USART1)
		return PDC_USART1;

        else return 0;//ERr
}
#endif

/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
}
#endif
/**INDENT-ON**/
/// @endcond

