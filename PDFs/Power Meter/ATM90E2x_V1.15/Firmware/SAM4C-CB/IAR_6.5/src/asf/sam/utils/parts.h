/**
 * \file
 *
 * \brief Arch file for SAM.
 *
 * This file defines common SAM series.
 *
 * Copyright (c) 2011 - 2012 Atmel Corporation. All rights reserved.
 *
 * \asf_license_start
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. The name of Atmel may not be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * 4. This software may only be redistributed and used in connection with an
 *    Atmel microcontroller product.
 *
 * THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * EXPRESSLY AND SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * \asf_license_stop
 *
 */

#ifndef _SAM_PARTS_
#define _SAM_PARTS_

//Device config is in this file
#include "project.h"
   
/* Convenience macro for checking GCC and IAR part definitions */
#define part_is_defined(part) (defined(__ ## part ## __))




//------------------------------------------------------------------------------
//---- Additional informations (not included in SOC deliverables)
//------------------------------------------------------------------------------
#include "Devices/packages.h" // Keys values
//#include "Devices/keys.h" // ERr (moved in device features file)
//------------------------------------------------------------------------------


/* SAM3 family */

/* SAM3S series */
#define SAM3S1 ( \
    part_is_defined( SAM3S1A ) || \
    part_is_defined( SAM3S1B ) || \
    part_is_defined( SAM3S1C ) )

#define SAM3S2 ( \
    part_is_defined( SAM3S2A ) || \
    part_is_defined( SAM3S2B ) || \
    part_is_defined( SAM3S2C ) )

#define SAM3S4 ( \
    part_is_defined( SAM3S4A ) || \
    part_is_defined( SAM3S4B ) || \
    part_is_defined( SAM3S4C ) )

#define SAM3S8 ( \
    part_is_defined( SAM3S8B ) || \
    part_is_defined( SAM3S8C ) )

#define SAM3SD8 ( \
    part_is_defined( SAM3SD8B ) || \
    part_is_defined( SAM3SD8C ) )

#define SAM3U1 ( \
    part_is_defined( SAM3U1C ) || \
    part_is_defined( SAM3U1E ) )

#define SAM3U2 ( \
    part_is_defined( SAM3U2C ) || \
    part_is_defined( SAM3U2E ) )

#define SAM3U4 ( \
    part_is_defined( SAM3U4C ) || \
    part_is_defined( SAM3U4E ) )

#define SAM3N1 ( \
    part_is_defined( SAM3N1A ) || \
    part_is_defined( SAM3N1B ) || \
    part_is_defined( SAM3N1C ) )

#define SAM3N2 ( \
    part_is_defined( SAM3N2A ) || \
    part_is_defined( SAM3N2B ) || \
    part_is_defined( SAM3N2C ) )

#define SAM3N4 ( \
    part_is_defined( SAM3N4A ) || \
    part_is_defined( SAM3N4B ) || \
    part_is_defined( SAM3N4C ) )
	
#define SAM3X4 ( \
    part_is_defined( SAM3X4C ) || \
	part_is_defined( SAM3X4E ) )

#define SAM3X8 ( \
    part_is_defined( SAM3X8C ) || \
	part_is_defined( SAM3X8E ) || \
    part_is_defined( SAM3X8H ) )

#define SAM3A4 ( \
    part_is_defined( SAM3A4C ) )

#define SAM3A8 ( \
    part_is_defined( SAM3A8C ) )

#define SAM4S8 ( \
    part_is_defined( SAM4S8B ) || \
    part_is_defined( SAM4S8C ) )

#define SAM4S16 ( \
    part_is_defined( SAM4S16B ) || \
    part_is_defined( SAM4S16C ) )

/* Entire SAM3S Family */
#define SAM3S (SAM3S1 || SAM3S2 || SAM3S4 || SAM3S8 || SAM3SD8)

/* Entire SAM3U Family */
#define SAM3U (SAM3U1 || SAM3U2 || SAM3U4)

/* Entire SAM3N Family */
#define SAM3N (SAM3N1 || SAM3N2 || SAM3N4)

/* Entire SAM3XA Family */
#define SAM3XA (SAM3X4 || SAM3X8 || SAM3A4 || SAM3A8)

/* SAM9 family */

/* SAM7 family */
//Gary
/* Entire SAM4S Family */
//#define SAM4S (SAM4S8 || SAM4S16)

/* Global SAM product line */
//Gary
#define SAM ( SAM3S || SAM3U || SAM3N || SAM3XA || SAM4S ||SAM4C)

//Gary
/*
#ifdef SAM
	#include "io.h"
#endif
*/
//---- CM4P2 -------------------------------------------------------------------
//#elif defined __CM4P2B__
//  #define CM4P2 1
//  #define CM4P2B 1
#if defined __CM4P2E__
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

#if (CM4P2==1)
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

#endif /* _SAM_PARTS_ */
