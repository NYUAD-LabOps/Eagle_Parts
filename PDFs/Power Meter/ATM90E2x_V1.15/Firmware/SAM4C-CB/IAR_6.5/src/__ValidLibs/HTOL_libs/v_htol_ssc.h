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
 * File Name           : v_htol_ssc.h
 * Object              :
 * Creation            : ERr   Sep/2011
 *----------------------------------------------------------------------------
*/
#ifndef _V_HTOL_SSC_H
#define _V_HTOL_SSC_H


#include "project.h"

// ---- General purpose include files
#include "device.h"
#include "board.h"
#include "htol.h"


// ---- Peripherals (ASF drivers)


// ---- Validation libraries
#include "v_utils.h"
#include "v_drivers/v_nvic.h"
#include "v_drivers/v_ssc.h"
#include "HTOL_libs/v_htol_utils.h"


// ----------------------------------------------------------------------------
// ----------- Peripheral HTOL test settings
// ----------------------------------------------------------------------------

#define HTOL_SSC_NB_TEST_MODE 1

// Test modes
#define SSC_MODE0 0x00000000 // Not functional (reg access)
//#define SSC_MODE1 0x00000000 //


// Configuration fields to updtate
#define SSC_CONFIG_FIELDS 0x00000000

// Enable all possible IT sources
#define SSC_IT_SOURCES_EN 0xFFFFFFFF

// ----------------------------------------------------------------------------



/*------------------*/
/* Prototypes       */
/*------------------*/
extern void run_ssc_htol(Ssc *ssc, uint32_t test_mode);//, uint32_t test_nb_iter);
uint32_t init_ssc_htol(Ssc *ssc, uint32_t test_mode);
void ssc_reg_access(Ssc *ssc);
void nvic_ssc_it_enable();




#endif //_V_HTOL_SSC_H


