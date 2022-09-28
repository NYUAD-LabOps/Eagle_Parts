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
 * File Name           : v_htol_spi.h
 * Object              :
 * Creation            : ERr   Sep/2011
 *----------------------------------------------------------------------------
*/
#ifndef _V_HTOL_SPI_H
#define _V_HTOL_SPI_H


#include "project.h"

// ---- General purpose include files
#include "device.h"
#include "board.h"
#include "htol.h"


// ---- Peripherals (ASF drivers)


// ---- Validation libraries
#include "v_drivers/v_nvic.h"
#include "v_drivers/v_spi.h"
#include "HTOL_libs/v_htol_utils.h"


// ----------------------------------------------------------------------------
// ----------- SPI HTOL test settings
// ----------------------------------------------------------------------------
#define HTOL_SPI_NB_TEST_MODE 3

// Test modes
#define SPI_MODE0 0x00000000 // Not functional (reg access)

// Master mode / local loopback
#define SPI_MODE1 ( SPI_MR_MSTR     & ~SPI_MR_PS    & ~SPI_MR_PCSDEC \
                  | SPI_MR_MODFDIS  & ~SPI_MR_WDRBT | SPI_MR_LLB     \
                  & ~SPI_MR_PCS_Msk & ~SPI_MR_DLYBCS_Msk )
#define SCBR_VAL1 1 // MCK divider for SPI clock
#define SPI_CSR_MODE1  ( SPI_CSR_BITS_16_BIT     \
                       | SPI_CSR_SCBR(SCBR_VAL1) \
                       | SPI_CSR_DLYBS(0)        \
                       | SPI_CSR_DLYBCT(0)) // default min delay
  
// Slave mode / no transfer
#define SPI_MODE2 (0& ~SPI_MR_MSTR    & ~SPI_MR_PS    & ~SPI_MR_PCSDEC \
                  |   SPI_MR_MODFDIS  & ~SPI_MR_WDRBT & ~SPI_MR_LLB    \
                  &   ~SPI_MR_PCS_Msk & ~SPI_MR_DLYBCS_Msk )
#define SPI_CSR_MODE2 0x00000000


// Configuration fields to updtate
#define SPI_MR_FIELDS_1 (SPI_MR_MODFDIS | SPI_MR_WDRBT | SPI_MR_DLYBCS_Msk)
#define SPI_CSR_FIELDS_1 ( SPI_CSR_CPOL   | SPI_CSR_NCPHA \
                         | SPI_CSR_CSNAAT | SPI_CSR_CSAAT )
#define SPI_MR_FIELDS_2  0xFF0F00B7
#define SPI_CSR_FIELDS_2 0xFFFFFF7F


// Enable all possible IT sources
#define SPI_IT_SOURCES_EN_1 SPI_IER_RDRF
#define SPI_IT_SOURCES_EN_2 0xFFFFFFFF


// SRAM test buffer size (8 bits words)
#define SPI_RAM_TEST_SIZE ISRAM_TEST_SECTION_SIZE

// Timeout for 16bits word transfer (depend on SCBR field)
#define HTOL_SPI_WORD_TIMEOUT SCBR_VAL1
// ----------------------------------------------------------------------------



/*------------------*/
/* Prototypes       */
/*------------------*/
extern void run_spi_htol(Spi *spi, uint32_t test_mode, uint32_t test_nb_iter);
uint32_t init_spi_htol(Spi *spi, uint32_t test_mode);
void spi_reg_access(Spi *spi);
void spi_htol_transfer(Spi* spi);
void nvic_spi_it_enable();


// ----------------------------------------------------------------------------
// SRAM test buffer size check
#if (SPI_RAM_TEST_SIZE > ISRAM_TEST_SECTION_SIZE)
  #warning SPI buffer size too big : redefining to max value
  #undef SPI_RAM_TEST_SIZE
  #define SPI_RAM_TEST_SIZE ISRAM_TEST_SECTION_SIZE
#endif
// ----------------------------------------------------------------------------



#endif //_V_HTOL_SPI_H


