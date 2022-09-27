//===================================================================
#ifndef TOUPROC_H_INCLUDED
#define TOUPROC_H_INCLUDED

#include "compiler.h"

/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
extern "C" {
#endif
/**INDENT-ON**/
/// @endcond

typedef	enum
{
	TOU1 =0,
	TOU2,
	TOU3,
	TOU4,
	ALL
}TOU_CONST;

#define	TOU_NUM_MAX		8
typedef	struct
{	
	uint8_t	touid;
	uint8_t	minute;
	uint8_t	hour;
}TOU_TABLE;
typedef	struct
{
	uint8_t	type;
	TOU_TABLE	table[TOU_NUM_MAX];
}TOU_Str;
//====================================================================
extern	TOU_Str	VTou;
//--------------------------------------------------------------------
void	TOUProcProcess(void);


/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
}
#endif
/**INDENT-ON**/
/// @endcond


#endif /* DISPLAY_H_INCLUDED */
