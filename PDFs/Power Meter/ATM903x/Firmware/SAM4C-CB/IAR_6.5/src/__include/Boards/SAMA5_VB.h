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
#ifndef _SAMA5_VB_H
#define _SAMA5_VB_H

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
| DBGU (J8)            |  PB30=DRXD / PB31=DTXD |   
| USART0 (J11)         |  PD17=RXD0 / PD18=TXD0 |
|                      |  PD16=RTS0 / PD15=CTS0 |
| Blue LED (D1)        |  PA23 (1 => LED off)   |
| Green LED (D3)       |  PA21 (1 => LED off)   |
| Yellow LED (D4)      |  PD5  (1 => LED off)   |
| Power (red) LED (D2) |  PA22 (1 => LED On)    |
| Right click (BP3 )   |  PC19  (push => 0)     |
| Left click (BP4)     |  PD19  (push => 0)     |
=================================================
*----------------------------------------------------------------------------
*----------------------------------------------------------------------------
*/

#include "device.h"


/*----------------------------------------------------------------------------*/
/* -------- Leds Definition                                                   */
/*----------------------------------------------------------------------------*/
#define BRD_BASE_PIO_D1  PIOA
#define BRD_BASE_PIO_D2  PIOA
#define BRD_BASE_PIO_D3  PIOA
#define BRD_BASE_PIO_D4  PIOD
#define BRD_ID_PIO_D1    ID_PIOA
#define BRD_ID_PIO_D2    ID_PIOA
#define BRD_ID_PIO_D3    ID_PIOA
#define BRD_ID_PIO_D4    ID_PIOD
#define BRD_D1_MASK      (1<<23)  // PA23 D1
#define BRD_D2_MASK      (1<<22)  // PA22 POWER LED
#define BRD_D3_MASK      (1<<21)  // PA21 D3
#define BRD_D4_MASK      (1<<5)	  // PD5  D4

#define BRD_D1_POLARITY 0 // (0 => LED On)
#define BRD_D2_POLARITY 1 // (1 => LED On)
#define BRD_D3_POLARITY 0 // (0 => LED On)
#define BRD_D4_POLARITY 0 // (0 => LED On)

#define BRD_PIOA_LED_MASK  (BRD_D1_MASK|BRD_D2_MASK|BRD_D3_MASK)
#define BRD_PIOB_LED_MASK  (0) // none
#define BRD_PIOC_LED_MASK  (0) // none
#define BRD_PIOD_LED_MASK  (BRD_D4_MASK)
#define BRD_PIOE_LED_MASK  (0) // none

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
#define BRD_BASE_PIO_BP3   PIOC
#define BRD_BASE_PIO_BP4   PIOD
#define BRD_ID_PIO_BP3     ID_PIOC
#define BRD_ID_PIO_BP4     ID_PIOD
#define BRD_BP3_MASK       (1<<19)	// PC19  RIGHT CLICK 
#define BRD_BP4_MASK       (1<<19)	// PD19  LEFT CLICK

#define BRD_PIOA_INPUT_MASK    (0) // none
#define BRD_PIOB_INPUT_MASK    (0) // none
#define BRD_PIOC_INPUT_MASK    (BRD_BP3_MASK)
#define BRD_PIOD_INPUT_MASK    (BRD_BP4_MASK)
#define BRD_PIOE_INPUT_MASK    (0) // none

#define BRD_GET_BP3  pio_get(BRD_BASE_PIO_BP3,PIO_INPUT,BRD_BP3_MASK)
#define BRD_GET_BP4  pio_get(BRD_BASE_PIO_BP4,PIO_INPUT,BRD_BP4_MASK)
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
#define BRD_DBGU  (0xDB)  // DBGU (J8)
// UART0 = (0x10)
// UART1 = (0x11)
// ...
#define BRD_USART0   (20)  // USART0 (J11)
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




#endif // _SAMA5_VB_H
