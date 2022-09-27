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



#ifndef _V_SPI_H
#define _V_SPI_H


#include "project.h"

// ---- General purpose include files
#include "device.h"

// ---- Peripherals (ASF drivers)


// ---- Validation libraries



/*----------------------------------------------------------------------------
 *        Macros
 *----------------------------------------------------------------------------*/
/**
 *
 * Here are several macros which should be used when configuring a SPI
 * peripheral.
 *
 * \section spi_configuration_macros SPI Configuration Macros
 * - \ref SPI_PCS
 * - \ref SPI_SCBR
 * - \ref SPI_DLYBS
 * - \ref SPI_DLYBCT
 */

/** Calculate the PCS field value given the chip select NPCS value */
//#define SPI_PCS(npcs)       ((~(1 << npcs) & 0xF) << 16)

/** Calculates the value of the CSR SCBR field given the baudrate and MCK. */
//#define SPI_SCBR(baudrate, masterClock) ((uint32_t) (masterClock / baudrate) << 8)

/** Calculates the value of the CSR DLYBS field given the desired delay (in ns) */
//#define SPI_DLYBS(delay, masterClock) ((uint32_t) (((masterClock / 1000000) * delay) / 1000) << 16)

/** Calculates the value of the CSR DLYBCT field given the desired delay (in ns) */
//#define SPI_DLYBCT(delay, masterClock) ((uint32_t) (((masterClock / 1000000) * delay) / 32000) << 24)

/*------------------------------------------------------------------------------ */



/*----------------------------------------------------------------------------
 *        Exported functions
 *----------------------------------------------------------------------------*/

extern void SPI_Enable( Spi* spi ) ;
extern void SPI_Disable( Spi* spi ) ;
extern void SPI_EnableIt( Spi* spi, uint32_t dwSources ) ;
extern void SPI_DisableIt( Spi* spi, uint32_t dwSources ) ;

extern void SPI_Configure( Spi* spi, /*uint32_t dwId,*/ uint32_t dwConfiguration ) ;
extern void SPI_ConfigureNPCS( Spi* spi, uint32_t dwNpcs, uint32_t dwConfiguration ) ;

extern uint32_t SPI_Read( Spi* spi ) ;
extern void SPI_Write( Spi* spi, uint32_t dwNpcs, uint16_t wData ) ;

extern uint32_t SPI_GetStatus( Spi* spi ) ;
extern uint32_t SPI_IsFinished( Spi* pSpi ) ;

#if (SPI_HAS_PDC == 1)
extern void SPI_PdcEnableTx( Spi* spi ) ;
extern void SPI_PdcDisableTx( Spi* spi ) ;
extern void SPI_PdcEnableRx( Spi* spi ) ;
extern void SPI_PdcDisableRx( Spi* spi ) ;
extern void SPI_PdcSetTx( Spi* spi, void* pvTxBuf, uint32_t dwTxCount, void* pvTxNextBuf, uint32_t dwTxNextCount ) ;
extern void SPI_PdcSetRx( Spi* spi, void* pvRxBuf, uint32_t dwRxCount, void* pvRxNextBuf, uint32_t dwRxNextCount ) ;
extern uint32_t SPI_WriteBuffer( Spi* spi, void* pvBuffer, uint32_t dwLength ) ;
extern uint32_t SPI_ReadBuffer( Spi* spi, void* pvBuffer, uint32_t dwLength ) ;
#endif

void SPI_Software_Reset(Spi *spi);
void SPI_Set_LastTransfer(Spi *spi);
void SPI_Clear_LastTransfer(Spi *spi);
void SPI_Mode_Master(Spi *spi);
void SPI_Mode_Slave(Spi *spi);
void SPI_Fixed_Peripheral(Spi *spi);
void SPI_Var_Peripheral(Spi *spi);
void SPI_CSdec_Sel(Spi *spi);
void SPI_CSdec_Dissel(Spi *spi);
void SPI_FalutDetect_Disable(Spi *spi);
void SPI_FalutDetect_Enable(Spi *spi);
void SPI_Loopback_Disable(Spi *spi);
void SPI_Loopback_Enable(Spi *spi);
void SPI_WaitData_En(Spi *spi);
void SPI_WaitData_Dis(Spi *spi);
void SPI_Set_PCS(Spi *spi,unsigned int value);
void SPI_Set_DLYBCS(Spi *spi,int value);
unsigned int SPI_Read_Data(Spi *spi);
unsigned int SPI_Read_PCS(Spi *spi);
void SPI_Write_Data(Spi *spi,unsigned int value);
void SPI_Write_Data_PCS(Spi *spi, unsigned int data,unsigned int pcs);
void SPI_Write_LastData_PCS(Spi *spi,unsigned int data,unsigned int pcs);
unsigned int SPI_Get_Status(Spi *spi,unsigned int status);
void SPI_Interrupt_Enable(Spi *spi,unsigned int interrupt);
void SPI_Interrupt_Disable(Spi *spi,unsigned int interrupt);
unsigned int SPI_Interrupt_Mask(Spi *spi,unsigned int interrupt);
unsigned int SPI_Send_Command(Spi *spi,char cmd);
void SPI_CSRx_CPOL(Spi *spi,unsigned int CS,unsigned int CPOL);
void SPI_CSRx_NCPHA(Spi *spi,unsigned int CS,unsigned int NCPHA);
void SPI_CSRx_CSAAT(Spi *spi,unsigned int CS,unsigned int CSAAT);
void SPI_CSRx_BITS(Spi *spi,unsigned int CS,unsigned int Bits);
void SPI_CSRx_SCBR(Spi *spi,unsigned int CS,unsigned int SCBR);
void SPI_CSRx_DLYBS(Spi *spi,unsigned int CS,unsigned int DLYBS);
void SPI_CSRx_DLYBCT(Spi *spi,unsigned int CS,int DLYBCT);
void SPI_Mode(Spi* spi,unsigned int CS,int mode);
#endif //_V_SPI_H

