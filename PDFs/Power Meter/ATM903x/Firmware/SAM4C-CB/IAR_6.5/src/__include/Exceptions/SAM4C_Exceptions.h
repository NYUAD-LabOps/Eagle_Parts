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

#ifndef _SAM4C_EXCEPTIONS_H
#define _SAM4C_EXCEPTIONS_H

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
extern void Reset_IrqHandler      ( void );
extern void NMI_IrqHandler        ( void );
extern void HardFault_IrqHandler  ( void );
extern void MemManage_IrqHandler  ( void );
extern void BusFault_IrqHandler   ( void );
extern void UsageFault_IrqHandler ( void );
extern void SVC_IrqHandler        ( void );
extern void DebugMon_IrqHandler   ( void );
extern void PendSV_IrqHandler     ( void );
extern void SysTick_IrqHandler    ( void );

/* Peripherals handlers */
extern void ADC_IrqHandler        ( void );
extern void AES_IrqHandler        ( void );
extern void ARM1_IrqHandler       ( void );
extern void CPKCC_IrqHandler      ( void );
extern void EFC_IrqHandler        ( void );
extern void ICM_IrqHandler        ( void );
extern void IPC0_IrqHandler       ( void );
extern void IPC1_IrqHandler       ( void );
extern void PIOA_IrqHandler       ( void );
extern void PIOB_IrqHandler       ( void );
extern void PIOC_IrqHandler       ( void );
extern void PMC_IrqHandler        ( void );
extern void PWM_IrqHandler        ( void );
extern void RSTC_IrqHandler       ( void );
extern void RTC_IrqHandler        ( void );
extern void RTT_IrqHandler        ( void );
extern void SLCDC_IrqHandler      ( void );
extern void SMC0_IrqHandler       ( void );
extern void SMC1_IrqHandler       ( void );
extern void SPI0_IrqHandler       ( void );
extern void SPI1_IrqHandler       ( void );
extern void SRAM_IrqHandler       ( void );
extern void SUPC_IrqHandler       ( void );
extern void TC0_IrqHandler        ( void );
extern void TC1_IrqHandler        ( void );
extern void TC2_IrqHandler        ( void );
extern void TC3_IrqHandler        ( void );
extern void TC4_IrqHandler        ( void );
extern void TC5_IrqHandler        ( void );
extern void TRNG_IrqHandler       ( void );
extern void TWI0_IrqHandler       ( void );
extern void TWI1_IrqHandler       ( void );
extern void UART0_IrqHandler      ( void );
extern void UART1_IrqHandler      ( void );
extern void USART0_IrqHandler     ( void );
extern void USART1_IrqHandler     ( void );
extern void USART2_IrqHandler     ( void );
extern void USART3_IrqHandler     ( void );
extern void USART4_IrqHandler     ( void );
extern void WDT_IrqHandler        ( void );


#endif //_SAM4C_EXCEPTIONS_H
