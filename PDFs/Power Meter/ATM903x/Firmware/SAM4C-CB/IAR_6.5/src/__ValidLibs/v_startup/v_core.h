//*----------------------------------------------------------------------------
//*         ATMEL Microcontroller Software Support  -  ROUSSET  -
//*----------------------------------------------------------------------------
//* The software is delivered "AS IS" without warranty or condition of any
//* kind, either express, implied or statutory. This includes without
//* limitation any warranty or condition with respect to merchantability or
//* fitness for any particular purpose, or against the infringements of
//* intellectual property rights of others.
//*----------------------------------------------------------------------------
//* File Name           : v_core.h
//* Object              : mmu and cache control
//* Creation            : JPP   02/Mar/2007
//*----------------------------------------------------------------------------

#ifndef _CORE_H
#define _CORE_H



// Include Standard files




// Define Assembly funct
unsigned int v_ARM_ReadControl( void);
void v_ARM_WriteControl(unsigned int ctl);
#if (DEVICE_CORE_0_TYPE == CORE_TYPE_CA5)
  unsigned int v_ARM_GetCPSR(void);
  void v_ARM_SetCPSR_bits(unsigned int mask);
  void v_ARM_ClrCPSR_bits(unsigned int mask);
#endif

// Core register definitions
#define CPSR_MASK_IRQ 0x00000080
#define CPSR_MASK_FIQ 0x00000040



#endif //_CORE_H