//*----------------------------------------------------------------------------
//*         ATMEL Microcontroller Software Support  -  ROUSSET  -
//*----------------------------------------------------------------------------
//* The software is delivered "AS IS" without warranty or condition of any
//* kind, either express, implied or statutory. This includes without
//* limitation any warranty or condition with respect to merchantability or
//* fitness for any particular purpose, or against the infringements of
//* intellectual property rights of others.
//*----------------------------------------------------------------------------
//* File Name           : v_mmu.h
//* Object              : mmu and cache control
//* Creation            : JPP   02/Mar/2007
//*----------------------------------------------------------------------------

#ifndef _MMU_H
#define _MMU_H



// ---- General purpose include files
#include "v_core.h"


// Include Standard files


// Functions prototypes
extern unsigned int v_StatusICache(void);
extern void v_EnableICache(void);
extern void v_DisableICache(void);



#endif //_MMU_H