#ifndef _HUM_PIOD_CONST
#define _HUM_PIOD_CONST



//------------------------------------------------------------------------------
#define HUM_PIOD_MASK(val) ((HUM_PIOD_ ## val)<<(val))
#define HUM_PIOD_CLEAR_MASK (~HUM_PIOD_SET_MASK)
#define HUM_PIOD_SET_MASK   ( HUM_PIOD_MASK(0)  | HUM_PIOD_MASK(1)   \
                            | HUM_PIOD_MASK(2)  | HUM_PIOD_MASK(3)   \
                            | HUM_PIOD_MASK(4)  | HUM_PIOD_MASK(5)   \
                            | HUM_PIOD_MASK(6)  | HUM_PIOD_MASK(7)   \
                            | HUM_PIOD_MASK(8)  | HUM_PIOD_MASK(9)   \
                            | HUM_PIOD_MASK(10) | HUM_PIOD_MASK(11)  \
                            | HUM_PIOD_MASK(12) | HUM_PIOD_MASK(13)  \
                            | HUM_PIOD_MASK(14) | HUM_PIOD_MASK(15)  \
                            | HUM_PIOD_MASK(16) | HUM_PIOD_MASK(17)  \
                            | HUM_PIOD_MASK(18) | HUM_PIOD_MASK(19)  \
                            | HUM_PIOD_MASK(20) | HUM_PIOD_MASK(21)  \
                            | HUM_PIOD_MASK(22) | HUM_PIOD_MASK(23)  \
                            | HUM_PIOD_MASK(24) | HUM_PIOD_MASK(25)  \
                            | HUM_PIOD_MASK(26) | HUM_PIOD_MASK(27)  \
                            | HUM_PIOD_MASK(28) | HUM_PIOD_MASK(29)  \
                            | HUM_PIOD_MASK(30) | HUM_PIOD_MASK(31)  )
//---------------------------
#ifndef HUM_PIOD_0
  #ifndef PIO_PD0
    #define HUM_PIOD_ 0
  #endif // PIO_PD0
#endif //HUM_PIOD_0
//---------------------------
#ifndef HUM_PIOD_1
  #ifndef PIO_PD1
    #define HUM_PIOD_1 0
  #endif // PIO_PD1
#endif //HUM_PIOD_1
//---------------------------
#ifndef HUM_PIOD_2
  #ifndef PIO_PD2
    #define HUM_PIOD_2 0
  #endif // PIO_PD2
#endif //HUM_PIOD_2
//---------------------------
#ifndef HUM_PIOD_3
  #ifndef PIO_PD3
    #define HUM_PIOD_3 0
  #endif // PIO_PD3
#endif //HUM_PIOD_3
//---------------------------
#ifndef HUM_PIOD_4
  #ifndef PIO_PD4
    #define HUM_PIOD_4 0
  #endif // PIO_PD4
#endif //HUM_PIOD_4
//---------------------------
#ifndef HUM_PIOD_5
  #ifndef PIO_PD5
    #define HUM_PIOD_5 0
  #endif // PIO_PD5
#endif //HUM_PIOD_5
//---------------------------
#ifndef HUM_PIOD_6
  #ifndef PIO_PD6
    #define HUM_PIOD_6 0
  #endif // PIO_PD6
#endif //HUM_PIOD_6
//---------------------------
#ifndef HUM_PIOD_7
  #ifndef PIO_PD7
    #define HUM_PIOD_7 0
  #endif // PIO_PD7
#endif //HUM_PIOD_7
//---------------------------
#ifndef HUM_PIOD_8
  #ifndef PIO_PD8
    #define HUM_PIOD_8 0
  #endif // PIO_PD8
#endif //HUM_PIOD_8
//---------------------------
#ifndef HUM_PIOD_9
  #ifndef PIO_PD9
    #define HUM_PIOD_9 0
  #endif // PIO_PD9
#endif //HUM_PIOD_9
//---------------------------
#ifndef HUM_PIOD_10
  #ifndef PIO_PD10
    #define HUM_PIOD_10 0
  #endif // PIO_PD10
#endif //HUM_PIOD_10
//---------------------------
#ifndef HUM_PIOD_11
  #ifndef PIO_PD11
    #define HUM_PIOD_11 0
  #endif // PIO_PD11
