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
#ifndef _SAM3S_VB_H
#define _SAM3S_VB_H

/*---------------------------------------------------------------------------
*    Board level definitions
*----------------------------------------------------------------------------
* Device compliance :
*
*
*----------------------------------------------------------------------------

// !!!!! SAM4S-VB definitions !!!!!!
--------------------------------------------
|    Board       |        PIO              |
____________________________________________
| UART0 (J10)    |  PA9=URXD0 / PA10=UTXD0 |   
| UART1 (J12)    |  PB2=URXD1 / PB3=UTXD1  |
| Gr LED (D3)    |  PA16 (1 => LED off)    |
| Gr LED (D4)    |  PA6  (1 => LED off)    |
| Power LED (D1) |  PA15 (1 => LED On)     |
| RClick (BP2)   |  PA2  (push => 0)       |
| LClick (BP3)   |  PA5  (push => 0)       |
============================================
*----------------------------------------------------------------------------
*----------------------------------------------------------------------------
*/

#include "device.h"



/*----------------------------------------------------------------------------*/
/* -------- Leds Definition                                                   */
/*----------------------------------------------------------------------------*/
#define BRD_BASE_PIO_D1  PIOA
#define BRD_BASE_PIO_D3  PIOA
#define BRD_BASE_PIO_D4  PIOA
#define BRD_ID_PIO_D1    ID_PIOA
#define BRD_ID_PIO_D3    ID_PIOA
#define BRD_ID_PIO_D4    ID_PIOA
#define BRD_D1_MASK      (1<<15)  /* PA15 POWER LED*/ 
#define BRD_D3_MASK      (1<<16)  /* PA16 D3 */
#define BRD_D4_MASK      (1<<6)	  /* PA6  D4 */

#define BRD_D1_POLARITY 1 // (1 => LED On)
#define BRD_D3_POLARITY 0 // (0 => LED On)
#define BRD_D4_POLARITY 0 // (0 => LED On)

#define BRD_BASE_PIO_ALL_LED  PIOA
#define BRD_ID_PIO_ALL_LED    ID_PIOA
#define BRD_ALL_LED_MASK      (BRD_D1_MASK|BRD_D3_MASK|BRD_D4_MASK)

#define BRD_TURN_ON_D1   pio_set(BRD_BASE_PIO_D1,BRD_D1_MASK)
#define BRD_TURN_OFF_D1  pio_clear(BRD_BASE_PIO_D1,BRD_D1_MASK)
#define BRD_TOGGLE_D1    pio_toggle(BRD_BASE_PIO_D1,BRD_D1_MASK)
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
#define BRD_BASE_PIO_BP2   PIOA
#define BRD_BASE_PIO_BP3   PIOA
#define BRD_ID_PIO_BP2     ID_PIOA
#define BRD_ID_PIO_BP3     ID_PIOA
#define BRD_BP2_MASK       (1<<2)	// PA2  RIGHT CLICK 
#define BRD_BP3_MASK       (1<<5)	// PA5  LEFT CLICK

#define BRD_BASE_PIO_ALL_INPUT  PIOA
#define BRD_ID_PIO_ALL_INPUT    ID_PIOA
#define BRD_ALL_INPUT_MASK      (BRD_BP2_MASK | BRD_BP3_MASK)
//#define BRD_ALL_INPUT_PINS {BRD_ALL_INPUT_MASK, BRD_BASE_PIO_INPUT, BRD_ID_PIO_INPUT, PIO_INPUT, PIO_PULLUP}

#define BRD_GET_BP2  pio_get(BRD_BASE_PIO_BP2,PIO_INPUT,BRD_BP2_MASK)
#define BRD_GET_BP3  pio_get(BRD_BASE_PIO_BP3,PIO_INPUT,BRD_BP3_MASK)
/*----------------------------------------------------------------------------*/


//------------------------------------------------------------------------------
// ---- Board Clocks ----
//-----------------------
#define BRD_SLOW_OSC               0         // NONE bypass through J7 connector
#define BRD_MAIN_OSC               0         // NONE bypass through J6 connector
#define BRD_SLOW_XTAL              32768     // Y3(R28 & R30)
#define BRD_MAIN_XTAL            12000000  // Y2(JP31 & JP32) or Y1(R21 & R24)
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// ---- Board Peripherals ----
//----------------------------
#define BRD_UART0 0 // UART0 on J10
#define BRD_UART1 1 // UART1 on J12
//------------------------------------------------------------------------------


/*----------------------------------------------------------------------------*/
/*---------------------------------------------------------*/
/* Peripherals Definition (Device dependant)               */
/*---------------------------------------------------------*/
// SAM3S ////////////////////////////////////////////////////
#if (SAM3S==1 || SAM3S8==1)
  #define BRD_BASE_PIO_UART0  PIOA
  #define BRD_ID_PIO_UART0    ID_PIOA
  #define BRD_UART0_RXD	      PIO_PA9A_URXD0
  #define BRD_UART0_TXD	      PIO_PA10A_UTXD0
  #define BRD_PERIPH_UART0    PIO_PERIPH_A
  #define BRD_BASE_PIO_UART1  PIOB
  #define BRD_ID_PIO_UART1    ID_PIOB
  #define BRD_UART1_RXD	      PIO_PB2A_URXD1
  #define BRD_UART1_TXD	      PIO_PB3A_UTXD1
  #define BRD_PERIPH_UART1    PIO_PERIPH_A
// SAM4S ////////////////////////////////////////////////////
#elif (SAM4S==1)
  #define BRD_BASE_PIO_UART0  PIOA
  #define BRD_ID_PIO_UART0    ID_PIOA
  #define BRD_UART0_RXD	      PIO_PA9A_URXD0
  #define BRD_UART0_TXD	      PIO_PA10A_UTXD0
  #define BRD_PERIPH_UART0    PIO_PERIPH_A
  #define BRD_BASE_PIO_UART1  PIOB
  #define BRD_ID_PIO_UART1    ID_PIOB
  #define BRD_UART1_RXD	      PIO_PB2A_URXD1
  #define BRD_UART1_TXD	      PIO_PB3A_UTXD1
  #define BRD_PERIPH_UART1    PIO_PERIPH_A
#else
  #error board.h file does not support the specified device.
#endif

/////////////////////////////////////////////////////////////





#endif /* _SAM3S_VB_H */
