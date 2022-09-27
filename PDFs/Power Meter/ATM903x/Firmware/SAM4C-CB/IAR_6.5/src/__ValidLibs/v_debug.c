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
 * File Name           : v_debug.c
 *----------------------------------------------------------------------------
*/

#include "v_debug.h"




//*----------------------------------------------------------------------------
//* \fn    DEBUG_Ready
//* \brief This function Wait SR_TXEMPTY
//*----------------------------------------------------------------------------
extern void DEBUG_Ready(void)
{
   //while (!(BASE_DEBUG->UART_SR & UART_SR_TXEMPTY));
  while (!DEBUG_is_tx_empty((DEBUG_PERIPH_T*)BASE_DEBUG));
}


//*----------------------------------------------------------------------------
//* \fn    DEBUG_Printk
//* \brief This function is used to send a string through the DEBUG channel
//* (Very low level debugging)
//*----------------------------------------------------------------------------
extern void DEBUG_Printk(char *buffer) // \arg pointer to a string ending by \0
{
   while(*buffer != '\0')
   {
      while (!DEBUG_is_tx_ready((DEBUG_PERIPH_T*)BASE_DEBUG));
      
      DEBUG_write((DEBUG_PERIPH_T*)BASE_DEBUG, *buffer++);
   }

   DEBUG_Ready();
}


/*----------------------------------------------------------------------------*/
//* Function Name : DEBUG_PrintReg
//* Object       : print register value (uses stdio libs)
//*---------------------------------------------------------------------------*/
extern void DEBUG_PrintReg(uint32_t val32)
{
 char reg_string[9];
  
   sprintf(reg_string,"%d",val32);
   DEBUG_Printk(reg_string);
}


/*----------------------------------------------------------------------------*/
//* Function Name : DEBUG_PrintRegX
//* Object       : print register value (uses stdio libs)
//*---------------------------------------------------------------------------*/
extern void DEBUG_PrintRegX(uint32_t val32)
{
 char reg_string[9];
  
   sprintf(reg_string,"%X",val32);
   DEBUG_Printk(reg_string);
}

                
//*----------------------------------------------------------------------------
//* \fn    DEBUG_Get
//* \brief Get a Char to USART
//*----------------------------------------------------------------------------
extern int DEBUG_Get(char *val)
{
    if ((DEBUG_is_rx_ready((DEBUG_PERIPH_T*)BASE_DEBUG)) == 0) 
       return (1 != 1);
    else
        {
	   DEBUG_read((DEBUG_PERIPH_T*)BASE_DEBUG,(uint8_t*)val);
           return (1==1);
        }
}



//*----------------------------------------------------------------------------
//* \fn    DEBUG_Initialize
//* \brief 
//*----------------------------------------------------------------------------
extern void DEBUG_Initialize (unsigned int uMasterClk)
{
   DEBUG_PERIPH_OPTIONS_T debug_conf;
  
   // ----- First, enable the clock of the DEBUG
   pmc_enable_periph_clk(ID_DEBUG);
     
   
   // ----- Configure DEBUG
   DEBUG_reset_rx((DEBUG_PERIPH_T*)BASE_DEBUG);
   
   debug_conf.dw_mck=uMasterClk;
   debug_conf.dw_baudrate=DEFAULT_DEBUG_BAUD_RATE;
   //debug_conf.dw_mode=US_ASYNC_MODE;
   debug_conf.dw_mode=DEBUG_PERIPH_mode;//ERr
   debug_conf.dw_chmode=DEBUG_PERIPH_chmode; // not used
   DEBUG_init((DEBUG_PERIPH_T*)BASE_DEBUG,&debug_conf);


   // ----- ensure that no lock DEBUG //??
   //if (BASE_DEBUG -> UART_BRGR == 0) BASE_DEBUG -> UART_BRGR =1;
    
   // ----- Open PIO for DEBUG
   pio_set_peripheral(BRD_BASE_PIO_DEBUG,PIO_PERIPH_DEBUG,(uint32_t)(DEBUG_RXD | DEBUG_TXD));


   // ----- Enable Transmitter & receiver
   DEBUG_enable_tx((DEBUG_PERIPH_T*)BASE_DEBUG);
   DEBUG_enable_rx((DEBUG_PERIPH_T*)BASE_DEBUG);
   
   //BASE_DEBUG -> UART_IER = UART_IER_RXRDY;
   DEBUG_enable_interrupt((DEBUG_PERIPH_T*)BASE_DEBUG,DEBUG_IER_RXRDY);
   
   // ----- DEBUG IT management -------
   enable_interrupt(ID_DEBUG);

   /*
   // no more 32 interrupt
   // Disable the interrupt first
   NVIC -> ICER[0] = (1 << ID_DEBUG) ;

   // Clear any pending status
   NVIC -> ICPR[0] = (1 << ID_DEBUG) ;

   // Set priority
   //NVIC -> IP[ID_DEBUG] = PRIORITY_DEBUG;      // VP_test

   // Enable IT
   NVIC -> ISER[0] = (1 << ID_DEBUG) ;
   */
}
