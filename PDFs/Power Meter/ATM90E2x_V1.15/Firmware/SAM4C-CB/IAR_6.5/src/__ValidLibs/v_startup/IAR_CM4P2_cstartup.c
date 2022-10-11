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
#pragma weak ACC_Handler=Dummy_Handler
#pragma weak ADC_Handler=Dummy_Handler
//#pragma weak CRCCU_Handler=Dummy_Handler
#pragma weak AES_Handler=Dummy_Handler
#pragma weak AFEC0_Handler=Dummy_Handler
#pragma weak AFEC1_Handler=Dummy_Handler
#pragma weak ARM_Handler=Dummy_Handler
#pragma weak CAN0_Handler=Dummy_Handler
#pragma weak CAN1_Handler=Dummy_Handler
#pragma weak DACC_Handler=Dummy_Handler
#pragma weak DMAC_Handler=Dummy_Handler
#pragma weak EFC_Handler=Dummy_Handler
#pragma weak GMAC_Handler=Dummy_Handler
#pragma weak HSMCI_Handler=Dummy_Handler
#pragma weak PIOA_Handler=Dummy_Handler
#pragma weak PIOB_Handler=Dummy_Handler
#pragma weak PIOC_Handler=Dummy_Handler
#pragma weak PIOD_Handler=Dummy_Handler
#pragma weak PIOE_Handler=Dummy_Handler
#pragma weak PMC_Handler=Dummy_Handler
#pragma weak PWM_Handler=Dummy_Handler
#pragma weak RSTC_Handler=Dummy_Handler
#pragma weak RTC_Handler=Dummy_Handler
#pragma weak RTT_Handler=Dummy_Handler
#pragma weak SMC_Handler=Dummy_Handler
#pragma weak SPI_Handler=Dummy_Handler
#pragma weak SSC_Handler=Dummy_Handler
#pragma weak SUPC_Handler=Dummy_Handler
#pragma weak TC0_Handler=Dummy_Handler
#pragma weak TC1_Handler=Dummy_Handler
#pragma weak TC2_Handler=Dummy_Handler
#pragma weak TC3_Handler=Dummy_Handler
#pragma weak TC4_Handler=Dummy_Handler
#pragma weak TC5_Handler=Dummy_Handler
#pragma weak TC6_Handler=Dummy_Handler
#pragma weak TC7_Handler=Dummy_Handler
#pragma weak TC8_Handler=Dummy_Handler
#pragma weak TWI0_Handler=Dummy_Handler
#pragma weak TWI1_Handler=Dummy_Handler
#pragma weak UART0_Handler=Dummy_Handler
#pragma weak UART1_Handler=Dummy_Handler
#pragma weak USART0_Handler=Dummy_Handler
#pragma weak USART1_Handler=Dummy_Handler
#pragma weak UDP_Handler=Dummy_Handler
#pragma weak WDT_Handler=Dummy_Handler





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
    SUPC_Handler,      // 0  SUPPLY CONTROLLER
    RSTC_Handler,      // 1  RESET CONTROLLER
    RTC_Handler,       // 2  REAL TIME CLOCK
    RTT_Handler,       // 3  REAL TIME TIMER
    WDT_Handler,       // 4  WATCHDOG TIMER
    PMC_Handler,       // 5  PMC
    EFC_Handler,       // 6  EEFC
    UART0_Handler,     // 7  UART0
    SMC_Handler,       // 8 SMC
    PIOA_Handler,      // 9 Parallel IO Controller A
    PIOB_Handler,      // 10 Parallel IO Controller B
    PIOC_Handler,      // 11 Parallel IO Controller C
    PIOD_Handler,      // 12 Parallel IO Controller B
    PIOE_Handler,      // 13 Parallel IO Controller C
    USART0_Handler,    // 14 USART 0
    USART1_Handler,    // 15 USART 1
    IrqHandlerNotUsed,    // 16 Reserved
    TWI0_Handler,      // 17 TWI 0
    TWI1_Handler,      // 18 TWI 1
    SPI_Handler,       // 19 Serial Peripheral Interface
    DMAC_Handler,      // 20 Serial Peripheral Interface
    TC0_Handler,       // 21 Timer Counter 0
    TC1_Handler,       // 22 Timer Counter 1
    TC2_Handler,       // 23 Timer Counter 2
    TC3_Handler,       // 24 Timer Counter 3
    TC4_Handler,       // 25 Timer Counter 4
    TC5_Handler,       // 26 Timer Counter 5
    TC6_Handler,       // 27 Timer Counter 2
    TC7_Handler,       // 28 Timer Counter 3
    TC8_Handler,       // 29 Timer Counter 4
    AFEC0_Handler,     // 30 Analog to Digital Converter
    AFEC1_Handler,     // 31 Analog to Digital Converter
    DACC_Handler,      // 32 Digital to Analog Converter
    ACC_Handler,       // 33 Analog Comparator
    ARM_Handler,       // 34 Analog Comparator
    UDP_Handler,       // 35 USB Device Port
    PWM_Handler,       // 36 Pulse Width Modulation
    CAN0_Handler,      // 37
    CAN1_Handler,      // 38
    AES_Handler,       // 39
    IrqHandlerNotUsed,    // 40  Reserved    
    IrqHandlerNotUsed,    // 41  Reserved    
    IrqHandlerNotUsed,    // 42  Reserved    
    IrqHandlerNotUsed,    // 43  Reserved    
    GMAC_Handler,      // 44  
    UART0_Handler      // 45  UART0
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
    SUPC_Handler,      // 0  SUPPLY CONTROLLER
    RSTC_Handler,      // 1  RESET CONTROLLER
    RTC_Handler,       // 2  REAL TIME CLOCK
    RTT_Handler,       // 3  REAL TIME TIMER
    WDT_Handler,       // 4  WATCHDOG TIMER
    PMC_Handler,       // 5  PMC
    EFC_Handler,       // 6  EEFC
    UART0_Handler,     // 7  UART0
    SMC_Handler,       // 8 SMC
    PIOA_Handler,      // 9 Parallel IO Controller A
    PIOB_Handler,      // 10 Parallel IO Controller B
    PIOC_Handler,      // 11 Parallel IO Controller C
    PIOD_Handler,      // 12 Parallel IO Controller B
    PIOE_Handler,      // 13 Parallel IO Controller C
    USART0_Handler,    // 14 USART 0
    USART1_Handler,    // 15 USART 1
    IrqHandlerNotUsed,    // 16 Reserved
    TWI0_Handler,      // 17 TWI 0
    TWI1_Handler,      // 18 TWI 1
    SPI_Handler,       // 19 Serial Peripheral Interface
    DMAC_Handler,      // 20 Serial Peripheral Interface
    TC0_Handler,       // 21 Timer Counter 0
    TC1_Handler,       // 22 Timer Counter 1
    TC2_Handler,       // 23 Timer Counter 2
    TC3_Handler,       // 24 Timer Counter 3
    TC4_Handler,       // 25 Timer Counter 4
    TC5_Handler,       // 26 Timer Counter 5
    TC6_Handler,       // 27 Timer Counter 2
    TC7_Handler,       // 28 Timer Counter 3
    TC8_Handler,       // 29 Timer Counter 4
    AFEC0_Handler,     // 30 Analog to Digital Converter
    AFEC1_Handler,     // 31 Analog to Digital Converter
    DACC_Handler,      // 32 Digital to Analog Converter
    ACC_Handler,       // 33 Analog Comparator
    ARM_Handler,       // 34 Analog Comparator
    UDP_Handler,       // 35 USB Device Port
    PWM_Handler,       // 36 Pulse Width Modulation
    CAN0_Handler,      // 37
    CAN1_Handler,      // 38
    AES_Handler,       // 39
    IrqHandlerNotUsed,    // 40  Reserved    
    IrqHandlerNotUsed,    // 41  Reserved    
    IrqHandlerNotUsed,    // 42  Reserved    
    IrqHandlerNotUsed,    // 43  Reserved    
    GMAC_Handler,      // 44  
    UART0_Handler      // 45  UART0
};
//------------------------------------------------------------------------------



//------------------------------------------------------------------------------
void Dummy_Handler( void )
{
  while ( 1 ) ;
}
//------------------------------------------------------------------------------


