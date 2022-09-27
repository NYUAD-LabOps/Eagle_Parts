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
 * File Name           : v_htol_spi.c
 *----------------------------------------------------------------------------
*/

#include "v_htol_spi.h"



// global variables
extern volatile uint8_t spi_flag; // v_htol_it_routines.c definition
//extern uint32_t htol_iter;    // v_htol_main_functions.c definition
//extern unsigned int MCK_Freq; // v_htol_main_functions.c definition
extern volatile uint32_t periph_read_reg; // v_htol_main_functions.c definition
//extern volatile unsigned int it_flag[2]; // v_htol_it_routines.c definition


/*----------------------------------------------------------------------------*/
//* Function Name : run_spi_htol
//* Object       : run SPI test for HTOL
//*               
//*
//* Parameters: spi          = tested peripheral base address
//*             test_mode    = tested peripheral config (Parity mode)
//*             test_nb_iter = number of bytes to copy /or INFINITE_LOOP
//*---------------------------------------------------------------------------*/
extern void run_spi_htol(Spi *spi, uint32_t test_mode, uint32_t test_nb_iter)
{
 uint8_t  mode;

 
  Valid_DebugTrace( "* HTOL SPI TEST *\n\r");

  // ----- Disable SPI write protect
  spi->SPI_WPMR = SPI_WPMR_SPIWPKEY(SPI_KEY_VAL);

  // Software reset
  spi->SPI_CR = SPI_CR_SWRST;

  // ----- SPI disable
  spi->SPI_CR =  SPI_CR_SPIDIS;
  spi->SPI_IDR = 0xFFFFFFFF ; // disable all IT
  
  // ----- SPI init
  spi_flag = 0;
  mode = init_spi_htol(spi,test_mode);

  // ----- SPI test
  switch (mode){
                case 0: // not functional (reg access)
                  spi_reg_access(spi);
                  break;
                case 1:
                  // ----- SPI enable
                  spi->SPI_CR = SPI_CR_SPIEN;
                  spi_htol_transfer(spi);
                  break;
                case 2:
                  // ----- SPI enable
                  spi->SPI_CR = SPI_CR_SPIEN;
                  break;
  default: break;}

  // ----- Enable SPI write protect
  spi->SPI_WPMR   = SPI_WPMR_SPIWPEN |SPI_WPMR_SPIWPKEY(SPI_KEY_VAL);

  spi->SPI_MR     = ~(spi->SPI_MR);     // triggers WPSR status flags
  spi->SPI_CSR[0] = ~(spi->SPI_CSR[0]); // triggers WPSR status flags
  spi->SPI_CSR[1] = ~(spi->SPI_CSR[1]); // triggers WPSR status flags
  spi->SPI_CSR[2] = ~(spi->SPI_CSR[2]); // triggers WPSR status flags
  spi->SPI_CSR[3] = ~(spi->SPI_CSR[3]); // triggers WPSR status flags

  return;
}



/*----------------------------------------------------------------------------*/
//* Function Name : init_spi_htol
//* Object       : run SPI test for HTOL
//*---------------------------------------------------------------------------*/
uint32_t init_spi_htol(Spi *spi, uint32_t test_mode)
{
 uint32_t spi_next_mode, csr_next_mode;
 uint8_t  mode;
 
  mode = test_mode % HTOL_SPI_NB_TEST_MODE;
  switch (mode){
                case 0: // not functional (reg access)
                  return(mode); // No init
                case 1: // Master (LLB)
                  spi_next_mode = SPI_MODE1;
                  csr_next_mode = SPI_CSR_MODE1;
                  // pseudo random config update
                  reg32_update_fields(&spi_next_mode,SPI_MR_FIELDS_1);
                  reg32_update_fields(&csr_next_mode,SPI_CSR_FIELDS_1);
                  spi->SPI_IER = SPI_IT_SOURCES_EN_1; // SPI interrupt enable
                  break;
                case 2: // Slave
                  spi_next_mode = SPI_MODE2;
                  csr_next_mode = SPI_CSR_MODE2;
                  // pseudo random config update
                  reg32_update_fields(&spi_next_mode,SPI_MR_FIELDS_2);
                  reg32_update_fields(&csr_next_mode,SPI_CSR_FIELDS_2);
                  spi->SPI_IER = SPI_IT_SOURCES_EN_2; // SPI interrupt enable
                  break;
  default: break;}
 
  // Program modes
  spi->SPI_MR  = spi_next_mode;
  spi->SPI_CSR[0] = csr_next_mode;
  spi->SPI_CSR[1] = csr_next_mode;
  spi->SPI_CSR[2] = csr_next_mode;
  spi->SPI_CSR[3] = csr_next_mode;
  
  // enable ALL SPI interrupt (core level)
  nvic_spi_it_enable();

  return(mode);
}


