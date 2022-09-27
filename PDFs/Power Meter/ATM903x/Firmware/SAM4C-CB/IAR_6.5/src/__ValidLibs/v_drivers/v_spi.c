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


#include "v_spi.h"


/*----------------------------------------------------------------------------
 *        Exported functions
 *----------------------------------------------------------------------------*/

/**
 * \brief Enables a SPI peripheral.
 *
 * \param spi  Pointer to an Spi instance.
 */
extern void SPI_Enable( Spi* spi )
{
    spi->SPI_CR = SPI_CR_SPIEN ;
}

/**
 * \brief Disables a SPI peripheral.
 *
 * \param spi  Pointer to an Spi instance.
 */
extern void SPI_Disable( Spi* spi )
{
    spi->SPI_CR = SPI_CR_SPIDIS ;
}

/**
 * \brief Enables one or more interrupt sources of a SPI peripheral.
 *
 * \param spi  Pointer to an Spi instance.
 * \param sources Bitwise OR of selected interrupt sources.
 */
extern void SPI_EnableIt( Spi* spi, uint32_t dwSources )
{
    spi->SPI_IER = dwSources ;
}

/**
 * \brief Disables one or more interrupt sources of a SPI peripheral.
 *
 * \param spi  Pointer to an Spi instance.
 * \param sources Bitwise OR of selected interrupt sources.
 */
extern void SPI_DisableIt( Spi* spi, uint32_t dwSources )
{
    spi->SPI_IDR = dwSources ;
}

/**
 * \brief Configures a SPI peripheral as specified. The configuration can be computed
 * using several macros (see \ref spi_configuration_macros).
 *
 * \param spi  Pointer to an Spi instance.
 * \param id   Peripheral ID of the SPI.
 * \param configuration  Value of the SPI configuration register.
 */
extern void SPI_Configure( Spi* spi, /*uint32_t dwId,*/ uint32_t dwConfiguration )
{
    //PMC_EnablePeripheral( dwId ) ;
    spi->SPI_CR = SPI_CR_SPIDIS ;

    // Execute a software reset of the SPI twice
    spi->SPI_CR = SPI_CR_SWRST ;
    spi->SPI_CR = SPI_CR_SWRST ;
    spi->SPI_MR = dwConfiguration ;
}


/**
 * \brief Configures a chip select of a SPI peripheral. The chip select configuration
 * is computed using several macros (see \ref spi_configuration_macros).
 *
 * \param spi   Pointer to an Spi instance.
 * \param npcs  Chip select to configure (0, 1, 2 or 3).
 * \param configuration  Desired chip select configuration.
 */
void SPI_ConfigureNPCS( Spi* spi, uint32_t dwNpcs, uint32_t dwConfiguration )
{
    spi->SPI_CSR[dwNpcs] = dwConfiguration ;
}

/**
 * \brief Get the current status register of the given SPI peripheral.
 * \note This resets the internal value of the status register, so further
 * read may yield different values.
 * \param spi   Pointer to a Spi instance.
 * \return  SPI status register.
 */
extern uint32_t SPI_GetStatus( Spi* spi )
{
    return spi->SPI_SR ;
}

/**
 * \brief Reads and returns the last word of data received by a SPI peripheral. This
 * method must be called after a successful SPI_Write call.
 *
 * \param spi  Pointer to an Spi instance.
 *
 * \return readed data.
 */
extern uint32_t SPI_Read( Spi* spi )
{
    while ( (spi->SPI_SR & SPI_SR_RDRF) == 0 ) ;

    return spi->SPI_RDR & 0xFFFF ;
}

/**
 * \brief Sends data through a SPI peripheral. If the SPI is configured to use a fixed
 * peripheral select, the npcs value is meaningless. Otherwise, it identifies
 * the component which shall be addressed.
 *
 * \param spi   Pointer to an Spi instance.
 * \param npcs  Chip select of the component to address (0, 1, 2 or 3).
 * \param data  Word of data to send.
 */
extern void SPI_Write( Spi* spi, uint32_t dwNpcs, uint16_t wData )
{
    /* Send data */
    while ( (spi->SPI_SR & SPI_SR_TXEMPTY) == 0 ) ;
    spi->SPI_TDR = wData | SPI_TDR_PCS( dwNpcs ) ;
    while ( (spi->SPI_SR & SPI_SR_TDRE) == 0 ) ;
}


/**
 * \brief Check if SPI transfer finish.
 *
 * \param spi  Pointer to an Spi instance.
 *
 * \return Returns 1 if there is no pending write operation on the SPI; otherwise
 * returns 0.
 */
extern uint32_t SPI_IsFinished( Spi* spi )
{
    return ((spi->SPI_SR & SPI_SR_TXEMPTY) != 0) ;
}


