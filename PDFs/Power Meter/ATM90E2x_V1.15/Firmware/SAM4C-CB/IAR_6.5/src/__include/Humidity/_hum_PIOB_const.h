#ifndef _HUM_PIOB_CONST
#define _HUM_PIOB_CONST



//------------------------------------------------------------------------------
#define HUM_PIOB_MASK(val) ((HUM_PIOB_ ## val)<<(val))
#define HUM_PIOB_CLEAR_MASK (~HUM_PIOB_SET_MASK)
#define HUM_PIOB_SET_MASK   ( HUM_PIOB_MASK(0)  | HUM_PIOB_MASK(1)   \
                            | HUM_PIOB_MASK(2)  | HUM_PIOB_MASK(3)   \
                            | HUM_PIOB_MASK(4)  | HUM_PIOB_MASK(5)   \
                            | HUM_PIOB_MASK(6)  | HUM_PIOB_MASK(7)   \
                            | HUM_PIOB_MASK(8)  | HUM_PIOB_MASK(9)   \
                            | HUM_PIOB_MASK(10) | HUM_PIOB_MASK(11)  \
                            | HUM_PIOB_MASK(12) | HUM_PIOB_MASK(13)  \
                            | HUM_PIOB_MASK(14) | HUM_PIOB_MASK(15)   \
                            | HUM_PIOB_MASK(16) | HUM_PIOB_MASK(17)  \
                            | HUM_PIOB_MASK(18) | HUM_PIOB_MASK(19)  \
                            | HUM_PIOB_MASK(20) | HUM_PIOB_MASK(21)  \
                            | HUM_PIOB_MASK(22) | HUM_PIOB_MASK(23)  \
                            | HUM_PIOB_MASK(24) | HUM_PIOB_MASK(25)  \
                            | HUM_PIOB_MASK(26) | HUM_PIOB_MASK(27)  \
                            | HUM_PIOB_MASK(28) | HUM_PIOB_MASK(29)  \
                            | HUM_PIOB_MASK(30) | HUM_PIOB_MASK(31)  )
//---------------------------
#ifndef HUM_PIOB_0
  #ifndef PIO_PB0
    #define HUM_PIOB_ 0
  #endif // PIO_PB0
#endif //HUM_PIOB_0
//---------------------------
#ifndef HUM_PIOB_1
  #ifndef PIO_PB1
    #define HUM_PIOB_1 0
  #endif // PIO_PB1
#endif //HUM_PIOB_1
//---------------------------
#ifndef HUM_PIOB_2
  #ifndef PIO_PB2
    #define HUM_PIOB_2 0
  #endif // PIO_PB2
#endif //HUM_PIOB_2
//---------------------------
#ifndef HUM_PIOB_3
  #ifndef PIO_PB3
    #define HUM_PIOB_3 0
  #endif // PIO_PB3
#endif //HUM_PIOB_3
//---------------------------
#ifndef HUM_PIOB_4
  #ifndef PIO_PB4
    #define HUM_PIOB_4 0
  #endif // PIO_PB4
#endif //HUM_PIOB_4
//---------------------------
#ifndef HUM_PIOB_5
  #ifndef PIO_PB5
    #define HUM_PIOB_5 0
  #endif // PIO_PB5
#endif //HUM_PIOB_5
//---------------------------
#ifndef HUM_PIOB_6
  #ifndef PIO_PB6
    #define HUM_PIOB_6 0
  #endif // PIO_PB6
#endif //HUM_PIOB_6
//---------------------------
#ifndef HUM_PIOB_7
  #ifndef PIO_PB7
    #define HUM_PIOB_7 0
  #endif // PIO_PB7
#endif //HUM_PIOB_7
//---------------------------
#ifndef HUM_PIOB_8
  #ifndef PIO_PB8
    #define HUM_PIOB_8 0
  #endif // PIO_PB8
#endif //HUM_PIOB_8
//---------------------------
#ifndef HUM_PIOB_9
  #ifndef PIO_PB9
    #define HUM_PIOB_9 0
  #endif // PIO_PB9
#endif //HUM_PIOB_9
//---------------------------
#ifndef HUM_PIOB_10
  #ifndef PIO_PB10
    #define HUM_PIOB_10 0
  #endif // PIO_PB10
