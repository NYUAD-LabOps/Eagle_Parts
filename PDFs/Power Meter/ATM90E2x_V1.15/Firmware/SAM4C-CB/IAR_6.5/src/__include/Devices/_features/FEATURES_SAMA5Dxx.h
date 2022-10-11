/*----------------------------------------------------------------------------
*         ATMEL Microcontroller Software Support  -  ROUSSET  -
*----------------------------------------------------------------------------
* The software is delivered "AS IS" without warranty or condition of any
* kind, either express, implied or statutory. This includes without
* limitation any warranty or condition with respect to merchantability or
* fitness for any particular purpose, or against the infringements of
* intellectual property rights of others.
*----------------------------------------------------------------------------
* File Name           : features_sama5xxxxx.h
* Object              : ATSAM Definition File.
*
* Creation            : Sept/2011
*----------------------------------------------------------------------------
*/
#ifndef _FEATURES_SAMA5Dxx_H
#define _FEATURES_SAMA5Dxx_H



//------------------------------------------------------------------------------
// ----     Devices specific Definitions       ----
//-------------------------------------------------
#if defined __SAMA5D31__
  #include "SAMA5/SAMA5D_FEATURES_31A.h"
#elif defined __SAMA5D33__
  #include "SAMA5/SAMA5D_FEATURES_33A.h"
#elif defined __SAMA5D34__
  #include "SAMA5/SAMA5D_FEATURES_34A.h"
#elif defined __SAMA5D35__
  #include "SAMA5/SAMA5D_FEATURES_35A.h"
#else
  #error Library does not support the specified device.
#endif
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// ----       Core Definitions           ----
//-------------------------------------------
#define DEVICE_CORE_0_TYPE     CORE_TYPE_CA5
#define DEVICE_CORE_0_VERSION  0
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// ----      Device Definitions          ----
//-------------------------------------------
#define DEVICE_NB_INTERRUPTS ID_PERIPH_COUNT
#define DEVICE_HAS_SUPC      0
#define DEVICE_HAS_AIC       1
//...
#define DEVICE_HAS_ACC      0
#define DEVICE_HAS_ADC      1
#define DEVICE_HAS_AES      1
//#define DEVICE_HAS_CAN0     0
//#define DEVICE_HAS_CAN1     0
#define DEVICE_HAS_DAC      0
#define DEVICE_HAS_DBGU     1
#define DEVICE_HAS_DMAC     1
#define DEVICE_HAS_EFC0     0
#define DEVICE_HAS_EFC1     0
//#define DEVICE_HAS_EMAC     1
//#define DEVICE_HAS_GMAC     0
#define DEVICE_HAS_HSMCI0   1
#define DEVICE_HAS_HSMCI1   1
//#define DEVICE_HAS_HSMCI2   1
#define DEVICE_HAS_ISI      1
//#define DEVICE_HAS_LCDC     1
#define DEVICE_HAS_MPDDRC   1
#define DEVICE_HAS_PDC      1
#define DEVICE_HAS_PIOA     1
#define DEVICE_HAS_PIOB     1
#define DEVICE_HAS_PIOC     1
#define DEVICE_HAS_PIOD     1
#define DEVICE_HAS_PIOE     1
#define DEVICE_HAS_PWM      1
#define DEVICE_HAS_RTC      1
#define DEVICE_HAS_RTT      0
#define DEVICE_HAS_SHA      1
#define DEVICE_HAS_SPI0     1
#define DEVICE_HAS_SPI1     1
#define DEVICE_HAS_SSC0     1
#define DEVICE_HAS_SSC1     1
#define DEVICE_HAS_TC0      1
//#define DEVICE_HAS_TC1      0
#define DEVICE_HAS_TDES     1
#define DEVICE_HAS_TRNG     1
#define DEVICE_HAS_TWI0     1
#define DEVICE_HAS_TWI1     1
#define DEVICE_HAS_TWI2     1
//#define DEVICE_HAS_UART0    1
//#define DEVICE_HAS_UART1    1
#define DEVICE_HAS_UDP      1
#define DEVICE_HAS_UHP      1
#define DEVICE_HAS_USART0   1
#define DEVICE_HAS_USART1   1
#define DEVICE_HAS_USART2   1
#define DEVICE_HAS_USART3   1
#define DEVICE_HAS_WDT      1
//...
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// ----        IP Definitions            ----
//-------------------------------------------
//
// ---- ADC ---------------------------------
#define ADC_CHANNELS    (12)
#define ADC_HAS_PDC         (0)
#define ADC_HAS_TRIGGER_REG (1)
//-------------------------------------------

// ---- DBGU --------------------------------
#define DBGU_HAS_PDC     0
//-------------------------------------------

// ---- HSMCI -------------------------------
#define HSMCI_HAS_PDC     (0)
#define HSMCI0_HAS_PDC    (HSMCI_HAS_PDC)
#define HSMCI1_HAS_PDC    (HSMCI_HAS_PDC)
//#define HSMCI2_HAS_PDC    (HSMCI_HAS_PDC)
//--------------------------------------------

// ---- PIO ---------------------------------
#define PIO_HAS_PERIPH_A  1
#define PIO_HAS_PERIPH_B  1
#define PIO_HAS_PERIPH_C  1
#define PIO_HAS_PERIPH_D  0
#define PIO_HAS_PARALLEL_CAPTURE (0)
//-------------------------------------------

