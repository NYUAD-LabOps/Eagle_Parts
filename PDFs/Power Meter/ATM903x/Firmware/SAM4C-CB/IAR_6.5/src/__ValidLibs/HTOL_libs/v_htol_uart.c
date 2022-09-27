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
 * File Name           : v_htol_uart.c
 *----------------------------------------------------------------------------
*/

#include "v_htol_uart.h"



// global variables
//extern char msg[80]; //debug purpose
extern uint32_t htol_iter;
extern unsigned int MCK_Freq;
// variables declared in v_htol_main_functions.c


/*----------------------------------------------------------------------------*/
//* Function Name : run_uart_htol
//* Object       : run UART test for HTOL
//*                SRAM buffer copies through UART local loopback
//*
//* Parameters: uart         = tested peripheral base address
//*             test_mode    = tested peripheral config (Parity mode)
//*             test_nb_iter = number of bytes to copy /or INFINITE_LOOP
//*---------------------------------------------------------------------------*/
extern void run_uart_htol(Uart *uart, uint32_t test_mode, uint32_t test_nb_iter)
{
 uint32_t i;
 uint8_t *read_ptr,*write_ptr;
  
  Valid_DebugTrace( "* HTOL UART TEST *\n\r");
  
  // ----- UART init
  init_uart_htol(uart,test_mode);
  //init_uart_htol(uart,4); //ERr force no parity mode

  // ----- UART transfer (local loopback)
  read_ptr  = (uint8_t*)ISRAM_CODE_SECTION_START;
  write_ptr = (uint8_t*)ISRAM_TEST_SECTION_START;
  for(i=0;i<=test_nb_iter;){
    uart_write(uart,*read_ptr++);
    //while (!uart_is_rx_ready(uart));
    //wait_loop(HTOL_UART_CHAR_TIMEOUT); //non blocking wait loop
    WAIT_UNTIL(uart_is_rx_ready(uart),HTOL_UART_CHAR_TIMEOUT);
    uart_read(uart,write_ptr++);
    if(read_ptr>=(uint8_t*)ISRAM_TEST_SECTION_START){read_ptr=(uint8_t*)ISRAM_CODE_SECTION_START;}
    if(write_ptr>=(uint8_t*)ISRAM_TEST_SECTION_END){write_ptr=(uint8_t*)ISRAM_TEST_SECTION_START;}
    if(test_nb_iter != INFINITE_LOOP)++i;
    }
}



/*----------------------------------------------------------------------------*/
//* Function Name : init_uart_htol
//* Object       : run UART test for HTOL
//*---------------------------------------------------------------------------*/
void init_uart_htol(Uart *uart, uint32_t test_mode)
{
 sam_uart_opt_t uart_conf;
 uint32_t mode, par_mode;
 
  mode = test_mode % HTOL_UART_NB_TEST_MODE;
  switch (mode){
                case 0: par_mode=UART_MR_PAR_EVEN; break;
                case 1: par_mode=UART_MR_PAR_ODD; break;
                case 2: par_mode=UART_MR_PAR_SPACE; break;
                case 3: par_mode=UART_MR_PAR_MARK; break;
                case 4: par_mode=UART_MR_PAR_NO; break;
  default: break;}
   
  // ----- UART init
  uart_reset(uart); //reset & disable
  uart_conf.dw_mck=MCK_Freq;
  uart_conf.dw_baudrate=(MCK_Freq/(16*HTOL_UART_BGR_VAL));
  uart_conf.dw_mode=par_mode;
  uart_conf.dw_chmode=UART_MR_CHMODE_LOCAL_LOOPBACK;
  if (v_uart_init(uart, &uart_conf))HTOL_ErrorLog(INIT_ERROR,(uint32_t)uart,htol_iter);
  // ----- Enable Transmitter & receiver
  uart_enable(uart);
}