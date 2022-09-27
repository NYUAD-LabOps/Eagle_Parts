//===================================================================
#ifndef BASETIME_H_INCLUDED
#define BASETIME_H_INCLUDED

#include "compiler.h"

/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
extern "C" {
#endif
/**INDENT-ON**/
/// @endcond


typedef struct
{
	volatile	uint8_t	T5ms;
	uint8_t	T500ms;
	uint8_t	T1s;
	uint8_t	T1Min;
}BASETIME_Str;
//---------------------variable declare------------------------------
extern	BASETIME_Str    VBaseTimer;
//===================================================================
void	SysTick_Handler(void);
void    BaseTimerProcess(void);

/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
}
#endif
/**INDENT-ON**/
/// @endcond


#endif /* BASETIMER_H_INCLUDED */
