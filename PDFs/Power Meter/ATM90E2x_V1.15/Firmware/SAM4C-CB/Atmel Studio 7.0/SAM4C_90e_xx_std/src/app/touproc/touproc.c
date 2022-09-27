//===================================================================
#include "target.h"

/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
extern "C" {
#endif
/**INDENT-ON**/
/// @endcond

TOU_Str	VTou;
//===================================================================
//decription    ::  tou process
//function      ::  TOUProcProcess
//input         ::  none
//output        ::  none
//call          ::  rtc_get_time
//effect        ::  VTou
//===================================================================
void	TOUProcProcess(void)
{
	uint32_t	i,j;
	for(i=0;i<TOU_NUM_MAX;i++)
	{
		if( VRTC.hour<VTou.table[i].hour || \
			(VRTC.hour==VTou.table[i].hour && VRTC.minute<VTou.table[i].minute) )
		{
			break;
		}
	}
	if( i==0 )
	{
		j=VTou.table[TOU_NUM_MAX-1].touid;
	}
	else
	{
		j=VTou.table[i-1].touid;
	}
	if(VTou.type !=j)
	{
		//save tou energy decimal
		VTou.type =j;
        //clear_TOU_DemandCal();//clear 15 minutes demand measure buffer		
		//read-out tou energy decimal
	}//tou is changed
}


/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
}
#endif
/**INDENT-ON**/
/// @endcond

