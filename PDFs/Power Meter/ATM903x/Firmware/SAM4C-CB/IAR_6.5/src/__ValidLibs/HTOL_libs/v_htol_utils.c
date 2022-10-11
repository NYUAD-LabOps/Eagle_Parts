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
 * File Name           : v_htol_utils.c
 *----------------------------------------------------------------------------
*/

#include "v_htol_utils.h"


// global variables
extern unsigned int  MCK_clock_speed; // main.c
extern uint32_t htol_iter;    // v_htol_main_functions.c definition
//extern unsigned int MCK_Freq; // v_htol_main_functions.c definition
extern volatile unsigned int it_flag[2]; // v_htol_it_routines.c definition


// -----------------------------------------------------------------------------
#pragma data_alignment=0x10
uint32_t errlog_tab[NB_ERROR_TYPE][4];
// -----------------------------------------------------------------------------


extern void isram_log_error(uint32_t error_code, uint32_t periph, uint32_t iter)
{
  errlog_tab[error_code][1] = periph;
  errlog_tab[error_code][2] +=1;
  errlog_tab[error_code][3] = iter;
}


extern void flash_log_error(uint32_t error_code, uint32_t periph, uint32_t iter)
{ // not implemented
  return;
}


extern void init_errlog_tab()
{
 uint32_t i;
  
 for(i=0;i<NB_ERROR_TYPE;++i){
   errlog_tab[i][0] = ERROR_CODE_PATTERN + i;
   errlog_tab[i][1] = 0xFFFFFFFF;
   errlog_tab[i][2] = 0000000000;
   errlog_tab[i][3] = 0xFFFFFFFF;
   }
}


extern void led_toogle_1Hz(uint32_t time)
{
 uint32_t i,count;

  count = time / 500;  
  for(i=count;i;){
    TOOGLE_PASS_LED;
    wait_time(500);
    if(time!=INFINITE_LOOP)i--;
    }
}


extern void led_toogle(uint32_t time, uint32_t freq)
{
 uint32_t i,count,wait_ms;

  wait_ms = (500/freq);
  count = time / wait_ms;
  for(i=count;i;){
    TOOGLE_PASS_LED;
    wait_time(wait_ms);
    if(time!=INFINITE_LOOP)i--;
    }
}


extern void sos_loop(uint32_t time)
{
 uint32_t i,j,count;

  count = time / 15000;  
  for(i=0;i<=count;){
    for(j=0;j<6;++j){TOOGLE_PASS_LED;wait_time(500);}  //S 
    for(j=0;j<6;++j){TOOGLE_PASS_LED;wait_time(1000);} //0
    for(j=0;j<6;++j){TOOGLE_PASS_LED;wait_time(500);}  //S
    TURN_OFF_PASS_LED;
    wait_time(3000); // 3s off
    if(time!=INFINITE_LOOP)++i;
    }
}


extern void reg32_update_fields(uint32_t *reg_addr, uint32_t fields_mask)
{
 uint32_t prand_val;
 
  // pseudo random value
  prand_val = (htol_iter*it_flag[1]) ^ ((REG_TC0_CV0<<16)|REG_TC0_CV1);
  (*reg_addr)&=(~fields_mask);
  (*reg_addr)|=(prand_val & fields_mask);
}


extern void reg8_update_fields(uint8_t *reg_addr, uint8_t fields_mask)
{
 uint8_t prand_val;

  // pseudo random value
  prand_val = (uint8_t)((htol_iter*it_flag[1])^(REG_TC0_CV0));
  (*reg_addr)&=(~fields_mask);
  (*reg_addr)|=(prand_val & fields_mask);
}