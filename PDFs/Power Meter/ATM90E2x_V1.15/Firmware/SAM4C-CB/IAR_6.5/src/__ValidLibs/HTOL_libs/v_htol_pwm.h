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
 * File Name           : v_htol_pwm.h
 * Object              :
 * Creation            : ERr   Sep/2011
 *----------------------------------------------------------------------------
*/
#ifndef _V_HTOL_PWM_H
#define _V_HTOL_PWM_H


#include "project.h"

// ---- General purpose include files
#include "device.h"
#include "board.h"
#include "htol.h"


// ---- Peripherals (ASF drivers)


// ---- Validation libraries
#include "v_utils.h"
#include "v_drivers/v_nvic.h"
#include "v_drivers/v_pwm.h"
#include "HTOL_libs/v_htol_utils.h"



// ----------------------------------------------------------------------------
// ----------- IP relative definitions
// ----------------------------------------------------------------------------
#define PWM_ALL_REG_GROUPS ( PWM_WPCR_WPRG0 | PWM_WPCR_WPRG1 | PWM_WPCR_WPRG2 \
                           | PWM_WPCR_WPRG3 | PWM_WPCR_WPRG4 | PWM_WPCR_WPRG5 )
#define PWM_DIS_ALL_CH ( PWM_DIS_CHID0 | PWM_DIS_CHID1 \
                       | PWM_DIS_CHID2 | PWM_DIS_CHID3 )
// ----------------------------------------------------------------------------



// ----------------------------------------------------------------------------
// ----------- Peripheral HTOL test settings
// ----------------------------------------------------------------------------

#define HTOL_PWM_NB_TEST_MODE 1

// Test modes
#define PWM_MODE0 0x00000000 // Not functional (reg access)
//#define PWM_MODE1 0x00000000 //


// Configuration fields to updtate
#define PWM_CONFIG_FIELDS 0x00000000

// Enable all possible IT sources
#define PWM_IT_SOURCES_EN1 0xFFFFFFFF
#define PWM_IT_SOURCES_EN2 0xFFFFFFFF

// ----------------------------------------------------------------------------



/*------------------*/
/* Prototypes       */
/*------------------*/
extern void run_pwm_htol(Pwm *pwm, uint32_t test_mode);
uint32_t init_pwm_htol(Pwm *pwm, uint32_t test_mode);
void pwm_reg_access(Pwm *pwm);
void nvic_pwm_it_enable();




#endif //_V_HTOL_PWM_H


