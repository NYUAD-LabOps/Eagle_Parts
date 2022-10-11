//===================================================================
#ifndef EEPROM_H_INCLUDED
#define EEPROM_H_INCLUDED

#include "target.h"
#include "E2define.h"

/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
extern "C" {
#endif
/**INDENT-ON**/
/// @endcond

#define	u32 uint32_t
#define	u16 uint16_t	
#define	u8  uint8_t		
//#define	AT24C1024Device		0xA0
#define	WrE2_DeviceAddr		0xA0
#define	RdE2_DeviceAddr		0xA1

#define ByteDeley_us        10
#define WriteFMDelay_ms     5
  
  
#define	EEPROM_SDA_PORT		(IOPORT_PIOA)
#define	EEPROM_SDA_MASK		((1<<24))
#define	EEPROM_SDA_PIN		24
#define	EEPROM_SCL_PORT		(IOPORT_PIOA)
#define	EEPROM_SCL_MASK		((1<<25))
#define	EEPROM_SCL_PIN		25

#define	I2C_SDA_Out()	arch_ioport_set_pin_dir(EEPROM_SDA_PIN,IOPORT_DIR_OUTPUT)
#define	I2C_SDA_In()	arch_ioport_set_pin_dir(EEPROM_SDA_PIN,IOPORT_DIR_INPUT)
#define	I2C_SCL_Out()	arch_ioport_set_pin_dir(EEPROM_SCL_PIN,IOPORT_DIR_OUTPUT)
#define	I2C_SCL_In()	arch_ioport_set_pin_dir(EEPROM_SCL_PIN,IOPORT_DIR_INPUT)

#define	I2C_SDA_High()	arch_ioport_set_pin_level(EEPROM_SDA_PIN,IOPORT_PIN_LEVEL_HIGH)
#define	I2C_SDA_Low()	arch_ioport_set_pin_level(EEPROM_SDA_PIN,IOPORT_PIN_LEVEL_LOW)
#define	I2C_SCL_High()	arch_ioport_set_pin_level(EEPROM_SCL_PIN,IOPORT_PIN_LEVEL_HIGH)
#define	I2C_SCL_Low()	arch_ioport_set_pin_level(EEPROM_SCL_PIN,IOPORT_PIN_LEVEL_LOW)

#define	BIO_I2C_SDA		arch_ioport_get_pin_level(EEPROM_SDA_PIN)
#define	BIO_I2C_SCL		arch_ioport_get_pin_level(EEPROM_SCL_PIN)

#define	I2C_WP_Low()	0		//wp=low level
#define	I2C_WP_High()	1		//wp=high level
#define I2C_VDD_Out()   1       //Control_E2_VCC is out
#define I2C_VDD_High()  1       //E2_VCC =high level
#define I2C_VDD_Low()   0       //E2_VCC =low level
//=========================================================
typedef	union
{
	u32	ErrFlag;
	struct{
		u32	RdRTCErrFlag	: 1;	//bit 0
		u32	WrRTCErrFlag	: 1;
		u32	IIcNoAckFlag	: 1;
		u32	RdE2ErrFlag		: 1;	//bit 3
		u32	WrE2ErrFlag		: 1;	//bit 4
		u32	RTCErrFlag		: 1;	//bit 5
		u32	CRCErrFlag		:	1;	//bit 6
		u32	EnergyFlag		: 1;	//bit 7		
		u32	E2promErrFlag		:	1;
		u32	E2ErrEventFlag	: 1;//
			
		u32	:	22;
		}BIT;		
}ErrFlag_Struct;
//---------------------------------------------------------
#define	Con_WrE2SafeByte	0x68

//=========================================================
//---------------------------------------------------------
void	BSP_E2promBus_Init(void);
void	I2C_START(void);
void	I2C_STOP(void);
u8	Read_I2C_1ByteAck(void);
u8	Read_I2C_1ByteNoAck(void);
u8	Write_I2C_1Byte(u8 I2C_WR_data);
//---------------------------------------------------------
void WPEE0_ENABLE(void);
void WPEE0_DISABLE(void);
void EEPROMOpen (void);
void EEPROMClose (void);
void E2PROMInit(void);
u16 EEPROMreader(u32 offset,u8 *buffer,u16 size);
u16	EEPROMwriter(u32 offset,u8 *buffer,u16 size);
u8 EEPROMGetState(void);
u8	RdE2DataCRC(u16 offset,u8 *ptr,u8 len);
u8	WrE2DataCRC(u16 offset,u8 *ptr,u8 len);

void	Delay_N_ms(uint16_t val);
void	Delay_N_us(uint16_t val);
void	COPYBYTEDATA(u8 *sptr,u8 *mptr,u8 len);
u8	CSandXOR_CheckGenerator(u8 *ptr,u8 len);
//---------------------------------------------------------
extern	ErrFlag_Struct	VErrFlag;
extern	u8	VWrE2SafeByte;
//=========================================================





/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
}
#endif
/**INDENT-ON**/
/// @endcond

#endif /* eeprom_H_INCLUDED */
