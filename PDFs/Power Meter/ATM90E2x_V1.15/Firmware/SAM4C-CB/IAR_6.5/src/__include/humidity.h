#ifndef _HUMIDITY_H
#define _HUMIDITY_H



#include "Devices/packages.h"


//---- PIO default configuration -----------------------------------------------
#define HUM_PIO_DEFAULT_VAL    0  // 0 or 1
#define HUM_PIO_MULTIDRV       0  // 1=enable 0=disable
#define HUM_PIO_PULLUP         0  // 1=enable 0=disable
//------------------------------------------------------------------------------


//---- SAM3S -------------------------------------------------------------------
#if (SAM3S==1)
  #if   (DEVICE_PACKAGE == _QFP48_)
    #error Library does not support the specified package
  #elif (DEVICE_PACKAGE == _QFP64_)
    #include "Humidity/hum_sam3s_qfp64.h"
  #elif (DEVICE_PACKAGE == _QFP100_)
    #error Library does not support the specified package
  #elif (DEVICE_PACKAGE == _QFN48_)
    #error Library does not support the specified package
  #elif (DEVICE_PACKAGE == _QFN64_)
    #error Library does not support the specified package
  #elif (DEVICE_PACKAGE == _BGA100_)
    #error Library does not support the specified package
  #else
    #error Library does not support the specified package
  #endif
//---- SAM4S -------------------------------------------------------------------
#elif (SAM4S==1)
  #if   (DEVICE_PACKAGE == _QFP48_)
    #error Library does not support the specified package
  #elif (DEVICE_PACKAGE == _QFP64_)
    #include "Humidity/hum_sam3s_qfp64.h"
  #elif (DEVICE_PACKAGE == _QFP100_)
    #error Library does not support the specified package
  #elif (DEVICE_PACKAGE == _QFN48_)
    #error Library does not support the specified package
  #elif (DEVICE_PACKAGE == _QFN64_)
    #error Library does not support the specified package
  #elif (DEVICE_PACKAGE == _BGA100_)
    #error Library does not support the specified package
  #else
    #error Library does not support the specified package
  #endif
//---- SAM4S -------------------------------------------------------------------
#elif (SAMA5==1)
  #if   (DEVICE_PACKAGE == _BGA324_)
    #warning Humidity/hum_sama5_bga324.h is empty
    #include "Humidity/hum_sama5_bga324.h"
  #else
    #error Library does not support the specified package
  #endif
//---- Not implemented ---------------------------------------------------------
#else
  #error Library does not support the specified device.
#endif
//------------------------------------------------------------------------------




#endif //_HUMIDITY_H