// --- PDC routines ------------------------------------------------------------
#if (SPI_HAS_PDC == 1)
/**
 * \brief Enable Spi PDC transmit
 * \param spi  Pointer to an Spi instance.
*/
extern void SPI_PdcEnableTx( Spi* spi )
{
    spi->SPI_PTCR = SPI_PTCR_TXTEN ;
}

/**
 * \brief Disable Spi PDC transmit
 * \param spi  Pointer to an Spi instance.
*/
extern void SPI_PdcDisableTx( Spi* spi )
{
    spi->SPI_PTCR = SPI_PTCR_TXTDIS ;
}

/**
 * \brief Enable Spi PDC receive
 * \param spi  Pointer to an Spi instance.
*/
extern void SPI_PdcEnableRx( Spi* spi )
{
    spi->SPI_PTCR = SPI_PTCR_RXTEN ;
}

/**
 * \brief Disable Spi PDC receive
 * \param spi  Pointer to an Spi instance.
*/
extern void SPI_PdcDisableRx( Spi* spi )
{
    spi->SPI_PTCR = SPI_PTCR_RXTDIS ;
}

/**
 * \brief Set PDC transmit and next transmit buffer address and size.
 *
 * \param spi    Pointer to an Spi instance.
 * \param txBuf  PDC transmit buffer address.
 * \param txCount  Length in bytes of the transmit buffer.
 * \param txNextBuf  PDC next transmit buffer address.
 * \param txNextCount  Length in bytes of the next transmit buffer.
 */
extern void SPI_PdcSetTx( Spi* spi, void* pvTxBuf, uint32_t dwTxCount, void* pvTxNextBuf, uint32_t dwTxNextCount )
{
    spi->SPI_TPR = (uint32_t)pvTxBuf ;
    spi->SPI_TCR = dwTxCount ;
    spi->SPI_TNPR = (uint32_t)pvTxNextBuf ;
    spi->SPI_TNCR = dwTxNextCount ;
}

/**
 * \brief Set PDC receive and next receive buffer address and size.
 *
 * \param spi    Pointer to an Spi instance.
 * \param rxBuf  PDC receive buffer address.
 * \param rxCount  Length in bytes of the receive buffer.
 * \param rxNextBuf  PDC next receive buffer address.
 * \param rxNextCount  Length in bytes of the next receive buffer.
 */
extern void SPI_PdcSetRx( Spi* spi, void* pvRxBuf, uint32_t dwRxCount, void* pvRxNextBuf, uint32_t dwRxNextCount )
{
    spi->SPI_RPR = (uint32_t)pvRxBuf ;
    spi->SPI_RCR = dwRxCount ;
    spi->SPI_RNPR = (uint32_t)pvRxNextBuf ;
    spi->SPI_RNCR = dwRxNextCount ;
}

/**
 * \brief Sends the contents of buffer through a SPI peripheral, using the PDC to
 * take care of the transfer.
 *
 * \param spi     Pointer to an Spi instance.
 * \param buffer  Data buffer to send.
 * \param length  Length of the data buffer.
 */
extern uint32_t SPI_WriteBuffer( Spi* spi, void* pvBuffer, uint32_t dwLength )
{
    /* Check if first bank is free */
    if ( spi->SPI_TCR == 0 )
    {
        spi->SPI_TPR = (uint32_t)pvBuffer ;
        spi->SPI_TCR = dwLength ;
        spi->SPI_PTCR = PERIPH_PTCR_TXTEN ;

        return 1 ;
    }
    /* Check if second bank is free */
    else
    {
        if ( spi->SPI_TNCR == 0 )
        {
            spi->SPI_TNPR = (uint32_t)pvBuffer ;
            spi->SPI_TNCR = dwLength ;

            return 1 ;
        }
    }

    /* No free banks */
    return 0 ;
}

/**
 * \brief Reads data from a SPI peripheral until the provided buffer is filled. This
 * method does NOT need to be called after SPI_Write or SPI_WriteBuffer.
 *
 * \param spi     Pointer to an Spi instance.
 * \param buffer  Data buffer to store incoming bytes.
 * \param length  Length in bytes of the data buffer.
 */
extern uint32_t SPI_ReadBuffer( Spi* spi, void *pvBuffer, uint32_t dwLength )
{
    /* Check if the first bank is free */
    if ( spi->SPI_RCR == 0 )
    {
        spi->SPI_RPR = (uint32_t)pvBuffer ;
        spi->SPI_RCR = dwLength ;
        spi->SPI_PTCR = PERIPH_PTCR_RXTEN ;

        return 1 ;
    }
    /* Check if second bank is free */
    else
    {
        if ( spi->SPI_RNCR == 0 )
        {
            spi->SPI_RNPR = (uint32_t)pvBuffer ;
            spi->SPI_RNCR = dwLength ;
            return 1 ;
        }
    }

    /* No free bank */
    return 0 ;
}
#endif
//------------------------------------------------------------------------------




