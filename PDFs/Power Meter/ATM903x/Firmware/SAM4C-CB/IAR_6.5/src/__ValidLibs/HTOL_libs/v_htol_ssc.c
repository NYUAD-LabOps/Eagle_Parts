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
 * File Name           : v_htol_ssc.c
 *----------------------------------------------------------------------------
*/

#include "v_htol_ssc.h"



// global variables
//extern uint32_t htol_iter;    // v_htol_main_functions.c definition
//extern unsigned int MCK_Freq; // v_htol_main_functions.c definition
extern volatile uint32_t periph_read_reg; // v_htol_main_functions.c definition
//extern volatile unsigned int it_flag[2]; // v_htol_it_routines.c definition


/*----------------------------------------------------------------------------*/
//* Function Name : run_ssc_htol
//* Object       : run SSC test for HTOL
//*               
//*
//* Parameters: ssc          = tested peripheral base address
//*             test_mode    = tested peripheral config (Parity mode)
//*             test_nb_iter = number of bytes to copy /or INFINITE_LOOP
//*---------------------------------------------------------------------------*/
extern void run_ssc_htol(Ssc *ssc, uint32_t test_mode)//, uint32_t test_nb_iter)
{
 uint8_t  mode;

 
  Valid_DebugTrace( "* HTOL SSC TEST *\n\r");

  // ----- Disable SSC write protect
  ssc->SSC_WPMR = SSC_WPMR_WPKEY(SSC_KEY_VAL);
  
  // ----- Reset SSC and disable all channels & interrupts
  ssc->SSC_CR  = SSC_CR_SWRST; // Software Reset
  ssc->SSC_CR  = SSC_CR_RXDIS | SSC_CR_TXDIS; // Channels disable
  ssc->SSC_IDR = 0xFFFFFFFF;
  
  // ----- SSC init
  mode = init_ssc_htol(ssc,test_mode);

  // ----- SSC test
  switch (mode){
                case 0: // not functional (reg access)
                  ssc_reg_access(ssc);
                  break;
                case 1:
                  break;
  default: break;}

  // ----- Enable SSC write protect
  ssc->SSC_WPMR = SSC_WPMR_WPKEY(SSC_KEY_VAL)|SSC_WPMR_WPEN;
  ssc->SSC_CMR  = ~(ssc->SSC_CMR); // triggers WPVS flag;
  
  return;
}



/*----------------------------------------------------------------------------*/
//* Function Name : init_ssc_htol
//* Object       : run SSC test for HTOL
//*---------------------------------------------------------------------------*/
uint32_t init_ssc_htol(Ssc *ssc, uint32_t test_mode)
{
 uint32_t ssc_next_mode;
 uint8_t  mode;
 
  mode = test_mode % HTOL_SSC_NB_TEST_MODE;
  switch (mode){
                case 0: // not functional (reg access)
                  ssc_next_mode = SSC_MODE0;
                  break;
                case 1:
                  //ssc_next_mode = SSC_MODE1;
                  // pseudo random config update
                  //reg32_update_fields(&ssc_next_mode,SSC_CONFIG_FIELDS);
                  break;
  default: break;}
  
  // Program modes
  ssc->SSC_CMR = ssc_next_mode;
 
  // enable ALL SSC interrupt (core level)
  nvic_ssc_it_enable();
  
  // SSC interrupt enable
  ssc->SSC_IER = SSC_IT_SOURCES_EN;

  return(mode);
}


/*----------------------------------------------------------------------------*/
//* Function Name : ssc_reg_access
//* Object        : read/write peripheral register access
//*---------------------------------------------------------------------------*/
void ssc_reg_access(Ssc *ssc)
{
  ssc->SSC_CR     = ~(ssc->SSC_CR);
  ssc->SSC_CMR    = ~(ssc->SSC_CMR);
  ssc->SSC_RCMR   = ~(ssc->SSC_RCMR);
  ssc->SSC_RFMR   = ~(ssc->SSC_RFMR);
  ssc->SSC_TCMR   = ~(ssc->SSC_TCMR);
  ssc->SSC_TFMR   = ~(ssc->SSC_TFMR);
  periph_read_reg = ~(ssc->SSC_RHR);  //RO
  ssc->SSC_THR    = ~(ssc->SSC_THR);
  periph_read_reg = ~(ssc->SSC_RSHR); //RO
  ssc->SSC_TSHR   = ~(ssc->SSC_TSHR);
  ssc->SSC_RC0R   = ~(ssc->SSC_RC0R);
  ssc->SSC_RC1R   = ~(ssc->SSC_RC1R);
  periph_read_reg = ~(ssc->SSC_SR);   //RO
  ssc->SSC_IER    = ~(ssc->SSC_IER);
  ssc->SSC_IDR    = ~(ssc->SSC_IDR);
  periph_read_reg = ~(ssc->SSC_IMR);  //RO
  ssc->SSC_WPMR   = ~(ssc->SSC_WPMR); // no effect (no key)
  periph_read_reg = ~(ssc->SSC_WPSR); //RO
}


/*----------------------------------------------------------------------------*/
//* Function Name : nvic_ssc_it_enable
//* Object        : enable ALL SSC interrupt (core level)
//*---------------------------------------------------------------------------*/
void nvic_ssc_it_enable()
{
#ifdef ID_SSC
  nvic_enable_it(ID_SSC);
#endif
}

