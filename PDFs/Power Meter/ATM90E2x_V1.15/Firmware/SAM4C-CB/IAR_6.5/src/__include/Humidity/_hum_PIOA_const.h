#ifndef _HUM_PIOA_CONST
#define _HUM_PIOA_CONST



//------------------------------------------------------------------------------
#define HUM_PIOA_MASK(val) ((HUM_PIOA_ ## val)<<(val))
#define HUM_PIOA_CLEAR_MASK (~HUM_PIOA_SET_MASK)
#define HUM_PIOA_SET_MASK   ( HUM_PIOA_MASK(0)  | HUM_PIOA_MASK(1)   \
                            | HUM_PIOA_MASK(2)  | HUM_PIOA_MASK(3)   \
                            | HUM_PIOA_MASK(4)  | HUM_PIOA_MASK(5)   \
                            | HUM_PIOA_MASK(6)  | HUM_PIOA_MASK(7)   \
                            | HUM_PIOA_MASK(8)  | HUM_PIOA_MASK(9)   \
                            | HUM_PIOA_MASK(10) | HUM_PIOA_MASK(11)  \
                            | HUM_PIOA_MASK(12) | HUM_PIOA_MASK(13)  \
                            | HUM_PIOA_MASK(14) | HUM_PIOA_MASK(15)  \
                            | HUM_PIOA_MASK(16) | HUM_PIOA_MASK(17)  \
                            | HUM_PIOA_MASK(18) | HUM_PIOA_MASK(19)  \
                            | HUM_PIOA_MASK(20) | HUM_PIOA_MASK(21)  \
                            | HUM_PIOA_MASK(22) | HUM_PIOA_MASK(23)  \
                            | HUM_PIOA_MASK(24) | HUM_PIOA_MASK(25)  \
                            | HUM_PIOA_MASK(26) | HUM_PIOA_MASK(27)  \
                            | HUM_PIOA_MASK(28) | HUM_PIOA_MASK(29)  \
                            | HUM_PIOA_MASK(30) | HUM_PIOA_MASK(31)  )
//---------------------------
#ifndef HUM_PIOA_0
  #ifndef PIO_PA0
    #define HUM_PIOA_ 0
  #endif // PIO_PA0
#endif //HUM_PIOA_0
//---------------------------
#ifndef HUM_PIOA_1
  #ifndef PIO_PA1
    #define HUM_PIOA_1 0
  #endif // PIO_PA1
#endif //HUM_PIOA_1
//---------------------------
#ifndef HUM_PIOA_2
  #ifndef PIO_PA2
    #define HUM_PIOA_2 0
  #endif // PIO_PA2
#endif //HUM_PIOA_2
//---------------------------
#ifndef HUM_PIOA_3
  #ifndef PIO_PA3
    #define HUM_PIOA_3 0
  #endif // PIO_PA3
#endif //HUM_PIOA_3
//---------------------------
#ifndef HUM_PIOA_4
  #ifndef PIO_PA4
    #define HUM_PIOA_4 0
  #endif // PIO_PA4
#endif //HUM_PIOA_4
//---------------------------
#ifndef HUM_PIOA_5
  #ifndef PIO_PA5
    #define HUM_PIOA_5 0
  #endif // PIO_PA5
#endif //HUM_PIOA_5
//---------------------------
#ifndef HUM_PIOA_6
  #ifndef PIO_PA6
    #define HUM_PIOA_6 0
  #endif // PIO_PA6
#endif //HUM_PIOA_6
//---------------------------
#ifndef HUM_PIOA_7
  #ifndef PIO_PA7
    #define HUM_PIOA_7 0
  #endif // PIO_PA7
#endif //HUM_PIOA_7
//---------------------------
#ifndef HUM_PIOA_8
  #ifndef PIO_PA8
    #define HUM_PIOA_8 0
  #endif // PIO_PA8
#endif //HUM_PIOA_8
//---------------------------
#ifndef HUM_PIOA_9
  #ifndef PIO_PA9
    #define HUM_PIOA_9 0
  #endif // PIO_PA9
#endif //HUM_PIOA_9
//---------------------------
#ifndef HUM_PIOA_10
  #ifndef PIO_PA10
    #define HUM_PIOA_10 0
  #endif // PIO_PA10
