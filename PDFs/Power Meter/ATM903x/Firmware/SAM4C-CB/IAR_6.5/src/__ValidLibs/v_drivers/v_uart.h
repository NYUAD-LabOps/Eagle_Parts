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

#ifndef _V_UART_H
#define _V_UART_H


#include "project.h"

// ---- General purpose include files
//#include <stdio.h> //IAR
#include "device.h"


// ---- Peripherals (ASF drivers)
#include "drivers/uart/uart.h"


// ---- Prototypes -------------------------------------------------------------
extern uint32_t v_uart_init(Uart * p_uart, const sam_uart_opt_t * p_uart_opt);



#endif //_V_UART_H

