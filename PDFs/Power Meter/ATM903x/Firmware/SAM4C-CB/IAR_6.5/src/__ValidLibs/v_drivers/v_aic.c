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
 * File Name           : v_aic.c
 *----------------------------------------------------------------------------
*/

#include "v_aic.h"




//------------------------------------------------------------------------------
//* Function Name : aic_enable_it                                             --
//* Object        : enables an interrupt line                                 --
//* Parameter     : periph_id = peripheral identifier                         --
//------------------------------------------------------------------------------
extern void aic_enable_it(Aic *aic, uint32_t periph_id)
{
  aic->AIC_SSR  = AIC_SSR_INTSEL(periph_id);
  aic->AIC_IECR = AIC_IECR_INTEN;
}
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
//* Function Name : aic_disable_it                                             --
//* Object        : disables an interrupt line                                 --
//* Parameter     : periph_id = peripheral identifier                         --
//------------------------------------------------------------------------------
extern void aic_disable_it(Aic *aic, uint32_t periph_id)
{
  aic->AIC_SSR  = AIC_SSR_INTSEL(periph_id);
  aic->AIC_IDCR = AIC_IDCR_INTD;
}
//------------------------------------------------------------------------------
