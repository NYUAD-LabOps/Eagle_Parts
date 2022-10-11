#ifndef _HTOL_TEST_LIST_CHECK_H
#define _HTOL_TEST_LIST_CHECK_H


#include "device.h"

// ---- Validation libraries
#include "v_dbgu.h"


// ----------------------------------------------------------------------------
//  Exclude debug UART from HTOL test when debug mode is set on DBGU
// ----------------------------------------------------------------------------
#if (DEBUG_MODE == DBGU)
  #if (ID_DBGU == ID_UART0)
    #undef   TST_UART0
    #define  TST_UART0 0
    #warning "HTOL test list: UART0 used for debug traces : disabling test"
  #elif (ID_DBGU == ID_UART1)
    #undef   TST_UART1
    #define  TST_UART1 0
    #warning "HTOL test list: UART1 used for debug traces : disabling test"
  #elif (ID_DBGU == ID_USART0)
    #undef   TST_USART0
    #define  TST_USART0 0
    #warning "HTOL test list: USART0 used for debug traces : disabling test"
  #elif (ID_DBGU == ID_USART1)
    #undef   TST_USART1
    #define  TST_USART1 0
    #warning "HTOL test list: USART1 used for debug traces : disabling test"
  #endif
#endif


// ----------------------------------------------------------------------------
//  HTOL Test check (all tests are not applicable for all devices)
// ----------------------------------------------------------------------------
#if (TST_ACC==1)
  #ifndef ID_ACC
    #undef   TST_ACC
    #define  TST_ACC 0
    #warning "HTOL test list: ACC does not exist in selected device : disabling test"
  #endif
#endif
//------------------------------------------------------------------------------
#if (TST_ADC==1)
  #ifndef ID_ADC
    #undef   TST_ADC
    #define  TST_ADC 0
    #warning "HTOL test list: ADC does not exist in selected device : disabling test"
  #endif
#endif
//------------------------------------------------------------------------------
#if (TST_CRCCU==1)
  #ifndef ID_CRCCU
    #undef   TST_CRCCU
    #define  TST_CRCCU 0
    #warning "HTOL test list: CRCCU does not exist in selected device : disabling test"
  #endif
#endif
//------------------------------------------------------------------------------
#if (TST_DACC==1)
  #ifndef ID_DACC
    #undef   TST_DACC
    #define  TST_DACC 0
    #warning "HTOL test list: DACC does not exist in selected device : disabling test"
  #endif
#endif
//------------------------------------------------------------------------------
#if (TST_PIOA==1)
  #ifndef ID_PIOA
    #undef   TST_PIOA
    #define  TST_PIOA 0
    #warning "HTOL test list: PIOA does not exist in selected device : disabling test"
  #endif
#endif
#if (TST_PIOB==1)
  #ifndef ID_PIOB
    #undef   TST_PIOB
    #define  TST_PIOB 0
    #warning "HTOL test list: PIOB does not exist in selected device : disabling test"
  #endif
#endif
#if (TST_PIOC==1)
  #ifndef ID_PIOC
    #undef   TST_PIOC
    #define  TST_PIOC 0
    #warning "HTOL test list: PIOC does not exist in selected device : disabling test"
  #endif
#endif
#if (TST_PIOD==1)
  #ifndef ID_PIOD
    #undef   TST_PIOD
    #define  TST_PIOD 0
    #warning "HTOL test list: PIOD does not exist in selected device : disabling test"
  #endif
#endif
#if (TST_PIOE==1)
  #ifndef ID_PIOE
    #undef   TST_PIOE
    #define  TST_PIOE 0
    #warning "HTOL test list: PIOE does not exist in selected device : disabling test"
  #endif
#endif
//------------------------------------------------------------------------------
#if (TST_PWM==1)
  #ifndef ID_PWM
    #undef   TST_PWM
    #define  TST_PWM 0
    #warning "HTOL test list: XXX does not exist in selected device : disabling test"
  #endif
#endif
//------------------------------------------------------------------------------
#if (TST_RTC==1)
  #ifndef ID_RTC
    #undef   TST_RTC
    #define  TST_RTC 0
    #warning "HTOL test list: RTC does not exist in selected device : disabling test"
  #endif
