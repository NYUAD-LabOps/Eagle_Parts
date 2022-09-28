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
#ifndef _VALID_PATCH_SAM3S_H
#define _VALID_PATCH_SAM3S_H


//------------------------------------------------------------------------------
// ---- Bug reference:                          
//------------------------------------------------------------------------------
//#undef
//#define
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
// ---- Bug reference: iSOC naming
//------------------------------------------------------------------------------
#undef  IFLASH_NB_OF_LOCK_BITS
#define IFLASH0_NB_OF_LOCK_BITS  (4u)
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// ---- Bug reference: iSOC naming update
//------------------------------------------------------------------------------
#ifndef CKGR_MOR_MOSCRCF_4_MHz
  #define CKGR_MOR_MOSCRCF_4_MHz CKGR_MOR_MOSCRCF_4MHz
#endif
#ifndef CKGR_MOR_MOSCRCF_8_MHz
  #define CKGR_MOR_MOSCRCF_8_MHz CKGR_MOR_MOSCRCF_8MHz
#endif
#ifndef CKGR_MOR_MOSCRCF_12_MHz
  #define CKGR_MOR_MOSCRCF_12_MHz CKGR_MOR_MOSCRCF_12MHz
#endif

// Corrected
//#define PMC_MCKR_PRES_CLK_1 PMC_MCKR_PRES_CLK
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// ---- Feature file inclusion
//------------------------------------------------------------------------------
#include "Devices/_features/FEATURES_SAM3Sxx.h"
/*
#if defined __SAM3S1A__
  #include "Devices/_features/FEATURES_SAM3S1B.h"//ERr
#elif defined __SAM3S1B__
  #include "Devices/_features/FEATURES_SAM3S1B.h"
#elif defined __SAM3S1C__
  #include "Devices/_features/FEATURES_SAM3S1B.h"//ERr
#elif defined __SAM3S2A__
  #include "Devices/_features/FEATURES_SAM3S1B.h"//ERr
#elif defined __SAM3S2B__
  #include "Devices/_features/FEATURES_SAM3S1B.h"//ERr
#elif defined __SAM3S2C__
  #include "Devices/_features/FEATURES_SAM3S1B.h"//ERr
#elif defined __SAM3S4A__
  #include "Devices/_features/FEATURES_SAM3S1B.h"//ERr
#elif defined __SAM3S4B__
  #include "Devices/_features/FEATURES_SAM3S1B.h"//ERr
#elif defined __SAM3S4C__
  #include "Devices/_features/FEATURES_SAM3S1B.h"//ERr
#else
  #error Library does not support the specified device.
#endif
*/
//------------------------------------------------------------------------------

#endif//_VALID_PATCH_SAM3S_H
