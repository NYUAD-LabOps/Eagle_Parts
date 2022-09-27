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
 * File Name           : v_htol_twi.c
 *----------------------------------------------------------------------------
*/

#include "v_htol_twi.h"



// global variables
//extern uint32_t htol_iter;                // v_htol_main_functions.c definition
extern unsigned int MCK_Freq;             // v_htol_main_functions.c definition
extern volatile uint32_t periph_read_reg; // v_htol_main_functions.c definition
//extern volatile unsigned int it_flag[2];  // v_htol_it_routines.c definition


/*----------------------------------------------------------------------------*/
//* Function Name : run_twi_htol
//* Object       : run TWI test for HTOL
//*               
//*
//* Parameters: twi          = tested peripheral base address
//*             test_mode    = tested peripheral config (Parity mode)
//*             test_nb_iter = number of bytes to copy /or INFINITE_LOOP
//*---------------------------------------------------------------------------*/
extern void run_twi_htol(Twi *twi, uint32_t test_mode, uint32_t test_nb_iter)
{
 uint8_t  mode, p_rand_byte;
 
 
  Valid_DebugTrace( "* HTOL TWI TEST *\n\r");

  // ----- TWI disable
  TWI_DisableIt(twi,TWI_IT_SOURCES_EN);
  
  // ----- TWI init
  mode = init_twi_htol(twi,test_mode);

  // ----- TWI test
  switch (mode){
                case 0: // not functional (reg access)
                  twi_reg_access(twi);
                  break;
                case 1: // Master read
                  twi->TWI_CR = TWI_CR_START; // should generate NACK
                  break;
                case 2: // Master write
                  reg8_update_fields(&p_rand_byte,0xFF);
                  twi->TWI_THR = p_rand_byte;       // should generate NACK
                  break;
                case 3: // Slave
                  // Nothing to do...
                  break;
  default: break;}

  return;
}



/*----------------------------------------------------------------------------*/
//* Function Name : init_twi_htol
//* Object       : run TC test for HTOL
//*---------------------------------------------------------------------------*/
uint8_t init_twi_htol(Twi *twi, uint32_t test_mode)
{
 uint32_t twi_next_mode, twi_ck_freq;
 uint8_t  mode, slv_addr;
 
  mode = test_mode % HTOL_TWI_NB_TEST_MODE;
  switch (mode){
                case 0: // not functional (reg access)
                  return(mode); // No init
                case 1: // Master read
                  twi_next_mode = TWI_MST_MODE_R;
                  break;
                case 2: // Master write
                  twi_next_mode = TWI_MST_MODE_W;
                  break;
                case 3: // Slave
                  twi_next_mode = TWI_SLV_MODE;
                  break;
  default: break;}
 
  // enable ALL TWI interrupt (core level)
  nvic_twi_it_enable();

  twi_ck_freq = TWI_MAX_FREQ;
  // pseudo random config update
  if (mode==3){// Slave
    reg32_update_fields(&twi_next_mode,TWI_SLV_MODE_FIELDS);
    slv_addr = (uint8_t)(twi_next_mode>>TWI_SMR_SADR_Pos);
    TWI_ConfigureSlave(twi,slv_addr);
    }
  else{ //master
    TWI_ConfigureMaster(twi,twi_ck_freq,MCK_Freq);
    reg32_update_fields(&twi_next_mode,TWI_MST_MODE_FIELDS);
    twi->TWI_MMR = twi_next_mode;
    twi_next_mode = 0;
    reg32_update_fields(&twi_next_mode,TWI_IADR_IADR_Msk);
    twi->TWI_IADR = twi_next_mode;
    }
  
  // TWI interrupt enable
  TWI_EnableIt(twi,TWI_IT_SOURCES_EN);


  return(mode);
}



/*----------------------------------------------------------------------------*/
//* Function Name : twi_reg_access
//* Object        : read/write peripheral register access
//*---------------------------------------------------------------------------*/
void twi_reg_access(Twi *twi)
{
  twi->TWI_CR     = ~(twi->TWI_CR);
  twi->TWI_MMR    = ~(twi->TWI_MMR);
  twi->TWI_SMR    = ~(twi->TWI_SMR);
  twi->TWI_IADR   = ~(twi->TWI_IADR);
  twi->TWI_CWGR   = ~(twi->TWI_CWGR);
  periph_read_reg = ~(twi->TWI_SR);  //RO
  twi->TWI_IER    = ~(twi->TWI_IER);
  twi->TWI_IDR    = ~(twi->TWI_IDR);
  periph_read_reg = ~(twi->TWI_IMR); //RO
  periph_read_reg = ~(twi->TWI_RHR); //RO
  twi->TWI_THR    = ~(twi->TWI_THR);
}



/*----------------------------------------------------------------------------*/
//* Function Name : nvic_twi_it_enable
//* Object        : enable ALL TWI interrupt (core level)
//*---------------------------------------------------------------------------*/
void nvic_twi_it_enable()
{
#ifdef ID_TWI0
  nvic_enable_it(ID_TWI0);
#endif
#ifdef ID_TWI1
  nvic_enable_it(ID_TWI1);
#endif
#ifdef ID_TWI2
  nvic_enable_it(ID_TWI2);
#endif
}

