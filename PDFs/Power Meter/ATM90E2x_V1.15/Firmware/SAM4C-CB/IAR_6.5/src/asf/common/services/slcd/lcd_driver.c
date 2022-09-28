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

#include "lcd_driver.h"

//------------------------------------------------------------------------
const	uint8_t	DecodeDspTable[22]=
	{Dsp_0,Dsp_1,Dsp_2,Dsp_3,Dsp_4,Dsp_5,Dsp_6,Dsp_7,Dsp_8,Dsp_9,Dsp_A,Dsp_B,Dsp_C,Dsp_D,Dsp_E,Dsp_F,Dsp_U,Dsp_r,Dsp_bC,Dsp_L,Dsp_P,Dsp_t};

//typedef	struct	LCD_True_Table
//{
//	uint8_t	name[5];	//4 chars + 1 "null"
//	uint8_t	segXcomY[2];
//}LCD_True_Table_Str;

const	LCD_True_Table_Str	LCD_True_Table[LCDPane_Seg_MaxNum*LCDPane_Com_MaxNum+Con_Reset_Num]=
{
	//------seg0---com0--------5---
	{"7d",{0,0}},
	{"7c",{0,1}},
	{"7b",{0,2}},
	{"7a",{0,3}},
	{"˧",{0,4}},
	{"Ξ",{0,5}},
	//------seg1---com0--------5---	
	{"At",{1,0}},
	{"me",{1,0}},		//+2
	{"l®",{1,0}},		//
	{"8e",{1,1}},
	{"8g",{1,2}},
	{"8f",{1,3}},
	{"/",{1,4}},
	{"˂",{1,5}},
	//------seg2---com0--------5---
	{"8d",{2,0}},
	{"8c",{2,1}},
	{"8b",{2,2}},
	{"8a",{2,3}},
	{"ʅ",{2,4}},
	{"─",{2,5}},
	//------seg3---com0--------5---
	{"˽",{3,0}},
	{"9e",{3,1}},
	{"9g",{3,2}},
	{"9f",{3,3}},
	{"V",{3,4}},
	{"m³",{3,5}},
	//------seg4---com0--------5---
	{"9d",{4,0}},
	{"9c",{4,1}},
	{"9b",{4,2}},
	{"9a",{4,3}},
	{"k",{4,4}},
	{"t³",{4,5}},
	//------seg5---com0--------5---
	{"¤C",{5,0}},
	{"6a",{5,1}},
	{"6b",{5,2}},
	{"6c",{5,3}},
	{"6d",{5,4}},
	{"˅",{5,5}},
	//------seg6---com0--------5---
	{"¤B",{6,0}},
	{"6f",{6,1}},
	{"6g",{6,2}},
	{"6e",{6,3}},
	{"p3",{6,4}},
	{"˃",{6,5}},
	//------seg7---com0--------5---
	{"¤A",{7,0}},
	{"5a",{7,1}},
	{"5b",{7,2}},
	{"5c",{7,3}},
	{"5d",{7,4}},
	{"=",{7,5}},
	//------seg8---com0--------5---
	{"D",{8,0}},
	{"5f",{8,1}},
	{"5g",{8,2}},
	{"5e",{8,3}},
	{":2",{8,4}},
	{"p2",{8,5}},
	//------seg9---com0--------5---
	{"C", {9,0}},
	{"4a",{9,1}},
	{"4b",{9,2}},
	{"4c",{9,3}},
	{"4d",{9,4}},
	{"˄",{9,5}},
	//------seg10---com0--------5---
	{"B", {10,0}},
	{"4f",{10,1}},
	{"4g",{10,2}},
	{"4e",{10,3}},
	{"p1",{10,4}},
	{"h",{10,5}},
	//------seg11---com0--------5---
	{"A", {11,0}},
	{"3a",{11,1}},
	{"3b",{11,2}},
	{"3c",{11,3}},
	{"3d",{11,4}},
	{"r",{11,5}},
	//------seg12---com0--------5---
	{"x", {12,0}},
	{"3f",{12,1}},
	{"3g",{12,2}},
	{"3e",{12,3}},
	{":1",{12,4}},
	{"7f",{12,5}},
	//------seg13---com0--------5---
	{"ϖ", {13,0}},
	{"2a",{13,1}},
	{"2b",{13,2}},
	{"2c",{13,3}},
	{"2d",{13,4}},
	{"7g",{13,5}},
	//------seg14---com0--------5---
	{"ᵯ", {14,0}},
	{"2f",{14,1}},
	{"2g",{14,2}},
	{"2e",{14,3}},
	{"Co",{14,4}},	
	{"nt",{14,4}},	//+3
	{"Cu",{14,4}},	//	
	{"m-",{14,4}},	//
	{"7e",{14,5}},
	//------seg15---com0--------5---
	{"₪", {15,0}},
	{"1a",{15,1}},
	{"1b",{15,2}},
	{"1c",{15,3}},
	{"1d",{15,4}},
	{"EO",{15,5}},
	{"I-",{15,5}},	//+1
	//------seg16---com0--------5---
	{"Ψ", {16,0}},
	{"1f",{16,1}},
	{"1g",{16,2}},
	{"1e",{16,3}},
	{"TE",{16,4}},
	{"ST",{16,4}},	//+1
	{"AL",{16,5}},	
	{"T-",{16,5}},	//+1
};
//typedef	struct	Digit_Dicode_Tag
//{
//	uint8_t	name[2];
//}Digit_Dicode_Str;
const	Digit_Dicode_Str LCDPane_Digit_Table[63]=
{
	"1f","1g","1e","1d","1a","1b","1c",
	"2f","2g","2e","2d","2a","2b","2c",
	"3f","3g","3e","3d","3a","3b","3c",
	"4f","4g","4e","4d","4a","4b","4c",
	"5f","5g","5e","5d","5a","5b","5c",
	"6f","6g","6e","6d","6a","6b","6c",
	"7f","7g","7e","7d","7a","7b","7c",
	"8f","8g","8e","8d","8a","8b","8c",
	"9f","9g","9e","9d","9a","9b","9c",
};
const uint8_t	LCDPane_To_LCDDrive_Seg_Table[LCDPane_Seg_MaxNum]=
{
	33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49
};
const	uint8_t LCDPane_To_LCDDrive_Com_Table[LCDPane_Com_MaxNum]=
{
	0,1,2,3,4,5
};
//=========================================================
//description		::	display single pixel symbol 
//function			::	DisplayPixel
//input				::	name->display symbol first address
//								visible=1 display,=0 disable
//output			::	none
//call				::	none
//effect			::
//=========================================================
void	DisplayPixel( uint8_t * name , uint8_t visible )
{
	uint8_t	i;	
	for(i=0;i<(LCDPane_Seg_MaxNum*LCDPane_Com_MaxNum +Con_Reset_Num);i++)
	{	
		if( *name ==LCD_True_Table[i].name[0] && *(name+1) ==LCD_True_Table[i].name[1] ) 
		{
			if(visible==1)
			{
				if( LCDPane_To_LCDDrive_Seg_Table[ LCD_True_Table[i].segXcomY[0] ] >31 )
				{
					SLCDC->SLCDC_COM[ LCDPane_To_LCDDrive_Com_Table[ LCD_True_Table[i].segXcomY[1] ] ].SLCDC_MMEMR |=0x1u<<( LCDPane_To_LCDDrive_Seg_Table[ LCD_True_Table[i].segXcomY[0] ]-32 );
				}
				else
				{
					SLCDC->SLCDC_COM[ LCDPane_To_LCDDrive_Com_Table[ LCD_True_Table[i].segXcomY[1] ] ].SLCDC_LMEMR |=0x1u<<( LCDPane_To_LCDDrive_Seg_Table[ LCD_True_Table[i].segXcomY[0] ] );
				}				
			}
			
			else
			{
				if( LCDPane_To_LCDDrive_Seg_Table[ LCD_True_Table[i].segXcomY[0] ] >31 )
				{
					SLCDC->SLCDC_COM[ LCDPane_To_LCDDrive_Com_Table[ LCD_True_Table[i].segXcomY[1] ] ].SLCDC_MMEMR &=~( 0x1u<<( LCDPane_To_LCDDrive_Seg_Table[ LCD_True_Table[i].segXcomY[0] ]-32 ) );
				}
				else
				{
					SLCDC->SLCDC_COM[ LCDPane_To_LCDDrive_Com_Table[ LCD_True_Table[i].segXcomY[1] ] ].SLCDC_LMEMR &=~( 0x1u<<( LCDPane_To_LCDDrive_Seg_Table[ LCD_True_Table[i].segXcomY[0] ] ) );
				}			
			}
		
			break;
		}		
	}
}
//=========================================================
//description		::	display single bcd  
//function			::	DisplaySingleDigit
//input				::	digitposit
//						dispval
//output			::	none
//call				::	none
//effect			::
//=========================================================
void	DisplaySingleDigit(uint8_t digitposit,uint8_t dispval)
{
	uint32_t	i;
	uint8_t		val;
	val =DecodeDspTable[dispval];
	for(i=0;i<7;i++)
	{
		if( (val&0x80) ==0x80 )
		{
			DisplayPixel( (uint8_t *)(LCDPane_Digit_Table[digitposit*7+i].name),1 );	
		}
		val =val<<1;
	}
}	
//=========================================================
//description		::	display text  
//function			::	DisplayText
//input				::	*text
//output			::	none
//call				::	none
//effect			::
//=========================================================
void	DisplayText(uint8_t * text)
{
	uint32_t	i;
	for(i=0;i<10;i=i+2)
	{
		if( *(text +i)==0 )
			break;
		DisplayPixel( text+i, 1 );
	}
}