#endif
//------------------------------------------------------------------------------
#if (TST_RTT==1)
  #ifndef ID_RTT
    #undef   TST_RTT
    #define  TST_RTT 0
    #warning "HTOL test list: RTT does not exist in selected device : disabling test"
  #endif
#endif
// ----------------------------------------------------------------------------
#if (TST_SPI==1) // single SPI controller
  #ifndef ID_SPI
    #undef   TST_SPI
    #define  TST_SPI 0
    #warning "HTOL test list: SPI does not exist in selected device : disabling test"
  #endif
#endif
#if (TST_SPI0==1)
  #ifndef ID_SPI0
    #undef   TST_SPI0
    #define  TST_SPI0 0
    #warning "HTOL test list: SPI0 does not exist in selected device : disabling test"
  #endif
#endif
#if (TST_SPI1==1)
  #ifndef ID_SPI1
    #undef   TST_SPI1
    #define  TST_SPI1 0
    #warning "HTOL test list: SPI1 does not exist in selected device : disabling test"
  #endif
#endif
//------------------------------------------------------------------------------
#if (TST_SSC==1) // single SSC controller
  #ifndef ID_SSC
    #undef   TST_SSC
    #define  TST_SSC 0
    #warning "HTOL test list: SSC does not exist in selected device : disabling test"
  #endif
#endif
#if (TST_SSC0==1)
  #ifndef ID_SSC0
    #undef   TST_SSC0
    #define  TST_SSC0 0
    #warning "HTOL test list: SSC0 does not exist in selected device : disabling test"
  #endif
#endif
#if (TST_SSC1==1)
  #ifndef ID_SSC1
    #undef   TST_SSC1
    #define  TST_SSC1 0
    #warning "HTOL test list: SSC1 does not exist in selected device : disabling test"
  #endif
#endif
//------------------------------------------------------------------------------
#if (TST_TC_0_1_2==1)
  #ifndef ID_TC0
    #undef   TST_TC_0_1_2
    #define  TST_TC_0_1_2 0
    #warning "HTOL test list: TC0, TC1 and TC2 don't exist in selected device : disabling test"
  #endif
#endif
#if (TST_TC_3_4_5==1)
  #ifndef ID_TC3
    #undef   TST_TC_3_4_5
    #define  TST_TC_3_4_5 0
    #warning "HTOL test list: TC3, TC4 and TC5 don't exist in selected device : disabling test"
  #endif
#endif
// ----------------------------------------------------------------------------
#if (TST_TWI0==1)
  #ifndef ID_TWI0
    #undef   TST_TWI0
    #define  TST_TWI0 0
    #warning "HTOL test list: TWI0 does not exist in selected device : disabling test"
  #endif
#endif
#if (TST_TWI1==1)
  #ifndef ID_TWI1
    #undef   TST_TWI1
    #define  TST_TWI1 0
    #warning "HTOL test list: TWI1 does not exist in selected device : disabling test"
  #endif
#endif
//------------------------------------------------------------------------------
#if (TST_UART0==1)
  #ifndef ID_UART0
    #undef   TST_UART0
    #define  TST_UART0 0
    #warning "HTOL test list: UART0 does not exist in selected device : disabling test"
  #endif
#endif
#if (TST_UART1==1)
  #ifndef ID_UART1
    #undef   TST_UART1
    #define  TST_UART1 0
    #warning "HTOL test list: UART1 does not exist in selected device : disabling test"
  #endif
#endif
//------------------------------------------------------------------------------
#if (TST_USART0==1)
  #ifndef ID_USART0
    #undef   TST_USART0
    #define  TST_USART0 0
    #warning "HTOL test list: USART0 does not exist in selected device : disabling test"
  #endif
#endif
#if (TST_USART1==1)
  #ifndef ID_USART1
    #undef   TST_USART1
    #define  TST_USART1 0
    #warning "HTOL test list: USART1 does not exist in selected device : disabling test"
  #endif
#endif
//------------------------------------------------------------------------------




#endif // _HTOL_TEST_LIST_CHECK_H

