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
 * File Name           : v_htol_main_functions.h
 * Object              :
 * Creation            : ERr   Sep/2011
 *----------------------------------------------------------------------------
*/
#ifndef _V_HTOL_MAIN_FUNCTIONS_H
#define _V_HTOL_MAIN_FUNCTIONS_H


#include "project.h"


// ---- General purpose include files
#include "device.h"
#include "board.h"
#include "htol.h"


// ---- Peripherals (ASF drivers)
#include "drivers/pmc/pmc.h"
#include "drivers/uart/uart.h"


// ---- Validation libraries
#include "v_drivers/v_pmc.h"
#include "v_utils.h"
#include "HTOL_libs/v_htol_utils.h"
#include "HTOL_libs/v_htol_it_routines.h"
#include "HTOL_libs/v_htol_acc.h"
#include "HTOL_libs/v_htol_adc.h"
#include "HTOL_libs/v_htol_crccu.h"
#include "HTOL_libs/v_htol_dacc.h"
#include "HTOL_libs/v_htol_pio.h"
#include "HTOL_libs/v_htol_pwm.h"
#include "HTOL_libs/v_htol_rtc.h"
#include "HTOL_libs/v_htol_rtt.h"
#include "HTOL_libs/v_htol_spi.h"
#include "HTOL_libs/v_htol_ssc.h"
#include "HTOL_libs/v_htol_tc.h"
#include "HTOL_libs/v_htol_twi.h"
#include "HTOL_libs/v_htol_uart.h"
#include "HTOL_libs/v_htol_usart.h"
#include "HTOL_libs/v_htol_misc.h"

// every peripheral test will loop NB_LOOPTEST times before next iteration
//#define NB_LOOPTEST 1

// Number of transmitted characters for each test iteration of serial periph
#define NB_CHAR_TRANSFER (ISRAM_TEST_SECTION_SIZE/2)


/*------------------*/
/* Prototypes       */
/*------------------*/
extern void run_htol_test(unsigned int MCK_clock_speed);
//void htol_enable_periph_clocks(void);
void sram_test_section_fill(uint32_t pattern);
void htol_next_iter();
void htol_por_init();



#endif//_V_HTOL_MAIN_FUNCTIONS_H
