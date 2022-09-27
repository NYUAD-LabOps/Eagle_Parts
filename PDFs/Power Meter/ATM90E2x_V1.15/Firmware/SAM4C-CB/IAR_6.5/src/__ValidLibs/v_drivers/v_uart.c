/*! \file *********************************************************************
 *
 * \brief UART driver for SAM3.
 *
 * $asf_license$
 *
 * \par Purpose
 *
 * This file contains basic functions for the SAM3 UART, with support for all
 * modes, settings and clock speeds.
 *
 * \par Usage
 *
 * -# Enable the UART peripheral clock in the PMC.
 * -# Enable the required UART PIOs (see pio.h).
 * -# Configure the UART by calling uart_init.
 * -# Send data through the UART using the uart_write.
 * -# Receive data from the UART using the uart_read; 
 *    the availability of data can be polled with 
 *    uart_is_rx_ready.
 * -# Disable the transmitter and/or the receiver of the UART with
 *    uart_disable_tx and uart_disable_rx.
 *
 * - Compiler:           IAR EWARM and GNU GCC for SAM3
 * - Supported devices:  All SAM3 devices with a UART module can be used.
 * - AppNote:
 *
 * \author               Atmel Corporation: http://www.atmel.com \n
 *                       Support and FAQ: http://support.atmel.no/
 *
 ******************************************************************************/


#include  "v_uart.h"



/**
 * \brief Configure UART with the specified parameters.
 * The PMC and PIOs must be configured first.
 *
 * \param p_uart Pointer to the UART peripheral to configure.
 * \param p_uart_opt Pointer to sam_uart_opt_t instance.
 *
 * \retval 0 Success.
 * \retval 1 Bad baud rate generator value.
 */
uint32_t v_uart_init(Uart * p_uart, const sam_uart_opt_t * p_uart_opt)
{
	uint32_t cd = 0;

	/* Reset and disable receiver & transmitter */
	p_uart->UART_CR = UART_CR_RSTRX | UART_CR_RSTTX
			| UART_CR_RXDIS | UART_CR_TXDIS;

	/* Check and configure baudrate */
	/* Asynchronous, no oversampling */
      	cd = (p_uart_opt->dw_mck*10) / (p_uart_opt->dw_baudrate*16); //ERr
        cd = (cd%10<5?cd/10:cd/10+1);                               //ERr
	if (cd < 1 || cd > 65535)
		return 1;
        p_uart->UART_BRGR = cd;

        /* Configure mode */
        p_uart->UART_MR = p_uart_opt->dw_mode | p_uart_opt->dw_chmode; //ERr

#if (UART_HAS_PDC == 1)
	/* Disable PDC channel */
	p_uart->UART_PTCR = UART_PTCR_RXTDIS | UART_PTCR_TXTDIS;
#endif
	/* Enable receiver and transmitter */
	p_uart->UART_CR = UART_CR_RXEN | UART_CR_TXEN;

	return 0;
}

