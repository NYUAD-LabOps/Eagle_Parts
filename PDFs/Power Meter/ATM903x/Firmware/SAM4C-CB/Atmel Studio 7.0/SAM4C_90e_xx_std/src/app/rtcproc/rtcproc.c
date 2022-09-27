//===================================================================
#include "target.h"
//-------------------------------------------------------------------
const	uint8_t	TB_MonthDayTable[12]={0x31,0x28,0x31,0x30,0x31,0x30,0x31,0x31,0x30,0x31,0x30,0x31};
const	uint8_t	Month_WeekTable[12] ={0x00,0x03,0x03,0x06,0x01,0x04,0x06,0x02,0x05,0x00,0x03,0x05};

rtc_str    VRTC;
//-------------------------------------------------------------------

/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
extern "C" {
#endif
/**INDENT-ON**/
/// @endcond

//=========================================================
//decription	::	rtc.time data verify 
//function		::	Time_FormatChk
//Input			::	PP_Time->ss mm hh
//Output		::	1->rtc.time data is failure , 0 is ok
//call			::	N_Byte_BCDVerify
//effect		::	
//=========================================================
uint8_t	Time_FormatChk(uint8_t *PP_Time)
{
	if(N_Byte_BCDVerify(PP_Time, 3)) 
		return 0x01;
	if(*PP_Time > 0x59) 
		return 0x01;							
	if(*(PP_Time+1) > 0x59) 
		return 0x01;		
	if(*(PP_Time+2) > 0x23) 
		return 0x01;			

	return 0x00;
}
//=========================================================
//decription	::	rtc.date data verify 
//function		::	Date_FormatChk
//Input			::	PP_Date->week day month year
//Output		::	1->rtc.time data is failure , 0 is ok
//call			::	N_Byte_BCDVerify,BCD_8BIN
//effect		::	
//=========================================================
uint8_t	Date_FormatChk(uint8_t *PP_Date)
{
	uint8_t	Year,Month,Day;
	uint8_t	Temp1,Temp2;
	
	if(N_Byte_BCDVerify(PP_Date, 4)) 
		return 0x01;
	
	if(*(PP_Date+2)==0||*(PP_Date+2)>0x12)
		return	0x01;
			
	Temp1=TB_MonthDayTable[(BCD_8BIN(*(PP_Date+2))-1)];	
	if(((BCD_8BIN(*(PP_Date+3)))&0x03)==0)
 	{
 		if(*(PP_Date+2)==0x02)
 			Temp1++;		//if leap year then februray is 29 days
 	}
 	if(*(PP_Date+1)==0||*(PP_Date+1)>Temp1)
 	{
 		return(1);	
 	}
	
	Year=BCD_8BIN(*(PP_Date+3));
	Month=BCD_8BIN(*(PP_Date+2));
	Day=BCD_8BIN(*(PP_Date+1));	

	Temp1	=	Year /4;
	Temp2	=	Year+ Temp1;		//366 days one year.	
	Temp2	=	Temp2 % 0x07;
	Temp2	=	Temp2 + Day + Month_WeekTable[Month-1];
	if ( Year%4 == 0 &&Month <3)
		Temp2   -=	1;
	Temp2 += 6;				//2000/1/1 is Sat.
	*PP_Date = Temp2 % 7;
	if( *PP_Date ==0 )
    {
        *PP_Date =7;
    }
	return	(0);	
}
//=========================================================
//decription	::	rtc data verify 
//function		::	RTCData_Verify
//Input			::	ptr->ss mm hh week dd mm yy
//Output		::	1->rtc data is failure , 0 is ok
//call			::	Time_FormatChk,Date_FormatChk
//effect		::	
//=========================================================
uint8_t	RTCData_Verify(uint8_t *ptr)
{	
	if(Time_FormatChk(ptr)||Date_FormatChk(ptr+3))
	{
		return	(1);
	}
	else
	{	
 		return(0);
 	} 	
}
//===================================================================
//decription    ::  read RTC process
//function      ::  ReadRTCProcess
//input         ::  none
//output        ::  none
//call          ::  rtc_get_time,rtc_get_date,PutTaskIntoQue
//effect        ::  VRTC
//===================================================================
void    ReadRTCProcess(void)
{
	date_str	rtcdata;
	rtc_time_str	rtctime;
	rtc_str	temprtc;
	temprtc =VRTC;
	rtc_get_time(RTC, &rtctime.hour, &rtctime.minute, &rtctime.second);
	rtc_get_date(RTC, &rtcdata.year, &rtcdata.month, &rtcdata.day,&rtcdata.week);
	VRTC.second =(uint8_t)((rtctime.second/10)<<4);
	VRTC.second |=(uint8_t)(rtctime.second%10);
	VRTC.minute =(uint8_t)((rtctime.minute/10)<<4);
	VRTC.minute |=(uint8_t)(rtctime.minute%10);
	VRTC.hour =(uint8_t)((rtctime.hour/10)<<4);
	VRTC.hour |=(uint8_t)(rtctime.hour%10);
	VRTC.day =(uint8_t)((rtcdata.day/10)<<4);
	VRTC.day |=(uint8_t)(rtcdata.day%10);
	VRTC.month =(uint8_t)((rtcdata.month/10)<<4);
	VRTC.month |=(uint8_t)(rtcdata.month%10);
	VRTC.year =(uint8_t)(((rtcdata.year%100)/10)<<4);
	VRTC.year |=(uint8_t)(rtcdata.year%10);
	VRTC.week =(uint8_t)(rtcdata.week%10);
	//-----------------------------------------------------
	if( temprtc.minute != VRTC.minute )
	{
		PutTaskIntoQue(TOUProc);
	}
	//if( temprtc.month != VRTC.month )
	//{
	//	PutTaskIntoQue(HistoryDataSave);
	//}
	//-----------------------------------------------------	
}






/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
}
#endif
/**INDENT-ON**/
/// @endcond