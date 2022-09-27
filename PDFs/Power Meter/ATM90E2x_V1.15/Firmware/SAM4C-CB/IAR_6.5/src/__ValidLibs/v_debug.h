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
#include "drivers/pmc/pmc.h"
#include "drivers/pio/pio.h"

// ---- Validation libraries
#include "v_it_management.h"


//------------------------------------------------------------------------------
// DEBUG Definition ----
//----------------------
#define DEFAULT_DEBUG_BAUD_RATE  DEBUG_BAUD_RATE //defined in project.h

#ifdef BRD_DBGU
  #if (DEBUG_LINK == BRD_DBGU)
    #define ID_DEBUG             ID_DBGU
    #define BASE_DEBUG           DBGU
    #define BRD_BASE_PIO_DEBUG   BRD_BASE_PIO_DBGU
    #define BRD_ID_PIO_DEBUG     BRD_ID_PIO_DBGU
    #define DEBUG_RXD	         BRD_DBGU_RXD
    #define DEBUG_TXD	         BRD_DBGU_TXD
    #define PIO_PERIPH_DEBUG     BRD_PERIPH_DBGU
    #define IRQ_DEBUG_HANDLER    DBGU_IrqHandler
    #define DEBUG_LINK_TYPE      TYPE_DBGU
  #endif
#endif

#ifdef BRD_UART0
  #if (DEBUG_LINK == BRD_UART0)
    #define ID_DEBUG             ID_UART0
    #define BASE_DEBUG           UART0
    #define BRD_BASE_PIO_DEBUG   BRD_BASE_PIO_UART0
    #define BRD_ID_PIO_DEBUG     BRD_ID_PIO_UART0
    #define DEBUG_RXD	         BRD_UART0_RXD
    #define DEBUG_TXD	         BRD_UART0_TXD
    #define PIO_PERIPH_DEBUG     BRD_PERIPH_UART0
    #define IRQ_DEBUG_HANDLER    UART0_IrqHandler
    #define DEBUG_LINK_TYPE      TYPE_UART
  #endif
#endif

#ifdef BRD_UART1
  #if (DEBUG_LINK == BRD_UART1)
    #define ID_DEBUG             ID_UART1
    #define BASE_DEBUG           UART1
    #define BRD_BASE_PIO_DEBUG   BRD_BASE_PIO_UART1
    #define BRD_ID_PIO_DEBUG     BRD_ID_PIO_UART1
    #define DEBUG_RXD	         BRD_UART1_RXD
    #define DEBUG_TXD	         BRD_UART1_TXD
    #define PIO_PERIPH_DEBUG     BRD_PERIPH_UART1
    #define IRQ_DEBUG_HANDLER    UART1_IrqHandler
    #define DEBUG_LINK_TYPE      TYPE_UART
  #endif
#endif

#ifdef BRD_UART2
  #if (DEBUG_LINK == BRD_UART2)
    #define ID_DEBUG             ID_UART2
    #define BASE_DEBUG           UART2
    #define BRD_BASE_PIO_DEBUG   BRD_BASE_PIO_UART2
    #define BRD_ID_PIO_DEBUG     BRD_ID_PIO_UART2
    #define DEBUG_RXD	         BRD_UART2_RXD
    #define DEBUG_TXD	         BRD_UART2_TXD
    #define PIO_PERIPH_DEBUG     BRD_PERIPH_UART2
    #define IRQ_DEBUG_HANDLER    UART2_IrqHandler
    #define DEBUG_LINK_TYPE      TYPE_UART
  #endif
#endif

#ifdef BRD_USART0
  #if (DEBUG_LINK == BRD_USART0)
    #define ID_DEBUG             ID_USART0
    #define BASE_DEBUG           USART0
    #define BRD_BASE_PIO_DEBUG   BRD_BASE_PIO_USART0
    #define BRD_ID_PIO_DEBUG     BRD_ID_PIO_USART0
    #define DEBUG_RXD	         BRD_USART0_RXD
    #define DEBUG_TXD	         BRD_USART0_TXD
    #define PIO_PERIPH_DEBUG     BRD_PERIPH_USART0
    #define IRQ_DEBUG_HANDLER    USART0_IrqHandler
    #define DEBUG_LINK_TYPE      TYPE_USART
  #endif
#endif

