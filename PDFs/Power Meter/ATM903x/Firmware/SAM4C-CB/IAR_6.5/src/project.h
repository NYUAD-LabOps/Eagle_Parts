#ifndef _PROJECT_H
#define _PROJECT_H
// ----------------------------------------------------------------------------

//CORE Define 
#define SAM4C_C0 1      // used
#define SAM4C_C1 0      //not used

#define	SoftwareVersion		0x101		//1.01

// ----------------------------------------------------------------------------
//  Package
//#define DEVICE_PACKAGE _QFP64_
#define DEVICE_PACKAGE _QFP100_
// ----------------------------------------------------------------------------
// Board (one define only)
#define SAM4C_VB_LQFP100_REVA
// ----------------------------------------------------------------------------



/// ----------------------------------------------------------------------------
//  Clock config
// ----------------------------------------------------------------------------
#define MAIN_CLK_CONFIG  USE_XTAL  // USE_RC_xMHZ or USE_EXT_CLK or USE_XTAL
#define MCK_CONFIG  USE_PLLB  // USE_MAIN_CLK or USE_PLLx or USE_SLOW_CLK
#define PLLA_MUL 29
#define PLLA_DIV 2
#define PLLB_MUL 25
#define PLLB_DIV 2
#define MCK_PRESCALER   1             // divider value 1,8,16,32,64
#define SLOW_CLK_CONFIG USE_XTAL  // USE_RC_32KHZ or USE_EXT_CLK or USE_XTAL
#define EXT_CLOCK_FREQ  1000000       // Value (Hz) (for external clock only)
#define SLOW_CLOCK_FREQ 32768         // Value (Hz)
// ----------------------------------------------------------------------------

#include "global.h"


// ----------------------------------------------------------------------------
//  User reset
// ----------------------------------------------------------------------------
#define ENABLE_USER_RESET 1       // 1=enable 0=disable
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
//  Watchdog Timer
// ----------------------------------------------------------------------------
#define ENABLE_WDT 0       // 1=enable 0=disable
#define WDT_TIME   5000    // value (ms) or WDT_MAX
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
//  Supply Controller settings
// ----------------------------------------------------------------------------
#define ENABLE_VREG 1       // Internal Voltage Regulator: 1=enable 0=disable
#define ENABLE_BOD  1       // Brownout detector: 1=enable 0=disable

#define ENABLE_SM    1                   // 1=enable 0=disable
#define SM_THRESHOLD SUPC_SMMR_SMTH_2_80V // Supply monitor threshold
//SUPC_SMMR_SMTH_x_xV : between UPC_SMMR_SMTH_1_9V and UPC_SMMR_SMTH_3_4V 
// ----------------------------------------------------------------------------


// ----------------------------------------------------------------------------
#define MAX_CODE_SIZE (0x7FE0) //(0x8000-0x20)
// WARNING: update .icf and project link options when changing this value


#define IFLASH_ADDR IFLASH_CNC_ADDR



#define FLASH_TAG_ADDR (unsigned int*)(IFLASH_ADDR+MAX_CODE_SIZE+0x1C)//FLASH config
#define ISRAM_TAG_ADDR (unsigned int*)(IRAM_ADDR+MAX_CODE_SIZE+0x1C)  //ISRAM config

#ifdef _LINK_TO_ISRAM_ // defined in IAR project options
  #define BINARY_TAG_ADDR   ISRAM_TAG_ADDR
#else
  #define BINARY_TAG_ADDR   FLASH_TAG_ADDR // default=FLASH config
#endif

//#define DEFAULT_BINARY_TAG (0xDEFA0000)

// IAR definitions 
#define INFO_SECTION _Pragma("location=\".info_section\"") // .icf definition
// ----------------------------------------------------------------------------


//#define DONT_USE_CMSIS_INIT //system_samxxx files


#endif /* _PROJECT_H */

