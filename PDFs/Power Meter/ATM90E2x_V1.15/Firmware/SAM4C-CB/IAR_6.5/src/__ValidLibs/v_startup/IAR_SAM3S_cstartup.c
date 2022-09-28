/* ----------------------------------------------------------------------------
 *         ATMEL Microcontroller Software Support 
 * ----------------------------------------------------------------------------
 * Copyright (c) 2008, Atmel Corporation
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
// Based on IAR software example
// Updated for SOC : ERr / 08/2011


// ------ Compatibility list (compliant devices) ------------------------------
// SAM3Sx (tested : SAM3S1B)
// SAM4Sx (tested : SAM4S16C)
// ---------------------- (file created for SAM3S) ----------------------------
//-----------------------------------------------------------------------------


#include "project.h"


// ---- General purpose include files
#include "device.h"
#include "board.h"
#include "exceptions.h"


//------------------------------------------------------------------------------
/// This is the code that gets called on processor reset. To initialize the
/// device.
//------------------------------------------------------------------------------
//#define AT91C_EFC_FWS_6WS (6  <<  8) // (EFC) 6 Wait States

int __low_level_init( void )
{  
   unsigned int  read_reg;
   
       
   //  --------- EFC Init
   //REG_EFC_FMR = AT91C_EFC_FWS_6WS; // 1 Wait State necessary to work at more than 30 MHz
#ifdef REG_EFC_FMR
   REG_EFC_FMR = EEFC_FMR_FWS(6); // 6 Wait states, other fields=0 (defaults)
#endif
#ifdef REG_EFC0_FMR
   REG_EFC0_FMR = EEFC_FMR_FWS(6); // 6 Wait states, other fields=0 (defaults)
#endif
#ifdef REG_EFC1_FMR
   REG_EFC1_FMR = EEFC_FMR_FWS(6); // 6 Wait states, other fields=0 (defaults)
#endif
   
   
   //  --------- select Slow clock as input clock for MCK
   read_reg = REG_PMC_MCKR;
   read_reg &= ~PMC_MCKR_CSS_Msk;
   read_reg |= PMC_MCKR_CSS_SLOW_CLK; 
   REG_PMC_MCKR = read_reg;   
   while( !(REG_PMC_SR & PMC_SR_MCKRDY) );//CJn
   
   
   // restore HW startup clock settings if ROMBOOT was executed (RAM debug)
   REG_CKGR_MOR = CKGR_MOR_KEY(MOR_KEY_VAL)         |
                             CKGR_MOR_MOSCXTST(0xFF)| // ERr(0x3F<<8)|
                             CKGR_MOR_MOSCRCF_4_MHz  |
                             CKGR_MOR_MOSCRCEN      |
                             CKGR_MOR_MOSCXTEN      ;

   while( !(REG_PMC_SR & PMC_SR_MOSCRCS) );//CJn

   read_reg = REG_PMC_MCKR;
   read_reg &= ~PMC_MCKR_PRES_Msk;
   read_reg |= PMC_MCKR_PRES_CLK_1;
   REG_PMC_MCKR = read_reg;
   //---------------------------------
   read_reg = REG_PMC_MCKR;
   read_reg &= ~PMC_MCKR_CSS_Msk;
   read_reg |= PMC_MCKR_CSS_MAIN_CLK; 
   REG_PMC_MCKR = read_reg;   
   while( !(REG_PMC_SR & PMC_SR_MCKRDY) );//CJn

   
  return 1; 
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------




//------------------------------------------------------------------------------
/// Exceptions handlers
//------------------------------------------------------------------------------
/* Cortex-M3 core handlers */
//#pragma weak Reset_Handler=Dummy_Handler
#pragma weak NMI_Handler
#pragma weak HardFault_Handler
#pragma weak MemManage_Handler
#pragma weak BusFault_Handler
#pragma weak UsageFault_Handler
#pragma weak SVC_Handler
#pragma weak DebugMon_Handler
#pragma weak PendSV_Handler
#pragma weak SysTick_Handler
#pragma weak IrqHandlerNotUsed

