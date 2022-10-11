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
 * File Name           : v_htol_dacc.c
 *----------------------------------------------------------------------------
*/

#include "v_htol_dacc.h"



// global variables
//extern uint32_t htol_iter;    // v_htol_main_functions.c definition
//extern unsigned int MCK_Freq; // v_htol_main_functions.c definition
extern volatile uint32_t periph_read_reg; // v_htol_main_functions.c definition
//extern volatile unsigned int it_flag[2]; // v_htol_it_routines.c definition


/*----------------------------------------------------------------------------*/
//* Function Name : run_dacc_htol
//* Object       : run DACC test for HTOL
//*               
//*
//* Parameters: dacc          = tested peripheral base address
//*             test_mode    = tested peripheral config (Parity mode)
//*             test_nb_iter = number of bytes to copy /or INFINITE_LOOP
//*---------------------------------------------------------------------------*/
extern void run_dacc_htol(Dacc *dacc, uint32_t test_mode)
{
 uint8_t  mode;

 
  Valid_DebugTrace( "* HTOL DACC TEST *\n\r");

  // ----- Disable DACC write protect
  dacc->DACC_WPMR = DACC_WPMR_WPKEY(DACC_KEY_VAL);
  
  // ----- DACC reset and disable all channels & interrupts
  dacc->DACC_CR   = DACC_CR_SWRST;
  dacc->DACC_CHDR = 0xFFFFFFFF;
  dacc->DACC_IDR  = 0xFFFFFFFF;
  
  // ----- DACC init
  mode = init_dacc_htol(dacc,test_mode);

  // ----- DACC test
  switch (mode){
                case 0: // not functional (reg access)
                  dacc_reg_access(dacc);
                  break;
                case 1:
                  break;
  default: break;}

  // ----- Enable DACC write protect
  dacc->DACC_WPMR = (DACC_WPMR_WPKEY(DACC_KEY_VAL))|DACC_WPMR_WPEN;
  dacc->DACC_MR   = ~(dacc->DACC_MR); // triggers WPROTERR flag

  return;
}



/*----------------------------------------------------------------------------*/
//* Function Name : init_dacc_htol
//* Object       : run DACC test for HTOL
//*---------------------------------------------------------------------------*/
uint32_t init_dacc_htol(Dacc *dacc, uint32_t test_mode)
{
 uint32_t dacc_next_mode;
 uint8_t  mode;
 
  mode = test_mode % HTOL_DACC_NB_TEST_MODE;
  switch (mode){
                case 0: // not functional (reg access)
                  dacc_next_mode = DACC_MODE0;
                  break;
                case 1:
                  //dacc_next_mode = DACC_MODE1;
                  // pseudo random config update
                  //reg32_update_fields(&dacc_next_mode,DACC_CONFIG_FIELDS);
                  break;
  default: break;}
 
  // Program modes
  dacc->DACC_MR = dacc_next_mode;

  // enable DACC interrupt (core level)
  nvic_dacc_it_enable();
  
  // DACC interrupt enable
  dacc->DACC_IER = DACC_IT_SOURCES_EN;

  return(mode);
}


/*----------------------------------------------------------------------------*/
//* Function Name : dacc_reg_access
//* Object        : read/write peripheral register access
//*---------------------------------------------------------------------------*/
void dacc_reg_access(Dacc *dacc)
{
  dacc->DACC_CR     = ~(dacc->DACC_CR);
  dacc->DACC_MR     = ~(dacc->DACC_MR);
  dacc->DACC_CHER   = ~(dacc->DACC_CHER);
  dacc->DACC_CHDR   = ~(dacc->DACC_CHDR);
  periph_read_reg   = ~(dacc->DACC_CHSR); //RO
  dacc->DACC_CDR    = ~(dacc->DACC_CDR);
  dacc->DACC_IER    = ~(dacc->DACC_IER);
  dacc->DACC_IDR    = ~(dacc->DACC_IDR);
  periph_read_reg   = ~(dacc->DACC_IMR);  //RO
  periph_read_reg   = ~(dacc->DACC_ISR);  //RO
  dacc->DACC_ACR    = ~(dacc->DACC_ACR);
  dacc->DACC_WPMR   = ~(dacc->DACC_WPMR); // (no effect)
  periph_read_reg   = ~(dacc->DACC_WPSR); //RO
}


/*----------------------------------------------------------------------------*/
//* Function Name : nvic_dacc_it_enable
//* Object        : enable DACC interrupt (core level)
//*---------------------------------------------------------------------------*/
void nvic_dacc_it_enable()
{
#ifdef ID_DACC
  nvic_enable_it(ID_DACC);
#endif
}