void SPI_Software_Reset(Spi *spi)
{
    spi->SPI_CR =     SPI_CR_SWRST;
}

void SPI_Set_LastTransfer(Spi *spi)
{
    spi->SPI_CR |=     SPI_CR_LASTXFER;
}

void SPI_Clear_LastTransfer(Spi *spi)
{
    spi->SPI_CR &= ~(    SPI_CR_LASTXFER);
}

void SPI_Mode_Master(Spi *spi)
{
    spi->SPI_MR |=     SPI_MR_MSTR;
}

void SPI_Mode_Slave(Spi *spi)
{
    spi->SPI_MR &= ~(    SPI_MR_MSTR);
}

void SPI_Fixed_Peripheral(Spi *spi)
{
    spi->SPI_MR &= ~(    SPI_MR_PS);
}

void SPI_Var_Peripheral(Spi *spi)
{
    spi->SPI_MR |= (    SPI_MR_PS);
}

void SPI_CSdec_Sel(Spi *spi)
{
    spi->SPI_MR |= (    SPI_MR_PCSDEC);
}

void SPI_CSdec_Dissel(Spi *spi)
{
    spi->SPI_MR &= ~(    SPI_MR_PCSDEC);
}

void SPI_FalutDetect_Disable(Spi *spi)
{
    spi->SPI_MR |= (    SPI_MR_MODFDIS);
}

void SPI_FalutDetect_Enable(Spi *spi)
{
    spi->SPI_MR &= ~(    SPI_MR_MODFDIS);
}

void SPI_Loopback_Disable(Spi *spi)
{
    spi->SPI_MR &= ~(    SPI_MR_LLB);
}

void SPI_Loopback_Enable(Spi *spi)
{
    spi->SPI_MR |= (    SPI_MR_LLB);
}

void SPI_WaitData_En(Spi *spi)
{
    spi->SPI_MR |= (    SPI_MR_WDRBT);
}

void SPI_WaitData_Dis(Spi *spi)
{
    spi->SPI_MR &= ~(    SPI_MR_WDRBT);
}
void SPI_Set_PCS(Spi *spi,unsigned int value)
{
    unsigned int reg;
    if(!(spi->SPI_MR &     SPI_MR_PS)) //check ps status or not ???
    {
        //value &= 0x07;    //avoid value is 0xf
        reg = (spi->SPI_MR );
        reg &= 0xfff0ffff;
        spi->SPI_MR = reg |(    SPI_MR_PCS(value));
    }
}

void SPI_Set_DLYBCS(Spi *spi,int value)
{
    spi->SPI_MR |= (    SPI_MR_DLYBCS(value));
}

unsigned int SPI_Read_Data(Spi *spi)
{
    return     (spi->SPI_RDR & SPI_RDR_RD_Msk) >> SPI_RDR_RD_Pos;
}

unsigned int SPI_Read_PCS(Spi *spi)
{

    return     (spi->SPI_RDR  & SPI_RDR_PCS_Msk) >> SPI_RDR_PCS_Pos;
}

void SPI_Write_Data(Spi *spi,unsigned int value)
{
    spi->SPI_TDR = (SPI_TDR_TD(value));
}

void SPI_Write_Data_PCS(Spi *spi, unsigned int data,unsigned int pcs)
{
    if((spi->SPI_MR &     SPI_MR_PS)) //check ps status or not ???
        spi->SPI_TDR = (    SPI_TDR_TD(data))|    SPI_TDR_PCS(pcs);
}

void SPI_Write_LastData_PCS(Spi *spi,unsigned int data,unsigned int pcs)
{
    if((spi->SPI_MR &     SPI_MR_PS)) //check ps status or not ???
        spi->SPI_TDR = (    SPI_TDR_TD(data))|    SPI_TDR_PCS(pcs)|    SPI_TDR_LASTXFER;
}

unsigned int SPI_Get_Status(Spi *spi,unsigned int status)
{
    return (spi->SPI_SR & status);
}

void SPI_Interrupt_Enable(Spi *spi,unsigned int interrupt)
{
    spi->SPI_IER |= interrupt;
}

void SPI_Interrupt_Disable(Spi *spi,unsigned int interrupt)
{
    spi->SPI_IDR |= interrupt;
}


unsigned int SPI_Interrupt_Mask(Spi *spi,unsigned int interrupt)
{
    return (spi->SPI_IMR & interrupt);
}

