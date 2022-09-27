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
 * File Name           : v_htol_misc.c
 *----------------------------------------------------------------------------
*/

#include "v_htol_misc.h"


// global variables
extern char msg[80]; //debug purpose
extern uint32_t htol_iter;
extern unsigned int MCK_Freq;
// variables declared in v_htol_main_functions.c



/*----------------------------------------------------------------------------*/
//* Function Name : run_misc_htol
//* Object        : run HTOL test on misc peripheral (register access)
//*---------------------------------------------------------------------------*/
extern void run_misc_htol(void)
{
 volatile uint32_t read_reg;
 uint32_t test;
 //uint32_t test_reg;
 
  Valid_DebugTrace( "* HTOL Miscelaneous Tests *\n\r");

#ifdef RSTC //TST_RSTC (reg access)
  RSTC->RSTC_CR = ~RSTC_CR_KEY_Msk | ~(RSTC_CR_KEY(RSTC_KEY_VAL)); // no effect (protected)
  read_reg = RSTC->RSTC_SR;
  RSTC->RSTC_MR = ~RSTC_MR_KEY_Msk | ~(RSTC_MR_KEY(RSTC_KEY_VAL)); // no effect (protected)
#endif//RSTC

#ifdef WDT //TST_WDT (reg access)
  WDT->WDT_CR = ~WDT_CR_KEY_Msk | ~(WDT_CR_KEY(WDT_KEY_VAL)); // no effect (protected)
  read_reg = WDT->WDT_SR;
  read_reg = WDT->WDT_MR; // try read access only
#endif//WDT

#ifdef PMC //TST_PMC (reg access)
  test = (PMC->PMC_WPMR) & PMC_WPMR_WPEN; // check write protection before test
  PMC->PMC_WPMR = PMC_WPMR_WPKEY(PMC_KEY_VAL) | PMC_WPMR_WPEN; // enable write protection
  PMC->PMC_SCER   = ~PMC->PMC_SCER;   // write protect violation
  PMC->PMC_SCDR   = ~PMC->PMC_SCDR;   // write protect violation
  read_reg        =  PMC->PMC_SCSR;   // RO
  PMC->PMC_PCER0  = ~PMC->PMC_PCER0;  // write protect violation
  PMC->PMC_PCDR0  = ~PMC->PMC_PCDR0;  // write protect violation
  read_reg        =  PMC->PMC_PCSR0;  // RO
#ifdef REG_PMC_PCER1
  PMC->PMC_PCER1  = ~PMC->PMC_PCER1;  // write protect violation
  PMC->PMC_PCDR1  = ~PMC->PMC_PCDR1;  // write protect violation
  read_reg        =  PMC->PMC_PCSR1;  // RO
#endif//REG_PMC_PCER1
  PMC->CKGR_MOR   = ~PMC->CKGR_MOR;   // write protect violation
  read_reg        =  PMC->CKGR_MCFR;  // RO
  PMC->CKGR_PLLAR = ~PMC->CKGR_PLLAR; // write protect violation
  PMC->CKGR_PLLBR = ~PMC->CKGR_PLLBR; // write protect violation
  PMC->PMC_MCKR   = ~PMC->PMC_MCKR;   // write protect violation
  PMC->PMC_USB    = ~PMC->PMC_USB;    // write protect violation
  PMC->PMC_PCK[0] = ~PMC->PMC_PCK[0]; // write protect violation
  PMC->PMC_PCK[1] = ~PMC->PMC_PCK[1]; // write protect violation
  PMC->PMC_PCK[2] = ~PMC->PMC_PCK[2]; // write protect violation
  read_reg        = ~PMC->PMC_IER;    // try read access only
  read_reg        = ~PMC->PMC_IDR;    // try read access only
  read_reg        =  PMC->PMC_SR;     // RO
  read_reg        =  PMC->PMC_IMR;    // RO
  PMC->PMC_FSMR   = ~PMC->PMC_FSMR;   // write protect violation
  PMC->PMC_FSPR   = ~PMC->PMC_FSPR;   // write protect violation
  read_reg        =  PMC->PMC_FOCR;   // try read access only
  PMC->PMC_OCR    = ~PMC->PMC_OCR;    // write protect violation
  read_reg = PMC->PMC_WPSR; // clear status
  if (!test){PMC->PMC_WPMR = PMC_WPMR_WPKEY(PMC_KEY_VAL);} // disable write protection
#endif//PMC

#ifdef CHIPID //TST_CHIPID (reg access)
  read_reg = CHIPID->CHIPID_CIDR;
  read_reg = CHIPID->CHIPID_EXID;
#endif//CHIPID

#ifdef MATRIX //MATRIX (reg access)
  test = (MATRIX->MATRIX_WPMR) & MATRIX_WPMR_WPEN; // check write protection before test
  MATRIX->MATRIX_WPMR = MATRIX_WPMR_WPKEY(MATRIX_KEY_VAL) | MATRIX_WPMR_WPEN; // enable write protection
  MATRIX->MATRIX_MCFG[0] = ~MATRIX->MATRIX_MCFG[0]; // write protect violation
  MATRIX->MATRIX_MCFG[1] = ~MATRIX->MATRIX_MCFG[1]; // write protect violation
  MATRIX->MATRIX_MCFG[2] = ~MATRIX->MATRIX_MCFG[2]; // write protect violation
  MATRIX->MATRIX_MCFG[3] = ~MATRIX->MATRIX_MCFG[3]; // write protect violation
  MATRIX->MATRIX_SCFG[0] = ~MATRIX->MATRIX_SCFG[0]; // write protect violation
  MATRIX->MATRIX_SCFG[1] = ~MATRIX->MATRIX_SCFG[1]; // write protect violation
  MATRIX->MATRIX_SCFG[2] = ~MATRIX->MATRIX_SCFG[2]; // write protect violation
  MATRIX->MATRIX_SCFG[3] = ~MATRIX->MATRIX_SCFG[3]; // write protect violation
  MATRIX->MATRIX_SCFG[4] = ~MATRIX->MATRIX_SCFG[4]; // write protect violation
  MATRIX->MATRIX_PRAS0   = ~MATRIX->MATRIX_PRAS0; // write protect violation
  MATRIX->MATRIX_PRAS1   = ~MATRIX->MATRIX_PRAS1; // write protect violation
  MATRIX->MATRIX_PRAS2   = ~MATRIX->MATRIX_PRAS2; // write protect violation
  MATRIX->MATRIX_PRAS3   = ~MATRIX->MATRIX_PRAS3; // write protect violation
  MATRIX->MATRIX_PRAS4   = ~MATRIX->MATRIX_PRAS4; // write protect violation
  MATRIX->CCFG_SYSIO     = ~MATRIX->CCFG_SYSIO;   // write protect violation
  MATRIX->CCFG_SMCNFCS   = ~MATRIX->CCFG_SYSIO;   // write protect violation
  read_reg               =  MATRIX->MATRIX_WPMR;  // try read access only
  read_reg = MATRIX->MATRIX_WPSR; // clear status
  if (!test){MATRIX->MATRIX_WPMR = MATRIX_WPMR_WPKEY(MATRIX_KEY_VAL);} // disable write protection
#endif//MATRIX
}


