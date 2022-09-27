/*----------------------------------------------------------------------------
*         ATMEL Microcontroller Software Support  -  ROUSSET  -
*----------------------------------------------------------------------------
* The software is delivered "AS IS" without warranty or condition of any
* kind, either express, implied or statutory. This includes without
* limitation any warranty or condition with respect to merchantability or
* fitness for any particular purpose, or against the infringements of
* intellectual property rights of others.
*----------------------------------------------------------------------------
* File Name           : features_sama5xxxxx.h
* Object              : ATSAM Definition File.
*
* Creation            : Sept/2011
*----------------------------------------------------------------------------
*/
#ifndef _SAM4N_FEATURES_16B_H
#define _SAM4N_FEATURES_16B_H



//------------------------------------------------------------------------------
// ----      Device Definitions          ----
//-------------------------------------------
#define DEVICE_HAS_PIOC      0
#define DEVICE_HAS_USART1    1
#define DEVICE_HAS_USART2    0
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// ----        IP Definitions            ----
//-------------------------------------------
//

// ---- ADC ---------------------------------
#define ADC_CHANNELS    (11)
//-------------------------------------------

// ---- PIO ---------------------------------
//#define PIOC_HAS_PDC    (0)
//-------------------------------------------

// ---- USART -------------------------------
#define USART1_HAS_PDC   (USART_HAS_PDC)
//#define USART2_HAS_PDC   (USART_HAS_PDC)
//-------------------------------------------
//...
//-------------------------------------------
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
#endif //_SAM4N_FEATURES_16B_H
