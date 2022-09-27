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
 * File Name           : v_htol_acc.h
 * Object              :
 * Creation            : ERr   Oct/2011
 *----------------------------------------------------------------------------
*/
#ifndef _V_HTOL_ACC_H
#define _V_HTOL_ACC_H


#include "project.h"

// ---- General purpose include files
#include "device.h"
#include "board.h"
#include "htol.h"


// ---- Peripherals (ASF drivers)
#include "drivers/acc/acc.h"

// ---- Validation libraries
#include "v_drivers/v_nvic.h"
#include "HTOL_libs/v_htol_utils.h"


// ----------------------------------------------------------------------------
// ----------- ACC HTOL test settings
// ----------------------------------------------------------------------------
#define HTOL_ACC_NB_TEST_MODE 2

// Test modes (base config)
#define ACC_MR0 0x00000000 // Not functional (reg access)


#define ACC_MR1  ~ACC_MR_ACEN       // pseudo random config
#define ACC_ACR1  ACC_ACR_ISEL_HISP // high speed option

//#define ACC_MR2 0x00000000 //
//#define ACC_ACR2 ACC_ACR_ISEL_HISP // high speed option



// Configuration fields to updtate
#define ACC_MR1_FIELDS  ( ACC_MR_SELMINUS_Msk | ACC_MR_SELPLUS_Msk \
                        & ~ACC_MR_ACEN        | ACC_MR_EDGETYP_Msk \
                        | ACC_MR_INV          | ACC_MR_SELFS       \
                        | ACC_MR_FE )
#define ACC_ACR1_FIELDS ACC_ACR_HYST_Msk
// ----------------------------------------------------------------------------



/*------------------*/
/* Prototypes       */
/*------------------*/
extern void run_acc_htol(Acc *acc, uint32_t test_mode);
uint32_t init_acc_htol(Acc *acc, uint32_t test_mode);
void acc_reg_access(Acc *acc);
void nvic_acc_it_enable();




#endif //_V_HTOL_ACC_H