#endif //HUM_PIOB_10
//---------------------------
#ifndef HUM_PIOB_11
  #ifndef PIO_PB11
    #define HUM_PIOB_11 0
  #endif // PIO_PB11
#endif //HUM_PIOB_11
//---------------------------
#ifndef HUM_PIOB_12
  #ifndef PIO_PB12
    #define HUM_PIOB_12 0
  #endif // PIO_PB12
#endif //HUM_PIOB_12
//---------------------------
#ifndef HUM_PIOB_13
  #ifndef PIO_PB13
    #define HUM_PIOB_13 0
  #endif // PIO_PB13
#endif //HUM_PIOB_13
//---------------------------
#ifndef HUM_PIOB_14
  #ifndef PIO_PB14
    #define HUM_PIOB_14 0
  #endif // PIO_PB14
#endif //HUM_PIOB_14
//---------------------------
#ifndef HUM_PIOB_15
  #ifndef PIO_PB15
    #define HUM_PIOB_15 0
  #endif // PIO_PB15
#endif //HUM_PIOB_15
//---------------------------
#ifndef HUM_PIOB_16
  #ifndef PIO_PB16
    #define HUM_PIOB_16 0
  #endif // PIO_PB16
#endif //HUM_PIOB_16
//---------------------------
#ifndef HUM_PIOB_17
  #ifndef PIO_PB17
    #define HUM_PIOB_17 0
  #endif // PIO_PB17
#endif //HUM_PIOB_17
//---------------------------
#ifndef HUM_PIOB_18
  #ifndef PIO_PB18
    #define HUM_PIOB_18 0
  #endif // PIO_PB18
#endif //HUM_PIOB_18
//---------------------------
#ifndef HUM_PIOB_19
  #ifndef PIO_PB19
    #define HUM_PIOB_19 0
  #endif // PIO_PB19
#endif //HUM_PIOB_19
//---------------------------
#ifndef HUM_PIOB_20
  #ifndef PIO_PB20
    #define HUM_PIOB_20 0
  #endif // PIO_PB20
#endif //HUM_PIOB_20
//---------------------------
#ifndef HUM_PIOB_21
  #ifndef PIO_PB21
    #define HUM_PIOB_21 0
  #endif // PIO_PB21
#endif //HUM_PIOB_21
//---------------------------
#ifndef HUM_PIOB_22
  #ifndef PIO_PB22
    #define HUM_PIOB_22 0
  #endif // PIO_PB22
#endif //HUM_PIOB_22
//---------------------------
#ifndef HUM_PIOB_23
  #ifndef PIO_PB23
    #define HUM_PIOB_23 0
  #endif // PIO_PB23
#endif //HUM_PIOB_23
//---------------------------
#ifndef HUM_PIOB_24
  #ifndef PIO_PB24
    #define HUM_PIOB_24 0
  #endif // PIO_PB24
#endif //HUM_PIOB_24
//---------------------------
#ifndef HUM_PIOB_25
  #ifndef PIO_PB25
    #define HUM_PIOB_25 0
  #endif // PIO_PB25
#endif //HUM_PIOB_25
//---------------------------
#ifndef HUM_PIOB_26
  #ifndef PIO_PB26
    #define HUM_PIOB_26 0
  #endif // PIO_PB26
#endif //HUM_PIOB_26
//---------------------------
#ifndef HUM_PIOB_27
  #ifndef PIO_PB27
    #define HUM_PIOB_27 0
  #endif // PIO_PB27
#endif //HUM_PIOB_27
//---------------------------
#ifndef HUM_PIOB_28
  #ifndef PIO_PB28
    #define HUM_PIOB_28 0
  #endif // PIO_PB28
#endif //HUM_PIOB_28
//---------------------------
#ifndef HUM_PIOB_29
  #ifndef PIO_PB29
    #define HUM_PIOB_29 0
  #endif // PIO_PB29
#endif //HUM_PIOB_29
//---------------------------
#ifndef HUM_PIOB_30
  #ifndef PIO_PB30
    #define HUM_PIOB_30 0
  #endif // PIO_PB30
#endif //HUM_PIOB_30
//---------------------------
#ifndef HUM_PIOB_31
  #ifndef PIO_PB31
    #define HUM_PIOB_31 0
  #endif // PIO_PB31
#endif //HUM_PIOB_31
//---------------------------

//------------------------------------------------------------------------------



#endif //_HUM_PIOB_CONST
