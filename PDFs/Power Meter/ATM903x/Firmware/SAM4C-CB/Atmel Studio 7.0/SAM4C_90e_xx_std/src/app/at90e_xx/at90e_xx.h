//===================================================================
#ifndef AT90E_xx_H_INCLUDED
#define AT90E_xx_H_INCLUDED

#include "target.h"

/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
extern "C" {
#endif
/**INDENT-ON**/
/// @endcond

#define	AFE90E3x_cmd_reg_E2_NumMax	(8*16+14)
#define	AFE90E2x_cmd_reg_E2_NumMax	(16+12)

//------AFE ZX0--------------
#define	AFE_ZX0_IRQn			( PIOA_IRQn )
#define AFE_ZX0_ID 				(ID_PIOA)
#define AFE_ZX0_PIO 			( PIOA )
#define	AFE_ZX0_PORT			(IOPORT_PIOA)
#define	AFE_ZX0_MASK			( PIO_PA13 )
#define	AFE_ZX0_PIO_En()		( AFE_ZX0_PIO->PIO_PER  |= AFE_ZX0_MASK )
#define	AFE_ZX0_PIO_Dis()		( AFE_ZX0_PIO->PIO_PDR  |= AFE_ZX0_MASK )
#define	AFE_ZX0_PullUp_En()		( AFE_ZX0_PIO->PIO_PUER |= AFE_ZX0_MASK )
#define	AFE_ZX0_PullUp_Dis()	( AFE_ZX0_PIO->PIO_PUDR |= AFE_ZX0_MASK )
#define	AFE_ZX0_Out()			( AFE_ZX0_PIO->PIO_OER |= AFE_ZX0_MASK )
#define	AFE_ZX0_In()			( AFE_ZX0_PIO->PIO_ODR |= AFE_ZX0_MASK )
#define	AFE_ZX0_High()			( AFE_ZX0_PIO->PIO_SODR |= AFE_ZX0_MASK )
#define	AFE_ZX0_Low()			( AFE_ZX0_PIO->PIO_CODR |= AFE_ZX0_MASK )

#define	BIO_AFE_ZX0		( AFE_ZX0_PIO->PIO_PDSR & ( AFE_ZX0_MASK ) )

#define	AFE_ZX0_ATR		( PIO_IT_FALL_EDGE )

//------AFE ZX1--------------
#define	AFE_ZX1_IRQn			( PIOA_IRQn )
#define AFE_ZX1_ID 				(ID_PIOA)
#define AFE_ZX1_PIO 			( PIOA )
#define	AFE_ZX1_PORT			(IOPORT_PIOA)
#define	AFE_ZX1_MASK			( PIO_PA18 )
#define	AFE_ZX1_PIO_En()		( AFE_ZX1_PIO->PIO_PER  |= AFE_ZX1_MASK )
#define	AFE_ZX1_PIO_Dis()		( AFE_ZX1_PIO->PIO_PDR  |= AFE_ZX1_MASK )
#define	AFE_ZX1_PullUp_En()		( AFE_ZX1_PIO->PIO_PUER |= AFE_ZX1_MASK )
#define	AFE_ZX1_PullUp_Dis()	( AFE_ZX1_PIO->PIO_PUDR |= AFE_ZX1_MASK )
#define	AFE_ZX1_Out()			( AFE_ZX1_PIO->PIO_OER |= AFE_ZX1_MASK )
#define	AFE_ZX1_In()			( AFE_ZX1_PIO->PIO_ODR |= AFE_ZX1_MASK )
#define	AFE_ZX1_High()			( AFE_ZX1_PIO->PIO_SODR |= AFE_ZX1_MASK )
#define	AFE_ZX1_Low()			( AFE_ZX1_PIO->PIO_CODR |= AFE_ZX1_MASK )

#define	BIO_AFE_ZX1		( AFE_ZX1_PIO->PIO_PDSR & ( AFE_ZX1_MASK ) )

#define	AFE_ZX1_ATR		( PIO_IT_FALL_EDGE )

//------AFE ZX2--------------
#define	AFE_ZX2_IRQn			( PIOA_IRQn )
#define AFE_ZX2_ID 				(ID_PIOA)
#define AFE_ZX2_PIO 			( PIOA )
#define	AFE_ZX2_PORT			(IOPORT_PIOA)
#define	AFE_ZX2_MASK			( PIO_PA16 )
#define	AFE_ZX2_PIO_En()		( AFE_ZX2_PIO->PIO_PER  |= AFE_ZX2_MASK )
#define	AFE_ZX2_PIO_Dis()		( AFE_ZX2_PIO->PIO_PDR  |= AFE_ZX2_MASK )
#define	AFE_ZX2_PullUp_En()		( AFE_ZX2_PIO->PIO_PUER |= AFE_ZX2_MASK )
#define	AFE_ZX2_PullUp_Dis()	( AFE_ZX2_PIO->PIO_PUDR |= AFE_ZX2_MASK )
#define	AFE_ZX2_Out()			( AFE_ZX2_PIO->PIO_OER |= AFE_ZX2_MASK )
#define	AFE_ZX2_In()			( AFE_ZX2_PIO->PIO_ODR |= AFE_ZX2_MASK )
#define	AFE_ZX2_High()			( AFE_ZX2_PIO->PIO_SODR |= AFE_ZX2_MASK )
#define	AFE_ZX2_Low()			( AFE_ZX2_PIO->PIO_CODR |= AFE_ZX2_MASK )

#define	BIO_AFE_ZX2		( AFE_ZX2_PIO->PIO_PDSR & ( AFE_ZX2_MASK ) )

#define	AFE_ZX2_ATR		( PIO_IT_FALL_EDGE )

//------AFE CF1--------------
#define	AFE_CF1_IRQn			( PIOA_IRQn )
#define AFE_CF1_ID 				(ID_PIOA)
#define AFE_CF1_PIO 			( PIOA )
#define	AFE_CF1_PORT			(IOPORT_PIOA)
#define	AFE_CF1_MASK			( PIO_PA20 )
#define	AFE_CF1_PIO_En()		( AFE_CF1_PIO->PIO_PER  |= AFE_CF1_MASK )
#define	AFE_CF1_PIO_Dis()		( AFE_CF1_PIO->PIO_PDR  |= AFE_CF1_MASK )
#define	AFE_CF1_PullUp_En()		( AFE_CF1_PIO->PIO_PUER |= AFE_CF1_MASK )
#define	AFE_CF1_PullUp_Dis()	( AFE_CF1_PIO->PIO_PUDR |= AFE_CF1_MASK )
#define	AFE_CF1_Out()			( AFE_CF1_PIO->PIO_OER |= AFE_CF1_MASK )
#define	AFE_CF1_In()			( AFE_CF1_PIO->PIO_ODR |= AFE_CF1_MASK )
#define	AFE_CF1_High()			( AFE_CF1_PIO->PIO_SODR |= AFE_CF1_MASK )
#define	AFE_CF1_Low()			( AFE_CF1_PIO->PIO_CODR |= AFE_CF1_MASK )

#define	BIO_AFE_CF1		( AFE_CF1_PIO->PIO_PDSR & ( AFE_CF1_MASK ) )

#define	AFE_CF1_ATR		( PIO_IT_FALL_EDGE )

//------AFE CF2--------------
#define	AFE_CF2_IRQn			( PIOA_IRQn )
#define AFE_CF2_ID 				(ID_PIOA)
#define AFE_CF2_PIO 			( PIOA )
#define	AFE_CF2_PORT			(IOPORT_PIOA)
#define	AFE_CF2_MASK			( PIO_PA19 )
#define	AFE_CF2_PIO_En()		( AFE_CF2_PIO->PIO_PER  |= AFE_CF2_MASK )
#define	AFE_CF2_PIO_Dis()		( AFE_CF2_PIO->PIO_PDR  |= AFE_CF2_MASK )
#define	AFE_CF2_PullUp_En()		( AFE_CF2_PIO->PIO_PUER |= AFE_CF2_MASK )
#define	AFE_CF2_PullUp_Dis()	( AFE_CF2_PIO->PIO_PUDR |= AFE_CF2_MASK )
#define	AFE_CF2_Out()			( AFE_CF2_PIO->PIO_OER |= AFE_CF2_MASK )
#define	AFE_CF2_In()			( AFE_CF2_PIO->PIO_ODR |= AFE_CF2_MASK )
#define	AFE_CF2_High()			( AFE_CF2_PIO->PIO_SODR |= AFE_CF2_MASK )
#define	AFE_CF2_Low()			( AFE_CF2_PIO->PIO_CODR |= AFE_CF2_MASK )

#define	BIO_AFE_CF2		( AFE_CF2_PIO->PIO_PDSR & ( AFE_CF2_MASK ) )

#define	AFE_CF2_ATR		( PIO_IT_FALL_EDGE )

//------AFE CF3--------------
#define	AFE_CF3_IRQn			( PIOA_IRQn )
#define AFE_CF3_ID 				(ID_PIOA)
#define AFE_CF3_PIO 			( PIOA )
#define	AFE_CF3_PORT			(IOPORT_PIOA)
#define	AFE_CF3_MASK			( PIO_PA27 )
#define	AFE_CF3_PIO_En()		( AFE_CF3_PIO->PIO_PER  |= AFE_CF3_MASK )
#define	AFE_CF3_PIO_Dis()		( AFE_CF3_PIO->PIO_PDR  |= AFE_CF3_MASK )
#define	AFE_CF3_PullUp_En()		( AFE_CF3_PIO->PIO_PUER |= AFE_CF3_MASK )
#define	AFE_CF3_PullUp_Dis()	( AFE_CF3_PIO->PIO_PUDR |= AFE_CF3_MASK )
#define	AFE_CF3_Out()			( AFE_CF3_PIO->PIO_OER |= AFE_CF3_MASK )
#define	AFE_CF3_In()			( AFE_CF3_PIO->PIO_ODR |= AFE_CF3_MASK )
#define	AFE_CF3_High()			( AFE_CF3_PIO->PIO_SODR |= AFE_CF3_MASK )
#define	AFE_CF3_Low()			( AFE_CF3_PIO->PIO_CODR |= AFE_CF3_MASK )

#define	BIO_AFE_CF3		( AFE_CF3_PIO->PIO_PDSR & ( AFE_CF3_MASK ) )

#define	AFE_CF3_ATR		( PIO_IT_FALL_EDGE )

//------AFE CF4--------------
#define	AFE_CF4_IRQn			( PIOA_IRQn )
#define AFE_CF4_ID 				(ID_PIOA)
#define AFE_CF4_PIO 			( PIOA )
#define	AFE_CF4_PORT			(IOPORT_PIOA)
#define	AFE_CF4_MASK			( PIO_PA26 )
#define	AFE_CF4_PIO_En()		( AFE_CF4_PIO->PIO_PER  |= AFE_CF4_MASK )
#define	AFE_CF4_PIO_Dis()		( AFE_CF4_PIO->PIO_PDR  |= AFE_CF4_MASK )
#define	AFE_CF4_PullUp_En()		( AFE_CF4_PIO->PIO_PUER |= AFE_CF4_MASK )
#define	AFE_CF4_PullUp_Dis()	( AFE_CF4_PIO->PIO_PUDR |= AFE_CF4_MASK )
#define	AFE_CF4_Out()			( AFE_CF4_PIO->PIO_OER |= AFE_CF4_MASK )
#define	AFE_CF4_In()			( AFE_CF4_PIO->PIO_ODR |= AFE_CF4_MASK )
#define	AFE_CF4_High()			( AFE_CF4_PIO->PIO_SODR |= AFE_CF4_MASK )
#define	AFE_CF4_Low()			( AFE_CF4_PIO->PIO_CODR |= AFE_CF4_MASK )

#define	BIO_AFE_CF4		( AFE_CF4_PIO->PIO_PDSR & ( AFE_CF4_MASK ) )

#define	AFE_CF4_ATR		( PIO_IT_FALL_EDGE )

//------AFE IRQ0--------------
#define	AFE_IRQ0_IRQn			( PIOA_IRQn )
#define AFE_IRQ0_ID 			(ID_PIOA)
#define AFE_IRQ0_PIO 			( PIOA )
#define	AFE_IRQ0_PORT			(IOPORT_PIOA)
#define	AFE_IRQ0_MASK			( PIO_PA28 )
#define	AFE_IRQ0_PIO_En()		( AFE_IRQ0_PIO->PIO_PER  |= AFE_IRQ0_MASK )
#define	AFE_IRQ0_PIO_Dis()		( AFE_IRQ0_PIO->PIO_PDR  |= AFE_IRQ0_MASK )
#define	AFE_IRQ0_PullUp_En()	( AFE_IRQ0_PIO->PIO_PUER |= AFE_IRQ0_MASK )
#define	AFE_IRQ0_PullUp_Dis()	( AFE_IRQ0_PIO->PIO_PUDR |= AFE_IRQ0_MASK )
#define	AFE_IRQ0_Out()			( AFE_IRQ0_PIO->PIO_OER |= AFE_IRQ0_MASK )
#define	AFE_IRQ0_In()			( AFE_IRQ0_PIO->PIO_ODR |= AFE_IRQ0_MASK )
#define	AFE_IRQ0_High()			( AFE_IRQ0_PIO->PIO_SODR |= AFE_IRQ0_MASK )
#define	AFE_IRQ0_Low()			( AFE_IRQ0_PIO->PIO_CODR |= AFE_IRQ0_MASK )

#define	BIO_AFE_IRQ0		( AFE_IRQ0_PIO->PIO_PDSR & ( AFE_IRQ0_MASK ) )

#define	AFE_IRQ0_ATR		( PIO_IT_FALL_EDGE )

//------AFE IRQ1--------------
#define AFE_IRQ1_ID 			(ID_PIOB)
#define AFE_IRQ1_PIO 			( PIOB )
#define	AFE_IRQ1_PORT			(IOPORT_PIOB)
#define	AFE_IRQ1_MASK			( PIO_PB7 )
#define	AFE_IRQ1_PIO_En()		( AFE_IRQ1_PIO->PIO_PER  |= AFE_IRQ1_MASK )
#define	AFE_IRQ1_PIO_Dis()		( AFE_IRQ1_PIO->PIO_PDR  |= AFE_IRQ1_MASK )
#define	AFE_IRQ1_PullUp_En()	( AFE_IRQ1_PIO->PIO_PUER |= AFE_IRQ1_MASK )
#define	AFE_IRQ1_PullUp_Dis()	( AFE_IRQ1_PIO->PIO_PUDR |= AFE_IRQ1_MASK )
#define	AFE_IRQ1_Out()			( AFE_IRQ1_PIO->PIO_OER |= AFE_IRQ1_MASK )
#define	AFE_IRQ1_In()			( AFE_IRQ1_PIO->PIO_ODR |= AFE_IRQ1_MASK )
#define	AFE_IRQ1_High()			( AFE_IRQ1_PIO->PIO_SODR |= AFE_IRQ1_MASK )
#define	AFE_IRQ1_Low()			( AFE_IRQ1_PIO->PIO_CODR |= AFE_IRQ1_MASK )

#define	BIO_AFE_IRQ1		( AFE_IRQ1_PIO->PIO_PDSR & ( AFE_IRQ1_MASK ) )

#define	AFE_IRQ1_ATR		( PIO_IT_FALL_EDGE )

//------AFE WARMOUT--------------
#define AFE_WARMOUT_ID 				(ID_PIOA)
#define AFE_WARMOUT_PIO 			( PIOA )
#define	AFE_WARMOUT_PORT			(IOPORT_PIOA)
#define	AFE_WARMOUT_MASK			( PIO_PA29 )
#define	AFE_WARMOUT_PIO_En()		( AFE_WARMOUT_PIO->PIO_PER  |= AFE_WARMOUT_MASK )
#define	AFE_WARMOUT_PIO_Dis()		( AFE_WARMOUT_PIO->PIO_PDR  |= AFE_WARMOUT_MASK )
#define	AFE_WARMOUT_PullUp_En()		( AFE_WARMOUT_PIO->PIO_PUER |= AFE_WARMOUT_MASK )
#define	AFE_WARMOUT_PullUp_Dis()	( AFE_WARMOUT_PIO->PIO_PUDR |= AFE_WARMOUT_MASK )
#define	AFE_WARMOUT_Out()			( AFE_WARMOUT_PIO->PIO_OER |= AFE_WARMOUT_MASK )
#define	AFE_WARMOUT_In()			( AFE_WARMOUT_PIO->PIO_ODR |= AFE_WARMOUT_MASK )
#define	AFE_WARMOUT_High()			( AFE_WARMOUT_PIO->PIO_SODR |= AFE_WARMOUT_MASK )
#define	AFE_WARMOUT_Low()			( AFE_WARMOUT_PIO->PIO_CODR |= AFE_WARMOUT_MASK )

#define	BIO_AFE_WARMOUT		( AFE_WARMOUT_PIO->PIO_PDSR & ( AFE_WARMOUT_MASK ) )
//-----------------------------------------------
#define AFE_RST_ID 				(ID_PIOB)
#define AFE_RST_PIO 			( PIOB )
#define	AFE_RST_PORT			(IOPORT_PIOB)
#define	AFE_RST_MASK			( PIO_PB10 )
#define AFE_DMA_ID 				(ID_PIOB)
#define AFE_DMA_PIO 			( PIOB )
#define	AFE_DMA_PORT			(IOPORT_PIOB)
#define	AFE_DMA_MASK			( PIO_PB8 )

#define AFE_PM1_ID 				(ID_PIOB)
#define AFE_PM1_PIO 			( PIOB )
#define	AFE_PM1_PORT			(IOPORT_PIOB)
#define	AFE_PM1_MASK			( PIO_PB9 )
#define AFE_PM0_ID 				(ID_PIOB)
#define AFE_PM0_PIO 			( PIOB )
#define	AFE_PM0_PORT			(IOPORT_PIOB)
#define	AFE_PM0_MASK			( PIO_PB6 )

#define	AFE_RST_PIO_En()	( AFE_RST_PIO->PIO_PER  |= AFE_RST_MASK )
#define	AFE_RST_PIO_Dis()	( AFE_RST_PIO->PIO_PDR  |= AFE_RST_MASK )
#define	AFE_DMA_PIO_En()	( AFE_DMA_PIO->PIO_PER  |= AFE_DMA_MASK )
#define	AFE_DMA_PIO_Dis()	( AFE_DMA_PIO->PIO_PDR  |= AFE_DMA_MASK )
#define	AFE_PM1_PIO_En()	( AFE_PM1_PIO->PIO_PER  |= AFE_PM1_MASK )
#define	AFE_PM1_PIO_Dis()	( AFE_PM1_PIO->PIO_PDR  |= AFE_PM1_MASK )
#define	AFE_PM0_PIO_En()	( AFE_PM0_PIO->PIO_PER  |= AFE_PM0_MASK )
#define	AFE_PM0_PIO_Dis()	( AFE_PM0_PIO->PIO_PDR  |= AFE_PM0_MASK )

#define	AFE_RST_Out()		( AFE_RST_PIO->PIO_OER |= AFE_RST_MASK )
#define	AFE_RST_In()		( AFE_RST_PIO->PIO_ODR |= AFE_RST_MASK )
#define	AFE_DMA_Out()		( AFE_DMA_PIO->PIO_OER |= AFE_DMA_MASK )
#define	AFE_DMA_In()		( AFE_DMA_PIO->PIO_ODR |= AFE_DMA_MASK )
#define	AFE_PM1_Out()		( AFE_PM1_PIO->PIO_OER |= AFE_PM1_MASK )
#define	AFE_PM1_In()		( AFE_PM1_PIO->PIO_ODR |= AFE_PM1_MASK )
#define	AFE_PM0_Out()		( AFE_PM0_PIO->PIO_OER |= AFE_PM0_MASK )
#define	AFE_PM0_In()		( AFE_PM0_PIO->PIO_ODR |= AFE_PM0_MASK )

#define	AFE_RST_High()		( AFE_RST_PIO->PIO_SODR |= AFE_RST_MASK )// arch_ioport_set_pin_level(AFE_RST_PIN,IOPORT_PIN_LEVEL_HIGH)
#define	AFE_RST_Low()		( AFE_RST_PIO->PIO_CODR |= AFE_RST_MASK )// arch_ioport_set_pin_level(AFE_RST_PIN,IOPORT_PIN_LEVEL_LOW)
#define	AFE_DMA_High()		( AFE_DMA_PIO->PIO_SODR |= AFE_DMA_MASK )//arch_ioport_set_pin_level(AFE_DMA_PIN,IOPORT_PIN_LEVEL_HIGH)
#define	AFE_DMA_Low()		( AFE_DMA_PIO->PIO_CODR |= AFE_DMA_MASK )//arch_ioport_set_pin_level(AFE_DMA_PIN,IOPORT_PIN_LEVEL_LOW)
#define	AFE_PM1_High()		( AFE_PM1_PIO->PIO_SODR |= AFE_PM1_MASK )//arch_ioport_set_pin_level(AFE_PM1_PIN,IOPORT_PIN_LEVEL_HIGH)
#define	AFE_PM1_Low()		( AFE_PM1_PIO->PIO_CODR |= AFE_PM1_MASK )//arch_ioport_set_pin_level(AFE_PM1_PIN,IOPORT_PIN_LEVEL_LOW)
#define	AFE_PM0_High()		( AFE_PM0_PIO->PIO_SODR |= AFE_PM0_MASK )//arch_ioport_set_pin_level(AFE_PM0_PIN,IOPORT_PIN_LEVEL_HIGH)
#define	AFE_PM0_Low()		( AFE_PM0_PIO->PIO_CODR |= AFE_PM0_MASK )//arch_ioport_set_pin_level(AFE_PM0_PIN,IOPORT_PIN_LEVEL_LOW)

#define AFE_CS_ID 			(ID_PIOC)
#define AFE_CS_PIO 			( PIOC )
#define	AFE_CS_PORT			(IOPORT_PIOC)
#define	AFE_CS_MASK			( PIO_PC2 )
#define AFE_SCK_ID 			(ID_PIOC)
#define AFE_SCK_PIO 		( PIOC )
#define	AFE_SCK_PORT		(IOPORT_PIOC)
#define	AFE_SCK_MASK		( PIO_PC5 )
#define AFE_MOSI_ID 		(ID_PIOC)
#define AFE_MOSI_PIO 		( PIOC )
#define	AFE_MOSI_PORT		(IOPORT_PIOC)
#define	AFE_MOSI_MASK		( PIO_PC4 )
#define AFE_MISO_ID 		(ID_PIOC)
#define AFE_MISO_PIO 		( PIOC )
#define	AFE_MISO_PORT		(IOPORT_PIOC)
#define	AFE_MISO_MASK		( PIO_PC3 )

#define	AFE_CS_PIO_En()		( AFE_CS_PIO->PIO_PER  |= AFE_CS_MASK )
#define	AFE_CS_PIO_Dis()	( AFE_CS_PIO->PIO_PDR  |= AFE_CS_MASK )
#define	AFE_SCK_PIO_En()	( AFE_SCK_PIO->PIO_PER  |= AFE_SCK_MASK )
#define	AFE_SCK_PIO_Dis()	( AFE_SCK_PIO->PIO_PDR  |= AFE_SCK_MASK )
#define	AFE_MOSI_PIO_En()	( AFE_MOSI_PIO->PIO_PER  |= AFE_MOSI_MASK )
#define	AFE_MOSI_PIO_Dis()	( AFE_MOSI_PIO->PIO_PDR  |= AFE_MOSI_MASK )
#define	AFE_MISO_PIO_En()	( AFE_MISO_PIO->PIO_PER  |= AFE_MISO_MASK )
#define	AFE_MISO_PIO_Dis()	( AFE_MISO_PIO->PIO_PDR  |= AFE_MISO_MASK )

#define	AFE_CS_Out()	( PIOC->PIO_OER |= AFE_CS_MASK )
#define	AFE_CS_In()		( PIOC->PIO_ODR |= AFE_CS_MASK )
#define	AFE_SCK_Out()	( PIOC->PIO_OER |= AFE_SCK_MASK )
#define	AFE_SCK_In()	( PIOC->PIO_ODR |= AFE_SCK_MASK )
#define	AFE_MOSI_Out()	( PIOC->PIO_OER |= AFE_MOSI_MASK )
#define	AFE_MOSI_In()	( PIOC->PIO_ODR |= AFE_MOSI_MASK )
#define	AFE_MISO_Out()	( PIOC->PIO_OER |= AFE_MISO_MASK )
#define	AFE_MISO_In()	( PIOC->PIO_ODR |= AFE_MISO_MASK )

#define	AFE_CS_High()	( PIOC->PIO_SODR |= AFE_CS_MASK )
#define	AFE_CS_Low()	( PIOC->PIO_CODR |= AFE_CS_MASK )
#define	AFE_SCK_High()	( PIOC->PIO_SODR |= AFE_SCK_MASK )
#define	AFE_SCK_Low()	( PIOC->PIO_CODR |= AFE_SCK_MASK )
#define	AFE_MOSI_High()	( PIOC->PIO_SODR |= AFE_MOSI_MASK )
#define	AFE_MOSI_Low()	( PIOC->PIO_CODR |= AFE_MOSI_MASK )
#define	AFE_MISO_High()	( PIOC->PIO_SODR |= AFE_MISO_MASK )
#define	AFE_MISO_Low()	( PIOC->PIO_CODR |= AFE_MISO_MASK )

#define	AFE_CS_PullUp_En()		( PIOC->PIO_PUER |= AFE_CS_MASK )
#define	AFE_CS_PullUp_Dis()		( PIOC->PIO_PUDR |= AFE_CS_MASK )
#define	AFE_SCK_PullUp_En()		( PIOC->PIO_PUER |= AFE_SCK_MASK )
#define	AFE_SCK_PullUp_Dis()	( PIOC->PIO_PUDR |= AFE_SCK_MASK )
#define	AFE_MOSI_PullUp_En()	( PIOC->PIO_PUER |= AFE_MOSI_MASK )
#define	AFE_MOSI_PullUp_Dis()	( PIOC->PIO_PUDR |= AFE_MOSI_MASK )
#define	AFE_MISO_PullUp_En()	( PIOC->PIO_PUER |= AFE_MISO_MASK )
#define	AFE_MISO_PullUp_Dis()	( PIOC->PIO_PUDR |= AFE_MISO_MASK )

#define	BIO_AFE_MISO	( PIOC->PIO_PDSR & (AFE_MISO_MASK) )
//---------------------------------------------------------
#define		Sag_Ua_Mask		(0x1u<<0)
#define		Sag_Ub_Mask		(0x1u<<1)
#define		Sag_Uc_Mask		(0x1u<<2)

#define		Pa_Dir_Mask		(0x1u<<8)
#define		Pb_Dir_Mask		(0x1u<<9)
#define		Pc_Dir_Mask		(0x1u<<10)

#define		Qa_Dir_Mask		(0x1u<<12)
#define		Qb_Dir_Mask		(0x1u<<13)
#define		Qc_Dir_Mask		(0x1u<<14)
//---------------------------------------------------------
typedef enum
{
	IsFailed =0,
	IsSuccess,
}Enable_TYPE;
typedef	enum
{
	SoftRest =0,
	SysStatus,
	FuncEn,
	SagTH,
	SmallPMod,
	LastSPIData =6,
	CalStart =0x20,
	PLconstH =0x21,
	PLcosntL =0x22,
	Lgain =0x23,
	Lphi =0x24,
	Ngain =0x25,
	Nphi =0x26,
	PStartTH =0x27,
	PNolTH =0x28,
	QStartTH =0x29,
	QNolTH =0x2A,
	MMode =0x2B,
	CS1 =0x2C,		//1-13
	AdjStart =0x30,
	Ugain =0x31,
	IgainL =0x32,
	IgainN =0x33,
	Uoffset =0x34,
	IoffsetL =0x35,
	IoffsetN =0x36,
	PoffsetL =0x37,
	PoffsetN =0x38,
	QoffsetL =0x39,
	QoffsetN =0x3A,
	CS2 =0x3B,			//1-12
	APenegy =0x40,
	ANenergy =0x41,
	ATenergy =0x42,
	RPenergy =0x43,
	RNenergy =0x44,
	RTenergy =0x45,
	Enstatus =0x46,		//1-7
	Irms =0x48,
	Urms =0x49,
	Pmean =0x4A,
	Qmean =0x4B,
	Freq =0x4C,
	PowerF =0x4D,
	Pangle =0x4E,
	Smean =0x4F,	
	Irms2 =0x68,
	Pmean2 =0x6A,
	Qmean2 =0x6B,
	PowerF2 =0x6D,
	Pangle2 =0x6E,
	Smean2 =0x6F		//1-14	
}AFE_90E25_REG;
typedef	enum
{
	P3_SoftReset		=0,
	P3_MeterEn			=0,		//90E32AS
	P3_SysStatus0		=1,
	P3_ChannelMapI		=1,		//90E32AS
	P3_SysStatus1		=2,
	P3_ChannelMapU		=2,		//90E32AS
	P3_FuncEn0			=3,		//90E32AS invalible
	P3_FuncEn1			=4,		//90E32AS invalible
	P3_SagPeakDetCfg	=5,		//90E32AS
	P3_Ovth				=6,		//90E32AS
	P3_ZXConfig		=7,
	P3_SagTh		=0x08,
	P3_PhaseLossTh	=0x09,
	P3_INWarnTh0	=0x0A,
	P3_INWarnTh1	=0x0B,	//90E32/32A invalible
	P3_Olth			=0x0B,	//90E32AS
	P3_THDNUTh		=0x0C,
	P3_FreqLoTh		=0x0C,	//90E32AS
	P3_THDNITh		=0x0D,
	P3_FreqHiTh		=0x0D,	//90E32AS
	P3_DMACtrl		=0x0E,	//90E32/32A invalible
	P3_PMPwrCtrl	=0x0E,	//90E32AS
	P3_LastSPIData	=0x0F,
	P3_IRQ0MergeCfg	=0x0F,	//90E32AS
	
	P3_DetectCtrl		=0x10,
	P3_DetectThA		=0x11,	
	P3_DetectTh1		=0x11,	//
	P3_DetectThB		=0x12,
	P3_DetectTh2		=0x12,	//
	P3_DetectThC		=0x13,
	P3_DetectTh3		=0x13,	//
	P3_PMOffsetA		=0x14,
	P3_IDCoffsetA		=0x14,	//90E32AS
	P3_PMOffsetB		=0x15,
	P3_IDCoffsetB		=0x15,	//90E32AS
	P3_PMOffsetC		=0x16,
	P3_IDCoffsetC		=0x16,	//90E32AS
	P3_PMPGA			=0x17,
	P3_UDCoffsetA		=0x17,	//90E32AS
	P3_PMIrmsA			=0x18,
	P3_UDCoffsetB		=0x18,	//90E32AS
	P3_PMIrmsB			=0x19,
	P3_UDCoffsetC		=0x19,	//90E32AS
	P3_PMIrmsC			=0x1A,
	P3_UGainTAB			=0x1A,	//90E32AS
	P3_PMconfig			=0x1B,
	P3_UGainTC			=0x1B,	//90E32AS
	P3_PMAvgSamples		=0x1C,
	P3_PhiFreqComp		=0x1C,	//90E32AS
	P3_PMIrmsLSB		=0x1D,	//90E32AS invalible
	
	P3_LOGIrms0			=0x20,	//90E32AS
	P3_LOGIrms1			=0x21,	//90E32AS
	P3_F0				=0x22,	//90E32AS
	P3_T0				=0x23,	//90E32AS
	P3_PhiAIrms01		=0x24,	//90E32AS
	P3_PhiAIrms02		=0x25,	//90E32AS
	P3_GainAIrms01		=0x26,	//90E32AS
	P3_GainAIrms02		=0x27,	//90E32AS	
	P3_PhiBIrms01		=0x28,	//90E32AS
	P3_PhiBIrms02		=0x29,	//90E32AS
	P3_GainBIrms01		=0x2A,	//90E32AS
	P3_GainBIrms02		=0x2B,	//90E32AS	
	P3_PhiCIrms01		=0x2C,	//90E32AS
	P3_PhiCIrms02		=0x2D,	//90E32AS
	P3_GainCIrms01		=0x2E,	//90E32AS
	P3_GainCIrms02		=0x2F,	//90E32AS
	
	P3_ConfigStart		=0x30,	//90E32AS invalible
	P3_PLConstH,
	P3_PLConstL,
	P3_MMode0,
	P3_MMode1,
	P3_PStartTh			=0x35,
	P3_QStartTh,
	P3_SStartTh,
	P3_PPhaseTh,
	P3_QPhaseTh,
	P3_SPhaseTh,
	P3_CS0			=0x3B,	//90E32AS invalible
	P3_CalStart		=0x40,	//90E32AS invalible
	P3_POffsetA,
	P3_QOffsetA,
	P3_POffsetB,
	P3_QOffsetB,
	P3_POffsetC,
	P3_QOffsetC		=0x46,
	P3_PQGainA		=0x47,
	P3_GainA		=0x47,	//90E32AS
	P3_PhiA			=0x48,
	P3_PQGainB		=0x49,
	P3_PhiB,
	P3_PQGainC,
	P3_PhiC,
	P3_CS1			=0x4D,	//90E32AS invalible
	P3_HarmStart	=0x50,	//90E32AS invalible
	P3_POffsetAF,
	P3_POffsetBF,
	P3_POffsetCF,
	P3_PGainAF,
	P3_PGainBF,
	P3_PGainCF,
	P3_CS2			=0x57,	//90E32AS invalible
	P3_AdjStart		=0x60,	//90E32AS invalible
	P3_UGainA,
	P3_IGainA,
	P3_UOffsetA,
	P3_IOffsetA,
	P3_UGainB,
	P3_IGainB,
	P3_UOffsetB,
	P3_IOffsetB,
	P3_UGainC,
	P3_IGainC,
	P3_UOffsetC,
	P3_IOffsetC			=0x6C,
	P3_IGainN			=0x6D,	//90E36
	P3_IOffsetN			=0x6E,	//90E36
	P3_CS3				=0x6F,	//90E32AS invalible
	
	P3_2AS_SoftReset	=0x70,	//90E32AS
	P3_2AS_EMMState0	=0x71,	//90E32AS
	P3_2AS_EMMState1	=0x72,	//90E32AS
	P3_2AS_EMMIntState0	=0x73,	//90E32AS
	P3_2AS_EMMIntState1	=0x74,	//90E32AS
	P3_2AS_EMMIntEn0	=0x75,	//90E32AS
	P3_2AS_EMMIntEn1	=0x76,	//90E32AS
	P3_2AS_LastSPIData	=0x78,	//90E32AS
	P3_2AS_CRCErrStatus	=0x79,	//90E32AS
	P3_2AS_CRCDigest	=0x7A,	//90E32AS
	P3_2AS_CfgRegAccEn	=0x7F,	//90E32AS	
	
	P3_APenergyT		=0x80,
	P3_APenergyA,
	P3_APenergyB,
	P3_APenergyC,
	P3_ANenergyT,
	P3_ANenergyA,
	P3_ANenergyB,
	P3_ANenergyC,
	P3_RPenergyT,
	P3_RPenergyA,
	P3_RPenergyB,
	P3_RPenergyC,
	P3_RNenergyT,
	P3_RNenergyA,
	P3_RNenergyB,
	P3_RNenergyC,
	P3_SAenergyT		=0x90,
	P3_SenergyA,
	P3_SenergyB,
	P3_SenergyC,
	P3_SVenergyT		=0x94,	//90E32/32A/32AS invalible
	P3_EnStatus0,				//90E32AS invalible
	P3_EnStatus1		=0x96,	//90E32AS invalible
	P3_SVmeanT			=0x98,	//90E32/32A/32AS invalible
	P3_SVmeanTLSB		=0x99,	//90E32/32A/32AS invalible
	P3_APenergyTF		=0xA0,
	P3_APenergyAF,
	P3_APenergyBF,
	P3_APenergyCF,
	P3_ANenergyTF,
	P3_ANenergyAF,
	P3_ANenergyBF,
	P3_ANenergyCF,
	P3_APenergyTH,
	P3_APenergyAH,
	P3_APenergyBH,
	P3_APenergyCH,
	P3_ANenergyTH,
	P3_ANenergyAH,
	P3_ANenergyBH,
	P3_ANenergyCH,
	P3_PmeanT           =0xB0,
	P3_PmeanA,
	P3_PmeanB,
	P3_PmeanC,
	P3_QmeanT,
	P3_QmeanA,
	P3_QmeanB,
	P3_QmeanC,
	P3_SAmeanT,
	P3_SmeanA,
	P3_SmeanB,
	P3_SmeanC,
	P3_PFmeanT,
	P3_PFmeanA,
	P3_PFmeanB,
	P3_PFmeanC,
	P3_PmeanTLSB,
	P3_PmeanALSB,
	P3_PmeanBLSB,
	P3_PmeanCLSB,
	P3_QmeanTLSB,
	P3_QmeanALSB,
	P3_QmeanBLSB,
	P3_QmeanCLSB,
	P3_SAmeanTLSB,
	P3_SmeanALSB,
	P3_SmeanBLSB,
	P3_SmeanCLSB		=0xCB,
	P3_PmeanTF			=0xD0,
	P3_PmeanAF,
	P3_PmeanBF,
	P3_PmeanCF,
	P3_PmeanTH,
	P3_PmeanAH,
	P3_PmeanBH,
	P3_PmeanCH			=0xD7,
	P3_IrmsN1			=0xD8, //90E32/32A/32AS invalible
	P3_UrmsA,
	P3_UrmsB,
	P3_UrmsC,
	P3_IrmsN0,
	P3_IrmsA,
	P3_IrmsB,
	P3_IrmsC,
	P3_PmeanTFLSB		=0xE0,
	P3_PmeanAFLSB,
	P3_PmeanBFLSB,
	P3_PmeanCFLSB		=0xE3,
	P3_PmeanTHLSB		=0xE4, //90E32/32A invalible
	P3_PmeanAHLSB		=0xE5, //90E32/32A invalible
	P3_PmeanBHLSB		=0xE6, //90E32/32A invalible
	P3_PmeanCHLSB		=0xE7, //90E32/32A invalible
	P3_UrmsALSB		=0xE9,
	P3_UrmsBLSB,
	P3_UrmsCLSB,
	P3_IrmsALSB		=0xED,
	P3_IrmsBLSB,
	P3_IrmsCLSB		=0xEF,
	P3_THDUA		=0xF1,
	
	P3_THDUB,
	P3_THDUC		=0xF3,
	P3_THDIA		=0xF5,
	P3_THDIB,
	P3_THDIC,
	P3_Freq,
	P3_PangleA,
	P3_PangleB,
	P3_PangleC,
	P3_Temp,
	P3_UangleA,
	P3_UangleB,
	P3_UangleC		=0xFF,
	
	P3_UPeakA		=0xF1,
	P3_IPeakA,
	P3_UPeakB,
	P3_IPeakB,
	P3_UPeakC,
	P3_IPeakC,
		
	P3_AIHR2		=0x100,	//90E36/36A
	P3_AIHR3,
	P3_AIHR4,
	P3_AIHR5,
	P3_AIHR6,
	P3_AIHR7,
	P3_AIHR8,
	P3_AIHR9,
	P3_AIHR10,
	P3_AIHR11,
	P3_AIHR12,
	P3_AIHR13,
	P3_AIHR14,
	P3_AIHR15,
	P3_AIHR16,
	P3_AIHR17,
	P3_AIHR18,
	P3_AIHR19,
	P3_AIHR20,
	P3_AIHR21,
	P3_AIHR22,
	P3_AIHR23,
	P3_AIHR24,
	P3_AIHR25,
	P3_AIHR26,
	P3_AIHR27,
	P3_AIHR28,
	P3_AIHR29,
	P3_AIHR30,
	P3_AIHR31,
	P3_AIHR32,
	P3_AITHD,
	
	P3_BIHR2,
	P3_BIHR3,
	P3_BIHR4,
	P3_BIHR5,
	P3_BIHR6,
	P3_BIHR7,
	P3_BIHR8,
	P3_BIHR9,
	P3_BIHR10,
	P3_BIHR11,
	P3_BIHR12,
	P3_BIHR13,
	P3_BIHR14,
	P3_BIHR15,
	P3_BIHR16,
	P3_BIHR17,
	P3_BIHR18,
	P3_BIHR19,
	P3_BIHR20,
	P3_BIHR21,
	P3_BIHR22,
	P3_BIHR23,
	P3_BIHR24,
	P3_BIHR25,
	P3_BIHR26,
	P3_BIHR27,
	P3_BIHR28,
	P3_BIHR29,
	P3_BIHR30,
	P3_BIHR31,
	P3_BIHR32,
	P3_BITHD,
	
	P3_CIHR2,
	P3_CIHR3,
	P3_CIHR4,
	P3_CIHR5,
	P3_CIHR6,
	P3_CIHR7,
	P3_CIHR8,
	P3_CIHR9,
	P3_CIHR10,
	P3_CIHR11,
	P3_CIHR12,
	P3_CIHR13,
	P3_CIHR14,
	P3_CIHR15,
	P3_CIHR16,
	P3_CIHR17,
	P3_CIHR18,
	P3_CIHR19,
	P3_CIHR20,
	P3_CIHR21,
	P3_CIHR22,
	P3_CIHR23,
	P3_CIHR24,
	P3_CIHR25,
	P3_CIHR26,
	P3_CIHR27,
	P3_CIHR28,
	P3_CIHR29,
	P3_CIHR30,
	P3_CIHR31,
	P3_CIHR32,
	P3_CITHD,
	
	P3_AVHR2,
	P3_AVHR3,
	P3_AVHR4,
	P3_AVHR5,
	P3_AVHR6,
	P3_AVHR7,
	P3_AVHR8,
	P3_AVHR9,
	P3_AVHR10,
	P3_AVHR11,
	P3_AVHR12,
	P3_AVHR13,
	P3_AVHR14,
	P3_AVHR15,
	P3_AVHR16,
	P3_AVHR17,
	P3_AVHR18,
	P3_AVHR19,
	P3_AVHR20,
	P3_AVHR21,
	P3_AVHR22,
	P3_AVHR23,
	P3_AVHR24,
	P3_AVHR25,
	P3_AVHR26,
	P3_AVHR27,
	P3_AVHR28,
	P3_AVHR29,
	P3_AVHR30,
	P3_AVHR31,
	P3_AVHR32,
	P3_AVTHD,
	
	P3_BVHR2,
	P3_BVHR3,
	P3_BVHR4,
	P3_BVHR5,
	P3_BVHR6,
	P3_BVHR7,
	P3_BVHR8,
	P3_BVHR9,
	P3_BVHR10,
	P3_BVHR11,
	P3_BVHR12,
	P3_BVHR13,
	P3_BVHR14,
	P3_BVHR15,
	P3_BVHR16,
	P3_BVHR17,
	P3_BVHR18,
	P3_BVHR19,
	P3_BVHR20,
	P3_BVHR21,
	P3_BVHR22,
	P3_BVHR23,
	P3_BVHR24,
	P3_BVHR25,
	P3_BVHR26,
	P3_BVHR27,
	P3_BVHR28,
	P3_BVHR29,
	P3_BVHR30,
	P3_BVHR31,
	P3_BVHR32,
	P3_BVTHD,
	
	P3_CVHR2,
	P3_CVHR3,
	P3_CVHR4,
	P3_CVHR5,
	P3_CVHR6,
	P3_CVHR7,
	P3_CVHR8,
	P3_CVHR9,
	P3_CVHR10,
	P3_CVHR11,
	P3_CVHR12,
	P3_CVHR13,
	P3_CVHR14,
	P3_CVHR15,
	P3_CVHR16,
	P3_CVHR17,
	P3_CVHR18,
	P3_CVHR19,
	P3_CVHR20,
	P3_CVHR21,
	P3_CVHR22,
	P3_CVHR23,
	P3_CVHR24,
	P3_CVHR25,
	P3_CVHR26,
	P3_CVHR27,
	P3_CVHR28,
	P3_CVHR29,
	P3_CVHR30,
	P3_CVHR31,
	P3_CVHR32,
	P3_CVTHD,
	
	P3_AIFUND,
	P3_AVFUND,
	P3_BIFUND,
	P3_BVFUND,
	P3_CIFUND,
	P3_CVFUND,
	
	P3_DFT_SCAL		=0x1D0,
	P3_DFT_CTRL		=0x1D1,
	
	P3_BGCurveK		=0x201,		//90E32AS	
	P3_BG_TEMP_P12	=0x202,
	P3_BG_TEMP_P34,
	P3_BG_TEMP_P56,
	P3_BG_TEMP_P78,
	P3_BG_TEMP_N12,
	P3_BG_TEMP_N34,
	P3_BG_TEMP_N56,
	P3_BG_TEMP_N78,	
	P3_TEMP_COMP_GAIN		=0x270,
	P3_TEMP_COMP_REF		=0x27B,
	P3_PMIGainA,
	P3_PMIGainB,
	P3_PMIGainC,
	
	
	P3_CHIPID	=0x2F0		//	
}AFE_90E3x_REG;

//=========================================================
typedef	enum
{
	AT90E2x_ChipID_Adr	=5,
	AT90E3x_ChipID_Adr	=0x2F0
}AFE_CHIPID_ADR;
typedef enum
{
	AT90E23_CHIPID		=0x2612,
    AT90E25_CHIPID      =0x2613,
	AT90E32AS_VA_CHIPID	=0x0,
	AT90E32AS_VB_CHIPID	=0x1,
	AT90E32_CHIPID		=0x1,
	AT90E32A_CHIPID		=0x3,
	AT90E36_CHIPID		=0x8001,
	AT90E36A_CHIPID		=0x8003	
}AFE_TYPE_VAL;
typedef	enum
{	
	AT90E32   =0x02,
	AT90E36	  =0x06,
	AT90E32A  =0x12,
	AT90E36A  =0x16,
	AT90E25   =0x40,
    AT90E24   =0x41,
    AT90E23   =0x42,
	AT90E32AS =0x82		
}AFE_TYPE;
typedef enum
{
	Idle_Mode =0,
	Detect_Mode,
	Patial_Mode,
	Nomal_Mode	
}AFE_MODE;

#define	INT_Num_Max		7
typedef	enum
{
	ZX0 =0,
	ZX1,
	ZX2,
	CF1,
	CF2,
	CF3,
	CF4,
//	IRQ0,
//	IRQ1	
}INT_TYPE;
#define	RMS_Num_Max		(76)
typedef enum
{
	Ua =0,
	Ub,
	Uc,
	Un,
	Ia,
	Ib,
	Ic,
	In,
	Pt,
	Pa,		//9
	Pb,
	Pc,
	Pn,
	Qt,
	Qa,
	Qb,
	Qc,
	Qn,
	SVt,	
	SAt,	//19
	Sa,
	Sb,
	Sc,
	Sn,
	PFt,
	PFa,
	PFb,
	PFc,
	PFn,
	Frq,	//29
	CNFStart,
	CALStart,
	HMStart,
	ADJStart,
	SYSStatus0,
	SYSStatus1,
	FUNCEn0,
	FUNCEn1,	//37
	Pha,		
	Phb,
	Phc,
	Phn,	
	Temperature,	//42
	UangleA,
	UangleB,
	UangleC,
	THDNUA,
	THDNUB,
	THDNUC,
	THDNIA,
	THDNIB,
	THDNIC,		//51
	
	UPeak_A,
	IPeak_A,
	UPeak_B,
	IPeak_B,
	UPeak_C,
	IPeak_C,	//56
	
	AI_HRx,
	AI_THD,
	BI_HRx,
	BI_THD,
	CI_HRx,
	CI_THD,
	AV_HRx,		//63
	AV_THD,
	BV_HRx,
	BV_THD,
	CV_HRx,
	CV_THD,
	AI_FUND,	//69
	AV_FUND,
	BI_FUND,
	BV_FUND,
	CI_FUND,	//74
	CV_FUND
		
}RMS_TYPE;
//---------------------------------------------------------

//=========================================================
typedef	struct AFE_CMD_REG_E2Adr_Tag
{
	uint16_t	cmd;
	uint16_t	regadr;
	uint16_t	e2adr;
}AFE_CMD_REG_E2Adr_Str;
typedef	union
{
	uint16_t		HFWORD;
	struct{
			uint16_t	U_SCALE	:	8;	//voltage scale
			uint16_t	I_SCALE	:	8;	//current scale
		}BIT;	
}UI_SCALE_TYPE;

typedef	union
{
	uint16_t		HFWORD;
	struct{
			uint16_t	DFT_AI	:	3;	//phase A current scale
			uint16_t	DFT_BI	:	3;	//phase B current scale
			uint16_t	DFT_CI	:	3;	//phase C current scale
			uint16_t	DFT_AV	:	2;	//phase A voltage scale
			uint16_t	DFT_BV	:	2;	//phase B voltage scale
			uint16_t	DFT_CV	:	2;	//phase C voltage scale
			uint16_t			:	1;	//NULL
		}BIT;	
}DFT_SCALE_TYPE;

typedef	union
{
	uint16_t	HWORD;
	struct
	{
		uint16_t	UaSag	:1;	//
		uint16_t	UbSag	:1;	//
		uint16_t	UcSag	:1;	//
		uint16_t		:5;//
		uint16_t	PaDir	:1;	//
		uint16_t	PbDir	:1;	//
		uint16_t	PcDir	:1;	//
		uint16_t	PTDir	:1;
		uint16_t	QaDir	:1;	//
		uint16_t	QbDir	:1;	//
		uint16_t	QcDir	:1;	//
		uint16_t	QTDir	:1;		
	}BIT;
}STATUS_TYPE;

typedef	struct
{
	uint16_t	id;
	UI_SCALE_TYPE	ulscal;
	DFT_SCALE_TYPE	dft_scale;
	uint16_t	runmode;
	STATUS_TYPE	sagstatus;
	uint16_t	thd_timer;
	uint16_t	thd_status;
	uint16_t	warmout;
	uint16_t	measure_en_timer;
	uint16_t	IntNum[INT_Num_Max];
	uint32_t	RMS[RMS_Num_Max];
    //uint64_t    test;
}AFE_Str;
//---------------------------------------------------------
//extern  const	uint8_t	afe90e25_regadr_table[];
extern	const	AFE_CMD_REG_E2Adr_Str	afe90e2x_cmd_reg_e2adr_tbl[];
extern	const	AFE_CMD_REG_E2Adr_Str	afe90e3x_cmd_reg_e2adr_tbl[];

extern	AFE_Str		VAFE;
//---------------------------------------------------------
void	AFE_DMA_ENABLE(void);
void	AFE_DMA_DISABLE(void);
void	AFE_Normal_MODE(void);
void	AFE_Patial_MODE(void);
void	AFE_Detect_MODE(void);
void	AFE_Idle_MODE(void);
void	SET_AFE_MODE( AFE_MODE mode );

void	AFE_CS_ENABLE(void);
void	AFE_CS_DISABLE(void);
void	AFE_Configure_ZX0(void);
void	AFE_ZX0_INT_handler(uint32_t temp0, uint32_t temp1);
void	AFE_Configure_ZX1(void);
void	AFE_ZX1_INT_handler(uint32_t temp0, uint32_t temp1);
void	AFE_Configure_ZX2(void);
void	AFE_ZX2_INT_handler(uint32_t temp0, uint32_t temp1);
void	AFE_Configure_CF1(void);
void	AFE_CF1_INT_handler(uint32_t temp0, uint32_t temp1);
void	AFE_Configure_CF2(void);
void	AFE_CF2_INT_handler(uint32_t temp0, uint32_t temp1);
void	AFE_Configure_CF3(void);
void	AFE_CF3_INT_handler(uint32_t temp0, uint32_t temp1);
void	AFE_Configure_CF4(void);
void	AFE_CF4_INT_handler(uint32_t temp0, uint32_t temp1);
//void	AFE_Configure_IRQ0(void);
//void	AFE_IRQ0_INT_handler(void);
//void	AFE_Configure_IRQ1(void);
//void	AFE_IRQ1_INT_handler(void);
void	AFE_Configure_IRQ0(void);
void	AFE_Configure_IRQ1(void);
void	AFE_Configure_WarmOut(void);
void	Configure_AFE_Int(void);
void	AFE_SPI_Init(void);
void	Identify_AFE_Type(void);
uint32_t 	Read_AFE_1Reg(uint16_t regaddr);
uint32_t 	write_AFE_1Reg(uint16_t regaddr,uint16_t regdata);
uint32_t	CMD_Rd_AFE_Reg(uint8_t *ptr,uint16_t regadr);
uint32_t	CMD_Wr_AFE_Reg( uint8_t *ptr,uint16_t regadr );
void		Sag_check( void );
void		Enable_Harmonic_Calculate(void);
uint32_t	Rd_Measure_Parameter(uint16_t regh_addr,uint16_t regl_addr);
uint32_t	Calculate_V_I_Mul_Scal(uint32_t rmsval,uint16_t scale);
uint32_t	Calculate_V_I_RMS( uint32_t *rmsptr,uint32_t rmsval);
void		Calculate_Power( uint32_t *rmsptr,uint32_t rmsval );
void		Calculate_PowerFactor( uint32_t *rmsptr,uint32_t rmsval );
uint32_t	Calculate_Frequency( uint32_t *rmsptr,uint32_t rmsval );
uint32_t	Calculate_THDNx( uint32_t *rmsptr,uint32_t rmsval );
void		Calculate_angle( uint32_t *rmsptr,uint32_t rmsval );
uint32_t	Calculate_V_I_Peak( uint32_t *rmsptr,uint32_t rmsval,uint32_t regid );
uint32_t	Calculate_I_V_HarmonicRatio( uint16_t reg_addr );
float		Calculate_I_V_Fundamental( uint16_t reg_addr,uint16_t scale );

uint32_t	Measure_RMS( uint32_t *ptr,const RMS_TYPE rms_id );
void		Load_AFE_Cal_Para_From_Eprom(void);
//---------------------------------------------------------

//=========================================================





/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
}
#endif
/**INDENT-ON**/
/// @endcond

#endif /* eeprom_H_INCLUDED */
