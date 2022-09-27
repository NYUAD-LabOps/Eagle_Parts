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
 * File Name           : v_utils.h
 * Object              :
 * Creation            : ERr   Sep/2011
 *----------------------------------------------------------------------------
*/
#ifndef _V_UTILS_H
#define _V_UTILS_H


#include "project.h"

// ---- General purpose include files
#include "device.h"
#include "board.h"


// ---- Peripherals (ASF drivers)
#include "drivers/pmc/pmc.h"
#include "drivers/pio/pio.h"

// ---- Validation libraries
#include "v_debug.h"
#include "v_drivers/v_wdt.h"
#include "v_drivers/v_pmc.h"
#if DEVICE_HAS_SUPC
  #include "v_drivers/v_supc.h"
#endif
#if DEVICE_HAS_EFC0
  #include "v_drivers/v_efc.h"
#endif
 

/*----------------------------------------------------------------------------*/
/* Reset sources (define values are device dependant)                         */
/*----------------------------------------------------------------------------*/
#define POR_RESET 0x0 // (SAM3S) power up
#define BUP_RESET 0x1 // (SAM3S) return from backup mode
#define WDT_RESET 0x2 // (SAM3S) watchdog fault detect
#define SW_RESET  0x3 // (SAM3S) software reset
#define USR_RESET 0x4 // (SAM3S) user reset (external NRST)

#if (DEVICE_HAS_SUPC == 1)
  #define NB_RST_SOURCE  7
  #define BOD_RESET 0x5 // brownout detect
  #define SM_RESET  0x6 // supply monitor detect
#else
  #define NB_RST_SOURCE  5
#endif
#define RST_LABEL_SIZE 10
/*----------------------------------------------------------------------------*/

// ----------------------------------------------------------------------------
//  Watchdog Timer
// ----------------------------------------------------------------------------
#define WDT_MAX 0
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
//  Clock config
// ----------------------------------------------------------------------------
#define USE_RC_32KHZ  0
#define USE_RC_4MHZ   1
#define USE_RC_8MHZ   2
#define USE_RC_12MHZ  3
#define USE_EXT_CLK   4 // xtal in bypass mode
#define USE_XTAL      5 // xtal (no bypass)

#define USE_SLOW_CLK 0
#define USE_MAIN_CLK 1
#define USE_PLLA     2
#define USE_PLLB     3
// ----------------------------------------------------------------------------

//*---------------------------------------------------------------------------*/
//* Timeout macro
//* Object       : wait until cond is true with timeout=val
//*---------------------------------------------------------------------------*/
#define WAIT_UNTIL(cond, val) for(uint32_t _i__=0;!cond && _i__++<val;)
//*---------------------------------------------------------------------------*/

#define WAIT_LOOP_ITER_CYCLES 9 // number of MCK cycles to execute 1 increment



/*----------------------------------------------------------------------------*/
/* Prototypes                                                                 */
/*----------------------------------------------------------------------------*/
#ifndef SAMA5 //ERr SAMA5
extern void external_reset_enable(void);
extern void external_reset_disable(void);
#endif //ERr SAMA5

extern void watchdog_enable(uint32_t time);
extern uint32_t config_clocks(void);
extern uint32_t set_clocks(uint8_t main_clk_config, uint8_t mck_config, \
             uint8_t plla_mul, uint8_t plla_div, uint8_t pck_prescaler, \
             uint8_t mck_div);
extern uint32_t check_reset_source();
extern void wait_loop(uint32_t count);
extern void wait_time(uint32_t time);
#if DEVICE_HAS_SUPC
extern void brownout_detector_enable();
extern void supply_monitor_enable();
extern void supply_monitor_disable();
#endif
#if DEVICE_HAS_EFC0
extern void display_flash_desc_dbgu(iflash_descriptor_t* fdes);
#endif
/*----------------------------------------------------------------------------*/



/*----------------------------------------------------------------------------*/
/* Inline functions definitions                                               */


/*----------------------------------------------------------------------------*/
//* Function Name : Valid_DebugTrace
//* Object       : debug trace (depend on DEBUG_MODE defined in project.h)
//*---------------------------------------------------------------------------*/
inline void Valid_DebugTrace(char *buffer)
{
#if (DEBUG_MODE==SERIAL_DEBUG)
  DEBUG_Printk(buffer);
#else
  return;
#endif
}


/*----------------------------------------------------------------------------*/
//* Function Name : Valid_DebugPrintReg
//* Object       : print reg value (depend on DEBUG_MODE defined in project.h)
//*---------------------------------------------------------------------------*/
inline void Valid_DebugPrintReg(uint32_t reg_addr32)
{
#if (DEBUG_MODE==SERIAL_DEBUG)
  DEBUG_PrintReg(reg_addr32);
#else
  return;
#endif
}


/*----------------------------------------------------------------------------*/
//* Function Name : Valid_DebugPrintRegX
//* Object       : print reg value (depend on DEBUG_MODE defined in project.h)
//*---------------------------------------------------------------------------*/
inline void Valid_DebugPrintRegX(uint32_t reg_addr32)
{
#if (DEBUG_MODE==SERIAL_DEBUG)
  DEBUG_PrintRegX(reg_addr32);
#else
  return;
#endif
}


/*----------------------------------------------------------------------------*/

#endif //_V_UTILS_H