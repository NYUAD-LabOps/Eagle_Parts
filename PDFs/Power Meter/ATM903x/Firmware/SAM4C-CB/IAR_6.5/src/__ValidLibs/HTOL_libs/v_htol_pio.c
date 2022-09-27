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
 * File Name           : v_htol_pio.c
 *----------------------------------------------------------------------------
*/

#include "v_htol_pio.h"



// global variables
//extern uint32_t htol_iter;    // v_htol_main_functions.c definition
//extern unsigned int MCK_Freq; // v_htol_main_functions.c definition
extern volatile uint32_t periph_read_reg; // v_htol_main_functions.c definition
//extern volatile unsigned int it_flag[2]; // v_htol_it_routines.c definition


/*----------------------------------------------------------------------------*/
//* Function Name : run_pio_htol
//* Object       : run PIO test for HTOL
//*               
//*
//* Parameters: pio          = tested peripheral base address
//*             test_mode    = tested peripheral config (Parity mode)
//*             test_nb_iter = number of bytes to copy /or INFINITE_LOOP
//*---------------------------------------------------------------------------*/
extern void run_pio_htol(Pio *pio, uint32_t test_mode)
{
 uint8_t  mode;

 
  Valid_DebugTrace( "* HTOL PIO TEST *\n\r");

  // ----- Disable PIO write protect
  pio->PIO_WPMR = PIO_WPMR_WPKEY(PIO_KEY_VAL);
  
  // ----- PIO disable all interrupts
  pio->PIO_IDR   = 0xFFFFFFFF;
  pio->PIO_AIMDR = 0xFFFFFFFF;
  pio->PIO_PCIDR = 0xFFFFFFFF;
    
  // ----- PIO init
  mode = init_pio_htol(pio,test_mode);

  // ----- PIO test
  switch (mode){
                case 0: // not functional (reg access)
                  pio_reg_access(pio);
                  break;
                case 1:
                  break;
  default: break;}

  // ----- Enable PIO write protect
  pio->PIO_WPMR = PIO_WPMR_WPKEY(PIO_KEY_VAL)|PIO_WPMR_WPEN;
  pio->PIO_PER  = ~(pio->PIO_PER); // triggers WPROTERR flag;
  
  return;
}



/*----------------------------------------------------------------------------*/
//* Function Name : init_pio_htol
//* Object       : run PIO test for HTOL
//*---------------------------------------------------------------------------*/
uint32_t init_pio_htol(Pio *pio, uint32_t test_mode)
{
 uint32_t pio_next_mode;
 uint8_t  mode;
 
  mode = test_mode % HTOL_PIO_NB_TEST_MODE;
  switch (mode){
                case 0: // not functional (reg access)
                  pio_next_mode = PIO_MODE0;
                  break;
                case 1:
                  //pio_next_mode = PIO_MODE1;
                  // pseudo random config update
                  //reg32_update_fields(&pio_next_mode,PIO_CONFIG_FIELDS);
                  break;
  default: break;}
  
  // Program modes
  pio->PIO_PER = pio_next_mode;

  // enable ALL PIO interrupt (core level)
  nvic_pio_it_enable();
  
  // PIO interrupt enable
  pio->PIO_IDR   = PIO_IT_SOURCES_EN;
  pio->PIO_AIMDR = PIO_IT_ADD_SOURCES_EN;
  pio->PIO_PCIDR = PIO_IT_CAP_SOURCES_EN;
  
  return(mode);
}