// ---- PMC ---------------------------------
#define PMC_HAS_MCKR_FIELD_MDIV     1
#define PMC_HAS_PLLA_TUNING         0
// ************ PLLA TUNING *****************
// (electrical characteristics dependant)
//#define PMC_HAS_PLLAR_FIELD_OUTA    1
//#define PMC_HAS_REG_PLLICPR         1
//#define PLLA_TUNING_F_LOW   400000000
//#define PLLA_TUNING_F_HIGH  800000000
//#define PLLA_TUNING_F_STEP   50000000
// ******************************************

// **************** PLLICPR *****************
// (electrical characteristics dependant)
// ******************************************

// ---- PWM ---------------------------------
#define PWM_HAS_PDC        (0)
#define PWM_HAS_SMMR       (0)
#define PWM_HAS_FPV2       (1)
//--------------------------------------------

// ---- SPI ---------------------------------
#define SPI_HAS_PDC       (0)
#define SPI0_HAS_PDC      SPI_HAS_PDC
#define SPI1_HAS_PDC      SPI_HAS_PDC
//--------------------------------------------

// ---- SSC ---------------------------------
#define SSC_HAS_PDC       (0)
#define SSC0_HAS_PDC      SSC_HAS_PDC
#define SSC1_HAS_PDC      SSC_HAS_PDC
//--------------------------------------------

// ---- TC  ---------------------------------
#define TC_CHANNELS        (3)
#define TC_BMR_HAS_FILTER  (0)
#define TC_HAS_SMMR        (0)
#define TC_HAS_QDEC        (0)
#define TC_HAS_WR_PROTECT  (0)
#define TC_HAS_PDC         (0)
//--------------------------------------------
#define TC0_BMR_HAS_FILTER  TC_BMR_HAS_FILTER
//#define TC1_BMR_HAS_FILTER  TC_BMR_HAS_FILTER
//--------------------------------------------
#define TC0_HAS_SMMR  TC_HAS_SMMR
//#define TC1_HAS_SMMR  TC_HAS_SMMR
//--------------------------------------------
#define TC0_HAS_QDEC  TC_HAS_QDEC
//#define TC1_HAS_QDEC  TC_HAS_QDEC
//--------------------------------------------
#define TC0_HAS_WR_PROTECT  TC_HAS_WR_PROTECT
//#define TC1_HAS_WR_PROTECT  TC_HAS_WR_PROTECT
//-------------------------------------------
#define TC0_HAS_PDC  TC_HAS_PDC
//#define TC1_HAS_PDC  TC_HAS_PDC
//-------------------------------------------

// ---- TWI ---------------------------------
#define TWI_HAS_PDC       (0)
#define TWI0_HAS_PDC      TWI_HAS_PDC
#define TWI1_HAS_PDC      TWI_HAS_PDC
//--------------------------------------------

// ---- UART --------------------------------
//#define UART_HAS_PDC     (1)
//#define UART0_HAS_PDC    (UART_HAS_PDC)
//#define UART1_HAS_PDC    (UART_HAS_PDC)
//-------------------------------------------

// ---- USART -------------------------------
#define USART_HAS_PDC    (0)
#define USART0_HAS_PDC   (USART_HAS_PDC)
#define USART1_HAS_PDC   (USART_HAS_PDC)
#define USART2_HAS_PDC   (USART_HAS_PDC)
#define USART3_HAS_PDC   (USART_HAS_PDC)
//-------------------------------------------

//...
//-------------------------------------------
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// ----    Keys Definition         ----
//-------------------------------------
#define ADC_KEY_VAL    (0x414443u)
#define AIC_KEY_VAL    (0x414943u)
#define MATRIX_KEY_VAL (0x4D4154u)
#define MOR_KEY_VAL    (0x37u)
#define PIO_KEY_VAL    (0x50494Fu)
#define PMC_KEY_VAL    (0x504D43u)
#define PWM_KEY_VAL    (0x50574Du)
#define RSTC_KEY_VAL   (0xA5u)
#define SHDW_KEY_VAL   (0xA5u)
#define SMC_KEY_VAL    (0x534D43u)
#define SPI_KEY_VAL    (0x535049u)
#define SSC_KEY_VAL    (0x535343u)
////#define SUPC_KEY_VAL   0xA5u  
#define TC_KEY_VAL     (0x54494Du)
#define TWI_KEY_VAL    (0x545749u)
#define TRNG_KEY_VAL   (0x524E47u)
#define USART_KEY_VAL  (0x555341u)
#define WDT_KEY_VAL    (0xA5u)
//------------------------------------------------------------------------------



//------------------------------------------------------------------------------
// ----     Devices specific Definitions       ----
//-------------------------------------------------
#if defined __SAMA5D31A__
  #include "SAMA5D_FEATURES_31A.h"
#elif defined __SAMA5D33A__
  #include "SAMA5D_FEATURES_33A.h"
#elif defined __SAMA5D34A__
  #include "SAMA5D_FEATURES_34A.h"
#elif defined __SAMA5D35A__
  #include "SAMA5D_FEATURES_35A.h"
#endif
//------------------------------------------------------------------------------





//------------------------------------------------------------------------------
// ----     Global Definitions           ----
//-------------------------------------------
#define CORE_TYPE_CA5    315
#define CORE_TYPE_CM3    3133
#define CORE_TYPE_CM4    3134
#define CORE_TYPE_ARM7   118137
#define CORE_TYPE_ARM9   118139
//------------------------------------------------------------------------------

#endif //_FEATURES_SAMA5Dxx_H
