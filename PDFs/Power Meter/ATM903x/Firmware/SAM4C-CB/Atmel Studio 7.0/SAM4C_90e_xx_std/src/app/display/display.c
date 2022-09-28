//===================================================================
#include "target.h"
//-------------------------------------------------------------------
DISPLAY_Str    VDisplay;
//-------------------------------------------------------------------

/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
extern "C" {
#endif
/**INDENT-ON**/
/// @endcond

enum 
{
	Wh_UNIT = 0,
	W_UNIT,
	kWh_UNIT,
	kW_UNIT,
    VArh_UNIT,
	VAr_UNIT,
	kVArh_UNIT,
	kVAr_UNIT,
    VAh_UNIT,
	VA_UNIT,
    kVAh_UNIT,
	kVA_UNIT,
	V_UNIT,
	I_UNIT
};
//------------------------------------------------------------------------
const	uint8_t	DecodeDspTable[22]=
	{Dsp_0,Dsp_1,Dsp_2,Dsp_3,Dsp_4,Dsp_5,Dsp_6,Dsp_7,Dsp_8,Dsp_9,Dsp_A,Dsp_B,Dsp_C,Dsp_D,Dsp_E,Dsp_F,Dsp_U,Dsp_r,Dsp_bC,Dsp_L,Dsp_P,Dsp_t};

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
	for(i=0;i<8;i=i+2)
	{
		if( *(text +i)==0 )
			break;
		DisplayPixel( text+i, 1 );
	}
}
//===================================================================
//decription    ::  LCD display initialize
//function      ::  LCD_Disp_init
//input         ::  none
//output        ::  none
//call          ::  none
//effect        ::  none
//===================================================================
void	LCD_Disp_init(void)
{
	pmc_enable_periph_clk(ID_SLCDC);
	
    unsigned int reg = SUPC->SUPC_MR & SUPC_MR_LCDMODE_Msk;
    if( reg != SUPC_MR_LCDMODE_LCDOFF )
    {
        supc_set_slcd_power_mode( SUPC, SUPC_MR_LCDMODE_LCDOFF );
    }

    //set internal LDO output
    supc_set_slcd_vol(SUPC,CONF_SLCDC_VOLT_2_64V);	//2.64v

    //power source to internal power
    supc_set_slcd_power_mode(SUPC , SUPC_MR_LCDMODE_LCDON_INVR);
    //software reset
    slcdc_reset(SLCDC);

    //select COM num
	reg = SLCDC->SLCDC_MR;
	reg &=( ~ SLCDC_MR_COMSEL_Msk );
	reg |= ( ( CONF_SLCDC_COM_NUM - 1 ) << SLCDC_MR_COMSEL_Pos );	//6 COM
	SLCDC->SLCDC_MR = reg;
	//select SEG num
	reg = SLCDC->SLCDC_MR;
	reg &=( ~ SLCDC_MR_SEGSEL_Pos );
	reg |= ( SLCDC_MR_SEGSEL( CONF_SLCDC_SEG_NUM - 1 ) << SLCDC_MR_SEGSEL_Pos );	//18 SEG
	SLCDC->SLCDC_MR = reg;
	//---configure segment1--------------------------------
	slcdc_set_segmap1( SLCDC,SLCDC_SMR1_LCD33 |  SLCDC_SMR1_LCD34 | \
                 SLCDC_SMR1_LCD35 | SLCDC_SMR1_LCD36 |  SLCDC_SMR1_LCD37 |  SLCDC_SMR1_LCD38 |   \
                 SLCDC_SMR1_LCD39 |  SLCDC_SMR1_LCD40 |  SLCDC_SMR1_LCD41 | \
                 SLCDC_SMR1_LCD42 |  SLCDC_SMR1_LCD43 |  SLCDC_SMR1_LCD44 | \
                 SLCDC_SMR1_LCD45 | SLCDC_SMR1_LCD46 | SLCDC_SMR1_LCD47 | \
                 SLCDC_SMR1_LCD48 | SLCDC_SMR1_LCD49 );//seg 33 ~ 49
    //---config frame rate 64Hz----------------------------
    slcdc_set_frame_rate(SLCDC,CONF_SLCDC_FRAME_FREQ);
	//---config buff timer 64 sclk period------------------
    slcdc_set_buf_time( SLCDC, CONF_SLCDC_BUFTM_128X );		//buffer on time =slck/1024	
    //---config bias is 1/3--------------------------------
	SLCDC->SLCDC_MR &= ( ~SLCDC_MR_BIAS_Msk );
	SLCDC->SLCDC_MR |= ( CONF_SLCDC_BIAS << SLCDC_MR_BIAS_Pos );	//bias =1/3

    //set slcd blink frequence
	slcdc_set_blink_freq( SLCDC, 32, 1 );
	//---configure lcd mode is NORMAL ---------------------
    slcdc_set_display_mode( SLCDC, SLCDC_DISPMODE_NORMAL );
    //---Enable slcdc--------------------------------------
    slcdc_enable(SLCDC);
	//---wait for SLCD is ready----------------------------
    while(!slcdc_get_status(SLCDC));

	slcdc_set_display_memory( SLCDC );	
}
//===================================================================
//decription    ::  updata display number process
//function      ::  RefreshDisplayNumberProcess
//input         ::  none
//output        ::  none
//call          ::  PutTaskIntoQue
//effect        ::  VDisplay.Number
//===================================================================
void	RefreshDisplayNumberProcess(void)
{
    uint8_t i;
	if( VDisplay.Number ==DISPLAY_ALL )
	{
		VDisplay.Number =DISPLAY_VERSION;
		//VDisplay.OnOffFlag0 =0x00000013;
        //VDisplay.OnOffFlag1 =0xC2;
		
		VDisplay.LpTimer =2;//VDisplay.GapTimer//display 2s=4*500ms
	}
	else
	{	
		if( VDisplay.Number ==DISPLAY_VERSION )
		{
			VDisplay.Number =DISPLAY_AFE_TYPE;
		}
		else
		{
			if( (VAFE.id==AT90E25) || (VAFE.id==AT90E24) || (VAFE.id==AT90E23) )
			{
				VDisplay.OnOffFlag0 &=0x01221113;
				VDisplay.OnOffFlag1 &=0xC2;
			}
			else
			{
				VDisplay.OnOffFlag1 &=0xC3;
			}
			
			if(VDisplay.Direct&BACKWARD)
			{
				if((VDisplay.Direct&FORWARD)==0)
				{
					for(i=0;i<(DisplayNumber_Max);i++)
					{
						if( --VDisplay.Number >=DisplayNumber_Max )
						{
							VDisplay.Number =DisplayNumber_Max-1;
						}
						if( (VDisplay.Number <32)&&((VDisplay.OnOffFlag0 &(0x1u<<VDisplay.Number))!=0) )
						{
							break;
						}
						if( (VDisplay.Number >31)&&((VDisplay.OnOffFlag1 &(0x1u<<(VDisplay.Number-32)))!=0) )
						{
							break;
						}             
					}			
				}//it is not display down key
			}//it is display up key
			else
			{
				for(i=0;i<(DisplayNumber_Max);i++)
				{
					VDisplay.Number++;
					if( VDisplay.Number >=DisplayNumber_Max )
					{
						VDisplay.Number=0;
					}  
					if( (VDisplay.Number <32)&&((VDisplay.OnOffFlag0 &(0x1u<<VDisplay.Number))!=0) )
					{
						break;
					}
					if( (VDisplay.Number >31)&&((VDisplay.OnOffFlag1 &(0x1u<<(VDisplay.Number-32)))!=0) )
					{
						break;
					}              
				}				
			}//it is not display up key 
		}
		VDisplay.LpTimer =10;//VDisplay.GapTimer//display 5s=10*500ms
	}	
	VDisplay.Direct=0;	
	PutTaskIntoQue( RefreshDisplay );
}
//===================================================================
//decription    ::  updata display process
//function      ::  RefreshDisplayProcess
//input         ::  none
//output        ::  none
//call          ::  none
//effect        ::  VDisplay.Buff
//===================================================================
void    RefreshDisplayProcess(void)
{
    uint32_t	i,j;
	uint8_t		buff[6];
	uint16_t	displaynum_offset;
	//clear_slcd_ram();
	slcdc_clear_display_memory( SLCDC );
	//-----------------------------------------------------
	for(i=0;i<6;i++)
	{
		buff[i]=0;
	}
	switch( VAFE.runmode )
	{
		case	Idle_Mode:
		{
			buff[0] =14;		//"E"
			buff[1] =Con_L;//Con_L;
			buff[2] =13;	//"D"
			buff[3] =Con_I;	//"i"
			displaynum_offset =0x400;
		}
		break;
		case	Detect_Mode:
		{
			buff[0] =Con_T;	//"t"
			buff[1] =Con_C;	//"C"
			buff[2] =14;	//"E"	
			buff[3] =Con_T;	//"t"
			buff[4] =14;	//"E"
			buff[5] =13;	//"D"
			displaynum_offset =0x600;
		}
		break;
		case	Patial_Mode:
		{
			buff[0] =Con_T;	//"t"		
			buff[1] =Con_r;	//"r"	
			buff[2] =10;	//"A"
			buff[3] =Con_P;	//"P"
			displaynum_offset =0x400;
		}
		break;
		default:
		{	
			switch(VDisplay.Number)
			{
				case	DISPLAY_AFE_TYPE:
				{
					switch( VAFE.id )
					{
						case	AT90E23:
						case	AT90E25:
						{					
							buff[1]=6;		//6
							buff[2]=2;		//2
							displaynum_offset =0x500; //display 5 digits					
						}
						break;
                        case	AT90E24:
						{					
							buff[1]=4;		//4
							buff[2]=2;		//2
							displaynum_offset =0x500; //display 5 digits					
						}
						break;                        
						case	AT90E32:
						{					
							buff[1]=2;		//2
							buff[2]=3;		//3
							displaynum_offset =0x500; //display 5 digits
						}
						break;
						case	AT90E32A:
						{					
							buff[0]=10;		//A
							buff[1]=2;		//2
							buff[2]=3;		//3
							displaynum_offset =0x600; //display 6 digits
						}
						break;
						case	AT90E32AS:
						{					
							buff[0]=10;		//b--AS
							buff[1]=2;		//2
							buff[2]=3;		//3
							displaynum_offset =0x600; //display 6 digits
						}
						break;
						case	AT90E36:
						{					
							buff[1]=6;		//6
							buff[2]=3;		//3
							displaynum_offset =0x500; //display 5 digits
						}
						break;
						case	AT90E36A:
						{	
							buff[0]=10;		//A
							buff[1]=6;		//6
							buff[2]=3;		//3
							displaynum_offset =0x600; //display 6 digits
						}
						break;
						default :
						{					
							buff[1]=Con_r;		//r
							buff[2]=Con_r;		//r
							displaynum_offset =0x500; //display 5 digits
						}
						break;
					}
					buff[3]=14;		//E	
					buff[4]=0;		//0
					buff[5]=9;		//9
					for(i=0;i<(6-(displaynum_offset>>8));i++)
					{
						for(j=0;j<5;j++)
						{
							buff[j]=buff[j+1];
						}
					}		
					displaynum_offset &=0xFF00;//from the first digit start
				}//end case AFE_TYPE
				break;
				
				case	DISPLAY_VA_RMS:
				{
					displaynum_offset = display_volt( &buff[0],((uint8_t *)(&VAFE.RMS[Ua]))+1 );			
					DisplayPixel("A",1);  // 'A'
				}//end case va_rms
				break;
				case	DISPLAY_VB_RMS:
				{
					displaynum_offset =display_volt( &buff[0],((uint8_t *)&VAFE.RMS[Ub])+1 );
					DisplayPixel("B",1);  // 'B'			
				}//end case vb_rms
				break;
				case	DISPLAY_VC_RMS:
				{
					displaynum_offset =display_volt( &buff[0],((uint8_t *)&VAFE.RMS[Uc])+1 );
					DisplayPixel("C",1);  // 'C'
				}//end case vc_rms
				break;
				case	DISPLAY_IA_RMS:
				{
					displaynum_offset =display_current( &buff[0],((uint8_t *)&VAFE.RMS[Ia])+1 );
					DisplayPixel("A",1);  // 'A'
				}//end case ia_rms
				break;
				case	DISPLAY_IB_RMS:
				{
					displaynum_offset =display_current( &buff[0],((uint8_t *)&VAFE.RMS[Ib])+1 );
					DisplayPixel("B",1);  // 'B'
				}//end case ib_rms
				break;
				case	DISPLAY_IC_RMS:
				{
					displaynum_offset =display_current( &buff[0],((uint8_t *)&VAFE.RMS[Ic])+1 );
					DisplayPixel("C",1);  // 'C'
				}//end case ic_rms
				break;		
				case	DISPLAY_Ptotal_RMS:
				{
					displaynum_offset =display_p_power( &buff[0],((uint8_t *)&VAFE.RMS[Pt])+1 );			
				}//end case active power total
				break;
				case	DISPLAY_PA_RMS:
				{
					displaynum_offset =display_p_power( &buff[0],((uint8_t *)&VAFE.RMS[Pa])+1 );	
					DisplayPixel("A",1);	//"A"
				}//end case active power a
				break;
				case	DISPLAY_PB_RMS:
				{
					displaynum_offset =display_p_power( &buff[0],((uint8_t *)&VAFE.RMS[Pb])+1 );	
					DisplayPixel("B",1);	//"B"
				}//end case active power b
				break;
				case	DISPLAY_PC_RMS:
				{
					displaynum_offset =display_p_power( &buff[0],((uint8_t *)&VAFE.RMS[Pc])+1 );	
					DisplayPixel("C",1);	//"C"
				}//end case active power c
				break;
				case	DISPLAY_Qtotal_RMS:
				{
					displaynum_offset =display_q_power( &buff[0],((uint8_t *)&VAFE.RMS[Qt])+1 );			
				}//end case reactive power total
				break;
				case	DISPLAY_QA_RMS:
				{
					displaynum_offset =display_q_power( &buff[0],((uint8_t *)&VAFE.RMS[Qa])+1 );	
					DisplayPixel("A",1);	//"A"
				}//end case reactive power a
				break;
				case	DISPLAY_QB_RMS:
				{
					displaynum_offset =display_q_power( &buff[0],((uint8_t *)&VAFE.RMS[Qb])+1 );	
					DisplayPixel("B",1);	//"B"
				}//end case reactive power b
				break;
				case	DISPLAY_QC_RMS:
				{
					displaynum_offset =display_q_power( &buff[0],((uint8_t *)&VAFE.RMS[Qc])+1 );	
					DisplayPixel("C",1);	//"C"
				}//end case reactive power c
				break;
				case	DISPLAY_SAtotal_RMS:
				{
					displaynum_offset =display_s_power( &buff[0],((uint8_t *)&VAFE.RMS[SAt])+1 );			
				}//end case apparent power abslute total
				break;
				case	DISPLAY_SVtotal_RMS:
				{
					displaynum_offset =display_s_power( &buff[0],((uint8_t *)&VAFE.RMS[SVt])+1 );			
				}//end case apparent power algebra total
				break;		
				case	DISPLAY_SA_RMS:
				{
					displaynum_offset =display_s_power( &buff[0],((uint8_t *)&VAFE.RMS[Sa])+1 );	
					DisplayPixel("A",1);	//"A"
				}//end case apparent power a
				break;
				case	DISPLAY_SB_RMS:
				{
					displaynum_offset =display_s_power( &buff[0],((uint8_t *)&VAFE.RMS[Sb])+1 );	
					DisplayPixel("B",1);	//"B"
				}//end case apparent power b
				break;
				case	DISPLAY_SC_RMS:
				{
					displaynum_offset =display_s_power( &buff[0],((uint8_t *)&VAFE.RMS[Sc])+1 );	
					DisplayPixel("C",1);	//"C"
				}//end case apparent power c
				break;
				case	DISPLAY_PFtotal_RMS:
				{
					displaynum_offset =display_pf( &buff[0],(uint8_t *)&VAFE.RMS[PFt] );			
				}//end case power fact total
				break;
				case	DISPLAY_PFA_RMS:
				{
					displaynum_offset =display_pf( &buff[0],(uint8_t *)&VAFE.RMS[PFa] );
					DisplayPixel("A",1);	//"A"
				}//end case power fact a
				break;
				case	DISPLAY_PFB_RMS:
				{
					displaynum_offset =display_pf( &buff[0],(uint8_t *)&VAFE.RMS[PFb] );
					DisplayPixel("B",1);	//"B"
				}//end case power fact b
				break;
				case	DISPLAY_PFC_RMS:
				{
					displaynum_offset =display_pf( &buff[0],(uint8_t *)&VAFE.RMS[PFc] );
					DisplayPixel("C",1);	//"C"
				}//end case power fact c
				break;
				case	DISPLAY_FREQ_RMS:
				{			
					buff[0]=(uint8_t)( VAFE.RMS[Frq]&0x0F) ;
					buff[1]=(uint8_t)( (VAFE.RMS[Frq]>>4)&0x0F) ;
					buff[2]=(uint8_t)( (VAFE.RMS[Frq]>>8)&0x0F) ;
					buff[3]=(uint8_t)( (VAFE.RMS[Frq]>>12)&0x0F) ;
								
					DisplayPixel("p2",1);  // 'p2'
//					dsoffset=0;//from the first digit start
//					displaynum=4;//display 4 digits
					displaynum_offset =0x400;
				}//end case frequency
				break;
				case	DISPLAY_CNFStart_RMS:
				{			
					buff[0]=(uint8_t)( VAFE.RMS[CNFStart]&0x0F) ;
					buff[1]=(uint8_t)( (VAFE.RMS[CNFStart]>>4)&0x0F) ;
					buff[2]=(uint8_t)( (VAFE.RMS[CNFStart]>>8)&0x0F) ;
					buff[3]=(uint8_t)( (VAFE.RMS[CNFStart]>>12)&0x0F) ;			
		
//					dsoffset=0;//from the first digit start
//					displaynum=4;//display 4 digits
					displaynum_offset =0x400;		
				}//end case configure start
				break;
				case	DISPLAY_CALStart_RMS:
				{			
					buff[0]=(uint8_t)( VAFE.RMS[CALStart]&0x0F) ;
					buff[1]=(uint8_t)( (VAFE.RMS[CALStart]>>4)&0x0F) ;
					buff[2]=(uint8_t)( (VAFE.RMS[CALStart]>>8)&0x0F) ;
					buff[3]=(uint8_t)( (VAFE.RMS[CALStart]>>12)&0x0F) ;			
		
//					dsoffset=0;//from the first digit start
//					displaynum=4;//display 4 digits
					displaynum_offset =0x400;		
				}//end case calculate start
				break;
				case	DISPLAY_HMStart_RMS:
				{			
					buff[0]=(uint8_t)( VAFE.RMS[HMStart]&0x0F) ;
					buff[1]=(uint8_t)( (VAFE.RMS[HMStart]>>4)&0x0F) ;
					buff[2]=(uint8_t)( (VAFE.RMS[HMStart]>>8)&0x0F) ;
					buff[3]=(uint8_t)( (VAFE.RMS[HMStart]>>12)&0x0F) ;			
		
//					dsoffset=0;//from the first digit start
//					displaynum=4;//display 4 digits
					displaynum_offset =0x400;		
				}//end case harm start
				break;
				case	DISPLAY_ADJStart_RMS:
				{			
					buff[0]=(uint8_t)( VAFE.RMS[ADJStart]&0x0F) ;
					buff[1]=(uint8_t)( (VAFE.RMS[ADJStart]>>4)&0x0F) ;
					buff[2]=(uint8_t)( (VAFE.RMS[ADJStart]>>8)&0x0F) ;
					buff[3]=(uint8_t)( (VAFE.RMS[ADJStart]>>12)&0x0F) ;			
		
//					dsoffset=0;//from the first digit start
//					displaynum=4;//display 4 digits
					displaynum_offset =0x400;		
				}//end case adjust start
				break;
				case	DISPLAY_SYSStatus0_RMS:
				{			
					buff[0]=(uint8_t)( VAFE.RMS[SYSStatus0]&0x0F) ;
					buff[1]=(uint8_t)( (VAFE.RMS[SYSStatus0]>>4)&0x0F) ;
					buff[2]=(uint8_t)( (VAFE.RMS[SYSStatus0]>>8)&0x0F) ;
					buff[3]=(uint8_t)( (VAFE.RMS[SYSStatus0]>>12)&0x0F) ;			
		
//					dsoffset=0;//from the first digit start
//					displaynum=4;//display 4 digits
					displaynum_offset =0x400;			
				}//end case system status 0
				break;
				case	DISPLAY_SYSStatus1_RMS:
				{			
					buff[0]=(uint8_t)( VAFE.RMS[SYSStatus1]&0x0F) ;
					buff[1]=(uint8_t)( (VAFE.RMS[SYSStatus1]>>4)&0x0F) ;
					buff[2]=(uint8_t)( (VAFE.RMS[SYSStatus1]>>8)&0x0F) ;
					buff[3]=(uint8_t)( (VAFE.RMS[SYSStatus1]>>12)&0x0F) ;			
		
//					dsoffset=0;//from the first digit start
//					displaynum=4;//display 4 digits
					displaynum_offset =0x400;		
				}//end case system status 1
				break;
				case	DISPLAY_FUNCEN0_RMS:
				{			
					buff[0]=(uint8_t)( VAFE.RMS[FUNCEn0]&0x0F) ;
					buff[1]=(uint8_t)( (VAFE.RMS[FUNCEn0]>>4)&0x0F) ;
					buff[2]=(uint8_t)( (VAFE.RMS[FUNCEn0]>>8)&0x0F) ;
					buff[3]=(uint8_t)( (VAFE.RMS[FUNCEn0]>>12)&0x0F) ;			
		
//					dsoffset=0;//from the first digit start
//					displaynum=4;//display 4 digits
					displaynum_offset =0x400;		
				}//end case function enable 0
				break;
				case	DISPLAY_FUNCEN1_RMS:
				{			
					buff[0]=(uint8_t)( VAFE.RMS[FUNCEn1]&0x0F) ;
					buff[1]=(uint8_t)( (VAFE.RMS[FUNCEn1]>>4)&0x0F) ;
					buff[2]=(uint8_t)( (VAFE.RMS[FUNCEn1]>>8)&0x0F) ;
					buff[3]=(uint8_t)( (VAFE.RMS[FUNCEn1]>>12)&0x0F) ;			
		
//					dsoffset=0;//from the first digit start
//					displaynum=4;//display 4 digits
					displaynum_offset =0x400;		
				}//end case function enable 1
				break;
						
				case	DISPLAY_TOTAL_ENERGY:
				{			
					buff[0]=(uint8_t)(VEnergy.total.integer&0x0F);//l6;
					buff[1]=(uint8_t)((VEnergy.total.integer>>4)&0x0F);//5;
					buff[2]=(uint8_t)((VEnergy.total.integer>>8)&0x0F);//4;
					buff[3]=(uint8_t)((VEnergy.total.integer>>12)&0x0F);//3;
					buff[4]=(uint8_t)((VEnergy.total.integer>>16)&0x0F);//2;
					buff[5]=(uint8_t)((VEnergy.total.integer>>20)&0x0F);//1;
					
					DisplayPixel("p2",1);  // 'p2'				
					display_units(kWh_UNIT);
					
//					dsoffset=0;//from the first digit start
//					displaynum=6;//display 6 digits
					displaynum_offset =0x600;
					if(buff[5]==0)
					{
						displaynum_offset =displaynum_offset -0x100;
						if(buff[4]==0)
						{
							displaynum_offset =displaynum_offset -0x100;
							if(buff[3]==0)
							{
								displaynum_offset =displaynum_offset -0x100;
							}
						}
					}
					
				}//end case total_energy
				break;
				case	DISPLAY_TOU1_ENERGY:
				{
					buff[0]=0;
					buff[1]=0;
					buff[2]=0;
					buff[3]=0;
					buff[4]=0;
					buff[5]=0;
					
					DisplayPixel("p2",1);  // 'p2'				
					display_units(kWh_UNIT);
					
//					dsoffset=0;//from the first digit start
//					displaynum=6;//display 6 digits
					displaynum_offset =0x600;
				}//end case tou1_energy
				break;
				case	DISPLAY_TOU2_ENERGY:
				{
					buff[0]=0;
					buff[1]=0;
					buff[2]=0;
					buff[3]=0;
					buff[4]=0;
					buff[5]=0;
					
					DisplayPixel("p2",1);  // 'p2'			
					display_units(kWh_UNIT);
					
//					dsoffset=0;//from the first digit start
//					displaynum=6;//display 6 digits
					displaynum_offset =0x600;
				}//end case tou2_energy
				break;
				case	DISPLAY_TOU3_ENERGY:
				{
					buff[0]=(uint8_t)(VEnergy.tou3.integer&0x0F);//l6;
					buff[1]=(uint8_t)((VEnergy.tou3.integer>>4)&0x0F);//5;
					buff[2]=(uint8_t)((VEnergy.tou3.integer>>8)&0x0F);//4;
					buff[3]=(uint8_t)((VEnergy.tou3.integer>>12)&0x0F);//3;
					buff[4]=(uint8_t)((VEnergy.tou3.integer>>16)&0x0F);//2;
					buff[5]=(uint8_t)((VEnergy.tou3.integer>>20)&0x0F);//1;
					
					DisplayPixel("p2",1);  // 'p2'			
					display_units(kWh_UNIT);
					
//					dsoffset=0;//from the first digit start
//					displaynum=6;//display 6 digits
					displaynum_offset =0x600;
				}//end case tou3_energy
				break;
				case	DISPLAY_TOU4_ENERGY:
				{
					buff[0]=0;
					buff[1]=0;
					buff[2]=0;
					buff[3]=0;
					buff[4]=0;
					buff[5]=0;
					
					DisplayPixel("p2",1);  // 'p2'				
					display_units(kWh_UNIT);
					
//					dsoffset=0;//from the first digit start
//					displaynum=6;//display 6 digits
					displaynum_offset =0x600;
				}//end case tou4_energy
				break;
				
				case	DISPLAY_RTC_TIME:
				{
					buff[0]=(uint8_t)( RTC->RTC_TIMR&0x0F);//%10 );//VRTC.second&0x0F;
					buff[1]=(uint8_t)( ((RTC->RTC_TIMR>>4)&0x07));///10 );//(VRTC.second>>4)&0x0F;
					buff[2]=(uint8_t)( ((RTC->RTC_TIMR >>8)&0x0F));//%10 );//VRTC.minute&0x0F;
					buff[3]=(uint8_t)( ((RTC->RTC_TIMR >>12)&0x07));///10 );//(VRTC.minute>>4)&0x0F;
					buff[4]=(uint8_t)( ((RTC->RTC_TIMR >>16)&0x0F));//%10 );//(VRTC.hour)&0x0F;
					buff[5]=(uint8_t)( ((RTC->RTC_TIMR >>20)&0x03));///10 );//(VRTC.hour>>4)&0x0F;
					
					DisplayPixel(":1",1);
					DisplayPixel(":2",1);			
					
//					dsoffset=0;//from the first digit start
//					displaynum=6;//display 6 digits
					displaynum_offset =0x600;
				}//end case rtc_time
				break;
				case	DISPLAY_RTC_DATE:
				{
					buff[0]=(uint8_t)( ((RTC->RTC_CALR>>24)&0x0F));// %10 );//VRTC.day&0x0F;
					buff[1]=(uint8_t)( ((RTC->RTC_CALR>>28)&0x03));// /10 );//(VRTC.day>>4)&0x0F;
					buff[2]=(uint8_t)( ((RTC->RTC_CALR>>16)&0x0F));// %10 );//(VRTC.month)&0x0F;
					buff[3]=(uint8_t)( ((RTC->RTC_CALR>>20)&0x01));// /10 );//(VRTC.month>>4)&0x0F;
					buff[4]=(uint8_t)( ((RTC->RTC_CALR>>8)&0x0F));// %10 );//(VRTC.year)&0x0F;
					buff[5]=(uint8_t)( (((RTC->RTC_CALR>>12)&0x0F)));//%100) /10 );//(VRTC.year>>4)&0x0F;
					
//					dsoffset=0;//from the first digit start
//					displaynum=6;//display 6 digits
					displaynum_offset =0x600;			
				}//end case rtc_date
				break;
				case	DISPLAY_VERSION:
				{
					buff[0] =(uint8_t)((SoftwareVersion)&0x0F);
					buff[1] =(uint8_t)((SoftwareVersion>>4)&0x0F);
					buff[2] =(uint8_t)((SoftwareVersion>>8)&0x0F);
					buff[3] =16;	//"U"
					
//					dsoffset=0;//from the first digit start
//					displaynum=4;//display 4 digits
					displaynum_offset =0x400;
					
					DisplayPixel("p2",1);			
				}//end case DISPLAY_VERSION
				break;
				case	DISPLAY_ALL:
				{			
					slcdc_set_display_memory( SLCDC );
					displaynum_offset =0x0000;
				}//end case DISPLAY_ALL
				break;
				
				default :
				break;
			}//displaynum,dsoffset
		}//afe is other mode
		break;
	}//end switch(afe_run_mode)
	//-----------------------------------------------------
	display_n_digits_k_posit( displaynum_offset,&buff[0]);

	if( VDisplay.Number ==DISPLAY_AFE_TYPE && VAFE.id==AT90E32AS )
	{
		DisplaySingleDigit( 6, 5);	//"S"
	}
	else
	{	
		DisplaySingleDigit( 6, (VDisplay.Number%1000)/100);
		DisplaySingleDigit( 8, VDisplay.Number%10);
		DisplaySingleDigit( 7, (VDisplay.Number%100)/10);
	}    	
	DisplayText("Atmel®");
	if(VCom.lamptimer)
	{
		DisplayPixel("Ψ",1);
	}
	if( VAFE.id!=0 )
	{
		DisplayText("contcum-");  // 'ContCum'
		if( (VAFE.sagstatus.BIT.UaSag) )
		{
			DisplayPixel("¤A",1);
		}
		if( (VAFE.id!=AT90E25) && (VAFE.id!=AT90E24) && (VAFE.id!=AT90E23) )
		{
			if( (VAFE.sagstatus.BIT.UbSag) )
			{
				DisplayPixel("¤B",1);
			}
			if( (VAFE.sagstatus.BIT.UcSag) )
			{
				DisplayPixel("¤C",1);
			}
		}
		if( (VAFE.sagstatus.BIT.PTDir) )
		{
			DisplayPixel("˂",1);
			DisplayPixel("─",1);
			DisplayPixel("Ξ",1);
			if( (VAFE.sagstatus.BIT.QTDir) )
			{			
				DisplayPixel("˅",1);
			}
			else
			{
				DisplayPixel("˄",1);
			}
		}
		else
		{
			DisplayPixel("˃",1);
			DisplayPixel("=",1);
			DisplayPixel("Ξ",1);
			if( (VAFE.sagstatus.BIT.QTDir) )
			{			
				DisplayPixel("˅",1);
			}
			else
			{
				DisplayPixel("˄",1);
			}
		}
	}
	//-----------------------------------------------------	
}
//===================================================================
//decription    ::  copy byte data to display buffer
//function      ::  copybytedatatodispbuff
//input         ::  *mptr,*sptr,len
//output        ::  none
//call          ::  none
//effect        ::  none
//===================================================================
void	copybytedatatodispbuff( uint8_t *mptr,uint8_t *sptr,uint8_t len)
{
	uint8_t	i;
	for(i=0;i<len;i++)
	{
		*(mptr+(i<<1)) =(*(sptr+i))&0x0F;
		*(mptr+(i<<1)+1)=(*(sptr+i)>>4)&0x0F;
	}
}
//===================================================================
//decription    ::  display voltage			xxx.xx V
//function      ::  display_volt
//input         ::  *mptr,*sptr
//output        ::  none
//call          ::  copybytedatatodispbuff
//effect        ::  none
//===================================================================
uint16_t	display_volt( uint8_t *mptr,uint8_t *sptr )
{
	uint16_t	i=0x500;
	copybytedatatodispbuff( mptr,sptr,3 );
	if(*(mptr+4)==0)
	{
		i=i-0x100;
		if(*(mptr+3)==0)
		{
			i=i-0x100;
		}
	}
	DisplayPixel("p2",1);  // 'p2'
	display_units(V_UNIT);

    return( i );
}
//===================================================================
//decription    ::  display current		xxxx.xxx A
//function      ::  display_current
//input         ::  *mptr,*sptr
//output        ::  none
//call          ::  copybytedatatodispbuff
//effect        ::  none
//===================================================================
uint16_t	display_current( uint8_t *mptr,uint8_t *sptr )
{
	uint16_t	i=0x600;
	copybytedatatodispbuff( mptr,sptr,3 );
	if(*(mptr+5)==0)
	{
		i=i-0x100;
		if(*(mptr+4)==0)
		{
			i=i-0x100;
		}
	}	
	DisplayPixel("p1",1);  // 'p1'
	display_units(I_UNIT);			

    return(i);
}
//===================================================================
//decription    ::  display power		xxxxxx.x w/va
//function      ::  display_power
//input         ::  *mptr,*sptr
//output        ::  digigit num
//call          ::  copybytedatatodispbuff
//effect        ::  none
//===================================================================
uint16_t	display_power( uint8_t *mptr,uint8_t *sptr )
{
	uint16_t	i=0x600;		
	copybytedatatodispbuff( mptr,sptr,3 );
	if(*(mptr+5)==0)
	{
		i=i-0x100;
		if(*(mptr+4)==0)
		{
			i=i-0x100;
			if(*(mptr+3)==0)
			{
				i=i-0x100;
				if(*(mptr+2)==0)
				{
					i=i-0x100;
				}
			}
		}
	}	
	DisplayPixel("p3",1);  // 'p3'
	return(i);
}
//===================================================================
//decription    ::  display active power
//function      ::  display_p_power
//input         ::  *mptr,*sptr
//output        ::  none
//call          ::  display_power
//effect        ::  none
//===================================================================
uint16_t	display_p_power( uint8_t *mptr,uint8_t *sptr )
{
	uint16_t	i;
	i=display_power( mptr,sptr);	
	//display_units(kW_UNIT);
	display_units(W_UNIT);
	
//	dsoffset=0;//from the first digit start
//	displaynum=5;//display 5 digits
    return(i);	
}
//===================================================================
//decription    ::  display reactive power
//function      ::  display_q_power
//input         ::  *mptr,*sptr
//output        ::  none
//call          ::  display_power
//effect        ::  none
//===================================================================
uint16_t	display_q_power( uint8_t *mptr,uint8_t *sptr )
{
	uint16_t	i;
	i=display_power( mptr,sptr);	
	//display_units(kVAr_UNIT);
	display_units(VAr_UNIT);
//	dsoffset=0;//from the first digit start
//	displaynum=5;//display 5 digits
    return(i);
}
//===================================================================
//decription    ::  display apparent power
//function      ::  display_s_power
//input         ::  *mptr,*sptr
//output        ::  none
//call          ::  display_power
//effect        ::  none
//===================================================================
uint16_t	display_s_power( uint8_t *mptr,uint8_t *sptr )
{
	uint16_t	i;
	i=display_power( mptr,sptr);	
	//display_units(kVA_UNIT);
	display_units(VA_UNIT);
	
//	dsoffset=0;//from the first digit start
//	displaynum=5;//display 5 digits
    return(i);
}
//===================================================================
//decription    ::  display power fact
//function      ::  display_pf
//input         ::  *mptr,*sptr
//output        ::  none
//call          ::  copybytedatatodispbuff
//effect        ::  none
//===================================================================
uint16_t	display_pf( uint8_t *mptr,uint8_t *sptr )
{
	copybytedatatodispbuff( mptr,sptr,2 );
	DisplayPixel("p1",1);  // 'p1'
	
//	dsoffset=0;//from the first digit start
//	displaynum=4;//display 4 digits
    return(0x400);	
}
//===================================================================
//decription    ::  display n digits from right k posit start
//function      ::  display_n_digits_k_posit
//input         ::  num_posit->digit num & right start posit
//				::	ptr->display data start address
//output        ::  none
//call          ::  set_upper_digit
//effect        ::  SLCDC
//===================================================================
void	display_n_digits_k_posit(uint16_t num_posit,uint8_t *ptr)
{
	uint8_t	i;
	uint8_t	num,posit;
	
	num =(uint8_t)(num_posit>>8);
	posit =(uint8_t)(num_posit&0x00FF);
	if(num<=6&&(num+posit)<=6)
	{
		for(i=0;i<num;i++)
		{
			DisplaySingleDigit( 5-posit-i, *(ptr+i));			
		}
	}
}
//===================================================================
//decription    ::  display unit symbol
//function      ::  display_units
//input         ::  unit
//output        ::  none
//call          ::  display_segment_index
//effect        ::  SLCDC
//===================================================================
void	display_units(uint32_t unit)
{

	switch (unit) 
	{		
        case Wh_UNIT:
		{
			// "V\/h"
			DisplayPixel("V",1);  // 'V'
			DisplayPixel("ʅ",1);  // '\'
			DisplayPixel("/",1);  // '/'
			DisplayPixel("h",1);  // 'h'
		}          
        break;
		case W_UNIT:
		{
			// "V\/h"
			DisplayPixel("V",1);  // 'V'
			DisplayPixel("ʅ",1);  // '\'
			DisplayPixel("/",1);  // '/'			
		}          
        break;		
        case kWh_UNIT:
		{
			// "kV\/h"
			DisplayPixel("k",1);  // 'k'
			DisplayPixel("V",1);  // 'V'
			DisplayPixel("ʅ",1);  // '\'
			DisplayPixel("/",1);  // '/'
			DisplayPixel("h",1);  // 'h'
		}          
		break;
		case kW_UNIT:
		{
			// "kV\/h"
			DisplayPixel("k",1);  // 'k'
			DisplayPixel("V",1);  // 'V'
			DisplayPixel("ʅ",1);  // '\'
			DisplayPixel("/",1);  // '/'			
		}          
		break;
        case VArh_UNIT:
		{
			// "VArh"
			DisplayPixel("V",1);  // 'V'
			DisplayPixel("/",1);  // '/'
			DisplayPixel("˧",1);  // 'л'			
			DisplayPixel("r",1);  // 'r'
			DisplayPixel("h",1);  // 'h'
		}          
		break;
		case VAr_UNIT:
		{
			// "VArh"
			DisplayPixel("V",1);  // 'V'
			DisplayPixel("/",1);  // '/'
			DisplayPixel("˧",1);  // '˧'			
			DisplayPixel("r",1);  // 'r'			
		}          
		break;
        case kVArh_UNIT:
		{
			// "kVArh"
			DisplayPixel("k",1);  // 'k'
			DisplayPixel("V",1);  // 'V'
			DisplayPixel("/",1);  // '/'
			DisplayPixel("˧",1);  // '˧'			
			DisplayPixel("r",1);  // 'r'
			DisplayPixel("h",1);  // 'h'
		}          
		break;
		case kVAr_UNIT:
		{
			// "kVAr"
			DisplayPixel("k",1);  // 'k'
			DisplayPixel("V",1);  // 'V'
			DisplayPixel("/",1);  // '/'
			DisplayPixel("˧",1);  // '˧'			
			DisplayPixel("r",1);  // 'r'			
		}          
		break;
        case VAh_UNIT:
		{
			// "VAh"
			DisplayPixel("V",1);  // 'V'
			DisplayPixel("/",1);  // '/'
			DisplayPixel("˧",1);  // '˧'			
			DisplayPixel("r",1);  // 'r'
			DisplayPixel("h",1);  // 'h'
		}          
		break;
		case VA_UNIT:
		{
			// "VA"
			DisplayPixel("V",1);  // 'V'
			DisplayPixel("/",1);  // '/'
			DisplayPixel("˧",1);  // '˧'	
		}          
		break;		
        case kVAh_UNIT:
		{
			// "kVAh"
			DisplayPixel("k",1);  // 'k'
			DisplayPixel("V",1);  // 'V'
			DisplayPixel("/",1);  // '/'
			DisplayPixel("˧",1);  // '˧'			
			DisplayPixel("h",1);  // 'h'
		}          
		break;
		case kVA_UNIT:
		{
			// "kVA"
			DisplayPixel("k",1);  // 'k'
			DisplayPixel("V",1);  // 'V'
			DisplayPixel("/",1);  // '/'
			DisplayPixel("˧",1);  // '˧'	
		}          
		break;
        case V_UNIT:
		{
			// "V"
			DisplayPixel("V",1);  // 'V'
		}
		break;          
        case I_UNIT:
		{
			// "I"
			DisplayPixel("/",1);  // '/'
			DisplayPixel("˧",1);  // '˧'
		}          
		break;
		default:
		break;
    }

}



/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
}
#endif
/**INDENT-ON**/
/// @endcond