//*----------------------------------------------------------------------------
//*         ATMEL Microcontroller Software Support  -  ROUSSET  -
//*----------------------------------------------------------------------------
//* The software is delivered "AS IS" without warranty or condition of any
//* kind, either express, implied or statutory. This includes without
//* limitation any warranty or condition with respect to merchantability or
//* fitness for any particular purpose, or against the infringements of
//* intellectual property rights of others.
//*----------------------------------------------------------------------------
//* File Name           : v_mmu.c
//* Object              : mmu and cache control
//* Creation            : JPP   02/Mar/2007
//*----------------------------------------------------------------------------

#include "v_mmu.h"


// Include Standard files



//*----------------------------------------------------------------------------
//* \fn    AT91F_StatusICache
//* \brief Reset I Cache (Should be run from a non cachable area)
//*----------------------------------------------------------------------------
unsigned int v_StatusICache(void)
{
 unsigned int ctl;

  //ctl = AT91F_ARM_ReadControl();
  ctl = v_ARM_ReadControl();
  if  ((ctl & (1 << 12)) == (1 << 12)) return 1;
  else return 0;
}
//*----------------------------------------------------------------------------
//* \fn    AT91F_EnableICache
//* \brief Enable I Cache
//*----------------------------------------------------------------------------
void v_EnableICache(void)
{
 unsigned int ctl;

  //ctl = AT91F_ARM_ReadControl();
  ctl = v_ARM_ReadControl();
  ctl |= (1 << 12);
  //AT91F_ARM_WriteControl(ctl);
  v_ARM_WriteControl(ctl);
}

//*----------------------------------------------------------------------------
//* \fn    AT91F_DisableICache
//* \brief Disable I Cache
//*----------------------------------------------------------------------------
void v_DisableICache(void)
{
 unsigned int ctl;

   //ctl = AT91F_ARM_ReadControl();
  ctl = v_ARM_ReadControl();
  ctl &= ~(1 << 12);
  //AT91F_ARM_WriteControl(ctl);
  v_ARM_WriteControl(ctl);
}


