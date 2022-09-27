/*! \file *********************************************************************
For ASF libs compliance
*******************************************************************************/

#ifndef __EXCEPTIONS_H
#define __EXCEPTIONS_H

#include "project.h"
#include "board.h"

//Gary
#if (SAM4C==1)
  #include "Exceptions/SAM4C_Exceptions.h" 
//------------------------------------------------------------------------------
#elif (SAM3S==1 || SAM3S8==1)
  #include "Exceptions/SAM3S_Exceptions.h"


#elif (SAM4S==1)
  #include "Exceptions/SAM3S_Exceptions.h" // identical to SAM3S
#elif (SAM4N==1)
  #include "Exceptions/SAM3S_Exceptions.h" // identical to SAM3S
#elif (CM4P2==1)
  #include "Exceptions/CM4P2_Exceptions.h" // identical to SAM3S
#elif (SAMA5==1)
  #include "Exceptions/SAMA5_Exceptions.h"

//------------------------------------------------------------------------------
#else
  #error Library does not support the specified device.
#endif



#endif  // __EXCEPTIONS_H
