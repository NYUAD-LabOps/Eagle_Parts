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
 * File Name           : v_relocate.c
 *----------------------------------------------------------------------------
*/

#include "v_relocate.h"


#ifndef SCB_VTOR_TBLBASE_Pos
//ERr : missing definitions in CMSIS 2.10 / core_cmx.h
#define SCB_VTOR_TBLBASE_Pos  29                              /*!< SCB VTOR: TBLBASE Position */
#define SCB_VTOR_TBLBASE_Msk  (0x1ul << SCB_VTOR_TBLBASE_Pos) /*!< SCB VTOR: TBLBASE Mask */
#endif


//------------------------------------------------------------------------------
/// Relocate interrupt table given (unique) source 
/// \param source  Interrupt Table to enable.
//------------------------------------------------------------------------------
void relocate_int_table(unsigned int new_dest)
{
  // no need to use AT91C_NVIC_TBLBASE and AT91C_NVIC_TBLOFF are include in address
  if (new_dest)
    SCB -> VTOR = (unsigned int) &new_vector_table | SCB_VTOR_TBLBASE_Msk;
  else
  {
    SCB -> VTOR = (unsigned int) &vector_table & ~SCB_VTOR_TBLBASE_Msk;  
  }
}

