//*----------------------------------------------------------------------------
//*         ATMEL Microcontroller Software Support  -  ROUSSET  -
//*----------------------------------------------------------------------------
//* The software is delivered "AS IS" without warranty or condition of any
//* kind, either express, implied or statutory. This includes without
//* limitation any warranty or condition with respect to merchantability or
//* fitness for any particular purpose, or against the infringements of
//* intellectual property rights of others.
//*----------------------------------------------------------------------------
//* File Name           : v_core.c
//* Object              : mmu and cache control
//* Creation            : JPP   02/Mar/2007
//*----------------------------------------------------------------------------
#include "project.h"

// ---- General purpose include files
//#include <stdio.h> //IAR
#include "device.h"
#include "board.h"

#include "v_core.h"



extern unsigned int v_ARM_ReadControl( void)
{
  asm("mov r0, #0");
  // read CP15 register SCTLR System Control Register
  asm("MRC p15, 0, r0, c1, c0, 0");
  asm("bx lr");
}


extern void v_ARM_WriteControl(unsigned int ctl)
{
  // write CP15 register SCTLR System Control Register
  asm("MCR p15, 0, r0, c1, c0, 0");
  asm("bx lr");
}

#if (DEVICE_CORE_0_TYPE == CORE_TYPE_CA5)
unsigned int v_ARM_GetCPSR(void)
{
  asm("MRS R0, CPSR"); // Get current CPSR
  asm("bx lr");
}


void v_ARM_SetCPSR_bits(unsigned int mask)
{
  asm("MRS R1, CPSR");   // Get current CPSR
  asm("ORR R0, R0, R1"); // Calculate new CPSR value
  asm("MSR CPSR_c,R0");  // Set new value
  asm("bx lr");
}


void v_ARM_ClrCPSR_bits(unsigned int mask)
{
  asm("MRS R1, CPSR");   // Get current CPSR
  asm("MVN R0, R0");     // invert
  asm("AND R0, R0, R1"); // Calculate new CPSR value
  asm("MSR CPSR_c,R0");  // Set new value
  asm("bx lr");
}
#endif