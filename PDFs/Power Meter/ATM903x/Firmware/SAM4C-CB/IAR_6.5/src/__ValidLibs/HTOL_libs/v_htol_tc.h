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
 * File Name           : v_htol_tc.h
 * Object              :
 * Creation            : ERr   Sep/2011
 *----------------------------------------------------------------------------
*/
#ifndef _V_HTOL_TC_H
#define _V_HTOL_TC_H


#include "project.h"

// ---- General purpose include files
#include "device.h"
#include "board.h"
#include "htol.h"


// ---- Peripherals (ASF drivers)
#include "drivers/tc/tc.h"


// ---- Validation libraries
#include "v_drivers/v_nvic.h"
#include "HTOL_libs/v_htol_utils.h"


// ----------------------------------------------------------------------------
// ----------- TC HTOL test settings
// ----------------------------------------------------------------------------
// TC test modes (TC block base config)
#define TC_BLOCK_MODE0 0x03FBFF3F // Not functional (reg access)
//#define TC_BLOCK_MODE1 (TC_BMR_QDEN | TC_BMR_FILTER) // FILTER & QDEN enable
//#define TC_BLOCK_MODE0 (0)
#define TC_BLOCK_MODE1 (TC_BMR_FILTER)
#define TC_BLOCK_MODE2 (TC_BMR_FILTER)
#define TC_BLOCK_MODE3 (TC_BMR_FILTER)
#define TC_BLOCK_MODE4 (TC_BMR_FILTER)
#define TC_BLOCK_MODE5 (TC_BMR_FILTER)

#define HTOL_TC_NB_TEST_MODE 6
#define TC_DISABLE_IT_LEVEL  0 // disable TC interrupt for higher frequencies

// Capture test modes (channel base config)
#define TC_MODE0_C 0x000F47FF // Not functional (reg access)
#define TC_MODE1_C 0x00000000 // TCLK1
#define TC_MODE2_C 0x00000001 // TCLK2
#define TC_MODE3_C 0x00000002 // TCLK3
#define TC_MODE4_C 0x00000003 // TCLK4
#define TC_MODE5_C 0x00000004 // TCLK5

// Wave test modes (channel base config)
#define TC_MODE0_W 0xFFFFFFFF // Not functional
#define TC_MODE1_W 0x00000000 // TCLK1
#define TC_MODE2_W 0x00000001 // TCLK2
#define TC_MODE3_W 0x00000002 // TCLK3
#define TC_MODE4_W 0x00000003 // TCLK4
#define TC_MODE5_W 0x00000004 // TCLK5


// BMR Fields to update
#define TC_BMR_FIELDS ( TC_BMR_TC0XC0S_Msk | TC_BMR_TC1XC1S_Msk \
                      | TC_BMR_TC2XC2S_Msk | TC_BMR_MAXFILT_Msk \
                                        | TC_BMR_POSEN       \
                      | TC_BMR_SPEEDEN     | TC_BMR_EDGPHA      \
                      | TC_BMR_INVA        | TC_BMR_INVB        \
                      | TC_BMR_INVIDX      | TC_BMR_SWAP        \
                      | TC_BMR_IDXPHB )

// CMR Fields to update - Capture mode
#define TC_CMR_CAPT_FIELDS   ( TC_CMR_ETRGEDG_Msk | TC_CMR_ABETRG   \
                             | TC_CMR_CPCTRG      | TC_CMR_LDRA_Msk \
                             | TC_CMR_LDRB_Msk )

// CMR Fields to update - Wave mode
#define TC_CMR_WAVE_FIELDS   ( TC_CMR_EEVTEDG_Msk | TC_CMR_ENETRG    \
                             | TC_CMR_WAVSEL_Msk  | TC_CMR_ACPA_Msk  \
                             | TC_CMR_ACPC_Msk    | TC_CMR_AEEVT_Msk \
                             | TC_CMR_ASWTRG_Msk  | TC_CMR_BCPB_Msk  \
                             | TC_CMR_BCPC_Msk    | TC_CMR_BEEVT_Msk \
                             | TC_CMR_BSWTRG_Msk )

// Enable all possible IT sources
#define TC_IT_SOURCES_EN ( TC_IER_COVFS | TC_IER_LOVRS | TC_IER_CPAS  \
                         | TC_IER_CPBS  | TC_IER_CPCS  | TC_IER_LDRAS \
                         | TC_IER_LDRBS | TC_IER_ETRGS )
#define TCQ_IT_SOURCES_EN ( TC_QIER_IDX | TC_QIER_DIRCHG | TC_QIER_QERR )
// ----------------------------------------------------------------------------



/*------------------*/
/* Prototypes       */
/*------------------*/
extern void run_tc_htol(Tc *tc, uint32_t test_mode);
void init_tc_htol(Tc *tc, uint32_t test_mode);
void nvic_tc_it_enable();
uint32_t tc_get_mode(Tc * p_tc, uint32_t ul_channel);


#endif//_V_HTOL_TC_H


