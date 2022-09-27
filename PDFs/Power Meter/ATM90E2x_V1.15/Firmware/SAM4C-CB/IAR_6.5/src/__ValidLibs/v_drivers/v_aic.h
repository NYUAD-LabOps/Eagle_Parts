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
 * File Name           : v_aic.h
 * Object              :
 * Creation            : ERr   Dec/2011
 *----------------------------------------------------------------------------
*/

#ifndef _V_AIC_H
#define _V_AIC_H


#include "project.h"


// ---- General purpose include files
#include "device.h"
//#include <stdint.h>


// ---- Peripherals (ASF drivers)


// ---- Validation libraries




//------------------------------------------------------------------------------
// Definitions     ----
//---------------------

//------------------------------------------------------------------------------



//------------------------------------------------------------------------------
// Prototypes      ----
//---------------------
extern void aic_enable_it(Aic *aic, uint32_t periph_id);
extern void aic_disable_it(Aic *aic, uint32_t periph_id);
//------------------------------------------------------------------------------





#endif //_V_AIC_H
