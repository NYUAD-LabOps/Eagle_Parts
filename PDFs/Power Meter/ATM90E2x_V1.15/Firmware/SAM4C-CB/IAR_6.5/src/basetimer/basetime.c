//===================================================================
#include "target.h"
//-------------------------------------------------------------------
extern sys_t	        sys;		    // system parameters

BASETIME_Str    VBaseTimer;
//-------------------------------------------------------------------

/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
extern "C" {
#endif
/**INDENT-ON**/
/// @endcond

//===================================================================
//decription    ::  system tick interrupt
//function      ::  SysTick_Handler
//input         ::  none
//output        ::  none
//call          ::  none
//effect        ::  VBaseTimer.T5ms
//===================================================================
void SysTick_Handler(void)
{
	sys.ms_ticks++;
	VBaseTimer.T5ms++;	
}
//===================================================================
//decription    ::  base timer process
//function      ::  BaseTimerProcess
//input         ::  none
//output        ::  none
//call          ::  none
//effect        ::  VBaseTimer.T5ms
//===================================================================
void    BaseTimerProcess(void)
{
    VBaseTimer.T5ms =0;
	wdt_restart(WDT);
/*
    if( sys.mode == RESTART_MODE )
    {
        sys.mode &= ~RESTART_MODE;
        PutTaskIntoQue(ResetProc);
    }
    if( sys.events&SECOND_FG ==SECOND_FG)// |= SECOND_FG
    {
        sys.events &= ~SECOND_FG;
        PutTaskIntoQue(MeasureProc);
    }
*/	
	//-----------------------------------------------------
	if(VAFE.thd_timer)
	{
		if(--VAFE.thd_timer==0)
        {
            VAFE.thd_status =IsSuccess;
        }
	}
	//-----------------------------------------------------
	if(VCom.Rs485.sendtimer !=0)
	{
		if( --VCom.Rs485.sendtimer==0 && VCom.Rs485.state==SEND )
		{
			PutTaskIntoQue(Rs485Transmit);
		}
	}//endif (Rs485.sendtimer !=0)
	else
	{
		if(++VCom.Rs485.overtimer >59)
		{
			Init_Uart_App(Rs485_ID); 
		}
	}//
	if(VCom.IR.sendtimer !=0)
	{
		if( --VCom.IR.sendtimer==0 && VCom.IR.state==SEND )
		{
			PutTaskIntoQue(IrTransmit);
		}
	}//endif (IR.sendtimer !=0)
	else
	{
		if(++VCom.IR.overtimer >59)
		{
			VCom.IR.overtimer =0;
			Init_Uart_App(Ir_ID);
		}
	}//
	if(VCom.ZigBee.sendtimer !=0)
	{
		if( --VCom.ZigBee.sendtimer==0 && VCom.ZigBee.state==SEND )
		{
			PutTaskIntoQue(ZigBeeTransmit);
		}
	}//endif (ZigBee.sendtimer !=0)
	else
	{
		if(++VCom.ZigBee.overtimer >59)
		{
			VCom.ZigBee.overtimer =0;
			Init_Usart_App(ZigBee_ID);
		}
	}//
	//-----------------------------------------------------
	if(sys.dispkeydn ==0x55)
	{
		sys.dispkeydn=0;
		VDisplay.Direct |= FORWARD;
		VDisplay.LpTimer =10;
        PutTaskIntoQue(UpdataDisplayNumber);	
	}
	if(sys.dispkeyup ==0x55)
	{
		sys.dispkeyup=0;
		VDisplay.Direct |= BACKWARD;
		VDisplay.LpTimer =10;
        PutTaskIntoQue(UpdataDisplayNumber);
	}
	if(++VBaseTimer.T500ms >99)
	{				
		VBaseTimer.T500ms =0;
		PutTaskIntoQue(ReadRTC);
        PutTaskIntoQue(UpdataDisplay);
		PutTaskIntoQue(PulseProc);//
        if(--VDisplay.LpTimer ==0)
        {
            VDisplay.LpTimer =10;
            PutTaskIntoQue(UpdataDisplayNumber);
        }
		if(VCom.lamptimer)
		{
			VCom.lamptimer--;
		}		
	}
	if(++VBaseTimer.T1s >199)
	{
		VBaseTimer.T1s=0;
		PutTaskIntoQue(SecondProc);		
		if(++VBaseTimer.T1Min >59)
		{
			VBaseTimer.T1Min=0;
//			PutTaskIntoQue(DemandProc);
			PutTaskIntoQue(CheckMajorPara);
		}
	}

}


/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
}
#endif
/**INDENT-ON**/
/// @endcond