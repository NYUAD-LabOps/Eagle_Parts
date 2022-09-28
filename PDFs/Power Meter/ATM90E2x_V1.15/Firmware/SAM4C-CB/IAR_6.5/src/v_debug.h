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
 * File Name           : v_debug.h
 * Object              :
 * Creation            : JPP   04/Sep/2006
 *                     : ERr   Sep/2011
 *----------------------------------------------------------------------------
*/
#ifndef _V_DEBUG_H
#define _V_DEBUG_H


#include "project.h"

// ---- General purpose include files
#include <stdio.h> //IAR
#include "device.h"
#include "board.h"


// ---- Peripherals (ASF drivers)
#include "pmc.h"
#include "pio.h"

#define ID_DEBUG             ID_UART0
#define BASE_DEBUG           UART0
#define IRQ_DEBUG_HANDLER    UART0_IrqHandler

#include "drivers/uart/uart.h"
#define DEBUG_is_rx_ready        uart_is_rx_ready
#define DEBUG_is_tx_ready        uart_is_tx_ready
#define DEBUG_is_tx_empty        uart_is_tx_empty
#define DEBUG_write              uart_write
#define DEBUG_read               uart_read
#define DEBUG_init               uart_init
#define DEBUG_reset_rx           uart_reset_rx
#define DEBUG_enable_tx          uart_enable_tx
#define DEBUG_enable_rx          uart_enable_rx
#define DEBUG_enable_interrupt   uart_enable_interrupt
#define DEBUG_PERIPH_T           Uart
#define DEBUG_PERIPH_OPTIONS_T   sam_uart_opt_t
#define DEBUG_PERIPH_mode        UART_MR_PAR_NO
#define DEBUG_PERIPH_chmode      UART_MR_CHMODE_NORMAL
#define DEBUG_IER_RXRDY          UART_IER_RXRDY


/*------------------*/
/* Prototypes       */
/*------------------*/
extern void DEBUG_Ready(void);
extern void DEBUG_Printk(char *buffer);
extern void DEBUG_PrintReg(uint32_t val32);
extern void DEBUG_PrintRegX(uint32_t val32);
extern int DEBUG_Get(char *val);
extern void DEBUG_Initialize (unsigned int uBaud);



#endif //_V_DEBUG_H