#ifndef _PACKAGES_H
#define _PACKAGES_H



//---- Packages ----------------------------------------------------------------
#define _QFP48_    1048
#define _QFP64_    1064
#define _QFP100_   1100
#define _QFN48_    2048
#define _QFN64_    2064
#define _BGA100_   3100
#define _BGA144_   3144
#define _BGA324_   3324
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
#if   (DEVICE_PACKAGE == _QFP48_)
  #define _DEVICE_PIN_COUNT_ 48
#elif (DEVICE_PACKAGE == _QFP64_)
  #define _DEVICE_PIN_COUNT_ 64
#elif (DEVICE_PACKAGE == _QFP100_)
  #define _DEVICE_PIN_COUNT_ 100
#elif (DEVICE_PACKAGE == _QFN48_)
  #define _DEVICE_PIN_COUNT_ 48
#elif (DEVICE_PACKAGE == _QFN64_)
  #define _DEVICE_PIN_COUNT_ 64
#elif (DEVICE_PACKAGE == _BGA100_)
  #define _DEVICE_PIN_COUNT_ 100
#elif (DEVICE_PACKAGE == _BGA144_)
  #define _DEVICE_PIN_COUNT_ 144
#elif (DEVICE_PACKAGE == _BGA324_)
  #define _DEVICE_PIN_COUNT_ 324
#else
  #error Library does not support the specified package
#endif
//------------------------------------------------------------------------------





#endif //_PACKAGES_H
