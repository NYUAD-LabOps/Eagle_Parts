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
 * File Name           : v_humi_main_functions.c
 *----------------------------------------------------------------------------
*/

#include "v_humi_main_functions.h"


// global variables



/*----------------------------------------------------------------------------*/
//* Function Name : run_humi_test
//* Object       : run the Humidity Test
//*---------------------------------------------------------------------------*/
extern void run_humi_test(void)
{
  Valid_DebugTrace( "\n\r => Setting PIO pattern and entering sleep mode... \n\r");

  // Enable clocks and set outputs
  wait_time(100);
  enable_all_pio_clk();
  set_output_all_pio();

  
  // Watchdog Initialization
  if(HUM_ENABLE_WDT)watchdog_enable(HUM_WDT_TIME);
  else wdt_disable(WDT);

  // Enter deep sleep mode
  led_toogle(2000,2); // 2s / 2 Hz
  TOOGLE_PASS_LED;
  hum_conf_all_pio(); //configure all PIOs
  __WFI();            // Entering sleep mode: wake-up on WDT
  
  // Toogle LED in case of IT wake-up  
  TOOGLE_PASS_LED;
  
  //sos_loop(INFINITE_LOOP);
}
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
//* Function Name : hum_conf_all_pio
//* Object        : configures pio outputs with alternate 0101 pattern
// *                (package & device dependant)
//*---------------------------------------------------------------------------*/
void hum_conf_all_pio(void)
{
#ifdef PIOA
  pio_set(PIOA,HUM_PIOA_SET_MASK);
  pio_clear(PIOA,HUM_PIOA_CLEAR_MASK);
#endif //PIOA
#ifdef PIOB
  pio_set(PIOB,HUM_PIOB_SET_MASK);
  pio_clear(PIOB,HUM_PIOB_CLEAR_MASK);
#endif //PIOB
#ifdef PIOC
  pio_set(PIOC,HUM_PIOC_SET_MASK);
  pio_clear(PIOC,HUM_PIOC_CLEAR_MASK);
#endif //PIOC
#ifdef PIOD
  pio_set(PIOD,HUM_PIOD_SET_MASK);
  pio_clear(PIOD,HUM_PIOD_CLEAR_MASK);
#endif //PIOA
#ifdef PIOE
  pio_set(PIOE,HUM_PIOE_SET_MASK);
  pio_clear(PIOE,HUM_PIOE_CLEAR_MASK);
#endif //PIOE
}
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
//* Function Name : enable_all_pio_clk
//* Object        : enable peripheral clocks for PIO controllers
//*---------------------------------------------------------------------------*/
void enable_all_pio_clk(void)
{
#ifdef PIOA
  pmc_enable_periph_clk(ID_PIOA);
#endif //PIOA
#ifdef PIOB
  pmc_enable_periph_clk(ID_PIOB);
#endif //PIOB
#ifdef PIOC
  pmc_enable_periph_clk(ID_PIOC);
#endif //PIOC
#ifdef PIOD
  pmc_enable_periph_clk(ID_PIOD);
#endif //PIOD
#ifdef PIOE
  pmc_enable_periph_clk(ID_PIOE);
#endif //PIOE
}
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
//* Function Name : set_output_all_pio
//* Object        : sets all pios as outputs
//*---------------------------------------------------------------------------*/
void set_output_all_pio(void)
{
#ifdef PIOA
  pio_set_output(PIOA,0xFFFFFFFF,HUM_PIO_DEFAULT_VAL,HUM_PIO_MULTIDRV,HUM_PIO_PULLUP);
#endif //PIOA
#ifdef PIOB
  pio_set_output(PIOB,0xFFFFFFFF,HUM_PIO_DEFAULT_VAL,HUM_PIO_MULTIDRV,HUM_PIO_PULLUP);
#endif //PIOB
#ifdef PIOC
  pio_set_output(PIOC,0xFFFFFFFF,HUM_PIO_DEFAULT_VAL,HUM_PIO_MULTIDRV,HUM_PIO_PULLUP);
#endif //PIOC
#ifdef PIOD
  pio_set_output(PIOD,0xFFFFFFFF,HUM_PIO_DEFAULT_VAL,HUM_PIO_MULTIDRV,HUM_PIO_PULLUP);
#endif //PIOD
#ifdef PIOE
  pio_set_output(PIOE,0xFFFFFFFF,HUM_PIO_DEFAULT_VAL,HUM_PIO_MULTIDRV,HUM_PIO_PULLUP);
#endif //PIOE
}
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/

