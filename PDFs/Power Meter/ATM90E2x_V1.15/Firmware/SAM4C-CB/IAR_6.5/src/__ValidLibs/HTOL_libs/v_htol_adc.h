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
 * File Name           : v_htol_adc.h
 * Object              :
 * Creation            : ERr   Sep/2011
 *----------------------------------------------------------------------------
*/
#ifndef _V_HTOL_ADC_H
#define _V_HTOL_ADC_H


#include "project.h"

// ---- General purpose include files
#include "device.h"
#include "board.h"
#include "htol.h"


// ---- Peripherals (ASF drivers)


// ---- Validation libraries
#include "v_utils.h"
#include "v_drivers/v_nvic.h"
#include "v_drivers/v_adc.h"
#include "HTOL_libs/v_htol_utils.h"



// ----------------------------------------------------------------------------
// ----------- Peripheral HTOL test settings
// ----------------------------------------------------------------------------

#define HTOL_ADC_NB_TEST_MODE 1

// Test modes
#define ADC_MODE0 0x00000000 // Not functional (reg access)
//#define ADC_MODE1 0x00000000 //


// Configuration fields to updtate
#define ADC_CONFIG_FIELDS 0x00000000

// Enable all possible IT sources
#define ADC_IT_SOURCES_EN 0xFFFFFFFF

// ----------------------------------------------------------------------------



/*------------------*/
/* Prototypes       */
/*------------------*/
extern void run_adc_htol(Adc *adc, uint32_t test_mode);
uint32_t init_adc_htol(Adc *adc, uint32_t test_mode);
void adc_reg_access(Adc *adc);
void nvic_adc_it_enable();

// ----------------------------------------------------------------------------
// ----------- Channel number definition (hard coded in SOC header)
// ----------------------------------------------------------------------------
//---- SAM3S ------------------------------------------------------------------
#if (SAM3S==1)
  #if (_DEVICE_PIN_COUNT_==48)
    #define ADC_CHANNEL_NUMBER 9
  #elif (_DEVICE_PIN_COUNT_==64)
    #define ADC_CHANNEL_NUMBER 11
  #elif (_DEVICE_PIN_COUNT_==100)
    #define ADC_CHANNEL_NUMBER 16
  #else
    #error Unknown package definition (bad pincount value)
  #endif
//---- SAM4S -------------------------------------------------------------------
#elif (SAM4S==1)
  #if (_DEVICE_PIN_COUNT_==48)
    #define ADC_CHANNEL_NUMBER 9
  #elif (_DEVICE_PIN_COUNT_==64)
    #define ADC_CHANNEL_NUMBER 11
  #elif (_DEVICE_PIN_COUNT_==100)
    #define ADC_CHANNEL_NUMBER 16
  #else
    #error Unknown package definition (bad pincount value)
  #endif
//---- Not implemented ---------------------------------------------------------
#else
  #error Library does not support the specified device.
#endif
//------------------------------------------------------------------------------
#endif //_V_HTOL_ADC_H


