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
// first release based on UART driver : //ERr UART driver
// ****************************************************************************



#ifndef _V_USART_
#define _V_USART_

#include  "compiler.h"

/*! \brief Option list for USART peripheral initialize */
typedef struct sam_usart_opt {
	//! MCK for USART
	uint32_t dw_mck;
	//! Expected baud rate
	uint32_t dw_baudrate;
	//! Initialize value for USART mode register
	uint32_t dw_mode;
	//! Configure channel mode (Normal, Automatic, Local_loopback or Remote_loopback)
	uint32_t dw_chmode;
} sam_usart_opt_t;

/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
extern "C" {
#endif
/**INDENT-ON**/
/// @endcond

/**
 * \brief Configure USART with the specified parameters.
 *
 * \param usart Pointer to the USART peripheral to configure.
 * \param p_usart_opt Pointer to sam_usart_opt_t instance.
 *
 * \return 0 for OK.
 */
extern uint32_t usart_init( Usart *usart, const sam_usart_opt_t *p_usart_opt ) ;

/**
 * \brief Enable USART transmitter.
 *
 * \param usart Pointer to an USART peripheral.
 *
 * \return 0 for OK.
 */
extern void usart_enable_tx( Usart *usart ) ;

/**
 * \brief Disable USART transmitter.
 *
 * \param usart Pointer to an USART peripheral.
 *
 * \return 0 for OK.
 */
extern void usart_disable_tx( Usart *usart ) ;

/**
 * \brief Immediately stop and disable USART transmitter.
 *
 * \param usart Pointer to an USART peripheral.
 *
 * \return 0 for OK.
 */
extern void usart_reset_tx( Usart *usart ) ;

/**
 * \brief Enable USART receiver.
 *
 * \param usart Pointer to an USART peripheral.
 *
 * \return 0 for OK.
 */
extern void usart_enable_rx( Usart *usart ) ;

/**
 * \brief Disable USART receiver.
 *
 * \param usart Pointer to an USART peripheral.
 *
 * \return 0 for OK.
 */
extern void usart_disable_rx( Usart *usart ) ;

/**
 * \brief Immediately stop and disable USART receiver.
 *
 * \param usart Pointer to an USART peripheral.
 *
 * \return 0 for OK.
 */
extern void usart_reset_rx( Usart *usart ) ;

/**
 * \brief Enable USART receiver and transmitter.
 *
 * \param usart Pointer to an USART peripheral.
 *
 * \return 0 for OK.
 */
extern void usart_enable( Usart *usart ) ;

/**
 * \brief Disable USART receiver and transmitter.
 *
 * \param usart Pointer to an USART peripheral.
 *
 * \return 0 for OK.
 */
extern void usart_disable( Usart *usart ) ;

/**
 * \brief Reset USART receiver and transmitter.
 *
 * \param usart Pointer to an USART peripheral.
 *
 * \return 0 for OK.
 */
extern void usart_reset( Usart *usart ) ;

/** \brief Enable USART interrupts.
 *
 *  \param usart pointer to an Usart instance.
 *  \param dw_sources interrupt sources bit map.
 */
extern void usart_enable_interrupt( Usart *usart,uint32_t dw_sources ) ;

/** \brief Disable USART interrupts.
 *
 *  \param usart pointer to an Usart instance.
 *  \param dw_sources interrupt sources bit map.
 */
extern void usart_disable_interrupt( Usart *usart,uint32_t dw_sources ) ;

/** \brief Read USART interrupt mask.
 *
 *  \param usart pointer to an Usart instance.
 *
 *  \return The interrupt mask value.
 */
extern uint32_t usart_get_interrupt_mask( Usart *usart ) ;

/**
 * \brief   Get current status.
 *
 * \param usart Pointer to an Usart instance.
 *
 * \return The current USART status.
 */
extern uint32_t usart_get_status( Usart *usart ) ;

/** 
 * \brief Check if Transmit is Ready.
 * Check if Data has been loaded in USART_THR and is waiting to be loaded in the Transmit Shift Register (TSR).
 *
 * \param usart Pointer to an Usart instance.
 *
 * \return 0 for YES, others for NO.
 */
extern uint32_t usart_is_tx_ready( Usart *usart ) ;

/** 
 * \brief Check if Transmit Hold Register is empty.
 * Check if Last data written in USART_THR has been loaded in TSR and last data loaded in TSR has been transmitted.
 *
 * \param usart Pointer to an Usart instance.
 *
 * \return 0 for YES, others for NO.
 */
extern uint32_t usart_is_tx_empty( Usart *usart ) ;

/** 
 * \brief Check if Received data is ready.
 * Check if Data has been received and loaded in USART_RHR.
 *
 * \param usart Pointer to an Usart instance.
 *
 * \return 0 for YES, others for NO.
 */
extern uint32_t usart_is_rx_ready( Usart *usart ) ;

/** 
 * \brief Check if transmit is enabled.
 *
 * \param usart Pointer to an Usart instance.
 *
 * \return 0 for YES, others for NO.
 */
extern uint32_t usart_is_tx_enabled( Usart *usart ) ;

/**
 * \brief Check if receive is enabled.
 *
 * \param usart Pointer to an Usart instance.
 *
 * \return 0 for YES, others for NO.
 */
extern uint32_t usart_is_rx_enabled( Usart *usart ) ;

#if defined (sam3s) || defined (sam3n)
/** 
 * \brief Check if one receive buffer is filled.
 *
 * \param usart Pointer to an Usart instance.
 *
 * \return 0 for YES, others for NO.
 */
extern uint32_t usart_is_rx_buf_end( Usart *usart ) ;

/** 
 * \brief Check if one transmit buffer is sent out.
 *
 * \param usart Pointer to an Usart instance.
 *
 * \return 0 for YES, others for NO.
 */
extern uint32_t usart_is_tx_buf_end( Usart *usart ) ;

/** \brief Check if both receive buffers are full.
 *
 *  \param usart Pointer to an Usart instance.
 *
 *  \return 0 for YES, others for NO.
 */
extern uint32_t usart_is_rx_buf_full( Usart *usart ) ;

/** 
 * \brief Check if both transmit buffers are sent out.
 *
 * \param usart Pointer to an Usart instance.
 *
 * \return 0 for YES, others for NO.
 */
extern uint32_t usart_is_tx_buf_empty( Usart *usart ) ;
#endif

/** 
 * \brief Write to USART Transmit Holding Register
 * Before writing user should check if tx is ready (or empty).
 *
 * \param usart Pointer to an USART peripheral.
 * \param data Data to be sent.
 *
 * \return 0 if successful.
 */
extern uint32_t usart_write( Usart *usart, const uint8_t data ) ;

/** 
 * \brief Read from USART Receive Holding Register.
 * Before reading user should check if rx is ready.
 *
 * \param usart Pointer to an USART peripheral.
 *
 * \return 0 if successful.
 */
extern uint32_t usart_read( Usart *usart, uint8_t *data ) ;

#if defined (sam3s) || defined (sam3n)
/** 
 * \brief Get PDC registers base address
 *
 * \param usart Pointer to an USART peripheral.
 *
 * \return PDC registers base for PDC driver to access.
 */
extern Pdc *usart_get_pdc_base( Usart *usart ) ;
#endif

/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
}
#endif
/**INDENT-ON**/
/// @endcond

#endif // _V_USART_

