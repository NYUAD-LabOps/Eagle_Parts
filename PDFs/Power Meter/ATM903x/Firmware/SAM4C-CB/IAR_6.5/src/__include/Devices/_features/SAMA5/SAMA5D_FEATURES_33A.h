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
#ifndef _SAMA5D_FEATURES_33A_H
#define _SAMA5D_FEATURES_33A_H
//------------------------------------------------------------------------------



//------------------------------------------------------------------------------
// ----      Device Definitions          ----
//-------------------------------------------
#define DEVICE_HAS_CAN0     0
#define DEVICE_HAS_CAN1     0
#define DEVICE_HAS_EMAC     0
#define DEVICE_HAS_GMAC     1
#define DEVICE_HAS_HSMCI2   0
#define DEVICE_HAS_LCDC     1
#define DEVICE_HAS_TC1      0
#define DEVICE_HAS_UART0    0
#define DEVICE_HAS_UART1    0
//...
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// ----        IP Definitions            ----
//-------------------------------------------
//

// ---- HSMCI ---------------------------------
//#define HSMCI2_HAS_PDC    (HSMCI_HAS_PDC)
//--------------------------------------------

// ---- TC  ---------------------------------
#define TC_CHANNELS       (3)
//--------------------------------------------
//#define TC1_BMR_HAS_FILTER  TC_BMR_HAS_FILTER
//--------------------------------------------
//#define TC1_HAS_SMMR  TC_HAS_SMMR
//--------------------------------------------
//#define TC1_HAS_QDEC  TC_HAS_QDEC
//--------------------------------------------
//#define TC1_HAS_WR_PROTECT  TC_HAS_WR_PROTECT
//-------------------------------------------
//#define TC1_HAS_PDC  TC_HAS_PDC
//-------------------------------------------
//...
//-------------------------------------------

// ---- UART --------------------------------
//#define UART_HAS_PDC     (1)
//#define UART0_HAS_PDC    (UART_HAS_PDC)
//#define UART1_HAS_PDC    (UART_HAS_PDC)
//-------------------------------------------
//
//------------------------------------------------------------------------------
#endif //_SAMA5D_FEATURES_33A_H
