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

#ifndef _SAMA5_EXCEPTIONS_H
#define _SAMA5_EXCEPTIONS_H

/*----------------------------------------------------------------------------
 *        Types
 *----------------------------------------------------------------------------*/

/* Function prototype for exception table items (interrupt handler). */
//typedef void( *IntFunc )( void ) ;



/*----------------------------------------------------------------------------
 *        Exported functions
 *----------------------------------------------------------------------------*/
/* Cortex-A5 core handlers */
/*
*/

extern void FIQ_Handler( void ) ;
extern void SYS_IrqHandler( void ) ;
extern void Spurious_handler( void ) ;

/* Peripherals handlers */
extern void DBGU_IrqHandler( void ) ;
extern void PIT_IrqHandler( void ) ;
extern void WDT_IrqHandler( void ) ;
extern void SMC_IrqHandler( void ) ;
extern void PIOA_IrqHandler( void ) ;
extern void PIOB_IrqHandler( void ) ;
extern void PIOC_IrqHandler( void ) ;
extern void PIOD_IrqHandler( void ) ;
extern void PIOE_IrqHandler( void ) ;
extern void SMD_IrqHandler( void ) ;
extern void USART0_IrqHandler( void ) ;
extern void USART1_IrqHandler( void ) ;
extern void USART2_IrqHandler( void ) ;
extern void USART3_IrqHandler( void ) ;
extern void UART0_IrqHandler( void ) ;//
extern void UART1_IrqHandler( void ) ;//
extern void TWI0_IrqHandler( void ) ;
extern void TWI1_IrqHandler( void ) ;
extern void TWI2_IrqHandler( void ) ;
extern void HSMCI0_IrqHandler( void ) ;
extern void HSMCI1_IrqHandler( void ) ;
extern void HSMCI2_IrqHandler( void ) ;
extern void SPI0_IrqHandler( void ) ;
extern void SPI1_IrqHandler( void ) ;
extern void TC0_IrqHandler( void ) ;//
extern void TC1_IrqHandler( void ) ;//
extern void PWM_IrqHandler( void ) ;
extern void ADC_IrqHandler( void ) ;
extern void DMAC0_IrqHandler( void ) ;
extern void DMAC1_IrqHandler( void ) ;
extern void UHPHS_IrqHandler( void ) ;
extern void UDPHS_IrqHandler( void ) ;
extern void GMAC_IrqHandler( void ) ;
extern void EMAC_IrqHandler( void ) ;
extern void LCDC_IrqHandler( void ) ;
extern void ISI_IrqHandler( void ) ;
extern void SSC0_IrqHandler( void ) ;
extern void SSC1_IrqHandler( void ) ;
extern void CAN0_IrqHandler( void ) ;
extern void CAN1_IrqHandler( void ) ;
extern void SHA_IrqHandler( void ) ;
extern void AES_IrqHandler( void ) ;
extern void TDES_IrqHandler( void ) ;
extern void TRNG_IrqHandler( void ) ;
extern void ARM_IrqHandler( void ) ;//
extern void IRQ_IrqHandler( void ) ;//
extern void FUSE_IrqHandler( void ) ;//
extern void MPDDRC_IrqHandler( void ) ;//




#endif //_SAMA5_EXCEPTIONS_H
