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
 * File Name           : v_htol_utils.h
 * Object              :
 * Creation            : ERr   Sep/2011
 *----------------------------------------------------------------------------
*/
#ifndef _V_HTOL_UTILS_H
#define _V_HTOL_UTILS_H



#include "project.h"

// ---- General purpose include files
#include "device.h"
#include "board.h"
#include "htol.h"


// ---- Peripherals (ASF drivers)
//#include "drivers/pmc/pmc.h"


// ---- Validation libraries
#include "v_drivers/v_pio.h"
#include "v_dbgu.h"
#include "v_utils.h"



//*---------------------------------------------------------------------------*/
//* Error codes definitions
//*---------------------------------------------------------------------------*/
#define RESET_ERROR 0x0
#define INIT_ERROR  0x1
#define CODE2_ERROR 0x2
#define CODE3_ERROR 0x3
#define CODE4_ERROR 0x4
#define CODE5_ERROR 0x5
#define CODE6_ERROR 0x6
#define CODE7_ERROR 0x7
#define CODE8_ERROR 0x8
#define MISC_ERROR  0x9

#define NB_ERROR_TYPE 10
#define ERROR_CODE_PATTERN 0xCACAB0F0
//*---------------------------------------------------------------------------*/


//*---------------------------------------------------------------------------*/
//* Timeout macro
//* Object       : wait until cond is true with timeout=val
//*---------------------------------------------------------------------------*/
//#define WAIT_UNTIL(cond, val) for(uint32_t _i__=0;!cond && _i__++<val;)
//#define WAIT_LOOP_ITER_CYCLES 9 // number of MCK cycles to execute 1 increment
//*---------------------------------------------------------------------------*/


/*------------------*/
/* Prototypes       */
/*------------------*/
extern void isram_log_error(uint32_t error_code, uint32_t periph, uint32_t iter);
extern void flash_log_error(uint32_t error_code, uint32_t periph, uint32_t iter);
extern void init_errlog_tab(void);
//extern void wait_loop(uint32_t count); // moved to v_utils.h
//extern void wait_time(uint32_t time);  // moved to v_utils.h
extern void sos_loop(uint32_t time);
extern void led_toogle_1Hz(uint32_t time);
extern void led_toogle(uint32_t time, uint32_t freq);
extern void reg32_update_fields(uint32_t *reg_addr, uint32_t fields_mask);
extern void reg8_update_fields(uint8_t *reg_addr, uint8_t fields_mask);


/*----------------------------------------------------------------------------*/
//* Function Name : HTOL_DebugTrace
//* Object       : debug trace (depend on DEBUG_MODE defined in project.h)
//*---------------------------------------------------------------------------*/
/*
inline void HTOL_DebugTrace(char *buffer)
{
#if (DEBUG_MODE==DBGU)
  DBGU_Printk(buffer);
#else
  return;
#endif
}
*/

/*----------------------------------------------------------------------------*/
//* Function Name : HTOL_DebugPrintReg
//* Object       : print reg value (depend on DEBUG_MODE defined in project.h)
//*---------------------------------------------------------------------------*/
/*
inline void HTOL_DebugPrintReg(uint32_t reg_addr32)
{
#if (DEBUG_MODE==DBGU)
  DBGU_PrintReg(reg_addr32);
#else
  return;
#endif
}
*/

/*----------------------------------------------------------------------------*/
//* Function Name : HTOL_DebugPrintReg
//* Object       : print reg value (depend on DEBUG_MODE defined in project.h)
//*---------------------------------------------------------------------------*/
/*
inline void HTOL_DebugPrintRegX(uint32_t reg_addr32)
{
#if (DEBUG_MODE==DBGU)
  DBGU_PrintRegX(reg_addr32);
#else
  return;
#endif
}
*/

/*----------------------------------------------------------------------------*/
//* Function Name : HTOL_ErrorLog
//* Object       : Error log (depend on ERRLOG_MODE defined in project.h)
//*---------------------------------------------------------------------------*/
inline void HTOL_ErrorLog(uint32_t error_code, uint32_t periph, uint32_t iter)
{
#if (ERRLOG_MODE==ISRAM)
  isram_log_error(error_code, periph, iter);
#elif (ERRLOG_MODE==FLASH)
  flash_log_error(error_code, periph, iter);
#else
  return;
#endif
}


#endif//_V_HTOL_UTILS_H
