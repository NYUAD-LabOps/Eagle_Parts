/*-----------------------------------------------------------------------------
 *           ATMEL Microcontroller Software Support  -  ROUSSET  -
 *-----------------------------------------------------------------------------
 * DISCLAIMER:  THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *----------------------------------------------------------------------------
 * File Name           : v_htol_it_routines.c
 *----------------------------------------------------------------------------
*/

#include "v_htol_it_routines.h"


// global variables
volatile uint8_t spi_flag;
volatile unsigned int it_flag[2];             // debug purpose
volatile unsigned int it_count[NB_PERIPH_ID]; // debug purpose


/*----------------------------------------------------------------------------*/
//* Function Name : ACC_IrqHandler
//* Object        : Analog Comparator interrupt routine
//*---------------------------------------------------------------------------*/
#ifdef ID_ACC
void ACC_IrqHandler( void )
{
  it_flag[0] = IT_FLAG_PATTERN(ID_ACC);
  it_flag[1] = REG_ACC_ISR;
  ++(it_count[ID_ACC]);
  ACC->ACC_IDR = 0xFFFFFFFF ; // disable all IT
  return;
}
#endif
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
//* Function Name : ADC_IrqHandler
//* Object        : Analog to Digital Converter interrupt routine
//*---------------------------------------------------------------------------*/
#ifdef ID_ADC
void ADC_IrqHandler( void )
{
  it_flag[0] = IT_FLAG_PATTERN(ID_ADC);
  it_flag[1] = REG_ADC_CHSR;
  ++(it_count[ID_ADC]);
  ADC->ADC_IDR = 0xFFFFFFFF ; // disable all IT
  return;
}
#endif
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
//* Function Name : CRCCU_IrqHandler
//* Object        : CRC unit interrupt routine
//*---------------------------------------------------------------------------*/
#ifdef ID_CRCCU
void CRCCU_IrqHandler( void )
{
  it_flag[0] = IT_FLAG_PATTERN(ID_CRCCU);
  it_flag[1] = REG_CRCCU_SR;
  ++(it_count[ID_CRCCU]);
  CRCCU->CRCCU_IDR = 0xFFFFFFFF ; // disable all IT
  CRCCU->CRCCU_DMA_IDR = 0xFFFFFFFF ; // disable all IT
  return;
}
#endif
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
//* Function Name : DACC_IrqHandler
//* Object        : Digital to Analog Converter interrupt routine
//*---------------------------------------------------------------------------*/
#ifdef ID_DACC
void DACC_IrqHandler( void )
{
  it_flag[0] = IT_FLAG_PATTERN(ID_DACC);
  it_flag[1] = REG_DACC_ISR;
  ++(it_count[ID_DACC]);
  DACC->DACC_IDR = 0xFFFFFFFF ; // disable all IT
  return;
}
#endif
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
//* Function Name : PIOx_IrqHandler
//* Object        : Parallel Input Output interrupt routines
//*---------------------------------------------------------------------------*/
#ifdef ID_PIOA
void PIOA_IrqHandler( void )
{
  it_flag[0] = IT_FLAG_PATTERN(ID_PIOA);
  it_flag[1] = REG_PIOA_PSR;
  ++(it_count[ID_PIOA]);
  PIOA->PIO_IDR   = 0xFFFFFFFF ; // disable all IT
  PIOA->PIO_AIMDR = 0xFFFFFFFF ; // disable all IT
  PIOA->PIO_PCIDR = 0xFFFFFFFF ; // disable all IT
  return;
}
#endif

#ifdef ID_PIOB
void PIOB_IrqHandler( void )
{
  it_flag[0] = IT_FLAG_PATTERN(ID_PIOB);
  it_flag[1] = REG_PIOB_PSR;
  ++(it_count[ID_PIOB]);
  PIOB->PIO_IDR   = 0xFFFFFFFF ; // disable all IT
  PIOB->PIO_AIMDR = 0xFFFFFFFF ; // disable all IT
  PIOB->PIO_PCIDR = 0xFFFFFFFF ; // disable all IT
  return;
}
#endif

