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
#ifndef _SAMA5_BIB_H
#define _SAMA5_BIB_H

/*---------------------------------------------------------------------------
*    Board level definitions
*----------------------------------------------------------------------------
* Device compliance : SAMA5xx
*
*
*----------------------------------------------------------------------------
-------------------------------------------------
|    Board             |        PIO             |
_________________________________________________
| Green LED (D4)       |  PD5  (1 => LED off)   |
| Right click (BP3 )   |  PC19                  |
=================================================
*----------------------------------------------------------------------------
*----------------------------------------------------------------------------
*/


//signals S6 & S2 => inputs


#include "device.h"


/*----------------------------------------------------------------------------*/
/* -------- Leds Definition                                                   */
/*----------------------------------------------------------------------------*/
#define BRD_BASE_PIO_D4  PIOD

#define BRD_ID_PIO_D4    ID_PIOD

#define BRD_D4_MASK      (1<<5)	  // PD5  D4

#define BRD_D4_POLARITY 0 // (0 => LED On)

#define BRD_PIOA_LED_MASK  (0) // none
#define BRD_PIOB_LED_MASK  (0) // none
#define BRD_PIOC_LED_MASK  (0) // none
#define BRD_PIOD_LED_MASK  (BRD_D4_MASK)
#define BRD_PIOE_LED_MASK  (0) // none

#define BRD_TURN_ON_D4   pio_clear(BRD_BASE_PIO_D4,BRD_D4_MASK)
#define BRD_TURN_OFF_D4  pio_set(BRD_BASE_PIO_D4,BRD_D4_MASK)
#define BRD_TOGGLE_D4    pio_toggle(BRD_BASE_PIO_D4,BRD_D4_MASK)
/*----------------------------------------------------------------------------*/



/*----------------------------------------------------------------------------*/
/* -------- Inputs Definition                                                 */
/*----------------------------------------------------------------------------*/
#define BRD_BASE_PIO_S5  (PIOD)
#define BRD_ID_PIO_S5    (ID_PIOD)
#define BRD_S5_MASK      (1<<19)	// PD19 VB LEFT CLICK

// Warning: unprotected common input on SAM5 BIB revA!!!
#define BRD_BASE_PIO_S6  (PIOC)
#define BRD_ID_PIO_S6    (ID_PIOC)
#define BRD_S6_MASK      (1<<19)	// PC19 VB RIGHT CLICK 

// Warning: unprotected common input on SAM5 BIB revA!!!
#define BRD_BASE_PIO_S234  (PIOD)
#define BRD_ID_PIO_S234    (ID_PIOD)
#define BRD_S234_MASK      (1<<21)

#define BRD_PIOA_INPUT_MASK  (0) // none
#define BRD_PIOB_INPUT_MASK  (0) // none
#define BRD_PIOC_INPUT_MASK  (BRD_S6_MASK) // unprotected common input !!!
#define BRD_PIOD_INPUT_MASK  (BRD_S5_MASK | BRD_S234_MASK) // S234 unprotected
#define BRD_PIOE_INPUT_MASK  (0) // none

#define BRD_GET_S234_INPUT  pio_get(BRD_BASE_PIO_S234,PIO_INPUT,BRD_S234_MASK)
#define BRD_GET_S5_INPUT  pio_get(BRD_BASE_PIO_S5,PIO_INPUT,BRD_S5_MASK)
#define BRD_GET_S6_INPUT  pio_get(BRD_BASE_PIO_S6,PIO_INPUT,BRD_S6_MASK)
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* -------- Board Clocks                                                      */
/*----------------------------------------------------------------------------*/
#define BRD_SLOW_OSC     0         // NONE bypass through J4 connector
#define BRD_MAIN_OSC     0         // NONE bypass through J3 connector
#define BRD_SLOW_XTAL    32768     // Y1(R49 & R50)
#define BRD_MAIN_XTAL    12000000  // Y2(R47 & R51)


/*----------------------------------------------------------------------------*/
/* -------- Board available serial links                                      */
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* -------- Board available serial links                                      */
/*----------------------------------------------------------------------------*/
//#define BRD_DBGU  (0xDB)  // DBGU (J8)
// UART0 = (0x10)
// UART1 = (0x11)
// ...
//#define BRD_USART0   (20)  // USART0 (J11)
// USART1 = (0x21)
// USART2 = (0x22)
// ...


/*----------------------------------------------------------------------------*/
/*---------------------------------------------------------*/
/* Peripherals Definition (Device dependant)               */
/*---------------------------------------------------------*/
// SAMA5 ////////////////////////////////////////////////////
#if (SAMA5==1)
// ---- DBGU on J8 -------------------------------------
  #define BRD_BASE_PIO_DBGU   PIOB
  #define BRD_ID_PIO_DBGU     ID_PIOB
  #define BRD_DBGU_RXD	      PIO_PB30A_DRXD
  #define BRD_DBGU_TXD	      PIO_PB31A_DTXD
  #define BRD_PERIPH_DBGU     PIO_PERIPH_A
// ---- USART0 on J11 ----------------------------------
  #define BRD_BASE_PIO_USART0  PIOD
  #define BRD_ID_PIO_USART0    ID_PIOD
  #define BRD_USART0_RXD       PIO_PD17A_RXD0
  #define BRD_USART0_TXD       PIO_PD18A_TXD0
  #define BRD_USART0_RTS0      PIO_PD16A_RTS0
  #define BRD_USART0_CTS0      PIO_PD15A_CTS0
  #define BRD_PERIPH_USART0    PIO_PERIPH_A
/////////////////////////////////////////////////////////////
//#elif (SAMA5yy==1)
#else
  #error board.h file does not support the specified device.
#endif

/////////////////////////////////////////////////////////////




#endif // _SAMA5_BIB_H