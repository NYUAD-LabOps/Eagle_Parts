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
#ifndef _VALID_PATCH_SAM4N_H
#define _VALID_PATCH_SAM4N_H



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
// ---- Bug reference: missing components
//------------------------------------------------------------------------------
//typedef volatile       uint32_t RoReg;
/*
#define CHIPID     ((Chipid *)0x400E0740U) //< \brief (CHIPID) Base Address
#include "SOC_Patches/SAM4N/component_chipid.h"
#include "SOC_Patches/SAM4N/instance_chipid.h"
*/
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// ---- Bug reference: missing Flash informations
//------------------------------------------------------------------------------
#define IFLASH0_NB_OF_LOCK_BITS  (128u)
#define IFLASH_NB_OF_LOCK_BITS  (IFLASH0_NB_OF_LOCK_BITS)
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// ---- Bug reference (SAM4S):                    
//------------------------------------------------------------------------------
/*
#undef  CKGR_PLLAR_MULA_Msk
#define CKGR_PLLAR_MULA_Msk (0x3fu << CKGR_PLLAR_MULA_Pos)
*/
//#warning Validation patch : CKGR_PLLAR_MULA_Msk redefined
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// ---- Bug reference(SAM4S): definitions missing in iSOC header last release
//------------------------------------------------------------------------------
/*
#define PMC_FSMR_LPM (0x1<<20) // used in current version of pmc.c (ASF)
*/
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// ---- Bug reference: Supply monitor threshold values definitions (SAM4S)
//------------------------------------------------------------------------------
#undef   SUPC_SMMR_SMTH_1_9V
#undef   SUPC_SMMR_SMTH_2_0V
#undef   SUPC_SMMR_SMTH_2_1V
#undef   SUPC_SMMR_SMTH_2_2V
#undef   SUPC_SMMR_SMTH_2_3V
#undef   SUPC_SMMR_SMTH_2_4V
#undef   SUPC_SMMR_SMTH_2_5V
#undef   SUPC_SMMR_SMTH_2_6V
#undef   SUPC_SMMR_SMTH_2_7V
#undef   SUPC_SMMR_SMTH_2_8V
#undef   SUPC_SMMR_SMTH_2_9V
#undef   SUPC_SMMR_SMTH_3_0V
#undef   SUPC_SMMR_SMTH_3_1V
#undef   SUPC_SMMR_SMTH_3_2V
#undef   SUPC_SMMR_SMTH_3_3V
#undef   SUPC_SMMR_SMTH_3_4V
#define   SUPC_SMMR_SMTH_1_60V (0x0u << 0)
#define   SUPC_SMMR_SMTH_1_72V (0x1u << 0)
#define   SUPC_SMMR_SMTH_1_84V (0x2u << 0)
#define   SUPC_SMMR_SMTH_1_96V (0x3u << 0)
#define   SUPC_SMMR_SMTH_2_08V (0x4u << 0)
#define   SUPC_SMMR_SMTH_2_20V (0x5u << 0)
#define   SUPC_SMMR_SMTH_2_32V (0x6u << 0)
#define   SUPC_SMMR_SMTH_2_44V (0x7u << 0)
#define   SUPC_SMMR_SMTH_2_56V (0x8u << 0)
#define   SUPC_SMMR_SMTH_2_68V (0x9u << 0)
#define   SUPC_SMMR_SMTH_2_80V (0xAu << 0)
#define   SUPC_SMMR_SMTH_2_92V (0xBu << 0)
#define   SUPC_SMMR_SMTH_3_04V (0xCu << 0)
#define   SUPC_SMMR_SMTH_3_16V (0xDu << 0)
#define   SUPC_SMMR_SMTH_3_28V (0xEu << 0)
#define   SUPC_SMMR_SMTH_3_40V (0xFu << 0)
//------------------------------------------------------------------------------



//------------------------------------------------------------------------------
// ---- Bug reference: iSOC naming update
//------------------------------------------------------------------------------
// => definition updated in iSOC header last release
/*
#ifndef CKGR_MOR_MOSCRCF_4_MHz
  #define CKGR_MOR_MOSCRCF_4_MHz CKGR_MOR_MOSCRCF_4MHz
#endif
#ifndef CKGR_MOR_MOSCRCF_8_MHz
  #define CKGR_MOR_MOSCRCF_8_MHz CKGR_MOR_MOSCRCF_8MHz
#endif
#ifndef CKGR_MOR_MOSCRCF_12_MHz
  #define CKGR_MOR_MOSCRCF_12_MHz CKGR_MOR_MOSCRCF_12MHz
#endif

#define PMC_MCKR_PRES_CLK_1  PMC_MCKR_PRES_CLK
#define CKGR_PLLAR_ONE       CKGR_PLLAR_STUCKTO1
*/
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// ---- Feature file inclusion
//------------------------------------------------------------------------------
#include "Devices/_features/FEATURES_SAM4Nxx.h"
/*
// ---- Global Definitions ------------------------------------------------
#define CORE_TYPE_CA5    315
#define CORE_TYPE_CM3    3133
#define CORE_TYPE_CM4    3134
#define CORE_TYPE_ARM7   118137
#define CORE_TYPE_ARM9   118139
//-------------------------------------------------------------------------
#if defined __SAM4N8A__
  #include "Devices/_features/FEATURES_SAM4N16C.h"//ERr
#elif defined __SAM4N8B__
  #include "Devices/_features/FEATURES_SAM4N16C.h"//ERr
#elif defined __SAM4N8C__
  #include "Devices/_features/FEATURES_SAM4N16C.h"//ERr
#elif defined __SAM4N16B__
  #include "Devices/_features/FEATURES_SAM4N16C.h"//ERr
#elif defined __SAM4N16C__
  #include "Devices/_features/FEATURES_SAM4N16C.h"
#else
  #error Library does not support the specified device.
#endif
*/
//------------------------------------------------------------------------------

#endif//_VALID_PATCH_SAM4N_H