#ifdef BRD_USART1
  #if (DEBUG_LINK == BRD_USART1)
    #define ID_DEBUG             ID_USART1
    #define BASE_DEBUG           USART1
    #define BRD_BASE_PIO_DEBUG   BRD_BASE_PIO_USART1
    #define BRD_ID_PIO_DEBUG     BRD_ID_PIO_USART1
    #define DEBUG_RXD	         BRD_USART1_RXD
    #define DEBUG_TXD	         BRD_USART1_TXD
    #define PIO_PERIPH_DEBUG     BRD_PERIPH_USART1
    #define IRQ_DEBUG_HANDLER    USART1_IrqHandler
    #define DEBUG_LINK_TYPE      TYPE_USART
  #endif
#endif

#ifdef BRD_USART2
  #if (DEBUG_LINK == BRD_USART2)
    #define ID_DEBUG             ID_USART2
    #define BASE_DEBUG           USART2
    #define BRD_BASE_PIO_DEBUG   BRD_BASE_PIO_USART2
    #define BRD_ID_PIO_DEBUG     BRD_ID_PIO_USART2
    #define DEBUG_RXD	         BRD_USART2_RXD
    #define DEBUG_TXD	         BRD_USART2_TXD
    #define PIO_PERIPH_DEBUG     BRD_PERIPH_USART2
    #define IRQ_DEBUG_HANDLER    USART2_IrqHandler
    #define DEBUG_LINK_TYPE      TYPE_USART
  #endif
#endif

#ifdef BRD_USART3
  #if (DEBUG_LINK == BRD_USART3)
    #define ID_DEBUG             ID_USART3
    #define BASE_DEBUG           USART3
    #define BRD_BASE_PIO_DEBUG   BRD_BASE_PIO_USART3
    #define BRD_ID_PIO_DEBUG     BRD_ID_PIO_USART3
    #define DEBUG_RXD	         BRD_USART3_RXD
    #define DEBUG_TXD	         BRD_USART3_TXD
    #define PIO_PERIPH_DEBUG     BRD_PERIPH_USART3
    #define IRQ_DEBUG_HANDLER    USART3_IrqHandler
    #define DEBUG_LINK_TYPE      TYPE_USART
  #endif
#endif


#if (DEBUG_LINK_TYPE==TYPE_DBGU)
  #include "v_drivers/v_dbgu.h"
  #define DEBUG_is_rx_ready        dbgu_is_rx_ready
  #define DEBUG_is_tx_ready        dbgu_is_tx_ready
  #define DEBUG_is_tx_empty        dbgu_is_tx_empty
  #define DEBUG_write              dbgu_write
  #define DEBUG_read               dbgu_read
  #define DEBUG_init               dbgu_init
  #define DEBUG_reset_rx           dbgu_reset_rx
  #define DEBUG_enable_tx          dbgu_enable_tx
  #define DEBUG_enable_rx          dbgu_enable_rx
  #define DEBUG_enable_interrupt   dbgu_enable_interrupt
  #define DEBUG_PERIPH_T           Dbgu
  #define DEBUG_PERIPH_OPTIONS_T   sam_dbgu_opt_t
  #define DEBUG_PERIPH_mode        DBGU_MR_PAR_NONE
  #define DEBUG_PERIPH_chmode      DBGU_MR_CHMODE_NORM
  #define DEBUG_IER_RXRDY          DBGU_IER_RXRDY
#elif (DEBUG_LINK_TYPE==TYPE_UART)
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
#elif (DEBUG_LINK_TYPE==TYPE_USART)
  #include "v_drivers/v_usart.h"
  #define DEBUG_is_rx_ready        usart_is_rx_ready
  #define DEBUG_is_tx_ready        usart_is_tx_ready
  #define DEBUG_is_tx_empty        usart_is_tx_empty
  #define DEBUG_write              usart_write
  #define DEBUG_read               usart_read
  #define DEBUG_init               usart_init
  #define DEBUG_reset_rx           usart_reset_rx
  #define DEBUG_enable_tx          usart_enable_tx
  #define DEBUG_enable_rx          usart_enable_rx
  #define DEBUG_enable_interrupt   usart_enable_interrupt
  #define DEBUG_PERIPH_T           Usart
  #define DEBUG_PERIPH_OPTIONS_T   sam_usart_opt_t
  #define DEBUG_PERIPH_mode        (US_MR_USART_MODE_NORMAL | US_MR_PAR_NO)
  #define DEBUG_PERIPH_chmode      US_MR_CHMODE_NORMAL
  #define DEBUG_IER_RXRDY          US_IER_RXRDY
#endif
//------------------------------------------------------------------------------



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