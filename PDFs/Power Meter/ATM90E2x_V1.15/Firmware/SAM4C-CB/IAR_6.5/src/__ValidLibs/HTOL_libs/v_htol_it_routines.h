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
 * File Name           : v_htol_it_routines.h
 * Object              :
 * Creation            : ERr   / Oct 2011
 *----------------------------------------------------------------------------
*/
#ifndef _V_HTOL_IT_ROUTINES_H
#define _V_HTOL_IT_ROUTINES_H


#include "project.h"


// ---- General purpose include files
#include "device.h"
#include "board.h"
#include "htol.h"


// ---- Peripherals (ASF drivers)
#include "drivers/tc/tc.h"


// ---- Validation libraries
//#include "v_utils.h"
//#include "HTOL_libs/v_htol_utils.h"

#define IT_FLAG_PATTERN(ID_PERIPH) 0x501F0000+(ID_PERIPH)


// ----------------------------------------------------------------------------
//  Number of peripherals
// ----------------------------------------------------------------------------
#if (SAM3S == 1)
  #define NB_PERIPH_ID 35
#elif (SAM4S == 1)
  #define NB_PERIPH_ID 35
#else
  #warning HTOL library does not support selected device
#endif
// ----------------------------------------------------------------------------


/*------------------*/
/* Prototypes       */
/*------------------*/




#endif//_V_HTOL_IT_ROUTINES_H
