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
 * File Name           : v_htol_uart.h
 * Object              :
 * Creation            : ERr   Sep/2011
 *----------------------------------------------------------------------------
*/
#ifndef _V_HTOL_UART_H
#define _V_HTOL_UART_H


#include "project.h"

// ---- General purpose include files
#include "device.h"
#include "board.h"
#include "htol.h"


// ---- Peripherals (ASF drivers)
#include "drivers/uart/uart.h"


// ---- Validation libraries
#include "HTOL_libs/v_htol_utils.h"
#include "v_drivers/v_uart.h"

// ----------------------------------------------------------------------------
// ----------- UART HTOL test settings
// ----------------------------------------------------------------------------
#define HTOL_UART_BGR_VAL  1      // baudrate = master clock / (16 * BGR)
#define HTOL_UART_NB_TEST_MODE 5

//#define HTOL_UART_BAUDRATE     115200 // not used
#define HTOL_UART_CHAR_TIMEOUT (HTOL_UART_BGR_VAL*16)*2
// ----------------------------------------------------------------------------


/*------------------*/
/* Prototypes       */
/*------------------*/
extern void run_uart_htol(Uart *uart, uint32_t test_mode, uint32_t test_nb_iter);
void init_uart_htol(Uart *uart, uint32_t test_mode);


#endif//_V_HTOL_UART_H
