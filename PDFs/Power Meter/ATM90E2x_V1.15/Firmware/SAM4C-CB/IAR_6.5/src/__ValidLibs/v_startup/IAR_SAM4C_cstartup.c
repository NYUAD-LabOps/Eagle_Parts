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
// Updated for SOC : AYi / 11/2012


// ------ Compatibility list (compliant devices) ------------------------------
// SAM3Sx (tested : SAM4C)
// ---------------------- (file created for SAM4C) ----------------------------
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
    //SUPC->SUPC_MR =0xa5005a00;
   //supc_enable_voltage_regulator(); //----ZTZ----2013/07/29----
   
#if (SAM4C_C0==1)
  unsigned int  read_reg;
   //  --------- EFC Init
   //REG_EFC_FMR = AT91C_EFC_FWS_6WS; // 1 Wait State necessary to work at more than 30 MHz
  #ifdef REG_EFC_FMR
   REG_EFC_FMR = EEFC_FMR_CLOE | EEFC_FMR_FWS(6); // 6 Wait states, other fields=0 (defaults)
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
#elif (SAM4C_C1==1)   

#else
     #error CORE not specified.
#endif

   
  return 1; 
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------




//------------------------------------------------------------------------------
/// Exceptions handlers
//------------------------------------------------------------------------------
/* Cortex-M4 core handlers */
#pragma weak NMI_Handler
#pragma weak HardFault_Handler
#pragma weak MemManage_Handler
#pragma weak BusFault_Handler
#pragma weak UsageFault_Handler
#pragma weak SVC_Handler
#pragma weak DebugMon_Handler
#pragma weak PendSV_Handler
#pragma weak SysTick_Handler