#endif //HUM_PIOD_11
//---------------------------
#ifndef HUM_PIOD_12
  #ifndef PIO_PD12
    #define HUM_PIOD_12 0
  #endif // PIO_PD12
#endif //HUM_PIOD_12
//---------------------------
#ifndef HUM_PIOD_13
  #ifndef PIO_PD13
    #define HUM_PIOD_13 0
  #endif // PIO_PD13
#endif //HUM_PIOD_13
//---------------------------
#ifndef HUM_PIOD_14
  #ifndef PIO_PD14
    #define HUM_PIOD_14 0
  #endif // PIO_PD14
#endif //HUM_PIOD_14
//---------------------------
#ifndef HUM_PIOD_15
  #ifndef PIO_PD15
    #define HUM_PIOD_15 0
  #endif // PIO_PD15
#endif //HUM_PIOD_15
//---------------------------
#ifndef HUM_PIOD_16
  #ifndef PIO_PD16
    #define HUM_PIOD_16 0
  #endif // PIO_PD16
#endif //HUM_PIOD_16
//---------------------------
#ifndef HUM_PIOD_17
  #ifndef PIO_PD17
    #define HUM_PIOD_17 0
  #endif // PIO_PD17
#endif //HUM_PIOD_17
//---------------------------
#ifndef HUM_PIOD_18
  #ifndef PIO_PD18
    #define HUM_PIOD_18 0
  #endif // PIO_PD18
#endif //HUM_PIOD_18
//---------------------------
#ifndef HUM_PIOD_19
  #ifndef PIO_PD19
    #define HUM_PIOD_19 0
  #endif // PIO_PD19
#endif //HUM_PIOD_19
//---------------------------
#ifndef HUM_PIOD_20
  #ifndef PIO_PD20
    #define HUM_PIOD_20 0
  #endif // PIO_PD20
#endif //HUM_PIOD_20
//---------------------------
#ifndef HUM_PIOD_21
  #ifndef PIO_PD21
    #define HUM_PIOD_21 0
  #endif // PIO_PD21
#endif //HUM_PIOD_21
//---------------------------
#ifndef HUM_PIOD_22
  #ifndef PIO_PD22
    #define HUM_PIOD_22 0
  #endif // PIO_PD22
#endif //HUM_PIOD_22
//---------------------------
#ifndef HUM_PIOD_23
  #ifndef PIO_PD23
    #define HUM_PIOD_23 0
  #endif // PIO_PD23
#endif //HUM_PIOD_23
//---------------------------
#ifndef HUM_PIOD_24
  #ifndef PIO_PD24
    #define HUM_PIOD_24 0
  #endif // PIO_PD24
#endif //HUM_PIOD_24
//---------------------------
#ifndef HUM_PIOD_25
  #ifndef PIO_PD25
    #define HUM_PIOD_25 0
  #endif // PIO_PD25
#endif //HUM_PIOD_25
//---------------------------
#ifndef HUM_PIOD_26
  #ifndef PIO_PD26
    #define HUM_PIOD_26 0
  #endif // PIO_PD26
#endif //HUM_PIOD_26
//---------------------------
#ifndef HUM_PIOD_27
  #ifndef PIO_PD27
    #define HUM_PIOD_27 0
  #endif // PIO_PD27
#endif //HUM_PIOD_27
//---------------------------
#ifndef HUM_PIOD_28
  #ifndef PIO_PD28
    #define HUM_PIOD_28 0
  #endif // PIO_PD28
#endif //HUM_PIOD_28
//---------------------------
#ifndef HUM_PIOD_29
  #ifndef PIO_PD29
    #define HUM_PIOD_29 0
  #endif // PIO_PD29
#endif //HUM_PIOD_29
//---------------------------
#ifndef HUM_PIOD_30
  #ifndef PIO_PD30
    #define HUM_PIOD_30 0
  #endif // PIO_PD30
#endif //HUM_PIOD_30
//---------------------------
#ifndef HUM_PIOD_31
  #ifndef PIO_PD31
    #define HUM_PIOD_31 0
  #endif // PIO_PD31
#endif //HUM_PIOD_31
//---------------------------

//------------------------------------------------------------------------------



#endif //_HUM_PIOD_CONST
