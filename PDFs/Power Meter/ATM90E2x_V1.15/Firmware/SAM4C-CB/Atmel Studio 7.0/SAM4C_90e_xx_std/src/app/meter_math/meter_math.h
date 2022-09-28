//===================================================================
#ifndef METER_MATH_H_INCLUDED
#define METER_MATH_H_INCLUDED

#include "compiler.h"

/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
extern "C" {
#endif
/**INDENT-ON**/
/// @endcond


uint8_t BCD_8BIN(uint8_t bcddata);
uint16_t BIN_TO_BCD(uint8_t bindata);
uint8_t BCD_2_Add(uint8_t addend,uint8_t *point);
uint8_t BCD_8_Add(uint8_t *pointadd,uint8_t *pointend);

uint8_t	BCD_Verify(uint8_t BCDData);
uint8_t	N_Byte_BCDVerify(uint8_t *ptr, uint8_t len);

/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
}
#endif
/**INDENT-ON**/
/// @endcond


#endif /* METER_MATH_H_INCLUDED */
