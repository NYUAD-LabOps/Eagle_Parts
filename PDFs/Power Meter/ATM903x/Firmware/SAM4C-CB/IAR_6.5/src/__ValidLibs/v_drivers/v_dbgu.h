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
 * File Name           : v_dbgu.h
 * Object              :
 * Creation            : JPP   04/Sep/2006
 *                     : ERr   Sep/2011
 *----------------------------------------------------------------------------
*/
#ifndef _V_DBGU_H
#define _V_DBGU_H


#include  "compiler.h"


/*! \brief Option list for DBGU peripheral initialize */
typedef struct sam_dbgu_opt {
	//! MCK for DBGU
	uint32_t dw_mck;
	//! Expected baud rate
	uint32_t dw_baudrate;
	//! Initialize value for DBGU mode register
	uint32_t dw_mode;
	//! Configure channel mode (Normal, Automatic, Local_loopback or Remote_loopback)
	uint32_t dw_chmode;
} sam_dbgu_opt_t;



/**
 * \brief Configure DBGU with the specified parameters.
 *
 * \param dbgu Pointer to the DBGU peripheral to configure.
 * \param p_dbgu_opt Pointer to sam_dbgu_opt_t instance.
 *
 * \return 0 for OK.
 */
extern uint32_t dbgu_init( Dbgu *dbgu, const sam_dbgu_opt_t *p_dbgu_opt ) ;

/**
 * \brief Enable DBGU transmitter.
 *
 * \param dbgu Pointer to a DBGU peripheral.
 *
 * \return 0 for OK.
 */
extern void dbgu_enable_tx( Dbgu *dbgu ) ;

/**
 * \brief Disable DBGU transmitter.
 *
 * \param dbgu Pointer to a DBGU peripheral.
 *
 * \return 0 for OK.
 */
extern void dbgu_disable_tx( Dbgu *dbgu ) ;

/**
 * \brief Immediately stop and disable DBGU transmitter.
 *
 * \param dbgu Pointer to a DBGU peripheral.
 *
 * \return 0 for OK.
 */
extern void dbgu_reset_tx( Dbgu *dbgu ) ;

/**
 * \brief Enable DBGU receiver.
 *
 * \param dbgu Pointer to a DBGU peripheral.
 *
 * \return 0 for OK.
 */
extern void dbgu_enable_rx( Dbgu *dbgu ) ;

/**
 * \brief Disable DBGU receiver.
 *
 * \param dbgu Pointer to a DBGU peripheral.
 *
 * \return 0 for OK.
 */
extern void dbgu_disable_rx( Dbgu *dbgu ) ;

/**
 * \brief Immediately stop and disable DBGU receiver.
 *
 * \param dbgu Pointer to a DBGU peripheral.
 *
 * \return 0 for OK.
 */
extern void dbgu_reset_rx( Dbgu *dbgu ) ;

/**
 * \brief Enable DBGU receiver and transmitter.
 *
 * \param dbgu Pointer to a DBGU peripheral.
 *
 * \return 0 for OK.
 */
extern void dbgu_enable( Dbgu *dbgu ) ;

/**
 * \brief Disable DBGU receiver and transmitter.
 *
 * \param dbgu Pointer to a DBGU peripheral.
 *
 * \return 0 for OK.
 */
extern void dbgu_disable( Dbgu *dbgu ) ;

/**
 * \brief Reset DBGU receiver and transmitter.
 *
 * \param dbgu Pointer to a DBGU peripheral.
 *
 * \return 0 for OK.
 */
extern void dbgu_reset( Dbgu *dbgu ) ;

/** \brief Enable DBGU interrupts.
 *
 *  \param dbgu pointer to a Dbgu instance.
 *  \param dw_sources interrupt sources bit map.
 */
extern void dbgu_enable_interrupt( Dbgu *dbgu,uint32_t dw_sources ) ;

/** \brief Disable DBGU interrupts.
 *
 *  \param dbgu pointer to a Dbgu instance.
 *  \param dw_sources interrupt sources bit map.
 */
extern void dbgu_disable_interrupt( Dbgu *dbgu,uint32_t dw_sources ) ;

/** \brief Read DBGU interrupt mask.
 *
 *  \param dbgu pointer to a Dbgu instance.
 *
 *  \return The interrupt mask value.
 */
extern uint32_t dbgu_get_interrupt_mask( Dbgu *dbgu ) ;

/**
 * \brief   Get current status.
 *
 * \param dbgu Pointer to a Dbgu instance.
 *
 * \return The current DBGU status.
 */
extern uint32_t dbgu_get_status( Dbgu *dbgu ) ;

/** 
 * \brief Check if Transmit is Ready.
 * Check if Data has been loaded in DBGU_THR and is waiting to be loaded in the Transmit Shift Register (TSR).
 *
 * \param dbgu Pointer to a Dbgu instance.
 *
 * \return 0 for YES, others for NO.
 */
extern uint32_t dbgu_is_tx_ready( Dbgu *dbgu ) ;

/** 
 * \brief Check if Transmit Hold Register is empty.
 * Check if Last data written in DBGU_THR has been loaded in TSR and last data loaded in TSR has been transmitted.
 *
 * \param dbgu Pointer to a Dbgu instance.
 *
 * \return 0 for YES, others for NO.
 */
extern uint32_t dbgu_is_tx_empty( Dbgu *dbgu ) ;

/** 
 * \brief Check if Received data is ready.
 * Check if Data has been received and loaded in DBGU_RHR.
 *
 * \param dbgu Pointer to a Dbgu instance.
 *
 * \return 0 for YES, others for NO.
 */
extern uint32_t dbgu_is_rx_ready( Dbgu *dbgu ) ;

/** 
 * \brief Check if transmit is enabled.
 *
 * \param dbgu Pointer to a Dbgu instance.
 *
 * \return 0 for YES, others for NO.
 */
extern uint32_t dbgu_is_tx_enabled( Dbgu *dbgu ) ;

/**
 * \brief Check if receive is enabled.
 *
 * \param dbgu Pointer to a Dbgu instance.
 *
 * \return 0 for YES, others for NO.
 */
extern uint32_t dbgu_is_rx_enabled( Dbgu *dbgu ) ;

/** 
 * \brief Write to DBGU Transmit Holding Register
 * Before writing user should check if tx is ready (or empty).
 *
 * \param dbgu Pointer to a DBGU peripheral.
 * \param data Data to be sent.
 *
 * \return 0 if successful.
 */
extern uint32_t dbgu_write( Dbgu *dbgu, const uint8_t data ) ;

/** 
 * \brief Read from DBGU Receive Holding Register.
 * Before reading user should check if rx is ready.
 *
 * \param dbgu Pointer to a DBGU peripheral.
 *
 * \return 0 if successful.
 */
extern uint32_t dbgu_read( Dbgu *dbgu, uint8_t *data ) ;




#endif //_V_DBGU_H