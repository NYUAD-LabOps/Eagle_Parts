/**
 * \file
 *
 * \brief LCD management
 *
 * Copyright (c) 2010-2012 Atmel Corporation. All rights reserved.
 *
 * \asf_license_start
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. The name of Atmel may not be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * 4. This software may only be redistributed and used in connection with an
 *    Atmel microcontroller product.
 *
 * THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * EXPRESSLY AND SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * \asf_license_stop
 *
 */
#ifndef LCD_DRIVER_H
#define LCD_DRIVER_H

#include "asf.h"
#include "compiler.h"

//-------------------------------------------------------------------
#define	Dsp_a	0x08
#define	Dsp_b	0x04
#define	Dsp_c	0x02
#define	Dsp_h	0x01

#define	Dsp_f	0x80
#define	Dsp_g	0x40
#define	Dsp_e	0x20
#define	Dsp_d	0x10

#define	Dsp_0	(Dsp_a+Dsp_b+Dsp_c+Dsp_d+Dsp_e+Dsp_f)
#define	Dsp_1	(Dsp_b+Dsp_c)
#define	Dsp_2	(Dsp_a+Dsp_b+Dsp_d+Dsp_e+Dsp_g)
#define	Dsp_3	(Dsp_a+Dsp_b+Dsp_c+Dsp_d+Dsp_g)
#define	Dsp_4	(Dsp_b+Dsp_c+Dsp_f+Dsp_g)
#define	Dsp_5	(Dsp_a+Dsp_c+Dsp_d+Dsp_f+Dsp_g)
#define	Dsp_6	(Dsp_a+Dsp_c+Dsp_d+Dsp_e+Dsp_f+Dsp_g)
#define	Dsp_7	(Dsp_a+Dsp_b+Dsp_c)
#define	Dsp_8	(Dsp_a+Dsp_b+Dsp_c+Dsp_d+Dsp_e+Dsp_f+Dsp_g)
#define	Dsp_9	(Dsp_a+Dsp_b+Dsp_c+Dsp_d+Dsp_f+Dsp_g)
#define	Dsp_A	(Dsp_a+Dsp_b+Dsp_c+Dsp_e+Dsp_f+Dsp_g)
#define	Dsp_B	(Dsp_c+Dsp_d+Dsp_e+Dsp_f+Dsp_g)
#define	Dsp_C	(Dsp_d+Dsp_e+Dsp_g)
#define	Dsp_D	(Dsp_b+Dsp_c+Dsp_d+Dsp_e+Dsp_g)
#define	Dsp_E	(Dsp_a+Dsp_d+Dsp_e+Dsp_f+Dsp_g)
#define	Dsp_F	(Dsp_a+Dsp_e+Dsp_f+Dsp_g)
#define	Dsp_U	(Dsp_b+Dsp_c+Dsp_d+Dsp_e+Dsp_f)
#define	Dsp_r	(Dsp_e+Dsp_g)

#define	Dsp_bC	(Dsp_a+Dsp_d+Dsp_e+Dsp_f)
#define	Dsp_L	(Dsp_d+Dsp_e+Dsp_f)
#define	Dsp_P	(Dsp_a+Dsp_b+Dsp_e+Dsp_f+Dsp_g)
#define	Dsp_t	(Dsp_d+Dsp_e+Dsp_f+Dsp_g)

#define	Con_I	1
#define	Con_E	14
#define	Con_U	16
#define	Con_r	17
#define	Con_C	18
#define	Con_L	19
#define	Con_P	20
#define	Con_T	21


#define	LCDPane_Seg_MaxNum	17
#define	LCDPane_Com_MaxNum	6
#define	Con_Reset_Num	8

typedef	struct	LCD_True_Table
{
	uint8_t	name[3];	//2 chars + 1 "null"
	uint8_t	segXcomY[2];
}LCD_True_Table_Str;
typedef	struct	Digit_Dicode_Tag
{
	uint8_t	name[2];
}Digit_Dicode_Str;