/*

//This fucntion is used to set hte number on the 3 small digits. The input value should be from 0 to 9
// Any other value with turn off the digit completely
uint32_t set_lower_digit(uint32_t index, uint32_t value)
{
  uint32_t mask_low = 0, mask_high = 0;
  
  if( index < 1 || index > 3)
    return 0;
  
 
  switch(index)
  {
      case 1:
      mask_low = SLCDC_SMR0_LCD3;
      //mask_high = DIGIT1_HIGH_MASK;
      break;
      
      case 2:
      mask_low = SLCDC_SMR0_LCD5;
      mask_high = SLCDC_SMR0_LCD4;
      break;
      
      case 3:
      mask_low = SLCDC_SMR0_LCD7;
      mask_high = SLCDC_SMR0_LCD6;
      break;
  }
  

  if(index == 1)
  {
      SLCDC->SLCDC_COM[2].SLCDC_LMEMR &= ~mask_low; 
      SLCDC->SLCDC_COM[3].SLCDC_LMEMR &= ~mask_low; 
      SLCDC->SLCDC_COM[5].SLCDC_LMEMR &= ~SLCDC_SMR0_LCD29; //e
      SLCDC->SLCDC_COM[5].SLCDC_LMEMR &= ~SLCDC_SMR0_LCD27; //f
      SLCDC->SLCDC_COM[1].SLCDC_LMEMR &= ~mask_low; 
      SLCDC->SLCDC_COM[0].SLCDC_LMEMR &= ~mask_low; 
      SLCDC->SLCDC_COM[5].SLCDC_LMEMR &= ~SLCDC_SMR0_LCD28; //g
    
      switch (value)
      {
          case 0:
          SLCDC->SLCDC_COM[2].SLCDC_LMEMR |= mask_low; 
          SLCDC->SLCDC_COM[3].SLCDC_LMEMR |= mask_low; 
          SLCDC->SLCDC_COM[5].SLCDC_LMEMR |= SLCDC_SMR0_LCD27; 
          SLCDC->SLCDC_COM[1].SLCDC_LMEMR |= mask_low; 
          SLCDC->SLCDC_COM[0].SLCDC_LMEMR |= mask_low; 
          SLCDC->SLCDC_COM[5].SLCDC_LMEMR |= SLCDC_SMR0_LCD29;
          break;
          
          case 1:
          SM_SET_DIGIT1(mask_low, mask_high);
          break;
          
          case 2:
          SLCDC->SLCDC_COM[3].SLCDC_LMEMR |= mask_low; 
          SLCDC->SLCDC_COM[2].SLCDC_LMEMR |= mask_low; 
          SLCDC->SLCDC_COM[0].SLCDC_LMEMR |= mask_low; 
          SLCDC->SLCDC_COM[5].SLCDC_LMEMR |= SLCDC_SMR0_LCD28; 
          SLCDC->SLCDC_COM[5].SLCDC_LMEMR |= SLCDC_SMR0_LCD29;
          break;
          
          case 3:
          SLCDC->SLCDC_COM[3].SLCDC_LMEMR |= mask_low; 
          SLCDC->SLCDC_COM[2].SLCDC_LMEMR |= mask_low; 
          SLCDC->SLCDC_COM[5].SLCDC_LMEMR |= SLCDC_SMR0_LCD28; 
          SLCDC->SLCDC_COM[1].SLCDC_LMEMR |= mask_low; 
          SLCDC->SLCDC_COM[0].SLCDC_LMEMR |= mask_low;
          break;
          
          case 4:
          SLCDC->SLCDC_COM[5].SLCDC_LMEMR |= SLCDC_SMR0_LCD28; 
          SLCDC->SLCDC_COM[5].SLCDC_LMEMR |= SLCDC_SMR0_LCD27; 
          SLCDC->SLCDC_COM[2].SLCDC_LMEMR |= mask_low; 
          SLCDC->SLCDC_COM[1].SLCDC_LMEMR |= mask_low;
          break;
          
          case 5:
          SLCDC->SLCDC_COM[3].SLCDC_LMEMR |= mask_low; 
          SLCDC->SLCDC_COM[5].SLCDC_LMEMR |= SLCDC_SMR0_LCD27; 
          SLCDC->SLCDC_COM[5].SLCDC_LMEMR |= SLCDC_SMR0_LCD28; 
          SLCDC->SLCDC_COM[1].SLCDC_LMEMR |= mask_low; 
          SLCDC->SLCDC_COM[0].SLCDC_LMEMR |= mask_low;
          break;
          
          case 6:
          SLCDC->SLCDC_COM[3].SLCDC_LMEMR |= mask_low; 
          SLCDC->SLCDC_COM[5].SLCDC_LMEMR |= SLCDC_SMR0_LCD27; 
          SLCDC->SLCDC_COM[5].SLCDC_LMEMR |= SLCDC_SMR0_LCD28; 
          SLCDC->SLCDC_COM[1].SLCDC_LMEMR |= mask_low; 
          SLCDC->SLCDC_COM[0].SLCDC_LMEMR |= mask_low; 
          SLCDC->SLCDC_COM[5].SLCDC_LMEMR |= SLCDC_SMR0_LCD29;
          break;
          
          case 7:
          SM_SET_DIGIT7(mask_low, mask_high);
          break;
          
          case 8:
          SLCDC->SLCDC_COM[2].SLCDC_LMEMR |= mask_low; 
          SLCDC->SLCDC_COM[3].SLCDC_LMEMR |= mask_low; 
          SLCDC->SLCDC_COM[5].SLCDC_LMEMR |= SLCDC_SMR0_LCD27; 
          SLCDC->SLCDC_COM[5].SLCDC_LMEMR |= SLCDC_SMR0_LCD28; 
          SLCDC->SLCDC_COM[1].SLCDC_LMEMR |= mask_low; 
          SLCDC->SLCDC_COM[0].SLCDC_LMEMR |= mask_low; 
          SLCDC->SLCDC_COM[5].SLCDC_LMEMR |= SLCDC_SMR0_LCD29;
          break;
          
          case 9:
          SLCDC->SLCDC_COM[2].SLCDC_LMEMR |= mask_low; 
          SLCDC->SLCDC_COM[3].SLCDC_LMEMR |= mask_low; 
          SLCDC->SLCDC_COM[5].SLCDC_LMEMR |= SLCDC_SMR0_LCD27; 
          SLCDC->SLCDC_COM[5].SLCDC_LMEMR |= SLCDC_SMR0_LCD28; 
          SLCDC->SLCDC_COM[1].SLCDC_LMEMR |= mask_low; 
          SLCDC->SLCDC_COM[0].SLCDC_LMEMR |= mask_low;
          break;
          
          default:
          //clear
          break;

      }
  
  }
  else
  {
      SM_CLEAR_DIGIT(mask_low,mask_high);
      switch (value)
      {
          case 0:
          SM_SET_DIGIT0(mask_low, mask_high);
          break;
          
          case 1:
          SM_SET_DIGIT1(mask_low, mask_high);
          break;
          
          case 2:
          SM_SET_DIGIT2(mask_low, mask_high);
          break;
          
          case 3:
          SM_SET_DIGIT3(mask_low, mask_high);
          break;
          
          case 4:
          SM_SET_DIGIT4(mask_low, mask_high);
          break;
          
          case 5:
          SM_SET_DIGIT5(mask_low, mask_high);
          break;
          
          case 6:
          SM_SET_DIGIT6(mask_low, mask_high);
          break;
          
          case 7:
          SM_SET_DIGIT7(mask_low, mask_high);
          break;
          
          case 8:
          SM_SET_DIGIT8(mask_low, mask_high);
          break;
          
          case 9:
          SM_SET_DIGIT9(mask_low, mask_high);
          break;
          
          default:
          //clear
          break;

      }

  }
  return 1;
}


//This fucntion is used to set hte number on the 6 big digits. The input value should be from 0 to 9
// Any other value with turn off the digit completely
uint32_t set_upper_digit(uint32_t index, uint32_t value)
{
  uint32_t mask_low = 0, mask_high = 0;
  
  if( index < 1 || index > 6)
    return 0;
  
 
  switch(index)
  {
      case 1:
      mask_low = DIGIT1_LOW_MASK;
      mask_high = DIGIT1_HIGH_MASK;
      break;
      
      case 2:
      mask_low = DIGIT2_LOW_MASK;
      mask_high = DIGIT2_HIGH_MASK;
      break;
      
      case 3:
      mask_low = DIGIT3_LOW_MASK;
      mask_high = DIGIT3_HIGH_MASK;
      break;
      
      case 4:
      mask_low = DIGIT4_LOW_MASK;
      mask_high = DIGIT4_HIGH_MASK;
      break;
      
      case 5:
      mask_low = DIGIT5_LOW_MASK;
      mask_high = DIGIT5_HIGH_MASK;
      break;
      
      case 6:
      mask_low = DIGIT6_LOW_MASK;
      mask_high = DIGIT6_HIGH_MASK;
      break;
  }
  

  
  //Special handling for Digit 1 because it uses SLCDC_MMEMR
  if(index == 1)
  {
      SLCDC->SLCDC_COM[2].SLCDC_LMEMR &= ~mask_low; 
      SLCDC->SLCDC_COM[1].SLCDC_LMEMR &= ~mask_low; 
      SLCDC->SLCDC_COM[1].SLCDC_MMEMR &= ~mask_high; 
      SLCDC->SLCDC_COM[2].SLCDC_MMEMR &= ~mask_high; 
      SLCDC->SLCDC_COM[3].SLCDC_LMEMR &= ~mask_low; 
      SLCDC->SLCDC_COM[4].SLCDC_LMEMR &= ~mask_low; 
      SLCDC->SLCDC_COM[3].SLCDC_MMEMR &= ~mask_high;   
    
    
      switch (value)
      {
          case 0:
          SLCDC->SLCDC_COM[2].SLCDC_LMEMR |= mask_low; 
          SLCDC->SLCDC_COM[1].SLCDC_LMEMR |= mask_low; 
          SLCDC->SLCDC_COM[1].SLCDC_MMEMR |= mask_high; 
          SLCDC->SLCDC_COM[3].SLCDC_LMEMR |= mask_low; 
          SLCDC->SLCDC_COM[4].SLCDC_LMEMR |= mask_low; 
          SLCDC->SLCDC_COM[3].SLCDC_MMEMR |= mask_high; 
          break;
          
          case 1:
          SLCDC->SLCDC_COM[2].SLCDC_LMEMR |= mask_low;
          SLCDC->SLCDC_COM[3].SLCDC_LMEMR |= mask_low;
          break;
          
          case 2:
          SLCDC->SLCDC_COM[1].SLCDC_LMEMR |= mask_low; 
          SLCDC->SLCDC_COM[2].SLCDC_LMEMR |= mask_low; 
          SLCDC->SLCDC_COM[4].SLCDC_LMEMR |= mask_low; 
          SLCDC->SLCDC_COM[3].SLCDC_MMEMR |= mask_high; 
          SLCDC->SLCDC_COM[2].SLCDC_MMEMR |= mask_high;
          break;
          
          case 3:
          SLCDC->SLCDC_COM[1].SLCDC_LMEMR |= mask_low; 
          SLCDC->SLCDC_COM[2].SLCDC_LMEMR |= mask_low; 
          SLCDC->SLCDC_COM[2].SLCDC_MMEMR |= mask_high; 
          SLCDC->SLCDC_COM[3].SLCDC_LMEMR |= mask_low; 
          SLCDC->SLCDC_COM[4].SLCDC_LMEMR |= mask_low;
          break;
          
          case 4:
          SLCDC->SLCDC_COM[1].SLCDC_MMEMR |= mask_high; 
          SLCDC->SLCDC_COM[2].SLCDC_MMEMR |= mask_high; 
          SLCDC->SLCDC_COM[2].SLCDC_LMEMR |= mask_low; 
          SLCDC->SLCDC_COM[3].SLCDC_LMEMR |= mask_low;
          break;
          
          case 5:
          SLCDC->SLCDC_COM[1].SLCDC_LMEMR |= mask_low; 
          SLCDC->SLCDC_COM[1].SLCDC_MMEMR |= mask_high; 
          SLCDC->SLCDC_COM[2].SLCDC_MMEMR |= mask_high; 
          SLCDC->SLCDC_COM[3].SLCDC_LMEMR |= mask_low; 
          SLCDC->SLCDC_COM[4].SLCDC_LMEMR |= mask_low;
          break;
          
          case 6:
          SLCDC->SLCDC_COM[1].SLCDC_LMEMR |= mask_low; 
          SLCDC->SLCDC_COM[1].SLCDC_MMEMR |= mask_high; 
          SLCDC->SLCDC_COM[2].SLCDC_MMEMR |= mask_high; 
          SLCDC->SLCDC_COM[3].SLCDC_LMEMR |= mask_low; 
          SLCDC->SLCDC_COM[4].SLCDC_LMEMR |= mask_low; 
          SLCDC->SLCDC_COM[3].SLCDC_MMEMR |= mask_high;
          break;
          
          case 7:
          SLCDC->SLCDC_COM[1].SLCDC_LMEMR |= mask_low; 
          SLCDC->SLCDC_COM[2].SLCDC_LMEMR |= mask_low; 
          SLCDC->SLCDC_COM[3].SLCDC_LMEMR |= mask_low;
          break;
          
          case 8:
          SLCDC->SLCDC_COM[2].SLCDC_LMEMR |= mask_low; 
          SLCDC->SLCDC_COM[1].SLCDC_LMEMR |= mask_low; 
          SLCDC->SLCDC_COM[1].SLCDC_MMEMR |= mask_high; 
          SLCDC->SLCDC_COM[2].SLCDC_MMEMR |= mask_high; 
          SLCDC->SLCDC_COM[3].SLCDC_LMEMR |= mask_low; 
          SLCDC->SLCDC_COM[4].SLCDC_LMEMR |= mask_low; 
          SLCDC->SLCDC_COM[3].SLCDC_MMEMR |= mask_high;
          break;
          
          case 9:
          SLCDC->SLCDC_COM[2].SLCDC_LMEMR |= mask_low; 
          SLCDC->SLCDC_COM[1].SLCDC_LMEMR |= mask_low; 
          SLCDC->SLCDC_COM[1].SLCDC_MMEMR |= mask_high; 
          SLCDC->SLCDC_COM[2].SLCDC_MMEMR |= mask_high; 
          SLCDC->SLCDC_COM[3].SLCDC_LMEMR |= mask_low; 
          SLCDC->SLCDC_COM[4].SLCDC_LMEMR |= mask_low;
          break;
          
          default:
          //clear the digit
          break;

      }
    

  }
  else
  {
      CLEAR_DIGIT(mask_low, mask_high);
      switch (value)
      {
          case 0:
          SET_DIGIT0(mask_low, mask_high);
          break;
          
          case 1:
          SET_DIGIT1(mask_low, mask_high);
          break;
          
          case 2:
          SET_DIGIT2(mask_low, mask_high);
          break;
          
          case 3:
          SET_DIGIT3(mask_low, mask_high);
          break;
          
          case 4:
          SET_DIGIT4(mask_low, mask_high);
          break;
          
          case 5:
          SET_DIGIT5(mask_low, mask_high);
          break;
          
          case 6:
          SET_DIGIT6(mask_low, mask_high);
          break;
          
          case 7:
          SET_DIGIT7(mask_low, mask_high);
          break;
          
          case 8:
          SET_DIGIT8(mask_low, mask_high);
          break;
          
          case 9:
          SET_DIGIT9(mask_low, mask_high);
          break;
          
		  //-------------------------------------
		  case	10:
		  SET_DIGIT_A(mask_low, mask_high);		  
		  break;
		  
		  case	11:
		  SET_DIGIT_b(mask_low, mask_high);		  
		  break;
		  
		  case	12:
		  SET_DIGIT_C(mask_low, mask_high);		  
		  break;
		  
		  case	13:
		  SET_DIGIT_d(mask_low, mask_high);		  
		  break;
		  
		  case	14:
		  SET_DIGIT_E(mask_low, mask_high);		  
		  break;
		  
		  case	15:
		  SET_DIGIT_F(mask_low, mask_high);		  
		  break;
		  
		  case	16:
		  SET_DIGIT_U(mask_low, mask_high);		  
		  break;
		  //-------------------------------------
		  
          default:
          //clear
          break;

      }
  }
  
  return 1;
}

void display_logo()
{
  SLCDC->SLCDC_COM[0].SLCDC_LMEMR |= SEGMENT_S17_S21_S28;
}

void clear_logo()
{
  SLCDC->SLCDC_COM[0].SLCDC_LMEMR &= ~SEGMENT_S17_S21_S28;
} 

//Clears all the 6 big digits
void clear_upper_digits()
{
   for(int i = 1; i< 7; i++)
   //set all the upper digits to illegal values to turn them off
      set_upper_digit(i, 99);
}

//Clears all the 6 big digits
void clear_lower_digits()
{
   for(int i = 1; i< 4; i++)
   //set all the upper digits to illegal values to turn them off
      set_lower_digit(i, 99);
}

//Clears the entire LCD
void clear_display()
{
   slcdc_disable(SLCDC);
   //LCD_init();
}

//Sets double dots (col 1..see datasheet)
void set_col1()
{
    SLCDC->SLCDC_COM[4].SLCDC_LMEMR |= COL1;
}
//Sets double dots (col 2..see datasheet)
void set_col2()
{
    SLCDC->SLCDC_COM[4].SLCDC_LMEMR |= COL2;
}
//Sets P2 (P2..see datasheet)
void set_p2()
{
    SLCDC->SLCDC_COM[5].SLCDC_LMEMR |= P2;
}
//Sets P1 (P1..see datasheet)
void set_p1()
{
    SLCDC->SLCDC_COM[4].SLCDC_LMEMR |= P1;
}
//Sets P3 (P3..see datasheet)
void set_p3()
{
    SLCDC->SLCDC_COM[4].SLCDC_LMEMR |= P3;
}


//Sets double dots (col 1..see datasheet)
void clear_col1()
{
   SLCDC->SLCDC_COM[4].SLCDC_LMEMR &= ~COL1;
}
//Sets double dots (col 2..see datasheet)
void clear_col2()
{
   SLCDC->SLCDC_COM[4].SLCDC_LMEMR &= ~COL2;
}
//Sets P2 (P2..see datasheet)
void clear_p2()
{
    SLCDC->SLCDC_COM[5].SLCDC_LMEMR &= ~P2;
}
//Sets P1 (P1..see datasheet)
void clear_p1()
{
    SLCDC->SLCDC_COM[4].SLCDC_LMEMR &= ~P1;
}
//Sets P3 (P3..see datasheet)
void clear_p3()
{
    SLCDC->SLCDC_COM[4].SLCDC_LMEMR &= ~P3;
}

uint32_t display_segment_index(uint32_t index)
{
     switch(index)
     {
        case 1:
        SLCDC->SLCDC_COM[0].SLCDC_MMEMR |= SEGMENT_S1_S13_S14;
        break;
        
        case 2:
        SLCDC->SLCDC_COM[0].SLCDC_LMEMR |= SEGMENT_S2_S15;
        break;
        
        case 3:
        SLCDC->SLCDC_COM[0].SLCDC_LMEMR |= SEGMENT_S3_S16;
        break;
        
        case 4:
        SLCDC->SLCDC_COM[0].SLCDC_LMEMR |= SEGMENT_S4;
        break;
        
        case 5:
        SLCDC->SLCDC_COM[0].SLCDC_LMEMR |= SEGMENT_S5;
        break;
        
        case 6:
        SLCDC->SLCDC_COM[0].SLCDC_LMEMR |= SEGMENT_S6_S23;
        break;
        
        case 7:
        SLCDC->SLCDC_COM[0].SLCDC_LMEMR |= SEGMENT_S7_S24;
        break;
        
        case 8:
        SLCDC->SLCDC_COM[0].SLCDC_LMEMR |= SEGMENT_S8_S27;
        break;
        
        case 9:
        SLCDC->SLCDC_COM[0].SLCDC_LMEMR |= SEGMENT_S9;
        break;
        
        case 10:
        SLCDC->SLCDC_COM[0].SLCDC_LMEMR |= SEGMENT_S10_S31;
        break;
        
        case 11:
        SLCDC->SLCDC_COM[0].SLCDC_LMEMR |= SEGMENT_S11_S32;
        break;
        
        case 12:
        SLCDC->SLCDC_COM[0].SLCDC_LMEMR |= SEGMENT_S12_S33;
        break;
        
        case 13:
        SLCDC->SLCDC_COM[4].SLCDC_MMEMR |= SEGMENT_S1_S13_S14;
        break;
        
        case 14:
        SLCDC->SLCDC_COM[5].SLCDC_MMEMR |= SEGMENT_S1_S13_S14;
        break;
        
        case 15:
        SLCDC->SLCDC_COM[5].SLCDC_LMEMR |= SEGMENT_S2_S15;
        break;
        
        case 16:
        SLCDC->SLCDC_COM[4].SLCDC_LMEMR |= SEGMENT_S3_S16;
        break;
        
        case 17:
        SLCDC->SLCDC_COM[0].SLCDC_LMEMR |= SEGMENT_S17_S21_S28;
        break;
        
        case 18:
        SLCDC->SLCDC_COM[4].SLCDC_LMEMR |= SEGMENT_S18_S25;
        break;
        
        case 19:
        SLCDC->SLCDC_COM[4].SLCDC_LMEMR |= SEGMENT_S19_S26;
        break;
        
        case 20:
        SLCDC->SLCDC_COM[4].SLCDC_LMEMR |= SEGMENT_S20_S29;
        break;
        
        case 21:
        SLCDC->SLCDC_COM[4].SLCDC_LMEMR |= SEGMENT_S17_S21_S28;
        break;
        
        case 22:
        SLCDC->SLCDC_COM[4].SLCDC_LMEMR |= SEGMENT_S22_S30;
        break;
        
        case 23:
        SLCDC->SLCDC_COM[5].SLCDC_LMEMR |= SEGMENT_S6_S23;
        break;
        
        case 24:
        SLCDC->SLCDC_COM[5].SLCDC_LMEMR |= SEGMENT_S7_S24;
        break;
        
        case 25:
        SLCDC->SLCDC_COM[5].SLCDC_LMEMR |= SEGMENT_S18_S25;
        break;
        
        case 26:
        SLCDC->SLCDC_COM[5].SLCDC_LMEMR |= SEGMENT_S19_S26;
        break;
        
        case 27:
        SLCDC->SLCDC_COM[5].SLCDC_LMEMR |= SEGMENT_S8_S27;
        break;
        
        case 28:
        SLCDC->SLCDC_COM[5].SLCDC_LMEMR |= SEGMENT_S17_S21_S28;
        break;
        
        case 29:
        SLCDC->SLCDC_COM[5].SLCDC_LMEMR |= SEGMENT_S20_S29;
        break;
        
        case 30:
        SLCDC->SLCDC_COM[5].SLCDC_LMEMR |= SEGMENT_S22_S30;
        break;
        
        case 31:
        SLCDC->SLCDC_COM[5].SLCDC_LMEMR |= SEGMENT_S10_S31;
        break;
        
        case 32:
        SLCDC->SLCDC_COM[5].SLCDC_LMEMR |= SEGMENT_S11_S32;
        break;
        
        case 33:
        SLCDC->SLCDC_COM[5].SLCDC_LMEMR |= SEGMENT_S12_S33;
        break;
        
        default:
        return 0;
        
    }
    
    return 1;
            
}

uint32_t clear_segment_index(uint32_t index)
{
     switch(index)
     {
        case 1:
        SLCDC->SLCDC_COM[0].SLCDC_MMEMR &= ~SEGMENT_S1_S13_S14;
        break;
        
        case 2:
        SLCDC->SLCDC_COM[0].SLCDC_LMEMR &= ~SEGMENT_S2_S15;
        break;
        
        case 3:
        SLCDC->SLCDC_COM[0].SLCDC_LMEMR &= ~SEGMENT_S3_S16;
        break;
        
        case 4:
        SLCDC->SLCDC_COM[0].SLCDC_LMEMR &= ~SEGMENT_S4;
        break;
        
        case 5:
        SLCDC->SLCDC_COM[0].SLCDC_LMEMR &= ~SEGMENT_S5;
        break;
        
        case 6:
        SLCDC->SLCDC_COM[0].SLCDC_LMEMR &= ~SEGMENT_S6_S23;
        break;
        
        case 7:
        SLCDC->SLCDC_COM[0].SLCDC_LMEMR &= ~SEGMENT_S7_S24;
        break;
        
        case 8:
        SLCDC->SLCDC_COM[0].SLCDC_LMEMR &= ~SEGMENT_S8_S27;
        break;
        
        case 9:
        SLCDC->SLCDC_COM[0].SLCDC_LMEMR &= ~SEGMENT_S9;
        break;
        
        case 10:
        SLCDC->SLCDC_COM[0].SLCDC_LMEMR &= ~SEGMENT_S10_S31;
        break;
        
        case 11:
        SLCDC->SLCDC_COM[0].SLCDC_LMEMR &= ~SEGMENT_S11_S32;
        break;
        
        case 12:
        SLCDC->SLCDC_COM[0].SLCDC_LMEMR &= ~SEGMENT_S12_S33;
        break;
        
        case 13:
        SLCDC->SLCDC_COM[4].SLCDC_MMEMR &= ~SEGMENT_S1_S13_S14;
        break;
        
        case 14:
        SLCDC->SLCDC_COM[5].SLCDC_MMEMR &= ~SEGMENT_S1_S13_S14;
        break;
        
        case 15:
        SLCDC->SLCDC_COM[5].SLCDC_LMEMR &= ~SEGMENT_S2_S15;
        break;
        
        case 16:
        SLCDC->SLCDC_COM[4].SLCDC_LMEMR &= ~SEGMENT_S3_S16;
        break;
        
        case 17:
        SLCDC->SLCDC_COM[0].SLCDC_LMEMR &= ~SEGMENT_S17_S21_S28;
        break;
        
        case 18:
        SLCDC->SLCDC_COM[4].SLCDC_LMEMR &= ~SEGMENT_S18_S25;
        break;
        
        case 19:
        SLCDC->SLCDC_COM[4].SLCDC_LMEMR &= ~SEGMENT_S19_S26;
        break;
        
        case 20:
        SLCDC->SLCDC_COM[4].SLCDC_LMEMR &= ~SEGMENT_S20_S29;
        break;
        
        case 21:
        SLCDC->SLCDC_COM[4].SLCDC_LMEMR &= ~SEGMENT_S17_S21_S28;
        break;
        
        case 22:
        SLCDC->SLCDC_COM[4].SLCDC_LMEMR &= ~SEGMENT_S22_S30;
        break;
        
        case 23:
        SLCDC->SLCDC_COM[5].SLCDC_LMEMR &= ~SEGMENT_S6_S23;
        break;
        
        case 24:
        SLCDC->SLCDC_COM[5].SLCDC_LMEMR &= ~SEGMENT_S7_S24;
        break;
        
        case 25:
        SLCDC->SLCDC_COM[5].SLCDC_LMEMR &= ~SEGMENT_S18_S25;
        break;
        
        case 26:
        SLCDC->SLCDC_COM[5].SLCDC_LMEMR &= ~SEGMENT_S19_S26;
        break;
        
        case 27:
        SLCDC->SLCDC_COM[5].SLCDC_LMEMR &= ~SEGMENT_S8_S27;
        break;
        
        case 28:
        SLCDC->SLCDC_COM[5].SLCDC_LMEMR &= ~SEGMENT_S17_S21_S28;
        break;
        
        case 29:
        SLCDC->SLCDC_COM[5].SLCDC_LMEMR &= ~SEGMENT_S20_S29;
        break;
        
        case 30:
        SLCDC->SLCDC_COM[5].SLCDC_LMEMR &= ~SEGMENT_S22_S30;
        break;
        
        case 31:
        SLCDC->SLCDC_COM[5].SLCDC_LMEMR &= ~SEGMENT_S10_S31;
        break;
        
        case 32:
        SLCDC->SLCDC_COM[5].SLCDC_LMEMR &= ~SEGMENT_S11_S32;
        break;
        
        case 33:
        SLCDC->SLCDC_COM[5].SLCDC_LMEMR &= ~SEGMENT_S12_S33;
        break;
        
        default:
        return 0;
        
    }
    
    return 1;
            
}
*/
//The value can only be between 0 and 15.
void set_LCD_contrast(uint32_t contrast)
{
    //set internal LDO output
    supc_enable_slcd_ldo_output(SUPC ,contrast);
}

