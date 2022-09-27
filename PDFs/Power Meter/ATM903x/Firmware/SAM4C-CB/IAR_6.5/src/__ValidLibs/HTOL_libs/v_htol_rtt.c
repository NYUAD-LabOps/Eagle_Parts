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
 * File Name           : v_htol_rtt.c
 *----------------------------------------------------------------------------
*/

#include "v_htol_rtt.h"



// global variables
//extern uint32_t htol_iter;    // v_htol_main_functions.c definition
//extern unsigned int MCK_Freq; // v_htol_main_functions.c definition
extern volatile uint32_t periph_read_reg; // v_htol_main_functions.c definition
//extern volatile unsigned int it_flag[2]; // v_htol_it_routines.c definition


/*----------------------------------------------------------------------------*/
//* Function Name : run_rtt_htol
//* Object       : run RTT test for HTOL
//*               
//*
//* Parameters: rtt          = tested peripheral base address
//*             test_mode    = tested peripheral config (Parity mode)
//*             test_nb_iter = number of bytes to copy /or INFINITE_LOOP
//*---------------------------------------------------------------------------*/
extern void run_rtt_htol(Rtt *rtt, uint32_t test_mode)
{
 uint8_t  mode;

 
  Valid_DebugTrace( "* HTOL RTT TEST *\n\r");

  // ----- RTT disable all interrupts
  RTT->RTT_MR &= ~(RTT_MR_ALMIEN | RTT_MR_RTTINCIEN); // disable all IT
  
  // ----- RTT init
  mode = init_rtt_htol(rtt,test_mode);

  // ----- RTT test
  switch (mode){
                case 0: // not functional (reg access)
                  rtt_reg_access(rtt);
                  break;
                case 1:
                  break;
  default: break;}


  return;
}


/*----------------------------------------------------------------------------*/
//* Function Name : init_rtt_htol
//* Object       : run RTT test for HTOL
//*---------------------------------------------------------------------------*/
uint32_t init_rtt_htol(Rtt *rtt, uint32_t test_mode)
{
 uint32_t rtt_next_mode;
 uint8_t  mode;
 
  mode = test_mode % HTOL_RTT_NB_TEST_MODE;
  switch (mode){
                case 0: // not functional (reg access)
                  rtt_next_mode = RTT_MODE0;
                  break;
                case 1:
                  //rtt_next_mode = RTT_MODE1;
                  // pseudo random config update
                  //reg32_update_fields(&rtt_next_mode,RTT_CONFIG_FIELDS);
                  break;
  default: break;}
   
  // Program modes
  rtt->RTT_MR = rtt_next_mode;
  
  // enable ALL RTT interrupt (core level)
  nvic_rtt_it_enable();
  
  // RTT interrupt enable
  RTT->RTT_MR |= (RTT_MR_ALMIEN | RTT_MR_RTTINCIEN); // enable all IT

  return(mode);
}


/*----------------------------------------------------------------------------*/
//* Function Name : rtt_reg_access
//* Object        : read/write peripheral register access
//*---------------------------------------------------------------------------*/
void rtt_reg_access(Rtt *rtt)
{
  rtt->RTT_MR     = ~(rtt->RTT_MR);
  rtt->RTT_AR     = ~(rtt->RTT_AR);
  periph_read_reg =  (rtt->RTT_VR);
  periph_read_reg =  (rtt->RTT_SR); //RO
}


/*----------------------------------------------------------------------------*/
//* Function Name : nvic_rtt_it_enable
//* Object        : enable ALL RTT interrupt (core level)
//*---------------------------------------------------------------------------*/
void nvic_rtt_it_enable()
{
#ifdef ID_RTT
  nvic_enable_it(ID_RTT);
#endif
}

