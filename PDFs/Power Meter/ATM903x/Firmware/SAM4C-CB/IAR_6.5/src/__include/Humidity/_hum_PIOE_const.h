#ifndef _HUM_PIOE_CONST
#define _HUM_PIOE_CONST



//------------------------------------------------------------------------------
#define HUM_PIOE_MASK(val) ((HUM_PIOE_ ## val)<<(val))
#define HUM_PIOE_CLEAR_MASK (~HUM_PIOE_SET_MASK)
#define HUM_PIOE_SET_MASK   ( HUM_PIOE_MASK(0)  | HUM_PIOE_MASK(1)   \
                            | HUM_PIOE_MASK(2)  | HUM_PIOE_MASK(3)   \
                            | HUM_PIOE_MASK(4)  | HUM_PIOE_MASK(5)   \
                            | HUM_PIOE_MASK(6)  | HUM_PIOE_MASK(7)   \
                            | HUM_PIOE_MASK(8)  | HUM_PIOE_MASK(9)   \
                            | HUM_PIOE_MASK(10) | HUM_PIOE_MASK(11)  \
                            | HUM_PIOE_MASK(12) | HUM_PIOE_MASK(13)  \
                            | HUM_PIOE_MASK(14) | HUM_PIOE_MASK(15)  \
                            | HUM_PIOE_MASK(16) | HUM_PIOE_MASK(17)  \
                            | HUM_PIOE_MASK(18) | HUM_PIOE_MASK(19)  \
                            | HUM_PIOE_MASK(20) | HUM_PIOE_MASK(21)  \
                            | HUM_PIOE_MASK(22) | HUM_PIOE_MASK(23)  \
                            | HUM_PIOE_MASK(24) | HUM_PIOE_MASK(25)  \
                            | HUM_PIOE_MASK(26) | HUM_PIOE_MASK(27)  \
                            | HUM_PIOE_MASK(28) | HUM_PIOE_MASK(29)  \
                            | HUM_PIOE_MASK(30) | HUM_PIOE_MASK(31)  )
//---------------------------
#ifndef HUM_PIOE_0
  #ifndef PIO_PE0
    #define HUM_PIOE_ 0
  #endif // PIO_PE0
#endif //HUM_PIOE_0
//---------------------------
#ifndef HUM_PIOE_1
  #ifndef PIO_PE1
    #define HUM_PIOE_1 0
  #endif // PIO_PE1
#endif //HUM_PIOE_1
//---------------------------
#ifndef HUM_PIOE_2
  #ifndef PIO_PE2
    #define HUM_PIOE_2 0
  #endif // PIO_PE2
#endif //HUM_PIOE_2
//---------------------------
#ifndef HUM_PIOE_3
  #ifndef PIO_PE3
    #define HUM_PIOE_3 0
  #endif // PIO_PE3
#endif //HUM_PIOE_3
//---------------------------
#ifndef HUM_PIOE_4
  #ifndef PIO_PE4
    #define HUM_PIOE_4 0
  #endif // PIO_PE4
#endif //HUM_PIOE_4
//---------------------------
#ifndef HUM_PIOE_5
  #ifndef PIO_PE5
    #define HUM_PIOE_5 0
  #endif // PIO_PE5
#endif //HUM_PIOE_5
//---------------------------
#ifndef HUM_PIOE_6
  #ifndef PIO_PE6
    #define HUM_PIOE_6 0
  #endif // PIO_PE6
#endif //HUM_PIOE_6
//---------------------------
#ifndef HUM_PIOE_7
  #ifndef PIO_PE7
    #define HUM_PIOE_7 0
  #endif // PIO_PE7
#endif //HUM_PIOE_7
//---------------------------
#ifndef HUM_PIOE_8
  #ifndef PIO_PE8
    #define HUM_PIOE_8 0
  #endif // PIO_PE8
#endif //HUM_PIOE_8
//---------------------------
#ifndef HUM_PIOE_9
  #ifndef PIO_PE9
    #define HUM_PIOE_9 0
  #endif // PIO_PE9
#endif //HUM_PIOE_9
//---------------------------
#ifndef HUM_PIOE_10
  #ifndef PIO_PE10
    #define HUM_PIOE_10 0
  #endif // PIO_PE10
