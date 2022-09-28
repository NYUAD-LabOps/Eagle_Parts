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



#include "v_ssc.h"


/*----------------------------------------------------------------------------
 *       Exported functions
 *----------------------------------------------------------------------------*/

/**
 * \brief Configures a SSC peripheral.If the divided clock is not used, the master
 * clock frequency can be set to 0.
 * \note The emitter and transmitter are disabled by this function.
 * \param bitRate  bit rate.
 * \param masterClock  master clock.
 */
void SSC_Configure(Ssc* ssc, uint32_t bitRate, uint32_t masterClock)
{
    /* Enable SSC peripheral clock */
    //PMC->PMC_PCER0 = 1 << ID_SSC; //ERr done within PMC driver

    /* Reset, disable receiver & transmitter */
    ssc->SSC_CR = SSC_CR_RXDIS | SSC_CR_TXDIS | SSC_CR_SWRST;

#if (SSC_HAS_PDC == 1)
    ssc->SSC_PTCR = SSC_PTCR_RXTDIS | SSC_PTCR_TXTDIS;
#endif
    
    /* Configure clock frequency */
    if (bitRate != 0) {

        ssc->SSC_CMR = masterClock / (2 * bitRate);
    }
    else {

        ssc->SSC_CMR = 0;
    }
}


/**
 * \brief Configures the transmitter of a SSC peripheral.
 * \param tcmr Transmit Clock Mode Register value.
 * \param tfmr Transmit Frame Mode Register value.
 */
void SSC_ConfigureTransmitter(Ssc* ssc, uint32_t tcmr, uint32_t tfmr)
{
    ssc->SSC_TCMR = tcmr;
    ssc->SSC_TFMR = tfmr;
}


/**
 * \brief Configures the receiver of a SSC peripheral.
 * \param rcmr Receive Clock Mode Register value.
 * \param rfmr Receive Frame Mode Register value.
 */
void SSC_ConfigureReceiver(Ssc* ssc, uint32_t rcmr, uint32_t rfmr)
{
    ssc->SSC_RCMR = rcmr;
    ssc->SSC_RFMR = rfmr;
}


/**
 * \brief Enables the transmitter of a SSC peripheral.
 */
void SSC_EnableTransmitter(Ssc* ssc)
{
    ssc->SSC_CR = SSC_CR_TXEN;
}


/**
 * \brief Disables the transmitter of a SSC peripheral.
 */
void SSC_DisableTransmitter(Ssc* ssc)
{
    ssc->SSC_CR = SSC_CR_TXDIS;
}


/**
 * \brief Enables the receiver of a SSC peripheral.
 */
void SSC_EnableReceiver(Ssc* ssc)
{
    ssc->SSC_CR = SSC_CR_RXEN;
}


/**
 * \brief Disables the receiver of a SSC peripheral.
 */
void SSC_DisableReceiver(Ssc* ssc)
{
    ssc->SSC_CR = SSC_CR_RXDIS;
}


/**
 * \brief Enables one or more interrupt sources of a SSC peripheral.
 * \param sources Bitwise OR of selected interrupt sources.
 */
void SSC_EnableInterrupts(Ssc* ssc, uint32_t sources)
{
    ssc->SSC_IER = sources;
}


/**
 * \brief Disables one or more interrupt sources of a SSC peripheral.
 * \param sources Bitwise OR of selected interrupt sources.
 */
void SSC_DisableInterrupts(Ssc* ssc, uint32_t sources)
{
    ssc->SSC_IDR = sources;
}


/**
 * \brief Sends one data frame through a SSC peripheral. If another frame is currently
 * being sent, this function waits for the previous transfer to complete.
 * \param frame Data frame to send.
 */
void SSC_Write(Ssc* ssc, uint32_t frame)
{
    while ((ssc->SSC_SR & SSC_SR_TXRDY) == 0);
    ssc->SSC_THR = frame;
}


/**
 * \brief Waits until one frame is received on a SSC peripheral, and returns it.
 */
uint32_t SSC_Read(Ssc* ssc)
{
    while ((ssc->SSC_SR & SSC_SR_RXRDY) == 0);
    return ssc->SSC_RHR;
}

#if (SSC_HAS_PDC == 1)
/**
 * \brief Sends the contents of a data buffer a SSC peripheral, using the PDC.
 * \param buffer Data buffer to send.
 * \param length Size of the data buffer.
 * \return 1 if the buffer has been queued for transmission; otherwise returns 0.
 */
uint8_t SSC_WriteBuffer(Ssc* ssc, void *buffer, uint32_t length)
{
    /* Check if first bank is free*/
    if (ssc->SSC_TCR == 0) {

        ssc->SSC_TPR = (uint32_t) buffer;
        ssc->SSC_TCR = length;
        ssc->SSC_PTCR = SSC_PTCR_TXTEN;
        return 1;
    }
    /* Check if second bank is free*/
    else if (ssc->SSC_TNCR == 0) {

        ssc->SSC_TNPR = (uint32_t) buffer;
        ssc->SSC_TNCR = length;
        return 1;
    }
    return 0;
}


/**
 * \brief Reads data coming from a SSC peripheral receiver and stores it into the
 * giving buffer with PDC.
 * \param buffer ata buffer used for reception.
 * \param length Size of the data buffer.
 * \return 1 if the buffer has been queued for reception; otherwise returns 0.
 */
uint8_t SSC_ReadBuffer(Ssc* ssc, void *buffer, uint32_t length)
{
    /* Check if the first bank is free*/
    if (ssc->SSC_RCR == 0) {

        ssc->SSC_RPR = (uint32_t) buffer;
        ssc->SSC_RCR = length;
        ssc->SSC_PTCR = SSC_PTCR_RXTEN;
        return 1;
    }
    /* Check if second bank is free*/
    else if (ssc->SSC_RNCR == 0) {
        ssc->SSC_RNPR = (uint32_t) buffer;
        ssc->SSC_RNCR = length;
        return 1;
    }
    return 0;
}
#endif