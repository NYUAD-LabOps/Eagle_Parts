//===================================================================
#ifndef COMPROCESS_H_INCLUDED
#define COMPROCESS_H_INCLUDED

#include "compiler.h"

/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
extern "C" {
#endif
/**INDENT-ON**/
/// @endcond

#define	Baud_115200		115200
#define	Baud_9600		9600
#define	Baud_4800		4800
#define	Baud_2400		2400
#define	Baud_1200		1200
#define	Baud_600		600
#define	Baud_300		300

#define	IEC_HandShake_BD	Baud_4800
#define	IEC_Protocol_BD		Baud_4800

//-------------------------------------------------------------------

typedef	enum
{
	Rs485_ID =0,
	Ir_ID,
	PLC_ID,
	ZigBee_ID	
}UART_TYPE;

typedef	enum
{
	IEC_PROTOCOL =0,
	DLT645_PROTOCOL
}PROTOCOL_TYPE;
typedef	enum
{
	FREE	=0,
	BAUDMONITOR,
	LEADER,
	FRAMESYNC,
	DATASYNC,
	RECDATA,
	FRAMETAIL,
	CMDPROCESS,
	SEND,
	IEC_STX_SYMB,
	IEC_ETX_SYMB,
	IEC_BCC_SYMB
	
}UART_STATUS_TYPE;
typedef	enum
{
	IEC_STEP0 =0,
	IEC_STEP1,
	IEC_STEP2,
	IEC_STEP3,
	IEC_STEP4,
	IEC_STEP5,
	IEC_STEP6,
	IEC_STEP7,
	IEC_STEP8,
	IEC_STEP9,
	IEC_STEP10,
	IEC_STEP11,
	IEC_STEP12,
	IEC_STEP13,
	IEC_STEP14,
	IEC_STEP15,
	IEC_STEP16,
	IEC_STEP17,
	IEC_STEP18,
	IEC_STEP19,
	IEC_STEP20
}IEC_STEP_TYPE;
typedef	enum
{
	LEADER_SYMB =0xFE,
	FRAMESYNC_SYMB =0x68,
	DATASYNC_SYMB =0x68,
	FRAMETAIL_SYMB =0x16
	
}DLT645_SYMB;
typedef	enum
{
	SOH_SYMB =0x01,		//"SOH"
	STX_SYMB =0x02,		//"STX"
	ETX_SYMB =0x03,		//"ETX"
	ACK_SYMB =0x06,		//"ACK"
	NACK_SYMB =0x15		//"NACK"
	
}IEC_SYMB;
#define	FRAME_MAX_LEN	200
#define	IEC_FRAME_SAVE_FLAG		0x70

typedef	struct
{
	uint8_t	First68Flag    		:	1;  //bit 0 
 	uint8_t	Second68Flag 		:	1;  //bit 1 
	uint8_t	OneFrameFlag		:	1;	//bit 2
	uint8_t	SendDataFlag		:	1;	//bit 3
	uint8_t	MeterID		 		:	1;  //bit 4 =IEC_DeviceAddress
	uint8_t	BroadID				:	1;	//bit 5	=IEC_RdPassword_Flag
	uint8_t	GlobleID		 	:	1;  //bit 6	=IEC_WrPassword_Flag
	uint8_t	GlobleMeterID		:	1;	//bit 7	=
}BComBit;
typedef	union
{
	uint8_t		BYTE;
	BComBit		BIT;
}ComByte;

typedef	struct
{
	uint8_t	protocolmode;				//IEC_PROTOCOL ,DLT645_PROTOCOL
    uint8_t	iecstep;
	uint8_t	state;
	uint8_t	baud_sym;
	uint32_t	baud_ID;
	uint8_t	overtimer;
	uint8_t	sendtimer;
	uint8_t	offset;
	uint8_t	len;
	ComByte	Flag;	
	uint8_t	buff[FRAME_MAX_LEN];	
}UART_str;

typedef struct
{
	//----------RS485 UART0--------------------------------
	UART_str	Rs485;
	//----------IR USART1----------------------------------
	UART_str	IR;
	//----------ZigBee USART2------------------------------
	UART_str	ZigBee;
	//----------PLC USART3---------------------------------
	UART_str	PLC;
	//-----------------------------------------------------
	uint8_t		lamptimer;
	uint8_t		meter645ID[6];	//645 meter id
	uint8_t		meterIECID[14];	 //IEC id
	uint8_t		psdIEC[8];	//IEC password
	uint32_t	testval;
}COM_Str;
//---------------------variable declare------------------------------
extern	COM_Str    VCom;
//===================================================================
void	UART0_IrqHandler(void);
void 	UART1_IrqHandler(void);
void 	UART_IntProc(Uart *Uartx,UART_str *ptr);
void 	USART2_IrqHandler(void);
void 	USART3_IrqHandler(void);
void 	USART_IntProc(Usart *Usartx,UART_str *ptr);
void	Init_Uart_App(UART_TYPE uart_id);
void    ComProcess(UART_TYPE uart_id);
void	ComSendProcess(UART_TYPE uart_id);
uint32_t	IEC_Cal_TxBcc(uint8_t *ptr,uint8_t len);
uint32_t	IEC_Cal_RxBcc(uint8_t *ptr);


/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
}
#endif
/**INDENT-ON**/
/// @endcond


#endif /* DISPLAY_H_INCLUDED */
