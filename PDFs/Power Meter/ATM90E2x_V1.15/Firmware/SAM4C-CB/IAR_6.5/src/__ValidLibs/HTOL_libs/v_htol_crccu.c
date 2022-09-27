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
 * File Name           : v_htol_crccu.c
 *----------------------------------------------------------------------------
*/

#include "v_htol_crccu.h"



// global variables
//extern uint32_t htol_iter;    // v_htol_main_functions.c definition
//extern unsigned int MCK_Freq; // v_htol_main_functions.c definition
extern volatile uint32_t periph_read_reg; // v_htol_main_functions.c definition
//extern volatile unsigned int it_flag[2]; // v_htol_it_routines.c definition


/*----------------------------------------------------------------------------*/
//* Function Name : run_crccu_htol
//* Object       : run CRCCU test for HTOL
//*               
//*
//* Parameters: crccu          = tested peripheral base address
//*             test_mode    = tested peripheral config (Parity mode)
//*             test_nb_iter = number of bytes to copy /or INFINITE_LOOP
//*---------------------------------------------------------------------------*/
extern void run_crccu_htol(Crccu *crccu, uint32_t test_mode)
{
 uint8_t  mode;

 
  Valid_DebugTrace( "* HTOL CRCCU TEST *\n\r");

  // ----- reset CRCCU and disable all interrupts
  crccu->CRCCU_CR      = CRCCU_CR_RESET;
  crccu->CRCCU_MR     &= (~(CRCCU_MR_ENABLE | CRCCU_MR_COMPARE));
  crccu->CRCCU_IDR     = 0xFFFFFFFF;
  crccu->CRCCU_DMA_IDR = 0xFFFFFFFF;

  // ----- CRCCU init
  mode = init_crccu_htol(crccu,test_mode);

  // ----- CRCCU test
  switch (mode){
                case 0: // not functional (reg access)
                  crccu_reg_access(crccu);
                  break;
                case 1:
                  break;
  default: break;}


  return;
}



/*----------------------------------------------------------------------------*/
//* Function Name : init_crccu_htol
//* Object       : run CRCCU test for HTOL
//*---------------------------------------------------------------------------*/
uint32_t init_crccu_htol(Crccu *crccu, uint32_t test_mode)
{
 uint32_t crccu_next_mode;
 uint8_t  mode;
 
  mode = test_mode % HTOL_CRCCU_NB_TEST_MODE;
  switch (mode){
                case 0: // not functional (reg access)
                  crccu_next_mode = CRCCU_MODE0;
                  break;
                case 1:
                  //crccu_next_mode = CRCCU_MODE1;
                  // pseudo random config update
                  //reg32_update_fields(&crccu_next_mode,CRCCU_CONFIG_FIELDS);
                  break;
  default: break;}

  // Program modes
  crccu->CRCCU_MR = crccu_next_mode;
  
  // enable CRCCU interrupt (core level)
  nvic_crccu_it_enable();
  
  // CRCCU interrupt enable
  crccu->CRCCU_IER = CRCCU_IT_SOURCES_EN;

  return(mode);
}


/*----------------------------------------------------------------------------*/
//* Function Name : crccu_reg_access
//* Object        : read/write peripheral register access
//*---------------------------------------------------------------------------*/
void crccu_reg_access(Crccu *crccu)
{
  crccu->CRCCU_DSCR    = ~(crccu->CRCCU_DSCR);
  crccu->CRCCU_DMA_EN  = ~(crccu->CRCCU_DMA_EN);
  crccu->CRCCU_DMA_DIS = ~(crccu->CRCCU_DMA_DIS);
  periph_read_reg      = ~(crccu->CRCCU_DMA_SR);   //RO
  crccu->CRCCU_DMA_IER = ~(crccu->CRCCU_DMA_IER);
  crccu->CRCCU_DMA_IDR = ~(crccu->CRCCU_DMA_IDR);
  periph_read_reg      = ~(crccu->CRCCU_DMA_ISR);  //RO
  crccu->CRCCU_CR      = ~(crccu->CRCCU_CR);
  crccu->CRCCU_MR      = ~(crccu->CRCCU_MR);
  crccu->CRCCU_IER     = ~(crccu->CRCCU_IER);
  crccu->CRCCU_IDR     = ~(crccu->CRCCU_IDR);
  periph_read_reg      = ~(crccu->CRCCU_DMA_IMR);  //RO
  periph_read_reg      = ~(crccu->CRCCU_DMA_ISR);  //RO
  periph_read_reg      = ~(crccu->CRCCU_SR);       //RO
  periph_read_reg      = ~(crccu->CRCCU_IMR);      //RO
  periph_read_reg      = ~(crccu->CRCCU_ISR);      //RO
  //...
}


/*----------------------------------------------------------------------------*/
//* Function Name : nvic_crccu_it_enable
//* Object        : enable CRCCU interrupt (core level)
//*---------------------------------------------------------------------------*/
void nvic_crccu_it_enable()
{
#ifdef ID_CRCCU
  nvic_enable_it(ID_CRCCU);
#endif
}