/* Peripherals handlers */
#pragma weak ACC_IrqHandler=Dummy_Handler
#pragma weak ADC_IrqHandler=Dummy_Handler
#pragma weak CRCCU_IrqHandler=Dummy_Handler
#pragma weak DACC_IrqHandler=Dummy_Handler
#pragma weak EEFC_IrqHandler=Dummy_Handler
#pragma weak HSMCI_IrqHandler=Dummy_Handler
#pragma weak PIOA_IrqHandler=Dummy_Handler
#pragma weak PIOB_IrqHandler=Dummy_Handler
#pragma weak PIOC_IrqHandler=Dummy_Handler
#pragma weak PMC_IrqHandler=Dummy_Handler
#pragma weak PWM_IrqHandler=Dummy_Handler
#pragma weak RSTC_IrqHandler=Dummy_Handler
#pragma weak RTC_IrqHandler=Dummy_Handler
#pragma weak RTT_IrqHandler=Dummy_Handler
#pragma weak SMC_IrqHandler=Dummy_Handler
#pragma weak SPI_IrqHandler=Dummy_Handler
#pragma weak SSC_IrqHandler=Dummy_Handler
#pragma weak SUPC_IrqHandler=Dummy_Handler
#pragma weak TC0_IrqHandler=Dummy_Handler
#pragma weak TC1_IrqHandler=Dummy_Handler
#pragma weak TC2_IrqHandler=Dummy_Handler
#pragma weak TC3_IrqHandler=Dummy_Handler
#pragma weak TC4_IrqHandler=Dummy_Handler
#pragma weak TC5_IrqHandler=Dummy_Handler
#pragma weak TWI0_IrqHandler=Dummy_Handler
#pragma weak TWI1_IrqHandler=Dummy_Handler
#pragma weak UART0_IrqHandler=Dummy_Handler
#pragma weak UART1_IrqHandler=Dummy_Handler
#pragma weak USART0_IrqHandler=Dummy_Handler
#pragma weak USART1_IrqHandler=Dummy_Handler
#pragma weak USBD_IrqHandler=Dummy_Handler
#pragma weak WDT_IrqHandler=Dummy_Handler


//------------------------------------------------------------------------------
/// Exceptions default routines
//------------------------------------------------------------------------------
void NMI_Handler(void) {   
    while(1);
}
//------------------------------------------------------------------------------
void HardFault_Handler(void){
    while(1);
}
//------------------------------------------------------------------------------
void MemManage_Handler(void){
    while(1);
}
//------------------------------------------------------------------------------
void BusFault_Handler(void){
    while(1);
}
//------------------------------------------------------------------------------
void UsageFault_Handler(void){
    while(1);
}
//------------------------------------------------------------------------------
void SVC_Handler(void){
    while(1);
}
//------------------------------------------------------------------------------
void DebugMon_Handler(void){
    while(1);
}
//------------------------------------------------------------------------------
void PendSV_Handler(void){
    while(1);
}
//------------------------------------------------------------------------------
void SysTick_Handler( void ){
      while(1);
}
//------------------------------------------------------------------------------
void IrqHandlerNotUsed(void){
    while(1);
}
//------------------------------------------------------------------------------
void IrqDBGUBHandler(void) {   
    while(1);
}
//------------------------------------------------------------------------------



//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
// Exception Vector Tables -----------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
#pragma language=extended
#pragma segment="CSTACK"

typedef void( *intfunc )( void );
typedef union { intfunc __fun; void * __ptr; } intvec_elem;

extern int  __low_level_init( void );
extern void main( void );
extern void __iar_program_start( void );


