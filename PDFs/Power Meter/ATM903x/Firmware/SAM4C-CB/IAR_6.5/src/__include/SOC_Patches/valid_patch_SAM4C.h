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
#ifndef _VALID_PATCH_SAM4C_H
#define _VALID_PATCH_SAM4C_H



//------------------------------------------------------------------------------
// ---- Bug reference: definitions missing in iSOC header last release
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// ---- Bug reference: Supply monitor threshold values definitions
//------------------------------------------------------------------------------
#warning waiting for electrical part to be added to be updated in datasheet
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
// ---- Bug reference: iFLASH definitions
//------------------------------------------------------------------------------

#define IFLASH0_NB_OF_LOCK_BITS IFLASH_NB_OF_LOCK_BITS

//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// ---- Bug reference: iSOC naming update
//------------------------------------------------------------------------------
// => definition updated in iSOC header last release


#define ID_SRAM1_2   (42)
//-----------------------------------------------------------------------------




//------------------------------------------------------------------------------
// ---- Feature file inclusion
//------------------------------------------------------------------------------
#include "Devices/_features/FEATURES_SAM4Cxx.h"

//------------------------------------------------------------------------------

#endif//_VALID_PATCH_SAM4C_H
