//===================================================================
#include "eeprom.h"

/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
extern "C" {
#endif
/**INDENT-ON**/
/// @endcond

ErrFlag_Struct	VErrFlag;
u8	VWrE2SafeByte;
//=========================================================
//decription	::	EEprom write is enable
//function		::	WPEE0_ENABLE
//Input			::	none
//Output		::	eeprom_wp=0
//call			::	none
//effect		::	none
//=========================================================
void	WPEE0_ENABLE(void)
{
	I2C_WP_Low();
}
//=========================================================
//decription	::	EEprom write is disable
//function		::	WPEE0_DISABLE
//Input			::	none
//Output		::	eeprom_wp=1
//call			::	none
//effect		::	none
//=========================================================
void	WPEE0_DISABLE(void)
{
	I2C_WP_High();
}
//=========================================================
//decription	::	EEprom's vdd is open
//function		::	EEPROMOpen
//Input			::	none
//Output		::	none
//call			::	none
//effect		::	none
//=========================================================
void	EEPROMOpen (void)
{
	I2C_VDD_Out();
	I2C_VDD_High();
}
//=========================================================
//decription	::	EEprom's vdd is closed
//function		::	EEPROMClose
//Input			::	none
//Output		::	none
//call			::	none
//effect		::	none
//=========================================================
void	EEPROMClose (void)
{
	I2C_VDD_Out();
	I2C_VDD_Low();
}
//=========================================================
//decription	::	EEprom bus Inition
//function		::	BSP_E2promBus_Init
//Input			::	none
//Output		::	none
//call			::	I2C_START,I2C_STOP
//effect		::	none
//=========================================================
void	BSP_E2promBus_Init(void)
{
	EEPROMOpen();
	
	I2C_SDA_Out();
	I2C_SCL_Out();
	
	I2C_START();
	__NOP();
	__NOP();
	I2C_STOP();
	__NOP();
}
//=========================================================
//decription	::	read size byte data from e2prom by e2 bus
//function		::	EEPROMreader
//Input			::	offset->read E2 address
//					buffer->data ram pointer
//					size->read data len
//Output		::	read out data len
//call			::	I2C.aperator
//effect		::	if VErrFlag.BIT.RdE2ErrFlag=1 then e2 is error
//=========================================================
u16	EEPROMreader(u32 offset,u8 *buffer,u16 size)
{
	u8	WrDeviceAddr;
	u16 RdLen;
	u8	RdE2PgInAdr,RdE2PgAdr;
	u8 	count,len;
	u8	ptroffset=0;	
	WrDeviceAddr =WrE2_DeviceAddr;
	if(offset>>16)
	{
		WrDeviceAddr |=0x02;//high 16 bits address visitor
	}
//    RdLen =(u16)(offset);
	RdE2PgInAdr =(u8)(offset);
	RdE2PgAdr =(u8)(offset>>8);
	RdLen =0;
	while(size>0)
	{	
		VErrFlag.BIT.RdE2ErrFlag=1;
				
		I2C_START();		
		Write_I2C_1Byte(WrDeviceAddr);	//write device address
		if(VErrFlag.BIT.IIcNoAckFlag)
			break;		
		Write_I2C_1Byte(RdE2PgAdr);		//page in high address 
		if(VErrFlag.BIT.IIcNoAckFlag)
			break;
		Write_I2C_1Byte(RdE2PgInAdr);		//page in low address 
		if(VErrFlag.BIT.IIcNoAckFlag)
			break;
		
		I2C_START();
		Write_I2C_1Byte(WrDeviceAddr|0x01); 
		if(VErrFlag.BIT.IIcNoAckFlag)
			break;
		
		if(((RdE2PgInAdr%0x40)+size)>0x40)
		{
			len=((RdE2PgInAdr/0x40)+1)*0x40-RdE2PgInAdr;
		}//it is not finished
		else
		{
			len=size;
		}//it is finished
		for(count=0;count<len-1;count++)
		{
			*(buffer+count+ptroffset)=Read_I2C_1ByteAck();		
		}
		*(buffer+count+ptroffset)=Read_I2C_1ByteNoAck();
		VErrFlag.BIT.RdE2ErrFlag=0;

		I2C_STOP();		
		ptroffset=ptroffset+len;
		size=size-len;
		RdLen=RdLen-len;
		if((u8)(RdE2PgInAdr+len)<RdE2PgInAdr)
		{
			RdE2PgAdr++;
			if(RdE2PgAdr==0)
			{
				WrDeviceAddr |=0x02;//high 16 bits address visitor
			}
		}
		RdE2PgInAdr=RdE2PgInAdr+len;		
	}
	if(VErrFlag.BIT.RdE2ErrFlag)		
	{
		I2C_STOP();		
	}	
	return(RdLen);
}
//=========================================================
//decription	::	write n byte data to e2prom by e2 bus
//function		::	WriteE2promData
//Input			::	offset->write E2 address
//					buffer->data ram pointer
//					size->write data len
//Output		::	write to data len
//call			::	I2C.aperator
//effect		::	if VErrFlag.BIT.WrE2ErrFlag=1 then e2 is error
//=========================================================
u16	EEPROMwriter(u32 offset,u8 *buffer,u16 size)
{
	u8	WrDeviceAddr;
	u16 WrLen;
	u8	WrE2PageAddr,WrE2PageInAddr;
	u8 	count,len;
	u8	ptroffset=0;
	WrLen	=0;
	WrDeviceAddr =WrE2_DeviceAddr;
	if(offset>>16)
	{
		WrDeviceAddr |=0x02;//high 16 bits address visitor
	}
	WrE2PageAddr =(u8)(offset>>8);
	WrE2PageInAddr =(u8)(offset);
				
	while(size>0)
	{	
		VErrFlag.BIT.WrE2ErrFlag=1;			
		I2C_START();		
		Write_I2C_1Byte(WrDeviceAddr);		//device address
		if(VErrFlag.BIT.IIcNoAckFlag)
			break;		
		Write_I2C_1Byte(WrE2PageAddr);		//page in high address 
		if(VErrFlag.BIT.IIcNoAckFlag)
			break;
		Write_I2C_1Byte(WrE2PageInAddr);		//page in low address 
		if(VErrFlag.BIT.IIcNoAckFlag)
			break;				
		if(((WrE2PageInAddr%0x40)+size)>0x40)
		{
			len=((WrE2PageInAddr/0x40)+1)*0x40-WrE2PageInAddr;
		}//it is not finished
		else
		{
			len=size;
		}//it is finished
		for(count=0;count<len;count++)
		{
			Write_I2C_1Byte(*(buffer+count+ptroffset));
			if(VErrFlag.BIT.IIcNoAckFlag)
				break;	
		}
		if(count<len)
			break;	
		I2C_STOP();
		Delay_N_ms(WriteFMDelay_ms);
		
		WPEE0_ENABLE();			
		ptroffset=ptroffset+len;
		size=size-len;
		WrLen=WrLen+len;
		if((u8)(WrE2PageInAddr+len)<WrE2PageInAddr)
		{
			WrE2PageAddr++;
			if(WrE2PageAddr==0)
			{
				WrDeviceAddr |=0x02;//high 16 bit address
			}
		}
		WrE2PageInAddr=WrE2PageInAddr+len;		
	}	
	if(size==0)
	{
		VErrFlag.BIT.WrE2ErrFlag=0;		
	}
	else
	{		
		I2C_STOP();
	}
	WPEE0_DISABLE();	
	return(WrLen);
}
//=========================================================
//decription	::	get eeprom status
//function		::	EEPROMGetState
//Input			::	none
//Output		::	0=right,1=read e2 error,2=write e2 error
//call			::	none
//effect		::	none
//=========================================================
u8 EEPROMGetState(void)
{
	u8 i=0;
	if(VErrFlag.BIT.RdE2ErrFlag)
	{
		i |=1;
	}	
	if(VErrFlag.BIT.WrE2ErrFlag)
	{
		i |=2;
	}
	return (i);
} 
//================================================
//Description     ::	read E2 data with check code 
//Function        ::	RdE2DataCRC
//Input           ::	E2PgInAdr,ptr,len
//Output          ::	if failure return 1 else 0
//Call            ::	none
//Effect          ::
//===============================================
u8	RdE2DataCRC(u16 E2PgInAdr,u8 *ptr,u8 len)
{
	u8	i;
	u8	Buff[16];
	if(len ==0 || len >14 || ((E2PgInAdr&0x000F) +len)>15)
	{
		return (1);
	}
	for(i=0;i<3;i++)
	{
		EEPROMreader((E2PgInAdr&0xFFF0)+(0x100*i),&Buff[0],16);
		if(VErrFlag.BIT.RdE2ErrFlag)
		{
			break;
		}
		if(	CSandXOR_CheckGenerator(&Buff[0],14) )
		{
			continue;
		}
		COPYBYTEDATA((&Buff[0]+((u8)(E2PgInAdr)&0x0F)),ptr,len);//copy data
		break;
	}
	if(VErrFlag.BIT.RdE2ErrFlag || i==3)
	{
		return (1);
	}	
	return (0);
}
//================================================
//Description     ::	read E2 data with check code 
//Function        ::	RdE2DataCRC
//Input           ::	E2PgInAdr,ptr,len
//						VWrE2SafeByte =0x68
//Output          ::	if failure return 1 else 0
//Call            ::	none
//Effect          ::
//===============================================
u8	WrE2DataCRC(u16 E2PgInAdr,u8 *ptr,u8 len)
{
	u8	i;
	u8	Buff[16];
	if(len ==0 || len >14 || ((E2PgInAdr&0x000F) +len)>15)
	{
		VWrE2SafeByte=0;
		return (1);
	}    
	if( len !=14 )
	{
		for(i=0;i<3;i++)
		{
			EEPROMreader((E2PgInAdr&0xFFF0)+(0x100*i),&Buff[0],16);
			if(VErrFlag.BIT.RdE2ErrFlag)
			{
				VWrE2SafeByte=0;
				return (1);
			}
			if(	!(CSandXOR_CheckGenerator(&Buff[0],14)) )
			{
				break;
			}					
		}		
	}    
	COPYBYTEDATA(ptr,(&Buff[0]+((u8)(E2PgInAdr)&0x0F)),len);//copy data
	CSandXOR_CheckGenerator(&Buff[0],14);
	WPEE0_ENABLE();
	if(VWrE2SafeByte != Con_WrE2SafeByte)
	{		
		WPEE0_DISABLE();
		return(1);
	}
	EEPROMwriter(E2PgInAdr&0xFFF0,&Buff[0],16);
	if(VErrFlag.BIT.WrE2ErrFlag)
	{
		return (1);
	}
	EEPROMreader(E2PgInAdr&0xFFF0,&Buff[0],16);
	if(VErrFlag.BIT.RdE2ErrFlag)
		return (1);
	if( CSandXOR_CheckGenerator(&Buff[0],14) )
		return (1);
	WPEE0_ENABLE();	
	for(i=1;i<3;i++)
	{
		if(VWrE2SafeByte != Con_WrE2SafeByte)
		{		
			break;
		}
		EEPROMwriter(((E2PgInAdr&0xFFF0)+ 0x100*i),&Buff[0],16);
		if(VErrFlag.BIT.WrE2ErrFlag)
			break;
		WPEE0_ENABLE();
	}
	VWrE2SafeByte=0;
	WPEE0_DISABLE();
	if(i<3)
		return (1);
	else
		return (0);
}
//=========================================================
//decription	::	start I2C bus
//function		::	I2Cstart
//Input			::	none
//Output		::	none
//call			::	Delay_5_us
//effect		::
//=========================================================
void I2C_START(void) 
{	
	I2C_SDA_Out();
	I2C_SCL_Out();
	
	I2C_SDA_High();
	I2C_SCL_High();
	
	Delay_N_us(ByteDeley_us);
	
	I2C_SDA_Low();	

	Delay_N_us(ByteDeley_us);

	I2C_SCL_Low();
	
	Delay_N_us(ByteDeley_us);
}
//=========================================================
//decription	::	stop I2C bus
//function		::	I2C_STOP
//Input			::	none
//Output		::	none
//call			::	Delay_5_us
//effect		::	scl=0,sda=in
//=========================================================
void I2C_STOP(void)
{	
	I2C_SDA_In();

	while(!BIO_I2C_SDA)	
	{
		if(BIO_I2C_SCL)
			I2C_SCL_Low();
		else
			I2C_SCL_High();

		Delay_N_us(ByteDeley_us);	
	}	
	I2C_SCL_Low();
	
	I2C_SDA_Out();
	I2C_SCL_Out();
	
	I2C_SDA_Low();

	Delay_N_us(ByteDeley_us);

	I2C_SCL_High();

	Delay_N_us(ByteDeley_us);

	I2C_SDA_High();

	Delay_N_us(ByteDeley_us);
	
	I2C_SDA_In();
	I2C_SCL_Low();		 
}
//=========================================================
//decription	::	read one byte from I2C bus with ack
//function		::	Read_I2C_1ByteAck
//Input			::	none
//Output		::	read out data
//call			::	Delay_I2C()
//effect		::	scl=0,sda=0
//=========================================================
u8 Read_I2C_1ByteAck( void )
{
    u8	i;
    u8	I2C_RD_Data = 0;

    I2C_SCL_Low();
    I2C_SDA_In();
    I2C_SCL_Out();
    //	__disable_irq();
    for ( i = 0; i < 8; i++ )
    {
        Delay_N_us( ByteDeley_us );
        I2C_RD_Data = I2C_RD_Data << 1;
        I2C_SCL_High();

        Delay_N_us( ByteDeley_us );

        if ( BIO_I2C_SDA )
        {
            I2C_RD_Data = I2C_RD_Data | 0x01;
        }
        I2C_SCL_Low();
        //Delay_N_us(ByteDeley_us);
    }
    I2C_SDA_Low();
    I2C_SDA_Out();
    I2C_SDA_Low();

    Delay_N_us( ByteDeley_us );

    I2C_SCL_High();

    Delay_N_us( ByteDeley_us );

    I2C_SCL_Low();
	I2C_SDA_In();
    Delay_N_us( ByteDeley_us );
    //	__enable_irq();
    return ( I2C_RD_Data );
}
//=========================================================
//decription	::	read one byte from I2C bus without ack
//function		::	Read_I2C_1ByteNoAck
//Input			::	none
//Output		::	read out data
//call			::	Delay_I2C()
//effect		::	scl=0,sda=in
//=========================================================
u8 Read_I2C_1ByteNoAck( void )
{
    u8	i;
    u8	I2C_RD_Data = 0;

    I2C_SCL_Low();
    I2C_SDA_In();
    I2C_SCL_Out();
    //	__disable_irq();
    for ( i = 0; i < 8; i++ )
    {
        //Delay_N_us(ByteDeley_us);
        I2C_RD_Data = I2C_RD_Data << 1;
        I2C_SCL_High();

        Delay_N_us( ByteDeley_us );

        if ( BIO_I2C_SDA )
        {
            I2C_RD_Data = I2C_RD_Data | 0x01;
        }
        I2C_SCL_Low();
        Delay_N_us( ByteDeley_us );
    }
    I2C_SDA_High();
    I2C_SDA_Out();
    I2C_SDA_High();

    Delay_N_us( ByteDeley_us );

    I2C_SCL_High();

    Delay_N_us( ByteDeley_us );

    I2C_SCL_Low();
	Delay_N_us( ByteDeley_us );
    //	__enable_irq();
    return ( I2C_RD_Data );
}
//=========================================================
//decription	::	write one byte to I2C bus 
//function		::	Write_I2C_1Byte
//Input			::	write data
//Output		::	1=write is failure,0=write is success
//call			::	Delay_I2C()
//effect		::	scl=0,sda=in
//=========================================================
u8 Write_I2C_1Byte( u8 I2C_WR_data )
{
    u8	i, j;
    j = 0;
    I2C_SCL_Low();
    VErrFlag.BIT.IIcNoAckFlag = 1;
    I2C_SDA_Out();
    I2C_SCL_Out();
    //	__disable_irq();
    for ( i = 0; i < 8; i++ )
    {
        //Delay_N_us(ByteDeley_us);
        if ( ( I2C_WR_data & 0x80 ) != 0x80 )
        {
            I2C_SDA_Low();
        }
        else
        {
            I2C_SDA_High();
        }

        I2C_WR_data = I2C_WR_data << 1;

        Delay_N_us( ByteDeley_us );

        I2C_SCL_High();

        Delay_N_us( ByteDeley_us );

        I2C_SCL_Low();

        Delay_N_us( ByteDeley_us >> 1 );
    }//loop 8 num
    I2C_SDA_In();

    for ( i = 0; i < 3; i++ )
    {
        Delay_N_us( ByteDeley_us );
        I2C_SCL_High();
        Delay_N_us( ByteDeley_us );
        if ( !BIO_I2C_SDA )
        {
            j = 0;
            VErrFlag.BIT.IIcNoAckFlag = 0;
            break;
        }
        else
        {
            j = 1;
        }
    }
    I2C_SCL_Low();
    Delay_N_us( ByteDeley_us );
    //	__enable_irq();
    return ( j );
}
//=========================================================
//decription	::	delay n ms
//function		::	Delay_N_ms
//Input			::	val
//Output		::	none
//call			::	sysclk_get_cpu_hz()
//effect		::
//=========================================================
void	Delay_N_ms(uint16_t val)
{
	uint16_t	j;
	for(j=0;j<val;j++)
	{
		Delay_N_us(1330);	//1ms
	}
}
//=========================================================
//decription	::	delay n 4us
//function		::	Delay_N_4us
//Input			::	val
//Output		::	none
//call			::	sysclk_get_cpu_hz()
//effect		::
//=========================================================
void	Delay_N_us(uint16_t val)
{
	volatile uint32_t	f;
	uint32_t	j,k;	
	for(j=0;j<val;j++)
	{
		f=sysclk_get_cpu_hz();
		__NOP();
		__NOP();
		__NOP();
		for(k=0;k<(f/30000000)+1;k++)
		{
			//__NOP();
		}		
	}
}
//=========================================================
//decription	::	copy byte data from sptr to mptr
//function		::	COPYBYTEDATA
//Input			::	*sptr,*mptr
//					len
//Output		::	none
//call			::	none
//effect		::
//=========================================================
void	COPYBYTEDATA(u8 *sptr,u8 *mptr,u8 len)
{
	u8	i;
	for(i=0;i<len;i++)
	{
		*(mptr+i) =*(sptr+i);
	}
}
//=========================================================
//Description     ::	data cs and xor check & generator 
//Function        ::	CSandXOR_CheckGenerator
//Input           ::	ptr len
//Output          ::	1= crc is error 0= crc is ok
//Call            ::
//Effect          ::		
//=========================================================
u8	CSandXOR_CheckGenerator(u8 *ptr,u8 len)
{
	u8 i;		
	u8	CSTemp1;
	u8	XORTemp2;	
			
	CSTemp1=0;
	XORTemp2=0;
		
	for(i=0;i<len;i++)
	{
		CSTemp1=CSTemp1+*(ptr+i);
		XORTemp2=XORTemp2 ^ *(ptr+i);
	}
	if(CSTemp1==*(ptr+len)&&XORTemp2==*(ptr+len+1))
		i=0;
	else
		i=1;	
			
	*(ptr+len)=CSTemp1;
	*(ptr+len+1)=XORTemp2;
	
	return(i);
}




/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
}
#endif
/**INDENT-ON**/
/// @endcond

/**
 * \}
 */
