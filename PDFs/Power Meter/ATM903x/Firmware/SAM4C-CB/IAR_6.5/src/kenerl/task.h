//===================================================================
#ifndef TASK_H_INCLUDED
#define TASK_H_INCLUDED

#include "compiler.h"

/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
extern "C" {
#endif
/**INDENT-ON**/
/// @endcond

#define TASK_Num_MAX  30

typedef enum 
{
    EMPTYTASK =0,
	ReadRTC,
	SecondProc,
	TOUProc,
    UpdataDisplay,
	UpdataDisplayNumber,
	DemandProc,
	Rs485CmdProc,
	Rs485Transmit,
	IrCmdProc,
	IrTransmit,
	PLCCmdProc,
	PLCTransmit,
	ZigBeeCmdProc,
	ZigBeeTransmit,
    HistoryDataSave,
	CheckMajorPara,
	PulseProc,
	EnergyProc,
    MeasureProc,
	ResetDSP,
    ResumeCalibrationPara,
    ResetProc
}TASK_CONST;

typedef struct
{
	uint8_t	inputos;
	uint8_t outputos;
	uint8_t	Buff[TASK_Num_MAX];
}TASK_Str;
//---------------------variable declare------------------------------
extern	TASK_Str	VTask;
//===================================================================
void	InitTaskQue(void);
uint8_t    PutTaskIntoQue_INT(TASK_CONST TaskID);
uint8_t    PutTaskIntoQue(TASK_CONST TaskID);
TASK_CONST    GetTaskFromQue(void);

/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
}
#endif
/**INDENT-ON**/
/// @endcond


#endif /* DISPLAY_H_INCLUDED */
