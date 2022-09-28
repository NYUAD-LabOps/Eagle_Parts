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
 * File Name           : v_htol_main_functions.c
 *----------------------------------------------------------------------------
*/

#include "v_htol_main_functions.h"
#include "htol_test_list_check.h"


// global variables
uint32_t htol_iter, htol_test_periph_mode;
uint32_t MCK_Freq;
volatile uint32_t periph_read_reg;
extern volatile unsigned int it_count[NB_PERIPH_ID]; // v_htol_it_routines.c


/*----------------------------------------------------------------------------*/
//* Function Name : run_htol_test
//* Object       : run the complete HTOL test list (infinite loop)
//*---------------------------------------------------------------------------*/
extern void run_htol_test(unsigned int  MCK_clock_speed)
{
  MCK_Freq = MCK_clock_speed;
  v_pmc_enable_all_periph_clk(); //htol_enable_periph_clocks();
  
  // Enable two counters in TC0 timer counter
  REG_TC0_CCR0=(TC_CCR_CLKEN | TC_CCR_SWTRG);
  REG_TC0_CCR1=(TC_CCR_CLKEN | TC_CCR_SWTRG);
  
  if (check_reset_source()==POR_RESET){htol_por_init();} // reset counters

  sram_test_section_fill(0xCAFEDEDE);

  // Watchdog Initialization
  if(HTOL_ENABLE_WDT)watchdog_enable(HTOL_WDT_TIME);
  else wdt_disable(WDT);
   
//______________________________________________________________________________  
  while (1){                                              // HTOL test main loop

#if(TST_MISC==1)
    run_misc_htol();
#endif

#if(TST_ACC==1)
    run_acc_htol(ACC,htol_test_periph_mode);
#endif

#if(TST_ADC==1)
    run_adc_htol(ADC,htol_test_periph_mode);
#endif

#if(TST_CRCCU==1)
    run_crccu_htol(CRCCU,htol_test_periph_mode);
#endif

#if(TST_DACC==1)
    run_dacc_htol(DACC,htol_test_periph_mode);
#endif
    
#if (TST_PIOA==1)
  run_pio_htol(PIOA,htol_test_periph_mode);
#endif
#if (TST_PIOB==1)
  run_pio_htol(PIOB,htol_test_periph_mode);
#endif
#if (TST_PIOC==1)
  run_pio_htol(PIOC,htol_test_periph_mode); 
#endif
#if (TST_PIOD==1)
  run_pio_htol(PIOD,htol_test_periph_mode);
#endif
#if (TST_PIOE==1)
  run_pio_htol(PIOE,htol_test_periph_mode);
#endif

#if(TST_PWM==1)
    run_pwm_htol(PWM,htol_test_periph_mode);
#endif

#if(TST_RTC==1)
    run_rtc_htol(RTC,htol_test_periph_mode);
#endif

#if(TST_RTT==1)
    run_rtt_htol(RTT,htol_test_periph_mode);
#endif

#if(TST_SPI==1) // single SPI controller
    run_spi_htol(SPI,htol_test_periph_mode,NB_CHAR_TRANSFER);
#endif
#if(TST_SPI0==1)
    run_spi_htol(SPI0,htol_test_periph_mode,NB_CHAR_TRANSFER);
#endif
#if(TST_SPI1==1)
    run_spi_htol(SPI1,htol_test_periph_mode,NB_CHAR_TRANSFER);
#endif

#if(TST_SSC==1) // single SSC controller
    run_ssc_htol(SSC,htol_test_periph_mode);
#endif
#if(TST_SSC0==1)
    run_ssc_htol(SSC0,htol_test_periph_mode);
#endif
#if(TST_SSC1==1)
    run_ssc_htol(SSC1,htol_test_periph_mode);
#endif

#if(TST_UART0==1)
    run_uart_htol(UART0,htol_test_periph_mode,NB_CHAR_TRANSFER);
#endif
#if(TST_UART1==1)
    run_uart_htol(UART1,htol_test_periph_mode,NB_CHAR_TRANSFER);
#endif
#if(TST_USART0==1)
    run_usart_htol(USART0,htol_test_periph_mode,NB_CHAR_TRANSFER);
#endif
#if(TST_USART1==1)
    run_usart_htol(USART1,htol_test_periph_mode,NB_CHAR_TRANSFER);
#endif

#if(TST_TC_0_1_2==1)
    run_tc_htol(TC0,htol_test_periph_mode);
#endif
#if(TST_TC_3_4_5==1)
    run_tc_htol(TC1,htol_test_periph_mode);
#endif

#if(TST_TWI0==1)
    run_twi_htol(TWI0,htol_test_periph_mode,NB_CHAR_TRANSFER);
#endif
#if(TST_TWI1==1)
    run_twi_htol(TWI1,htol_test_periph_mode,NB_CHAR_TRANSFER);
#endif

    //...
    htol_next_iter();
  }//___________________________________________________________________________  
//                                                    // eof HTOL test main loop


}
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/



/*----------------------------------------------------------------------------*/
//* Function Name: htol_enable_periph_clocks
//* Object: enable all peripheral clocks (even if periph test is disabled)
//*---------------------------------------------------------------------------*/
/*
void htol_enable_periph_clocks(void)
{
  v_pmc_enable_all_periph_clk();

#ifdef UART0
  pmc_enable_periph_clk(ID_UART0);
#endif
#ifdef UART1
  pmc_enable_periph_clk(ID_UART1);
#endif
#ifdef USART0
  pmc_enable_periph_clk(ID_USART0);
#endif
#ifdef USART1
  pmc_enable_periph_clk(ID_USART1);
#endif
#ifdef PIOA
  pmc_enable_periph_clk(ID_PIOA);
#endif
#ifdef PIOB
  pmc_enable_periph_clk(ID_PIOB);
#endif
#ifdef PIOC
  pmc_enable_periph_clk(ID_PIOC);
#endif
#ifdef PIOD
  pmc_enable_periph_clk(ID_PIOD);
#endif
#ifdef PIOE
  pmc_enable_periph_clk(ID_PIOE);
#endif
}
*/


/*----------------------------------------------------------------------------*/
//* Function Name : sram_test_section_fill
//* Object       : fill SRAM test buffer with defined 32bits pattern
//*                (SRAM buffer size and address defined in htol.h
//*---------------------------------------------------------------------------*/
void sram_test_section_fill(uint32_t pattern)
{
 uint32_t *i;
 
  //end = (uint32_t*)ISRAM_TEST_SECTION_START+(ISRAM_TEST_SECTION_SIZE>>2);
  for(i=(uint32_t*)ISRAM_TEST_SECTION_START;i<(uint32_t*)ISRAM_TEST_SECTION_END;*i++=pattern);
}



/*----------------------------------------------------------------------------*/
//* Function Name : htol_next_iter
//* Object       : update counters for HTOL test next iteration
//*---------------------------------------------------------------------------*/
void htol_next_iter()
{
  ++htol_iter;
  ++htol_test_periph_mode;
  TOOGLE_PASS_LED;
}



/*----------------------------------------------------------------------------*/
//* Function Name : htol_por_init
//* Object       : init counters for HTOL test first iteration (on POR only)
//*---------------------------------------------------------------------------*/
void htol_por_init()
{
 uint32_t i;
   
   for(i=0;i<NB_PERIPH_ID;++i){it_count[i]=0;}
   htol_iter=0;
   init_errlog_tab();
}
