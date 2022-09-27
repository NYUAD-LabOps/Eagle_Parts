/*----------------------------------------------------------------------------
*         ATMEL Microcontroller Software Support  -  ROUSSET  -
*----------------------------------------------------------------------------
* The software is delivered "AS IS" without warranty or condition of any
* kind, either express, implied or statutory. This includes without
* limitation any warranty or condition with respect to merchantability or
* fitness for any particular purpose, or against the infringements of
* intellectual property rights of others.
*----------------------------------------------------------------------------
* File Name           : device.h
* Object              : ATSAM Definition File.
*
* Creation            : ERr / Aug 2011
*----------------------------------------------------------------------------
*/
#ifndef _DEVICE_H
#define _DEVICE_H

#include "project.h" 

//---- SAM3S -------------------------------------------------------------------
#if defined __SAM3S1A__
  #define SAM3 1
  #define SAM3S 1
  #define SAM3S1 1
#elif defined __SAM3S1B__
  #define SAM3 1
  #define SAM3S 1
  #define SAM3S1 1
#elif defined __SAM3S1C__
  #define SAM3 1
  #define SAM3S 1
  #define SAM3S1 1
#elif defined __SAM3S2A__
  #define SAM3 1
  #define SAM3S 1
  #define SAM3S2 1
#elif defined __SAM3S2B__
  #define SAM3 1
  #define SAM3S 1
  #define SAM3S2 1
#elif defined __SAM3S2C__
  #define SAM3 1
  #define SAM3S 1
  #define SAM3S2 1
#elif defined __SAM3S4A__
  #define SAM3 1
  #define SAM3S 1
  #define SAM3S4 1
#elif defined __SAM3S4B__
  #define SAM3 1
  #define SAM3S 1
  #define SAM3S4 1
#elif defined __SAM3S4C__
  #define SAM3 1
  #define SAM3S 1
  #define SAM3S4 1
//---- SAM3S8 ------------------------------------------------------------------
/*
#elif defined __SAM3S8A__
  #define SAM3 1
  #define SAM3S8 1
*/
#elif defined __SAM3S8B__
  #define SAM3 1
  #define SAM3S8 1
#elif defined __SAM3S8C__
  #define SAM3 1
  #define SAM3S8 1
#elif defined __SAM3SD8A__
  #define SAM3 1
  #define SAM3SD8 1
#elif defined __SAM3SD8B__
  #define SAM3 1
  #define SAM3SD8 1
#elif defined __SAM3SD8C__
  #define SAM3 1
  #define SAM3SD8 1
//---- SAM4S -------------------------------------------------------------------
#elif defined __SAM4S8B__
  #define SAM4 1
  #define SAM4S 1
  #define SAM4S8 1
#elif defined __SAM4S8C__
  #define SAM4 1
  #define SAM4S 1
  #define SAM4S8 1
#elif defined __SAM4S16B__
  #define SAM4 1
  #define SAM4S 1
  #define SAM4S16 1
#elif defined __SAM4S16C__
  #define SAM4 1
  #define SAM4S 1
  #define SAM4S16 1
#elif defined __SAM4SA16B__
  #define SAM4 1
  #define SAM4S 1
  #define SAM4SA16 1
#elif defined __SAM4SA16C__
  #define SAM4 1
  #define SAM4S 1
  #define SAM4SA16 1
#elif defined __SAM4SD16B__
  #define SAM4 1
  #define SAM4S 1
  #define SAM4SD16 1
#elif defined __SAM4SD16C__
  #define SAM4 1
  #define SAM4S 1
  #define SAM4SD16 1
#elif defined __SAM4SD32B__
  #define SAM4 1
  #define SAM4S 1
  #define SAM4SD32 1
#elif defined __SAM4SD32C__
  #define SAM4 1
  #define SAM4S 1
  #define SAM4SD32 1
//---- SAM4N -------------------------------------------------------------------
#elif defined __SAM4N8A__
  #define SAM4 1
  #define SAM4N 1
  #define SAM4N8 1
#elif defined __SAM4N8B__
  #define SAM4 1
  #define SAM4N 1
  #define SAM4N8 1
#elif defined __SAM4N8C__
  #define SAM4 1
  #define SAM4N 1
  #define SAM4N8 1
#elif defined __SAM4N16B__
  #define SAM4 1
  #define SAM4N 1
  #define SAM4N16 1
#elif defined __SAM4N16C__
  #define SAM4 1
  #define SAM4N 1
  #define SAM4N16 1
//---- SAMA5 -------------------------------------------------------------------
#elif defined __SAMA5D31__
  #define SAMA5 1
  #define SAMA5D 1
  #define SAMA5D31 1
#elif defined __SAMA5D33__
  #define SAMA5 1
  #define SAMA5D 1
  #define SAMA5D33 1
#elif defined __SAMA5D34__
  #define SAMA5 1
  #define SAMA5D 1
  #define SAMA5D34 1
