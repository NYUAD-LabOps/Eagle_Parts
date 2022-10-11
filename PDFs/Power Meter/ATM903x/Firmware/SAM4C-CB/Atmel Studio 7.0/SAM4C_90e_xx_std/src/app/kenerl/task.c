//===================================================================
#include "target.h"
//-------------------------------------------------------------------
TASK_Str    VTask;
//-------------------------------------------------------------------

/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
extern "C" {
#endif
/**INDENT-ON**/
/// @endcond

//===================================================================
//decription    ::  inition task queue
//function      ::  InitTaskQue
//input         ::  none
//output        ::  none
//call          ::  none
//effect        ::  vtask.Buff
//===================================================================
void	InitTaskQue( void )
{
    uint8_t	i;
	for(i=0;i<TASK_Num_MAX;i++)
	{
		VTask.Buff[i]=0;
	}
	VTask.inputos =0;
	VTask.outputos =0;
}
//===================================================================
//decription    ::  put task into task queue in interrupt state
//function      ::  PutTaskIntoQue_INT
//input         ::  TaskID
//output        ::  1:success, 0=failure
//call          ::  none
//effect        ::  vtask.offset
//===================================================================
uint8_t    PutTaskIntoQue_INT( TASK_CONST TaskID )
{
    if( VTask.inputos >= TASK_Num_MAX )
    {
        VTask.inputos =0;// TASK_Num_MAX >>1;       
    }
    VTask.Buff[VTask.inputos] =TaskID;
    VTask.inputos++;

    return ( 1 );
}
//===================================================================
//decription    ::  put task into task queue
//function      ::  PutTaskIntoQue
//input         ::  TaskID
//output        ::  1:success, 0=failure
//call          ::  none
//effect        ::  vtask.offset
//===================================================================
uint8_t    PutTaskIntoQue( TASK_CONST TaskID )
{
    uint8_t	i;
    __disable_irq();
    i = PutTaskIntoQue_INT( TaskID );
    __enable_irq();

    return ( i );
}
//===================================================================
//decription    ::  get task from task queue
//function      ::  GetTaskFromQue
//input         ::  none
//output        ::  taskID
//call          ::  none
//effect        ::  vtask.offset
//===================================================================
TASK_CONST    GetTaskFromQue( void )
{
	uint8_t    i;
    TASK_CONST   j;
	
    __disable_irq();
    j=VTask.Buff[VTask.outputos];
	VTask.Buff[VTask.outputos]=0;
    if( (++VTask.outputos) >=TASK_Num_MAX)
    {
      VTask.outputos =0;//(TASK_Num_MAX>>1);
    }       
    __enable_irq();
	
    return ( j );
}


/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
}
#endif
/**INDENT-ON**/
/// @endcond