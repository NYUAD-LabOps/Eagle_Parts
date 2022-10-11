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
#ifndef _VALID_PATCH_SAM3S8_H
#define _VALID_PATCH_SAM3S8_H


//------------------------------------------------------------------------------
// ---- Bug reference:                          
//------------------------------------------------------------------------------
//#undef
//#define
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// ---- SOC naming compatibility
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// ---- Bug reference: EFC missing definitions
//------------------------------------------------------------------------------
#ifndef EEFC_FCR_FKEY
  #define EEFC_FCR_FKEY(value) ((EEFC_FCR_FKEY_Msk & ((value) << EEFC_FCR_FKEY_Pos)))
#endif

#ifndef EEFC_FCR_FCMD
  #define EEFC_FCR_FCMD(value) ((EEFC_FCR_FCMD_Msk & ((value) << EEFC_FCR_FCMD_Pos)))
#endif
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// ---- Bug reference: iSOC naming update
//------------------------------------------------------------------------------
//#define PMC_MCKR_PRES_CLK_1 PMC_MCKR_PRES_CLK
#define IFLASH_PAGE_SIZE         IFLASH0_PAGE_SIZE
#define IFLASH_LOCK_REGION_SIZE  IFLASH0_LOCK_REGION_SIZE
#define IFLASH_NB_OF_PAGES       IFLASH0_NB_OF_PAGES
#define IFLASH_NB_OF_LOCK_BITS   IFLASH0_NB_OF_LOCK_BITS
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// ---- Feature file inclusion
//------------------------------------------------------------------------------
#include "Devices/_features/FEATURES_SAM3Sxx.h"
/*
#if defined __SAM3SD8A__
  #include "Devices/_features/FEATURES_SAM3S8C.h"//ERr
#elif defined __SAM3SD8B__
  #include "Devices/_features/FEATURES_SAM3S8C.h"//ERr
#elif defined __SAM3SD8C__
  #include "Devices/_features/FEATURES_SAM3S8C.h"//ERr
#elif defined __SAM3S8A__
  #include "Devices/_features/FEATURES_SAM3S8C.h"//ERr
#elif defined __SAM3S8B__
  #include "Devices/_features/FEATURES_SAM3S8C.h"//ERr
#elif defined __SAM3S8C__
  #include "Devices/_features/FEATURES_SAM3S8C.h"
#else
  #error Library does not support the specified device.
#endif
*/
//------------------------------------------------------------------------------

#endif//_VALID_PATCH_SAM3S8_H
