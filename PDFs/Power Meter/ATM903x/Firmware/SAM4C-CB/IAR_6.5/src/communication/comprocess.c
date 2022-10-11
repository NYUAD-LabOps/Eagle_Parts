//===================================================================
#include "target.h"
//-------------------------------------------------------------------
extern sys_t	        sys;		    // system parameters

COM_Str    VCom;
//-------------------------------------------------------------------

/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
extern "C" {
#endif
/**INDENT-ON**/
/// @endcond

//===================================================================
//decription    ::  UART0 interrupt process
//function      ::  UART0_IrqHandler
//input         ::  none
//output        ::  none
//call          ::  UART_IntProc
//effect        ::  none
//===================================================================
void UART0_IrqHandler(void)
{	  
	UART_IntProc( UART0,&VCom.Rs485 );
}
//===================================================================
//decription    ::  UART1 interrupt process
//function      ::  UART1_IrqHandler
//input         ::  none
//output        ::  none
//call          ::  UART_IntProc
//effect        ::  none
//===================================================================
void	UART1_IrqHandler(void)
{	  
	UART_IntProc( UART1,&VCom.IR );	
}
//===================================================================
//decription    ::  UART interrupt process
//function      ::  UART_IntProc
//input         ::  UARTx,ptr
//output        ::  none
//call          ::  none
//effect        ::  none
//===================================================================
void UART_IntProc(Uart *UARTx,UART_str *ptr)
{	  
	uint32_t ul_status;
	uint8_t data;
	TASK_CONST	taskid;
	//Read USART Status.
	ul_status = uart_get_status(UARTx);//read uart status
	
	if(ptr->state ==CMDPROCESS || ptr->state ==SEND)
	{
        uart_read(UARTx, &data);//read uart receive register
		return;
	}
	switch(ptr->protocolmode)
	{
		/*
		case	IEC_PROTOCOL:
		{
			if( ptr->state !=SEND )
			{
				if ( !(ul_status & US_CSR_RXRDY) )
				{
					break;
				}
				if( ptr==&VCom.Rs485 )
				{
					taskid =Rs485CmdProc;					
				}
				if( ptr==&VCom.IR )
				{
					taskid =IrCmdProc;					
				}
				uart_read(UARTx, &data);//read uart receive register
				ptr->overtimer =0;
				//-----------DLT645 or IEC protocol check------------
				if( ptr->offset ==0)
				{
					if( data ==0xFE )
					{
						__NOP();
						ptr->protocolmode =DLT645_PROTOCOL;
						__NOP();
						break;
					}
				}//endif (offset==0)
				//------------IEC protocol receive data--------------				
				if( ptr->iecstep==IEC_STEP19 )
				{
					switch(ptr->state ==FREE)
					{	
						case	FREE:
						{
							ptr->offset =0;
							ptr->state =IEC_STX_SYMB;
						}	
						case	IEC_STX_SYMB:						
						{
							if( data==SOH_SYMB )	//"SOH"
							{
								ptr->state =IEC_ETX_SYMB;
								ptr->Flag.BIT.First68Flag =1;								
							}
							else
							{
								ptr->state =FREE;
							}
						}
						break;						
						case	IEC_ETX_SYMB:
						{
							if( data==ETX_SYMB )	//"ETX"
							{
								ptr->state =IEC_BCC_SYMB;
								ptr->Flag.BIT.Second68Flag =1;
							}						
						}
						break;
						case	IEC_BCC_SYMB:
						{
							ptr->state =CMDPROCESS;
							ptr->Flag.BIT.OneFrameFlag =1;							
							PutTaskIntoQue_INT(taskid);
						}
						break;
					}//end switch(ptr->state)
				}//endif (iec_step19)
				else
				{
					ptr->state =CMDPROCESS;
					PutTaskIntoQue_INT(taskid);
				}//endif else				
				ptr->buff[ptr->offset]=data;
				if(++ptr->offset >=FRAME_MAX_LEN )
				{
					ptr->state =FREE;
					ptr->Flag.BYTE &=IEC_FRAME_SAVE_FLAG;//resave IEC_DeviceAddr,RdPassword,WrPassword
					ptr->offset =0;
				}				
			}//endif( !=SEND )
			else
			{
			}//it is (SEND)
		}//end case IEC
		break;
		*/
		case	DLT645_PROTOCOL:
		{
			if( ptr->state !=SEND )
			{
				if ( !(ul_status & US_CSR_RXRDY) )
				{
                  break;
				}
				if( ptr==&VCom.Rs485 )
				{
					taskid =Rs485CmdProc;					
				}
				if( ptr==&VCom.IR )
				{
					taskid =IrCmdProc;					
				}
				uart_read(UARTx, &data);//read uart receive register
				ptr->overtimer =0;			
				switch(ptr->state)
				{
					case	FREE:
					{
						//if( data==0 )
						//{
							ptr->state =BAUDMONITOR;
							ptr->offset =0;
							ptr->Flag.BYTE =0;
							volatile int i = sysclk_get_cpu_hz();
							const sam_uart_opt_t uart_console_settings =
									{ i, ptr->baud_ID, UART_MR_PAR_EVEN };
							uart_init(UARTx, &uart_console_settings);						
						//}
					}
					break;
					case	BAUDMONITOR:
					{
						if( data==LEADER_SYMB )
						{
							ptr->state =LEADER;
						}
						else
						{
							if( data==FRAMESYNC_SYMB )
							{
								ptr->state =FRAMESYNC_SYMB;
								ptr->offset=4;
								ptr->Flag.BIT.First68Flag =1;
							}
						}
					}
					break;
					case	LEADER:
					{
						if( data==FRAMESYNC_SYMB )
						{
							ptr->state =FRAMESYNC_SYMB;
							ptr->offset=4;
							ptr->Flag.BIT.First68Flag =1;
						}
					}
					break;
					case	FRAMESYNC_SYMB:
					{
						if( ptr->offset ==11 )
						{
							if( data==DATASYNC_SYMB )
							{
								ptr->state =RECDATA;
								ptr->Flag.BIT.Second68Flag =1;
							}
							else
							{
								ptr->state =FREE;
								ptr->Flag.BYTE =0;
								ptr->offset =0;
							}						
						}
					}
					break;				
					case	RECDATA:
					{
						if( data==FRAMETAIL_SYMB )
						{
							if( ptr->offset >= (ptr->buff[13]+15) )//(ptr->len +15) )
							{
								ptr->state =CMDPROCESS;
								ptr->Flag.BIT.OneFrameFlag =1;
								PutTaskIntoQue_INT(taskid);
							}					
						}
					}
					break;
					default:
					break;				
				}//end switch(ptr->state)
				ptr->buff[ptr->offset]=data;
				if(++ptr->offset >=FRAME_MAX_LEN )
				{
					ptr->state =FREE;
					ptr->Flag.BYTE =0;
					ptr->offset =0;
				}
			}//endif (ptr->state !=SEND)
			else
			{
				if(ul_status&US_CSR_TXRDY)
				{
					if( ptr->state ==SEND )
					{
						if( ptr->len ==0 || ptr->offset >=FRAME_MAX_LEN )
						{
							ptr->state =FREE;
							ptr->Flag.BYTE =0;
							ptr->offset =0;
						}
						else
						{
							uart_write(UARTx,ptr->buff[++ptr->offset]);				
							ptr->len--;
						}
					}				
				}//endif (ul_status&US_CSR_TXRDY)
			}//it is send status
		}//end case DLT645
		break;
		default :
		break;
	}
}
//===================================================================
//decription    ::  USART2 interrupt process
//function      ::  USART2_IrqHandler
//input         ::  none
//output        ::  none
//call          ::  USART_IntProc
//effect        ::  none
//===================================================================
void	USART2_IrqHandler(void)
{	
	USART_IntProc( USART2,&VCom.ZigBee );	
}
//===================================================================
//decription    ::  USART3 interrupt process
//function      ::  USART3_IrqHandler
//input         ::  none
//output        ::  none
//call          ::  USART_IntProc
//effect        ::  none
//===================================================================
void	USART3_IrqHandler(void)
{	  
	USART_IntProc( USART3,&VCom.PLC );	
}
//===================================================================
//decription    ::  USART interrupt process
//function      ::  USART_IntProc
//input         ::  Usartx,ptr
//output        ::  none
//call          ::  PutTaskIntoQue_INT
//effect        ::  none
//===================================================================
void	USART_IntProc(Usart *Usartx,UART_str *ptr)
{	  
	uint32_t ul_status;
	uint8_t data;
	//Read USART Status.
	ul_status = usart_get_status(Usartx);//read uart status   

	if(ptr->state ==CMDPROCESS || ptr->state ==SEND)
	{
		data =(Usartx->US_RHR & US_RHR_RXCHR_Msk); //read uart receive register        
		return;
	}
	switch(ptr->protocolmode)
	{	
		case	DLT645_PROTOCOL:
		{
			if( ptr->state !=SEND )
			{
				if ( !(ul_status & US_CSR_RXRDY) )
				{
                  break;
				}
				data =(Usartx->US_RHR & US_RHR_RXCHR_Msk); //read uart receive register
				ptr->overtimer =0;			
				switch(ptr->state)
				{
					case	FREE:
					{
						ptr->state =BAUDMONITOR;
						ptr->offset =0;
						ptr->Flag.BYTE =0;							
					}
					break;
					case	BAUDMONITOR:
					{
						if( data==LEADER_SYMB )
						{
							ptr->state =LEADER;
						}
						else
						{
							if( data==FRAMESYNC_SYMB )
							{
								ptr->state =FRAMESYNC_SYMB;
								ptr->offset=4;
								ptr->Flag.BIT.First68Flag =1;
							}
						}
					}
					break;
					case	LEADER:
					{
						if( data==FRAMESYNC_SYMB )
						{
							ptr->state =FRAMESYNC_SYMB;
							ptr->offset=4;
							ptr->Flag.BIT.First68Flag =1;
						}
					}
					break;
					case	FRAMESYNC_SYMB:
					{
						if( ptr->offset ==11 )
						{
							if( data==DATASYNC_SYMB )
							{
								ptr->state =RECDATA;
								ptr->Flag.BIT.Second68Flag =1;
							}
							else
							{
								ptr->state =FREE;
								ptr->Flag.BYTE =0;
								ptr->offset =0;
							}						
						}
					}
					break;				
					case	RECDATA:
					{
						if( data==FRAMETAIL_SYMB )
						{
							if( ptr->offset >= (ptr->buff[13]+15) )//(ptr->len +15) )
							{
								ptr->state =CMDPROCESS;
								ptr->Flag.BIT.OneFrameFlag =1;
								
								if( ptr==&VCom.ZigBee)
								{	
									ul_status =ZigBeeCmdProc;									
								}							
								if( ptr==&VCom.PLC)
								{	
									ul_status =PLCCmdProc;									
								}
								PutTaskIntoQue_INT((TASK_CONST)(ul_status));
							}					
						}
					}
					break;
					default:
					break;				
				}//end switch(ptr->state)
				ptr->buff[ptr->offset]=data;
				if(++ptr->offset >=FRAME_MAX_LEN )
				{
					ptr->state =FREE;
					ptr->Flag.BYTE =0;
					ptr->offset =0;
				}
			}//endif (ptr->state !=SEND)
			/*
			else
			{
				if(ul_status&US_CSR_TXRDY)
				{
					if( ptr->state ==SEND )
					{
						if( ptr->len ==0 || ptr->offset >=FRAME_MAX_LEN )
						{
							ptr->state =FREE;
							ptr->Flag.BYTE =0;
							ptr->offset =0;
						}
						else
						{
							Usartx->US_THR =ptr->buff[++ptr->offset];			
							ptr->len--;
						}
					}				
				}//endif (ul_status&US_CSR_TXRDY)
			}//it is send status
			*/
		}//end case DLT645
		break;
		default :
		break;
	}
}
//===================================================================
//decription    ::  inition usart process
//function      ::  Init_Usart
//input         ::  uart_id
//output        ::  none
//call          ::  uart_init
//effect        ::  none
//===================================================================
void	Init_Usart_App(UART_TYPE uart_id)
{
	volatile int i;
	Usart *Usartx;
	UART_str *ptr;
	uint32_t	check_code;
	switch( uart_id )
	{		
		case	ZigBee_ID:
		{
			gpio_configure_pin(PIN_USART2_RXD_IDX, PIN_USART2_RXD_FLAGS);
			gpio_configure_pin(PIN_USART2_TXD_IDX, PIN_USART2_TXD_FLAGS);			
			gpio_configure_pin(PIN_USART2_RTS_IDX, PIN_USART2_RTS_FLAGS);
			gpio_configure_pin(PIN_USART2_RE_IDX,  PIN_USART2_RE_FLAGS);
			gpio_set_pin_low(PIN_USART2_RE_IDX);	//usart2 is receive status			
			pmc_enable_periph_clk(ID_USART2);
					
			Usartx =USART2;
			ptr =&VCom.ZigBee;
		}
		break;
		case	PLC_ID:
		{
			gpio_configure_pin(PIN_USART3_RXD_IDX, PIN_USART3_RXD_FLAGS);
			gpio_configure_pin(PIN_USART3_TXD_IDX, PIN_USART3_TXD_FLAGS);			
			gpio_configure_pin(PIN_USART3_RTS_IDX, PIN_USART3_RTS_FLAGS);
			gpio_configure_pin(PIN_USART3_RE_IDX,  PIN_USART3_RE_FLAGS);
			gpio_set_pin_low(PIN_USART3_RE_IDX);	//usart3 is receive status
			pmc_enable_periph_clk(ID_USART3);
			
			Usartx =USART3;
			ptr =&VCom.PLC;
		}
		break;		
	}//
	i =	sysclk_get_cpu_hz();	
	
	switch( ptr->baud_sym )
	{		
		case	0x40:
		{
			ptr->baud_ID =Baud_9600;			
		}
		break;
		case	0x20:
		{
			ptr->baud_ID =Baud_4800;			
		}
		break;
		case	0x10:
		{
			ptr->baud_ID =Baud_2400;			
		}
		break;
		case	0x08:
		{
			ptr->baud_ID =Baud_1200;			
		}
		break;
		case	0x04:
		{
			ptr->baud_ID =Baud_600;			
		}
		break;
		case	0x02:
		{
			ptr->baud_ID =Baud_300;			
		}
		break;
		default:
			ptr->baud_ID =Baud_4800;
	}
	check_code =US_MR_PAR_EVEN;
	ptr->protocolmode =DLT645_PROTOCOL;
	ptr->Flag.BYTE =0;	
	ptr->offset =0;		
	ptr->len =0;
	ptr->overtimer =0;
	ptr->sendtimer =0;    
	ptr->state =FREE;
	
	const sam_usart_opt_t usart_console_settings =
						{ ptr->baud_ID,US_MR_CHRL_8_BIT, check_code, US_MR_NBSTOP_1_BIT, US_MR_USART_MODE_RS485,0};		
	usart_init_rs485( Usartx, &usart_console_settings, i );
	usart_enable_rx(Usartx);
	usart_enable_tx(Usartx);
	
	usart_enable_interrupt(Usartx,US_IER_RXRDY);
	switch( uart_id )
	{
		case	ZigBee_ID:
		{
			NVIC_EnableIRQ(USART2_IRQn);
		}
		break;		
		case	PLC_ID:
		{
			NVIC_EnableIRQ(USART3_IRQn);
		}
		break;
	}	
}
//===================================================================
//decription    ::  inition uart process
//function      ::  Init_Uart
//input         ::  uart_id
//output        ::  none
//call          ::  uart_init
//effect        ::  none
//===================================================================
void	Init_Uart_App(UART_TYPE uart_id)
{
	volatile int i;
	Uart *Uartx;
	UART_str *ptr;
	uint32_t	mode=0;
	switch( uart_id )
	{
		case	Rs485_ID:
		{
			Uartx =UART0;
			ptr =&VCom.Rs485;
			
			pio_configure(PINS_UART0_PIO, PINS_UART0_TYPE, PINS_UART0_MASK,PINS_UART0_ATTR);
			pmc_enable_periph_clk(ID_UART0);
		}
		break;
		case	Ir_ID:
		{
			PMC->CKGR_PLLAR =0;	//disable plla
			
			Uartx =UART1;
			ptr =&VCom.IR;
			
			pio_configure(PINS_UART1_PIO, PINS_UART1_TYPE, PINS_UART1_MASK,PINS_UART1_ATTR);
			pmc_enable_periph_clk(ID_UART1);

			PMC->CKGR_PLLAR =0x00BC6401;	//mul=188,count=100,en=1
			while( (PMC->PMC_SR & PMC_SR_LOCKA)==0 );
			mode |=UART_MR_OPT_CLKDIV(12) | UART_MR_OPT_DUTY_DUTY_50 | UART_MR_OPT_MDINV_DISABLED | UART_MR_OPT_EN_DISABLED; 
			//UART1->UART_MR |=UART_MR_OPT_CLKDIV(12) | UART_MR_OPT_DUTY_DUTY_50 | UART_MR_OPT_MDINV_DISABLED | UART_MR_OPT_EN_DISABLED; 
		}
		break;
	}//
	i =	sysclk_get_cpu_hz();
	if (uart_id==Rs485_ID )
	{
		switch( ptr->baud_sym )
		{
			case	0x80:
			{
				ptr->baud_ID =Baud_115200;			
			}
			break;
			case	0x40:
			{
				ptr->baud_ID =Baud_9600;			
			}
			break;
			case	0x20:
			{
				ptr->baud_ID =Baud_4800;			
			}
			break;
			case	0x10:
			{
				ptr->baud_ID =Baud_2400;			
			}
			break;
			case	0x08:
			{
				ptr->baud_ID =Baud_1200;			
			}
			break;
			case	0x04:
			{
				ptr->baud_ID =Baud_600;			
			}
			break;
			case	0x02:
			{
				ptr->baud_ID =Baud_300;			
			}
			break;
			default:
				ptr->baud_ID =Baud_4800;
		}
	}
	if (uart_id==Ir_ID )
	{
		ptr->baud_ID =Baud_1200;		
	}
	ptr->Flag.BYTE =0;
	/*	
	if( ptr->protocolmode ==DLT645_PROTOCOL )
	{
		ptr->baud_ID =IEC_HandShake_BD;
		ptr->Flag.BYTE =0;
		ptr->iecstep =IEC_STEP0;
	}//
	else
	{
		switch(ptr->iecstep)
		{
			//case	IEC_STEP0:
			//case	IEC_STEP1:
			//case	IEC_STEP2:
			//case	IEC_STEP3:
			//case	IEC_STEP4:
			//case	IEC_STEP5:
			//case	IEC_STEP6:
			//case	IEC_STEP7:
			//case	IEC_STEP8:
			//case	IEC_STEP9:
			//case	IEC_STEP10:			
			//{
			//	baud_hz =IEC_HandShake_BD;
			//	ptr->iecstep =IEC_STEP0;
			//}	
			//break;
			case	IEC_STEP11:
			case	IEC_STEP12:
			case	IEC_STEP13:
			case	IEC_STEP14:
			case	IEC_STEP15:
			case	IEC_STEP16:	
			case	IEC_STEP17:
			case	IEC_STEP18:
			{	
				ptr->baud_ID =IEC_Protocol_BD;				
				ptr->iecstep =IEC_STEP11;				
			}
			break;
			case	IEC_STEP19:
			{
				ptr->baud_ID =IEC_Protocol_BD;
				ptr->Flag.BYTE &=IEC_FRAME_SAVE_FLAG;//resave IEC_DeviceAddr,RdPassword,WrPassword
				ptr->iecstep =IEC_STEP19;
			}
			break;
			default:
			{
				ptr->baud_ID =IEC_HandShake_BD;
				ptr->iecstep =IEC_STEP0;
				ptr->Flag.BYTE =0;
			}
			break;
		}
	}
	*/
	mode |=UART_MR_PAR_EVEN;//UART_MR_PAR_NO;
	ptr->offset =0;		
	ptr->len =0;
	ptr->overtimer =0;
	ptr->sendtimer =0;    
	ptr->state =FREE;
	ptr->protocolmode =DLT645_PROTOCOL;//IEC_PROTOCOL;
	const sam_uart_opt_t uart_console_settings =
						{ i, ptr->baud_ID, mode };
	uart_init(Uartx, &uart_console_settings);
	
	uart_enable_interrupt(Uartx, US_IER_RXRDY);
	if( uart_id==Rs485_ID )
	{
		NVIC_EnableIRQ(UART0_IRQn);
	}
	if( uart_id==Ir_ID )
	{
		//Uartx->UART_MR |=( UART_MR_OPT_EN_ENABLED | UART_MR_OPT_CMPTH_VDDIO_DIV2 | UART_MR_OPT_DUTY_DUTY_50 | UART_MR_OPT_CLKDIV(18) );//F=(Fmck*10/10)/8/(18+8)=
		NVIC_EnableIRQ(UART1_IRQn);
	}
}
//===================================================================
//decription    ::  communication send process
//function      ::  ComSendProcess
//input         ::  uart_id
//output        ::  none
//call          ::  none
//effect        ::  none
//===================================================================
void	ComSendProcess(UART_TYPE uart_id)
{
	TASK_CONST sendid;		
	UART_str	*ptr;
	ptr =&VCom.Rs485;
	if( uart_id== Ir_ID )
	{
		ptr =&VCom.IR;
		//--------------modulation send--------------------
        UART1->UART_MR |=UART_MR_OPT_CLKDIV(12) | UART_MR_OPT_DUTY_DUTY_50 | UART_MR_OPT_MDINV_DISABLED; 
		UART1->UART_MR |=UART_MR_OPT_EN_ENABLED; 
		//-------------------------------------------------		
	}
	if( uart_id== PLC_ID )
	{
		ptr =&VCom.PLC;
	}
	if( uart_id== ZigBee_ID )
	{
		ptr =&VCom.ZigBee;
	}
	if( ptr->state ==SEND )
	{
		if( (ptr->len !=0) && (ptr->offset <FRAME_MAX_LEN) )
		{	
			switch(uart_id)
			{
				case	Rs485_ID:
				{
					uart_write(UART0,ptr->buff[ptr->offset++]);
					while( !(uart_get_status(UART0) & US_CSR_TXRDY) );
					sendid =Rs485Transmit;
				}
				break;
				case	Ir_ID:
				{
					uart_write(UART1,ptr->buff[ptr->offset++]);
					while( !(uart_get_status(UART1) & US_CSR_TXRDY) );
					sendid =IrTransmit;
				}
				break;
				case	ZigBee_ID:
				{
					gpio_set_pin_high(PIN_USART2_RE_IDX);	//usart2 is send status
					usart_write(USART2,ptr->buff[ptr->offset++]);
					while( !(usart_get_status(USART2) & US_CSR_TXRDY) );
					sendid =ZigBeeTransmit;
				}
				break;					
				case	PLC_ID:
				{
					usart_write(USART3,ptr->buff[ptr->offset++]);
					while( !(usart_get_status(USART3) & US_CSR_TXRDY) );
					sendid =PLCTransmit;						
				}
				break;
			}	
			if(--ptr->len !=0)
			{
				PutTaskIntoQue(sendid);
				ptr->overtimer =0;
			}
			else
			{
				ptr->overtimer =57;
			}					
		}		
	}
}

//===================================================================
//decription    ::  communication protocol process
//function      ::  ComProcess
//input         ::  uart_id
//output        ::  none
//call          ::  none
//effect        ::  none
//===================================================================
void    ComProcess(UART_TYPE uart_id)
{
	uint32_t	i,j;
	uint32_t	cmd;
	uint32_t	len;
	uint32_t	ErrType;
	uint32_t	buff[32];
    UART_str	*ptr;
	ptr =&VCom.Rs485;
	if( uart_id== Ir_ID )
	{
		ptr =&VCom.IR;
	}
	if( uart_id== PLC_ID )
	{
		ptr =&VCom.PLC;
	}
	if( uart_id== ZigBee_ID )
	{
		ptr =&VCom.ZigBee;
	}
	if( ptr->protocolmode ==DLT645_PROTOCOL )
	{
		VWrE2SafeByte =0x40;
		//-------------meter id judge----------------------
		for(i=0;i<6;i++)
		{
			if( ptr->buff[5+i] !=0x99)
				break;
		}
		if( i>=6 )
		{
			ptr->Flag.BIT.BroadID =1;
		}//it is broad ID
		else
		{
			for(i=0;i<6;i++)
			{
				if( ptr->buff[5+i] !=0xAA)
					break;
			}
			if( i>=6 )
			{
				ptr->Flag.BIT.GlobleID =1;
			}//it is global ID
			else
			{
				for(i=0;i<6;i++)
				{
					if( ptr->buff[5+i] !=VCom.meter645ID[i] )
						break;
				}
				if(i>=6)
				{
					ptr->Flag.BIT.MeterID =1;
				}//it is Merter ID
				else
				{
					for(j=i;j<6;j++)
					{
						if(ptr->buff[5+j] !=0xAA)
							break;
					}
					if(j>=6)
					{
						ptr->Flag.BIT.GlobleMeterID =1;
					}//it is 
					else
					{
						Init_Uart_App(uart_id);
						VWrE2SafeByte =0;
						return;
					}
				}//it is not Merter ID
			}//it is not globle ID
		}//it is not broad ID
		//--------------cs check---------------------------
		for(j=0,i=0;i<(ptr->buff[13]+10);i++)
		{
			j+= ptr->buff[4+i];
		}
		if( (j&0xFF)!=ptr->buff[4+i] )
		{
			Init_Uart_App(uart_id);
			VWrE2SafeByte =0;  
			return;
		}
		VWrE2SafeByte |=0x20;
		//-------------data -0x33--------------------------
		for(i=0;i<(ptr->buff[13]);i++)
		{
			ptr->buff[14+i] -=0x33;
		}
		cmd =(uint32_t)( ptr->buff[17]);
		cmd =cmd<<8;
		cmd |=(uint32_t)( ptr->buff[16]);
		cmd =cmd<<8;
		cmd |=(uint32_t)( ptr->buff[15]);
		cmd =cmd<<8;
		cmd |=(uint32_t)( ptr->buff[14]);
		//-------------------------------------------------
		ErrType =0x80;	
		
		switch( ptr->buff[12] )
		{
			case	0x01:
			{
				ErrType =0x01;
				if( ptr->buff[15]==0xC0 && ptr->buff[14]==0x32 )
				{
					COPYBYTEDATA( &VCom.meter645ID[0],(uint8_t * )(&(ptr->buff[16])),6);
					len =6+2;
					ErrType =0x13;					
				}//cmd=C032
				if( ptr->buff[15]==0xC0 && ptr->buff[14]==0x11 )
				{
					COPYBYTEDATA( &VRTC.second,(uint8_t * )(&(ptr->buff[16])),3);
					len =3+2;
					ErrType =0x13;					
				}//cmd=C011
				if( ptr->buff[15]==0xC0 && ptr->buff[14]==0x10 )
				{
					COPYBYTEDATA( &VRTC.day,(uint8_t * )(&(ptr->buff[17])),3);
					ptr->buff[16] =VRTC.week;
					len =4+2;
					ErrType =0x13;					
				}//cmd=C010
				if( ptr->buff[15]==0xC2 && ptr->buff[14]==0x01 )
				{
					ptr->buff[16] =(uint8_t)(VDisplay.OnOffFlag0>>1);
					ptr->buff[17] =(uint8_t)(VDisplay.OnOffFlag0>>9);
					ptr->buff[18] =(uint8_t)(VDisplay.OnOffFlag0>>17);
					ptr->buff[19] =(uint8_t)(VDisplay.OnOffFlag0>>25);
					if( VDisplay.OnOffFlag1&0x1 )
					{
						ptr->buff[19] |=0x80;
					}
					ptr->buff[20] =VDisplay.GapTimer;						
					len =5+2;
					ErrType =0x13;
				}//cmd=C201
				if( ptr->buff[15]==0xD0 || ptr->buff[15]==0xD1 || ptr->buff[15]==0xD2 || ptr->buff[15]==0xD8 )
				{	
					if( (VAFE.id==AT90E25 ||VAFE.id==AT90E24 ||VAFE.id==AT90E23 ) && ptr->buff[15]>0xD0 )
					{
						break;
					}
					if( (VAFE.id==AT90E32AS) && (ptr->buff[15]==0xD0 && (ptr->buff[14]>0xAF && ptr->buff[14]<0xCC) ) )
					{
						VAFE.measure_en_timer =3;
					}					
					CMD_Rd_AFE_Reg( &(ptr->buff[16]),(uint16_t)(cmd&0xFFF) );
					len =2+2;
					ErrType =0x13;
				}//cmd=D0/D1/D2/D8_xx
				if( ptr->buff[15]==0xE0 )
				{
					if( ptr->buff[14]==0x10 )
					{						
                        if( VAFE.id ==AT90E25 || VAFE.id ==AT90E24 || VAFE.id ==AT90E23 )
                        {
                            ptr->buff[16] =AT90E25;
                        }
                        else
                        {
                            ptr->buff[16] =VAFE.id;
                        }
						len =1+2;
						ErrType =0x13;
					}
					if( ptr->buff[14]==0x30 )
					{
						if( (VAFE.id!=AT90E25) && (VAFE.id!=AT90E24) && (VAFE.id!=AT90E23) )
						{
							ptr->buff[16] =(uint8_t)VAFE.runmode;	//afe work mode
							
							len =1+2;
							ErrType =0x13;
						}	
					}
					if( ptr->buff[14]==0x50 )
					{
						ptr->buff[16] =0;		//read afe pin status
						if(BIO_AFE_IRQ0)
						{
							ptr->buff[16] |=2;
						}
						if( (VAFE.id!=AT90E25) && (VAFE.id!=AT90E24) && (VAFE.id!=AT90E23) )
						{
							if(BIO_AFE_IRQ1)
							{
								ptr->buff[16] |=4;
							}
						}						
						if(BIO_AFE_WARMOUT)
						{
							ptr->buff[16] |=1;
						}
						len =1+2;
						ErrType =0x13;
					}
					if( ptr->buff[14]==0x70 )
					{
						ptr->buff[16] =(uint8_t)(VAFE.ulscal.BIT.U_SCALE);
						ptr->buff[17] =(uint8_t)(VAFE.ulscal.BIT.I_SCALE);
						len =2+2;
						ErrType =0x13;
					}
					if( ptr->buff[14]>0x7F && ptr->buff[14]<(0x7F+RMS_Num_Max) )
					{
						ptr->buff[16] =(uint8_t)(VAFE.RMS[ptr->buff[14]-0x7F]);
						ptr->buff[17] =(uint8_t)(VAFE.RMS[ptr->buff[14]-0x7F]>>8);
						ptr->buff[18] =(uint8_t)(VAFE.RMS[ptr->buff[14]-0x7F]>>16);
						ptr->buff[19] =(uint8_t)(VAFE.RMS[ptr->buff[14]-0x7F]>>24);
						
						len =4+2;
						ErrType =0x13;
					}//read RMS data
				}//cmd=E0xx
				if( ptr->buff[15]==0xF0 )
				{
					if( VAFE.thd_status ==IsSuccess )
					{
						VAFE.RMS[AI_HRx] =Calculate_I_V_HarmonicRatio( 0x100 + ptr->buff[14]-1 );
						ptr->buff[16] =(uint8_t)(VAFE.RMS[AI_HRx]);
						ptr->buff[17] =(uint8_t)(VAFE.RMS[AI_HRx]>>8);
						ptr->buff[18] =(uint8_t)(VAFE.RMS[AI_HRx]>>16);
						ptr->buff[19] =(uint8_t)(VAFE.RMS[AI_HRx]>>24);
						
						VAFE.RMS[AI_THD] =Calculate_I_V_HarmonicRatio( 0x11F );
						ptr->buff[20] =(uint8_t)(VAFE.RMS[AI_THD]);
						ptr->buff[21] =(uint8_t)(VAFE.RMS[AI_THD]>>8);
						ptr->buff[22] =(uint8_t)(VAFE.RMS[AI_THD]>>16);
						ptr->buff[23] =(uint8_t)(VAFE.RMS[AI_THD]>>24);
						
						VAFE.RMS[BI_HRx] =Calculate_I_V_HarmonicRatio( 0x120 + ptr->buff[14]-1 );
						ptr->buff[24] =(uint8_t)(VAFE.RMS[BI_HRx]);
						ptr->buff[25] =(uint8_t)(VAFE.RMS[BI_HRx]>>8);
						ptr->buff[26] =(uint8_t)(VAFE.RMS[BI_HRx]>>16);
						ptr->buff[27] =(uint8_t)(VAFE.RMS[BI_HRx]>>24);
						
						VAFE.RMS[BI_THD] =Calculate_I_V_HarmonicRatio( 0x13F );
						ptr->buff[28] =(uint8_t)(VAFE.RMS[BI_THD]);
						ptr->buff[29] =(uint8_t)(VAFE.RMS[BI_THD]>>8);
						ptr->buff[30] =(uint8_t)(VAFE.RMS[BI_THD]>>16);
						ptr->buff[31] =(uint8_t)(VAFE.RMS[BI_THD]>>24);
						
						VAFE.RMS[CI_HRx] =Calculate_I_V_HarmonicRatio( 0x140 + ptr->buff[14]-1 );
						ptr->buff[32] =(uint8_t)(VAFE.RMS[CI_HRx]);
						ptr->buff[33] =(uint8_t)(VAFE.RMS[CI_HRx]>>8);
						ptr->buff[34] =(uint8_t)(VAFE.RMS[CI_HRx]>>16);
						ptr->buff[35] =(uint8_t)(VAFE.RMS[CI_HRx]>>24);
						
						VAFE.RMS[CI_THD] =Calculate_I_V_HarmonicRatio( 0x15F );
						ptr->buff[36] =(uint8_t)(VAFE.RMS[CI_THD]);
						ptr->buff[37] =(uint8_t)(VAFE.RMS[CI_THD]>>8);
						ptr->buff[38] =(uint8_t)(VAFE.RMS[CI_THD]>>16);
						ptr->buff[39] =(uint8_t)(VAFE.RMS[CI_THD]>>24);
						
						VAFE.RMS[AV_HRx] =Calculate_I_V_HarmonicRatio( 0x160 + ptr->buff[14]-1 );
						ptr->buff[40] =(uint8_t)(VAFE.RMS[AV_HRx]);
						ptr->buff[41] =(uint8_t)(VAFE.RMS[AV_HRx]>>8);
						ptr->buff[42] =(uint8_t)(VAFE.RMS[AV_HRx]>>16);
						ptr->buff[43] =(uint8_t)(VAFE.RMS[AV_HRx]>>24);
						
						VAFE.RMS[AV_THD] =Calculate_I_V_HarmonicRatio( 0x17F );
						ptr->buff[44] =(uint8_t)(VAFE.RMS[AV_THD]);
						ptr->buff[45] =(uint8_t)(VAFE.RMS[AV_THD]>>8);
						ptr->buff[46] =(uint8_t)(VAFE.RMS[AV_THD]>>16);
						ptr->buff[47] =(uint8_t)(VAFE.RMS[AV_THD]>>24);
						
						VAFE.RMS[BV_HRx] =Calculate_I_V_HarmonicRatio( 0x180 + ptr->buff[14]-1 );
						ptr->buff[48] =(uint8_t)(VAFE.RMS[BV_HRx]);
						ptr->buff[49] =(uint8_t)(VAFE.RMS[BV_HRx]>>8);
						ptr->buff[50] =(uint8_t)(VAFE.RMS[BV_HRx]>>16);
						ptr->buff[51] =(uint8_t)(VAFE.RMS[BV_HRx]>>24);
						
						VAFE.RMS[BV_THD] =Calculate_I_V_HarmonicRatio( 0x19F );
						ptr->buff[52] =(uint8_t)(VAFE.RMS[BV_THD]);
						ptr->buff[53] =(uint8_t)(VAFE.RMS[BV_THD]>>8);
						ptr->buff[54] =(uint8_t)(VAFE.RMS[BV_THD]>>16);
						ptr->buff[55] =(uint8_t)(VAFE.RMS[BV_THD]>>24);
						
						VAFE.RMS[CV_HRx] =Calculate_I_V_HarmonicRatio( 0x1A0 + ptr->buff[14]-1 );
						ptr->buff[56] =(uint8_t)(VAFE.RMS[CV_HRx]);
						ptr->buff[57] =(uint8_t)(VAFE.RMS[CV_HRx]>>8);
						ptr->buff[58] =(uint8_t)(VAFE.RMS[CV_HRx]>>16);
						ptr->buff[59] =(uint8_t)(VAFE.RMS[CV_HRx]>>24);
						
						VAFE.RMS[CV_THD] =Calculate_I_V_HarmonicRatio( 0x1BF );
						ptr->buff[60] =(uint8_t)(VAFE.RMS[CV_THD]);
						ptr->buff[61] =(uint8_t)(VAFE.RMS[CV_THD]>>8);
						ptr->buff[62] =(uint8_t)(VAFE.RMS[CV_THD]>>16);
						ptr->buff[63] =(uint8_t)(VAFE.RMS[CV_THD]>>24);
						
						VAFE.RMS[AI_FUND] =Calculate_I_V_Fundamental( 0x1C0,1000*(1<<(VAFE.dft_scale.BIT.DFT_AI)) );
						ptr->buff[64] =(uint8_t)(VAFE.RMS[AI_FUND]);
						ptr->buff[65] =(uint8_t)(VAFE.RMS[AI_FUND]>>8);
						ptr->buff[66] =(uint8_t)(VAFE.RMS[AI_FUND]>>16);
						ptr->buff[67] =(uint8_t)(VAFE.RMS[AI_FUND]>>24);
						
						VAFE.RMS[AV_FUND] =Calculate_I_V_Fundamental( 0x1C1,100*(1<<(VAFE.dft_scale.BIT.DFT_AV)) );
						ptr->buff[68] =(uint8_t)(VAFE.RMS[AV_FUND]);
						ptr->buff[69] =(uint8_t)(VAFE.RMS[AV_FUND]>>8);
						ptr->buff[70] =(uint8_t)(VAFE.RMS[AV_FUND]>>16);
						ptr->buff[71] =(uint8_t)(VAFE.RMS[AV_FUND]>>24);
						
						VAFE.RMS[BI_FUND] =Calculate_I_V_Fundamental( 0x1C2,1000*(1<<(VAFE.dft_scale.BIT.DFT_BI)) );
						ptr->buff[72] =(uint8_t)(VAFE.RMS[BI_FUND]);
						ptr->buff[73] =(uint8_t)(VAFE.RMS[BI_FUND]>>8);
						ptr->buff[74] =(uint8_t)(VAFE.RMS[BI_FUND]>>16);
						ptr->buff[75] =(uint8_t)(VAFE.RMS[BI_FUND]>>24);
						
						VAFE.RMS[BV_FUND] =Calculate_I_V_Fundamental( 0x1C3,100*(1<<(VAFE.dft_scale.BIT.DFT_BV)) );
						ptr->buff[76] =(uint8_t)(VAFE.RMS[BV_FUND]);
						ptr->buff[77] =(uint8_t)(VAFE.RMS[BV_FUND]>>8);
						ptr->buff[78] =(uint8_t)(VAFE.RMS[BV_FUND]>>16);
						ptr->buff[79] =(uint8_t)(VAFE.RMS[BV_FUND]>>24);
						
						VAFE.RMS[CI_FUND] =Calculate_I_V_Fundamental( 0x1C4,1000*(1<<(VAFE.dft_scale.BIT.DFT_CI)) );
						ptr->buff[80] =(uint8_t)(VAFE.RMS[CI_FUND]);
						ptr->buff[81] =(uint8_t)(VAFE.RMS[CI_FUND]>>8);
						ptr->buff[82] =(uint8_t)(VAFE.RMS[CI_FUND]>>16);
						ptr->buff[83] =(uint8_t)(VAFE.RMS[CI_FUND]>>24);
						
						VAFE.RMS[CV_FUND] =Calculate_I_V_Fundamental( 0x1C5,100*(1<<(VAFE.dft_scale.BIT.DFT_CV)) );			
						ptr->buff[84] =(uint8_t)(VAFE.RMS[CV_FUND]);
						ptr->buff[85] =(uint8_t)(VAFE.RMS[CV_FUND]>>8);
						ptr->buff[86] =(uint8_t)(VAFE.RMS[CV_FUND]>>16);
						ptr->buff[87] =(uint8_t)(VAFE.RMS[CV_FUND]>>24);
						
						len =(18<<2)+2;		//18*4+2						
						ErrType =0x13;						
					}
					else
					{
						ErrType =0x01;
					}
				}//cmd=F0xx
			}//DL/T645-1997 read command
			break;
			case	0x04:
			{	
				ErrType =0x01;
				if( ptr->buff[15]==0xA0 )
				{
					if( ptr->buff[16]!=0x00 || ptr->buff[17]!=0x33 || ptr->buff[18]!=0x33 || ptr->buff[19]!=0x33 )
					{
						ErrType =0x02;
						break;
					}
				}
				else
				{
					if( ptr->buff[16]!=0x01 || ptr->buff[17]!=0x11 || ptr->buff[18]!=0x11 || ptr->buff[19]!=0x11 )
					{
						ErrType =0x02;
						break;
					}
				}
				switch( ptr->buff[15] )
				{
					case	0xA0:
					{
						switch( ptr->buff[14] )
						{
							case	0x50:
							{								
								if( (VAFE.id==AT90E25) || (VAFE.id==AT90E24) || (VAFE.id==AT90E23) )
								{
									j =E2_AT90E2x_FunEn;
									i =E2_AT90E2x_UIScal;
									len =4;
								}
								else
								{
									j =E2_AT90E3x_000_Register;
									i =E2_AT90E3x_UIScal;
									len =18;
								}
								buff[0]=0x101;
								VWrE2SafeByte |=0x08;
								if( WrE2DataCRC( (uint16_t)(i),(uint8_t *)(buff[0]),2) )
								{
									break;
								}
								VWrE2SafeByte =0x68;
								for(i=0;i<16;i++)
									buff[i]=0;								
								for(i=0;i<len;i++)
								{								
									if( WrE2DataCRC( (uint16_t)(j),(uint8_t *)(buff[0]),14) )
									{
										break;
									}
									j =j<<4;
									VWrE2SafeByte =0x68;
								}
								if(i>=len)
								{
									ErrType =0x14;
								}
							}//inition E2prom
							break;
							case	0x51:
							{
								VWrE2SafeByte |=0x08;
								if( (VAFE.id==AT90E25) || (VAFE.id==AT90E24) || (VAFE.id==AT90E23) )
								{
									for(i=0;i<(AFE90E2x_cmd_reg_E2_NumMax/7);i++)
									{
										for(j=0;j<7;j++)
										{										
											CMD_Rd_AFE_Reg( (uint8_t *)(&buff[0])+(uint16_t)(j<<1),afe90e2x_cmd_reg_e2adr_tbl[(i*7)+j].regadr );
										}
										WrE2DataCRC( afe90e2x_cmd_reg_e2adr_tbl[i*7].e2adr,(uint8_t *)(buff[0]),14);
										VWrE2SafeByte =0x68;
									}
									if( (i*7)<AFE90E2x_cmd_reg_E2_NumMax )
									{
										for(j=0;j<(AFE90E2x_cmd_reg_E2_NumMax-(i*7));j++)
										{										
											CMD_Rd_AFE_Reg( (uint8_t *)(&buff[0])+(uint16_t)(j<<1),afe90e2x_cmd_reg_e2adr_tbl[(i*7)+j].regadr );
										}
										WrE2DataCRC( afe90e2x_cmd_reg_e2adr_tbl[(i<<3)-i].e2adr,(uint8_t *)(buff[0]),j<<1);										
									}
								}
								else
								{									
									for(i=0;i<(AFE90E3x_cmd_reg_E2_NumMax/8);i++)
									{
										for(j=0;j<8;j++)
										{										
											CMD_Rd_AFE_Reg( (uint8_t *)(&buff[0])+(uint16_t)(j<<1),afe90e3x_cmd_reg_e2adr_tbl[(i*8)+j].regadr );
										}
										EEPROMwriter( afe90e3x_cmd_reg_e2adr_tbl[i*8].e2adr,(uint8_t *)(buff[0]),16);
										//VWrE2SafeByte =0x68;
									}
									if( (i*8)<AFE90E3x_cmd_reg_E2_NumMax )
									{
										for(j=0;j<(AFE90E3x_cmd_reg_E2_NumMax-(i*8));j++)
										{										
											CMD_Rd_AFE_Reg( (uint8_t *)(&buff[0])+(uint16_t)(j<<1),afe90e3x_cmd_reg_e2adr_tbl[(i*8)+j].regadr );
										}
										EEPROMwriter( afe90e3x_cmd_reg_e2adr_tbl[(i<<3)].e2adr,(uint8_t *)(buff[0]),j<<1);										
									}
								}
                                ErrType =0x14;
							}//save calibration data to E2prom
							break;
							case	0x52:
							{
								
							}//write configure data to AFE
							break;
							case	0x53:
							{
								//xxStart write to 0x5678
							}
							break;
							case	0x54:
							{
								//xxStart write to 0x8765
							}
							break;
							case	0x55:
							{
								//auto read cs and write
							}
							break;
							case	0xA1:
							{
								Load_AFE_Cal_Para_From_Eprom();
                                ErrType =0x14;
							}//read calibration data from E2prom and write AFE
							break;
						}
					}//DL/T645-1997 extend command
					break;
					case	0xC0:
					{
						if(ptr->buff[14]==0x11)
						{
                            ptr->buff[20] =BCD_8BIN( ptr->buff[20] );
                            ptr->buff[21] =BCD_8BIN( ptr->buff[21] );
                            ptr->buff[22] =BCD_8BIN( ptr->buff[22] );
                            
							rtc_set_time(RTC, (uint32_t)(ptr->buff[22]), (uint32_t)(ptr->buff[21]),(uint32_t)(ptr->buff[20]) );
							PutTaskIntoQue(ReadRTC);
							ErrType =0x14;							
						}//end case 0x11
						if(ptr->buff[14]==0x10)
						{
                            ptr->buff[20] =BCD_8BIN( ptr->buff[20] );
                            if( ptr->buff[20]==0 )
                            {
                                ptr->buff[20] =7;
                            }  
                            ptr->buff[21] =BCD_8BIN( ptr->buff[21] );
                            ptr->buff[22] =BCD_8BIN( ptr->buff[22] );
                            ptr->buff[23] =BCD_8BIN( ptr->buff[23] );
                            
							if( rtc_set_date(RTC, (uint32_t)(ptr->buff[23]),(uint32_t)(ptr->buff[22]), (uint32_t)(ptr->buff[21]),(uint32_t)(ptr->buff[20]) ) )
                            {
                              ErrType =0x02;
                            }
                            else
                            {
                              ErrType =0x14;
                            }
							PutTaskIntoQue(ReadRTC);
							
						}//end case 0x10
					}//cmd =C0xx
					break;
                    case	0xC1:
                    {
                        if(ptr->buff[14]==0x19)
                        {
							VWrE2SafeByte =0x68;
							Clear_Energy();
							VDisplay.Number =DISPLAY_TOTAL_ENERGY;
							VDisplay.LpTimer =10;//display 5s=10*500ms
				
							ErrType =0x14;
						}
                    }//end case 0x14
                    break;
					case	0xC2:
					{
						if( ptr->buff[14]==0x01 )
						{
							VWrE2SafeByte |=0x08;					
							VDisplay.OnOffFlag0 =(uint32_t)(ptr->buff[23]);                          
							VDisplay.OnOffFlag0 =VDisplay.OnOffFlag0 <<8;                            
							VDisplay.OnOffFlag0 |=(uint32_t)(ptr->buff[22]);                            
							VDisplay.OnOffFlag0 =VDisplay.OnOffFlag0 <<8;                           
							VDisplay.OnOffFlag0 |=(uint32_t)(ptr->buff[21]);                           
							VDisplay.OnOffFlag0 =VDisplay.OnOffFlag0 <<8;                            
							VDisplay.OnOffFlag0 |=(uint32_t)(ptr->buff[20]);
							VDisplay.OnOffFlag0 =VDisplay.OnOffFlag0 <<1;
							VDisplay.OnOffFlag0 |=1;
                            VDisplay.OnOffFlag1 =0x61;  //display rtc and total energy							
							VDisplay.OnOffFlag1 =VDisplay.OnOffFlag1 <<1;
							if( (ptr->buff[23])&0x80 )
							{
								VDisplay.OnOffFlag1 |=1;
							}
                            VDisplay.GapTimer =(uint8_t)(ptr->buff[24]);
							WrE2DataCRC( (WrE2Page0Addr<<8)+E2DisplayOnOffAdr,&(ptr->buff[20]),5 );
							ErrType =0x14;
						}//C201
					}//cmd =C2xx
					break;
					case	0xD0:					
					{
						VWrE2SafeByte |=0x08;
						if( (VAFE.id==AT90E25) || (VAFE.id==AT90E24) || (VAFE.id==AT90E23) )
						{
							for(i=0;i<AFE90E2x_cmd_reg_E2_NumMax;i++)
							{
								if( afe90e2x_cmd_reg_e2adr_tbl[i].cmd == (uint16_t)(cmd&0xFFFF) )
								{
									break;
								}
							}
							if(i<AFE90E2x_cmd_reg_E2_NumMax)
							{
								WrE2DataCRC( afe90e2x_cmd_reg_e2adr_tbl[i].e2adr,&(ptr->buff[20]),2 );
								CMD_Wr_AFE_Reg( &(ptr->buff[20]),afe90e2x_cmd_reg_e2adr_tbl[i].regadr );
								ErrType =0x14;
							}
							else
							{
								CMD_Wr_AFE_Reg( &(ptr->buff[20]),(uint16_t)(cmd&0xFF) );
								ErrType =0x14;
							}							
						}
						else
						{
							for(i=0;i<AFE90E3x_cmd_reg_E2_NumMax;i++)
							{
								if( afe90e3x_cmd_reg_e2adr_tbl[i].cmd == (uint16_t)(cmd&0xFFFF) )
								{
									break;
								}
							}
							if(i<AFE90E3x_cmd_reg_E2_NumMax)
							{
								//WrE2DataCRC( afe90e3x_cmd_reg_e2adr_tbl[i].e2adr,&(ptr->buff[20]),2 );
								EEPROMwriter( afe90e3x_cmd_reg_e2adr_tbl[i].e2adr,&(ptr->buff[20]),2);
								CMD_Wr_AFE_Reg( &(ptr->buff[20]),afe90e3x_cmd_reg_e2adr_tbl[i].regadr );
								
								ErrType =0x14;
							}
							else
							{
								CMD_Wr_AFE_Reg( &(ptr->buff[20]),(uint16_t)(cmd&0xFFF) );
								ErrType =0x14;
							}
						}//afe is 3 phase meter
					}//cmd =D0xx
                    break;
					case	0xD1:
					case	0xD2:
					case	0xD8:
					{
						if( (VAFE.id!=AT90E25) && (VAFE.id!=AT90E24) && (VAFE.id!=AT90E23) )
						{
							for(i=0;i<AFE90E3x_cmd_reg_E2_NumMax;i++)
							{
								if( afe90e3x_cmd_reg_e2adr_tbl[i].cmd == (uint16_t)(cmd&0xFFFF) )
								{
									break;
								}
							}
							if(i<AFE90E3x_cmd_reg_E2_NumMax)
							{
								//WrE2DataCRC( afe90e3x_cmd_reg_e2adr_tbl[i].e2adr,&(ptr->buff[20]),2 );
								EEPROMwriter( afe90e3x_cmd_reg_e2adr_tbl[i].e2adr,&(ptr->buff[20]),2);
								CMD_Wr_AFE_Reg( &(ptr->buff[20]),afe90e3x_cmd_reg_e2adr_tbl[i].regadr );
								
								ErrType =0x14;
							}
							else
							{
								CMD_Wr_AFE_Reg( &(ptr->buff[20]),(uint16_t)(cmd&0xFFF) );
								ErrType =0x14;
							}
						}
					}//cmd =D1/D2/D8xx
					break;					
					case	0xE0:
					{
						switch(ptr->buff[14])
						{
							case	0x30:
							{								
								if( (VAFE.id!=AT90E25) && (VAFE.id!=AT90E24) && (VAFE.id!=AT90E23) )
								{
									VAFE.runmode =ptr->buff[20];
									
									switch( ptr->buff[20] )
									{
										case	Idle_Mode:
										{
											SET_AFE_MODE(Idle_Mode);
										}
										break;
										case	Detect_Mode:
										{
											//SET_AFE_MODE(Idle_Mode);
											SET_AFE_MODE( Detect_Mode );
											for(i=0;i<AFE90E3x_cmd_reg_E2_NumMax;i++)
											{
												if( afe90e3x_cmd_reg_e2adr_tbl[i].cmd==0xD010 || afe90e3x_cmd_reg_e2adr_tbl[i].cmd==0xD011 ||
													afe90e3x_cmd_reg_e2adr_tbl[i].cmd==0xD012 || afe90e3x_cmd_reg_e2adr_tbl[i].cmd==0xD013 )
												{
													EEPROMreader( afe90e3x_cmd_reg_e2adr_tbl[i].e2adr,(uint8_t *)(&buff[0]),2);
													CMD_Wr_AFE_Reg( (uint8_t *)(&buff[0]),afe90e3x_cmd_reg_e2adr_tbl[i].regadr );
												}							
											}																						
										}
										break;
										case	Patial_Mode:
										{
											//SET_AFE_MODE(Idle_Mode);
											SET_AFE_MODE( Patial_Mode );
											for( j=P3_PMOffsetA;j<(P3_PMIrmsLSB+1);j++ )
											{
												if( VAFE.id ==AT90E32AS && j==P3_PMIrmsLSB )
												{
													break;
												}
												for( i=0;i<AFE90E3x_cmd_reg_E2_NumMax;i++ )
												{
													if( afe90e3x_cmd_reg_e2adr_tbl[i].regadr ==j )
													{
														EEPROMreader( afe90e3x_cmd_reg_e2adr_tbl[i].e2adr,(uint8_t *)(&buff[0]),2);
														CMD_Wr_AFE_Reg( (uint8_t *)(&buff[0]),afe90e3x_cmd_reg_e2adr_tbl[i].regadr );
													}
												}
											}			
											if( VAFE.id ==AT90E32AS )
											{
												for(j=0x20;j<0x30;j++)
												{
													for(i=0;i<AFE90E3x_cmd_reg_E2_NumMax;i++)
													{
														if( afe90e3x_cmd_reg_e2adr_tbl[i].regadr ==j )
														{
															EEPROMreader( afe90e3x_cmd_reg_e2adr_tbl[i].e2adr,(uint8_t *)(&buff[0]),2);
															CMD_Wr_AFE_Reg( (uint8_t *)(&buff[0]),afe90e3x_cmd_reg_e2adr_tbl[i].regadr );
														}
													}
												}
											}											
										}
										break;
										case	Nomal_Mode:
										default:
										{
											SET_AFE_MODE(Nomal_Mode);
											Load_AFE_Cal_Para_From_Eprom();
										}
										break;
									}//									
									ErrType =0x14;
								}
							}
							break;
							case	0x70:
							{
								VWrE2SafeByte |=0x08;
								if( (VAFE.id!=AT90E25) && (VAFE.id!=AT90E24) && (VAFE.id!=AT90E23) )
								{										
									WrE2DataCRC( E2_AT90E3x_UIScal,&(ptr->buff[20]),2 );								
								}
								else
								{
									WrE2DataCRC( E2_AT90E2x_UIScal,&(ptr->buff[20]),2 );
								}
								VAFE.ulscal.BIT.I_SCALE =(uint16_t)(ptr->buff[21]);
								VAFE.ulscal.BIT.U_SCALE =(uint16_t)(ptr->buff[20]);
								
								ErrType =0x14;
							}
							break;
							case	0x20:
							{
								if(VAFE.thd_timer ==0)
								{
									Enable_Harmonic_Calculate();	//enable dft calculate
									ErrType =0x14;
								}
								else
								{
									ErrType =0x02;
								}
							}
							break;
						}						
					}
					break;
				}				
			}//DL/T645-1997 write command
			break;
        /*
			case	0x08:
			{
				rtc_set_time(RTC, (uint32_t)(ptr->buff[16]), (uint32_t)(ptr->buff[15]),(uint32_t)(ptr->buff[14]));
				
				ptr->buff[30]=0;
				ptr->buff[31]=ptr->buff[17];
				ptr->buff[32]=ptr->buff[18];
				ptr->buff[33]=ptr->buff[19];				
				Date_FormatChk( &(ptr->buff[30]) );
				rtc_set_date(RTC, (uint32_t)(ptr->buff[33]), (uint32_t)(ptr->buff[32]), (uint32_t)(ptr->buff[31]), (uint32_t)(ptr->buff[30]));
				
				PutTaskIntoQue(ReadRTC);
				ErrType =0x15;
			}
			break;
         */
			case	0x0A:
			{
				VWrE2SafeByte |=0x08;
                if( (WrE2DataCRC( ((WrE2Page0Addr<<8)+E2MeterIDAdr),&(ptr->buff[14]),6))==0 )
				{
                    COPYBYTEDATA( (uint8_t * )(&(ptr->buff[14])),&VCom.meter645ID[0],6);
					ErrType =0x15;
				}
				else
				{
 					ErrType =0x02;
				}
			}//DL/T645-1997 write meter address
			break;
			case	0x0C:
			{					
				if( uart_id==Rs485_ID || uart_id==ZigBee_ID )
				{                   
					switch( ptr->buff[14] )
					{
						case	0x02:
						case	0x04:
						case	0x08:
						case	0x10:
						case	0x20:
						case	0x40:						
							ptr->baud_sym =ptr->buff[14];
						break;						
						case	0x80:
						{
							if( uart_id==Rs485_ID )
							{
								ptr->baud_sym =ptr->buff[14];
							}
							else
							{
								ptr->buff[14] =0xFF;
							}
                        }
						break;
						default:
							ptr->buff[14] =0xFF;
					}					
				}
				else
				{
					ptr->buff[14] =0xFF;
				}
				len =1;		//1						
				ErrType =0x13;
			}//DL/T645-1997 write communication baud
			break;
		//---------------next is DL/T645-2007 protocal--------------------
			case	0x11:
			{
				ErrType =0x11;
				switch(cmd)
				{
					case	0x04000101:
					{
						COPYBYTEDATA( &VRTC.day,&(ptr->buff[19]),3 );
						ptr->buff[18] =VRTC.week;
						
						len =4;
					}
					break;
					case	0x04000102:
					{
						COPYBYTEDATA( &VRTC.second,&(ptr->buff[18]),3 );
						
						len =3;
					}
					break;
					case	0x04000401:
					{
						COPYBYTEDATA( &VCom.meter645ID[0],&(ptr->buff[18]),6 );
						
						len =6;
					}
					break;					
					case	0x04000B01:
					{
						if( RdE2DataCRC( (E2FreezePgAdr<<8)+E2FreezeDateAdr,&(ptr->buff[18]),2 ) )
						{
							ErrType =0x02;
						}
						else
						{
							len =2;//
						}
					}
					break;
					case	0x04010001:
					{						
						if( RdE2DataCRC( (E2TouPgAdr<<8)+E2Tou1Adr,&(ptr->buff[18]),12 ) )
						{
							ErrType =0x02;
						}
						else
						{
							if( WrE2DataCRC( (E2TouPgAdr<<8)+E2Tou5Adr,&(ptr->buff[18+12]),12 ) )
							{
								ErrType =0x02;
							}
							else
							{
								len =24;//
							}
						}
					}
					break;
/*					
					case	0x02010100:
					{
						ptr->buff[18] =(uint8_t)(VMeasure.rms.V_A);
						ptr->buff[19] =(uint8_t)(VMeasure.rms.V_A>>8);
						
						len=2;
					}
					break;
					case	0x02010200:
					{
						ptr->buff[18] =(uint8_t)(VMeasure.rms.V_B);
						ptr->buff[19] =(uint8_t)(VMeasure.rms.V_B>>8);
						
						len=2;
					}
					break;
					case	0x02010300:
					{
						ptr->buff[18] =(uint8_t)(VMeasure.rms.V_C);
						ptr->buff[19] =(uint8_t)(VMeasure.rms.V_C>>8);
						
						len=2;
					}
					break;
					case	0x0201FF00:
					{
						ptr->buff[18] =(uint8_t)(VMeasure.rms.V_A);
						ptr->buff[19] =(uint8_t)(VMeasure.rms.V_A>>8);
						ptr->buff[20] =(uint8_t)(VMeasure.rms.V_B);
						ptr->buff[21] =(uint8_t)(VMeasure.rms.V_B>>8);
						ptr->buff[22] =(uint8_t)(VMeasure.rms.V_C);
						ptr->buff[23] =(uint8_t)(VMeasure.rms.V_C>>8);
						
						len=6;
					}
					break;
					case	0x02020100:
					{
						ptr->buff[18] =(uint8_t)(VMeasure.rms.I_A);
						ptr->buff[19] =(uint8_t)(VMeasure.rms.I_A>>8);
						ptr->buff[20] =(uint8_t)(VMeasure.rms.I_A>>16);
						len=3;
					}
					break;
					case	0x02020200:
					{
						ptr->buff[18] =(uint8_t)(VMeasure.rms.I_B);
						ptr->buff[19] =(uint8_t)(VMeasure.rms.I_B>>8);
						ptr->buff[20] =(uint8_t)(VMeasure.rms.I_B>>16);
						len=3;
					}
					break;
					case	0x02020300:
					{
						ptr->buff[18] =(uint8_t)(VMeasure.rms.I_C);
						ptr->buff[19] =(uint8_t)(VMeasure.rms.I_C>>8);
						ptr->buff[20] =(uint8_t)(VMeasure.rms.I_C>>16);
						len=3;
					}
					break;
					case	0x0202FF00:
					{
						ptr->buff[18] =(uint8_t)(VMeasure.rms.I_A);
						ptr->buff[19] =(uint8_t)(VMeasure.rms.I_A>>8);
						ptr->buff[20] =(uint8_t)(VMeasure.rms.I_A>>16);						
						ptr->buff[21] =(uint8_t)(VMeasure.rms.I_B);
						ptr->buff[22] =(uint8_t)(VMeasure.rms.I_B>>8);
						ptr->buff[23] =(uint8_t)(VMeasure.rms.I_B>>16);
						ptr->buff[24] =(uint8_t)(VMeasure.rms.I_C);
						ptr->buff[25] =(uint8_t)(VMeasure.rms.I_C>>8);
						ptr->buff[26] =(uint8_t)(VMeasure.rms.I_C>>16);												
						len=9;
					}
					break;
*/                    
				}//end switch(cmd)
			}//end case 0x11
			break;
			case	0x13:
			{
				COPYBYTEDATA( &VCom.meter645ID[0],(uint8_t * )(&(ptr->buff[14])),6);
				len =6;				
				ErrType =0x13;
			}//end case 0x13
			break;
			case	0x14:
			{
				ErrType =0x14;
				switch(cmd)
				{
					case	0x04000101:
					{
						rtc_set_date(RTC, 2000+BCD_8BIN((ptr->buff[29])), BCD_8BIN(ptr->buff[28]),BCD_8BIN(ptr->buff[27]), BCD_8BIN(ptr->buff[26]) );
						VDisplay.Number =DISPLAY_RTC_DATE;
						VDisplay.LpTimer =10;//display 5s=10*500ms
					}
					break;
					case	0x04000102:
					{
						rtc_set_time( RTC, BCD_8BIN(ptr->buff[28]), BCD_8BIN(ptr->buff[27]),BCD_8BIN(ptr->buff[26]) );
						VDisplay.Number =DISPLAY_RTC_TIME;
						VDisplay.LpTimer =10;//display 5s=10*500ms
					}
					break;
					case	0x04000B01:
					{
						VWrE2SafeByte |=0x08;						
						if( WrE2DataCRC( (E2FreezePgAdr<<8)+E2FreezeDateAdr,&(ptr->buff[26]),2 ) )
						{
							ErrType =0x02;
						}
						else
						{
							PutTaskIntoQue(HistoryDataSave);//
						}
					}
					break;
					case	0x04010001:
					{
						VWrE2SafeByte |=0x08;						
						if( WrE2DataCRC( (E2TouPgAdr<<8)+E2Tou1Adr,&(ptr->buff[26]),12 ) )
						{
							ErrType =0x02;
						}
						else
						{
							VWrE2SafeByte =0x68;
							if( WrE2DataCRC( (E2TouPgAdr<<8)+E2Tou5Adr,&(ptr->buff[26+12]),12 ) )
							{
								ErrType =0x02;
							}
							else
							{
//								COPYBYTEDATA( &(ptr->buff[26]),&(VTou.table[0].touid),24 );
//								PutTaskIntoQue(TOUProc);//
							}
						}
					}
					break;
				}//end case (cmd)				
			}//end case 0x14
			break;
			case	0x15:
			{
				VWrE2SafeByte =0x68;
				//i=(uint32_t )(WrE2DataCRC( ((WrE2Page0Addr<<8)+E2MeterIDAdr),&(ptr->buff[14]),6));
                __NOP();                
				//if( i==0 )
                if( (WrE2DataCRC( ((WrE2Page0Addr<<8)+E2MeterIDAdr),&(ptr->buff[14]),6))==0 )
				{
					__NOP();
                    COPYBYTEDATA( (uint8_t * )(&(ptr->buff[14])),&VCom.meter645ID[0],6);
					ErrType =0x15;
				}
				else
				{
                    __NOP();
                    __NOP();
					ErrType =0x02;
				}
			}//end case 0x15
			break;
/*            
			case	0x19:
			{
				VWrE2SafeByte =0x68;
				clear_e2_cur_month_maxDemand(ALL);
				VWrE2SafeByte =0x68;
				clear_e2_cur_month_maxDemand(TOU1);
				VWrE2SafeByte =0x68;
				clear_e2_cur_month_maxDemand(TOU2);
				VWrE2SafeByte =0x68;
				clear_e2_cur_month_maxDemand(TOU3);
				VWrE2SafeByte =0x68;
				clear_e2_cur_month_maxDemand(TOU4);
				clear_e2_history_maxDemand();
				
				clear_maxDemand(ALL);
				clear_maxDemand(TOU1);
				clear_maxDemand(TOU2);
				clear_maxDemand(TOU3);
				clear_maxDemand(TOU4);
				
				clear_total_DemandCal();
				clear_TOU_DemandCal();
				
				VDisplay.Number =DISPLAY_TOTAL_MAX_DEMAND;
				VDisplay.LpTimer =10;//display 5s=10*500ms
				ErrType =0x19;
			}//end case 0x19
			break;
*/       
			case	0x1A:
			{
				VWrE2SafeByte =0x68;
				Clear_Energy();
				VDisplay.Number =DISPLAY_TOTAL_ENERGY;
				VDisplay.LpTimer =10;//display 5s=10*500ms
				
				ErrType =0x1A;				
			}//end case 0x1A
			break;
            
			case	0x08:
			{
				COPYBYTEDATA(&(ptr->buff[14]),(uint8_t *)(&buff[0]),3);				
				COPYBYTEDATA(&(ptr->buff[17]),(uint8_t *)(&buff[1]),3);
				//*(uint8_t *)(&buff[0]+3) =0
				buff[0] &=0x00FFFFFF;
				if( Time_FormatChk((uint8_t *)&(buff[0])) || Date_FormatChk((uint8_t *)(&buff[0]+3)) )
				{
					break;
				}				
				rtc_set_time( RTC, BCD_8BIN(((buff[0]>>16)&0xFF)), BCD_8BIN(((buff[0]>>8)&0xFF)),BCD_8BIN((buff[0]&0xFF)) );
				rtc_set_date(RTC, (2000+BCD_8BIN(((buff[1]>>16)&0xFF))), BCD_8BIN(((buff[1]>>8)&0xFF)),BCD_8BIN(((buff[1])&0xFF)), BCD_8BIN(((buff[0]>>24)&0xFF)));
				VDisplay.Number =DISPLAY_RTC_TIME;
				VDisplay.LpTimer =10;//display 5s=10*500ms
			}
			break;
			//-------------read AFE internal register----------------
            
			case	0x2E:
			{
				if(ptr->buff[13]!=0x04)
				{
					ErrType =0x80;
					break;
				}                
				ErrType =CMD_Rd_AFE_Reg(&(ptr->buff[18]),(uint16_t)(cmd));
				ptr->buff[20]=0;
				ptr->buff[21]=0;				
				len =4;
				if(ptr->buff[16]==0x42)
				{
					len =8;
				}//endif (cmd=xx02xxxx)
			}
			break;
			//-------------write AFE internal register---------------
			case	0x2F:
			{
				VWrE2SafeByte |=0x08;
				if( ptr->buff[18] !=0x00 || ptr->buff[19] !=0x00	\
					|| ptr->buff[20] !=0x00 || ptr->buff[21] !=0x00 )
				{
					ErrType =0x04;
					break;
				}				
				ErrType =CMD_Wr_AFE_Reg(&(ptr->buff[26]),(uint16_t)(cmd));				
			}
			break;
            
			default:			
			break;			
		}//end (ptr->buff[12])	
		
		//-----------communication end---------------
        VWrE2SafeByte =0;

		switch(ErrType)
		{
			case	0x01:
			case	0x02:
			case	0x04:
			case	0x08:
			case	0x10:
			case	0x20:
			case	0x40:
			{
				ptr->buff[13] =1;
				ptr->buff[14] =ErrType;
				ptr->buff[12] |=0x40;
			}
			break;
			case	0x11:            
			case	0x2E:
				len +=4;			
			case    0x13:
			{
				ptr->buff[13] = len;
			}
			break;
			case	0x14:
			case	0x15:
			case	0x19:
			case	0x1A:
			case	0x2F:
			{
				ptr->buff[13] = 0;
			}	
			break;
			default :
				ErrType =0x80;
			break;
		}
		if(ErrType !=0x80)
		{
			ptr->buff[12] |=0x80;		
			if(ptr->buff[13]!=0)
			{
				for(i=0;i<(ptr->buff[13]);i++)
				{
					ptr->buff[14+i] +=0x33;
				}
			}
			ptr->buff[0]=LEADER_SYMB;
			ptr->buff[1]=LEADER_SYMB;
			ptr->buff[2]=LEADER_SYMB;
			ptr->buff[3]=LEADER_SYMB;
			ptr->buff[4]=FRAMESYNC_SYMB;
			COPYBYTEDATA( &VCom.meter645ID[0],(uint8_t * )(&(ptr->buff[5])),6);
			ptr->buff[11]=DATASYNC_SYMB;		
			
			//-----------calculate cs----------------------
			for(j=0,i=0;i<(ptr->buff[13]+10);i++)
			{
				j+=ptr->buff[4+i];
			}
			ptr->buff[i+4] =(uint8_t)(j&0xFF);
			ptr->buff[i+5] =FRAMETAIL_SYMB;
			
			ptr->len =(ptr->buff[13])+4+2+6+2+2;
			ptr->state =SEND;
			ptr->Flag.BYTE =0;
			ptr->Flag.BIT.SendDataFlag =1;
            ptr->offset =2;			//90E3x_GUI only receive 2 FE
            ptr->len=ptr->len-2;           
			ptr->sendtimer =1;		//wait for 5ms =1*5ms
			ptr->overtimer =0;
			
			VCom.lamptimer =20;		//10s=20*0.5s
		}
		else
		{
			switch(uart_id)
			{
				case	Rs485_ID:
				case	Ir_ID:
				{
					Init_Uart_App(uart_id);
				}
				break;
				case	ZigBee_ID:				
				case	PLC_ID:
				{
					Init_Usart_App(uart_id);
				}
			}
		}			
	}//endif(DLT645_PROTOCOL)
	//--------------------IEC protocol command process---------------
	else
	{
		ptr->state =FREE;
		switch(ptr->iecstep)
		{
			case	IEC_STEP0:
			{
				if(ptr->buff[(ptr->offset)-1]==0x2F)	// "/"
				{
					ptr->iecstep =IEC_STEP1;
				}
			}//case(IEC_STEP0)
			break;
			case	IEC_STEP1:
			{
				if(ptr->buff[(ptr->offset)-1]==0x3F)	// "?"
				{
					ptr->iecstep =IEC_STEP2;
				}
				else
				{
					Init_Uart_App(uart_id);
				}
			}//case(IEC_STEP1)
			break;
			case	IEC_STEP2:
			{
				if(ptr->buff[(ptr->offset)-1]==0x21)	// "!"
				{
					//-------check IEC ID------------------
					for(i=0;i<((ptr->offset)-3);i++)
					{
						if(ptr->buff[i+2] !=VCom.meterIECID[i])
							break;
					}
					if( i>=((ptr->offset)-3) )
					{
						ptr->iecstep =IEC_STEP3;
						ptr->Flag.BIT.MeterID =1;
					}
					else
					{
						Init_Uart_App(uart_id);
					}				
				}//endif (!)
				else
				{
					if( ptr->offset >16 )
					{
						Init_Uart_App(uart_id);
					}
				}
			}//case(IEC_STEP2)
			break;
			case	IEC_STEP3:
			{
				if(ptr->buff[(ptr->offset)-1]==0x0D)	// "CR"
				{
					ptr->iecstep =IEC_STEP4;
				}//endif (CR)
				else
				{
					Init_Uart_App(uart_id);
				}
			}//case(IEC_STEP3)
			break;
			case	IEC_STEP4:
			{
				if(ptr->buff[(ptr->offset)-1]==0x0A)	// "LF"
				{
					ptr->buff[0] =0x2F;//"/"
					ptr->buff[1] =0x5A;//"Z"
					ptr->buff[2] =0x54;//"T"
					ptr->buff[3] =0x5A;//"Z"		
					ptr->buff[4] =0x33;//"Baud=2=1200"   3=2400  4=4800 5=9600
//					ptr->baud_ID =3;
					for(i=0;i<14;i++)
					{
						ptr->buff[5+i] =VCom.meterIECID[i];
					}
					ptr->buff[19] =0x0D;//"CR"
					ptr->buff[20] =0x0A;//"LF"
				
					ptr->len=21;
					ptr->offset=0;
					ptr->state =SEND;
					PutTaskIntoQue(Rs485Transmit);
					ptr->iecstep =IEC_STEP5;
				}
				else
				{
					Init_Uart_App(uart_id);
				}
			}//case(IEC_STEP4)
			break;
			case	IEC_STEP5:
			{
				if(ptr->buff[(ptr->offset)-1]==0x06) //"ACK"
				{
					ptr->iecstep =IEC_STEP6;
				}
				else
				{
					Init_Uart_App(uart_id);
				}
			}//case(IEC_STEP5)
			break;
			case	IEC_STEP6:
			{
				if(ptr->buff[(ptr->offset)-1]==0x30) //"0"
				{
					ptr->iecstep =IEC_STEP7;
				}
				else
				{
					Init_Uart_App(uart_id);
				}
			}//case(IEC_STEP6)
			break;	
			case	IEC_STEP7:
			{
				if(ptr->buff[(ptr->offset)-1]==0x33) //"Baud=3=2400"
				{
					ptr->iecstep =IEC_STEP8;
				}
				else
				{
					Init_Uart_App(uart_id);
				}
			}//case(IEC_STEP7)
			break;
			case	IEC_STEP8:
			{
				if(ptr->buff[(ptr->offset)-1]==0x31) //"1"
				{
					ptr->iecstep =IEC_STEP9;
				}
				else
				{
					Init_Uart_App(uart_id);
				}
			}//case(IEC_STEP8)
			break;
			case	IEC_STEP9:
			{
				if(ptr->buff[(ptr->offset)-1]==0x0D) //"CR"
				{
					ptr->iecstep =IEC_STEP10;
				}
				else
				{
					Init_Uart_App(uart_id);
				}
			}//case(IEC_STEP9)
			break;
			case	IEC_STEP10:
			{
				if(ptr->buff[(ptr->offset)-1]==0x0A) //"LF"
				{
					ptr->buff[0] =0x01;//"SOH"
					ptr->buff[1] =0x50;//"P"
					ptr->buff[2] =0x30;//"0"
					ptr->buff[3] =0x02;//"STX"
					ptr->buff[4] =0x28;//"("
					ptr->buff[5] =0x5A;//"Z"
					ptr->buff[6] =0x54;//"T"
					ptr->buff[7] =0x5A;//"Z"
					ptr->buff[8] =0x29;//")"
					ptr->buff[9] =0x03;//"ETX"
					
					ptr->buff[10] =IEC_Cal_TxBcc((uint8_t *)(&(ptr->buff[1])),9);//"BCC=check_code"
				
					ptr->len=11;
					ptr->offset=0;
					ptr->state =SEND;
					ptr->sendtimer =100;//baud change delay 500ms=100*5ms				
					
					ptr->iecstep =IEC_STEP11;
				}
				else
				{
					Init_Uart_App(uart_id);
				}
			}//case(IEC_STEP10)
			break;
			case	IEC_STEP11:
			{
				if(ptr->buff[(ptr->offset)-1]==0x01) //"SOH"
				{
					ptr->iecstep =IEC_STEP12;
				}
				else
				{
					Init_Uart_App(uart_id);
				}
			}//case(IEC_STEP11)
			break;
			case	IEC_STEP12:
			{
				if(ptr->buff[(ptr->offset)-1]==0x50) //"P"
				{
					ptr->iecstep =IEC_STEP13;
				}
				else
				{
					Init_Uart_App(uart_id);
				}
			}//case(IEC_STEP12)
			break;
			case	IEC_STEP13:
			{
				if(ptr->buff[(ptr->offset)-1]==0x31) //"1"
				{
					ptr->iecstep =IEC_STEP14;
				}
				else
				{
					Init_Uart_App(uart_id);
				}
			}//case(IEC_STEP13)
			break;
			case	IEC_STEP14:
			{
				if(ptr->buff[(ptr->offset)-1]==0x02) //"STX"
				{
					ptr->iecstep =IEC_STEP15;
				}
				else
				{
					Init_Uart_App(uart_id);
				}
			}//case(IEC_STEP14)
			break;
			case	IEC_STEP15:
			{
				if(ptr->buff[(ptr->offset)-1]==0x28) //"("
				{
					ptr->iecstep =IEC_STEP16;
				}
				else
				{
					Init_Uart_App(uart_id);
				}
			}//case(IEC_STEP16)
			break;
			case	IEC_STEP16:
			{
				if(ptr->buff[(ptr->offset)-1]==0x29) //")"
				{
					//-------password check----------------
					for(i=0;i<8;i++)
					{
						if( ptr->buff[5+i]!=VCom.psdIEC[i] )
							break;
					}
					if(i>=8)
					{
						ptr->iecstep =IEC_STEP17;
					}
				}
				else
				{
					if( ptr->offset >13 )//8 bytes password
					{
						Init_Uart_App(uart_id);
					}
				}
			}//case(IEC_STEP16)
			break;
			case	IEC_STEP17:
			{
				if(ptr->buff[(ptr->offset)-1]==ETX_SYMB) //"ETX"
				{
					ptr->iecstep =IEC_STEP18;
				}
				else
				{
					Init_Uart_App(uart_id);
				}
			}//case(IEC_STEP17)
			break;
			case	IEC_STEP18:
			{
				if( ptr->buff[(ptr->offset)-1]==IEC_Cal_RxBcc(&(ptr->buff[1])) ) //"BCC"
				{
					ptr->buff[0]= ACK_SYMB;	//"ACK"	
					ptr->iecstep =IEC_STEP19;
				}
				else
				{
					ptr->buff[0]= NACK_SYMB;	//"NACK"
				}
				ptr->len=1;
				ptr->offset=0;
				ptr->state =SEND;
				PutTaskIntoQue(Rs485Transmit);
			}//case(IEC_STEP18)
			break;
			//-------------command frame process-----------
			case	IEC_STEP19:
			{
				if( ptr->buff[(ptr->offset)-1]!=IEC_Cal_RxBcc(&(ptr->buff[1])) ) //"BCC"
				{	
					ptr->offset	=0;
					ptr->Flag.BYTE &=IEC_FRAME_SAVE_FLAG;
					ptr->state =FREE;
					
					break;
				}
				switch( ptr->buff[1] )
				{
					//----------quit IEC communication---------------
					case	0x42:
					{
						ptr->iecstep =IEC_STEP0;
						ptr->offset =0;
					}
					break;
					//----------read command process-----------------
					case	0x52:
					{
						
					}//endcase 0x52
					break;
					//----------write command process----------------
					case	0x57:
					{
						
					}//endcase 0x57
					break;
					default:
					{
						Init_Uart_App(uart_id);
					}
					break;
				}//endswitch(ptr->buff[1])
			}
			break;
		}//end switch(state)
	}//endif (IEC_PROTOCOL)	

}
//===================================================================
//decription    ::  iec calculate send data bcc 
//function      ::  IEC_Cal_TxBcc
//input         ::  ptr->data first address
//					len
//output        ::  bcc (xor code)
//call          ::  none
//effect        ::  none
//===================================================================
uint32_t	IEC_Cal_TxBcc(uint8_t *ptr,uint8_t len)
{
	uint32_t	i;
	uint32_t	bcc;
	bcc=0;
	for(i=0;i<len;i++)
	{
		bcc ^=*(ptr+i);
	}
	return(bcc);
}
//===================================================================
//decription    ::  iec calculate receive data bcc 
//function      ::  IEC_Cal_RxBcc
//input         ::  ptr->data first address
//output        ::  bcc (xor code)
//call          ::  none
//effect        ::  none
//===================================================================
uint32_t	IEC_Cal_RxBcc(uint8_t *ptr)
{
	uint32_t	i;
	uint32_t	bcc;
	bcc=0;
	for(i=0;i<FRAME_MAX_LEN;i++)
	{
		if( *(ptr+i)==ETX_SYMB )
		{
			break;
		}
		bcc ^=*(ptr+i);
	}
	return(bcc);
}




/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
}
#endif
/**INDENT-ON**/
/// @endcond