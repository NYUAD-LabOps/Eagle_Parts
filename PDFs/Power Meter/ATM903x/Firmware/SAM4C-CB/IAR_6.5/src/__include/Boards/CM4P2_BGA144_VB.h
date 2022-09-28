/*----------------------------------------------------------------------------
*         ATMEL Microcontroller Software Support  -  ROUSSET  -
*----------------------------------------------------------------------------
* The software is delivered "AS IS" without warranty or condition of any
* kind, either express, implied or statutory. This includes without
* limitation any warranty or condition with respect to merchantability or
* fitness for any particular purpose, or against the infringements of
* intellectual property rights of others.
*----------------------------------------------------------------------------
* File Name           : 
* Object              : 
*
* Creation            : 
*----------------------------------------------------------------------------
*/
#ifndef _CM4P2_VB_H
#define _CM4P2_VB_H

/*---------------------------------------------------------------------------
*    Board level definitions
*----------------------------------------------------------------------------
* Device compliance : SAM3S1BA-AU
*
*
*----------------------------------------------------------------------------
--------------------------------------------
|    Board       |        PIO              |
____________________________________________
| UART0 (J10)    |  PA9=URXD0 / PA10=UTXD0 |   
| UART1 (J12)    |  PA6=URXD1 / PA5=UTXD1  |
| Gr LED (D3)    |  PE5  (1 => LED off)    |
| Gr LED (D4)    |  PE4  (1 => LED off)    |
| RClick (BP3)   |  PA2  (push => 0)       |
| LClick (BP4)   |  PA16 (push => 0)       |
============================================
*----------------------------------------------------------------------------
*----------------------------------------------------------------------------
*/

#include "device.h"


/*----------------------------------------------------------------------------*/
/* -------- Leds Definition                                                   */
/*----------------------------------------------------------------------------*/
#define BRD_BASE_PIO_D3  PIOE
#define BRD_BASE_PIO_D4  PIOE
#define BRD_ID_PIO_D3    ID_PIOE
#define BRD_ID_PIO_D4    ID_PIOE
#define BRD_D3_MASK      (1<<5)   /* PE5 D3 */
#define BRD_D4_MASK      (1<<4)	  /* PE4  D4 */

#define BRD_D3_POLARITY 0 // (0 => LED On)
#define BRD_D4_POLARITY 0 // (0 => LED On)

#define BRD_BASE_PIO_ALL_LED  PIOE
#define BRD_ID_PIO_ALL_LED    ID_PIOE
#define BRD_ALL_LED_MASK      (BRD_D3_MASK|BRD_D4_MASK)

#define BRD_TURN_ON_D3   pio_clear(BRD_BASE_PIO_D3,BRD_D3_MASK)
#define BRD_TURN_OFF_D3  pio_set(BRD_BASE_PIO_D3,BRD_D3_MASK)
#define BRD_TOGGLE_D3    pio_toggle(BRD_BASE_PIO_D3,BRD_D3_MASK)
#define BRD_TURN_ON_D4   pio_clear(BRD_BASE_PIO_D4,BRD_D4_MASK)
#define BRD_TURN_OFF_D4  pio_set(BRD_BASE_PIO_D4,BRD_D4_MASK)
#define BRD_TOGGLE_D4    pio_toggle(BRD_BASE_PIO_D4,BRD_D4_MASK)
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* -------- Inputs Definition                                                 */
/*----------------------------------------------------------------------------*/
#define BRD_BASE_PIO_BP3   PIOA
#define BRD_BASE_PIO_BP4   PIOA
#define BRD_ID_PIO_BP3     ID_PIOA
#define BRD_ID_PIO_BP4     ID_PIOA
#define BRD_BP3_MASK       (1<<2)	// PA2   RIGHT CLICK 
#define BRD_BP4_MASK       (1<<16)	// PA16  LEFT CLICK

#define BRD_BASE_PIO_ALL_INPUT  PIOA
#define BRD_ID_PIO_ALL_INPUT    ID_PIOA
#define BRD_ALL_INPUT_MASK      (BRD_BP3_MASK | BRD_BP4_MASK)

#define BRD_GET_BP3  pio_get(BRD_BASE_PIO_BP3,PIO_INPUT,BRD_BP3_MASK)
#define BRD_GET_BP4  pio_get(BRD_BASE_PIO_BP4,PIO_INPUT,BRD_BP4_MASK)
/*----------------------------------------------------------------------------*/


//------------------------------------------------------------------------------
// ---- Board Clocks ----
//-----------------------
#define BRD_SLOW_OSC               0         // NONE bypass through J7 connector
#define BRD_MAIN_OSC               0         // NONE bypass through J6 connector
#define BRD_SLOW_XTAL              32768     // Y1 Y4 Y6
#define BRD_MAIN_XTAL            8000000     // Y2 Y5 Y7
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// ---- Board Peripherals ----
//----------------------------
#define BRD_UART0 0 // UART0 on J6
#define BRD_UART1 1 // UART1 on J7
//------------------------------------------------------------------------------


/*----------------------------------------------------------------------------*/
/*---------------------------------------------------------*/
/* Peripherals Definition (Device dependant)               */
/*---------------------------------------------------------*/
// CM4P2E ////////////////////////////////////////////////////
#if (CM4P2E==1)
  #define BRD_BASE_PIO_UART0  PIOA
  #define BRD_ID_PIO_UART0    ID_PIOA
  #define BRD_UART0_RXD	      PIO_PA9A_URXD0
  #define BRD_UART0_TXD	      PIO_PA10A_UTXD0
  #define BRD_PERIPH_UART0    PIO_PERIPH_A
  #define BRD_BASE_PIO_UART1  PIOA
  #define BRD_ID_PIO_UART1    ID_PIOA
  #define BRD_UART1_RXD	      PIO_PA5C_URXD1
  #define BRD_UART1_TXD	      PIO_PA6C_UTXD1
  #define BRD_PERIPH_UART1    PIO_PERIPH_A
// CM4P2B ////////////////////////////////////////////////////
#elif (CM4P2B==1)
  #define BRD_BASE_PIO_UART0  PIOA
  #define BRD_ID_PIO_UART0    ID_PIOA
  #define BRD_UART0_RXD	      PIO_PA9A_URXD0
  #define BRD_UART0_TXD	      PIO_PA10A_UTXD0
  #define BRD_PERIPH_UART0    PIO_PERIPH_A
  #define BRD_BASE_PIO_UART1  PIOA
  #define BRD_ID_PIO_UART1    ID_PIOA
  #define BRD_UART1_RXD	      PIO_PA5C_URXD1
  #define BRD_UART1_TXD	      PIO_PA6C_UTXD1
  #define BRD_PERIPH_UART1    PIO_PERIPH_A
#else
  #error board.h file does not support the specified device.
#endif

/////////////////////////////////////////////////////////////




#endif // _CM4P2_VB_H
