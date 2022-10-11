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
 * File Name           : v_htol_rtc.c
 *----------------------------------------------------------------------------
*/

#include "v_htol_rtc.h"



// global variables
//extern uint32_t htol_iter;    // v_htol_main_functions.c definition
//extern unsigned int MCK_Freq; // v_htol_main_functions.c definition
extern volatile uint32_t periph_read_reg; // v_htol_main_functions.c definition
//extern volatile unsigned int it_flag[2]; // v_htol_it_routines.c definition


/*----------------------------------------------------------------------------*/
//* Function Name : run_rtc_htol
//* Object       : run RTC test for HTOL
//*               
//*
//* Parameters: rtc          = tested peripheral base address
//*             test_mode    = tested peripheral config (Parity mode)
//*             test_nb_iter = number of bytes to copy /or INFINITE_LOOP
//*---------------------------------------------------------------------------*/
extern void run_rtc_htol(Rtc *rtc, uint32_t test_mode)
{
 uint8_t  mode;

 
  Valid_DebugTrace( "* HTOL RTC TEST *\n\r");

  // ----- RTC disable all interrupts
  rtc->RTC_IDR = 0xFFFFFFFF;
  
  // ----- RTC init
  mode = init_rtc_htol(rtc,test_mode);

  // ----- RTC test
  switch (mode){
                case 0: // not functional (reg access)
                  rtc_reg_access(rtc);
                  break;
                case 1:
                  break;
  default: break;}


  return;
}



/*----------------------------------------------------------------------------*/
//* Function Name : init_rtc_htol
//* Object       : run RTC test for HTOL
//*---------------------------------------------------------------------------*/
uint32_t init_rtc_htol(Rtc *rtc, uint32_t test_mode)
{
 uint32_t rtc_next_mode;
 uint8_t  mode;
 
  mode = test_mode % HTOL_RTC_NB_TEST_MODE;
  switch (mode){
                case 0: // not functional (reg access)
                  rtc_next_mode = RTC_MODE0;
                  break;
                case 1:
                  //rtc_next_mode = RTC_MODE1;
                  // pseudo random config update
                  //reg32_update_fields(&rtc_next_mode,RTC_CONFIG_FIELDS);
                  break;
  default: break;}

  // Program modes
  rtc->RTC_MR = rtc_next_mode;

  // enable ALL RTC interrupt (core level)
  nvic_rtc_it_enable();
  
  // RTC interrupt enable
  rtc->RTC_IER = RTC_IT_SOURCES_EN;

  return(mode);
}


/*----------------------------------------------------------------------------*/
//* Function Name : rtc_reg_access
//* Object        : read/write peripheral register access
//*---------------------------------------------------------------------------*/
void rtc_reg_access(Rtc *rtc)
{
  rtc->RTC_CR     = ~(rtc->RTC_CR);
  rtc->RTC_MR     = ~(rtc->RTC_MR);
  rtc->RTC_TIMR   = ~(rtc->RTC_TIMR);
  rtc->RTC_CALR   = ~(rtc->RTC_CALR);
  rtc->RTC_TIMALR = ~(rtc->RTC_TIMALR);
  rtc->RTC_CALALR = ~(rtc->RTC_CALALR);
  periph_read_reg = ~(rtc->RTC_SR);  //RO
  rtc->RTC_SCCR   = ~(rtc->RTC_SCCR);
  rtc->RTC_IER    = ~(rtc->RTC_IER);
  rtc->RTC_IDR    = ~(rtc->RTC_IDR);
  periph_read_reg = ~(rtc->RTC_IMR); //RO
  periph_read_reg = ~(rtc->RTC_VER); //RO
}


/*----------------------------------------------------------------------------*/
//* Function Name : nvic_rtc_it_enable
//* Object        : enable ALL RTC interrupt (core level)
//*---------------------------------------------------------------------------*/
void nvic_rtc_it_enable()
{
#ifdef ID_RTC
  nvic_enable_it(ID_RTC);
#endif
}

