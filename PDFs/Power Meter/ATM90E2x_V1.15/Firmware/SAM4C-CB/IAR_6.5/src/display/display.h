//===================================================================
#ifndef DISPLAY_z_H_INCLUDED
#define DISPLAY_z_H_INCLUDED

#include "compiler.h"

/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
extern "C" {
#endif
/**INDENT-ON**/
/// @endcond

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
void	UpdataDisplayNumberProcess(void);
void    UpdataDisplayProcess(void);





/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
}
#endif
/**INDENT-ON**/
/// @endcond


#endif /* DISPLAY_H_INCLUDED */
