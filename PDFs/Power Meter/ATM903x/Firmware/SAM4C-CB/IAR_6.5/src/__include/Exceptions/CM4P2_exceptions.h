/* ----------------------------------------------------------------------------
 *         ATMEL Microcontroller Software Support
 * ----------------------------------------------------------------------------
 * Copyright (c) 2009, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */

/**
 * \file
 * Interface for default exception handlers.
 */

#ifndef _CM4P2_EXCEPTIONS_H
#define _CM4P2_EXCEPTIONS_H

/*----------------------------------------------------------------------------
 *        Types
 *----------------------------------------------------------------------------*/

/* Function prototype for exception table items (interrupt handler). */
//typedef void( *IntFunc )( void ) ;



/*----------------------------------------------------------------------------
 *        Exported functions
 *----------------------------------------------------------------------------*/
/* Default empty handler */
extern void Dummy_Handler( void ) ;

/* Cortex-M4 core handlers */
extern void Reset_Handler      ( void );
extern void NMI_Handler        ( void );
extern void HardFault_Handler  ( void );
extern void MemManage_Handler  ( void );
extern void BusFault_Handler   ( void );
extern void UsageFault_Handler ( void );
extern void SVC_Handler        ( void );
extern void DebugMon_Handler   ( void );
extern void PendSV_Handler     ( void );
extern void SysTick_Handler    ( void );

/* Peripherals handlers */
extern void ACC_Handler        ( void );
extern void AES_Handler        ( void );
extern void AFEC0_Handler      ( void );
extern void AFEC1_Handler      ( void );
extern void ARM_Handler        ( void );
extern void CAN0_Handler       ( void );
extern void CAN1_Handler       ( void );
extern void DACC_Handler       ( void );
extern void DMAC_Handler       ( void );
extern void EFC_Handler        ( void );
extern void GMAC_Handler       ( void );
extern void PIOA_Handler       ( void );
extern void PIOB_Handler       ( void );
extern void PIOC_Handler       ( void );
extern void PIOD_Handler       ( void );
extern void PIOE_Handler       ( void );
extern void PMC_Handler        ( void );
extern void PWM_Handler        ( void );
extern void RSTC_Handler       ( void );
extern void RTC_Handler        ( void );
extern void RTT_Handler        ( void );
extern void SMC_Handler        ( void );
extern void SPI_Handler        ( void );
extern void SUPC_Handler       ( void );
extern void TC0_Handler        ( void );
extern void TC1_Handler        ( void );
extern void TC2_Handler        ( void );
extern void TC3_Handler        ( void );
extern void TC4_Handler        ( void );
extern void TC5_Handler        ( void );
extern void TC6_Handler        ( void );
extern void TC7_Handler        ( void );
extern void TC8_Handler        ( void );
extern void TWI0_Handler       ( void );
extern void TWI1_Handler       ( void );
extern void UART0_Handler      ( void );
extern void UART1_Handler      ( void );
extern void UDP_Handler        ( void );
extern void USART0_Handler     ( void );
extern void USART1_Handler     ( void );
extern void WDT_Handler        ( void );


#endif //_CM4P2_EXCEPTIONS_H
