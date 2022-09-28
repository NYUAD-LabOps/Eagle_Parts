//===================================================================
#include "target.h"
//-------------------------------------------------------------------
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
void	SysTick_Handler(void)
{
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

	//__disable_irq();
    VBaseTimer.T5ms =0;
	//__enable_irq();
	wdt_restart(WDT);
	//-----------------------------------------------------

	//-----------------------------------------------------
	if ( ++VBaseTimer.T500ms > 99 )
    {
        VBaseTimer.T500ms = 0;
        //---------------------------------------

		//---------------------------------------
        //PutTaskIntoQue( ReFreshDisplayMsg );	//refresh display
        //if ( --VDisplay.LpTimer == 0 )
        //{
        //    VDisplay.LpTimer = 10;
        //    PutTaskIntoQue( ReFreshDisplayNumberMsg );
        //}
        
    }

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
			//Init_Uart_App(Ir_ID);
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
	if( VPressKey.dnkey ==0x55)
	{
		VPressKey.dnkey =0;
		VDisplay.Direct |= FORWARD;
		VDisplay.LpTimer =10;
        PutTaskIntoQue(RefreshDisplayNumber);	
	}
	if( VPressKey.upkey ==0x55)
	{
		VPressKey.upkey =0;
		VDisplay.Direct |= BACKWARD;
		VDisplay.LpTimer =10;
        PutTaskIntoQue(RefreshDisplayNumber);
	}
	if(++VBaseTimer.T500ms >99)
	{				
		VBaseTimer.T500ms =0;
		PutTaskIntoQue(RTCPROC);        
		PutTaskIntoQue(PulseProc);//
        if(--VDisplay.LpTimer ==0)
        {
            VDisplay.LpTimer =10;
            PutTaskIntoQue(RefreshDisplayNumber);
        }
		else
		{
			PutTaskIntoQue(RefreshDisplay);
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
	//-------------------------------------------

}


/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
}
#endif
/**INDENT-ON**/
/// @endcond