/*----------------------------------------------------------------------------*/
//* Function Name : spi_reg_access
//* Object        : read/write peripheral register access
//*---------------------------------------------------------------------------*/
void spi_reg_access(Spi *spi)
{
  spi->SPI_CR     = ~(spi->SPI_CR);
  spi->SPI_MR     = ~(spi->SPI_MR);
  periph_read_reg = ~(spi->SPI_RDR);  //RO
  spi->SPI_TDR    = ~(spi->SPI_TDR);
  periph_read_reg = ~(spi->SPI_SR);   //RO
  spi->SPI_IER    = ~(spi->SPI_IER);
  spi->SPI_IDR    = ~(spi->SPI_IDR);
  periph_read_reg = ~(spi->SPI_IMR);  //RO
  spi->SPI_CSR[0] = ~(spi->SPI_CSR[0]);
  spi->SPI_CSR[1] = ~(spi->SPI_CSR[1]);
  spi->SPI_CSR[2] = ~(spi->SPI_CSR[2]);
  spi->SPI_CSR[3] = ~(spi->SPI_CSR[3]);
  periph_read_reg = ~(spi->SPI_WPMR); 
  periph_read_reg = ~(spi->SPI_WPSR); //RO
}



/*----------------------------------------------------------------------------*/
//* Function Name : spi_htol_transfer
//* Object        : transfer data buffer using local loop back feature
//*---------------------------------------------------------------------------*/
void spi_htol_transfer(Spi* spi)
{ 
 uint32_t i, buffer_start,lastxfer_bit;
 uint16_t *read_ptr,*write_ptr;
 
 // pseudo random buffer start
 #if (ISRAM_TEST_SECTION_SIZE==SPI_RAM_TEST_SIZE)
   buffer_start = 0;
 #else
   reg32_update_fields(&buffer_start,0xFFFFFFFF);
   buffer_start = buffer_start % (ISRAM_TEST_SECTION_SIZE-SPI_RAM_TEST_SIZE);
 #endif

 read_ptr  = (uint16_t*)(ISRAM_CODE_SECTION_START + buffer_start);
 write_ptr = (uint16_t*)(ISRAM_TEST_SECTION_START + buffer_start);
    

 lastxfer_bit = 0;
 
 for(i=0;i<SPI_RAM_TEST_SIZE;i+=2){
    spi->SPI_IER = SPI_IT_SOURCES_EN_1 ; // enable IT
    if(i==SPI_RAM_TEST_SIZE-2)lastxfer_bit=SPI_TDR_LASTXFER;
    spi->SPI_TDR = SPI_TDR_TD(*read_ptr)|lastxfer_bit;
    //wait_time(1);
    WAIT_UNTIL((!spi_flag),HTOL_SPI_WORD_TIMEOUT);
    spi_flag = 0;
    *write_ptr = spi->SPI_RDR;
    read_ptr++;
    write_ptr++;
    }
}



/*----------------------------------------------------------------------------*/
//* Function Name : nvic_spi_it_enable
//* Object        : enable ALL SPI interrupt (core level)
//*---------------------------------------------------------------------------*/
void nvic_spi_it_enable()
{
#ifdef ID_SPI //single SPI peripheral
  nvic_enable_it(ID_SPI);
#endif
#ifdef ID_SPI0
  nvic_enable_it(ID_SPI0);
#endif
#ifdef ID_SPI1
  nvic_enable_it(ID_SPI1);
#endif
}