extern	const	uint8_t	DecodeDspTable[];
extern	const	LCD_True_Table_Str	LCD_True_Table[];
extern	const	Digit_Dicode_Str LCDPane_Digit_Table[];
extern	const	uint8_t	LCDPane_To_LCDDrive_Seg_Table[];
extern	const	uint8_t LCDPane_To_LCDDrive_Com_Table[];

void	DisplayPixel( uint8_t * name, uint8_t visible );
void	DisplaySingleDigit(uint8_t digitposit,uint8_t dispval);
void	DisplayText(uint8_t * text);
void 	set_LCD_contrast(uint32_t contrast);
void 	LCD_init();
void    set_slcd_ram(uint32_t pattern);
void    clear_slcd_ram(void);
//-------------------------------------------------------------------
//#define SEGMENT_S1_S13_S14 SLCDC_SMR1_LCD32
//#define SEGMENT_S2_S15 SLCDC_SMR0_LCD30
//#define SEGMENT_S3_S16 SLCDC_SMR0_LCD29
//#define SEGMENT_S4 SLCDC_SMR0_LCD28
//#define SEGMENT_S5 SLCDC_SMR0_LCD27
//#define SEGMENT_S6_S23 SLCDC_SMR0_LCD26
//#define SEGMENT_S7_S24 SLCDC_SMR0_LCD25
//#define SEGMENT_S8_S27 SLCDC_SMR0_LCD24
//#define SEGMENT_S9 SLCDC_SMR0_LCD12
//#define SEGMENT_S10_S31 SLCDC_SMR0_LCD10
//#define SEGMENT_S11_S32 SLCDC_SMR0_LCD9
//#define SEGMENT_S12_S33 SLCDC_SMR0_LCD8
//#define SEGMENT_S18_S25 SLCDC_SMR0_LCD7
//#define SEGMENT_S19_S26 SLCDC_SMR0_LCD6
//#define SEGMENT_S20_S29 SLCDC_SMR0_LCD5
//#define SEGMENT_S17_S21_S28 SLCDC_SMR0_LCD4
//#define SEGMENT_S22_S30 SLCDC_SMR0_LCD3
//
//#define COL1 SLCDC_SMR0_LCD27
//#define COL2 SLCDC_SMR0_LCD12
//#define P1 SLCDC_SMR0_LCD25
//#define P2 SLCDC_SMR0_LCD12
//#define P3 SLCDC_SMR0_LCD9
//
//#define DIGIT1_LOW_MASK SLCDC_SMR0_LCD30
//#define DIGIT1_HIGH_MASK SLCDC_SMR1_LCD32
//#define DIGIT2_LOW_MASK SLCDC_SMR0_LCD28
//#define DIGIT2_HIGH_MASK SLCDC_SMR0_LCD29
//#define DIGIT3_LOW_MASK SLCDC_SMR0_LCD26
//#define DIGIT3_HIGH_MASK SLCDC_SMR0_LCD27
//#define DIGIT4_LOW_MASK SLCDC_SMR0_LCD24
//#define DIGIT4_HIGH_MASK SLCDC_SMR0_LCD25
//#define DIGIT5_LOW_MASK SLCDC_SMR0_LCD10
//#define DIGIT5_HIGH_MASK SLCDC_SMR0_LCD12
//#define DIGIT6_LOW_MASK SLCDC_SMR0_LCD8
//#define DIGIT6_HIGH_MASK SLCDC_SMR0_LCD9
//
//
////b,c
//#define SET_DIGIT1(x,y)   SLCDC->SLCDC_COM[2].SLCDC_LMEMR |= x; \
//                          SLCDC->SLCDC_COM[3].SLCDC_LMEMR |= x
////a,b,d,e,g                             
//#define SET_DIGIT2(x,y)   SLCDC->SLCDC_COM[1].SLCDC_LMEMR |= x; \
//                          SLCDC->SLCDC_COM[2].SLCDC_LMEMR |= x; \
//                          SLCDC->SLCDC_COM[4].SLCDC_LMEMR |= x; \
//                          SLCDC->SLCDC_COM[3].SLCDC_LMEMR |= y; \
//                          SLCDC->SLCDC_COM[2].SLCDC_LMEMR |= y
////a,b,g,c,d                            
//#define SET_DIGIT3(x,y)   SLCDC->SLCDC_COM[1].SLCDC_LMEMR |= x; \
//                          SLCDC->SLCDC_COM[2].SLCDC_LMEMR |= x; \
//                          SLCDC->SLCDC_COM[2].SLCDC_LMEMR |= y; \
//                          SLCDC->SLCDC_COM[3].SLCDC_LMEMR |= x; \
//                          SLCDC->SLCDC_COM[4].SLCDC_LMEMR |= x
//                          
////f,g,b,c
//#define SET_DIGIT4(x,y)   SLCDC->SLCDC_COM[1].SLCDC_LMEMR |= y; \
//                          SLCDC->SLCDC_COM[2].SLCDC_LMEMR |= y; \
//                          SLCDC->SLCDC_COM[2].SLCDC_LMEMR |= x; \
//                          SLCDC->SLCDC_COM[3].SLCDC_LMEMR |= x;                           
////a,f,g,c,d                     
//#define SET_DIGIT5(x,y)   SLCDC->SLCDC_COM[1].SLCDC_LMEMR |= x; \
//                          SLCDC->SLCDC_COM[1].SLCDC_LMEMR |= y; \
//                          SLCDC->SLCDC_COM[2].SLCDC_LMEMR |= y; \
//                          SLCDC->SLCDC_COM[3].SLCDC_LMEMR |= x; \
//                          SLCDC->SLCDC_COM[4].SLCDC_LMEMR |= x
//                          
////a,f,g,c,d,e                     
//#define SET_DIGIT6(x,y)   SLCDC->SLCDC_COM[1].SLCDC_LMEMR |= x; \
//                          SLCDC->SLCDC_COM[1].SLCDC_LMEMR |= y; \
//                          SLCDC->SLCDC_COM[2].SLCDC_LMEMR |= y; \
//                          SLCDC->SLCDC_COM[3].SLCDC_LMEMR |= x; \
//                          SLCDC->SLCDC_COM[4].SLCDC_LMEMR |= x; \
//                          SLCDC->SLCDC_COM[3].SLCDC_LMEMR |= y
//
////a,b,c                     
//#define SET_DIGIT7(x,y)   SLCDC->SLCDC_COM[1].SLCDC_LMEMR |= x; \
//                          SLCDC->SLCDC_COM[2].SLCDC_LMEMR |= x; \
//                          SLCDC->SLCDC_COM[3].SLCDC_LMEMR |= x
//                            
////b,a,f,g,c,d,e                     
//#define SET_DIGIT8(x,y)   SLCDC->SLCDC_COM[2].SLCDC_LMEMR |= x; \
//                          SLCDC->SLCDC_COM[1].SLCDC_LMEMR |= x; \
//                          SLCDC->SLCDC_COM[1].SLCDC_LMEMR |= y; \
//                          SLCDC->SLCDC_COM[2].SLCDC_LMEMR |= y; \
//                          SLCDC->SLCDC_COM[3].SLCDC_LMEMR |= x; \
//                          SLCDC->SLCDC_COM[4].SLCDC_LMEMR |= x; \
//                          SLCDC->SLCDC_COM[3].SLCDC_LMEMR |= y
////b,a,f,g,c,d
//#define SET_DIGIT9(x,y)   SLCDC->SLCDC_COM[2].SLCDC_LMEMR |= x; \
//                          SLCDC->SLCDC_COM[1].SLCDC_LMEMR |= x; \
//                          SLCDC->SLCDC_COM[1].SLCDC_LMEMR |= y; \
//                          SLCDC->SLCDC_COM[2].SLCDC_LMEMR |= y; \
//                          SLCDC->SLCDC_COM[3].SLCDC_LMEMR |= x; \
//                          SLCDC->SLCDC_COM[4].SLCDC_LMEMR |= x
//                            
////b,a,f,c,d,e
//#define SET_DIGIT0(x,y)   SLCDC->SLCDC_COM[2].SLCDC_LMEMR |= x; \
//                          SLCDC->SLCDC_COM[1].SLCDC_LMEMR |= x; \
//                          SLCDC->SLCDC_COM[1].SLCDC_LMEMR |= y; \
//                          SLCDC->SLCDC_COM[3].SLCDC_LMEMR |= x; \
//                          SLCDC->SLCDC_COM[4].SLCDC_LMEMR |= x; \
//                          SLCDC->SLCDC_COM[3].SLCDC_LMEMR |= y   
//
////10=A  b,a,f,g,c,e                     
//#define SET_DIGIT_A(x,y)  SLCDC->SLCDC_COM[2].SLCDC_LMEMR |= x; \
//                          SLCDC->SLCDC_COM[1].SLCDC_LMEMR |= x; \
//                          SLCDC->SLCDC_COM[1].SLCDC_LMEMR |= y; \
//                          SLCDC->SLCDC_COM[2].SLCDC_LMEMR |= y; \
//                          SLCDC->SLCDC_COM[3].SLCDC_LMEMR |= x; \
//                          SLCDC->SLCDC_COM[3].SLCDC_LMEMR |= y
//
////11=b  f,g,c,d,e                     
//#define SET_DIGIT_b(x,y)  SLCDC->SLCDC_COM[1].SLCDC_LMEMR |= y; \
//                          SLCDC->SLCDC_COM[2].SLCDC_LMEMR |= y; \
//                          SLCDC->SLCDC_COM[3].SLCDC_LMEMR |= x; \
//                          SLCDC->SLCDC_COM[4].SLCDC_LMEMR |= x; \
//                          SLCDC->SLCDC_COM[3].SLCDC_LMEMR |= y						  
//
////12=c	a,f,d,e                     
//#define SET_DIGIT_C(x,y)  SLCDC->SLCDC_COM[1].SLCDC_LMEMR |= x; \
//                          SLCDC->SLCDC_COM[1].SLCDC_LMEMR |= y; \
//                          SLCDC->SLCDC_COM[4].SLCDC_LMEMR |= x; \
//                          SLCDC->SLCDC_COM[3].SLCDC_LMEMR |= y						  
//
////13=d	b,g,c,d,e                     
//#define SET_DIGIT_d(x,y)  SLCDC->SLCDC_COM[1].SLCDC_LMEMR |= x; \
//                          SLCDC->SLCDC_COM[1].SLCDC_LMEMR |= y; \
//                          SLCDC->SLCDC_COM[3].SLCDC_LMEMR |= x; \
//                          SLCDC->SLCDC_COM[4].SLCDC_LMEMR |= x; \
//                          SLCDC->SLCDC_COM[3].SLCDC_LMEMR |= y						  
//
////14=E	a,f,g,d,e                     
//#define SET_DIGIT_E(x,y)  SLCDC->SLCDC_COM[1].SLCDC_LMEMR |= x; \
//                          SLCDC->SLCDC_COM[1].SLCDC_LMEMR |= y; \
//                          SLCDC->SLCDC_COM[2].SLCDC_LMEMR |= y; \
//                          SLCDC->SLCDC_COM[4].SLCDC_LMEMR |= x; \
//                          SLCDC->SLCDC_COM[3].SLCDC_LMEMR |= y						  
//
////15=F	a,f,g,e                     
//#define SET_DIGIT_F(x,y)  SLCDC->SLCDC_COM[1].SLCDC_LMEMR |= x; \
//                          SLCDC->SLCDC_COM[1].SLCDC_LMEMR |= y; \
//                          SLCDC->SLCDC_COM[2].SLCDC_LMEMR |= y; \
//                          SLCDC->SLCDC_COM[3].SLCDC_LMEMR |= y						  
//
////16=U	b,f,c,d,e                     
//#define SET_DIGIT_U(x,y)  SLCDC->SLCDC_COM[2].SLCDC_LMEMR |= x; \
//                          SLCDC->SLCDC_COM[1].SLCDC_LMEMR |= y; \
//                          SLCDC->SLCDC_COM[3].SLCDC_LMEMR |= x; \
//                          SLCDC->SLCDC_COM[4].SLCDC_LMEMR |= x; \
//                          SLCDC->SLCDC_COM[3].SLCDC_LMEMR |= y                          
//						 
////b,a,f,g,c,d,e                     
//#define CLEAR_DIGIT(x,y)  SLCDC->SLCDC_COM[2].SLCDC_LMEMR &= ~x; \
//                          SLCDC->SLCDC_COM[1].SLCDC_LMEMR &= ~x; \
//                          SLCDC->SLCDC_COM[1].SLCDC_LMEMR &= ~y; \
//                          SLCDC->SLCDC_COM[2].SLCDC_LMEMR &= ~y; \
//                          SLCDC->SLCDC_COM[3].SLCDC_LMEMR &= ~x; \
//                          SLCDC->SLCDC_COM[4].SLCDC_LMEMR &= ~x; \
//                          SLCDC->SLCDC_COM[3].SLCDC_LMEMR &= ~y     
//
//                            
//    //############### SMALL DIGITS ##################################
////c,b                            
//#define SM_SET_DIGIT1(x,y)   SLCDC->SLCDC_COM[1].SLCDC_LMEMR |= x; \
//                          SLCDC->SLCDC_COM[2].SLCDC_LMEMR |= x
////a,b,d,e,g                             
//#define SM_SET_DIGIT2(x,y)   SLCDC->SLCDC_COM[3].SLCDC_LMEMR |= x; \
//                          SLCDC->SLCDC_COM[2].SLCDC_LMEMR |= x; \
//                          SLCDC->SLCDC_COM[0].SLCDC_LMEMR |= x; \
//                          SLCDC->SLCDC_COM[1].SLCDC_LMEMR |= y; \
//                          SLCDC->SLCDC_COM[2].SLCDC_LMEMR |= y
////a,b,g,c,d                            
//#define SM_SET_DIGIT3(x,y)   SLCDC->SLCDC_COM[3].SLCDC_LMEMR |= x; \
//                          SLCDC->SLCDC_COM[2].SLCDC_LMEMR |= x; \
//                          SLCDC->SLCDC_COM[2].SLCDC_LMEMR |= y; \
//                          SLCDC->SLCDC_COM[1].SLCDC_LMEMR |= x; \
//                          SLCDC->SLCDC_COM[0].SLCDC_LMEMR |= x
//                          
////f,g,b,c
//#define SM_SET_DIGIT4(x,y)   SLCDC->SLCDC_COM[3].SLCDC_LMEMR |= y; \
//                          SLCDC->SLCDC_COM[2].SLCDC_LMEMR |= y; \
//                          SLCDC->SLCDC_COM[2].SLCDC_LMEMR |= x; \
//                          SLCDC->SLCDC_COM[1].SLCDC_LMEMR |= x;                           
////a,f,g,c,d                     
//#define SM_SET_DIGIT5(x,y)   SLCDC->SLCDC_COM[3].SLCDC_LMEMR |= x; \
//                          SLCDC->SLCDC_COM[3].SLCDC_LMEMR |= y; \
//                          SLCDC->SLCDC_COM[2].SLCDC_LMEMR |= y; \
//                          SLCDC->SLCDC_COM[1].SLCDC_LMEMR |= x; \
//                          SLCDC->SLCDC_COM[0].SLCDC_LMEMR |= x
//                          
////a,f,g,c,d,e                     
//#define SM_SET_DIGIT6(x,y)   SLCDC->SLCDC_COM[3].SLCDC_LMEMR |= x; \
//                          SLCDC->SLCDC_COM[3].SLCDC_LMEMR |= y; \
//                          SLCDC->SLCDC_COM[2].SLCDC_LMEMR |= y; \
//                          SLCDC->SLCDC_COM[1].SLCDC_LMEMR |= x; \
//                          SLCDC->SLCDC_COM[0].SLCDC_LMEMR |= x; \
//                          SLCDC->SLCDC_COM[1].SLCDC_LMEMR |= y
//
////a,b,c                     
//#define SM_SET_DIGIT7(x,y)   SLCDC->SLCDC_COM[3].SLCDC_LMEMR |= x; \
//                          SLCDC->SLCDC_COM[2].SLCDC_LMEMR |= x; \
//                          SLCDC->SLCDC_COM[1].SLCDC_LMEMR |= x
//                            
////b,a,f,g,c,d,e                     
//#define SM_SET_DIGIT8(x,y)   SLCDC->SLCDC_COM[2].SLCDC_LMEMR |= x; \
//                          SLCDC->SLCDC_COM[3].SLCDC_LMEMR |= x; \
//                          SLCDC->SLCDC_COM[3].SLCDC_LMEMR |= y; \
//                          SLCDC->SLCDC_COM[2].SLCDC_LMEMR |= y; \
//                          SLCDC->SLCDC_COM[1].SLCDC_LMEMR |= x; \
//                          SLCDC->SLCDC_COM[0].SLCDC_LMEMR |= x; \
//                          SLCDC->SLCDC_COM[1].SLCDC_LMEMR |= y
////b,a,f,g,c,d
//#define SM_SET_DIGIT9(x,y)   SLCDC->SLCDC_COM[2].SLCDC_LMEMR |= x; \
//                          SLCDC->SLCDC_COM[3].SLCDC_LMEMR |= x; \
//                          SLCDC->SLCDC_COM[3].SLCDC_LMEMR |= y; \
//                          SLCDC->SLCDC_COM[2].SLCDC_LMEMR |= y; \
//                          SLCDC->SLCDC_COM[1].SLCDC_LMEMR |= x; \
//                          SLCDC->SLCDC_COM[0].SLCDC_LMEMR |= x
//                            
////b,a,f,c,d,e
//#define SM_SET_DIGIT0(x,y)   SLCDC->SLCDC_COM[2].SLCDC_LMEMR |= x; \
//                          SLCDC->SLCDC_COM[3].SLCDC_LMEMR |= x; \
//                          SLCDC->SLCDC_COM[3].SLCDC_LMEMR |= y; \
//                          SLCDC->SLCDC_COM[1].SLCDC_LMEMR |= x; \
//                          SLCDC->SLCDC_COM[0].SLCDC_LMEMR |= x; \
//                          SLCDC->SLCDC_COM[1].SLCDC_LMEMR |= y   
//
////b,a,f,g,c,d,e                     
//#define SM_CLEAR_DIGIT(x,y)  SLCDC->SLCDC_COM[2].SLCDC_LMEMR &= ~x; \
//                          SLCDC->SLCDC_COM[3].SLCDC_LMEMR &= ~x; \
//                          SLCDC->SLCDC_COM[3].SLCDC_LMEMR &= ~y; \
//                          SLCDC->SLCDC_COM[2].SLCDC_LMEMR &= ~y; \
//                          SLCDC->SLCDC_COM[1].SLCDC_LMEMR &= ~x; \
//                          SLCDC->SLCDC_COM[0].SLCDC_LMEMR &= ~x; \
//                          SLCDC->SLCDC_COM[1].SLCDC_LMEMR &= ~y                           
//                            
//                            
//                            
//                            
//                            
//    //############### SMALL DIGITS END##################################
//
//void set_col1();
//void set_col2();
//void set_p2();
//void set_p1();
//void set_p3();
//void clear_col1();
//void clear_col2();
//void clear_p2();
//void clear_p1();
//void clear_p3();
//uint32_t clear_segment_index(uint32_t index);
//uint32_t set_upper_digit(uint32_t index, uint32_t value);
//uint32_t display_segment_index(uint32_t index);
//void clear_upper_digits();
//void clear_lower_digits();
//uint32_t set_lower_digit(uint32_t index, uint32_t value);
//void clear_display();
//void 	set_LCD_contrast(uint32_t contrast);
//void 	LCD_init();
//void    set_slcd_ram(uint32_t pattern);
//void    clear_slcd_ram(void);



#endif