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
 * File Name           : v_humi_main_functions.h
 * Object              :
 * Creation            : ERr   Sep/2011
 *----------------------------------------------------------------------------
*/
#ifndef _V_HUMI_MAIN_FUNCTIONS_H
#define _V_HUMI_MAIN_FUNCTIONS_H


#include "project.h"


// ---- General purpose include files
#include "device.h"
#include "board.h"
#include "humidity.h"


// ---- Peripherals (ASF drivers)
#include "drivers/pio/pio.h"
#include "drivers/pmc/pmc.h"


// ---- Validation libraries
#include "v_htol_main_functions.h"
#include "v_drivers/v_wdt.h"


//------------------------------------------------------------------------------
// Prototypes                                                                 
//------------------------------------------------------------------------------
extern void run_humi_test(void);
void hum_conf_all_pio(void);
void enable_all_pio_clk(void);
void set_output_all_pio(void);


//------------------------------------------------------------------------------
// Macros                                                                     
//------------------------------------------------------------------------------
#ifdef PIOA
  #include "Humidity/_hum_PIOA_const.h"
#endif //PIOA
#ifdef PIOB
  #include "Humidity/_hum_PIOB_const.h"
#endif //PIOB
#ifdef PIOC
  #include "Humidity/_hum_PIOC_const.h"
#endif //PIOC
#ifdef PIOD
  #include "Humidity/_hum_PIOD_const.h"
#endif //PIOD
#ifdef PIOE
  #include "Humidity/_hum_PIOE_const.h"
#endif //PIOE


#endif//_V_HUMI_MAIN_FUNCTIONS_H
