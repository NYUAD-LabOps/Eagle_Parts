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
 * File Name           : v_htol_crccu.h
 * Object              :
 * Creation            : ERr   Sep/2011
 *----------------------------------------------------------------------------
*/
#ifndef _V_HTOL_CRCCU_H
#define _V_HTOL_CRCCU_H


#include "project.h"

// ---- General purpose include files
#include "device.h"
#include "board.h"
#include "htol.h"


// ---- Peripherals (ASF drivers)


// ---- Validation libraries
#include "v_utils.h"
#include "v_drivers/v_nvic.h"
#include "v_drivers/v_crccu.h"
#include "HTOL_libs/v_htol_utils.h"


// ----------------------------------------------------------------------------
// ----------- Peripheral HTOL test settings
// ----------------------------------------------------------------------------

#define HTOL_CRCCU_NB_TEST_MODE 1

// Test modes
#define CRCCU_MODE0 0x00000000 // Not functional (reg access)
//#define CRCCU_MODE1 0x00000000 //


// Configuration fields to updtate
#define CRCCU_CONFIG_FIELDS 0x00000000

// Enable all possible IT sources
#define CRCCU_IT_SOURCES_EN 0xFFFFFFFF

// ----------------------------------------------------------------------------



/*------------------*/
/* Prototypes       */
/*------------------*/
extern void run_crccu_htol(Crccu *crccu, uint32_t test_mode);
uint32_t init_crccu_htol(Crccu *crccu, uint32_t test_mode);
void crccu_reg_access(Crccu *crccu);
void nvic_crccu_it_enable();




#endif //_V_HTOL_CRCCU_H


