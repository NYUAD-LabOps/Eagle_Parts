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
 * File Name           : v_htol_twi.h
 * Object              :
 * Creation            : ERr   Sep/2011
 *----------------------------------------------------------------------------
*/
#ifndef _V_HTOL_TWI_H
#define _V_HTOL_TWI_H


#include "project.h"

// ---- General purpose include files
#include "device.h"
#include "board.h"
#include "htol.h"


// ---- Peripherals (ASF drivers)
//#include "drivers/twi/twi.h"


// ---- Validation libraries
#include "v_drivers/v_twi.h"
#include "v_drivers/v_nvic.h"
#include "HTOL_libs/v_htol_utils.h"


// ----------------------------------------------------------------------------
// ----------- TWI HTOL test settings
// ----------------------------------------------------------------------------
#define HTOL_TWI_NB_TEST_MODE 4

#define TWI_MAX_FREQ 400000 // 400Kbits/s

#define TWI_REG_ACCESS_MASK 0xFFFFFFFF // Not functional (reg access)

// Test modes
#define TWI_MST_MODE_R (TWI_MMR_IADRSZ_3_BYTE | TWI_MMR_MREAD)
#define TWI_MST_MODE_W (TWI_MMR_IADRSZ_3_BYTE)
#define TWI_SLV_MODE   0x00000000

// Configuration fields to updtate
#define TWI_MST_MODE_FIELDS (TWI_MMR_DADR_Msk)
#define TWI_SLV_MODE_FIELDS (TWI_SMR_SADR_Msk)

// Enable all possible IT sources
#define TWI_IT_SOURCES_EN 0x0000FF77
// ----------------------------------------------------------------------------



/*------------------*/
/* Prototypes       */
/*------------------*/
extern void run_twi_htol(Twi *twi, uint32_t test_mode, uint32_t test_nb_iter);
uint8_t init_twi_htol(Twi *twi, uint32_t test_mode);
void twi_reg_access(Twi *twi);
void nvic_twi_it_enable();




#endif //_V_HTOL_TWI_H