/* Peripherals handlers */
#pragma weak SUPC_IrqHandler=Dummy_Handler
#pragma weak RSTC_IrqHandler=Dummy_Handler
#pragma weak RTC_IrqHandler=Dummy_Handler
#pragma weak RTT_IrqHandler=Dummy_Handler
#pragma weak WDT_IrqHandler=Dummy_Handler
#pragma weak PMC_IrqHandler=Dummy_Handler
#pragma weak EFC_IrqHandler=Dummy_Handler
#pragma weak UART0_IrqHandler=Dummy_Handler
#pragma weak PIOA_IrqHandler=Dummy_Handler
#pragma weak PIOB_IrqHandler=Dummy_Handler
#pragma weak USART0_IrqHandler=Dummy_Handler
#pragma weak USART1_IrqHandler=Dummy_Handler
#pragma weak USART2_IrqHandler=Dummy_Handler
#pragma weak USART3_IrqHandler=Dummy_Handler
#pragma weak USART4_IrqHandler=Dummy_Handler
#pragma weak TWI0_IrqHandler=Dummy_Handler
#pragma weak TWI1_IrqHandler=Dummy_Handler
#pragma weak SPI0_IrqHandler=Dummy_Handler
#pragma weak TC0_IrqHandler=Dummy_Handler
#pragma weak TC1_IrqHandler=Dummy_Handler
#pragma weak TC2_IrqHandler=Dummy_Handler
#pragma weak TC3_IrqHandler=Dummy_Handler
#pragma weak TC4_IrqHandler=Dummy_Handler
#pragma weak TC5_IrqHandler=Dummy_Handler
#pragma weak ADC_IrqHandler=Dummy_Handler
#pragma weak ARM1_IrqHandler=Dummy_Handler
#pragma weak IPC0_IrqHandler=Dummy_Handler
#pragma weak SLCDC_IrqHandler=Dummy_Handler
#pragma weak TRNG_IrqHandler=Dummy_Handler
#pragma weak ICM_IrqHandler=Dummy_Handler
#ifdef _SAM4C_CPKCC_INSTANCE_
#pragma weak CPKCC_IrqHandler=Dummy_Handler
#endif /* _SAM4C_CPKCC_INSTANCE_ */
#pragma weak AES_IrqHandler=Dummy_Handler
#pragma weak PIOC_IrqHandler=Dummy_Handler
#pragma weak UART1_IrqHandler=Dummy_Handler
#pragma weak IPC1_IrqHandler=Dummy_Handler
#pragma weak SPI1_IrqHandler=Dummy_Handler
#pragma weak PWM_IrqHandler=Dummy_Handler
#ifdef _SAM4C_SRAM_INSTANCE_
#pragma weak SRAM_IrqHandler=Dummy_Handler
#endif /* _SAM4C_SRAM_INSTANCE_ */


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
//Loc duplicate function
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
const intvec_elem vector_table[] =
{
    { .__ptr = __sfe( "CSTACK" ) },
     __iar_program_start,
     NMI_Handler,
     HardFault_Handler,
     MemManage_Handler,
     BusFault_Handler,
     UsageFault_Handler,
     (0UL),          /* Reserved */
     (0UL),          /* Reserved */
     (0UL),          /* Reserved */
     (0UL),          /* Reserved */
     SVC_Handler,
     DebugMon_Handler,
     (0UL),          /* Reserved */
     PendSV_Handler,
     SysTick_Handler,
     
     /* Configurable interrupts */
     SUPC_IrqHandler,   /* 0  Supply Controller */
     RSTC_IrqHandler,   /* 1  Reset Controller */
     RTC_IrqHandler,    /* 2  Real Time Clock */
     RTT_IrqHandler,    /* 3  Real Time Timer */
     WDT_IrqHandler,    /* 4  Watchdog Timer */
     PMC_IrqHandler,    /* 5  Power Management Controller */
     EFC_IrqHandler,    /* 6  Enhanced Embedded Flash Controller */
     (0UL),             /* 7 Reserved */
     UART0_IrqHandler,  /* 8  UART 0 */
     (0UL),             /* 9 Reserved */
     (0UL),             /* 10 Reserved */
     PIOA_IrqHandler,   /* 11 Parallel I/O Controller A */
     PIOB_IrqHandler,   /* 12 Parallel I/O Controller B */
     (0UL),             /* 13 Reserved */
     USART0_IrqHandler, /* 14 USART 0 */
     USART1_IrqHandler, /* 15 USART 1 */
     USART2_IrqHandler, /* 16 USART 2 */
     USART3_IrqHandler, /* 17 USART 3 */
     USART4_IrqHandler, /* 18 USART 4 */
     TWI0_IrqHandler,   /* 19 Two Wire Interface 0 */
     TWI1_IrqHandler,   /* 20 Two Wire Interface 1 */
     SPI0_IrqHandler,   /* 21 Serial Peripheral Interface 0 */
     (0UL),             /* 22 Reserved */
     TC0_IrqHandler,    /* 23 Timer/Counter 0 */
     TC1_IrqHandler,    /* 24 Timer/Counter 1 */
     TC2_IrqHandler,    /* 25 Timer/Counter 2 */
     TC3_IrqHandler,    /* 26 Timer/Counter 3 */
     TC4_IrqHandler,    /* 27 Timer/Counter 4 */
     TC5_IrqHandler,    /* 28 Timer/Counter 5 */
     ADC_IrqHandler,    /* 29 Analog To Digital Converter */
     ARM1_IrqHandler,   /* 30 FPU signals : FPIXC, FPOFC, FPUFC, FPIOC, FPDZC, FPIDC, FPIXC */
     IPC0_IrqHandler,   /* 31 Interprocessor communication 0 */
     SLCDC_IrqHandler,  /* 32 Segment LCD Controller */
     TRNG_IrqHandler,   /* 33 True Random Generator */
     ICM_IrqHandler,    /* 34 Integrity Check Module */
#ifdef _SAM4C_CPKCC_INSTANCE_
     CPKCC_IrqHandler,  /* 35 Public Key Cryptography Controller */
#else
     (0UL),          /* 35 Reserved */
#endif /* _SAM4C_CPKCC_INSTANCE_ */
    AES_IrqHandler,    /* 36 Advanced Enhanced Standard */
    PIOC_IrqHandler,   /* 37 Parallel I/O Controller C */
    UART1_IrqHandler,  /* 38 UART 1 */
    IPC1_IrqHandler,   /* 39 Interprocessor communication 1 */
    SPI1_IrqHandler,   /* 40 Serial Peripheral Interface 1 */
    PWM_IrqHandler,    /* 41 Pulse Width Modulation */
#ifdef _SAM4C_SRAM_INSTANCE_
    SRAM_IrqHandler    /* 42 SRAM1, SRAM2 */
#else
    (0UL)           /* 42 Reserved */
#endif /* _SAM4C_SRAM_INSTANCE_ */

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
     (0UL),          /* Reserved */
     (0UL),          /* Reserved */
     (0UL),          /* Reserved */
     (0UL),          /* Reserved */
     SVC_Handler,
     DebugMon_Handler,
     (0UL),          /* Reserved */
     PendSV_Handler,
     SysTick_Handler,
     
     /* Configurable interrupts */
     SUPC_IrqHandler,   /* 0  Supply Controller */
     RSTC_IrqHandler,   /* 1  Reset Controller */
     RTC_IrqHandler,    /* 2  Real Time Clock */
     RTT_IrqHandler,    /* 3  Real Time Timer */
     WDT_IrqHandler,    /* 4  Watchdog Timer */
     PMC_IrqHandler,    /* 5  Power Management Controller */
     EFC_IrqHandler,    /* 6  Enhanced Embedded Flash Controller */
     (0UL),             /* 7 Reserved */
     UART0_IrqHandler,  /* 8  UART 0 */
     (0UL),             /* 9 Reserved */
     (0UL),             /* 10 Reserved */
     PIOA_IrqHandler,   /* 11 Parallel I/O Controller A */
     PIOB_IrqHandler,   /* 12 Parallel I/O Controller B */
     (0UL),             /* 13 Reserved */
     USART0_IrqHandler, /* 14 USART 0 */
     USART1_IrqHandler, /* 15 USART 1 */
     USART2_IrqHandler, /* 16 USART 2 */
     USART3_IrqHandler, /* 17 USART 3 */
     USART4_IrqHandler, /* 18 USART 4 */
     TWI0_IrqHandler,   /* 19 Two Wire Interface 0 */
     TWI1_IrqHandler,   /* 20 Two Wire Interface 1 */
     SPI0_IrqHandler,   /* 21 Serial Peripheral Interface 0 */
     (0UL),             /* 22 Reserved */
     TC0_IrqHandler,    /* 23 Timer/Counter 0 */
     TC1_IrqHandler,    /* 24 Timer/Counter 1 */
     TC2_IrqHandler,    /* 25 Timer/Counter 2 */
     TC3_IrqHandler,    /* 26 Timer/Counter 3 */
     TC4_IrqHandler,    /* 27 Timer/Counter 4 */
     TC5_IrqHandler,    /* 28 Timer/Counter 5 */
     ADC_IrqHandler,    /* 29 Analog To Digital Converter */
     ARM1_IrqHandler,   /* 30 FPU signals : FPIXC, FPOFC, FPUFC, FPIOC, FPDZC, FPIDC, FPIXC */
     IPC0_IrqHandler,   /* 31 Interprocessor communication 0 */
     SLCDC_IrqHandler,  /* 32 Segment LCD Controller */
     TRNG_IrqHandler,   /* 33 True Random Generator */
     ICM_IrqHandler,    /* 34 Integrity Check Module */
#ifdef _SAM4C_CPKCC_INSTANCE_
     CPKCC_IrqHandler,  /* 35 Public Key Cryptography Controller */
#else
     (0UL),          /* 35 Reserved */
#endif /* _SAM4C_CPKCC_INSTANCE_ */
    AES_IrqHandler,    /* 36 Advanced Enhanced Standard */
    PIOC_IrqHandler,   /* 37 Parallel I/O Controller C */
    UART1_IrqHandler,  /* 38 UART 1 */
    IPC1_IrqHandler,   /* 39 Interprocessor communication 1 */
    SPI1_IrqHandler,   /* 40 Serial Peripheral Interface 1 */
    PWM_IrqHandler,    /* 41 Pulse Width Modulation */
#ifdef _SAM4C_SRAM_INSTANCE_
    SRAM_IrqHandler    /* 42 SRAM1, SRAM2 */
#else
    (0UL)           /* 42 Reserved */
#endif /* _SAM4C_SRAM_INSTANCE_ */

};
//------------------------------------------------------------------------------



//------------------------------------------------------------------------------
void Dummy_Handler( void )
{
  while ( 1 ) ;
}
//------------------------------------------------------------------------------


