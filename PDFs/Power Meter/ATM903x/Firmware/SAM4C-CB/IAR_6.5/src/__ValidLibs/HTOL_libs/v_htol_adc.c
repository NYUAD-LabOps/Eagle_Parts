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
 * File Name           : v_htol_adc.c
 *----------------------------------------------------------------------------
*/

#include "v_htol_adc.h"



// global variables
//extern uint32_t htol_iter;    // v_htol_main_functions.c definition
//extern unsigned int MCK_Freq; // v_htol_main_functions.c definition
extern volatile uint32_t periph_read_reg; // v_htol_main_functions.c definition
//extern volatile unsigned int it_flag[2]; // v_htol_it_routines.c definition


/*----------------------------------------------------------------------------*/
//* Function Name : run_adc_htol
//* Object       : run ADC test for HTOL
//*               
//*
//* Parameters: adc          = tested peripheral base address
//*             test_mode    = tested peripheral config (Parity mode)
//*             test_nb_iter = number of bytes to copy /or INFINITE_LOOP
//*---------------------------------------------------------------------------*/
extern void run_adc_htol(Adc *adc, uint32_t test_mode)
{
 uint8_t  mode;

 
  Valid_DebugTrace( "* HTOL ADC TEST *\n\r");

  // ----- Disable ADC write protect
  adc->ADC_WPMR = ADC_WPMR_WPKEY(ADC_KEY_VAL);

  // ----- ADC reset
  adc->ADC_CR = ADC_CR_SWRST;

  // ----- ADC disable all interrupts
  adc->ADC_IDR = 0xFFFFFFFF;

  // ----- ADC init
  mode = init_adc_htol(adc,test_mode);

  // ----- ADC test
  switch (mode){
                case 0: // not functional (reg access)
                  adc_reg_access(adc);
                  break;
                case 1:
                  break;
  default: break;}

  // ----- Enable ADC write protect
  adc->ADC_WPMR = ADC_WPMR_WPKEY(ADC_KEY_VAL) | ADC_WPMR_WPEN;
  adc->ADC_MR = ~(adc->ADC_MR); // triggers WPROTERR flag

  return;
}



/*----------------------------------------------------------------------------*/
//* Function Name : init_adc_htol
//* Object       : run ADC test for HTOL
//*---------------------------------------------------------------------------*/
uint32_t init_adc_htol(Adc *adc, uint32_t test_mode)
{
 uint32_t adc_next_mode;
 uint8_t  mode;
 
  mode = test_mode % HTOL_ADC_NB_TEST_MODE;
  switch (mode){
                case 0: // not functional (reg access)
                  adc_next_mode = ADC_MODE0;
                  break;
                case 1:
                  //adc_next_mode = ADC_MODE1;
                  break;
  default: break;}
 
  // enable ADC interrupt (core level)
  nvic_adc_it_enable();
  
  // pseudo random config update
  reg32_update_fields(&adc_next_mode,ADC_CONFIG_FIELDS);
  
  // ADC interrupt enable
  adc->ADC_IER = ADC_IT_SOURCES_EN;

  return(mode);
}


/*----------------------------------------------------------------------------*/
//* Function Name : adc_reg_access
//* Object        : read/write peripheral register access
//*---------------------------------------------------------------------------*/
void adc_reg_access(Adc *adc)
{
 uint32_t i;
 
  adc->ADC_CR     = ~(adc->ADC_CR);
  adc->ADC_MR     = ~(adc->ADC_MR);
  adc->ADC_SEQR1  = ~(adc->ADC_SEQR1);
  adc->ADC_SEQR2  = ~(adc->ADC_SEQR2);
  adc->ADC_CHER   = 0xFFFFFFFF;
  adc->ADC_CHDR   = 0xFFFFFFFF;
  periph_read_reg = adc->ADC_CHSR;  //RO
  periph_read_reg = adc->ADC_LCDR;  //RO
  adc->ADC_IER    = 0xFFFFFFFF;
  adc->ADC_IDR    = 0xFFFFFFFF;
  periph_read_reg = adc->ADC_IMR;  //RO
  periph_read_reg = adc->ADC_ISR;  //RO
  periph_read_reg = adc->ADC_OVER; //RO
  adc->ADC_EMR    = ~(adc->ADC_EMR);
  adc->ADC_CWR    = ~(adc->ADC_CWR);
  adc->ADC_CGR    = ~(adc->ADC_CGR);
  adc->ADC_COR    = ~(adc->ADC_COR);
  for(i=0;i<ADC_CHANNEL_NUMBER;++i){periph_read_reg = adc->ADC_CDR[i];} //RO
  adc->ADC_ACR    = ~(adc->ADC_ACR);
  adc->ADC_WPMR   = ~(adc->ADC_WPMR); // (no effect)
  periph_read_reg = adc->ADC_WPSR;    //RO
  //...
}


/*----------------------------------------------------------------------------*/
//* Function Name : nvic_adc_it_enable
//* Object        : enable ADC interrupt (core level)
//*---------------------------------------------------------------------------*/
void nvic_adc_it_enable()
{
#ifdef ID_ADC
  nvic_enable_it(ID_ADC);
#endif
}

