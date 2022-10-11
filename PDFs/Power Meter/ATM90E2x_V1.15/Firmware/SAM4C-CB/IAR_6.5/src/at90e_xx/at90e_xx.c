//===================================================================
#include "AT90E_xx.h"

/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
extern "C" {
#endif
/**INDENT-ON**/
/// @endcond

//#define	AFE90E25_RegNum_Max		52
//const	uint8_t	afe90e25_regadr_table[AFE90E25_RegNum_Max]=
//{
//	SoftRest,SysStatus,FuncEn,SagTH,SmallPMod,LastSPIData,		//1-6
//	CalStart,PLconstH,PLcosntL,Lgain,Lphi,Ngain,Nphi,PStartTH,PNolTH,QStartTH,QNolTH,MMode,CS1,		//1-13
//	AdjStart,Ugain,IgainL,IgainN,Uoffset,IoffsetL,IoffsetN,PoffsetL,PoffsetN,QoffsetL,QoffsetN,CS2,			//1-12
//	APenegy,ANenergy,ATenergy,RPenergy,RNenergy,RTenergy,Enstatus,Irms,Urms,Pmean,Qmean,Freq,PowerF,Pangle,Smean,	//1-15
//	Irms2,Pmean2,Qmean2,PowerF2,Pangle2,Smean2		//1-6	
//}; 
//#define	AFE90E2x_cmd_reg_E2_NumMax	(16+12)
const	AFE_CMD_REG_E2Adr_Str	afe90e2x_cmd_reg_e2adr_tbl[AFE90E2x_cmd_reg_E2_NumMax]=
{
	{0xD002,	FuncEn,			E2_AT90E2x_FunEn},
	{0xD003,	SagTH,			E2_AT90E2x_SagTTH},
	{0xD004,	SmallPMod,		E2_AT90E2x_SmallPMod},
	{0xD020,	CalStart,		E2_AT90E2x_CalStart},	
	{0xD021,	PLconstH,		E2_AT90E2x_PLConstH},
	{0xD022,	PLcosntL,		E2_AT90E2x_PLConstL},
	{0xD023,	Lgain,			E2_AT90E2x_LGain},
	{0xD024,	Lphi,			E2_AT90E2x_LPhi},
	{0xD025,	Ngain,			E2_AT90E2x_NGain},
	{0xD026,	Nphi,			E2_AT90E2x_NPhi},
	{0xD027,	PStartTH,		E2_AT90E2x_PStartTH},
	{0xD028,	PNolTH,			E2_AT90E2x_PNolTH},
	{0xD029,	QStartTH,		E2_AT90E2x_QStartTH},
	{0xD02A,	QNolTH,			E2_AT90E2x_QNolTH},
	{0xD02B,	MMode,			E2_AT90E2x_MMode},
	{0xD02C,	CS1,			E2_AT90E2x_CS1},
	{0xD030,	AdjStart,		E2_AT90E2x_AdjStart},
	{0xD031,	Ugain,			E2_AT90E2x_Ugain},
	{0xD032,	IgainL,			E2_AT90E2x_IgainL},
	{0xD033,	IgainN,			E2_AT90E2x_IgainN},
	{0xD034,	Uoffset,		E2_AT90E2x_Uoffset},
	{0xD035,	IoffsetL,		E2_AT90E2x_IoffsetL},
	{0xD036,	IoffsetN,		E2_AT90E2x_IoffsetN},
	{0xD037,	PoffsetL,		E2_AT90E2x_PoffsetL},
	{0xD039,	PoffsetN,		E2_AT90E2x_PoffsetN},
	{0xD038,	QoffsetL,		E2_AT90E2x_QoffsetL},
	{0xD03A,	QoffsetN,		E2_AT90E2x_QoffsetN},
	{0xD03B,	CS2,			E2_AT90E2x_CS2}		
};
//#define	AFE90E3x_cmd_reg_E2_NumMax	(8*16+14)
const	AFE_CMD_REG_E2Adr_Str	afe90e3x_cmd_reg_e2adr_tbl[AFE90E3x_cmd_reg_E2_NumMax]=
{
	{0xD000,	0x00,			E2_AT90E3x_000_Register},
	{0xD001,	0x01,			E2_AT90E3x_001_Register},
	{0xD002,	0x02,			E2_AT90E3x_002_Register},
	{0xD003,	0x03,			E2_AT90E3x_003_Register},
	{0xD004,	0x04,			E2_AT90E3x_004_Register},
	{0xD005,	0x05,			E2_AT90E3x_005_Register},
	{0xD006,	0x06,			E2_AT90E3x_006_Register},
	{0xD007,	0x07,			E2_AT90E3x_007_Register},
	{0xD008,	0x08,			E2_AT90E3x_008_Register},
	{0xD009,	0x09,			E2_AT90E3x_009_Register},
	{0xD00A,	0x0A,			E2_AT90E3x_00A_Register},
	{0xD00B,	0x0B,			E2_AT90E3x_00B_Register},
	{0xD00C,	0x0C,			E2_AT90E3x_00C_Register},
	{0xD00D,	0x0D,			E2_AT90E3x_00D_Register},
	{0xD00E,	0x0E,			E2_AT90E3x_00E_Register},
	{0xD00F,	0x0F,			E2_AT90E3x_00F_Register},
	
	{0xD010,	0x10,			E2_AT90E3x_010_Register},
	{0xD011,	0x11,			E2_AT90E3x_011_Register},
	{0xD012,	0x12,			E2_AT90E3x_012_Register},
	{0xD013,	0x13,			E2_AT90E3x_013_Register},
	{0xD014,	0x14,			E2_AT90E3x_014_Register},
	{0xD015,	0x15,			E2_AT90E3x_015_Register},
	{0xD016,	0x16,			E2_AT90E3x_016_Register},
	{0xD017,	0x17,			E2_AT90E3x_017_Register},
	{0xD018,	0x18,			E2_AT90E3x_018_Register},
	{0xD019,	0x19,			E2_AT90E3x_019_Register},
	{0xD01A,	0x1A,			E2_AT90E3x_01A_Register},
	{0xD01B,	0x1B,			E2_AT90E3x_01B_Register},
	{0xD01C,	0x1C,			E2_AT90E3x_01C_Register},
	{0xD01D,	0x1D,			E2_AT90E3x_01D_Register},
	{0xD01E,	0x1E,			E2_AT90E3x_01E_Register},
	{0xD01F,	0x1F,			E2_AT90E3x_01F_Register},
	
	{0xD020,	0x20,			E2_AT90E3x_020_Register},
	{0xD021,	0x21,			E2_AT90E3x_021_Register},
	{0xD022,	0x22,			E2_AT90E3x_022_Register},
	{0xD023,	0x23,			E2_AT90E3x_023_Register},
	{0xD024,	0x24,			E2_AT90E3x_024_Register},
	{0xD025,	0x25,			E2_AT90E3x_025_Register},
	{0xD026,	0x26,			E2_AT90E3x_026_Register},
	{0xD027,	0x27,			E2_AT90E3x_027_Register},
	{0xD028,	0x28,			E2_AT90E3x_028_Register},
	{0xD029,	0x29,			E2_AT90E3x_029_Register},
	{0xD02A,	0x2A,			E2_AT90E3x_02A_Register},
	{0xD02B,	0x2B,			E2_AT90E3x_02B_Register},
	{0xD02C,	0x2C,			E2_AT90E3x_02C_Register},
	{0xD02D,	0x2D,			E2_AT90E3x_02D_Register},
	{0xD02E,	0x2E,			E2_AT90E3x_02E_Register},
	{0xD02F,	0x2F,			E2_AT90E3x_02F_Register},
	
	{0xD030,	0x30,			E2_AT90E3x_030_Register},
	{0xD031,	0x31,			E2_AT90E3x_031_Register},
	{0xD032,	0x32,			E2_AT90E3x_032_Register},
	{0xD033,	0x33,			E2_AT90E3x_033_Register},
	{0xD034,	0x34,			E2_AT90E3x_034_Register},
	{0xD035,	0x35,			E2_AT90E3x_035_Register},
	{0xD036,	0x36,			E2_AT90E3x_036_Register},
	{0xD037,	0x37,			E2_AT90E3x_037_Register},
	{0xD038,	0x38,			E2_AT90E3x_038_Register},
	{0xD039,	0x39,			E2_AT90E3x_039_Register},
	{0xD03A,	0x3A,			E2_AT90E3x_03A_Register},
	{0xD03B,	0x3B,			E2_AT90E3x_03B_Register},
	{0xD03C,	0x3C,			E2_AT90E3x_03C_Register},
	{0xD03D,	0x3D,			E2_AT90E3x_03D_Register},
	{0xD03E,	0x3E,			E2_AT90E3x_03E_Register},
	{0xD03F,	0x3F,			E2_AT90E3x_03F_Register},	
	
	{0xD040,	0x40,			E2_AT90E3x_040_Register},
	{0xD041,	0x41,			E2_AT90E3x_041_Register},
	{0xD042,	0x42,			E2_AT90E3x_042_Register},
	{0xD043,	0x43,			E2_AT90E3x_043_Register},
	{0xD044,	0x44,			E2_AT90E3x_044_Register},
	{0xD045,	0x45,			E2_AT90E3x_045_Register},
	{0xD046,	0x46,			E2_AT90E3x_046_Register},
	{0xD047,	0x47,			E2_AT90E3x_047_Register},
	{0xD048,	0x48,			E2_AT90E3x_048_Register},
	{0xD049,	0x49,			E2_AT90E3x_049_Register},
	{0xD04A,	0x4A,			E2_AT90E3x_04A_Register},
	{0xD04B,	0x4B,			E2_AT90E3x_04B_Register},
	{0xD04C,	0x4C,			E2_AT90E3x_04C_Register},
	{0xD04D,	0x4D,			E2_AT90E3x_04D_Register},
	{0xD04E,	0x4E,			E2_AT90E3x_04E_Register},
	{0xD04F,	0x4F,			E2_AT90E3x_04F_Register},
	
	{0xD050,	0x50,			E2_AT90E3x_050_Register},
	{0xD051,	0x51,			E2_AT90E3x_051_Register},
	{0xD052,	0x52,			E2_AT90E3x_052_Register},
	{0xD053,	0x53,			E2_AT90E3x_053_Register},
	{0xD054,	0x54,			E2_AT90E3x_054_Register},
	{0xD055,	0x55,			E2_AT90E3x_055_Register},
	{0xD056,	0x56,			E2_AT90E3x_056_Register},
	{0xD057,	0x57,			E2_AT90E3x_057_Register},
	{0xD058,	0x58,			E2_AT90E3x_058_Register},
	{0xD059,	0x59,			E2_AT90E3x_059_Register},
	{0xD05A,	0x5A,			E2_AT90E3x_05A_Register},
	{0xD05B,	0x5B,			E2_AT90E3x_05B_Register},
	{0xD05C,	0x5C,			E2_AT90E3x_05C_Register},
	{0xD05D,	0x5D,			E2_AT90E3x_05D_Register},
	{0xD05E,	0x5E,			E2_AT90E3x_05E_Register},
	{0xD05F,	0x5F,			E2_AT90E3x_05F_Register},
	
	{0xD060,	0x60,			E2_AT90E3x_060_Register},
	{0xD061,	0x61,			E2_AT90E3x_061_Register},
	{0xD062,	0x62,			E2_AT90E3x_062_Register},
	{0xD063,	0x63,			E2_AT90E3x_063_Register},
	{0xD064,	0x64,			E2_AT90E3x_064_Register},
	{0xD065,	0x65,			E2_AT90E3x_065_Register},
	{0xD066,	0x66,			E2_AT90E3x_066_Register},
	{0xD067,	0x67,			E2_AT90E3x_067_Register},
	{0xD068,	0x68,			E2_AT90E3x_068_Register},
	{0xD069,	0x69,			E2_AT90E3x_069_Register},
	{0xD06A,	0x6A,			E2_AT90E3x_06A_Register},
	{0xD06B,	0x6B,			E2_AT90E3x_06B_Register},
	{0xD06C,	0x6C,			E2_AT90E3x_06C_Register},
	{0xD06D,	0x6D,			E2_AT90E3x_06D_Register},
	{0xD06E,	0x6E,			E2_AT90E3x_06E_Register},
	{0xD06F,	0x6F,			E2_AT90E3x_06F_Register},
	
	{0xD070,	0x70,			E2_AT90E3x_070_Register},
	{0xD071,	0x71,			E2_AT90E3x_071_Register},
	{0xD072,	0x72,			E2_AT90E3x_072_Register},
	{0xD073,	0x73,			E2_AT90E3x_073_Register},
	{0xD074,	0x74,			E2_AT90E3x_074_Register},
	{0xD075,	0x75,			E2_AT90E3x_075_Register},
	{0xD076,	0x76,			E2_AT90E3x_076_Register},
	{0xD077,	0x77,			E2_AT90E3x_077_Register},
	{0xD078,	0x78,			E2_AT90E3x_078_Register},
	{0xD079,	0x79,			E2_AT90E3x_079_Register},
	{0xD07A,	0x7A,			E2_AT90E3x_07A_Register},
	{0xD07B,	0x7B,			E2_AT90E3x_07B_Register},
	{0xD07C,	0x7C,			E2_AT90E3x_07C_Register},
	{0xD07D,	0x7D,			E2_AT90E3x_07D_Register},
	{0xD07E,	0x7E,			E2_AT90E3x_07E_Register},
	{0xD07F,	0x7F,			E2_AT90E3x_07F_Register},
		
	{0xD800,	P3_BGCurveK,		E2_AT90E3x_800_Register},
	{0xD802,	P3_TEMP_COMP_GAIN,	E2_AT90E3x_802_Register},
	{0xD803,	P3_TEMP_COMP_REF,	E2_AT90E3x_803_Register},	
	{0xD804,	P3_PMIGainA,		E2_AT90E3x_804_Register},
	{0xD805,	P3_PMIGainB,		E2_AT90E3x_805_Register},
	{0xD806,	P3_PMIGainC,        E2_AT90E3x_806_Register},
	{0xD808,	P3_BG_TEMP_P12,     E2_AT90E3x_808_Register},
	{0xD809,	P3_BG_TEMP_P34,		E2_AT90E3x_809_Register},
	{0xD80A,	P3_BG_TEMP_P56,		E2_AT90E3x_80A_Register},
	{0xD80B,	P3_BG_TEMP_P78,		E2_AT90E3x_80B_Register},
	{0xD80C,	P3_BG_TEMP_N12,		E2_AT90E3x_80C_Register},
	{0xD80D,	P3_BG_TEMP_N34,		E2_AT90E3x_80D_Register},
	{0xD80E,	P3_BG_TEMP_N56,		E2_AT90E3x_80E_Register},
	{0xD80F,	P3_BG_TEMP_N78,		E2_AT90E3x_80F_Register}	
};


//---------------------------------------------------------  
AFE_Str		VAFE;

//=========================================================
//decription	::	AFE DMA is enable
//function		::	AFE_DMA_ENABLE
//Input			::	none
//Output		::	AFE_DMA=1
//call			::	none
//effect		::	none
//=========================================================
void	AFE_DMA_ENABLE(void)
{
	AFE_DMA_High();
}
//=========================================================
//decription	::	AFE DMA is disable
//function		::	AFE_DMA_DISABLE
//Input			::	none
//Output		::	AFE_DMA=0
//call			::	none
//effect		::	none
//=========================================================
void	AFE_DMA_DISABLE(void)
{
	AFE_DMA_Low();
}
//=========================================================
//decription	::	AFE is nomal mode
//function		::	AFE_Normal_MODE
//Input			::	none
//Output		::	AFE_PM1 =1 ,AFE_PM0 =1
//call			::	none
//effect		::	none
//=========================================================
void	AFE_Normal_MODE(void)
{
	AFE_PM1_High();
	AFE_PM0_High();
}
//=========================================================
//decription	::	AFE is patial mode
//function		::	AFE_Patial_MODE
//Input			::	none
//Output		::	AFE_PM1 =1 ,AFE_PM0 =0
//call			::	none
//effect		::	none
//=========================================================
void	AFE_Patial_MODE(void)
{
	AFE_PM1_High();
	AFE_PM0_Low();
}
//=========================================================
//decription	::	AFE is Detect mode
//function		::	AFE_Detect_MODE
//Input			::	none
//Output		::	AFE_PM1 =0 ,AFE_PM0 =1
//call			::	none
//effect		::	none
//=========================================================
void	AFE_Detect_MODE(void)
{
	AFE_PM1_Low();
	AFE_PM0_High();
}
//=========================================================
//decription	::	AFE is Idle mode
//function		::	AFE_Idle_MODE
//Input			::	none
//Output		::	AFE_PM1 =0 ,AFE_PM0 =0
//call			::	none
//effect		::	none
//=========================================================
void	AFE_Idle_MODE(void)
{
	AFE_PM1_Low();
	AFE_PM0_Low();	
}
//=========================================================
//decription	::	set AFE mode
//function		::	SET_AFE_MODE
//Input			::	mode
//Output		::	
//call			::	none
//effect		::	none
//=========================================================
void	SET_AFE_MODE( AFE_MODE mode )
{
	AFE_PM0_Out();
	AFE_PM1_Out();	
	VAFE.runmode =mode;
	switch (mode)
	{
		case	Idle_Mode:
		{
			AFE_Idle_MODE();
		}
		break;
		case	Detect_Mode:
		{
			AFE_Detect_MODE();
		}
		break;
		case	Patial_Mode:
		{	
			AFE_Patial_MODE();
		}
		break;
		case	Nomal_Mode:
		default:
		{
            AFE_Normal_MODE();           
		}
		break;
	}	
}

//=========================================================
//decription	::	AFE CS is enable
//function		::	AFE_CS_ENABLE
//Input			::	none
//Output		::	AFE_CS=0
//call			::	none
//effect		::	none
//=========================================================
void	AFE_CS_ENABLE(void)
{
	AFE_CS_Low();
}
//=========================================================
//decription	::	AFE CS is disable
//function		::	AFE_CS_DISABLE
//Input			::	none
//Output		::	AFE_CS=1
//call			::	none
//effect		::	none
//=========================================================
void	AFE_CS_DISABLE(void)
{
	AFE_CS_High();
}
//=========================================================
//decription	::	AFE configure zx0
//function		::	AFE_Configure_ZX0
//Input			::	none
//Output		::	none
//call			::	pmc_enable_periph_clk,pio_set_debounce_filter
//					gpio_configure_pin,pio_enable_interrupt
//effect		::	none
//=========================================================
void	AFE_Configure_ZX0(void)
{
	pmc_enable_periph_clk( AFE_ZX0_ID );
	gpio_configure_pin(AFE_ZX0_PIN, AFE_ZX0_FLAGS);
	pio_set_debounce_filter(AFE_ZX0_PIO, AFE_ZX0_MASK, 20);
	pio_handler_set(AFE_ZX0_PIO, AFE_ZX0_ID, AFE_ZX0_MASK, PIO_IT_FALL_EDGE, AFE_ZX0_INT_handler);
	pio_enable_interrupt(AFE_ZX0_PIO, AFE_ZX0_MASK);
	VAFE.IntNum[ZX0] =0;			
	NVIC_DisableIRQ(PIOA_IRQn);
	NVIC_ClearPendingIRQ(PIOA_IRQn);
	NVIC_SetPriority(PIOA_IRQn, 0);
	NVIC_EnableIRQ(PIOA_IRQn); 
}
//=========================================================
//decription	::	AFE ZX0 interrupt process
//function		::	AFE_ZX0_INT_handler
//Input			::	none
//Output		::	none
//call			::	none
//effect		::	none
//=========================================================
void	AFE_ZX0_INT_handler(void)
{
//	if( pio_get_interrupt_status( AFE_ZX0_PIO ) )
//	{
		if( !pio_get_pin_value( AFE_ZX0_PIN ) )
		{
			VAFE.IntNum[ZX0] ++;
		}
//	}
}
//=========================================================
//decription	::	AFE configure zx1
//function		::	AFE_Configure_ZX1
//Input			::	none
//Output		::	none
//call			::	pmc_enable_periph_clk,pio_set_debounce_filter
//					gpio_configure_pin,pio_enable_interrupt
//effect		::	none
//=========================================================
void	AFE_Configure_ZX1(void)
{
	pmc_enable_periph_clk( AFE_ZX1_ID );
	gpio_configure_pin(AFE_ZX1_PIN, AFE_ZX1_FLAGS);
	pio_set_debounce_filter(AFE_ZX1_PIO, AFE_ZX1_MASK, 20);
	pio_handler_set(AFE_ZX1_PIO, AFE_ZX1_ID, AFE_ZX1_MASK, PIO_IT_FALL_EDGE, AFE_ZX1_INT_handler);
	pio_enable_interrupt(AFE_ZX1_PIO, AFE_ZX1_MASK);
	VAFE.IntNum[ZX1] =0;			
	NVIC_DisableIRQ(PIOA_IRQn);
	NVIC_ClearPendingIRQ(PIOA_IRQn);
	NVIC_SetPriority(PIOA_IRQn, 0);
	NVIC_EnableIRQ(PIOA_IRQn); 
}
//=========================================================
//decription	::	AFE ZX1 interrupt process
//function		::	AFE_ZX1_INT_handler
//Input			::	none
//Output		::	none
//call			::	none
//effect		::	none
//=========================================================
void	AFE_ZX1_INT_handler(void)
{
//	if( pio_get_interrupt_status( AFE_ZX1_PIO ) )
//	{
		if( !pio_get_pin_value( AFE_ZX1_PIN ) )
		{
			VAFE.IntNum[ZX1] ++;
		}
//	}
}
//=========================================================
//decription	::	AFE configure zx2
//function		::	AFE_Configure_ZX2
//Input			::	none
//Output		::	none
//call			::	pmc_enable_periph_clk,pio_set_debounce_filter
//					gpio_configure_pin,pio_enable_interrupt
//effect		::	none
//=========================================================
void	AFE_Configure_ZX2(void)
{
	pmc_enable_periph_clk( AFE_ZX2_ID );
	gpio_configure_pin(AFE_ZX2_PIN, AFE_ZX2_FLAGS);
	pio_set_debounce_filter(AFE_ZX2_PIO, AFE_ZX2_MASK, 20);
	pio_handler_set(AFE_ZX2_PIO, AFE_ZX2_ID, AFE_ZX2_MASK, PIO_IT_FALL_EDGE, AFE_ZX2_INT_handler);
	pio_enable_interrupt(AFE_ZX2_PIO, AFE_ZX2_MASK);
	VAFE.IntNum[ZX2] =0;			
	NVIC_DisableIRQ(PIOA_IRQn);
	NVIC_ClearPendingIRQ(PIOA_IRQn);
	NVIC_SetPriority(PIOA_IRQn, 0);
	NVIC_EnableIRQ(PIOA_IRQn); 
}
//=========================================================
//decription	::	AFE ZX2 interrupt process
//function		::	AFE_ZX2_INT_handler
//Input			::	none
//Output		::	none
//call			::	none
//effect		::	none
//=========================================================
void	AFE_ZX2_INT_handler(void)
{
//	if( pio_get_interrupt_status( AFE_ZX2_PIO ) )
//	{
		if( !pio_get_pin_value( AFE_ZX2_PIN ) )
		{
			VAFE.IntNum[ZX2] ++;
		}
//	}
}
//=========================================================
//decription	::	AFE configure CF1
//function		::	AFE_Configure_CF1
//Input			::	none
//Output		::	none
//call			::	pmc_enable_periph_clk,pio_set_debounce_filter
//					gpio_configure_pin,pio_enable_interrupt
//effect		::	none
//=========================================================
void	AFE_Configure_CF1(void)
{
	pmc_enable_periph_clk( AFE_CF1_ID );
	gpio_configure_pin(AFE_CF1_PIN, AFE_CF1_FLAGS);
	pio_set_debounce_filter(AFE_CF1_PIO, AFE_CF1_MASK, 20);
	pio_handler_set(AFE_CF1_PIO, AFE_CF1_ID, AFE_CF1_MASK, PIO_IT_FALL_EDGE, AFE_CF1_INT_handler);
	pio_enable_interrupt(AFE_CF1_PIO, AFE_CF1_MASK);
	VAFE.IntNum[CF1] =0;			
	NVIC_DisableIRQ(PIOA_IRQn);
	NVIC_ClearPendingIRQ(PIOA_IRQn);
	NVIC_SetPriority(PIOA_IRQn, 0);
	NVIC_EnableIRQ(PIOA_IRQn); 
}
//=========================================================
//decription	::	AFE CF1 interrupt process
//function		::	AFE_CF1_INT_handler
//Input			::	none
//Output		::	none
//call			::	none
//effect		::	none
//=========================================================
void	AFE_CF1_INT_handler(void)
{
//	if( pio_get_interrupt_status( AFE_CF1_PIO ) )
//	{
		if( !pio_get_pin_value( AFE_CF1_PIN ) )
		{
			VAFE.IntNum[CF1] ++;
		}
//	}
}
//=========================================================
//decription	::	AFE configure CF2
//function		::	AFE_Configure_CF2
//Input			::	none
//Output		::	none
//call			::	pmc_enable_periph_clk,pio_set_debounce_filter
//					gpio_configure_pin,pio_enable_interrupt
//effect		::	none
//=========================================================
void	AFE_Configure_CF2(void)
{
	pmc_enable_periph_clk( AFE_CF2_ID );
	gpio_configure_pin(AFE_CF2_PIN, AFE_CF2_FLAGS);
	pio_set_debounce_filter(AFE_CF2_PIO, AFE_CF2_MASK, 20);
	pio_handler_set(AFE_CF2_PIO, AFE_CF2_ID, AFE_CF2_MASK, PIO_IT_FALL_EDGE, AFE_CF2_INT_handler);
	pio_enable_interrupt(AFE_CF2_PIO, AFE_CF2_MASK);
	VAFE.IntNum[CF2] =0;			
	NVIC_DisableIRQ(PIOA_IRQn);
	NVIC_ClearPendingIRQ(PIOA_IRQn);
	NVIC_SetPriority(PIOA_IRQn, 0);
	NVIC_EnableIRQ(PIOA_IRQn); 
}
//=========================================================
//decription	::	AFE CF2 interrupt process
//function		::	AFE_CF2_INT_handler
//Input			::	none
//Output		::	none
//call			::	none
//effect		::	none
//=========================================================
void	AFE_CF2_INT_handler(void)
{
//	if( pio_get_interrupt_status( AFE_CF2_PIO ) )
//	{
		if( !pio_get_pin_value( AFE_CF2_PIN ) )
		{
			VAFE.IntNum[CF2] ++;
		}
//	}
}
//=========================================================
//decription	::	AFE configure CF3
//function		::	AFE_Configure_CF3
//Input			::	none
//Output		::	none
//call			::	pmc_enable_periph_clk,pio_set_debounce_filter
//					gpio_configure_pin,pio_enable_interrupt
//effect		::	none
//=========================================================
void	AFE_Configure_CF3(void)
{
	pmc_enable_periph_clk( AFE_CF3_ID );
	gpio_configure_pin(AFE_CF3_PIN, AFE_CF3_FLAGS);
	pio_set_debounce_filter(AFE_CF3_PIO, AFE_CF3_MASK, 20);
	pio_handler_set(AFE_CF3_PIO, AFE_CF3_ID, AFE_CF3_MASK, PIO_IT_FALL_EDGE, AFE_CF3_INT_handler);
	pio_enable_interrupt(AFE_CF3_PIO, AFE_CF3_MASK);
	VAFE.IntNum[CF3] =0;			
	NVIC_DisableIRQ(PIOA_IRQn);
	NVIC_ClearPendingIRQ(PIOA_IRQn);
	NVIC_SetPriority(PIOA_IRQn, 0);
	NVIC_EnableIRQ(PIOA_IRQn); 
}
//=========================================================
//decription	::	AFE CF3 interrupt process
//function		::	AFE_CF3_INT_handler
//Input			::	none
//Output		::	none
//call			::	none
//effect		::	none
//=========================================================
void	AFE_CF3_INT_handler(void)
{
//	if( pio_get_interrupt_status( AFE_CF3_PIO ) )
//	{
		if( !pio_get_pin_value( AFE_CF3_PIN ) )
		{
			VAFE.IntNum[CF3] ++;
		}
//	}
}
//=========================================================
//decription	::	AFE configure CF4
//function		::	AFE_Configure_CF4
//Input			::	none
//Output		::	none
//call			::	pmc_enable_periph_clk,pio_set_debounce_filter
//					gpio_configure_pin,pio_enable_interrupt
//effect		::	none
//=========================================================
void	AFE_Configure_CF4(void)
{
	pmc_enable_periph_clk( AFE_CF4_ID );
	gpio_configure_pin(AFE_CF4_PIN, AFE_CF4_FLAGS);
	pio_set_debounce_filter(AFE_CF4_PIO, AFE_CF4_MASK, 20);
	pio_handler_set(AFE_CF4_PIO, AFE_CF4_ID, AFE_CF4_MASK, PIO_IT_FALL_EDGE, AFE_CF4_INT_handler);
	pio_enable_interrupt(AFE_CF4_PIO, AFE_CF4_MASK);
	VAFE.IntNum[CF4] =0;			
	NVIC_DisableIRQ(PIOA_IRQn);
	NVIC_ClearPendingIRQ(PIOA_IRQn);
	NVIC_SetPriority(PIOA_IRQn, 0);
	NVIC_EnableIRQ(PIOA_IRQn); 
}
//=========================================================
//decription	::	AFE CF4 interrupt process
//function		::	AFE_CF4_INT_handler
//Input			::	none
//Output		::	none
//call			::	none
//effect		::	none
//=========================================================
void	AFE_CF4_INT_handler(void)
{
//	if( pio_get_interrupt_status( AFE_CF4_PIO ) )
//	{
		if( !pio_get_pin_value( AFE_CF4_PIN ) )
		{
			VAFE.IntNum[CF4] ++;
		}
//	}
}
/*
//=========================================================
//decription	::	AFE configure IRQ0
//function		::	AFE_Configure_IRQ0
//Input			::	none
//Output		::	none
//call			::	pmc_enable_periph_clk,pio_set_debounce_filter
//					gpio_configure_pin,pio_enable_interrupt
//effect		::	none
//=========================================================
void	AFE_Configure_IRQ0(void)
{
	pmc_enable_periph_clk( AFE_IRQ0_ID );
	gpio_configure_pin(AFE_IRQ0_PIN, AFE_IRQ0_FLAGS);
	pio_set_debounce_filter(AFE_IRQ0_PIO, AFE_IRQ0_MASK, 20);
	pio_handler_set(AFE_IRQ0_PIO, AFE_IRQ0_ID, AFE_IRQ0_MASK, PIO_IT_FALL_EDGE, AFE_IRQ0_INT_handler);
	pio_enable_interrupt(AFE_IRQ0_PIO, AFE_IRQ0_MASK);
	VAFE.IntNum[IRQ0] =0;			
	NVIC_DisableIRQ(PIOA_IRQn);
	NVIC_ClearPendingIRQ(PIOA_IRQn);
	NVIC_SetPriority(PIOA_IRQn, 0);
	NVIC_EnableIRQ(PIOA_IRQn); 
}
//=========================================================
//decription	::	AFE IRQ0 interrupt process
//function		::	AFE_IRQ0_INT_handler
//Input			::	none
//Output		::	none
//call			::	none
//effect		::	none
//=========================================================
void	AFE_IRQ0_INT_handler(void)
{
//	if( pio_get_interrupt_status( AFE_IRQ0_PIO ) )
//	{
		if( !pio_get_pin_value( AFE_IRQ0_PIN ) )
		{
			VAFE.IntNum[IRQ0] ++;
		}
//	}
}
//=========================================================
//decription	::	AFE configure IRQ1
//function		::	AFE_Configure_IRQ1
//Input			::	none
//Output		::	none
//call			::	pmc_enable_periph_clk,pio_set_debounce_filter
//					gpio_configure_pin,pio_enable_interrupt
//effect		::	none
//=========================================================
void	AFE_Configure_IRQ1(void)
{
	pmc_enable_periph_clk( AFE_IRQ1_ID );
	gpio_configure_pin(AFE_IRQ1_PIN, AFE_IRQ1_FLAGS);
	pio_set_debounce_filter(AFE_IRQ1_PIO, AFE_IRQ1_MASK, 20);
	pio_handler_set(AFE_IRQ1_PIO, AFE_IRQ1_ID, AFE_IRQ1_MASK, PIO_IT_FALL_EDGE, AFE_IRQ1_INT_handler);
	pio_enable_interrupt(AFE_IRQ1_PIO, AFE_IRQ1_MASK);
	VAFE.IntNum[IRQ1] =0;			
	NVIC_DisableIRQ(PIOB_IRQn);
	NVIC_ClearPendingIRQ(PIOB_IRQn);
	NVIC_SetPriority(PIOB_IRQn, 0);
	NVIC_EnableIRQ(PIOB_IRQn); 
}
//=========================================================
//decription	::	AFE IRQ1 interrupt process
//function		::	AFE_IRQ1_INT_handler
//Input			::	none
//Output		::	none
//call			::	none
//effect		::	none
//=========================================================
void	AFE_IRQ1_INT_handler(void)
{
//	if( pio_get_interrupt_status( AFE_IRQ1_PIO ) )
//	{
		if( !pio_get_pin_value( AFE_IRQ1_PIN ) )
		{
			VAFE.IntNum[IRQ1] ++;
		}
//	}
}
*/
//=========================================================
//decription	::	AFE configure IRQ0
//function		::	AFE_Configure_IRQ0
//Input			::	none
//Output		::	none
//call			::	pmc_enable_periph_clk,
//					gpio_configure_pin,pio_set_debounce_filter
//effect		::	none
//=========================================================
void	AFE_Configure_IRQ0(void)
{
	pmc_enable_periph_clk( AFE_IRQ0_ID );
	gpio_configure_pin(AFE_IRQ0_PIN, AFE_IRQ0_FLAGS);
	pio_set_debounce_filter(AFE_IRQ0_PIO, AFE_IRQ0_MASK, 20);
}
//=========================================================
//decription	::	AFE configure IRQ1
//function		::	AFE_Configure_IRQ1
//Input			::	none
//Output		::	none
//call			::	pmc_enable_periph_clk,
//					gpio_configure_pin,pio_set_debounce_filter
//effect		::	none
//=========================================================
void	AFE_Configure_IRQ1(void)
{
	pmc_enable_periph_clk( AFE_IRQ1_ID );
	gpio_configure_pin(AFE_IRQ1_PIN, AFE_IRQ1_FLAGS);
	pio_set_debounce_filter(AFE_IRQ1_PIO, AFE_IRQ1_MASK, 20);
}
//=========================================================
//decription	::	AFE configure WarmOut
//function		::	AFE_Configure_WarmOut
//Input			::	none
//Output		::	none
//call			::	pmc_enable_periph_clk,
//					gpio_configure_pin,pio_set_debounce_filter
//effect		::	none
//=========================================================
void	AFE_Configure_WarmOut(void)
{
	pmc_enable_periph_clk( AFE_WARMOUT_ID );
	gpio_configure_pin(AFE_WARMOUT_PIN, AFE_WARMOUT_FLAGS);
	pio_set_debounce_filter(AFE_WARMOUT_PIO, AFE_WARMOUT_MASK, 20);
}
//=========================================================
//decription	::	configure AFE interrupt
//function		::	Configure_AFE_Int
//Input			::	none
//Output		::	none
//call			::	none
//effect		::	none
//=========================================================
void	Configure_AFE_Int(void)
{
	switch ( VAFE.id )
	{
		case	AT90E25:
        case	AT90E24:
        case	AT90E23:
		{
			AFE_Configure_ZX0();
			AFE_Configure_CF1();
		}
		break;
        case	AT90E32:
		case	AT90E32A:
		case	AT90E32AS:		
		case	AT90E36:
		case	AT90E36A:
		{
			AFE_Configure_ZX0();
			AFE_Configure_ZX1();
			AFE_Configure_ZX2();

			AFE_Configure_CF1();
			AFE_Configure_CF2();
			AFE_Configure_CF3();
			AFE_Configure_CF3();
						
			//AFE_Configure_IRQ0();
			//AFE_Configure_IRQ1();		
		}
		break;		
		default :
		break;
	}	
}
//=========================================================
//decription	::	AFE SPI bus Inition
//function		::	AFE_SPI_Init
//Input			::	none
//Output		::	none
//call			::	none
//effect		::	none
//=========================================================
void	AFE_SPI_Init(void)
{
	switch ( VAFE.id )
	{
		case	AT90E25:
        case	AT90E24:
        case	AT90E23:
		{
			VAFE.runmode =Nomal_Mode;
		}
		break;
        case	AT90E32:
		case	AT90E32A:
		case	AT90E32AS:		
		case	AT90E36:
		case	AT90E36A:
		{
			AFE_DMA_Out();
			AFE_DMA_DISABLE();
			SET_AFE_MODE( Nomal_Mode );	
			AFE_Configure_IRQ1();
		}
		break;		
		default :
		break;
	}
	AFE_Configure_WarmOut();
	AFE_Configure_IRQ0();
	
	AFE_CS_Out();
	AFE_CS_PullUp_En();
	AFE_CS_DISABLE();
	AFE_SCK_Out();
	AFE_SCK_PullUp_En();
	AFE_SCK_Low();
	AFE_MOSI_Out();
	AFE_MOSI_PullUp_En();
	AFE_MOSI_Low();
	AFE_MISO_In();
	AFE_MISO_PullUp_En();
	AFE_MISO_High();	
}
//=========================================================
//decription	::	identify afe type 
//function		::	Identify_AFE_Type
//Input			::	none
//Output		::	none
//call			::	afe_xx.app()
//effect		::	vafe.id
//=========================================================
void	Identify_AFE_Type(void)
{
	uint32_t	i;
	uint32_t	val;
	uint16_t	adr;
	
	for(i=0;i<13;i++)
	{	
		if( (i&0x1)==0x01 )
		{
			VAFE.id =AT90E25;
			adr =AT90E2x_ChipID_Adr;	//
		}//singal meter
		else
		{			
			VAFE.id =AT90E36;
			adr =AT90E3x_ChipID_Adr;	//
		}//muliti meter		
		AFE_SPI_Init();
		Delay_N_ms(20);
		val=Read_AFE_1Reg( adr );
        __NOP();
        __NOP();
		switch(val)
		{
			case	AT90E25_CHIPID:
			{
                val =Read_AFE_1Reg( 0x16 );
                if( val ==0x8097)
                {
                     VAFE.id =AT90E25;
                     i =15;
                }
                if( val ==0x8077 )
                {
                    VAFE.id =AT90E24;
                    i =15;
                }               
            }
			break;
            case	AT90E23_CHIPID:
			{
				VAFE.id =AT90E23;
				i=15;
			}
			break;
			case	AT90E36_CHIPID:
			{
				val=Read_AFE_1Reg( adr );
				if( val==AT90E36_CHIPID )
				{
					VAFE.id =AT90E36;
					i=15;
				}
			}
			break;
			case	AT90E36A_CHIPID:
			{
				val=Read_AFE_1Reg( adr );
				if( val==AT90E36A_CHIPID )
				{
					VAFE.id =AT90E36A;
					i=15;
				}
			}
			break;
			case	AT90E32_CHIPID:
			{
				val=Read_AFE_1Reg( 0x30 );
				if( val==0x6886 )
				{
					VAFE.id =AT90E32;					
				}
				else
				{				
					VAFE.id =AT90E32AS;//AT90E32AS_VB_CHIPID;
				}
				i=15;
			}
			break;
			case	AT90E32A_CHIPID:
			{
				val=Read_AFE_1Reg( adr );
				if( val==AT90E32A_CHIPID )
				{
					VAFE.id =AT90E32A;
					i=15;
				}
			}
			break;
			case	AT90E32AS_VA_CHIPID:
			{
				val=Read_AFE_1Reg( adr );
				if( val==AT90E32AS_VA_CHIPID )
				{
					VAFE.id =AT90E32AS;
					i=15;
				}				
			}
			break;
		}		
	}
	
	if( i!=16 )
	{
		VAFE.id =0;
	}
	VAFE.sagstatus.HWORD =0;
	VAFE.measure_en_timer =0;
}
//=========================================================
//decription	::	read single register data from AFE via spi bus 
//function		::	Read_AFE_1Reg
//Input			::	regaddr
//Output		::	read out data
//call			::	Delay_N_us()
//effect		::	sck=0
//=========================================================
uint32_t Read_AFE_1Reg(uint16_t regaddr)
{
	uint16_t	adr,delaytm;
	uint8_t		adrlen;
	uint32_t	i;	
	uint32_t	rd_data=0;
	delaytm =1;	
	switch ( VAFE.id )
	{
		case	AT90E25:
        case	AT90E24:
        case	AT90E23:
		{
			adr =(uint16_t )(regaddr&0x7F);
			adr =adr<<8;
			adrlen =8;
            delaytm =8;
		}
		break;
		case	AT90E32:
		case	AT90E32A:
		case	AT90E32AS:		
		case	AT90E36:
		case	AT90E36A:
		{
			adr =(uint16_t )(regaddr&0x7FFF);
			adrlen =16;			
		}
		break;		
		default :
		{
			adrlen =0;
		}
		break;
	}
	adr |=0x8000;
	AFE_CS_ENABLE();
	
	AFE_SCK_Low();
	AFE_MISO_In();
	AFE_MOSI_Out();
	AFE_SCK_Out();
//	__disable_irq();
	for(i=0;i<adrlen;i++)
	{
		if(adr&0x8000)
		{
			AFE_MOSI_High();
		}
		else
		{
			AFE_MOSI_Low();
		}
        Delay_N_us(delaytm);
		AFE_SCK_High();
		Delay_N_us(delaytm);
		AFE_SCK_Low();
		adr=adr<<1;
	}
	for(i=0;i<16;i++)
	{
        Delay_N_us(delaytm);
		AFE_SCK_High();
		rd_data =rd_data<<1;
		Delay_N_us(delaytm);
		if(BIO_AFE_MISO)
		{
			rd_data |=0x01;
		}
		else
		{
			__NOP();
			__NOP();
		}				
		AFE_SCK_Low();
	}
	Delay_N_us(delaytm);
//	__enable_irq();
	AFE_CS_DISABLE();
	Delay_N_us(delaytm);
	if(adrlen==0)
		return(0);
	return(rd_data);
}
//=========================================================
//decription	::	write single register data from AFE via spi bus 
//function		::	write_AFE_1Reg
//Input			::	regaddr,regdata
//Output		::	1=success,0=failure
//call			::	Delay_N_us()
//effect		::	sck=0
//=========================================================
uint32_t write_AFE_1Reg(uint16_t regaddr,uint16_t regdata)
{
	uint16_t    delaytm;
    uint32_t	i;	
	uint32_t	wr_data;
	uint32_t	wr_sck_num;
	
	wr_data =(uint32_t)(regaddr&0x7FFF);
	wr_data =wr_data<<16;	
	wr_data |=(uint32_t)(regdata&0xFFFF);
	delaytm =1;
	switch ( VAFE.id )
	{
		case	AT90E25:
        case	AT90E24:
        case	AT90E23:
		{
			wr_data =wr_data<<8;
			wr_sck_num =24;
            delaytm =8;
		}
		break;
		case	AT90E32:
		case	AT90E32A:
		case	AT90E32AS:		
		case	AT90E36:
		case	AT90E36A:
		{
			wr_sck_num =32;			
		}
		break;		
		default :
		{
			wr_sck_num =0;
		}
		break;
	}	
	AFE_CS_ENABLE();
	
	AFE_SCK_Low();
	AFE_MISO_In();
	AFE_MOSI_Out();
	AFE_SCK_Out();
//	__disable_irq();
	for(i=0;i<wr_sck_num;i++)
	{
		if(wr_data&0x80000000)
		{
			AFE_MOSI_High();
		}
		else
		{
			AFE_MOSI_Low();
		}
        Delay_N_us(delaytm);
		AFE_SCK_High();
		Delay_N_us(delaytm);
		AFE_SCK_Low();
		wr_data=wr_data<<1;
	}
	Delay_N_us(delaytm);	
//	__enable_irq();
	AFE_CS_DISABLE();
	Delay_N_us(delaytm);
	if(wr_sck_num==0)
		return(0);
	return(1);
}
//=========================================================
//decription	::	communicate read AFE single register 
//function		::	CMD_Rd_AFE_Reg
//Input			::	ptr,regaddr
//Output		::	ptr->read out data
//call			::	
//effect		::	sck=0
//=========================================================
uint32_t	CMD_Rd_AFE_Reg( uint8_t *ptr,uint16_t regadr )
{
	uint32_t	val;
	val =Read_AFE_1Reg(regadr);
	__NOP();
	*ptr =(uint8_t)(val);
	*(ptr+1)=(uint8_t)(val>>8);
	return (0x2E);
}
//=========================================================
//decription	::	communicate write AFE single register 
//function		::	CMD_Wr_AFE_Reg
//Input			::	ptr regadr
//Output		::	0x2F->success,0x02->failure
//call			::	write_AFE_1Reg
//effect		::	
//=========================================================
uint32_t	CMD_Wr_AFE_Reg( uint8_t *ptr,uint16_t regadr )
{
	uint16_t	val;
	val =(uint16_t)(*(ptr+1));
	val =val<<8;
    val |=(uint16_t)(*(ptr+0));
	if( write_AFE_1Reg(regadr,val) )
	{
		return (0x2F);
	}
	else
	{
		return (0x02);
	}
}
//=========================================================
//decription	::	sag check
//function		::	Sag_check
//Input			::	none
//Output		::	none
//call			::	VAFE.sagstatus
//effect		::	
//=========================================================
void	Sag_check( void )
{
	uint32_t	val;
	VAFE.sagstatus.HWORD &=0xFF00;
	if( (VAFE.id==AT90E25) || (VAFE.id==AT90E24) || (VAFE.id==AT90E23) )
	{
		val =Read_AFE_1Reg(SysStatus);
		if( val&0x02)
		{
			VAFE.sagstatus.BIT.UaSag =1;
		}
	}
	else
	{
		if( VAFE.id==AT90E32AS )
		{
			val =Read_AFE_1Reg(P3_2AS_EMMState1);
			val =val>>8;
		}
		else
		{
			val =Read_AFE_1Reg(P3_EnStatus1);
		}
		if( val&0x10)
		{
			VAFE.sagstatus.BIT.UcSag =1;
		}
		if( val&0x20)
		{
			VAFE.sagstatus.BIT.UbSag =1;
		}
		if( val&0x40)
		{
			VAFE.sagstatus.BIT.UaSag =1;
		}
	}		
}
//=========================================================
//decription	::	enable harmonic calculate
//function		::	Enable_Harmonic_Calculate
//Input			::	none
//Output		::	none
//call			::	write_AFE_1Reg
//effect		::	thd_timer,thd_status
//=========================================================
void	Enable_Harmonic_Calculate(void)
{
	uint32_t	val;
	val =write_AFE_1Reg( 0x1D1,0x01);	//enable dft calculate
	if(val)
	{
		VAFE.thd_timer =101;	//505ms=101*5ms		
	}
	else
	{
		VAFE.thd_timer =0;
	}
	VAFE.thd_status =IsFailed;
}

//=========================================================
//decription	::	read measure parameter
//function		::	Rd_Measure_Parameter
//Input			::	regh_addr regl_addr
//Output		::	(regh_addr)<<16 + (regl_addr)
//call			::	Read_AFE_1Reg
//effect		::	
//=========================================================
uint32_t	Rd_Measure_Parameter(uint16_t regh_addr,uint16_t regl_addr)
{
	uint32_t	val,val_h,val_l;
	val_h =Read_AFE_1Reg(regh_addr);
	val_l =Read_AFE_1Reg(regl_addr);
	val =Read_AFE_1Reg(regh_addr);
	if(val_h !=val )
	{
		val_h =Read_AFE_1Reg(regh_addr);
		val_l =Read_AFE_1Reg(regl_addr);
	}
	val =val_h<<16;
	val |=val_l;
	
	return(val);
}
//=========================================================
//decription	::	calculate voltage or current mull scale
//function		::	Calculate_V_I_Mul_Scal
//Input			::	rmsval,scale
//Output		::	rmsval*f(scale)
//return		::	result
//call			::	none
//effect		::	
//=========================================================
uint32_t	Calculate_V_I_Mul_Scal(uint32_t rmsval,uint16_t scale)
{
	uint32_t	m;
	m =rmsval;
	switch( scale )
	{
		case	0:
		{
			m =m>>4;
		}
		break;
		case	1:
		{
			m =m>>3;
		}
		break;
		case	2:
		{
			m =m>>2;
		}
		break;
		case	3:
		{
			m =m>>1;
		}
		break;
		case	5:
		{
			m =m<<1;
		}
		break;
		case	6:
		{
			m =m<<2;
		}
		break;
		case	7:
		{
			m =m<<3;
		}
		break;
		case	8:
		{
			m =m<<4;
		}
		break;
	}
	return(m);
}
//=========================================================
//decription	::	calculate voltage or current rms
//function		::	Calculate_V_I_RMS
//Input			::	rmsptr rmsval
//Output		::	rmsval->ptr (0xxx.xxxx) V
//								(xxx.xxxxx) A
//return		::	1:success,3:failed
//call			::	none
//effect		::	
//=========================================================
uint32_t	Calculate_V_I_RMS( uint32_t *rmsptr,uint32_t rmsval)
{
	uint32_t	m;
	
	m =rmsval>>8;
	*rmsptr =(m%1000000)/100000;
	*rmsptr =*rmsptr<<4;	
	*rmsptr |=(m%100000)/10000;
	*rmsptr =*rmsptr<<4;
	*rmsptr |=(m%10000)/1000;
	*rmsptr =*rmsptr<<4;
	*rmsptr |=(m%1000)/100;
	*rmsptr =*rmsptr<<4;
	*rmsptr |=(m%100)/10;
	*rmsptr =*rmsptr<<4;
	*rmsptr |=(m%10);
	
	m =(rmsval%256)*100;
	*rmsptr =*rmsptr<<4;	
	*rmsptr |=(m>>8)/10;
	*rmsptr =*rmsptr<<4;
	*rmsptr |=((m>>8)%10);

	return(1);
}
//=========================================================
//decription	::	calculate power
//function		::	Calculate_Power
//Input			::	rmsptr rmsval
//Output		::	rmsval->ptr   (xxxxx.xxx w)
//call			::	none
//effect		::	
//=========================================================
void	Calculate_Power( uint32_t *rmsptr,uint32_t rmsval )
{
	uint64_t	m;
	if(VAFE.id==AT90E32AS)
	{
		m =rmsval;
        m =m*1000;          // xxxxx.xxx w
		m=m/3125;		//*0.00032w
		*rmsptr =(uint8_t)((m%100000000)/10000000);
		*rmsptr =*rmsptr<<4;
		*rmsptr |=(uint8_t)((m%10000000)/1000000);        
		*rmsptr =*rmsptr<<4;
		*rmsptr |=(uint8_t)((m%1000000)/100000);
		*rmsptr =*rmsptr<<4;
		*rmsptr |=(uint8_t)((m%100000)/10000);
		*rmsptr =*rmsptr<<4;
		*rmsptr |=(uint8_t)((m%10000)/1000);
		*rmsptr =*rmsptr<<4;
		*rmsptr |=(uint8_t)((m%1000)/100);
		*rmsptr =*rmsptr<<4;
		*rmsptr |=(uint8_t)((m%100)/10);
		*rmsptr =*rmsptr<<4;
		*rmsptr |=(uint8_t)((m%10));
	}
	else
	{
		m =rmsval>>8;		//it is interger
		*rmsptr =(m%100000)/10000;
		*rmsptr =*rmsptr<<4;
		*rmsptr |=(m%10000)/1000;
		*rmsptr =*rmsptr<<4;
		*rmsptr |=(m%1000)/100;
		*rmsptr =*rmsptr<<4;
		*rmsptr |=(m%100)/10;
		*rmsptr =*rmsptr<<4;
		*rmsptr |=(m%10);
		
		m =((rmsval%256)*1000);	//it is decimal
		*rmsptr =*rmsptr<<4;
		*rmsptr |=(m>>8)/100;
		*rmsptr =*rmsptr<<4;
		*rmsptr |=((m>>8)%100)/10;
		*rmsptr =*rmsptr<<4;
		*rmsptr |=((m>>8)%10);
	}		
}
//=========================================================
//decription	::	calculate power factor
//function		::	Calculate_PowerFactor
//Input			::	rmsptr rmsval
//Output		::	rmptr->   (x.xxx ) 
//call			::	none
//effect		::	
//=========================================================
void	Calculate_PowerFactor( uint32_t *rmsptr,uint32_t rmsval )
{
	uint32_t	m;

	m =(rmsval&0x7FFF);
	*rmsptr =(m%10000)/1000;
	*rmsptr =*rmsptr<<4;
	*rmsptr |=(m%1000)/100;
	*rmsptr =*rmsptr<<4;
	*rmsptr |=(m%100)/10;
	*rmsptr =*rmsptr<<4;
	*rmsptr |=(m%10);
}
//=========================================================
//decription	::	calculate frequence
//function		::	Calculate_Frequency
//Input			::	rmsptr rmsval
//Output		::	rmsptr-> (xx.xx )
//return		::	1:success,3:failed
//call			::	none
//effect		::	
//=========================================================
uint32_t	Calculate_Frequency( uint32_t *rmsptr,uint32_t rmsval )
{
	uint32_t	m;
	m =rmsval;

	*rmsptr =(m%10000)/1000;
	*rmsptr =*rmsptr<<4;
	*rmsptr |=(m%1000)/100;
	*rmsptr =*rmsptr<<4;
	*rmsptr |=(m%100)/10;
	*rmsptr =*rmsptr<<4;
	*rmsptr |=(m%10);

	return(1);
}
//=========================================================
//decription	::	calculate thdnx
//function		::	Calculate_THDNx
//Input			::	rmsptr rmsval
//Output		::	rmsptr-> (xxxx.xxxx )
//return		::	1:success,3:failed 
//call			::	none
//effect		::	
//=========================================================
uint32_t	Calculate_THDNx( uint32_t *rmsptr,uint32_t rmsval )
{
	uint32_t	m;
	m =rmsval*100;
    
    *rmsptr =(m%100000000)/10000000;
	*rmsptr =*rmsptr<<4;
	*rmsptr |=(m%10000000)/1000000;
    *rmsptr =*rmsptr<<4;
	*rmsptr |=(m%1000000)/100000;
	*rmsptr =*rmsptr<<4;
	*rmsptr |=(m%100000)/10000;
	*rmsptr =*rmsptr<<4;
	*rmsptr |=(m%10000)/1000;
	*rmsptr =*rmsptr<<4;
	*rmsptr |=(m%1000)/100;
	*rmsptr =*rmsptr<<4;
	*rmsptr |=(m%100)/10;
	*rmsptr =*rmsptr<<4;
	*rmsptr |=(m%10);
	
	return(1);
}
//=========================================================
//decription	::	calculate angle
//function		::	Calculate_angle
//Input			::	rmsptr rmsval
//Output		::	rmsptr-> (xxx.x ) 
//call			::	none
//effect		::	
//=========================================================
void	Calculate_angle( uint32_t *rmsptr,uint32_t rmsval )
{
	uint32_t	m;

	m =rmsval&0x7FFF;
	
	*rmsptr =(m%10000)/1000;
	*rmsptr =*rmsptr<<4;
	*rmsptr |=(m%1000)/100;
	*rmsptr =*rmsptr<<4;
	*rmsptr |=(m%100)/10;
	*rmsptr =*rmsptr<<4;
	*rmsptr |=(m%10);	
}
//=========================================================
//decription	::	calculate voltage or current peak
//function		::	Calculate_V_I_Peak
//Input			::	rmsptr rmsval regid
//Output		::	rmsptr->  (xxxx ) V/A
//return		::	1:success,3:failed
//call			::	Read_AFE_1Reg
//effect		::	
//result :: V_peak=rmsval*UxGain/100*2^13
//			I_peak=rmsval*IxGain/1000*2^13
//=========================================================
uint32_t	Calculate_V_I_Peak( uint32_t *rmsptr,uint32_t rmsval,uint32_t regid )
{
	uint32_t	val;
	uint16_t	reg_addr,ratio=0;
	switch(regid)
	{
		case	Ua:
		{
			reg_addr =P3_UGainA;
			ratio =100;
		}
		break;
		case	Ub:
		{
			reg_addr =P3_UGainB;
			ratio =100;
		}
		break;
		case	Uc:
		{
			reg_addr =P3_UGainC;
			ratio =100;
		}
		break;
		case	Ia:
		{
			reg_addr =P3_IGainA;
			ratio =1000;
		}
		break;
		case	Ib:
		{
			reg_addr =P3_IGainB;
			ratio =1000;
		}
		break;
		case	Ic:
		{
			reg_addr =P3_IGainC;
			ratio =1000;
		}
		break;
		
	}
	if(ratio ==100 || ratio ==1000)
	{		
		val =Read_AFE_1Reg(reg_addr);
		val =val*rmsval;
		val =val>>13;
		val =val/ratio;
	
		*rmsptr =(val%100000)/10000;
		*rmsptr =*rmsptr<<4;
		*rmsptr |=(val%1000)/100;
		*rmsptr =*rmsptr<<4;
		*rmsptr |=(val%100)/10;
		*rmsptr =*rmsptr<<4;
		*rmsptr |=(val%10);
		
		return(1);
	}
	else
	{
		*rmsptr =0;
		return(3);
	}		
}
//=========================================================
//decription	::	calculate current or voltage harmonic ratio
//function		::	Calculate_I_V_HarmonicRatio
//Input			::	reg_addr
//Output		::	current or voltage harmonic ratio
//call			::	Read_AFE_1Reg
//effect		::	
//=========================================================
uint32_t	Calculate_I_V_HarmonicRatio( uint16_t reg_addr )
{
	uint32_t	val;
	val =Read_AFE_1Reg(reg_addr);
	val =val*100;
	val =val>>14;
	return (val);		
}
//=========================================================
//decription	::	calculate current or voltage fundaamental 
//function		::	Calculate_I_V_Fundamental
//Input			::	reg_addr,scale
//Output		::	current or voltage harmonic ratio
//call			::	Read_AFE_1Reg
//effect		::	
//=========================================================
float	Calculate_I_V_Fundamental( uint16_t reg_addr,uint16_t scale )
{
	float	val;
	val =3.2656;	
	val =val*Read_AFE_1Reg(reg_addr);	
	val =val/scale;	
	return (val);		
}
//=========================================================
//decription	::	measure rms 
//function		::	Measure_RMS
//Input			::	ptr,rms_id
//Output		::	measure result save into ptr point dada
//return		::	1:success,2:data is negative,3:failed
//call			::	Read_AFE_1Reg,Rd_Measure_Parameter,...
//effect		::	
//=========================================================
uint32_t	Measure_RMS( uint32_t *ptr,const RMS_TYPE rms_id )
{
	uint32_t	val;
	uint32_t	error_type;
//	uint32_t	*ptr;
	error_type =3;	//measure is failed
	if( VAFE.measure_en_timer !=0 )
	{
		VAFE.measure_en_timer--;
		return( error_type );
	}
	switch( rms_id)
	{
		case	Ua:
		{
			if(VAFE.id==AT90E36 || VAFE.id==AT90E36A 
				||VAFE.id==AT90E32 || VAFE.id==AT90E32A || VAFE.id==AT90E32AS)
			{
				val =Rd_Measure_Parameter((uint16_t)P3_UrmsA,(uint16_t)P3_UrmsALSB);
				val =val>>8;
				//val =val*VAFE.ulscal.BIT.U_SCALE;
				val =Calculate_V_I_Mul_Scal(val,VAFE.ulscal.BIT.U_SCALE);
				//ptr =&VAFE.RMS[Ua];      
                error_type =Calculate_V_I_RMS( ptr,val);				
			}
			if( (VAFE.id==AT90E25) || (VAFE.id==AT90E24) || (VAFE.id==AT90E23) )
			{
				val =Read_AFE_1Reg(Urms);
				//val =val*VAFE.ulscal.BIT.U_SCALE;
				val =Calculate_V_I_Mul_Scal(val,VAFE.ulscal.BIT.U_SCALE);
				val =val<<8;		//*256
				//ptr =&VAFE.RMS[Ua];      
                error_type =Calculate_V_I_RMS( ptr,val);
			}
		}
		break;
		case	Ub:
		{
			if(VAFE.id==AT90E36 || VAFE.id==AT90E36A 
				||VAFE.id==AT90E32 || VAFE.id==AT90E32A || VAFE.id==AT90E32AS)
			{
				val =Rd_Measure_Parameter((uint16_t)P3_UrmsB,(uint16_t)P3_UrmsBLSB);
				val =val>>8;
				//val =val*VAFE.ulscal.BIT.U_SCALE;
				val =Calculate_V_I_Mul_Scal(val,VAFE.ulscal.BIT.U_SCALE);
				//ptr =&VAFE.RMS[Ub];
				error_type =Calculate_V_I_RMS( ptr,val);
			}							
		}
		break;
		case	Uc:
		{
			if(VAFE.id==AT90E36 || VAFE.id==AT90E36A 
				||VAFE.id==AT90E32 || VAFE.id==AT90E32A || VAFE.id==AT90E32AS)
			{
				val =Rd_Measure_Parameter((uint16_t)P3_UrmsC,(uint16_t)P3_UrmsCLSB);
				val =val>>8;
				//val =val*VAFE.ulscal.BIT.U_SCALE;
				val =Calculate_V_I_Mul_Scal(val,VAFE.ulscal.BIT.U_SCALE);
				//ptr =&VAFE.RMS[Uc];
				error_type =Calculate_V_I_RMS( ptr,val);
			}							
		}
		break;		
		case	Ia:
		{
			if(VAFE.id==AT90E36 || VAFE.id==AT90E36A 
				||VAFE.id==AT90E32 || VAFE.id==AT90E32A || VAFE.id==AT90E32AS)
			{
				val =Rd_Measure_Parameter((uint16_t)P3_IrmsA,(uint16_t)P3_IrmsALSB);
				val =val>>8;
				//val =val*VAFE.ulscal.BIT.I_SCALE;
				val =Calculate_V_I_Mul_Scal(val,VAFE.ulscal.BIT.I_SCALE);
				//ptr =&VAFE.RMS[Ia];
				error_type =Calculate_V_I_RMS( ptr,val);
			}
			if( (VAFE.id==AT90E25) || (VAFE.id==AT90E24) || (VAFE.id==AT90E23) )
			{
				val =Read_AFE_1Reg(Irms);
				//val =val*VAFE.ulscal.BIT.I_SCALE;
				val =Calculate_V_I_Mul_Scal(val,VAFE.ulscal.BIT.I_SCALE);
				val =val<<8;		//*256
				//ptr =&VAFE.RMS[Ia];      
                error_type =Calculate_V_I_RMS( ptr,val);
			}
		}
		break;
		case	Ib:
		{
			if(VAFE.id==AT90E36 || VAFE.id==AT90E36A 
				||VAFE.id==AT90E32 || VAFE.id==AT90E32A || VAFE.id==AT90E32AS)
			{
				val =Rd_Measure_Parameter((uint16_t)P3_IrmsB,(uint16_t)P3_IrmsBLSB);				
				val =val>>8;
				val =Calculate_V_I_Mul_Scal(val,VAFE.ulscal.BIT.I_SCALE);
				//ptr =&VAFE.RMS[Ib];
				error_type =Calculate_V_I_RMS( ptr,val);
			}							
		}
		break;
		case	Ic:
		{
			if(VAFE.id==AT90E36 || VAFE.id==AT90E36A 
				||VAFE.id==AT90E32 || VAFE.id==AT90E32A || VAFE.id==AT90E32AS)
			{
				val =Rd_Measure_Parameter((uint16_t)P3_IrmsC,(uint16_t)P3_IrmsCLSB);
				val =val>>8;			
				val =Calculate_V_I_Mul_Scal(val,VAFE.ulscal.BIT.I_SCALE);
				//ptr =&VAFE.RMS[Ic];
				error_type =Calculate_V_I_RMS( ptr,val);
			}			
		}
		break;
		case	In:
		{
			if(VAFE.id==AT90E36 || VAFE.id==AT90E36A 
				||VAFE.id==AT90E32 || VAFE.id==AT90E32A || VAFE.id==AT90E32AS)
			{
				val	=Read_AFE_1Reg((uint16_t)P3_IrmsN0);				
				//val =val*VAFE.ulscal.BIT.I_SCALE;
				val =Calculate_V_I_Mul_Scal(val,VAFE.ulscal.BIT.I_SCALE);
				val =val<<8;		//*256
				//ptr =&VAFE.RMS[In];
				error_type =Calculate_V_I_RMS( ptr,val);
			}
			if( (VAFE.id==AT90E25) || (VAFE.id==AT90E24) || (VAFE.id==AT90E23) )
			{
				val =Read_AFE_1Reg(Irms2);
				//val =val*VAFE.ulscal.BIT.I_SCALE;
				val =Calculate_V_I_Mul_Scal(val,VAFE.ulscal.BIT.I_SCALE);				
				val =val<<8;	//*256
				//ptr =&VAFE.RMS[In];      
                error_type =Calculate_V_I_RMS( ptr,val);
			}
		}
		break;
		case	Pt:
		{			
			if(VAFE.id==AT90E36 || VAFE.id==AT90E36A 
				||VAFE.id==AT90E32 || VAFE.id==AT90E32A || VAFE.id==AT90E32AS)
			{			
				val =Rd_Measure_Parameter((uint16_t)P3_PmeanT,(uint16_t)P3_PmeanTLSB);			
				if((val&0x80000000)==0x80000000)
				{
					val = (~val)+1;
					error_type =2;
					VAFE.sagstatus.BIT.PTDir =1;
				}
				else
				{
					error_type =1;
					VAFE.sagstatus.BIT.PTDir =0;
				}
				if(VAFE.id!=AT90E32AS)
				{
					val =val>>6;		//*4
				}							
				val =Calculate_V_I_Mul_Scal(val,VAFE.ulscal.BIT.I_SCALE);
				val =Calculate_V_I_Mul_Scal(val,VAFE.ulscal.BIT.U_SCALE);
				//ptr =&VAFE.RMS[Pt];
				Calculate_Power( ptr,val );
			}			
		}
		break;	
		case	Pa:
		{
			if(VAFE.id==AT90E36 || VAFE.id==AT90E36A 
				||VAFE.id==AT90E32 || VAFE.id==AT90E32A || VAFE.id==AT90E32AS)
			{			
				val =Rd_Measure_Parameter((uint16_t)P3_PmeanA,(uint16_t)P3_PmeanALSB);			
				if((val&0x80000000)==0x80000000)
				{
					val = (~val)+1;
					error_type =2;
				}
				else
				{
					error_type =1;
				}
                if(VAFE.id!=AT90E32AS)
				{
					val =val>>8;		//
				}
				val =Calculate_V_I_Mul_Scal(val,VAFE.ulscal.BIT.I_SCALE);
				val =Calculate_V_I_Mul_Scal(val,VAFE.ulscal.BIT.U_SCALE);
				//ptr =&VAFE.RMS[Pa];
				Calculate_Power( ptr,val );
			}
			if( (VAFE.id==AT90E25) || (VAFE.id==AT90E24) || (VAFE.id==AT90E23) )
			{
				val =Read_AFE_1Reg(Pmean);
				if((val&0x8000)==0x8000)
				{
					val = (~val)+1;
					error_type =2;
					VAFE.sagstatus.BIT.PTDir =1;
				}
				else
				{
					error_type =1;
					VAFE.sagstatus.BIT.PTDir =0;
				}
				val =(val&0x7FFF);
				val =val<<8;	//*256
				val =Calculate_V_I_Mul_Scal(val,VAFE.ulscal.BIT.I_SCALE);
				val =Calculate_V_I_Mul_Scal(val,VAFE.ulscal.BIT.U_SCALE);
				//ptr =&VAFE.RMS[In];      
                Calculate_Power( ptr,val);
			}								
		}
		break;
		case	Pb:
		{
			if(VAFE.id==AT90E36 || VAFE.id==AT90E36A 
				||VAFE.id==AT90E32 || VAFE.id==AT90E32A || VAFE.id==AT90E32AS)
			{			
				val =Rd_Measure_Parameter((uint16_t)P3_PmeanB,(uint16_t)P3_PmeanBLSB);			
				if((val&0x80000000)==0x80000000)
				{
					val = (~val)+1;					
					error_type =2;
				}
				else
				{
					error_type =1;
				}
                if(VAFE.id!=AT90E32AS)
				{
					val =val>>8;		//
				}
				val =Calculate_V_I_Mul_Scal(val,VAFE.ulscal.BIT.I_SCALE);
				val =Calculate_V_I_Mul_Scal(val,VAFE.ulscal.BIT.U_SCALE);
				//ptr =&VAFE.RMS[Pb];
				Calculate_Power( ptr,val );	
			}			
		}		
		break;
		case	Pn:
		{			
			if( (VAFE.id==AT90E25) || (VAFE.id==AT90E24) || (VAFE.id==AT90E23) )
			{
				val =Read_AFE_1Reg(Pmean2);
				if((val&0x8000)==0x8000)
				{
					val = (~val)+1;
					error_type =2;
				}
				else
				{
					error_type =1;
				}
				val =(val&0x7FFF);
				val =val<<8;	//*256
				val =Calculate_V_I_Mul_Scal(val,VAFE.ulscal.BIT.I_SCALE);
				val =Calculate_V_I_Mul_Scal(val,VAFE.ulscal.BIT.U_SCALE);				
				//ptr =&VAFE.RMS[Pn];      
                Calculate_Power( ptr,val);
			}
		}
		break;
		case	Pc:
		{
			if(VAFE.id==AT90E36 || VAFE.id==AT90E36A 
				||VAFE.id==AT90E32 || VAFE.id==AT90E32A || VAFE.id==AT90E32AS)
			{			
				val =Rd_Measure_Parameter((uint16_t)P3_PmeanC,(uint16_t)P3_PmeanCLSB);			
				if((val&0x80000000)==0x80000000)
				{
					val = (~val)+1;
					error_type =2;
				}
				else
				{
					error_type =1;
				}
                if(VAFE.id!=AT90E32AS)
				{
					val =val>>8;		//
				}
				val =Calculate_V_I_Mul_Scal(val,VAFE.ulscal.BIT.I_SCALE);
				val =Calculate_V_I_Mul_Scal(val,VAFE.ulscal.BIT.U_SCALE);
				//ptr =&VAFE.RMS[Pc];
				Calculate_Power( ptr,val );				
			}									
		}
		break;
		case	Qt:
		{
			if(VAFE.id==AT90E36 || VAFE.id==AT90E36A 
				||VAFE.id==AT90E32 || VAFE.id==AT90E32A || VAFE.id==AT90E32AS)
			{			
				val =Rd_Measure_Parameter((uint16_t)P3_QmeanT,(uint16_t)P3_QmeanTLSB);			
				if((val&0x80000000)==0x80000000)
				{
					val = (~val)+1;
					error_type =2;
					VAFE.sagstatus.BIT.QTDir =1;
				}
				else
				{
					error_type =1;
					VAFE.sagstatus.BIT.QTDir =0;
				}
                if(VAFE.id!=AT90E32AS)
				{
					val =val>>6;		//*4
				}
				//else
				//{
				//	val =val<<2;		//*4
				//}
				val =Calculate_V_I_Mul_Scal(val,VAFE.ulscal.BIT.I_SCALE);
				val =Calculate_V_I_Mul_Scal(val,VAFE.ulscal.BIT.U_SCALE);
				//ptr =&VAFE.RMS[Qt];
				Calculate_Power( ptr,val );
			}		
		}
		break;		
		case	Qa:
		{
			if(VAFE.id==AT90E36 || VAFE.id==AT90E36A 
				||VAFE.id==AT90E32 || VAFE.id==AT90E32A || VAFE.id==AT90E32AS)
			{			
				val =Rd_Measure_Parameter((uint16_t)P3_QmeanA,(uint16_t)P3_QmeanALSB);			
				if((val&0x80000000)==0x80000000)
				{
					val = (~val)+1;
					error_type =2;
				}
				else
				{
					error_type =1;
				}
                if(VAFE.id!=AT90E32AS)
				{
					val =val>>8;		//
				}
				val =Calculate_V_I_Mul_Scal(val,VAFE.ulscal.BIT.I_SCALE);
				val =Calculate_V_I_Mul_Scal(val,VAFE.ulscal.BIT.U_SCALE);
				//ptr =&VAFE.RMS[Qa];
				Calculate_Power( ptr,val );
			}			
			if( (VAFE.id==AT90E25) || (VAFE.id==AT90E24) || (VAFE.id==AT90E23) )
			{
				val =Read_AFE_1Reg(Qmean);
				if((val&0x8000)==0x8000)
				{
					val = ~val;
					error_type =2;
					VAFE.sagstatus.BIT.QTDir =1;
				}
				else
				{
					error_type =1;
					VAFE.sagstatus.BIT.QTDir =0;
				}
				val &=0x7FFF;
				val =val<<8;	//*256
				val =Calculate_V_I_Mul_Scal(val,VAFE.ulscal.BIT.I_SCALE);
				val =Calculate_V_I_Mul_Scal(val,VAFE.ulscal.BIT.U_SCALE);
				//ptr =&VAFE.RMS[Qa];      
                Calculate_Power( ptr,val);
			}		
		}
		break;
		case	Qb:
		{
			if(VAFE.id==AT90E36 || VAFE.id==AT90E36A 
				||VAFE.id==AT90E32 || VAFE.id==AT90E32A || VAFE.id==AT90E32AS)
			{			
				val =Rd_Measure_Parameter((uint16_t)P3_QmeanB,(uint16_t)P3_QmeanBLSB);			
				if((val&0x80000000)==0x80000000)
				{
					val = (~val)+1;
					error_type =2;
				}
				else
				{
					error_type =1;
				}
                if(VAFE.id!=AT90E32AS)
				{
					val =val>>8;		//
				}
				val =Calculate_V_I_Mul_Scal(val,VAFE.ulscal.BIT.I_SCALE);
				val =Calculate_V_I_Mul_Scal(val,VAFE.ulscal.BIT.U_SCALE);
				//ptr =&VAFE.RMS[Qb];
				Calculate_Power( ptr,val );				
			}			
		}
		break;
		case	Qn:
		{			
			if( (VAFE.id==AT90E25) || (VAFE.id==AT90E24) || (VAFE.id==AT90E23) )
			{
				val =Read_AFE_1Reg(Qmean2);
				if((val&0x8000)==0x8000)
				{
					val = (~val)+1;
					error_type =2;
				}
				else
				{
					error_type =1;
				}
				val &=0x7FFF;
				val =val<<8;	//*256
				val =Calculate_V_I_Mul_Scal(val,VAFE.ulscal.BIT.I_SCALE);
				val =Calculate_V_I_Mul_Scal(val,VAFE.ulscal.BIT.U_SCALE);
				//ptr =&VAFE.RMS[Qn];      
                Calculate_Power( ptr,val);
			}
		}
		break;
		case	Qc:
		{
			if(VAFE.id==AT90E36 || VAFE.id==AT90E36A 
				||VAFE.id==AT90E32 || VAFE.id==AT90E32A || VAFE.id==AT90E32AS)
			{			
				val =Rd_Measure_Parameter((uint16_t)P3_QmeanC,(uint16_t)P3_QmeanCLSB);			
				if((val&0x80000000)==0x80000000)
				{
					val = (~val)+1;
					error_type =2;
				}
				else
				{
					error_type =1;
				}
                if(VAFE.id!=AT90E32AS)
				{
					val =val>>8;		//
				}
				val =Calculate_V_I_Mul_Scal(val,VAFE.ulscal.BIT.I_SCALE);
				val =Calculate_V_I_Mul_Scal(val,VAFE.ulscal.BIT.U_SCALE);
				//ptr =&VAFE.RMS[Qc];
				Calculate_Power( ptr,val );				
			}					
		}
		break;
		case	SAt:
		{
			if(VAFE.id==AT90E36 || VAFE.id==AT90E36A 
				||VAFE.id==AT90E32 || VAFE.id==AT90E32A || VAFE.id==AT90E32AS)
			{			
				val =Rd_Measure_Parameter((uint16_t)P3_SAmeanT,(uint16_t)P3_SAmeanTLSB);			
				if((val&0x80000000)==0x80000000)
				{
					val = (~val)+1;
					error_type =2;
				}
				else
				{
					error_type =1;
				}
                if(VAFE.id!=AT90E32AS)
				{
					val =val>>6;		//*4
				}
				val =Calculate_V_I_Mul_Scal(val,VAFE.ulscal.BIT.I_SCALE);
				val =Calculate_V_I_Mul_Scal(val,VAFE.ulscal.BIT.U_SCALE);
				//ptr =&VAFE.RMS[SAt];
				Calculate_Power( ptr,val );				
			}									
		}
		break;
		case	SVt:
		{
			if(VAFE.id==AT90E36 || VAFE.id==AT90E36A)
			{			
				val =Rd_Measure_Parameter((uint16_t)P3_SVmeanT,(uint16_t)P3_SVmeanTLSB);
				if( (val&0x80000000) ==0x80000000)
				{
					val =(~val)+1;
					error_type =2;
				}
				else
				{
					error_type =1;
				}
				val =val>>14;		//val=val*(4/65536)
                //val =val*VAFE.ulscal.BIT.I_SCALE;
				val =Calculate_V_I_Mul_Scal(val,VAFE.ulscal.BIT.I_SCALE);
				val =Calculate_V_I_Mul_Scal(val,VAFE.ulscal.BIT.U_SCALE);
				*ptr =(val%100000000)/10000000;		// (xxxxx.xxx) VA
				*ptr =*ptr <<4;
				*ptr |=(val%10000000)/1000000;
				*ptr =*ptr <<4;
				*ptr |=(val%1000000)/100000;
				*ptr =*ptr <<4;
				*ptr |=(val%100000)/10000;
				*ptr =*ptr <<4;
				*ptr |=(val%10000)/1000;
				*ptr =*ptr <<4;
				*ptr |=(val%1000)/100;
				*ptr =*ptr <<4;
				*ptr |=(val%100)/10;
				*ptr =*ptr <<4;
				*ptr |=(val%10);				
							
			}											
		}
		break;
		case	Sa:
		{
			if(VAFE.id==AT90E36 || VAFE.id==AT90E36A 
				||VAFE.id==AT90E32 || VAFE.id==AT90E32A || VAFE.id==AT90E32AS)
			{			
				val =Rd_Measure_Parameter((uint16_t)P3_SmeanA,(uint16_t)P3_SmeanALSB);			
				if((val&0x80000000)==0x80000000)
				{
					val = (~val)+1;
					error_type =2;
				}
				else
				{
					error_type =1;
				}
                if(VAFE.id!=AT90E32AS)
				{
					val =val>>8;		//
				}
				val =Calculate_V_I_Mul_Scal(val,VAFE.ulscal.BIT.I_SCALE);
				val =Calculate_V_I_Mul_Scal(val,VAFE.ulscal.BIT.U_SCALE);
				//ptr =&VAFE.RMS[Sa];
				Calculate_Power( ptr,val );	
			}
			if( (VAFE.id==AT90E25) || (VAFE.id==AT90E24) || (VAFE.id==AT90E23) )
			{
				val =Read_AFE_1Reg(Smean);
				if((val&0x8000)==0x8000)
				{
					val = (~val)+1;
					error_type =2;
				}
				else
				{
					error_type =1;
				}
				val =(val&0x7FFF);
				val =val<<8;	//*256
				val =Calculate_V_I_Mul_Scal(val,VAFE.ulscal.BIT.I_SCALE);
				val =Calculate_V_I_Mul_Scal(val,VAFE.ulscal.BIT.U_SCALE);
				//ptr =&VAFE.RMS[Sa];      
                Calculate_Power( ptr,val);
			}
		}
		break;
		case	Sb:
		{
			if(VAFE.id==AT90E36 || VAFE.id==AT90E36A 
				||VAFE.id==AT90E32 || VAFE.id==AT90E32A || VAFE.id==AT90E32AS)
			{			
				val =Rd_Measure_Parameter((uint16_t)P3_SmeanB,(uint16_t)P3_SmeanBLSB);			
				if((val&0x80000000)==0x80000000)
				{
					val = (~val)+1;
					error_type =2;
				}
				else
				{
					error_type =1;
				}
                if(VAFE.id!=AT90E32AS)
				{
					val =val>>8;		//
				}	
				val =Calculate_V_I_Mul_Scal(val,VAFE.ulscal.BIT.I_SCALE);
				val =Calculate_V_I_Mul_Scal(val,VAFE.ulscal.BIT.U_SCALE);
				//ptr =&VAFE.RMS[Sb];
				Calculate_Power( ptr,val );
			}
		}
		break;
		case	Sn:
		{
			if( (VAFE.id==AT90E25) || (VAFE.id==AT90E24) || (VAFE.id==AT90E23) )
			{
				val =Read_AFE_1Reg(Smean2);
				if((val&0x8000)==0x8000)
				{
					val = (~val)+1;
					error_type =2;
				}
				else
				{
					error_type =1;
				}
				val =(val&0x7FFF);
				val =val<<8;	//*256
				val =Calculate_V_I_Mul_Scal(val,VAFE.ulscal.BIT.I_SCALE);
				val =Calculate_V_I_Mul_Scal(val,VAFE.ulscal.BIT.U_SCALE);
				//ptr =&VAFE.RMS[Sn];      
                Calculate_Power( ptr,val);
			}
		}
		break;
		case	Sc:
		{
			if(VAFE.id==AT90E36 || VAFE.id==AT90E36A 
				||VAFE.id==AT90E32 || VAFE.id==AT90E32A || VAFE.id==AT90E32AS)
			{			
				val =Rd_Measure_Parameter((uint16_t)P3_SmeanC,(uint16_t)P3_SmeanCLSB);			
				if((val&0x80000000)==0x80000000)
				{
					val = (~val)+1;
					error_type =2;
				}
				else
				{
					error_type =1;
				}
                if(VAFE.id!=AT90E32AS)
				{
					val =val>>8;		//
				}
				val =Calculate_V_I_Mul_Scal(val,VAFE.ulscal.BIT.I_SCALE);
				val =Calculate_V_I_Mul_Scal(val,VAFE.ulscal.BIT.U_SCALE);
				//ptr =&VAFE.RMS[Sc];
				Calculate_Power( ptr,val );	
			}								
		}
		break;
		case	PFt:
		{
			if(VAFE.id==AT90E36 || VAFE.id==AT90E36A 
				||VAFE.id==AT90E32 || VAFE.id==AT90E32A || VAFE.id==AT90E32AS)
			{			
				val	=Read_AFE_1Reg((uint16_t)P3_PFmeanT);
				if( (val&0x8000)==0x8000 )
				{					
					val = (~val)+1;
					error_type =2;
				}
				else
				{
					error_type =1;
				}				
				val =(val &0x7FFF);				
				//ptr =&VAFE.RMS[PFt];
				Calculate_PowerFactor( ptr,val );
			}			
		}
		break;
		case	PFa:
		{
			if(VAFE.id==AT90E36 || VAFE.id==AT90E36A 
				||VAFE.id==AT90E32 || VAFE.id==AT90E32A || VAFE.id==AT90E32AS)
			{			
				val	=Read_AFE_1Reg((uint16_t)P3_PFmeanA);
				if( (val&0x8000)==0x8000 )
				{					
					val = (~val)+1;
					error_type =2;
				}
				else
				{
					error_type =1;
				}
				val =(val &0x7FFF);
				//ptr =&VAFE.RMS[PFa];
				Calculate_PowerFactor( ptr,val );
			}
			if( (VAFE.id==AT90E25) || (VAFE.id==AT90E24) || (VAFE.id==AT90E23) )
			{
				val	=Read_AFE_1Reg((uint16_t)PowerF);
				if( (val&0x8000)==0x8000 )
				{					
					val = (~val)+1;
					error_type =2;
				}
				else
				{
					error_type =1;
				}				
				val =(val &0x7FFF);
				//ptr =&VAFE.RMS[PFa];
				Calculate_PowerFactor( ptr,val );
			}
		}
		break;
		case	PFb:
		{
			if(VAFE.id==AT90E36 || VAFE.id==AT90E36A 
				||VAFE.id==AT90E32 || VAFE.id==AT90E32A || VAFE.id==AT90E32AS)
			{			
				val	=Read_AFE_1Reg((uint16_t)P3_PFmeanB);
				if( (val&0x8000)==0x8000 )
				{					
					val = (~val)+1;
					error_type =2;
				}
				else
				{
					error_type =1;
				}
				val =(val &0x7FFF);
				//ptr =&VAFE.RMS[PFb];
				Calculate_PowerFactor( ptr,val );
			}												
		}
		break;
		case	PFn:
		{
			if( (VAFE.id==AT90E25) || (VAFE.id==AT90E24) || (VAFE.id==AT90E23) )
			{			
				val	=Read_AFE_1Reg((uint16_t)PowerF2);
				if( (val&0x8000)==0x8000 )
				{					
					val = (~val)+1;
					error_type =2;
				}
				else
				{
					error_type =1;
				}				
				val =(val &0x7FFF);	
				//ptr =&VAFE.RMS[PFn];
				Calculate_PowerFactor( ptr,val );
			}												
		}
		break;
		case	PFc:
		{
			if(VAFE.id==AT90E36 || VAFE.id==AT90E36A 
				||VAFE.id==AT90E32 || VAFE.id==AT90E32A || VAFE.id==AT90E32AS)
			{			
				val	=Read_AFE_1Reg((uint16_t)P3_PFmeanC);
				if( (val&0x8000)==0x8000 )
				{					
					val = (~val)+1;
					error_type =2;
				}
				else
				{
					error_type =1;
				}				
				val =(val &0x7FFF);
				//ptr =&VAFE.RMS[PFc];
				Calculate_PowerFactor( ptr,val );
			}										
		}
		break;			
		case	Frq:
		{
			if(VAFE.id==AT90E36 || VAFE.id==AT90E36A 
				||VAFE.id==AT90E32 || VAFE.id==AT90E32A || VAFE.id==AT90E32AS)
			{			
				val	=Read_AFE_1Reg((uint16_t)P3_Freq);
				error_type =1;
				//ptr =&VAFE.RMS[Frq];
				Calculate_Frequency( ptr,val );
			}
			if( (VAFE.id==AT90E25) || (VAFE.id==AT90E24) || (VAFE.id==AT90E23) )
			{			
				val	=Read_AFE_1Reg((uint16_t)Freq);
				error_type =1;
				//ptr =&VAFE.RMS[Frq];
				Calculate_Frequency( ptr,val );
			}
		}
		break;		
		case	Pha:
		{
			if(VAFE.id==AT90E36 || VAFE.id==AT90E36A 
				||VAFE.id==AT90E32 || VAFE.id==AT90E32A || VAFE.id==AT90E32AS )
			{			
				val	=Read_AFE_1Reg((uint16_t)P3_PangleA);
				if( (val&0x8000)==0x8000 )
				{					
					val = (~val)+1;
					error_type =2;
				}
				else
				{
					error_type =1;
				}				
				val =(val &0x7FFF);
				//ptr =&VAFE.RMS[Pha];
				Calculate_angle( ptr,val );
			}			
			if( (VAFE.id==AT90E25) || (VAFE.id==AT90E24) || (VAFE.id==AT90E23) )
			{
				val	=Read_AFE_1Reg((uint16_t)Pangle);
				if( (val&0x8000)==0x8000 )
				{					
					val = (~val)+1;
					error_type =2;
				}
				else
				{
					error_type =1;
				}				
				val =(val &0x7FFF);
				//ptr =&VAFE.RMS[Pha];
				Calculate_angle( ptr,val );
			}
		}
		break;
		case	Phb:
		{
			if(VAFE.id==AT90E36 || VAFE.id==AT90E36A 
				||VAFE.id==AT90E32 || VAFE.id==AT90E32A || VAFE.id==AT90E32AS)
			{			
				val	=Read_AFE_1Reg((uint16_t)P3_PangleB);
				if( (val&0x8000)==0x8000 )
				{					
					val = (~val)+1;
					error_type =2;
				}
				else
				{
					error_type =1;
				}				
				val =(val &0x7FFF);
				//ptr =&VAFE.RMS[Phb];
				Calculate_angle( ptr,val );
			}				
		}
		break;
		case	Phn:
		{
			if( (VAFE.id==AT90E25) || (VAFE.id==AT90E24) || (VAFE.id==AT90E23) )
			{			
				val	=Read_AFE_1Reg((uint16_t)Pangle2);
				if( (val&0x8000)==0x8000 )
				{					
					val = (~val)+1;
					error_type =2;
				}
				else
				{
					error_type =1;
				}				
				val =(val &0x7FFF);
				//ptr =&VAFE.RMS[Phn];
				Calculate_angle( ptr,val );
			}				
		}
		break;
		case	Phc:
		{
			if(VAFE.id==AT90E36 || VAFE.id==AT90E36A 
				||VAFE.id==AT90E32 || VAFE.id==AT90E32A || VAFE.id==AT90E32AS)
			{			
				//val =Rd_Measure_Parameter((uint16_t)P3_PangleC,(uint16_t)P3_PangleC);			
				//val =val>>16;		//
				val	=Read_AFE_1Reg((uint16_t)P3_PangleC);
				if( (val&0x8000)==0x8000 )
				{					
					val = (~val)+1;
					error_type =2;
				}
				else
				{
					error_type =1;
				}				
				val =(val &0x7FFF);
				//ptr =&VAFE.RMS[Phc];
				Calculate_angle( ptr,val );
			}				
		}
		break;
		case	Temperature:
		{
			if(VAFE.id==AT90E36 || VAFE.id==AT90E36A 
				||VAFE.id==AT90E32 || VAFE.id==AT90E32A || VAFE.id==AT90E32AS)
			{			
				//val =Rd_Measure_Parameter((uint16_t)P3_Temp,(uint16_t)P3_Temp);			
				//val =val>>16;		//
				val	=Read_AFE_1Reg((uint16_t)P3_Temp);
				if( (val&0x8000)==0x8000 )
				{					
					val = (~val)+1;
					error_type =2;
				}
				else
				{
					error_type =1;
				}				
				val =(val &0x7FFF);
				//ptr =&VAFE.RMS[Temperature];
				Calculate_angle( ptr,val );
			}				
		}
		break;
		case	UangleA:
		{
			if(VAFE.id==AT90E36 || VAFE.id==AT90E36A 
				||VAFE.id==AT90E32 || VAFE.id==AT90E32A || VAFE.id==AT90E32AS)
			{			
				val	=Read_AFE_1Reg((uint16_t)P3_UangleA);
				if( (val&0x8000)==0x8000 )
				{					
					val = (~val)+1;
					error_type =2;
				}
				else
				{
					error_type =1;
				}				
				val =(val &0x7FFF);
				//ptr =&VAFE.RMS[UangleA];
				Calculate_angle( ptr,val );
			}				
		}
		break;
		case	UangleB:
		{
			if(VAFE.id==AT90E36 || VAFE.id==AT90E36A 
				||VAFE.id==AT90E32 || VAFE.id==AT90E32A || VAFE.id==AT90E32AS)
			{			
				val	=Read_AFE_1Reg((uint16_t)P3_UangleB);
				if( (val&0x8000)==0x8000 )
				{					
					val = (~val)+1;
					error_type =2;
				}
				else
				{
					error_type =1;
				}				
				val =(val &0x7FFF);
				//ptr =&VAFE.RMS[UangleB];
				Calculate_angle( ptr,val );
			}				
		}
		break;
		case	UangleC:
		{
			if(VAFE.id==AT90E36 || VAFE.id==AT90E36A 
				||VAFE.id==AT90E32 || VAFE.id==AT90E32A || VAFE.id==AT90E32AS)
			{			
				val	=Read_AFE_1Reg((uint16_t)P3_UangleC);
				if( (val&0x8000)==0x8000 )
				{					
					val = (~val)+1;
					error_type =2;
				}
				else
				{
					error_type =1;
				}				
				val =(val &0x7FFF);
				//ptr =&VAFE.RMS[UangleC];
				Calculate_angle( ptr,val );
			}				
		}
		break;
		case	THDNUA:
		{
			if(VAFE.id==AT90E36 || VAFE.id==AT90E36A 
				||VAFE.id==AT90E32 || VAFE.id==AT90E32A )
			{			
				val	=Read_AFE_1Reg((uint16_t)P3_THDUA);

				//ptr =&VAFE.RMS[THDNUA];
				error_type =Calculate_THDNx( ptr,val );
			}				
		}
		break;
		case	THDNUB:
		{
			if(VAFE.id==AT90E36 || VAFE.id==AT90E36A 
				||VAFE.id==AT90E32 || VAFE.id==AT90E32A )
			{			
				val	=Read_AFE_1Reg((uint16_t)P3_THDUB);

				//ptr =&VAFE.RMS[THDNUB];
				error_type =Calculate_THDNx( ptr,val );
			}				
		}
		break;
		case	THDNUC:
		{
			if(VAFE.id==AT90E36 || VAFE.id==AT90E36A 
				||VAFE.id==AT90E32 || VAFE.id==AT90E32A )
			{			
				val	=Read_AFE_1Reg((uint16_t)P3_THDUC);

				//ptr =&VAFE.RMS[THDNUC];
				error_type =Calculate_THDNx( ptr,val );
			}				
		}
		break;
		case	THDNIA:
		{
			if(VAFE.id==AT90E36 || VAFE.id==AT90E36A 
				||VAFE.id==AT90E32 || VAFE.id==AT90E32A )
			{			
				val	=Read_AFE_1Reg((uint16_t)P3_THDIA);

				//ptr =&VAFE.RMS[THDNIA];
				error_type =Calculate_THDNx( ptr,val );
			}				
		}
		break;
		case	THDNIB:
		{
			if(VAFE.id==AT90E36 || VAFE.id==AT90E36A 
				||VAFE.id==AT90E32 || VAFE.id==AT90E32A )
			{			
				val	=Read_AFE_1Reg((uint16_t)P3_THDIB);

				//ptr =&VAFE.RMS[THDNIB];
				error_type =Calculate_THDNx( ptr,val );
			}				
		}
		break;
		case	THDNIC:
		{
			if(VAFE.id==AT90E36 || VAFE.id==AT90E36A 
				||VAFE.id==AT90E32 || VAFE.id==AT90E32A )
			{			
				val	=Read_AFE_1Reg((uint16_t)P3_THDIC);

				//ptr =&VAFE.RMS[THDNIC];
				error_type =Calculate_THDNx( ptr,val );
			}				
		}
		break;
		case	UPeak_A:
		{
			if(VAFE.id==AT90E32AS)
			{
				val	=Read_AFE_1Reg((uint16_t)P3_UPeakA);	//UPeakA=val*UaGain/100*2^13

				//ptr =&VAFE.RMS[UPeak_A];
				error_type=Calculate_V_I_Peak( ptr,val,Ua );
			}
		}
		break;
		case	UPeak_B:
		{
			if(VAFE.id==AT90E32AS)
			{
				val	=Read_AFE_1Reg((uint16_t)P3_UPeakB);	//UPeakB=val*UbGain/100*2^13

				//ptr =&VAFE.RMS[UPeak_B];
				error_type=Calculate_V_I_Peak( ptr,val,Ub );
			}
		}
		break;
		case	UPeak_C:
		{
			if(VAFE.id==AT90E32AS)
			{
				val	=Read_AFE_1Reg((uint16_t)P3_UPeakC);	//UPeakC=val*UcGain/100*2^13

				//ptr =&VAFE.RMS[UPeak_C];
				error_type=Calculate_V_I_Peak( ptr,val,Uc );
			}
		}
		break;
		case	IPeak_A:
		{
			if(VAFE.id==AT90E32AS)
			{
				val	=Read_AFE_1Reg((uint16_t)P3_IPeakA);	//IPeakA=val*IaGain/1000*2^13

				//ptr =&VAFE.RMS[IPeak_A];
				error_type=Calculate_V_I_Peak( ptr,val,Ia );
			}
		}
		break;
		case	IPeak_B:
		{
			if(VAFE.id==AT90E32AS)
			{
				val	=Read_AFE_1Reg((uint16_t)P3_IPeakB);	//IPeakB=val*IbGain/1000*2^13

				//ptr =&VAFE.RMS[IPeak_B];
				error_type=Calculate_V_I_Peak( ptr,val,Ib );
			}
		}
		break;
		case	IPeak_C:
		{
			if(VAFE.id==AT90E32AS)
			{
				val	=Read_AFE_1Reg((uint16_t)P3_IPeakC);	//IPeakC=val*IcGain/1000*2^13

				//ptr =&VAFE.RMS[IPeak_C];
				error_type=Calculate_V_I_Peak( ptr,val,Ic );
			}
		}
		break;
		
		case	CNFStart:
		{
			if( (VAFE.id !=AT90E25) &&(VAFE.id !=AT90E24) &&(VAFE.id !=AT90E23) && (VAFE.id !=AT90E32AS) )
			{
				val =Read_AFE_1Reg(P3_ConfigStart);
				//ptr =&VAFE.RMS[CNFStart];
				*ptr =(uint8_t)(val>>8);
				*ptr =*ptr<<8;
				*ptr |=(uint8_t)(val);
					
				error_type =1;
			}			
		}
		break;
		case	CALStart:
		{
			val =0;
			if( VAFE.id==AT90E25 || VAFE.id==AT90E24 || VAFE.id==AT90E23 )
			{
				val =Read_AFE_1Reg(CalStart);
			}
			else
			{
				if(VAFE.id!=AT90E32AS)
				{
					val =Read_AFE_1Reg(P3_CalStart);
				}
			}
			//ptr =&VAFE.RMS[CALStart];
			*ptr =(uint8_t)(val>>8);
			*ptr =*ptr<<8;
			*ptr |=(uint8_t)(val);
			
			error_type =1;
		}
		break;
		case	HMStart:
		{
			if( (VAFE.id !=AT90E25) &&(VAFE.id !=AT90E24) &&(VAFE.id !=AT90E23) && (VAFE.id !=AT90E32AS) )
			{
				val =Read_AFE_1Reg(P3_HarmStart);
				//ptr =&VAFE.RMS[HMStart];				
				*ptr =(uint8_t)(val>>8);
				*ptr =*ptr<<8;
				*ptr |=(uint8_t)(val);
			
				error_type =1;
			}
		}
		break;
		case	ADJStart:
		{
			val =0;
			if( VAFE.id==AT90E25 || VAFE.id==AT90E24 || VAFE.id==AT90E23  )
			{
				val =Read_AFE_1Reg(AdjStart);
			}
			else
			{
				if(VAFE.id!=AT90E32AS)
				{
					val =Read_AFE_1Reg(P3_AdjStart);
				}
			}
			//ptr =&VAFE.RMS[ADJStart];
			*ptr =(uint8_t)(val>>8);
			*ptr =*ptr<<8;
			*ptr |=(uint8_t)(val);
			
			error_type =1;
		}
		break;	
		case	SYSStatus0:
		{
			if( VAFE.id==AT90E25 || VAFE.id==AT90E24 || VAFE.id==AT90E23  )
			{
				*ptr =Read_AFE_1Reg(SysStatus);
			}
			else
			{
				if(VAFE.id==AT90E32AS)
				{
					*ptr =Read_AFE_1Reg(P3_2AS_EMMState0);
				}
				else
				{
					*ptr =Read_AFE_1Reg(P3_SysStatus0);
				}
			}
			error_type =1;
		}
		break;
		case	SYSStatus1:
		{
			if(VAFE.id==AT90E32AS)
			{
				*ptr =Read_AFE_1Reg(P3_2AS_EMMState1);
			}
			else
			{
				if( (VAFE.id !=AT90E25) && (VAFE.id !=AT90E24) && (VAFE.id !=AT90E23) )
				{
					*ptr =Read_AFE_1Reg(P3_SysStatus1);
				}
			}
			error_type =1;
		}
		break;
		case	FUNCEn0:
		{
			if( (VAFE.id ==AT90E25) || (VAFE.id ==AT90E24) || (VAFE.id ==AT90E23) )
			{
				val =Read_AFE_1Reg(FuncEn);
			}
			else
			{
				if(VAFE.id==AT90E32AS)
				{
					val =Read_AFE_1Reg(P3_2AS_EMMIntEn0);
				}
				else
				{
					val =Read_AFE_1Reg(P3_FuncEn0);
				}
			}
			*ptr =val;
			error_type =1;
		}
		break;
		case	FUNCEn1:
		{
			if( (VAFE.id !=AT90E25) && (VAFE.id !=AT90E24) && (VAFE.id !=AT90E23) )
			{
				if(VAFE.id==AT90E32AS)
				{
					*ptr =Read_AFE_1Reg(P3_2AS_EMMIntEn1);
				}
				else
				{
					*ptr =Read_AFE_1Reg(P3_FuncEn1);
				}
			}
			error_type =1;
		}
		break;
		
	}
	if( VAFE.id ==0)
	{
		*ptr =0;
	}
	
	return(error_type);
}

//=========================================================
//decription	::	load afe calibration parameter from eeprom 
//function		::	Load_AFE_Cal_Para_From_Eprom
//Input			::	none
//Output		::	none
//call			::	RdE2DataCRC,CMD_Wr_AFE_Reg
//effect		::	VAFE.RMS[x]
//=========================================================
void	Load_AFE_Cal_Para_From_Eprom(void)
{
    uint32_t    i,j;
    uint8_t buff[16];
		
	VAFE.dft_scale.BIT.DFT_AI =1;
	VAFE.dft_scale.BIT.DFT_BI =1;
	VAFE.dft_scale.BIT.DFT_CI =1;
	VAFE.dft_scale.BIT.DFT_AV =1;
	VAFE.dft_scale.BIT.DFT_BV =1;
	VAFE.dft_scale.BIT.DFT_CV =1;
	VAFE.thd_status =IsFailed;
	VAFE.thd_timer =0;
	
	if( (VAFE.id ==AT90E25) || (VAFE.id ==AT90E24) || (VAFE.id ==AT90E23) )
	{
		RdE2DataCRC( E2_AT90E2x_UIScal,(uint8_t *)(&VAFE.ulscal.HFWORD),2 );
	}
	else
	{
		RdE2DataCRC( E2_AT90E3x_UIScal,(uint8_t *)(&VAFE.ulscal.HFWORD),2 );
	}
    if( (VAFE.ulscal.BIT.U_SCALE)>8 )
    {
        VAFE.ulscal.BIT.U_SCALE =4;
    }
    if( (VAFE.ulscal.BIT.I_SCALE)>8 )
    {
        VAFE.ulscal.BIT.I_SCALE =5;
    }  
	
	for(i=0;i<RMS_Num_Max;i++)
	{
		VAFE.RMS[i]=0;
	}
		
	if( (VAFE.id==AT90E25) || (VAFE.id==AT90E24) || (VAFE.id==AT90E23) )
	{	
		for(i=0;i<(AFE90E2x_cmd_reg_E2_NumMax/7);i++)
		{										
			RdE2DataCRC( afe90e2x_cmd_reg_e2adr_tbl[i*7].e2adr,(uint8_t *)(&buff[0]),14 );
			//COPYBYTEDATA((uint8_t *)(&buff[0]),(uint8_t *)(&VAFE.test[0]),14);
            for(j=0;j<7;j++)
			{										
				CMD_Wr_AFE_Reg( (uint8_t *)(&buff[0])+(uint16_t)(j<<1),afe90e2x_cmd_reg_e2adr_tbl[(i*7)+j].regadr );
			}			
		}
		if( (i*7)<AFE90E2x_cmd_reg_E2_NumMax )
		{
			RdE2DataCRC( afe90e2x_cmd_reg_e2adr_tbl[(i<<3)-i].e2adr,(uint8_t *)(&buff[0]),(AFE90E2x_cmd_reg_E2_NumMax-(i*7))<<1 );	
			for(j=0;j<(AFE90E2x_cmd_reg_E2_NumMax-(i*7));j++)
			{										
				CMD_Wr_AFE_Reg( (uint8_t *)(&buff[0])+(uint16_t)(j<<1),afe90e2x_cmd_reg_e2adr_tbl[(i*7)+j].regadr );
			}							
		}		
	}
	else
	{	
        if(VAFE.id==AT90E32AS)
        {
            buff[0]=0xAA;
            buff[1]=0x55;
            CMD_Wr_AFE_Reg(&buff[0],0x7F);
        }
      
		for(i=0;i<(AFE90E3x_cmd_reg_E2_NumMax/8);i++)
		{
			EEPROMreader( afe90e3x_cmd_reg_e2adr_tbl[i*8].e2adr,(uint8_t *)(&buff[0]),16);			
			for(j=0;j<8;j++)
			{										
				CMD_Wr_AFE_Reg( (uint8_t *)(&buff[0])+(uint16_t)(j<<1),afe90e3x_cmd_reg_e2adr_tbl[(i*8)+j].regadr );
			} 
		}
		if( (i*8)<AFE90E3x_cmd_reg_E2_NumMax )
		{
			EEPROMreader( afe90e3x_cmd_reg_e2adr_tbl[(i<<3)].e2adr,(uint8_t *)(&buff[0]),(AFE90E3x_cmd_reg_E2_NumMax-(i*8))<<1);
			for(j=0;j<(AFE90E3x_cmd_reg_E2_NumMax-(i*8));j++)
			{										
				CMD_Wr_AFE_Reg( (uint8_t *)(&buff[0])+(uint16_t)(j<<1),afe90e3x_cmd_reg_e2adr_tbl[(i*8)+j].regadr );
			}																				
		}									
	}
		
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
