//===================================================================
#include "target.h"
//===================================================================

/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
extern "C" {
#endif
/**INDENT-ON**/
/// @endcond


// Demo Meter variables
//sys_t       sys;		// System variable structure

//=========================================================
//------------- main -------------------------------------- 
//=========================================================
int main(void)
{
    //-----------------------------------------------------
	sys_init();
    //---------------------------------------------------------------
	//---------------------------------------------------------------
    //------------main loop------------------------------------------
    //---------------------------------------------------------------
	while (1) 	
	{
		//-----------------------------------------------------
		if(VBaseTimer.T5ms)
        {
          BaseTimerProcess();
        }
		
		switch( GetTaskFromQue() )
        {
            case  RTCPROC:
            {
                ReadRTCProcess();
            }
            break;        
            case  RefreshDisplay:
            {
                RefreshDisplayProcess();
            }
            break;
            case  RefreshDisplayNumber:
            {
                RefreshDisplayNumberProcess();
            }
            break;
            case    Rs485CmdProc:
            {
            	ComProcess(Rs485_ID);
			}
			break;
			case    Rs485Transmit:
            {
				ComSendProcess(Rs485_ID);
			}
			break;
			case    IrCmdProc:
            {
            	ComProcess(Ir_ID);
			}
			break;
			case    IrTransmit:
            {
				ComSendProcess(Ir_ID);
			}
			break;
			case    ZigBeeCmdProc:
            {
            	ComProcess(ZigBee_ID);
			}
			break;
			case    ZigBeeTransmit:
            {
				ComSendProcess(ZigBee_ID);
			}
			break;
			case    PulseProc:
            {
				PulseProcess();
			}
			break;
			case    EnergyProc:
            {
				EnergyProcess();
			}
			break;
			case    SecondProc:
            {
				SecondProcess();
			}
			break;
			case	CheckMajorPara:
			{
				CheckMajorParaProcess();
			}
			break;
            case    ResumeCalibrationPara:
            {
                Load_AFE_Cal_Para_From_Eprom();
            }
            break;
            default :
            break;
        }

	}//end while(1)
}	





/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
}
#endif
/**INDENT-ON**/
/// @endcond

