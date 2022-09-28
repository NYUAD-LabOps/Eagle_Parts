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
 * File Name           : v_htol_tc.c
 *----------------------------------------------------------------------------
*/

#include "v_htol_tc.h"



// global variables
extern uint32_t htol_iter;    // v_htol_main_functions.c definition
//extern unsigned int MCK_Freq; // v_htol_main_functions.c definition
extern volatile unsigned int it_flag[2]; // v_htol_it_routines.c definition


/*----------------------------------------------------------------------------*/
//* Function Name : run_tc_htol
//* Object       : run TC test for HTOL
//*               
//*
//* Parameters: tc           = tested peripheral base address
//*             test_mode    = tested peripheral config (Parity mode)
//*---------------------------------------------------------------------------*/
extern void run_tc_htol(Tc *tc, uint32_t test_mode)
{
 uint32_t channel;
  
  Valid_DebugTrace( "* HTOL TC TEST *\n\r");

  // ----- Disable TC write protect
  tc->TC_WPMR = TC_WPMR_WPKEY(TC_KEY_VAL);
  //tc_set_writeprotect(tc, 0);

  // ----- TC disable all channels & interrupts
  for(channel=0;channel<TCCHANNEL_NUMBER;++channel){
       tc_disable_interrupt(tc,channel,TC_IT_SOURCES_EN);
       tc_enable(tc,channel); // clock enable
       }
  tc_disable_qdec_interrupt(tc,TCQ_IT_SOURCES_EN);

  // ----- TC init (same conf for all channels)
  init_tc_htol(tc,test_mode);

  // ----- TC test (enable all channels)
  for(channel=0;channel<TCCHANNEL_NUMBER;++channel){
       tc_enable(tc,channel); // clock enable
       }

  // ----- Enable TC write protect
  tc->TC_WPMR = TC_WPMR_WPKEY(TC_KEY_VAL) | TC_WPMR_WPEN;
  //tc_set_writeprotect(tc, 1);

  return;
}



/*----------------------------------------------------------------------------*/
//* Function Name : init_tc_htol
//* Object       : run TC test for HTOL
//*---------------------------------------------------------------------------*/
void init_tc_htol(Tc *tc, uint32_t test_mode)
{
 uint32_t channel,tc_next_mode,bmr_next_mode,tc_it_sources;
 uint8_t  mode,wave,clki;
 
  mode = test_mode % HTOL_TC_NB_TEST_MODE;
  wave = test_mode & 0x01; //0101010101...
  clki = test_mode & 0x02; //0011001100...
  switch (mode){
                case 0: // not functional (reg access)
                  tc_next_mode = (wave ?TC_MODE0_W :TC_MODE0_C);
                  bmr_next_mode = TC_BLOCK_MODE0;
                  break;
                case 1:
                  tc_next_mode = (wave ?TC_MODE1_W :TC_MODE1_C);
                  bmr_next_mode = TC_BLOCK_MODE1;
                  break;
                case 2:
                  tc_next_mode = (wave ?TC_MODE2_W :TC_MODE2_C);
                  bmr_next_mode = TC_BLOCK_MODE2;
                  break;
                case 3:
                  tc_next_mode = (wave ?TC_MODE3_W :TC_MODE3_C);
                  bmr_next_mode = TC_BLOCK_MODE3;
                  break;
                case 4:
                  tc_next_mode = (wave ?TC_MODE4_W :TC_MODE4_C);
                  bmr_next_mode = TC_BLOCK_MODE4;
                  break;
                case 5:
                  tc_next_mode = (wave ?TC_MODE5_W :TC_MODE5_C);
                  bmr_next_mode = TC_BLOCK_MODE5;
                  break;
  default: break;}
 
  // enable ALL TC interrupt (core level)
  nvic_tc_it_enable();
  
  // ----- TC init - Block level
  //if(mode>TC_DISABLE_IT_LEVEL){tc_enable_qdec_interrupt(tc,TCQ_IT_SOURCES_EN);}
  
  // pseudo random config update - Block level
  reg32_update_fields(&bmr_next_mode,TC_BMR_FIELDS);
  tc->TC_BMR = bmr_next_mode;
  
  // ----- TC init - Channel level
  tc_it_sources = TC_IT_SOURCES_EN;
  for(channel=0;channel<TCCHANNEL_NUMBER;++channel){
       if (wave){ // pseudo random config update
         reg32_update_fields(&tc_next_mode,TC_CMR_WAVE_FIELDS);
         }
       else{ // pseudo random config update
         reg32_update_fields(&tc_next_mode,TC_CMR_CAPT_FIELDS);
         }
       if(clki) {tc_next_mode|=TC_CMR_CLKI;} // invert clock
       tc_init(tc,channel,tc_next_mode); // clock disable & mode setting
       
       // Stepper Motor Mode register
       tc_init_2bit_gray(tc,channel,tc_next_mode&(TC_SMMR_GCEN|TC_SMMR_DOWN));
 
       // it enable (for low frequency values only)
       if(mode>TC_DISABLE_IT_LEVEL){tc_enable_interrupt(tc,channel,tc_it_sources);}
       }
  return;
}


/*----------------------------------------------------------------------------*/
//* Function Name : nvic_tc_it_enable
//* Object        : enable ALL TC interrupt (core level)
//*---------------------------------------------------------------------------*/
void nvic_tc_it_enable()
{
#ifdef ID_TC0
  nvic_enable_it(ID_TC0);
#endif
#ifdef ID_TC1
  nvic_enable_it(ID_TC1);
#endif
#ifdef ID_TC2
  nvic_enable_it(ID_TC2);
#endif
#ifdef ID_TC3
   nvic_enable_it(ID_TC3);
#endif
#ifdef ID_TC4
   nvic_enable_it(ID_TC4);
#endif
#ifdef ID_TC5
   nvic_enable_it(ID_TC5);
#endif
}



/**
 * \brief Get current config on the selected channel.
 *
 * \param tc Pointer to an Tc instance.
 * \param ul_channel Channel
 *
 * \return The current TC channel mode
 */
uint32_t tc_get_mode(Tc * p_tc, uint32_t ul_channel)
{
	TcChannel *tc_channel;
	tc_channel = p_tc->TC_CHANNEL + ul_channel;
	return tc_channel->TC_CMR;
}