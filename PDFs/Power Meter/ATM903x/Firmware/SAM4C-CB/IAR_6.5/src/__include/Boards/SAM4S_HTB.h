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
#ifndef _SAM4S_HTB_H
#define _SAM4S_HTB_H

/*---------------------------------------------------------------------------
*    Board level definitions
*----------------------------------------------------------------------------
* Device compliance : SAM3S1BA-AU
*/
#include <device.h>

/*
*----------------------------------------------------------------------------
--------------------------------------------
|    Board        |        PIO             |
____________________________________________
| PASS FLAG (LD1) |  PA30 (1 => LED On)    |
| B5 input        |  PA29 (10K PU 3V3)     |
============================================
*----------------------------------------------------------------------------
*----------------------------------------------------------------------------*/



/*----------------------------------------------------------------------------*/
/* -------- Leds Definition                                                   */
/*----------------------------------------------------------------------------*/
#define BRD_BASE_PIO_LD1  PIOA
#define BRD_ID_PIO_LD1    ID_PIOA
#define BRD_LD1_MASK  (1<<30) // PA30 PASS FLAG

#define BRD_LD1_POLARITY 1

#define BRD_BASE_PIO_ALL_LED  PIOA
#define BRD_ID_PIO_ALL_LED    ID_PIOA
#define BRD_ALL_LED_MASK (BRD_LD1_MASK)

//#define BRD_LED_POLARITY(led) led ## _POLARITY

#define BRD_TURN_ON_LD1   pio_set(BRD_BASE_PIO_LD1,BRD_LD1_MASK)
#define BRD_TURN_OFF_LD1  pio_clear(BRD_BASE_PIO_LD1,BRD_LD1_MASK)
#define BRD_TOGGLE_LD1    pio_toggle(BRD_BASE_PIO_LD1,BRD_LD1_MASK)
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* -------- Inputs Definition                                                 */
/*----------------------------------------------------------------------------*/
#define BRD_BASE_PIO_B5   PIOA
#define BRD_ID_PIO_B5     ID_PIOA
#define BRD_B5_MASK  (1<<29) // PA29 B5 input (10K ext PU on 3V3)

#define BRD_BASE_PIO_ALL_INPUT  PIOA
#define BRD_ID_PIO_ALL_INPUT    ID_PIOA
#define BRD_ALL_INPUT_MASK (BRD_B5_MASK)

#define BRD_GET_B5_INPUT  pio_get(BRD_BASE_PIO_B5,PIO_INPUT,BRD_B5_MASK)
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* -------- Board Clocks                                                      */
/*----------------------------------------------------------------------------*/
#define BRD_SLOW_OSC               0         // NONE
#define BRD_MAIN_OSC               3000000   // OSC1 / B1
#define BRD_SLOW_XTAL              0         // NONE
#define BRD_MAIN_XTAL              0         // NONE
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/*---------------------------------------------------------*/
/* Peripherals Definition (Device dependant)               */
/*---------------------------------------------------------*/
// SAM3S ////////////////////////////////////////////////////
//#ifdef sam3s
  //#define
// SAM4S ////////////////////////////////////////////////////
//#elif defined sam4s
  //#define
//#else
//  #error board.h file does not support the specified device.
//#endif
/*----------------------------------------------------------------------------*/
/////////////////////////////////////////////////////////////




#endif /* _SAM4S_HTB_H */
