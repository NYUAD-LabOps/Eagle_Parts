#ifndef _BOARD_H
#define _BOARD_H

#include "project.h"

//---- SAM3S / SAM4S / SAM7S ------------------------------------------------
#if defined SAM4S_VB_QFN64_LQFP64_REVA
  #include "Boards/SAM4S_VB.h"
#elif defined SAM4S_VB_SCH_BGA100_LQFP100_REVA
  #include "Boards/SAM4S_VB.h"
#elif defined SAM4S_VB_QFP48_REVA
  #include "Boards/SAM4S_VB.h"
#elif defined SAM4S_VB_QFN48_REVA
  #include "Boards/SAM4S_VB.h"
#elif defined SAM3S_VB_BGA100_LQFP100_REVB
  #include "Boards/SAM3S_VB.h"
#elif defined POE09_785_001
  #include "Boards/SAM4S_HTB.h"
#elif defined TEMP_63904_BIB_REF
  #include "Boards/SAM4S_QFP100_HTB.h"
//---- SAMA5 ----------------------------------------------------------------
#elif defined SAMA5_VB_BGA324_REVA
  #include "Boards/SAMA5_VB.h"
#elif defined SAMA5_BIB_BGA324
  #include "Boards/SAMA5_BIB.h"
//---------------------------------------------------------------------------
//---- CM4P2 ----------------------------------------------------------------
#elif defined CM4P2_VB_REVA
  #include "Boards/CM4P2_BGA144_VB.h"
//---- SAM4C ------------------------------------------------
#elif defined SAM4C_VB_LQFP100_REVA  
  #include "Boards/SAM4C_VB_V_Area.h"
//---------------------------------------------------------------------------
#else
  #error Library does not support the specified board.
#endif
//---------------------------------------------------------------------------

#endif