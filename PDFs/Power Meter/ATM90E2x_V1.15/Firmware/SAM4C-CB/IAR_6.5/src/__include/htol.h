#ifndef _HTOL_H
#define _HTOL_H




#include "global.h"
/*----------------------------------------------------------------------------*/
/* HTOL tests settings definitions                                            */
/*----------------------------------------------------------------------------*/
#define INFINITE_LOOP 0   // for test_nb_iter parameters
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* ISRAM memory regions definition (use with htol_SAMxxxxxx.icf linker file)  */
/*----------------------------------------------------------------------------*/
#define ISRAM_CODE_SECTION_START (IRAM_ADDR)  // for SRAM linker
#define ISRAM_CODE_SECTION_SIZE  0x2800       // for SRAM linker
#define ISRAM_CODE_SECTION_END (ISRAM_CODE_SECTION_START+ISRAM_CODE_SECTION_SIZE)

#define ISRAM_DATA_SECTION_START (ISRAM_CODE_SECTION_END)
#define ISRAM_DATA_SECTION_SIZE   0x1000
#define ISRAM_DATA_SECTION_END   (ISRAM_DATA_SECTION_START+ISRAM_DATA_SECTION_SIZE)

#define ISRAM_TEST_SECTION_START (ISRAM_DATA_SECTION_END)
#define ISRAM_TEST_SECTION_SIZE  (IRAM_SIZE-ISRAM_CODE_SECTION_SIZE-ISRAM_DATA_SECTION_SIZE)
#define ISRAM_TEST_SECTION_END   (ISRAM_TEST_SECTION_START+ISRAM_TEST_SECTION_SIZE)
/*----------------------------------------------------------------------------*/

// ----------------------------------------------------------------------------
//  LED definition (depend on board.h)
// ----------------------------------------------------------------------------
#ifdef POE09_785_001 //SAM4S_HTOL_revA
  #define TURN_ON_PASS_LED   BRD_TURN_ON_LD1
  #define TURN_OFF_PASS_LED  BRD_TURN_OFF_LD1
  #define TOOGLE_PASS_LED    BRD_TOOGLE_LD1
#else               // SAM4S_VB_QFN64_LQFP64_revA
  #define TURN_ON_PASS_LED    BRD_TURN_ON_D3
  #define TURN_OFF_PASS_LED   BRD_TURN_OFF_D3
  #define TOOGLE_PASS_LED     BRD_TOOGLE_D3
  #define TURN_ON_USER_LED    BRD_TURN_ON_D4
  #define TURN_OFF_USER_LED   BRD_TURN_OFF_D4
  #define TOOGLE_USER_LED     BRD_TOOGLE_D4
  #define TURN_ON_POWER_LED   BRD_TURN_ON_D1
  #define TURN_OFF_POWER_LED  BRD_TURN_OFF_D1
  #define TOOGLE_POWER_LED    BRD_TOOGLE_D1
#endif
// ----------------------------------------------------------------------------
//  INPUTS definition (depend on board.h)
// ----------------------------------------------------------------------------
#ifdef POE09_785_001 //SAM4S_HTOL_revA
  #define GET_TEST_SELECT    BRD_GET_B5_INPUT
#else               // SAM4S_VB_QFN64_LQFP64_revA
  #define GET_TEST_SELECT    BRD_GET_BP2
#endif
// ----------------------------------------------------------------------------



#endif//_HTOL_H