#elif defined __SAMA5D35__
  #define SAMA5 1
  #define SAMA5D 1
  #define SAMA5D35 1
//---- CM4P2 -------------------------------------------------------------------
//#elif defined __CM4P2B__
//  #define CM4P2 1
//  #define CM4P2B 1
#elif defined __CM4P2E__
  #define CM4P2 1
  #define CM4P2E 1
//---- SAM4C -------------------------------------------------------------------
#elif defined __SAM4C16C__
  #define SAM4 1
  #define SAM4C 1
  #define SAM4C16 1
#elif defined __SAM4C16C__

#elif defined __SAM4C8C__
  #define SAM4 		1
  #define SAM4C 	1
  #define SAM4C8 	1
#elif defined __SAM4C8C__


#elif defined __SAM4CMP16C__
  #define SAM4 		1
  #define SAM4CMP 	1
  #define SAM4CMP16 	1
#elif defined __SAM4CMP16C__

#elif defined __SAM4CMP8C__
  #define SAM4 		1
  #define SAM4CMP 	1
  #define SAM4CMP8 	1
#elif defined __SAM4CMP8C__

#elif defined __SAM4CMS16C__
  #define SAM4 		1
  #define SAM4CMS 	1
  #define SAM4CMS16 	1
#elif defined __SAM4CMS16C__

#elif defined __SAM4CMS8C__
  #define SAM4 		1
  #define SAM4CMS 	1
  #define SAM4CMS8 	1
#elif defined __SAM4CMS8C__

#elif defined __SAM4MP16C__
  #define SAM4 		1
  #define SAM4MP 	1
  #define SAM4MP16 	1
#elif defined __SAM4MP16C__

#elif defined __SAM4MP8C__
  #define SAM4 		1
  #define SAM4MP 	1
  #define SAM4MP8 	1
#elif defined __SAM4MP8C__

#elif defined __SAM4MS16C__
  #define SAM4 		1
  #define SAM4MS 	1
  #define SAM4MS16 	1
#elif defined __SAM4MS16C__

#elif defined __SAM4MS8C__
  #define SAM4 		1
  #define SAM4MS 	1
  #define SAM4MS8 	1
#elif defined __SAM4MS8C__

//---- Not implemented ---------------------------------------------------------
#else
  #error Library does not support the specified device.
#endif
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
//---- SOC headers include
//------------------------------------------------------------------------------
#if (SAM3S==1)
  #include "Devices/SAM3S/split/SAM3S.h"
  #include "SOC_Patches/valid_patch_SAM3S.h"
  #include "Devices/iflash_info.h" // Embedded Flash definitions
#elif (SAM3S8==1)
  //#include "Devices/SAM3S8/header/SAM3S8.h"
  #include "Devices/SAM3S8/include/SAM3S8.h"
  #include "SOC_Patches/valid_patch_SAM3S8.h"
  #include "Devices/iflash_info.h" // Embedded Flash definitions
#elif (SAM4S==1)
  #include "Devices/SAM4S/split/SAM4S.h"
  #include "SOC_Patches/valid_patch_SAM4S.h"
  #include "Devices/iflash_info.h" // Embedded Flash definitions
#elif (SAM4N==1)
  #define DONT_USE_CMSIS_INIT //ERr
  #include "Devices/SAM4N/split/SAM4N.h"
  #include "SOC_Patches/valid_patch_SAM4N.h"
  #include "Devices/iflash_info.h" // Embedded Flash definitions
#elif (CM4P2==1)
  #define DONT_USE_CMSIS_INIT //ERr
  #include "Devices/CM4P2/split/CM4P2.h"
  #include "SOC_Patches/valid_patch_CM4P2.h"
  #include "Devices/iflash_info.h" // Embedded Flash definitions
#elif (SAMA5==1)
  #include "Devices/SAMA5/include/SAMA5.h"
  #include "SOC_Patches/valid_patch_SAMA5.h"
#elif (SAM4C==1)
  #if (SAM4C_C0==1)
    #include "Devices/SAM4C/SAM4C-0.h"
    #include "SOC_Patches/valid_patch_SAM4C.h"
    #include "Devices/iflash_info.h" // Embedded Flash definitions
  #elif (SAM4C_C1==1)
    #include "Devices/SAM4C/SAM4C-1.h"
    #include "SOC_Patches/valid_patch_SAM4C.h"
    #include "Devices/iflash_info.h" // Embedded Flash definitions
  #else
    #error CORE not specified.  
  #endif
#else
  #error Library does not support the specified device.
#endif
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
//---- Additional informations (not included in SOC deliverables)
//------------------------------------------------------------------------------
#include "Devices/packages.h" // Keys values
//#include "Devices/keys.h" // ERr (moved in device features file)
//------------------------------------------------------------------------------


#endif /* _DEVICE_H */
