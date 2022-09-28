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
	
//#define	AT24C1024Device		0xA0
#define	WrE2_DeviceAddr		0xA0
#define	RdE2_DeviceAddr		0xA1

#define ByteDeley_us        10
#define WriteFMDelay_ms     5

#define EEPROM_SDA_ID 		(ID_PIOA)
#define EEPROM_SDA_PIO 		( PIOA )
#define	EEPROM_SDA_PORT		(IOPORT_PIOA)
//#define	EEPROM_SDA_PIN		( 24 )
#define	EEPROM_SDA_MASK		( PIO_PA24 )

#define EEPROM_SCL_ID 		(ID_PIOA)
#define EEPROM_SCL_PIO 		( PIOA )
#define	EEPROM_SCL_PORT		(IOPORT_PIOA)
//#define	EEPROM_SCL_PIN		( 25 )
#define	EEPROM_SCL_MASK		( PIO_PA25 )

#define	I2C_SDA_PIO_En()		( EEPROM_SDA_PIO->PIO_PER  |= EEPROM_SDA_MASK )
#define	I2C_SDA_PIO_Dis()		( EEPROM_SDA_PIO->PIO_PDR  |= EEPROM_SDA_MASK )
#define	I2C_SDA_PullUp_En()		( EEPROM_SDA_PIO->PIO_PUER |= EEPROM_SDA_MASK )
#define	I2C_SDA_PullUp_Dis()	( EEPROM_SDA_PIO->PIO_PUDR |= EEPROM_SDA_MASK )
#define	I2C_SDA_Out()			( EEPROM_SDA_PIO->PIO_OER  |= EEPROM_SDA_MASK )
#define	I2C_SDA_In()			( EEPROM_SDA_PIO->PIO_ODR  |= EEPROM_SDA_MASK )
#define	I2C_SDA_High()			( EEPROM_SDA_PIO->PIO_SODR |= EEPROM_SDA_MASK )
#define	I2C_SDA_Low()			( EEPROM_SDA_PIO->PIO_CODR |= EEPROM_SDA_MASK )

#define	I2C_SCL_PIO_En()		( EEPROM_SCL_PIO->PIO_PER  |= EEPROM_SCL_MASK )
#define	I2C_SCL_PIO_Dis()		( EEPROM_SCL_PIO->PIO_PDR  |= EEPROM_SCL_MASK )
#define	I2C_SCL_PullUp_En()		( EEPROM_SCL_PIO->PIO_PUER |= EEPROM_SCL_MASK )
#define	I2C_SCL_PullUp_Dis()	( EEPROM_SCL_PIO->PIO_PUDR |= EEPROM_SCL_MASK )
#define	I2C_SCL_Out()			( EEPROM_SCL_PIO->PIO_OER  |= EEPROM_SCL_MASK )
#define	I2C_SCL_In()			( EEPROM_SCL_PIO->PIO_ODR  |= EEPROM_SCL_MASK )
#define	I2C_SCL_High()			( EEPROM_SCL_PIO->PIO_SODR |= EEPROM_SCL_MASK )
#define	I2C_SCL_Low()			( EEPROM_SCL_PIO->PIO_CODR |= EEPROM_SCL_MASK )

#define	BIO_I2C_SDA				( EEPROM_SDA_PIO->PIO_PDSR & (EEPROM_SDA_MASK) )
#define	BIO_I2C_SCL				( EEPROM_SCL_PIO->PIO_PDSR & (EEPROM_SCL_MASK) )

#define	I2C_WP_Low()	0		//wp=low level
#define	I2C_WP_High()	1		//wp=high level
#define I2C_VDD_Out()   1       //Control_E2_VCC is out
#define I2C_VDD_High()  1       //E2_VCC =high level
#define I2C_VDD_Low()   0       //E2_VCC =low level
//=========================================================
typedef	union
{
	uint32_t	ErrFlag;
	struct{
		uint32_t	RdRTCErrFlag	: 1;	//bit 0
		uint32_t	WrRTCErrFlag	: 1;
		uint32_t	IIcNoAckFlag	: 1;
		uint32_t	RdE2ErrFlag		: 1;	//bit 3
		uint32_t	WrE2ErrFlag		: 1;	//bit 4
		uint32_t	RTCErrFlag		: 1;	//bit 5
		uint32_t	CRCErrFlag		:	1;	//bit 6
		uint32_t	EnergyFlag		: 1;	//bit 7		
		uint32_t	E2promErrFlag		:	1;
		uint32_t	E2ErrEventFlag	: 1;//
			
		uint32_t	:	22;
		}BIT;		
}ErrFlag_Struct;
//---------------------------------------------------------
#define	Con_WrE2SafeByte	0x68

//=========================================================
//---------------------------------------------------------
void	BSP_E2promBus_Init(void);
void	I2C_START(void);
void	I2C_STOP(void);
uint8_t	Read_I2C_1ByteAck(void);
uint8_t	Read_I2C_1ByteNoAck(void);
uint8_t	Write_I2C_1Byte(uint8_t I2C_WR_data);
//---------------------------------------------------------
void WPEE0_ENABLE(void);
void WPEE0_DISABLE(void);
void EEPROMOpen (void);
void EEPROMClose (void);
void E2PROMInit(void);
uint16_t EEPROMreader(uint32_t offset,uint8_t *buffer,uint16_t size);
uint16_t	EEPROMwriter(uint32_t offset,uint8_t *buffer,uint16_t size);
uint8_t EEPROMGetState(void);
uint8_t	RdE2DataCRC(uint16_t offset,uint8_t *ptr,uint8_t len);
uint8_t	WrE2DataCRC(uint16_t offset,uint8_t *ptr,uint8_t len);

void	Delay_N_ms(uint16_t val);
void	Delay_N_us(uint16_t val);
void	COPYBYTEDATA(uint8_t *sptr,uint8_t *mptr,uint8_t len);
uint8_t	CSandXOR_CheckGenerator(uint8_t *ptr,uint8_t len);
//---------------------------------------------------------
extern	ErrFlag_Struct	VErrFlag;
extern	uint8_t	VWrE2SafeByte;
//=========================================================





/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
}
#endif
/**INDENT-ON**/
/// @endcond

#endif /* eeprom_H_INCLUDED */
