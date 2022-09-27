#ifndef _HUM_PIOC_CONST
#define _HUM_PIOC_CONST



//------------------------------------------------------------------------------
#define HUM_PIOC_MASK(val) ((HUM_PIOC_ ## val)<<(val))
#define HUM_PIOC_CLEAR_MASK (~HUM_PIOC_SET_MASK)
#define HUM_PIOC_SET_MASK   ( HUM_PIOC_MASK(0)  | HUM_PIOC_MASK(1)   \
                            | HUM_PIOC_MASK(2)  | HUM_PIOC_MASK(3)   \
                            | HUM_PIOC_MASK(4)  | HUM_PIOC_MASK(5)   \
                            | HUM_PIOC_MASK(6)  | HUM_PIOC_MASK(7)   \
                            | HUM_PIOC_MASK(8)  | HUM_PIOC_MASK(9)   \
                            | HUM_PIOC_MASK(10) | HUM_PIOC_MASK(11)  \
                            | HUM_PIOC_MASK(12) | HUM_PIOC_MASK(13)  \
                            | HUM_PIOC_MASK(14) | HUM_PIOC_MASK(15)   \
                            | HUM_PIOC_MASK(16) | HUM_PIOC_MASK(17)  \
                            | HUM_PIOC_MASK(18) | HUM_PIOC_MASK(19)  \
                            | HUM_PIOC_MASK(20) | HUM_PIOC_MASK(21)  \
                            | HUM_PIOC_MASK(22) | HUM_PIOC_MASK(23)  \
                            | HUM_PIOC_MASK(24) | HUM_PIOC_MASK(25)  \
                            | HUM_PIOC_MASK(26) | HUM_PIOC_MASK(27)  \
                            | HUM_PIOC_MASK(28) | HUM_PIOC_MASK(29)  \
                            | HUM_PIOC_MASK(30) | HUM_PIOC_MASK(31)  )
//---------------------------
#ifndef HUM_PIOC_0
  #ifndef PIO_PC0
    #define HUM_PIOC_ 0
  #endif // PIO_PC0
#endif //HUM_PIOC_0
//---------------------------
#ifndef HUM_PIOC_1
  #ifndef PIO_PC1
    #define HUM_PIOC_1 0
  #endif // PIO_PC1
#endif //HUM_PIOC_1
//---------------------------
#ifndef HUM_PIOC_2
  #ifndef PIO_PC2
    #define HUM_PIOC_2 0
  #endif // PIO_PC2
#endif //HUM_PIOC_2
//---------------------------
#ifndef HUM_PIOC_3
  #ifndef PIO_PC3
    #define HUM_PIOC_3 0
  #endif // PIO_PC3
#endif //HUM_PIOC_3
//---------------------------
#ifndef HUM_PIOC_4
  #ifndef PIO_PC4
    #define HUM_PIOC_4 0
  #endif // PIO_PC4
#endif //HUM_PIOC_4
//---------------------------
#ifndef HUM_PIOC_5
  #ifndef PIO_PC5
    #define HUM_PIOC_5 0
  #endif // PIO_PC5
#endif //HUM_PIOC_5
//---------------------------
#ifndef HUM_PIOC_6
  #ifndef PIO_PC6
    #define HUM_PIOC_6 0
  #endif // PIO_PC6
#endif //HUM_PIOC_6
//---------------------------
#ifndef HUM_PIOC_7
  #ifndef PIO_PC7
    #define HUM_PIOC_7 0
  #endif // PIO_PC7
#endif //HUM_PIOC_7
//---------------------------
#ifndef HUM_PIOC_8
  #ifndef PIO_PC8
    #define HUM_PIOC_8 0
  #endif // PIO_PC8
#endif //HUM_PIOC_8
//---------------------------
#ifndef HUM_PIOC_9
  #ifndef PIO_PC9
    #define HUM_PIOC_9 0
  #endif // PIO_PC9
#endif //HUM_PIOC_9
//---------------------------
#ifndef HUM_PIOC_10
  #ifndef PIO_PC10
    #define HUM_PIOC_10 0
  #endif // PIO_PC10
#endif //HUM_PIOC_10
//---------------------------
#ifndef HUM_PIOC_11
  #ifndef PIO_PC11
    #define HUM_PIOC_11 0
  #endif // PIO_PC11