//------------------------------------------------------------------------------
#pragma location = ".intvec"
#pragma data_alignment=0x100
intvec_elem vector_table[] =
{
    { .__ptr = __sfe( "CSTACK" ) },
     __iar_program_start,

    NMI_Handler,
    HardFault_Handler,
    MemManage_Handler,
    BusFault_Handler,
    UsageFault_Handler,
    0, 0, 0, 0,             // Reserved
    SVC_Handler,
    DebugMon_Handler,
    0,                      // Reserved
    PendSV_Handler,
    SysTick_Handler,       //  Cortex System Tick Timer

   // Configurable interrupts
    SUPC_IrqHandler,      // 0  SUPPLY CONTROLLER
    RSTC_IrqHandler,      // 1  RESET CONTROLLER
    RTC_IrqHandler,       // 2  REAL TIME CLOCK
    RTT_IrqHandler,       // 3  REAL TIME TIMER
    WDT_IrqHandler,       // 4  WATCHDOG TIMER
    PMC_IrqHandler,       // 5  PMC
    EEFC_IrqHandler,      // 6  EEFC
    IrqHandlerNotUsed,    // 7  Reserved
    UART0_IrqHandler,     // 8  UART0
    UART1_IrqHandler,     // 9  UART1
    SMC_IrqHandler,       // 10 SMC
    PIOA_IrqHandler,      // 11 Parallel IO Controller A
    PIOB_IrqHandler,      // 12 Parallel IO Controller B
    PIOC_IrqHandler,      // 13 Parallel IO Controller C
    USART0_IrqHandler,    // 14 USART 0
    USART1_IrqHandler,    // 15 USART 1
    IrqHandlerNotUsed,    // 16 Reserved
    IrqHandlerNotUsed,    // 17 Reserved
    HSMCI_IrqHandler,     // 18 Multimedia Card Interface
    TWI0_IrqHandler,      // 19 TWI 0
    TWI1_IrqHandler,      // 20 TWI 1
    SPI_IrqHandler,       // 21 Serial Peripheral Interface
    SSC_IrqHandler,       // 22 Serial Synchronous Controller
    TC0_IrqHandler,       // 23 Timer Counter 0
    TC1_IrqHandler,       // 24 Timer Counter 1
    TC2_IrqHandler,       // 25 Timer Counter 2
    TC3_IrqHandler,       // 26 Timer Counter 3
    TC4_IrqHandler,       // 27 Timer Counter 4
    TC5_IrqHandler,       // 28 Timer Counter 5
    ADC_IrqHandler,       // 29 Analog to Digital Converter
    DACC_IrqHandler,      // 30 Digital to Analog Converter
    PWM_IrqHandler,       // 31 Pulse Width Modulation
    CRCCU_IrqHandler,     // 32 CRC Calculation Unit
    ACC_IrqHandler,       // 33 Analog Comparator
    USBD_IrqHandler       // 34 USB Device Port
};



//------------------------------------------------------------------------------
#pragma data_alignment=0x100
intvec_elem new_vector_table[] =
{
    { .__ptr = __sfe( "CSTACK" ) },
    __iar_program_start,

    NMI_Handler,
    HardFault_Handler,
    MemManage_Handler,
    BusFault_Handler,
    UsageFault_Handler,
    0, 0, 0, 0,             // Reserved
    SVC_Handler,
    DebugMon_Handler,
    0,                      // Reserved
    PendSV_Handler,
    SysTick_Handler,       //  Cortex System Tick Timer

   // Configurable interrupts
    SUPC_IrqHandler,      // 0  SUPPLY CONTROLLER
    RSTC_IrqHandler,      // 1  RESET CONTROLLER
    RTC_IrqHandler,       // 2  REAL TIME CLOCK
    RTT_IrqHandler,       // 3  REAL TIME TIMER
    WDT_IrqHandler,       // 4  WATCHDOG TIMER
    PMC_IrqHandler,       // 5  PMC
    EEFC_IrqHandler,      // 6  EEFC
    IrqHandlerNotUsed,    // 7  Reserved
    UART0_IrqHandler,     // 8  UART0
    UART1_IrqHandler,     // 9  UART1
    SMC_IrqHandler,       // 10 SMC
    PIOA_IrqHandler,      // 11 Parallel IO Controller A
    PIOB_IrqHandler,      // 12 Parallel IO Controller B
    PIOC_IrqHandler,      // 13 Parallel IO Controller C
    USART0_IrqHandler,    // 14 USART 0
    USART1_IrqHandler,    // 15 USART 1
    IrqHandlerNotUsed,    // 16 Reserved
    IrqHandlerNotUsed,    // 17 Reserved
    HSMCI_IrqHandler,     // 18 Multimedia Card Interface
    TWI0_IrqHandler,      // 19 TWI 0
    TWI1_IrqHandler,      // 20 TWI 1
    SPI_IrqHandler,       // 21 Serial Peripheral Interface
    SSC_IrqHandler,       // 22 Serial Synchronous Controller
    TC0_IrqHandler,       // 23 Timer Counter 0
    TC1_IrqHandler,       // 24 Timer Counter 1
    TC2_IrqHandler,       // 25 Timer Counter 2
    TC3_IrqHandler,       // 26 Timer Counter 3
    TC4_IrqHandler,       // 27 Timer Counter 4
    TC5_IrqHandler,       // 28 Timer Counter 5
    ADC_IrqHandler,       // 29 Analog to Digital Converter
    DACC_IrqHandler,       // 30 Digital to Analog Converter
    PWM_IrqHandler,       // 31 Pulse Width Modulation
    CRCCU_IrqHandler,     // 32 CRC Calculation Unit
    ACC_IrqHandler,       // 33 Analog Comparator
    USBD_IrqHandler       // 34 USB Device Port
};
//------------------------------------------------------------------------------



//------------------------------------------------------------------------------
void Dummy_Handler( void )
{
  while ( 1 ) ;
}
//------------------------------------------------------------------------------


