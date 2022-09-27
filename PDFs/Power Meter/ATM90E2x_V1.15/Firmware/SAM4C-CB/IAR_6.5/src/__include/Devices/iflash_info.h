/*----------------------------------------------------------------------------
*         ATMEL Microcontroller Software Support  -  ROUSSET  -
*----------------------------------------------------------------------------
* The software is delivered "AS IS" without warranty or condition of any
* kind, either express, implied or statutory. This includes without
* limitation any warranty or condition with respect to merchantability or
* fitness for any particular purpose, or against the infringements of
* intellectual property rights of others.
*----------------------------------------------------------------------------
* File Name           : iflash_info.h
* Object              : ATSAM Definition File.
*
* Creation            : Oct/2011
*----------------------------------------------------------------------------
*/
#ifndef _IFLASH_INFO_H
#define _IFLASH_INFO_H


//---- SAM3S -------------------------------------------------------------------
#if (SAM3S1 == 1)
  #define IFLASH_NB_PLANES (1u)
#elif (SAM3S2 == 1)
  #define IFLASH_NB_PLANES (1u)
#elif (SAM3S4 == 1)
  #define IFLASH_NB_PLANES (1u)
#elif (SAM3S8 == 1)
  #define IFLASH_NB_PLANES (1u)
#elif (SAM3SD8 == 1)
  #define IFLASH_NB_PLANES (1u)
//---- SAM4S -------------------------------------------------------------------
#elif (SAM4S8 == 1)
  #define IFLASH_NB_PLANES        (1u)
  #define IFLASH0_SECTOR_SIZE     (65536) //ERr added
#elif (SAM4S16 == 1)
  #define IFLASH_NB_PLANES        (1u)
  #define IFLASH0_SECTOR_SIZE     (65536) //ERr added
#elif (SAM4SA16 == 1)
  #define IFLASH_NB_PLANES        (1u)
  #define IFLASH0_SECTOR_SIZE     (65536) //ERr added
#elif (SAM4SD16 == 1)
  #define IFLASH_NB_PLANES        (2u)
  #define IFLASH0_SECTOR_SIZE     (65536) //ERr added
  #define IFLASH1_SECTOR_SIZE     (65536) //ERr added
#elif (SAM4SD32 == 1)
  #define IFLASH_NB_PLANES        (2u)
  #define IFLASH0_SECTOR_SIZE     (65536) //ERr added
  #define IFLASH1_SECTOR_SIZE     (65536) //ERr added
//---- SAM4N -------------------------------------------------------------------
#elif (SAM4N8 == 1)
  #define IFLASH_NB_PLANES        (1u)
  #define IFLASH0_SECTOR_SIZE     (65536) //ERr added
#elif (SAM4N16 == 1)
  #define IFLASH_NB_PLANES        (1u)
  #define IFLASH0_SECTOR_SIZE     (65536) //ERr added
//---- CM4P2 -------------------------------------------------------------------
#elif (CM4P2 == 1)
  #define IFLASH_NB_PLANES        (1u)
  #define IFLASH0_SECTOR_SIZE     (65536) //ERr added
//---- SAM4C -------------------------------------------------------------------
#elif (SAM4C == 1)
  #define IFLASH_NB_PLANES        (1u)
  #define IFLASH0_SECTOR_SIZE     (65536) //AYi added
//------------------------------------------------------------------------------
#else
  #error Library does not support the specified device.
#endif



#endif //_IFLASH_INFO_H
