//===================================================================
#include "target.h"

/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
extern "C" {
#endif
/**INDENT-ON**/
/// @endcond


ENERGY_TYPE	VEnergy;
//=========================================================
//description	::	read current traffic energy decimal
//function		::	ReadEnergyDecimal
//input			::	E2PgInAdr,*ptr ram
//output		::	*(ptr+2) ram if BRdE2ErrFlag=1 then failure
//call			::	EEPROMreader,BIN_TO_BCD
//effcet		::  
//decare ::	*ptr->posit where the first data is not 0xFF
//			*(ptr+1)->value that the first data is not 0xFF
//			*(ptr+2)->energy decimal bcd value
//=========================================================
void	ReadEnergyDecimal(uint16_t E2PgInAddr,uint8_t *ptrram)
 {
 	uint8_t i;
 	uint8_t j;
 	uint8_t Buff[0x0d]; 	
 	 	
 	EEPROMreader( E2PgInAddr,&Buff[0],0x0d);
 	if(VErrFlag.BIT.RdE2ErrFlag)
 		return;
 	*ptrram=0;
 	*(ptrram+1)=0;
 	*(ptrram+2)=0;
 	for(i=0;i<12;i++)
 	{
 		if(Buff[i]==0xff)
 		{
 			(*ptrram)++;
 			*(ptrram+2)+=0x08;
 		}
 		else
 		{
 			if(Buff[i+1]==0xff)
 			{
 				if(Buff[i+2]==0xff)
 				{
 					(*ptrram)++;
 					*(ptrram+2)+=0x08;
 				}
 				else
 					break;
 			}
 			else
 				break;
 		} 		
 	}
 	j=Buff[i];
 	*(ptrram+1)=j;
 	for(i=0;i<8;i++)
 	{
 		if((j&0x80)!=0)
 		{
 			*(ptrram+2)=*(ptrram+2)+1;
 			j=j<<1;
 		}
 		else
 		{
 			break;
 		}
 	}
 	*(ptrram+2)=(uint8_t)BIN_TO_BCD(*(ptrram+2));
}
//=========================================================
//describe	::	energy process
//function	::	EnergyServe
//input		::	VWriteDLSafeByte,E2ZenPgInAdr,E2XSPgInAdr
//output	::	*ptr ram if BRdE2ErrFlag=1 then failure
//call		::	ReadDiangLiangXS
//effect	::
//=========================================================
void	EnergyServe(uint16_t E2IntegerPgInAdr,uint32_t E2DecimalPgInAdr)
{
 	uint8_t i;
 	uint8_t Buff[3]={0,0,0};
    uint8_t Buff1[16];
 	uint16_t m;
 	uint8_t j=0; 
 	uint8_t BDLOverFlag=0;
	m =E2DecimalPgInAdr;
 	for(i=16;i>0;i--)
 	{
		Buff1[i]=0;
	}
 	VWrE2SafeByte=0x40;//write e2 safebyte pre2  	
 	ReadEnergyDecimal(E2DecimalPgInAdr,&Buff[0]);//read decimal energy; 			
 	if(VErrFlag.BIT.RdE2ErrFlag)
 		return; 	
 	for(i=0;i<8;i++)
 	{
 		if((Buff[1]&0x80)!=0)
 		{
 			j =j>>1;
 			j |=0x80; 
 			Buff[1] =Buff[1]<<1;			
 		}
 		else 		
 		{
			break;
		}
 	}//total 1
 	Buff[1]=j;	//save decimal
 	if(Buff[0]>12)
 	{
 		return;
 	}
 	if(Buff[0]==12 && Buff[1]>0xE0)
 	{
 		Buff[1]=0x80;
 	}

 	if(Buff[0]==12 && Buff[1]==0xE0)
 	{
 		BDLOverFlag=1;//it is over
		RdE2DataCRC(  E2IntegerPgInAdr,&Buff1[1],4);//read integer energy
 		
 		VWrE2SafeByte|=0x20;		//write e2 safebyte pre1
 		if(VErrFlag.BIT.RdE2ErrFlag)
 		{
 			while(1);
 		}
 		Buff1[1]=0;
 		Buff1[6]=0;
 		Buff1[7]=0x01;
 		Buff1[8]=0;
 		Buff1[9]=0;
 		i=BCD_8_Add(&Buff1[6],&Buff1[1]); 	 	 	
 		Buff1[0]=0x68;
 		Buff1[5]=0x68;
	
 		VWrE2SafeByte |=0x08;		//write e2 safebyte allow
 		WrE2DataCRC( (E2IntegerPgInAdr-1),&Buff1[0],6);//write integer energy
 		
 		WPEE0_ENABLE();//enable e2 write
 		
 		if(VErrFlag.BIT.WrE2ErrFlag)
 		{
 			while(1);
 		}	
 		for(i=13;i>0;i--)
			Buff1[i]=0;
		EEPROMwriter( E2DecimalPgInAdr,&Buff1[0],13);//clear energy decimal;	
	
 		if(VErrFlag.BIT.WrE2ErrFlag)
 		{
 			while(1);
 		}	 		
 		RdE2DataCRC( E2IntegerPgInAdr&0xFFF0,&Buff1[0],14);
		
 		if(VErrFlag.BIT.RdE2ErrFlag)
 		{
 			while(1);
 		}	
 		Buff1[(E2IntegerPgInAdr&0x0F)-1]=0;
 		Buff1[(E2IntegerPgInAdr&0x0F)+4]=0;
 		CSandXOR_CheckGenerator(&Buff1[0],14);	
 					
 		WPEE0_ENABLE();//enable e2 write
 				
 		if(BDLOverFlag!=1)//
 		{
 			while(1);
 		}	
 		EEPROMwriter( E2IntegerPgInAdr&0xFFF0,&Buff1[0],16);
 		if(VErrFlag.BIT.WrE2ErrFlag) 	
 		{
 			while(1);
 		}	 
 	}//energy = 1 kwh
 	else
 	{ 		
 		if(Buff[1]==0xff)
 		{
 			Buff[1]=0xE0;
 		} 	
 		Buff[1] =Buff[1]>>1;			//
 		Buff[1] |=0x80;		//decimal+0.01
 	
 		WPEE0_ENABLE();//enable e2 write
 		//i=E2DecimalPgInAdr+Buff[0];		//E2PgInAdr+offset
		//m =E2DecimalPgInAdr;
		m +=Buff[0];		
		EEPROMwriter( m,&Buff[1],1);
		__NOP();
 	}//energy < 1 kwh

	//=============================================
	WPEE0_DISABLE();//disable e2 write
	VWrE2SafeByte=0;
}
//===============================================
//description	::	restore ram energy from eeprom
//fuction		::	RestoreRamEnergyFromEprom
//input			::	none
//output		::	none
//call			::	RdE2DataCRC,ReadEnergyDecimal
//effect		::	
//===============================================
void	RestoreRamEnergyFromEprom(void)
{
	uint32_t	i;
	uint32_t	val;
	uint32_t	e2intadr,e2decadr;
    uint8_t     buff[13];
	ENERGY_Str *ptr;
	e2intadr =(E2CurEnergyPgAdr<<8) + E2Tou1EnergyAdr;
	e2decadr =E2Tou1EnergyDecAddr;
	ptr =&VEnergy.tou1;
	for(i=0;i<4;i++)
	{
		if( RdE2DataCRC( e2intadr,(uint8_t *)(&val),4 ) )
			break;
		ptr->integer =val;
		ReadEnergyDecimal( e2decadr,&buff[0]);
		if(VErrFlag.BIT.RdE2ErrFlag)
			break;		
		ptr->integer &=0xFFFFFF00;
		ptr->integer |=(uint32_t)(buff[2]);//
		e2intadr +=0x08;
		e2decadr +=0x10;
		ptr ++;
	}
	ptr =&VEnergy.tou1;
	VEnergy.total.integer=0;	
	for(i=0;i<4;i++)
	{
		BCD_8_Add( (uint8_t *)((&ptr->integer)),(uint8_t *)(&VEnergy.total.integer) );
        ptr ++;
	}
}
//===================================================================
//decription    ::  addition culate pulse energy
//function      ::  Add_PulseEnergy
//input         ::  val
//output        ::  none
//call          ::  none
//effect        ::  VEnergy
//===================================================================
void	Add_PulseEnergy(uint32_t val)
{		
	VEnergy.pulse +=val;
}
//===================================================================
//decription    ::  clear energy
//function      ::  Clear_Energy
//input         ::  VWrE2SafeByte=0x68
//output        ::  none
//call          ::  none
//effect        ::  VEnergy
//===================================================================
void	Clear_Energy(void)
{
	uint32_t	i;
	uint32_t	e2adr;
	uint32_t	buff[4];
	for(i=0;i<4;i++)
		buff[i]=0;
	e2adr =E2CurEnergyPgAdr;
    e2adr =e2adr<<8;
    e2adr +=E2Tou1EnergyAdr;
	for(i=0;i<2;i++)
	{
		if( VWrE2SafeByte!=0x68 )
			break;
		WrE2DataCRC(e2adr+(i<<4),(uint8_t *)(&buff[0]),14);
		if(VErrFlag.BIT.WrE2ErrFlag)
			break;
		VWrE2SafeByte =0x68;
	}
	WPEE0_ENABLE();
	if(i<2)
	{
		VWrE2SafeByte =0;
		WPEE0_DISABLE();
		return;
	}
	e2adr =E2Tou1EnergyDecAddr;
	for(i=0;i<4;i++)
	{
		EEPROMwriter(e2adr+(i<<4),(uint8_t *)(&buff[0]),16);
		if(VErrFlag.BIT.WrE2ErrFlag)
			break;
		WPEE0_ENABLE();
	}
	if(i<4)
	{
		WPEE0_DISABLE();
		return;
	}
	e2adr =E2_RW_HistoryEnergyPgAdr;
	e2adr =e2adr<<8;
	e2adr +=E2Pre1Tou1EnergyAdr;	
	for(i=0;i<12;i++)
	{
		EEPROMwriter(e2adr+(i<<4),(uint8_t *)(&buff[0]),16);
		if(VErrFlag.BIT.WrE2ErrFlag)
			break;
		WPEE0_ENABLE();
	}	
	if(i>=12)
	{
		VEnergy.pulse =0;
		VEnergy.total.pulse =0;
		VEnergy.total.integer =0;
		VEnergy.tou1.pulse =0;
		VEnergy.tou1.integer =0;
		VEnergy.tou2.pulse =0;
		VEnergy.tou2.integer =0;
		VEnergy.tou3.pulse =0;
		VEnergy.tou3.integer =0;
		VEnergy.tou4.pulse =0;
		VEnergy.tou4.integer =0;
	}
	WPEE0_DISABLE();
}
//===================================================================
//decription    ::  pulse add process
//function      ::  PulseProcess
//input         ::  none
//output        ::  none
//call          ::  none
//effect        ::  VEnergy.pulse
//===================================================================
void	PulseProcess(void)
{
	__disable_irq();
	VEnergy.pulse +=(VAFE.IntNum[CF1]);//+VAFE.IntNum[CF2]+VAFE.IntNum[CF3]+VAFE.IntNum[CF4]);
	VAFE.IntNum[CF1] =0;
	VAFE.IntNum[CF2] =0;
	VAFE.IntNum[CF3] =0;
	VAFE.IntNum[CF4] =0;	
	__enable_irq();
	if( (VEnergy.pulse)/MeterConst )
	{
		PutTaskIntoQue(EnergyProc);
	}
}
//===================================================================
//decription    ::  energy add process
//function      ::  EnergyProcess
//input         ::  none
//output        ::  none
//call          ::  none
//effect        ::  VEnergy
//===================================================================
void	EnergyProcess(void)
{
	volatile uint32_t	i;
	uint32_t	e2intadr,e2decadr;
	ENERGY_Str *ptr;
    
    ptr =&VEnergy.tou3;
    e2decadr =E2Tou3EnergyDecAddr;
    e2intadr =E2CurEnergyPgAdr;
    e2intadr = e2intadr<<8;
	e2intadr +=E2Tou3EnergyAdr;
/*		
	switch(VTou.type)
	{
		case	TOU1:
		{
			ptr =&VEnergy.tou1;
			e2decadr =E2Tou1EnergyDecAddr;
			e2intadr =E2Tou1EnergyAdr;			
		}
		break;
		case	TOU2:
		{
			ptr =&VEnergy.tou2;
			e2decadr =E2Tou2EnergyDecAddr;
			e2intadr =E2Tou2EnergyAdr;		
		}		
		break;
		case	TOU4:
		{
			ptr =&VEnergy.tou4;
			e2decadr =E2Tou4EnergyDecAddr;
			e2intadr =E2Tou4EnergyAdr;			
		}		
		break;
		default	:
		{
			ptr =&VEnergy.tou3;
			e2decadr =E2Tou3EnergyDecAddr;
			e2intadr =E2Tou3EnergyAdr;		
		}		
		break;
	}//end switch vtou.type
*/
	if( (VEnergy.pulse)/MeterConst )
	{
		i =(VEnergy.pulse)/MeterConst;
		VEnergy.pulse =(VEnergy.pulse)%MeterConst;
		while( i )
		{
			EnergyServe( (uint16_t)(e2intadr),e2decadr );
			i--;
		}
		RestoreRamEnergyFromEprom();
	}//endif (0.01kWh)
}




/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
}
#endif
/**INDENT-ON**/
/// @endcond

