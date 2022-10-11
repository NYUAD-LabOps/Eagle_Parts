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
 * File Name           : v_htol_dacc.h
 * Object              :
 * Creation            : ERr   Sep/2011
 *----------------------------------------------------------------------------
*/
#ifndef _V_HTOL_DACC_H
#define _V_HTOL_DACC_H


#include "project.h"

// ---- General purpose include files
#include "device.h"
#include "board.h"
#include "htol.h"


// ---- Peripherals (ASF drivers)


// ---- Validation libraries
#include "v_utils.h"
#include "v_drivers/v_nvic.h"
#include "v_drivers/v_dacc.h"
#include "HTOL_libs/v_htol_utils.h"


// ----------------------------------------------------------------------------
// ----------- Peripheral HTOL test settings
// ----------------------------------------------------------------------------

#define HTOL_DACC_NB_TEST_MODE 1

// Test modes
#define DACC_MODE0 0x00000000 // Not functional (reg access)
//#define DACC_MODE1 0x00000000 //


// Configuration fields to updtate
#define DACC_CONFIG_FIELDS 0x00000000

// Enable all possible IT sources
#define DACC_IT_SOURCES_EN 0xFFFFFFFF

// ----------------------------------------------------------------------------



/*------------------*/
/* Prototypes       */
/*------------------*/
extern void run_dacc_htol(Dacc *dacc, uint32_t test_mode);
uint32_t init_dacc_htol(Dacc *dacc, uint32_t test_mode);
void dacc_reg_access(Dacc *dacc);
void nvic_dacc_it_enable();




#endif //_V_HTOL_DACC_H