#endif //HUM_PIOE_10
//---------------------------
#ifndef HUM_PIOE_11
  #ifndef PIO_PE11
    #define HUM_PIOE_11 0
  #endif // PIO_PE11
#endif //HUM_PIOE_11
//---------------------------
#ifndef HUM_PIOE_12
  #ifndef PIO_PE12
    #define HUM_PIOE_12 0
  #endif // PIO_PE12
#endif //HUM_PIOE_12
//---------------------------
#ifndef HUM_PIOE_13
  #ifndef PIO_PE13
    #define HUM_PIOE_13 0
  #endif // PIO_PE13
#endif //HUM_PIOE_13
//---------------------------
#ifndef HUM_PIOE_14
  #ifndef PIO_PE14
    #define HUM_PIOE_14 0
  #endif // PIO_PE14
#endif //HUM_PIOE_14
//---------------------------
#ifndef HUM_PIOE_15
  #ifndef PIO_PE15
    #define HUM_PIOE_15 0
  #endif // PIO_PE15
#endif //HUM_PIOE_15
//---------------------------
#ifndef HUM_PIOE_16
  #ifndef PIO_PE16
    #define HUM_PIOE_16 0
  #endif // PIO_PE16
#endif //HUM_PIOE_16
//---------------------------
#ifndef HUM_PIOE_17
  #ifndef PIO_PE17
    #define HUM_PIOE_17 0
  #endif // PIO_PE17
#endif //HUM_PIOE_17
//---------------------------
#ifndef HUM_PIOE_18
  #ifndef PIO_PE18
    #define HUM_PIOE_18 0
  #endif // PIO_PE18
#endif //HUM_PIOE_18
//---------------------------
#ifndef HUM_PIOE_19
  #ifndef PIO_PE19
    #define HUM_PIOE_19 0
  #endif // PIO_PE19
#endif //HUM_PIOE_19
//---------------------------
#ifndef HUM_PIOE_20
  #ifndef PIO_PE20
    #define HUM_PIOE_20 0
  #endif // PIO_PE20
#endif //HUM_PIOE_20
//---------------------------
#ifndef HUM_PIOE_21
  #ifndef PIO_PE21
    #define HUM_PIOE_21 0
  #endif // PIO_PE21
#endif //HUM_PIOE_21
//---------------------------
#ifndef HUM_PIOE_22
  #ifndef PIO_PE22
    #define HUM_PIOE_22 0
  #endif // PIO_PE22
#endif //HUM_PIOE_22
//---------------------------
#ifndef HUM_PIOE_23
  #ifndef PIO_PE23
    #define HUM_PIOE_23 0
  #endif // PIO_PE23
#endif //HUM_PIOE_23
//---------------------------
#ifndef HUM_PIOE_24
  #ifndef PIO_PE24
    #define HUM_PIOE_24 0
  #endif // PIO_PE24
#endif //HUM_PIOE_24
//---------------------------
#ifndef HUM_PIOE_25
  #ifndef PIO_PE25
    #define HUM_PIOE_25 0
  #endif // PIO_PE25
#endif //HUM_PIOE_25
//---------------------------
#ifndef HUM_PIOE_26
  #ifndef PIO_PE26
    #define HUM_PIOE_26 0
  #endif // PIO_PE26
#endif //HUM_PIOE_26
//---------------------------
#ifndef HUM_PIOE_27
  #ifndef PIO_PE27
    #define HUM_PIOE_27 0
  #endif // PIO_PE27
#endif //HUM_PIOE_27
//---------------------------
#ifndef HUM_PIOE_28
  #ifndef PIO_PE28
    #define HUM_PIOE_28 0
  #endif // PIO_PE28
#endif //HUM_PIOE_28
//---------------------------
#ifndef HUM_PIOE_29
  #ifndef PIO_PE29
    #define HUM_PIOE_29 0
  #endif // PIO_PE29
#endif //HUM_PIOE_29
//---------------------------
#ifndef HUM_PIOE_30
  #ifndef PIO_PE30
    #define HUM_PIOE_30 0
  #endif // PIO_PE30
#endif //HUM_PIOE_30
//---------------------------
#ifndef HUM_PIOE_31
  #ifndef PIO_PE31
    #define HUM_PIOE_31 0
  #endif // PIO_PE31
#endif //HUM_PIOE_31
//---------------------------

//------------------------------------------------------------------------------



#endif //_HUM_PIOE_CONST
