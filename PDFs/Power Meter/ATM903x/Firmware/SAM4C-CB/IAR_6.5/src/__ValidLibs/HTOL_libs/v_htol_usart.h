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
 * File Name           : v_htol_usart.h
 * Object              :
 * Creation            : ERr   Sep/2011
// first release based on UART driver : //ERr UART driver
 *----------------------------------------------------------------------------
*/
#ifndef _V_HTOL_USART_H
#define _V_HTOL_USART_H


#include "project.h"

// ---- General purpose include files
#include "device.h"
#include "board.h"
#include "htol.h"


// ---- Peripherals (ASF drivers)
//#include "drivers/usart/usart.h"


// ---- Validation libraries
#include "v_drivers/v_usart.h"
#include "HTOL_libs/v_htol_utils.h"


// ----------------------------------------------------------------------------
// ----------- UART HTOL test settings
// ----------------------------------------------------------------------------
#define HTOL_USART_BGR_VAL  1      // baudrate = master clock / (16 * BGR)
#define HTOL_USART_NB_TEST_MODE 5

#define HTOL_USART_BAUDRATE     115200 // not used
#define HTOL_USART_CHAR_TIMEOUT (HTOL_USART_BGR_VAL*16)*2
// ----------------------------------------------------------------------------


/*------------------*/
/* Prototypes       */
/*------------------*/
extern void run_usart_htol(Usart *usart, uint32_t test_mode, uint32_t test_nb_iter);
void init_usart_htol(Usart *usart, uint32_t test_mode);


#endif//_V_HTOL_USART_H
