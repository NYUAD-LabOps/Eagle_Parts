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



// Base functions extracted from softpack



#include "v_crccu.h"


/*----------------------------------------------------------------------------
 *        Definitions
 *----------------------------------------------------------------------------*/
#define CRCCU_TIMEOUT    0xFFFFFFFF

/*----------------------------------------------------------------------------
 *        Exported functions
 *----------------------------------------------------------------------------*/
/**
 * \brief Reset initial CRC to 0xFFFFFFFF.
 */
extern void CRCCU_ResetCrcValue( Crccu* pCrccu )
{
    pCrccu->CRCCU_CR = CRCCU_CR_RESET;
}

/**
 * \brief Configure the CRCCU.
 *
 * \param dscrAddr CRC decscriptor address.
 * \param mode     CRC work mode
 */
extern void CRCCU_Configure( Crccu* pCrccu, uint32_t dwDscrAddr, uint32_t dwMode )
{
    pCrccu->CRCCU_DSCR = dwDscrAddr ;
    pCrccu->CRCCU_MR = dwMode ;
}

/**
 * \brief Start to compute the CRC of a buffer.
 *
 * \return The CRC of the buffer.
 */
extern uint32_t CRCCU_ComputeCrc( Crccu* pCrccu )
{
    uint32_t dwTimeout = 0 ;

    pCrccu->CRCCU_DMA_EN = CRCCU_DMA_EN_DMAEN ;

    while ( ((pCrccu->CRCCU_DMA_SR & CRCCU_DMA_SR_DMASR) == CRCCU_DMA_SR_DMASR) &&
            (dwTimeout++ < CRCCU_TIMEOUT) ) ;

    return (pCrccu->CRCCU_SR) ;
}

