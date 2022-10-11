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
#ifndef _SAM4S_FEATURES_16C_H
#define _SAM4S_FEATURES_16C_H



//------------------------------------------------------------------------------
// ----      Device Definitions          ----
//-------------------------------------------
#define DEVICE_HAS_EFC1      1
#define DEVICE_HAS_PIOC      1
#define DEVICE_HAS_TC1       1 // channels 3-5
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// ----        IP Definitions            ----
//-------------------------------------------
//

// ---- ADC ---------------------------------
#define ADC_CHANNELS    (16)
//-------------------------------------------

// ---- PIO ---------------------------------
#define PIOC_HAS_PDC              (0)
//-------------------------------------------

// ---- TC  ---------------------------------
#define TC_CHANNELS       (6)
//--------------------------------------------
#define TC1_BMR_HAS_FILTER  TC_BMR_HAS_FILTER
//--------------------------------------------
#define TC1_HAS_SMMR  TC_HAS_SMMR
//--------------------------------------------
#define TC1_HAS_QDEC  TC_HAS_QDEC
//--------------------------------------------
#define TC1_HAS_WR_PROTECT  TC_HAS_WR_PROTECT
//-------------------------------------------
#define TC1_HAS_PDC  TC_HAS_PDC
//-------------------------------------------
//...
//-------------------------------------------
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
#endif //_SAM4S_FEATURES_16C_H
