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
#ifndef _VALID_PATCH_CM4P2_H
#define _VALID_PATCH_CM4P2_H


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
// ---- Bug reference: iSOCK/Datasheet issue
//------------------------------------------------------------------------------
#define REG_CCFG_SYSIO     (*(RwReg*)0x400E0314U) /**< \brief (MATRIX) System I/O Configuration register */
#define REG_CCFG_SMCNFCS   (*(RwReg*)0x400E031CU) /**< \brief (MATRIX) SMC Chip Select NAND Flash Assignment Register */
/* -------- CCFG_SYSIO : (MATRIX Offset: 0x0114) System I/O Configuration register -------- */
#define CCFG_SYSIO_SYSIO4 (0x1u << 4) /**< \brief (CCFG_SYSIO) PB4 or TDI Assignment */
#define CCFG_SYSIO_SYSIO5 (0x1u << 5) /**< \brief (CCFG_SYSIO) PB5 or TDO/TRACESWO Assignment */
#define CCFG_SYSIO_SYSIO6 (0x1u << 6) /**< \brief (CCFG_SYSIO) PB6 or TMS/SWDIO Assignment */
#define CCFG_SYSIO_SYSIO7 (0x1u << 7) /**< \brief (CCFG_SYSIO) PB7 or TCK/SWCLK Assignment */
#define CCFG_SYSIO_SYSIO10 (0x1u << 10) /**< \brief (CCFG_SYSIO) PB10 or DDM Assignment */
#define CCFG_SYSIO_SYSIO11 (0x1u << 11) /**< \brief (CCFG_SYSIO) PB11 or DDP Assignment */
#define CCFG_SYSIO_SYSIO12 (0x1u << 12) /**< \brief (CCFG_SYSIO) PB12 or ERASE Assignment */
/* -------- CCFG_SMCNFCS : (MATRIX Offset: 0x011C) SMC Chip Select NAND Flash Assignment Register -------- */
#define CCFG_SMCNFCS_SMC_NFCS0 (0x1u << 0) /**< \brief (CCFG_SMCNFCS) SMC NAND Flash Chip Select 0 Assignment */
#define CCFG_SMCNFCS_SMC_NFCS1 (0x1u << 1) /**< \brief (CCFG_SMCNFCS) SMC NAND Flash Chip Select 1 Assignment */
#define CCFG_SMCNFCS_SMC_NFCS2 (0x1u << 2) /**< \brief (CCFG_SMCNFCS) SMC NAND Flash Chip Select 2 Assignment */
#define CCFG_SMCNFCS_SMC_NFCS3 (0x1u << 3) /**< \brief (CCFG_SMCNFCS) SMC NAND Flash Chip Select 3 Assignment */
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// ---- Bug reference: iSOCK/Datasheet issue
//------------------------------------------------------------------------------
//#define SUPC_MR_ONREG SUPC_MR_VDDIORDYONREG
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// ---- Bug reference:                    
//------------------------------------------------------------------------------
#undef  CKGR_PLLAR_MULA_Msk
#define CKGR_PLLAR_MULA_Msk (0x3fu << CKGR_PLLAR_MULA_Pos)
//#warning Validation patch : CKGR_PLLAR_MULA_Msk redefined
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// ---- Bug reference: definitions missing in iSOC header last release
//------------------------------------------------------------------------------
#define PMC_FSMR_LPM (0x1<<20) // used in current version of pmc.c (ASF)
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// ---- Bug reference: Supply monitor threshold values definitions
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
#ifndef IFLASH0_NB_OF_LOCK_BITS
  #define IFLASH0_NB_OF_LOCK_BITS (IFLASH_NB_OF_LOCK_BITS)
#endif
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
#if defined _CM4P2E_
  #include "Devices/_features/FEATURES_CM4P2E.h"
#else
  #error Library does not support the specified device.
#endif
//------------------------------------------------------------------------------

#endif//_VALID_PATCH_CM4P2_H
