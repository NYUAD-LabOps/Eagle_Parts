//===================================================================
#include "target.h"
//-------------------------------------------------------------------

//-------------------------------------------------------------------

/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
extern "C" {
#endif
/**INDENT-ON**/
/// @endcond


//===================================================================
//decription    ::  check meter major parameter process
//function      ::  CheckMajorParaProcess
//input         ::  none
//output        ::  none
//call          ::  none
//effect        ::  none
//===================================================================
void    CheckMajorParaProcess(void)
{
	uint8_t	buff[5];
	RestoreRamEnergyFromEprom();
//	RdE2DataCRC( ((E2TouPgAdr<<8)+E2Tou1Adr),(uint8_t *)(&VTou.table[0]),12);
//	RdE2DataCRC( ((E2TouPgAdr<<8)+E2Tou5Adr),(uint8_t *)(&VTou.table[4]),12);
	RdE2DataCRC( ((E2TouPgAdr<<8)+E2MeterIDAdr),&VCom.meterIECID[0],14);
	COPYBYTEDATA( &VCom.meterIECID[0],&VCom.meter645ID[0],6);
	
	RdE2DataCRC( (RdE2Page0Addr<<8)+E2DisplayOnOffAdr,&(buff[0]),5 );
	VDisplay.GapTimer =(uint8_t)(buff[4]);	
	VDisplay.OnOffFlag0 =(uint32_t)(buff[3]);                          
	VDisplay.OnOffFlag0 =VDisplay.OnOffFlag0 <<8;                            
	VDisplay.OnOffFlag0 |=(uint32_t)(buff[2]);                            
	VDisplay.OnOffFlag0 =VDisplay.OnOffFlag0 <<8;                           
	VDisplay.OnOffFlag0 |=(uint32_t)(buff[1]);                           
	VDisplay.OnOffFlag0 =VDisplay.OnOffFlag0 <<8;                            
	VDisplay.OnOffFlag0 |=(uint32_t)(buff[0]);
	VDisplay.OnOffFlag0 =VDisplay.OnOffFlag0 <<1;
	VDisplay.OnOffFlag0 |=1;
    VDisplay.OnOffFlag1 =0x61;  //display rtc and total energy							
	VDisplay.OnOffFlag1 =VDisplay.OnOffFlag1 <<1;
	if( (buff[3])&0x80 )
	{
		VDisplay.OnOffFlag1 |=1;
	}
	if( VAFE.id ==AT90E25 || VAFE.id ==AT90E24 || VAFE.id==AT90E23 )
	{
		RdE2DataCRC( E2_AT90E2x_UIScal,(uint8_t *)(&VAFE.ulscal.HFWORD),2 );
	}
	else
	{
		RdE2DataCRC( E2_AT90E3x_UIScal,(uint8_t *)(&VAFE.ulscal.HFWORD),2 );
	}
    if( (VAFE.ulscal.BIT.U_SCALE)>8 )
    {
        VAFE.ulscal.BIT.U_SCALE =4;
    }
    if( (VAFE.ulscal.BIT.I_SCALE)>8 )
    {
        VAFE.ulscal.BIT.I_SCALE =5;
    }  
}



/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
}
#endif
/**INDENT-ON**/
/// @endcond