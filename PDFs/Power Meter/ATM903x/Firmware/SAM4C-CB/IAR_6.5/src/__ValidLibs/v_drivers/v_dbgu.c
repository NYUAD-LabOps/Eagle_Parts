/*-----------------------------------------------------------------------------
 *           ATMEL Microcontroller Software Support  -  ROUSSET  -
 *-----------------------------------------------------------------------------
 * DISCLAIMER:  THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *----------------------------------------------------------------------------
 * File Name           : v_dbgu.c
 *----------------------------------------------------------------------------
*/

#include "v_dbgu.h"


/**
 * \brief Configure DBGU with the specified parameters.
 * The PMC are PIO must be configured first.
 *
 * \param dbgu Pointer to the DBGU peripheral to configure.
 * \param p_dbgu_opt Pointer to sam_dbgu_opt_t instance.
 *
 * \retval 0 Success.
 * \retval 1 Bad baud rate generator value.
 */
extern uint32_t dbgu_init( Dbgu *dbgu, const sam_dbgu_opt_t *p_dbgu_opt )
{
    uint32_t cd = 0;
	
    /* Reset and disable receiver & transmitter */
    dbgu->DBGU_CR = DBGU_CR_RSTRX | DBGU_CR_RSTTX
                   | DBGU_CR_RXDIS | DBGU_CR_TXDIS;

    /* Check and configure baudrate */
    /* Asynchronous, no oversampling */
    
	cd = (p_dbgu_opt->dw_mck*10) / (p_dbgu_opt->dw_baudrate*16); //ERr
        cd = (cd%10<5?cd/10:cd/10+1);                               //ERr
        
	if (cd < 1 || cd > 65535)
		return 1;

    dbgu->DBGU_BRGR = cd;
    /* Configure mode */
    //dbgu->DBGU_MR = p_dbgu_opt->dw_mode;
    dbgu->DBGU_MR = p_dbgu_opt->dw_mode | p_dbgu_opt->dw_chmode; //ERr

    
    /* Disable PDC channel */
#if (DBGU_HAS_PDC == 1)
    dbgu->DBGU_PTCR = DBGU_PTCR_RXTDIS | DBGU_PTCR_TXTDIS;
#endif //ERr SAMA5

    
    /* Enable receiver and transmitter */
    dbgu->DBGU_CR = DBGU_CR_RXEN | DBGU_CR_TXEN;

	return 0;
}

/**
 * \brief Enable DBGU transmitter.
 *
 * \param dbgu Pointer to a DBGU peripheral.
 */
extern void dbgu_enable_tx( Dbgu *dbgu )
{
	/* Enable transmitter */ 
	dbgu->DBGU_CR = DBGU_CR_TXEN;
}

/**
 * \brief Disable DBGU transmitter.
 *
 * \param dbgu Pointer to a DBGU peripheral.
 */
extern void dbgu_disable_tx( Dbgu *dbgu )
{
	/* Disable transmitter */ 
	dbgu->DBGU_CR = DBGU_CR_TXDIS;
}

/**
 * \brief Immediately stop and disable DBGU transmitter.
 *
 * \param dbgu Pointer to a DBGU peripheral.
 */
extern void dbgu_reset_tx( Dbgu *dbgu )
{
    /* Reset transmitter */
    dbgu->DBGU_CR = DBGU_CR_TXDIS;
}

/**
 * \brief Enable DBGU receiver.
 *
 * \param dbgu Pointer to a DBGU peripheral.
 */
extern void dbgu_enable_rx( Dbgu *dbgu )
{
	/* Enable receiver */ 
	dbgu->DBGU_CR = DBGU_CR_RXEN;
}

/**
 * \brief Disable DBGU receiver.
 *
 * \param dbgu Pointer to a DBGU peripheral.
 */
extern void dbgu_disable_rx( Dbgu *dbgu )
{
	/* Disable receiver */ 
	dbgu->DBGU_CR = DBGU_CR_RXDIS;
}

/**
 * \brief Immediately stop and disable DBGU receiver.
 *
 * \param dbgu Pointer to a DBGU peripheral.
 */
extern void dbgu_reset_rx( Dbgu *dbgu )
{
    /* Reset receiver */
    dbgu->DBGU_CR = DBGU_CR_RXDIS;
}

/**
 * \brief Enable DBGU receiver and transmitter.
 *
 * \param dbgu Pointer to a DBGU peripheral.
 */
extern void dbgu_enable( Dbgu *dbgu )
{
    /* Enable receiver and transmitter */
    dbgu->DBGU_CR = DBGU_CR_RXEN | DBGU_CR_TXEN;
}

