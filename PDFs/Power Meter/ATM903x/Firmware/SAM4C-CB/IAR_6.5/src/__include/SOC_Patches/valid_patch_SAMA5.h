/*----------------------------------------------------------------------------
*         ATMEL Microcontroller Software Support  -  ROUSSET  -
*----------------------------------------------------------------------------
* The software is delivered "AS IS" without warranty or condition of any
* kind, either express, implied or statutory. This includes without
* limitation any warranty or condition with respect to merchantability or
* fitness for any particular purpose, or against the infringements of
* intellectual property rights of others.
*----------------------------------------------------------------------------
* File Name           : 
* Object              : ATSAM Definition File.
*
* Creation            : 08/Oct/2011
*----------------------------------------------------------------------------
*/
#ifndef _VALID_PATCH_SAMA5_H
#define _VALID_PATCH_SAMA5_H


//------------------------------------------------------------------------------
// ---- Bug reference: ADC MR field missing in datasheet
//------------------------------------------------------------------------------
#define ADC_MR_TRANSFER_Pos 28
#define ADC_MR_TRANSFER_Msk (0x3u << ADC_MR_TRANSFER_Pos) //brief (ADC_MR) Transfer Period
#define ADC_MR_TRANSFER(value) ((ADC_MR_TRANSFER_Msk & ((value) << ADC_MR_TRANSFER_Pos)))
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// ---- Bug reference: BSCR definition (DS issue)
//------------------------------------------------------------------------------
#undef BSC_CR_BOOT_Pos
#undef BSC_CR_BOOT_Msk
#undef BSC_CR_BOOT
#undef BSC_CR_BOOTKEY_Pos
#undef BSC_CR_BOOTKEY_Msk
#undef BSC_CR_BOOTKEY_VALID
#define BSC_CR_BOOT_Pos 0
#define BSC_CR_BOOT_Msk (0xffffu << BSC_CR_BOOT_Pos)
#define BSC_CR_BOOT(value) ((BSC_CR_BOOT_Msk & ((value) << BSC_CR_BOOT_Pos)))
#define BSC_CR_BOOTKEY_Pos 16
#define BSC_CR_BOOTKEY_Msk (0xffffu << BSC_CR_BOOTKEY_Pos)
#define BSC_CR_BOOTKEY_VALID (0x6683u << BSC_CR_BOOTKEY_Pos)
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// ---- Bug reference: PLLAR register definition (DS issue)
//------------------------------------------------------------------------------
#undef  CKGR_PLLAR_OUTA_Msk
#define CKGR_PLLAR_OUTA_Msk (0xFu << CKGR_PLLAR_OUTA_Pos)
//#define CKGR_PLLAR_OUTA(value) ((CKGR_PLLAR_OUTA_Msk & ((value) << CKGR_PLLAR_OUTA_Pos)))
#undef  CKGR_PLLAR_MULA_Pos
#define CKGR_PLLAR_MULA_Pos 18
//#define CKGR_PLLAR_MULA_Msk (0x7ffu << CKGR_PLLAR_MULA_Pos)
//#define CKGR_PLLAR_MULA(value) ((CKGR_PLLAR_MULA_Msk & ((value) << CKGR_PLLAR_MULA_Pos)))
#undef  PMC_PLLICPR_ICPLLA
#define PMC_PLLICPR_ICPLLA_Pos 0
#define PMC_PLLICPR_ICPLLA_Msk (0x3u << PMC_PLLICPR_ICPLLA_Pos)
#define PMC_PLLICPR_ICPLLA(value) ((PMC_PLLICPR_ICPLLA_Msk & ((value) << PMC_PLLICPR_ICPLLA_Pos)))
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// ---- compatibility with SAM3xx & SAM4xx iSOC defines
//------------------------------------------------------------------------------
// ---- PMC ----------------------------------------------
#define PMC_MCKR_PRES_CLK_1    PMC_MCKR_PRES_CLOCK
#define PMC_MCKR_PRES_CLK_2    PMC_MCKR_PRES_CLOCK_DIV2
#define PMC_MCKR_PRES_CLK_4    PMC_MCKR_PRES_CLOCK_DIV4
#define PMC_MCKR_PRES_CLK_8    PMC_MCKR_PRES_CLOCK_DIV8
#define PMC_MCKR_PRES_CLK_16   PMC_MCKR_PRES_CLOCK_DIV16
#define PMC_MCKR_PRES_CLK_32   PMC_MCKR_PRES_CLOCK_DIV32
#define PMC_MCKR_PRES_CLK_64   PMC_MCKR_PRES_CLOCK_DIV64
//#define PMC_MCKR_PRES_CLK_3  //not supported ?
#define PMC_PCK_CSS_MCK        PMC_PCK_CSS_MCK_CLK
#define CKGR_PLLAR_ONE         CKGR_PLLAR_STUCKTO1
//--------------------------------------------------------
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// ---- Feature file inclusion
//------------------------------------------------------------------------------
#include "Devices/_features/FEATURES_SAMA5Dxx.h"
/*
#if defined __SAMA5CD34A__
  #include "Devices/_features/FEATURES_SAMA5CD34A.h"
#elif defined __SAMA5CD35A__
  #include "Devices/_features/FEATURES_SAMA5CD34A.h"//ERr
#elif defined __SAMA5D31A__
  #include "Devices/_features/FEATURES_SAMA5CD34A.h"//ERr
#elif defined __SAMA5D33A__
  #include "Devices/_features/FEATURES_SAMA5CD34A.h"//ERr
#elif defined __SAMA5D34A__
  #include "Devices/_features/FEATURES_SAMA5CD34A.h"//ERr
#elif defined __SAMA5D35A__
  #include "Devices/_features/FEATURES_SAMA5CD34A.h"//ERr
#else
  #error Library does not support the specified device.
#endif
*/
//------------------------------------------------------------------------------

#endif//_VALID_PATCH_SAMA5_H
