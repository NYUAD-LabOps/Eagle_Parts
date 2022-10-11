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
#ifndef _SAM4C_VB_H
#define _SAM4C_VB_H

/*---------------------------------------------------------------------------
*    Board level definitions
*----------------------------------------------------------------------------
* Device compliance : SAM4C
*
*
*----------------------------------------------------------------------------
--------------------------------------------
|    Board       |        PIO              |
____________________________________________
| UART0 (J7)     |  PB4=URXD0 / PB5=UTXD0 |   
| UART1 (J8)     |  PC1=URXD1 / PC0=UTXD1  |
| Gr LED (D3)    |  PB15 (1 => LED off)    |
| Gr LED (D4)    |  PC6  (1 => LED off)    |
| Power LED (D5) |  VDDMAIN                |
============================================
*----------------------------------------------------------------------------
*----------------------------------------------------------------------------
*/

#include "device.h"

#define BOARD_NAME "SAM4CMP_DB"

/** Board oscillator settings */
#define BOARD_FREQ_SLCK_XTAL           (32768U)
#define BOARD_FREQ_SLCK_BYPASS         (32768U)

//gary: changed from 8192 //Loc
#define BOARD_FREQ_MAINCK_XTAL       (8192000U)  // used to be (12000000U)
#define BOARD_FREQ_MAINCK_BYPASS     (8000000U)  // SAM4C-EK has 8MHz


/** Master clock frequency */
#define BOARD_MCK                 (102400000UL) // used to be (CHIP_FREQ_CPU_MAX)

/*----------------------------------------------------------------------------*/
/* -------- Leds Definition                                                   */
/*----------------------------------------------------------------------------*/

#define BRD_BASE_PIO_D3  PIOB
#define BRD_BASE_PIO_D4  PIOC
#define BRD_ID_PIO_D3    ID_PIOB
#define BRD_ID_PIO_D4    ID_PIOC

#define BRD_D3_MASK      (1<<15)  /* PB15 D3 */
#define BRD_D4_MASK      (1<<6)	  /* PC6  D4 */


#define BRD_D3_POLARITY 0 // (0 => LED On)
#define BRD_D4_POLARITY 0 // (0 => LED On)



#define BRD_PIOA_LED_MASK  (0)
#define BRD_PIOB_LED_MASK  (BRD_D3_MASK) 
#define BRD_PIOC_LED_MASK  (BRD_D4_MASK) 
#define BRD_PIOD_LED_MASK  (0) // none
#define BRD_PIOE_LED_MASK  (0) // none


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
//#define BRD_BASE_PIO_BP2   PIOA
//#define BRD_BASE_PIO_BP3   PIOA
//#define BRD_ID_PIO_BP2     ID_PIOA
//#define BRD_ID_PIO_BP3     ID_PIOA
//#define BRD_BP2_MASK       (1<<2)	// PA2  RIGHT CLICK 
//#define BRD_BP3_MASK       (1<<5)	// PA5  LEFT CLICK

//#define BRD_BASE_PIO_ALL_INPUT  PIOA ///////////////////////////////////////////
//#define BRD_ID_PIO_ALL_INPUT    ID_PIOA ////////////////////////////////////////
//#define BRD_ALL_INPUT_MASK      (BRD_BP2_MASK | BRD_BP3_MASK) //////////////////

//#define BRD_PIOA_INPUT_MASK    (BRD_BP2_MASK | BRD_BP3_MASK)
//#define BRD_PIOB_INPUT_MASK    (0) // none
//#define BRD_PIOC_INPUT_MASK    (0) // none
//#define BRD_PIOD_INPUT_MASK    (0) // none
//#define BRD_PIOE_INPUT_MASK    (0) // none


//#define BRD_GET_BP2  pio_get(BRD_BASE_PIO_BP2,PIO_INPUT,BRD_BP2_MASK)
//#define BRD_GET_BP3  pio_get(BRD_BASE_PIO_BP3,PIO_INPUT,BRD_BP3_MASK)
/*----------------------------------------------------------------------------*/


//------------------------------------------------------------------------------
// ---- Board Clocks ----
//-----------------------
#define BRD_SLOW_OSC               0         //
#define BRD_MAIN_OSC               0         //
#define BRD_SLOW_XTAL              32768     // Y3(R35 & R36)

#define BRD_MAIN_XTAL            8192000  // Y4((R40 & R44)

//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// ---- Board Peripherals ----
//----------------------------
#define BRD_UART0 1 // UART0 on J7
#define BRD_UART1 0 // UART1 on J8
//------------------------------------------------------------------------------


/*----------------------------------------------------------------------------*/
/*---------------------------------------------------------*/
/* Peripherals Definition (Device dependant)               */
/*---------------------------------------------------------*/

// SAM4C ////////////////////////////////////////////////////
//AYI to be checked PIO Periph ???
#if (SAM4C==1)
  #define BRD_BASE_PIO_UART0  PIOB
  #define BRD_ID_PIO_UART0    ID_PIOB
  #define BRD_UART0_RXD	      PIO_PB4A_URXD0
  #define BRD_UART0_TXD	      PIO_PB5A_UTXD0 
  #define BRD_PERIPH_UART0    PIO_PERIPH_A 
  #define BRD_BASE_PIO_UART1  PIOC
  #define BRD_ID_PIO_UART1    ID_PIOC
  #define BRD_UART1_RXD	      PIO_PC1A_URXD1
  #define BRD_UART1_TXD	      PIO_PC0A_UTXD1
  #define BRD_PERIPH_UART1    PIO_PERIPH_A

#else
  #error board.h file does not support the specified device.
#endif

/////////////////////////////////////////////////////////////



#endif /* _SAM4C_VB_H */