/**
 * \brief Disable DBGU receiver and transmitter.
 *
 * \param dbgu Pointer to a DBGU peripheral.
 */
extern void dbgu_disable( Dbgu *dbgu )
{
    /* Disable receiver and transmitter */
    dbgu->DBGU_CR = DBGU_CR_RXDIS | DBGU_CR_TXDIS;
}

/**
 * \brief Reset DBGU receiver and transmitter.
 *
 * \param dbgu Pointer to a DBGU peripheral.
 */
extern void dbgu_reset( Dbgu *dbgu )
{
    /* Reset and disable receiver & transmitter */
    dbgu->DBGU_CR = DBGU_CR_RSTRX | DBGU_CR_RSTTX
                   | DBGU_CR_RXDIS | DBGU_CR_TXDIS;
}

/** \brief Enable DBGU interrupts.
 *
 *  \param dbgu pointer to a Dbgu instance.
 *  \param dw_sources interrupt sources bit map.
 */
extern void dbgu_enable_interrupt( Dbgu *dbgu,uint32_t dw_sources )
{
	dbgu->DBGU_IER = dw_sources;
}

/** \brief Disable DBGU interrupts.
 *
 *  \param dbgu pointer to a Dbgu instance.
 *  \param dw_sources interrupt sources bit map.
 */
extern void dbgu_disable_interrupt( Dbgu *dbgu,uint32_t dw_sources )
{
	dbgu->DBGU_IDR = dw_sources;
}

/** \brief Read DBGU interrupt mask.
 *
 *  \param dbgu pointer to a Dbgu instance.
 *
 *  \return The interrupt mask value.
 */
extern uint32_t dbgu_get_interrupt_mask( Dbgu *dbgu )
{
	return dbgu->DBGU_IMR;
}

/**
 * \brief   Get current status.
 *
 * \param dbgu Pointer to a Dbgu instance.
 *
 * \return The current DBGU status.
 */
extern uint32_t dbgu_get_status( Dbgu *dbgu )
{
	return dbgu->DBGU_SR;
}

/** 
 * \brief Check if Transmit is Ready.
 * Check if Data has been loaded in DBGU_THR and is waiting to be loaded in the Transmit Shift Register (TSR).
 *
 * \param dbgu Pointer to a Dbgu instance.
 *
 * \retval 0 Transmit is not ready, data pending.
 * \retval 1 Data has been transmitted.
 */
extern uint32_t dbgu_is_tx_ready( Dbgu *dbgu )
{
	return (dbgu->DBGU_SR & DBGU_SR_TXRDY) > 0;
}

/** 
 * \brief Check if Transmit Hold Register is empty.
 * Check if Last data written in DBGU_THR has been loaded in TSR and last data loaded in TSR has been transmitted.
 *
 * \param dbgu Pointer to a Dbgu instance.
 *
 * \retval 0 Transmit is not emtpy.
 * \retval 1 Transmit is emtpy.
 */
extern uint32_t dbgu_is_tx_empty( Dbgu *dbgu )
{
	return (dbgu->DBGU_SR & DBGU_SR_TXEMPTY) > 0;
}

/** 
 * \brief Check if Received data is ready.
 * Check if Data has been received and loaded in DBGU_RHR.
 *
 * \param dbgu Pointer to a Dbgu instance.
 *
 * \retval 0 No data has been received.
 * \retval 1 One data has been received.
 */
extern uint32_t dbgu_is_rx_ready( Dbgu *dbgu )
{
	return (dbgu->DBGU_SR & DBGU_SR_RXRDY) > 0;
}

/** 
 * \brief Write to DBGU Transmit Holding Register
 *
 * \param dbgu Pointer to a DBGU peripheral.
 * \param data Data to be sent.
 *
 * \retval 0 Success.
 * \retval 1 I/O Failure, DBGU is not ready.
 */
extern uint32_t dbgu_write( Dbgu *dbgu, const uint8_t data )
{
    /* Check if the transmitter is ready */
    if ( !(dbgu->DBGU_SR & DBGU_SR_TXRDY) )
		return 1;

    /* Send character */
    dbgu->DBGU_THR = data ;
	return 0;
}

/** 
 * \brief Read from DBGU Receive Holding Register.
 *
 * \param dbgu Pointer to a DBGU peripheral.
 *
 * \retval 0 Success.
 * \retval 1 I/O Failure, DBGU is not ready.
 */
extern uint32_t dbgu_read( Dbgu *dbgu, uint8_t *data )
{
    /* Check if the receiver is ready */
    if ( (dbgu->DBGU_SR & DBGU_SR_RXRDY) == 0 )
		return 1;

	/* Read character */
    *data = dbgu->DBGU_RHR ;
	return 0;
}

