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
 * File Name           : v_htol_usart.c
 * Object              :
 * Creation            : ERr   Sep/2011
// first release based on UART driver : //ERr UART driver
 *----------------------------------------------------------------------------
*/

#include "v_htol_usart.h"



// global variables
extern char msg[80]; //debug purpose
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
extern void run_usart_htol(Usart *usart, uint32_t test_mode, uint32_t test_nb_iter)
{
 uint32_t i;
 uint8_t *read_ptr,*write_ptr;
  
  Valid_DebugTrace( "* HTOL USART TEST *\n\r");
  
  // ----- UART init
  init_usart_htol(usart,test_mode);
  //init_uart_htol(uart,4); //ERr force no parity mode

  // ----- UART transfer (local loopback)
  read_ptr  = (uint8_t*)ISRAM_CODE_SECTION_START;
  write_ptr = (uint8_t*)ISRAM_TEST_SECTION_START;
  for(i=0;i<=test_nb_iter;){
    usart_write(usart,*read_ptr++); //ERr UART driver
    //while (!uart_is_rx_ready(uart));
    //wait_loop(HTOL_UART_CHAR_TIMEOUT); //non blocking wait loop
    WAIT_UNTIL(usart_is_rx_ready(usart),HTOL_USART_CHAR_TIMEOUT);//ERr UART driver
    usart_read(usart,write_ptr++); //ERr UART driver
    if(read_ptr>=(uint8_t*)ISRAM_TEST_SECTION_START){read_ptr=(uint8_t*)ISRAM_CODE_SECTION_START;}
    if(write_ptr>=(uint8_t*)ISRAM_TEST_SECTION_END){write_ptr=(uint8_t*)ISRAM_TEST_SECTION_START;}
    if(test_nb_iter != INFINITE_LOOP)++i;
    }
}



/*----------------------------------------------------------------------------*/
//* Function Name : init_uart_htol
//* Object       : run UART test for HTOL
//*---------------------------------------------------------------------------*/
void init_usart_htol(Usart *usart, uint32_t test_mode)
{
 sam_usart_opt_t usart_conf; //ERr UART driver
 uint32_t mode, par_mode;
 
  mode = test_mode % HTOL_USART_NB_TEST_MODE;
  switch (mode){
                case 0: par_mode=UART_MR_PAR_EVEN; break;  //ERr UART driver
                case 1: par_mode=UART_MR_PAR_ODD; break;   //ERr UART driver
                case 2: par_mode=UART_MR_PAR_SPACE; break; //ERr UART driver
                case 3: par_mode=UART_MR_PAR_MARK; break;  //ERr UART driver
                case 4: par_mode=UART_MR_PAR_NO; break;    //ERr UART driver
  default: break;}
   
  // ----- UART init
  usart_reset(usart); //reset & disable //ERr UART driver
  usart_conf.dw_mck=MCK_Freq;
  usart_conf.dw_baudrate=(MCK_Freq/(16*HTOL_USART_BGR_VAL));
  usart_conf.dw_mode=par_mode;
  usart_conf.dw_chmode=UART_MR_CHMODE_LOCAL_LOOPBACK;
  if (usart_init(usart, &usart_conf))HTOL_ErrorLog(INIT_ERROR,(uint32_t)usart,htol_iter);//ERr UART driver
  // ----- Enable Transmitter & receiver
  usart_enable(usart);//ERr UART driver
}