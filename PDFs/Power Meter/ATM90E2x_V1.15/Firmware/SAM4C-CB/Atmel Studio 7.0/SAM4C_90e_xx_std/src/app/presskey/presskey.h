//===================================================================
#ifndef PRESSKEY_H_INCLUDED
#define PRESSKEY_H_INCLUDED

#include "compiler.h"

/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
extern "C" {
#endif
/**INDENT-ON**/
/// @endcond
//Power Failure pin
#define	POWER_FAIL_IRQn		( PIOA_IRQn )
#define POWER_FAIL_ID 		(ID_PIOA)
#define POWER_FAIL_PIO 		( PIOA )
#define	POWER_FAIL_PORT		(IOPORT_PIOA)
//#define	POWER_FAIL_PIN		( 17 )
#define	POWER_FAIL_MASK		( PIO_PA17 )

#define	POWER_FAIL_PIO_En()		( POWER_FAIL_PIO->PIO_PER  |= POWER_FAIL_MASK )
#define	POWER_FAIL_PIO_Dis()	( POWER_FAIL_PIO->PIO_PDR  |= POWER_FAIL_MASK )
#define	POWER_FAIL_PullUp_En()	( POWER_FAIL_PIO->PIO_PUER |= POWER_FAIL_MASK )
#define	POWER_FAIL_PullUp_Dis()	( POWER_FAIL_PIO->PIO_PUDR |= POWER_FAIL_MASK )
#define	POWER_FAIL_Out()		( POWER_FAIL_PIO->PIO_OER  |= POWER_FAIL_MASK )
#define	POWER_FAIL_In()			( POWER_FAIL_PIO->PIO_ODR  |= POWER_FAIL_MASK )
#define	POWER_FAIL_High()		( POWER_FAIL_PIO->PIO_SODR |= POWER_FAIL_MASK )
#define	POWER_FAIL_Low()		( POWER_FAIL_PIO->PIO_CODR |= POWER_FAIL_MASK )
#define	BIO_POWER_FAIL			( POWER_FAIL_PIO->PIO_PDSR & (POWER_FAIL_MASK) )

//display key pin
#define	DISPKEY_DN_IRQn		( PIOB_IRQn )
#define DISPKEY_DN_ID 		(ID_PIOB)
#define DISPKEY_DN_PIO 		( PIOB )
#define	DISPKEY_DN_PORT		(IOPORT_PIOB)
//#define	DISPKEY_DN_PIN		( 14 )
#define	DISPKEY_DN_MASK		( PIO_PB14 )

#define	DISPKEY_DN_PIO_En()		( DISPKEY_DN_PIO->PIO_PER  |= DISPKEY_DN_MASK )
#define	DISPKEY_DN_PIO_Dis()	( DISPKEY_DN_PIO->PIO_PDR  |= DISPKEY_DN_MASK )
#define	DISPKEY_DN_PullUp_En()	( DISPKEY_DN_PIO->PIO_PUER |= DISPKEY_DN_MASK )
#define	DISPKEY_DN_PullUp_Dis()	( DISPKEY_DN_PIO->PIO_PUDR |= DISPKEY_DN_MASK )
#define	DISPKEY_DN_PullDn_En()	( DISPKEY_DN_PIO->PIO_PPDDR |= DISPKEY_DN_MASK )
#define	DISPKEY_DN_PullDn_Dis()	( DISPKEY_DN_PIO->PIO_PPDDR |= DISPKEY_DN_MASK )
#define	DISPKEY_DN_Out()		( DISPKEY_DN_PIO->PIO_OER  |= DISPKEY_DN_MASK )
#define	DISPKEY_DN_In()			( DISPKEY_DN_PIO->PIO_ODR  |= DISPKEY_DN_MASK )
#define	DISPKEY_DN_FILTER()		( DISPKEY_DN_PIO->PIO_IFER |= DISPKEY_DN_MASK )
#define	DISPKEY_DN_DEBOUNCE(val) ( DISPKEY_DN_PIO->PIO_SCDR = val )
#define	DISPKEY_DN_FILTER_EN()	( DISPKEY_DN_PIO->PIO_IFSCER |= DISPKEY_DN_MASK )
#define	DISPKEY_DN_High()		( DISPKEY_DN_PIO->PIO_SODR |= DISPKEY_DN_MASK )
#define	DISPKEY_DN_Low()		( DISPKEY_DN_PIO->PIO_CODR |= DISPKEY_DN_MASK )
#define	BIO_DISPKEY_DN			( DISPKEY_DN_PIO->PIO_PDSR & (DISPKEY_DN_MASK) )

#define	DISPKEY_UP_IRQn		( PIOB_IRQn )
#define DISPKEY_UP_ID 		(ID_PIOB)
#define DISPKEY_UP_PIO 		( PIOB )
#define	DISPKEY_UP_PORT		(IOPORT_PIOB)
//#define	DISPKEY_UP_PIN		( 13 )
#define	DISPKEY_UP_MASK		( PIO_PB13 )

#define	DISPKEY_UP_PIO_En()		( DISPKEY_UP_PIO->PIO_PER  |= DISPKEY_UP_MASK )
#define	DISPKEY_UP_PIO_Dis()	( DISPKEY_UP_PIO->PIO_PDR  |= DISPKEY_UP_MASK )
#define	DISPKEY_UP_PullUp_En()	( DISPKEY_UP_PIO->PIO_PUER |= DISPKEY_UP_MASK )
#define	DISPKEY_UP_PullUp_Dis()	( DISPKEY_UP_PIO->PIO_PUDR |= DISPKEY_UP_MASK )
#define	DISPKEY_UP_Out()		( DISPKEY_UP_PIO->PIO_OER  |= DISPKEY_UP_MASK )
#define	DISPKEY_UP_In()			( DISPKEY_UP_PIO->PIO_ODR  |= DISPKEY_UP_MASK )
#define	DISPKEY_UP_High()		( DISPKEY_UP_PIO->PIO_SODR |= DISPKEY_UP_MASK )
#define	DISPKEY_UP_Low()		( DISPKEY_UP_PIO->PIO_CODR |= DISPKEY_UP_MASK )
#define	BIO_DISPKEY_UP			( DISPKEY_UP_PIO->PIO_PDSR & (DISPKEY_UP_MASK) )

typedef struct
{
	uint8_t	upkey;
	uint8_t	dnkey;
	uint8_t	dir;
}PRESSKEY_Str;
//---------------------variable declare------------------------------
extern	PRESSKEY_Str    VPressKey;
//===================================================================
void	fail_detect_handler(uint32_t temp0, uint32_t temp1);
void	power_fail_detect( void );
void	DispDnkey_INT_handler(uint32_t temp0, uint32_t temp1);
void	DispDnkey_detect_config(void);
void	DispUpkey_INT_handler(uint32_t temp0, uint32_t temp1);
void	DispUpkey_detect_config(void);

/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
}
#endif
/**INDENT-ON**/
/// @endcond


#endif /* DISPLAY_H_INCLUDED */
