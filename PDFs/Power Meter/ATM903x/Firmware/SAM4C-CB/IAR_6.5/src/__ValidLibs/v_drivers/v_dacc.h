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



#ifndef _V_DACC_H
#define _V_DACC_H


#include "project.h"

// ---- General purpose include files
#include "device.h"

// ---- Peripherals (ASF drivers)


// ---- Validation libraries





/*------------------------------------------------------------------------------
 *         Definitions
 *------------------------------------------------------------------------------*/
#define DACC_CHANNEL_0 0
#define DACC_CHANNEL_1 1



/*------------------------------------------------------------------------------
 *         Macros function of register access
 *------------------------------------------------------------------------------*/
#define DACC_CfgModeReg(pDACC, mode)  { \
             (pDACC)->DACC_MR = (mode);\
        }

#define DACC_GetModeReg(pDACC)                ((pDACC)->DACC_MR)

#define DACC_StartConversion(pDACC)           ((pDACC)->DACC_CR = DACC_CR_START)

#define DACC_SoftReset(pDACC)                 ((pDACC)->DACC_CR = DACC_CR_SWRST)

#define DACC_EnableChannel(pDACC, channel)    {\
            (pDACC)->DACC_CHER = (1 << (channel));\
        }

#define DACC_DisableChannel(pDACC, channel)  {\
            (pDACC)->DACC_CHDR = (1 << (channel));\
        }

#define DACC_EnableIt(pDACC, mode)            {\
            (pDACC)->DACC_IER = (mode);\
        }

#define DACC_DisableIt(pDACC, mode)           {\
            (pDACC)->DACC_IDR = (mode);\
        }

#define DACC_EnableDataReadyIt(pDACC)         ((pDACC)->DACC_IER = AT91C_DACC_DRDY)

#define DACC_GetStatus(pDACC)                 ((pDACC)->DACC_ISR)

#define DACC_GetChannelStatus(pDACC)          ((pDACC)->DACC_CHSR)

#define DACC_GetInterruptMaskStatus(pDACC)    ((pDACC)->DACC_IMR)

#define DACC_GetLastConvertedData(pDACC)      ((pDACC)->DACC_LCDR)

#define DACC_CfgAnalogCtrlReg(pDACC,mode)     {\
            (pDACC)->DACC_ACR = (mode);\
        }

#define DACC_CfgExtModeReg(pDACC, extmode)    {\
            (pDACC)->DACC_EMR = (extmode);\
        }

#define DACC_GetAnalogCtrlReg(pDACC)          ((pDACC)->DACC_ACR)

/*------------------------------------------------------------------------------
 *         Exported functions
 *------------------------------------------------------------------------------*/
extern void DACC_Initialize( Dacc* pDACC,
                     uint8_t idDACC,
                     uint8_t trgEn,
                     uint8_t trgSel,
                     uint8_t word,
                     uint8_t sleepMode,
                     uint32_t mck,
                     uint8_t refresh,/*refresh period*/
                     uint8_t user_sel,/*user channel selection*/
                     uint32_t tag_mode,/*using tag for channel number*/
                     uint32_t startup
                     );


extern void DACC_SetConversionData( Dacc* pDACC, uint32_t dwData ) ;

extern uint32_t DACC_WriteBuffer( Dacc* pDACC, uint16_t* pwBuffer, uint32_t dwSize ) ;


#endif //_V_DACC_H

