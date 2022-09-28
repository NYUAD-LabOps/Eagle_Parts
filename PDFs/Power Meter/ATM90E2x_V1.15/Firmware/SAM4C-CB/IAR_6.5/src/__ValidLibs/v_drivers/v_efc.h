/* ----------------------------------------------------------------------------
 *         ATMEL Microcontroller Software Support
 * ----------------------------------------------------------------------------
 * Copyright (c) 2009, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */


// Base extracted from softpack



#ifndef _V_EFC_H
#define _V_EFC_H


#include "project.h"

// ---- General purpose include files
#include "device.h"


// ---- Peripherals (ASF drivers)


// ---- Validation libraries



// ----------------------------------------------------------------------------
// ---- Possible write errors mask (EFC status register)
// ----------------------------------------------------------------------------
#if (SAM3S1 || SAM3S2 || SAM3S4)
  #define WR_ERRORS_MASK (EEFC_FSR_FLOCKE | EEFC_FSR_FCMDE)
  #define ECC_1_ERRORS_MASK 0x00050000
  #define ECC_2_ERRORS_MASK 0x000A0000
  #define ECC_ERRORS_MASK (ECC_1_ERRORS_MASK | ECC_2_ERRORS_MASK)
  #define ALL_ERRORS_MASK (ECC_ERRORS_MASK | WR_ERRORS_MASK)
//#elif (SAM3S16 || SAM4S16)
#elif (SAM3S16 || SAM4S)
  #define WR_ERRORS_MASK (EEFC_FSR_FLOCKE | EEFC_FSR_FCMDE | EEFC_FSR_FLERR)
  #define ECC_1_ERRORS_MASK 0x00050000
  #define ECC_2_ERRORS_MASK 0x000A0000
  #define ECC_ERRORS_MASK (ECC_1_ERRORS_MASK | ECC_2_ERRORS_MASK)
  #define ALL_ERRORS_MASK (ECC_ERRORS_MASK | WR_ERRORS_MASK)
#endif
// ----------------------------------------------------------------------------



// ----------------------------------------------------------------------------
typedef struct iflash_descriptor {
	uint32_t fl_id;
	uint32_t fl_size;
	uint32_t fl_page_size;
	uint32_t fl_nb_plane;
      	//uint32_t fl_plane[IFLASH_NB_PLANES];
        uint32_t fl_plane[1];////////////////////////////////////////////////////////////////
      	uint32_t fl_nb_lock;
 	//uint32_t fl_lock[IFLASH_NB_OF_LOCK_BITS];
        uint32_t fl_lock[IFLASH0_NB_OF_LOCK_BITS];
} iflash_descriptor_t;
// ----------------------------------------------------------------------------


/*----------------------------------------------------------------------------
 *        Definitions
 *----------------------------------------------------------------------------*/
/* EFC command */
#define EFC_FCMD_GETD    0x00
#define EFC_FCMD_WP      0x01
#define EFC_FCMD_WPL     0x02
#define EFC_FCMD_EWP     0x03
#define EFC_FCMD_EWPL    0x04
#define EFC_FCMD_EA      0x05
#define EFC_FCMD_SLB     0x08
#define EFC_FCMD_CLB     0x09
#define EFC_FCMD_GLB     0x0A
//#define EFC_FCMD_SFB     0x0B
//#define EFC_FCMD_CFB     0x0C
//#define EFC_FCMD_GFB     0x0D
#define EFC_FCMD_STUI    0x0E /* Start unique ID */
#define EFC_FCMD_SPUI    0x0F /* Stop unique ID */

#define EFC_FCMD_SGPB    0x0B
#define EFC_FCMD_CGPB    0x0C
#define EFC_FCMD_GGPB    0x0D
#define EFC_FCMD_GCALB   0x10

#if (SAM4S==1)
  #define EFC_FCMD_EPA   0x7
  #define EFC_FCMD_ES    0x11
#endif


/* The IAP function entry addreass */
#define RAM_EXEC 0
#define ROM_EXEC 1
#define CHIP_FLASH_IAP_ADDRESS  (0x00800008)

#ifdef __cplusplus
 extern "C" {
#endif

/*----------------------------------------------------------------------------
 *        Exported functions prototypes
 *----------------------------------------------------------------------------*/
extern uint32_t v_efc_get_flash_descriptor(Efc* efc, iflash_descriptor_t* fdes, uint32_t dwUseIAP );
extern __ramfunc uint32_t v_EFC_PerformCommand( Efc* efc, uint8_t Command, uint16_t Argument, uint32_t dwUseIAP ) ;
extern void v_EFC_ComputeAddress(uint16_t wPage, uint16_t wOffset, uint32_t *pdwAddress ) ;
//----------------------------------------------------------------------------
//  (validation team addition)
//----------------------------------------------------------------------------
extern __ramfunc uint32_t v_EFC_PerformCommand_parallel(Efc* efc0, Efc* efc1, uint8_t Command0, uint8_t Command1, uint16_t Argument0, uint16_t Argument1, uint32_t* pStatus0, uint32_t* pStatus1);

/*----------------------------------------------------------------------------
 *        Exported functions prototypes
 *----------------------------------------------------------------------------*/
extern void EFC_EnableFrdyIt( Efc* efc ) ;
extern void EFC_DisableFrdyIt( Efc* efc ) ;
extern void EFC_SetWaitState( Efc* efc, uint8_t cycles ) ;
//extern void EFC_TranslateAddress( Efc** pEfc, uint32_t dwAddress, uint16_t *pwPage, uint16_t *pwOffset ) ;
//extern void EFC_ComputeAddress( Efc* efc, uint16_t wPage, uint16_t wOffset, uint32_t *pdwAddress ) ;
extern void EFC_StartCommand( Efc* efc, uint32_t dwCommand, uint32_t dwArgument ) ;
//extern uint32_t EFC_PerformCommand( Efc* efc, uint32_t dwCommand, uint32_t dwArgument, uint32_t dwUseIAP ) ;
extern uint32_t EFC_GetStatus( Efc* efc ) ;
extern uint32_t EFC_GetResult( Efc* efc ) ;



#ifdef __cplusplus
}
#endif

#endif//_V_EFC_H