#endif //HUM_PIOA_10
//---------------------------
#ifndef HUM_PIOA_11
  #ifndef PIO_PA11
    #define HUM_PIOA_11 0
  #endif // PIO_PA11
#endif //HUM_PIOA_11
//---------------------------
#ifndef HUM_PIOA_12
  #ifndef PIO_PA12
    #define HUM_PIOA_12 0
  #endif // PIO_PA12
#endif //HUM_PIOA_12
//---------------------------
#ifndef HUM_PIOA_13
  #ifndef PIO_PA13
    #define HUM_PIOA_13 0
  #endif // PIO_PA13
#endif //HUM_PIOA_13
//---------------------------
#ifndef HUM_PIOA_14
  #ifndef PIO_PA14
    #define HUM_PIOA_14 0
  #endif // PIO_PA14
#endif //HUM_PIOA_14
//---------------------------
#ifndef HUM_PIOA_15
  #ifndef PIO_PA15
    #define HUM_PIOA_15 0
  #endif // PIO_PA15
#endif //HUM_PIOA_15
//---------------------------
#ifndef HUM_PIOA_16
  #ifndef PIO_PA16
    #define HUM_PIOA_16 0
  #endif // PIO_PA16
#endif //HUM_PIOA_16
//---------------------------
#ifndef HUM_PIOA_17
  #ifndef PIO_PA17
    #define HUM_PIOA_17 0
  #endif // PIO_PA17
#endif //HUM_PIOA_17
//---------------------------
#ifndef HUM_PIOA_18
  #ifndef PIO_PA18
    #define HUM_PIOA_18 0
  #endif // PIO_PA18
#endif //HUM_PIOA_18
//---------------------------
#ifndef HUM_PIOA_19
  #ifndef PIO_PA19
    #define HUM_PIOA_19 0
  #endif // PIO_PA19
#endif //HUM_PIOA_19
//---------------------------
#ifndef HUM_PIOA_20
  #ifndef PIO_PA20
    #define HUM_PIOA_20 0
  #endif // PIO_PA20
#endif //HUM_PIOA_20
//---------------------------
#ifndef HUM_PIOA_21
  #ifndef PIO_PA21
    #define HUM_PIOA_21 0
  #endif // PIO_PA21
#endif //HUM_PIOA_21
//---------------------------
#ifndef HUM_PIOA_22
  #ifndef PIO_PA22
    #define HUM_PIOA_22 0
  #endif // PIO_PA22
#endif //HUM_PIOA_22
//---------------------------
#ifndef HUM_PIOA_23
  #ifndef PIO_PA23
    #define HUM_PIOA_23 0
  #endif // PIO_PA23
#endif //HUM_PIOA_23
//---------------------------
#ifndef HUM_PIOA_24
  #ifndef PIO_PA24
    #define HUM_PIOA_24 0
  #endif // PIO_PA24
#endif //HUM_PIOA_24
//---------------------------
#ifndef HUM_PIOA_25
  #ifndef PIO_PA25
    #define HUM_PIOA_25 0
  #endif // PIO_PA25
#endif //HUM_PIOA_25
//---------------------------
#ifndef HUM_PIOA_26
  #ifndef PIO_PA26
    #define HUM_PIOA_26 0
  #endif // PIO_PA26
#endif //HUM_PIOA_26
//---------------------------
#ifndef HUM_PIOA_27
  #ifndef PIO_PA27
    #define HUM_PIOA_27 0
  #endif // PIO_PA27
#endif //HUM_PIOA_27
//---------------------------
#ifndef HUM_PIOA_28
  #ifndef PIO_PA28
    #define HUM_PIOA_28 0
  #endif // PIO_PA28
#endif //HUM_PIOA_28
//---------------------------
#ifndef HUM_PIOA_29
  #ifndef PIO_PA29
    #define HUM_PIOA_29 0
  #endif // PIO_PA29
#endif //HUM_PIOA_29
//---------------------------
#ifndef HUM_PIOA_30
  #ifndef PIO_PA30
    #define HUM_PIOA_30 0
  #endif // PIO_PA30
#endif //HUM_PIOA_30
//---------------------------
#ifndef HUM_PIOA_31
  #ifndef PIO_PA31
    #define HUM_PIOA_31 0
  #endif // PIO_PA31
#endif //HUM_PIOA_31
//---------------------------

//------------------------------------------------------------------------------



#endif //_HUM_PIOA_CONST