/*----------------------------------------------------------------------------*/
//* Function Name : pio_reg_access
//* Object        : read/write peripheral register access
//*---------------------------------------------------------------------------*/
void pio_reg_access(Pio *pio)
{
  pio->PIO_PER       = ~(pio->PIO_PER);
  pio->PIO_PDR       = ~(pio->PIO_PDR);
  periph_read_reg    = ~(pio->PIO_PSR);   //RO
  pio->PIO_OER       = ~(pio->PIO_OER);
  pio->PIO_ODR       = ~(pio->PIO_ODR);
  periph_read_reg    = ~(pio->PIO_OSR);   //RO
  pio->PIO_IFER      = ~(pio->PIO_IFER);
  pio->PIO_IFDR      = ~(pio->PIO_IFDR);
  periph_read_reg    = ~(pio->PIO_IFSR);  //RO
  pio->PIO_SODR      = ~(pio->PIO_SODR);
  pio->PIO_CODR      = ~(pio->PIO_CODR);
  periph_read_reg    = ~(pio->PIO_ODSR);  //RO
  periph_read_reg    = ~(pio->PIO_PDSR);  //RO
  pio->PIO_IER       = ~(pio->PIO_IER);
  pio->PIO_IDR       = ~(pio->PIO_IDR);
  periph_read_reg    = ~(pio->PIO_IMR);   //RO
  periph_read_reg    = ~(pio->PIO_ISR);   //RO
  pio->PIO_MDER      = ~(pio->PIO_MDER);
  pio->PIO_MDDR      = ~(pio->PIO_MDDR);
  periph_read_reg    = ~(pio->PIO_MDSR);  //RO
  pio->PIO_PUDR      = ~(pio->PIO_PUDR);
  pio->PIO_PUER      = ~(pio->PIO_PUER);
  periph_read_reg    = ~(pio->PIO_PUSR);   //RO
  pio->PIO_ABCDSR[0] = ~(pio->PIO_ABCDSR[0]);
  pio->PIO_ABCDSR[1] = ~(pio->PIO_ABCDSR[1]);
  pio->PIO_IFSCDR    = ~(pio->PIO_IFSCDR);
  pio->PIO_IFSCER    = ~(pio->PIO_IFSCER);
  periph_read_reg    = ~(pio->PIO_IFSCSR); //RO
  pio->PIO_SCDR      = ~(pio->PIO_SCDR);
  pio->PIO_PPDDR     = ~(pio->PIO_PPDDR);
  pio->PIO_PPDER     = ~(pio->PIO_PPDER);
  periph_read_reg    = ~(pio->PIO_PPDSR);  //RO
  pio->PIO_OWER      = ~(pio->PIO_OWER);
  pio->PIO_OWDR      = ~(pio->PIO_OWDR);
  periph_read_reg    = ~(pio->PIO_OWSR);   //RO
  pio->PIO_AIMER     = ~(pio->PIO_AIMER);
  pio->PIO_AIMDR     = ~(pio->PIO_AIMDR);
  periph_read_reg    = ~(pio->PIO_AIMMR);  //RO
  pio->PIO_ESR       = ~(pio->PIO_ESR);
  pio->PIO_LSR       = ~(pio->PIO_LSR);
  periph_read_reg    = ~(pio->PIO_ELSR);   //RO
  pio->PIO_FELLSR    = ~(pio->PIO_FELLSR);
  pio->PIO_REHLSR    = ~(pio->PIO_REHLSR);
  periph_read_reg    = ~(pio->PIO_FRLHSR); //RO
  periph_read_reg    = ~(pio->PIO_LOCKSR); //RO
  pio->PIO_WPMR      = ~(pio->PIO_WPMR);   // (no effect)
  periph_read_reg    = ~(pio->PIO_WPSR);   //RO
  pio->PIO_SCHMITT   = ~(pio->PIO_SCHMITT);
  pio->PIO_PCMR      = ~(pio->PIO_PCMR);
  pio->PIO_PCIER     = ~(pio->PIO_PCIER);
  pio->PIO_PCIDR     = ~(pio->PIO_PCIDR);
  periph_read_reg    = ~(pio->PIO_PCIMR);  //RO
  periph_read_reg    = ~(pio->PIO_PCISR);  //RO
  periph_read_reg    = ~(pio->PIO_PCRHR);  //RO
}


/*----------------------------------------------------------------------------*/
//* Function Name : nvic_pio_it_enable
//* Object        : enable ALL PIO interrupt (core level)
//*---------------------------------------------------------------------------*/
void nvic_pio_it_enable()
{
#ifdef ID_PIO
  nvic_enable_it(ID_PIO);
#endif
#ifdef ID_PIOA
  nvic_enable_it(ID_PIOA);
#endif
#ifdef ID_PIOB
  nvic_enable_it(ID_PIOB);
#endif
#ifdef ID_PIOC
  nvic_enable_it(ID_PIOC);
#endif
#ifdef ID_PIOD
  nvic_enable_it(ID_PIOD);
#endif
#ifdef ID_PIOE
  nvic_enable_it(ID_PIOE);
#endif
}