#endif //HUM_PIOC_11
//---------------------------
#ifndef HUM_PIOC_12
  #ifndef PIO_PC12
    #define HUM_PIOC_12 0
  #endif // PIO_PC12
#endif //HUM_PIOC_12
//---------------------------
#ifndef HUM_PIOC_13
  #ifndef PIO_PC13
    #define HUM_PIOC_13 0
  #endif // PIO_PC13
#endif //HUM_PIOC_13
//---------------------------
#ifndef HUM_PIOC_14
  #ifndef PIO_PC14
    #define HUM_PIOC_14 0
  #endif // PIO_PC14
#endif //HUM_PIOC_14
//---------------------------
#ifndef HUM_PIOC_15
  #ifndef PIO_PC15
    #define HUM_PIOC_15 0
  #endif // PIO_PC15
#endif //HUM_PIOC_15
//---------------------------
#ifndef HUM_PIOC_16
  #ifndef PIO_PC16
    #define HUM_PIOC_16 0
  #endif // PIO_PC16
#endif //HUM_PIOC_16
//---------------------------
#ifndef HUM_PIOC_17
  #ifndef PIO_PC17
    #define HUM_PIOC_17 0
  #endif // PIO_PC17
#endif //HUM_PIOC_17
//---------------------------
#ifndef HUM_PIOC_18
  #ifndef PIO_PC18
    #define HUM_PIOC_18 0
  #endif // PIO_PC18
#endif //HUM_PIOC_18
//---------------------------
#ifndef HUM_PIOC_19
  #ifndef PIO_PC19
    #define HUM_PIOC_19 0
  #endif // PIO_PC19
#endif //HUM_PIOC_19
//---------------------------
#ifndef HUM_PIOC_20
  #ifndef PIO_PC20
    #define HUM_PIOC_20 0
  #endif // PIO_PC20
#endif //HUM_PIOC_20
//---------------------------
#ifndef HUM_PIOC_21
  #ifndef PIO_PC21
    #define HUM_PIOC_21 0
  #endif // PIO_PC21
#endif //HUM_PIOC_21
//---------------------------
#ifndef HUM_PIOC_22
  #ifndef PIO_PC22
    #define HUM_PIOC_22 0
  #endif // PIO_PC22
#endif //HUM_PIOC_22
//---------------------------
#ifndef HUM_PIOC_23
  #ifndef PIO_PC23
    #define HUM_PIOC_23 0
  #endif // PIO_PC23
#endif //HUM_PIOC_23
//---------------------------
#ifndef HUM_PIOC_24
  #ifndef PIO_PC24
    #define HUM_PIOC_24 0
  #endif // PIO_PC24
#endif //HUM_PIOC_24
//---------------------------
#ifndef HUM_PIOC_25
  #ifndef PIO_PC25
    #define HUM_PIOC_25 0
  #endif // PIO_PC25
#endif //HUM_PIOC_25
//---------------------------
#ifndef HUM_PIOC_26
  #ifndef PIO_PC26
    #define HUM_PIOC_26 0
  #endif // PIO_PC26
#endif //HUM_PIOC_26
//---------------------------
#ifndef HUM_PIOC_27
  #ifndef PIO_PC27
    #define HUM_PIOC_27 0
  #endif // PIO_PC27
#endif //HUM_PIOC_27
//---------------------------
#ifndef HUM_PIOC_28
  #ifndef PIO_PC28
    #define HUM_PIOC_28 0
  #endif // PIO_PC28
#endif //HUM_PIOC_28
//---------------------------
#ifndef HUM_PIOC_29
  #ifndef PIO_PC29
    #define HUM_PIOC_29 0
  #endif // PIO_PC29
#endif //HUM_PIOC_29
//---------------------------
#ifndef HUM_PIOC_30
  #ifndef PIO_PC30
    #define HUM_PIOC_30 0
  #endif // PIO_PC30
#endif //HUM_PIOC_30
//---------------------------
#ifndef HUM_PIOC_31
  #ifndef PIO_PC31
    #define HUM_PIOC_31 0
  #endif // PIO_PC31
#endif //HUM_PIOC_31
//---------------------------

//------------------------------------------------------------------------------



#endif //_HUM_PIOC_CONST