void LCD_init(void)
{

        pmc_enable_periph_clk(ID_SLCDC);
        
        unsigned int reg = SUPC->SUPC_MR & SUPC_MR_LCDMODE_Msk;
        if((reg != SUPC_MR_LCDMODE_LCDOFF ) || (reg != SUPC_MR_LCDMODE_EOF_LCDOFF ))
        {
            supc_enable_slcd_voltage(SUPC , SUPC_MR_LCDMODE_LCDOFF);
        }

        //set internal LDO output
        supc_enable_slcd_ldo_output(SUPC ,0x0);

        //power source to internal power
        supc_enable_slcd_voltage(SUPC , SUPC_MR_LCDMODE_LCDON_INVR);
	
         //software reset
        slcdc_software_reset(SLCDC);

        //select COM num
        slcdc_sel_COM_num(SLCDC, LCD_COM_NB);
        
//        slcdc_segment_map0(SLCDC,SLCDC_SMR0_LCD3 |  SLCDC_SMR0_LCD4 | \
//                     SLCDC_SMR0_LCD5 | SLCDC_SMR0_LCD6 |  SLCDC_SMR0_LCD7 |  SLCDC_SMR0_LCD8 |   \
//                     SLCDC_SMR0_LCD9 |  SLCDC_SMR0_LCD10 |  SLCDC_SMR0_LCD12 | \
//                    SLCDC_SMR0_LCD24 |  SLCDC_SMR0_LCD25 |  SLCDC_SMR0_LCD26 | \
//                      SLCDC_SMR0_LCD27 | SLCDC_SMR0_LCD28 | SLCDC_SMR0_LCD29 | \
//                        SLCDC_SMR0_LCD30);//seg 17, 20~22, and 24 ~31 
//        slcdc_segment_map1(SLCDC,SLCDC_SMR1_LCD32);// seg 32 ~ 49 all on
		
		slcdc_segment_map1( SLCDC,SLCDC_SMR1_LCD33 |  SLCDC_SMR1_LCD34 | \
                     SLCDC_SMR1_LCD35 | SLCDC_SMR1_LCD36 |  SLCDC_SMR1_LCD37 |  SLCDC_SMR1_LCD38 |   \
                     SLCDC_SMR1_LCD39 |  SLCDC_SMR1_LCD40 |  SLCDC_SMR1_LCD41 | \
                     SLCDC_SMR1_LCD42 |  SLCDC_SMR1_LCD43 |  SLCDC_SMR1_LCD44 | \
                     SLCDC_SMR1_LCD45 | SLCDC_SMR1_LCD46 | SLCDC_SMR1_LCD47 | \
                     SLCDC_SMR1_LCD48 | SLCDC_SMR1_LCD49 );//seg 33 ~ 49
         //config frame rate
        dev_slcd_config_frame_rate(SLCDC,BOARD_FREQ_SLCK_XTAL,0, 3);

        slcdc_set_buftime(SLCDC, 6);		
        slcdc_config_bias(SLCDC, 2);
        //slcdc_config_interrupt();

        //set slcd blink frequence
        slcdc_set_blink_frq(SLCDC,32);
        slcdc_set_display_mode(SLCDC, 0x0);
         //Enable slcdc
        slcdc_enable(SLCDC);
        while(!slcdc_get_status(SLCDC))
                ;
}
//===================================================================
//decription    ::  set slcd ram
//function      ::  set_slcd_ram
//input         ::  pattern
//output        ::  none
//call          ::  none
//effect        ::  SLCDC
//===================================================================
void    set_slcd_ram(uint32_t pattern)
{
    uint32_t i;    
    for (i=0; i < 6 ; i++) 
	{
        slcdc_write_lsb_memory(SLCDC, i , pattern);
        slcdc_write_msb_memory(SLCDC, i , pattern);
    }
}
//===================================================================
//decription    ::  clear slcd ram
//function      ::  clear_slcd_ram
//input         ::  none
//output        ::  none
//call          ::  none
//effect        ::  SLCDC
//===================================================================
void    clear_slcd_ram(void)
{
    uint32_t i;
    
    for (i=0; i < 6 ; i++) 
	{
        slcdc_clear_lsb_memory(SLCDC, i , 0xffffffff);
        slcdc_clear_msb_memory(SLCDC, i , 0xffffffff);
    }
}