#ifdef ID_PIOC
void PIOC_IrqHandler( void )
{
  it_flag[0] = IT_FLAG_PATTERN(ID_PIOC);
  it_flag[1] = REG_PIOC_PSR;
  ++(it_count[ID_PIOC]);
  PIOC->PIO_IDR   = 0xFFFFFFFF ; // disable all IT
  PIOC->PIO_AIMDR = 0xFFFFFFFF ; // disable all IT
  PIOC->PIO_PCIDR = 0xFFFFFFFF ; // disable all IT
  return;
}
#endif

#ifdef ID_PIOD
void PIOD_IrqHandler( void )
{
  it_flag[0] = IT_FLAG_PATTERN(ID_PIOD);
  it_flag[1] = REG_PIOD_PSR;
  ++(it_count[ID_PIOD]);
  PIOD->PIO_IDR   = 0xFFFFFFFF ; // disable all IT
  PIOD->PIO_AIMDR = 0xFFFFFFFF ; // disable all IT
  PIOD->PIO_PCIDR = 0xFFFFFFFF ; // disable all IT
  return;
}
#endif

#ifdef ID_PIOE
void PIOE_IrqHandler( void )
{
  it_flag[0] = IT_FLAG_PATTERN(ID_PIOE);
  it_flag[1] = REG_PIOE_PSR;
  ++(it_count[ID_PIOE]);
  PIOE->PIO_IDR   = 0xFFFFFFFF ; // disable all IT
  PIOE->PIO_AIMDR = 0xFFFFFFFF ; // disable all IT
  PIOE->PIO_PCIDR = 0xFFFFFFFF ; // disable all IT
  return;
}
#endif
/*----------------------------------------------------------------------------*/


//*----------------------------------------------------------------------------*/
//* Function Name : PWM_IrqHandler
//* Object        : Pulse Width Modulation controller interrupt routine
//*---------------------------------------------------------------------------*/
#ifdef ID_PWM
void PWM_IrqHandler( void )
{
  it_flag[0] = IT_FLAG_PATTERN(ID_PWM);
  it_flag[1] = REG_PWM_ISR1;
  //REG_PWM_ISR2 not saved
  ++(it_count[ID_PWM]);
  PWM->PWM_IDR1 = 0xFFFFFFFF ; // disable all IT
  PWM->PWM_IDR2 = 0xFFFFFFFF ; // disable all IT
  return;
}
#endif
/*----------------------------------------------------------------------------*/


//*----------------------------------------------------------------------------*/
//* Function Name : RTC_IrqHandler
//* Object        : Real Time Clock interrupt routine
//*---------------------------------------------------------------------------*/
#ifdef ID_RTC
void RTC_IrqHandler( void )
{
  it_flag[0] = IT_FLAG_PATTERN(ID_RTC);
  it_flag[1] = REG_RTC_SR;
  ++(it_count[ID_RTC]);
  RTC->RTC_IDR = 0xFFFFFFFF ; // disable all IT
  return;
}
#endif
/*----------------------------------------------------------------------------*/


//*----------------------------------------------------------------------------*/
//* Function Name : RTT_IrqHandler
//* Object        : Real Time Timer interrupt routine
//*---------------------------------------------------------------------------*/
#ifdef ID_RTT
void RTT_IrqHandler( void )
{
  it_flag[0] = IT_FLAG_PATTERN(ID_RTT);
  it_flag[1] = REG_RTT_SR;
  ++(it_count[ID_RTT]);
  RTT->RTT_MR &= ~(RTT_MR_ALMIEN | RTT_MR_RTTINCIEN); // disable all IT
  return;
}
#endif
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
//* Function Name : SPIx_IrqHandler
//* Object        : Serial Peripheral Interface interrupt routines
//*---------------------------------------------------------------------------*/
#ifdef ID_SPI
void SPI_IrqHandler( void )
{
  it_flag[0] = IT_FLAG_PATTERN(ID_SPI);
  it_flag[1] = REG_SPI_SR;
  ++(it_count[ID_SPI]);
  //SPI->SPI_RDR;
  spi_flag = 1;
  SPI->SPI_IDR = 0xFFFFFFFF ; // disable all IT
  return;
}
#endif

