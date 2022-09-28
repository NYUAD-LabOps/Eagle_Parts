//===================================================================
#ifndef DISPLAY_H_INCLUDED
#define DISPLAY_H_INCLUDED

#include "compiler.h"

/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
extern "C" {
#endif
/**INDENT-ON**/
/// @endcond

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

typedef	enum
{
	DISPLAY_AFE_TYPE =0,	
	DISPLAY_VA_RMS,
	DISPLAY_VB_RMS,
	DISPLAY_VC_RMS,
	DISPLAY_IA_RMS,
	DISPLAY_IB_RMS,			//5
	DISPLAY_IC_RMS,
	DISPLAY_Ptotal_RMS,
	DISPLAY_PA_RMS,
	DISPLAY_PB_RMS,
	DISPLAY_PC_RMS,			//10
	DISPLAY_Qtotal_RMS,
	DISPLAY_QA_RMS,
	DISPLAY_QB_RMS,
	DISPLAY_QC_RMS,
	DISPLAY_SAtotal_RMS,	//15
	DISPLAY_SVtotal_RMS,
	DISPLAY_SA_RMS,
	DISPLAY_SB_RMS,
	DISPLAY_SC_RMS,
	DISPLAY_PFtotal_RMS,	//20
	DISPLAY_PFA_RMS,
	DISPLAY_PFB_RMS,
	DISPLAY_PFC_RMS,	
	DISPLAY_FREQ_RMS,
	DISPLAY_CNFStart_RMS,	//25
	DISPLAY_CALStart_RMS,
	DISPLAY_HMStart_RMS,
	DISPLAY_ADJStart_RMS,
	DISPLAY_SYSStatus0_RMS,
	DISPLAY_SYSStatus1_RMS,	//30
	DISPLAY_FUNCEN0_RMS,
	DISPLAY_FUNCEN1_RMS,
	
	DISPLAY_TOTAL_ENERGY,
	DISPLAY_TOU1_ENERGY,
	DISPLAY_TOU2_ENERGY,
	DISPLAY_TOU3_ENERGY,
	DISPLAY_TOU4_ENERGY,
	DISPLAY_RTC_TIME,
	DISPLAY_RTC_DATE,	//40
	DISPLAY_TOTAL_MAX_DEMAND,
	DISPLAY_TOU1_MAX_DEMAND,
	DISPLAY_TOU2_MAX_DEMAND,
	DISPLAY_TOU3_MAX_DEMAND,
	DISPLAY_TOU4_MAX_DEMAND,	//44
	
	DISPLAY_VERSION =0xFE,
	DISPLAY_ALL
	
}DISPLAYNUMBER_CONST;

#define	DisplayNumber_Max	(40)

#define	BACKWARD	0x50
#define	FORWARD		0x05

typedef struct 
{
	uint8_t Direct;			// direction 0x50:backword,0x05:forward
	uint8_t Number;			// displaynumber
	uint8_t LpTimer;		// display loop timer
    uint8_t GapTimer;   	// display switch timer
	uint32_t OnOffFlag0;	// display item enable ^x=1 enable,=0 disable
    uint32_t OnOffFlag1;
	//uint8_t Buff[DisplayRam_Max];	// display ram num	
}DISPLAY_Str;

#define DISPLAY_SIZE (sizeof(DISPLAY_Str)/sizeof(uint8_t))
//---------------------variable declare------------------------------
extern	DISPLAY_Str    VDisplay;
//===================================================================
extern	const	uint8_t	DecodeDspTable[];
extern	const	LCD_True_Table_Str	LCD_True_Table[];
extern	const	Digit_Dicode_Str LCDPane_Digit_Table[];
extern	const	uint8_t	LCDPane_To_LCDDrive_Seg_Table[];
extern	const	uint8_t LCDPane_To_LCDDrive_Com_Table[];

void	DisplayPixel( uint8_t * name, uint8_t visible );
void	DisplaySingleDigit(uint8_t digitposit,uint8_t dispval);
void	DisplayText(uint8_t * text);

void	LCD_Disp_init(void);
void	RefreshDisplayNumberProcess(void);
void    RefreshDisplayProcess(void);

void	copybytedatatodispbuff( uint8_t *mptr,uint8_t *sptr,uint8_t len);
uint16_t	display_volt( uint8_t *mptr,uint8_t *sptr );
uint16_t	display_current( uint8_t *mptr,uint8_t *sptr );
uint16_t	display_power( uint8_t *mptr,uint8_t *sptr );
uint16_t	display_p_power( uint8_t *mptr,uint8_t *sptr );
uint16_t	display_q_power( uint8_t *mptr,uint8_t *sptr );
uint16_t	display_s_power( uint8_t *mptr,uint8_t *sptr );
uint16_t	display_pf( uint8_t *mptr,uint8_t *sptr );

void	display_n_digits_k_posit(uint16_t num_posit,uint8_t *ptr);
void	display_units(uint32_t unit);
void    set_slcd_ram(uint32_t pattern);
void    clear_slcd_ram(void);




/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
}
#endif
/**INDENT-ON**/
/// @endcond


#endif /* DISPLAY_H_INCLUDED */
