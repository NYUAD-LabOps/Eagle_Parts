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
 * File Name           : v_it_management.h
 * Object              :
 * Creation            : ERr   Dec/2011
 *----------------------------------------------------------------------------
*/
#ifndef _V_IT_MANAGEMENT_H
#define _V_IT_MANAGEMENT_H


#include "project.h"

// ---- General purpose include files
//#include <stdio.h> //IAR
#include "device.h"
#include "board.h"


// ---- Peripherals (ASF drivers)
//#include "drivers/uart/uart.h"


// ---- Validation libraries
#ifdef SAMA5
  #include "v_drivers/v_aic.h"
#else
  #include "v_drivers/v_nvic.h"
#endif


//------------------------------------------------------------------------------
// Definitions     ----
//---------------------

//------------------------------------------------------------------------------



//------------------------------------------------------------------------------
// Prototypes      ----
//---------------------
extern void enable_interrupt(uint32_t periph_id);
//------------------------------------------------------------------------------



#endif //_V_IT_MANAGEMENT_H