#ifdef ID_SPI0
void SPI0_IrqHandler( void )
{
  it_flag[0] = IT_FLAG_PATTERN(ID_SPI0);
  it_flag[1] = REG_SPI0_SR;
  ++(it_count[ID_SPI0]);
  //SPI0->SPI_RDR;
  spi_flag = 1;
  SPI0->SPI_IDR = 0xFFFFFFFF ; // disable all IT
  return;
}
#endif

#ifdef ID_SPI1
void SPI1_IrqHandler( void )
{
  it_flag[0] = IT_FLAG_PATTERN(ID_SPI1);
  it_flag[1] = REG_SPI1_SR;
  ++(it_count[ID_SPI1]);
  //SPI1->SPI_RDR;
  spi_flag = 1;
  SPI1->SPI_IDR = 0xFFFFFFFF ; // disable all IT
  return;
}
#endif
/*----------------------------------------------------------------------------*/


//*----------------------------------------------------------------------------*/
//* Function Name : SSC_IrqHandler
//* Object        : Synchronous Serial Controller interrupt routine
//*---------------------------------------------------------------------------*/
#ifdef ID_SSC
void SSC_IrqHandler( void )
{
  it_flag[0] = IT_FLAG_PATTERN(ID_SSC);
  it_flag[1] = REG_SSC_SR;
  ++(it_count[ID_SSC]);
  SSC->SSC_IDR = 0xFFFFFFFF ; // disable all IT
  return;
}
#endif
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
//* Function Name : TCx_IrqHandler
//* Object        : Timer counter interrupt routines
//*---------------------------------------------------------------------------*/
#ifdef ID_TC0
void TC0_IrqHandler( void )
{
  it_flag[0] = IT_FLAG_PATTERN(ID_TC0);
  it_flag[1] = REG_TC0_SR0;
  ++(it_count[ID_TC0]);
  return;
}
#endif

#ifdef ID_TC1
void TC1_IrqHandler( void )
{
  it_flag[0] = IT_FLAG_PATTERN(ID_TC1);
  it_flag[1] = REG_TC0_SR1;
  ++(it_count[ID_TC1]);
  return;
}
#endif

#ifdef ID_TC2
void TC2_IrqHandler( void )
{
  it_flag[0] = IT_FLAG_PATTERN(ID_TC2);
  it_flag[1] = REG_TC0_SR2;
  ++(it_count[ID_TC2]);
  return;
}
#endif

#ifdef ID_TC3
void TC3_IrqHandler( void )
{
  it_flag[0] = IT_FLAG_PATTERN(ID_TC3);
  it_flag[1] = REG_TC1_SR0;
  ++(it_count[ID_TC3]);
  return;
}
#endif

#ifdef ID_TC4
void TC4_IrqHandler( void )
{
  it_flag[0] = IT_FLAG_PATTERN(ID_TC4);
  it_flag[1] = REG_TC1_SR1;
  ++(it_count[ID_TC4]);
  return;
}
#endif

#ifdef ID_TC5
void TC5_IrqHandler( void )
{
  it_flag[0] = IT_FLAG_PATTERN(ID_TC5);
  it_flag[1] = REG_TC1_SR2;
  ++(it_count[ID_TC5]);
  return;
}
#endif
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
//* Function Name : TWIx_IrqHandler
//* Object        : Two Wires Interface interrupt routines
//*---------------------------------------------------------------------------*/
#ifdef ID_TWI0
void TWI0_IrqHandler( void )
{
  it_flag[0] = IT_FLAG_PATTERN(ID_TWI0);
  it_flag[1] = REG_TWI0_SR;
  ++(it_count[ID_TWI0]);
  TWI0->TWI_IDR = 0xFFFFFFFF ; // disable all IT
  return;
}
#endif

#ifdef ID_TWI1
void TWI1_IrqHandler( void )
{
  it_flag[0] = IT_FLAG_PATTERN(ID_TWI1);
  it_flag[1] = REG_TWI1_SR;
  ++(it_count[ID_TWI1]);
   TWI1->TWI_IDR = 0xFFFFFFFF ; // disable all IT
  return;
}
#endif
/*----------------------------------------------------------------------------*/


