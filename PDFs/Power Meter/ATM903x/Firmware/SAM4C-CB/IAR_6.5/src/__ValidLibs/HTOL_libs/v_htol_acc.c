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
 * File Name           : v_htol_acc.c
 *----------------------------------------------------------------------------
*/

#include "v_htol_acc.h"



// global variables
//extern uint32_t htol_iter;    // v_htol_main_functions.c definition
//extern unsigned int MCK_Freq; // v_htol_main_functions.c definition
extern volatile uint32_t periph_read_reg; // v_htol_main_functions.c definition
//extern volatile unsigned int it_flag[2]; // v_htol_it_routines.c definition


/*----------------------------------------------------------------------------*/
//* Function Name : run_acc_htol
//* Object       : run ACC test for HTOL
//*               
//*
//* Parameters: acc          = tested peripheral base address
//*             test_mode    = tested peripheral config (Parity mode)
//*---------------------------------------------------------------------------*/
extern void run_acc_htol(Acc *acc, uint32_t test_mode)
{
 uint8_t  mode;

 
  Valid_DebugTrace( "* HTOL ACC TEST *\n\r");

  // Software reset
  acc_reset(acc);
  
  // ----- Disable ACC write protect
  acc->ACC_WPMR = ACC_WPMR_WPKEY(ACC_KEY_VAL);

  // ----- ACC disable
  acc_disable(acc);
  acc_disable_interrupt(acc);
  
  // ----- ACC init
  mode = init_acc_htol(acc,test_mode);

  // ----- ACC test
  switch (mode){
                case 0: // not functional (reg access)
                  acc_reg_access(acc);
                  break;
                case 1:
                  acc_enable(acc);
                  break;
  default: break;}

  // ----- Enable ACC write protect
  acc->ACC_WPMR = ACC_WPMR_WPKEY(ACC_KEY_VAL) | ACC_WPMR_WPEN;
  acc->ACC_MR = ~(acc->ACC_MR); // triggers WPROTERR flag
  
  return;
}



/*----------------------------------------------------------------------------*/
//* Function Name : init_acc_htol
//* Object       : run ACC test for HTOL
//*---------------------------------------------------------------------------*/
uint32_t init_acc_htol(Acc *acc, uint32_t test_mode)
{
 uint32_t acc_next_mode,acr_next_mode;
 uint8_t  mode;
 
  mode = test_mode % HTOL_ACC_NB_TEST_MODE;
  switch (mode){
                case 0: // not functional (reg access)
                  return(mode);
                case 1:
                  acc_next_mode = ACC_MR1;
                  acr_next_mode = ACC_ACR1;
                  // pseudo random config update
                  reg32_update_fields(&acc_next_mode,ACC_MR1_FIELDS);
                  reg32_update_fields(&acr_next_mode,ACC_ACR1_FIELDS);
                  break;
  default: break;}

  // Program modes
  acc->ACC_MR   = acc_next_mode;
  acc->ACC_ACR  = acr_next_mode;
  
  // enable ACC interrupt (core level)
  nvic_acc_it_enable();
  
  // ACC interrupt enable
  acc_enable_interrupt(acc);

  return(mode);
}


/*----------------------------------------------------------------------------*/
//* Function Name : acc_reg_access
//* Object        : read/write peripheral register access
//*---------------------------------------------------------------------------*/
void acc_reg_access(Acc *acc)
{
  //acc->ACC_CR     = ~(acc->ACC_CR); resets ACC
  acc->ACC_MR     = ~(acc->ACC_MR);
  acc->ACC_IER    = ~(acc->ACC_IER);
  acc->ACC_IDR    = ~(acc->ACC_IDR);
  periph_read_reg = ~(acc->ACC_IMR);  //RO
  periph_read_reg = ~(acc->ACC_ISR);  //RO
  acc->ACC_ACR    = ~(acc->ACC_ACR);
  acc->ACC_WPMR   = ~(acc->ACC_WPMR); // (no effect)
  periph_read_reg = ~(acc->ACC_WPSR); //RO
}


/*----------------------------------------------------------------------------*/
//* Function Name : nvic_acc_it_enable
//* Object        : enable ALL ACC interrupt (core level)
//*---------------------------------------------------------------------------*/
void nvic_acc_it_enable()
{
#ifdef ID_ACC
  nvic_enable_it(ID_ACC);
#endif
}