unsigned int SPI_Send_Command(Spi *spi,char cmd)
{

    SPI_Write_Data(spi,cmd);
    while (!SPI_Get_Status(spi,SPI_SR_TDRE));

	while (!SPI_Get_Status(spi,SPI_SR_RDRF));
	return (SPI_Read_Data(spi));


}



//=========================================================================
// Set CPOL bit
// parameter CPOL:
// 0 = The inactive state value of SPCK is logic level zero.
// 1 = The inactive state value of SPCK is logic level one.
// Parameter CS:
// NCS0,1,2,3
//=========================================================================
void SPI_CSRx_CPOL(Spi *spi,unsigned int CS,unsigned int CPOL)
{
    if(CPOL & 0x01)
    {
        spi->SPI_CSR[CS] |=     SPI_CSR_CPOL;
    }
    else
    {
        spi->SPI_CSR[CS] &= ~    SPI_CSR_CPOL;
    }
}

//=========================================================================
// Set clock phase bit
// parameter NCPHA:
// 0 = Data is changed on the leading edge of SPCK and captured on the following edge of SPCK.
// 1 = Data is captured on the leading edge of SPCK and changed on the following edge of SPCK.
// Parameter CS:
// NCS0,1,2,3
//=========================================================================
void SPI_CSRx_NCPHA(Spi *spi,unsigned int CS,unsigned int NCPHA)
{
    if(NCPHA & 0x01)
    {
        spi->SPI_CSR[CS] |=     SPI_CSR_NCPHA;
    }
    else
    {
        spi->SPI_CSR[CS] &= ~    SPI_CSR_NCPHA;
    }
}

//=========================================================================
// Set Chip Select Active After Transfer bit
// parameter CSAAT:
// 0 = The Peripheral Chip Select Line rises as soon as the last transfer is achieved.
// 1 = The Peripheral Chip Select does not rise after the last transfer is achieved
// Parameter CS:
// NCS0,1,2,3
//=========================================================================
void SPI_CSRx_CSAAT(Spi *spi,unsigned int CS,unsigned int CSAAT)
{
    if(CSAAT & 0x01)
    {
        spi->SPI_CSR[CS]|=     SPI_CSR_CSAAT;
    }
    else
    {
        spi->SPI_CSR[CS] &= ~    SPI_CSR_CSAAT;
    }
}


//=========================================================================
// Set Bits Per Transfer bit
// parameter Bits:
// The BITS field determines the number of data bits transferred.
// Parameter CS:
// NCS0,1,2,3
//=========================================================================
void SPI_CSRx_BITS(Spi *spi,unsigned int CS,unsigned int Bits)
{
    spi->SPI_CSR[CS] |= Bits;
}



//=========================================================================
// Set SPCK Baud rate
// parameter SCBR:
// SPCK Baudrate = MCK/SCBR
// Parameter CS:
// NCS0,1,2,3
//=========================================================================
void SPI_CSRx_SCBR(Spi *spi,unsigned int CS,unsigned int SCBR)
{
    spi->SPI_CSR[CS] |=     SPI_CSR_SCBR(SCBR);
}


//=========================================================================
// Set Delay Before SPCK
// parameter DLYBS:
// Delay Before SPCK = DLYBS/MCK
// Parameter CS:
// NCS0,1,2,3
//=========================================================================
void SPI_CSRx_DLYBS(Spi *spi,unsigned int CS,unsigned int DLYBS)
{
    spi->SPI_CSR[CS] |=     SPI_CSR_DLYBS(DLYBS);
}

//=========================================================================
// Set Delay Between Consecutive Transfers
// parameter DLYBCT:
// Delay Before SPCK = 32*DLYBCT/MCK
// Parameter CS:
// NCS0,1,2,3
//=========================================================================
void SPI_CSRx_DLYBCT(Spi *spi,unsigned int CS,int DLYBCT)
{
    spi->SPI_CSR[CS] |=     SPI_CSR_DLYBCT(DLYBCT);
}


//=========================================================================
// Set SPI Mode
// parameter Mode:
// Mode 0,1,2,3
// Parameter CS:
// NCS0,1,2,3
//=========================================================================
void SPI_Mode(Spi* spi,unsigned int CS,int mode)
{
    unsigned int CPOL = 0;
    unsigned int NCPHA = 1;
    mode &= 0x03;
    if(mode == 0)
    {
        CPOL = 0;
        NCPHA = 1;
    }
    else if(mode == 0x01)
    {
        CPOL = 0;
        NCPHA = 0;
    }
    else if(mode == 0x02)
    {
        CPOL = 1;
        NCPHA = 1;
    }
    else if(mode == 0x03)
    {
        CPOL = 1;
        NCPHA = 0;
    }

    SPI_CSRx_CPOL(spi,CS,CPOL);
    SPI_CSRx_NCPHA(spi,CS,NCPHA);
}




