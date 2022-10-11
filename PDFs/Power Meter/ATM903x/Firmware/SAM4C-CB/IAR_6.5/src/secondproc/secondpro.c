//===================================================================
#include "target.h"
//-------------------------------------------------------------------

//-------------------------------------------------------------------

/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
extern "C" {
#endif
/**INDENT-ON**/
/// @endcond


//===================================================================
//decription    ::  second process
//function      ::  SecondProcess
//input         ::  none
//output        ::  none
//call          ::  Measure_RMS
//effect        ::  none
//===================================================================
void    SecondProcess(void)
{
	uint32_t	val;

		Measure_RMS( &VAFE.RMS[Ua],Ua );
		Measure_RMS( &VAFE.RMS[Ia],Ia );
		Measure_RMS( &VAFE.RMS[In],In );
		Measure_RMS( &VAFE.RMS[Pa],Pa );
		Measure_RMS( &VAFE.RMS[Qa],Qa );
		Measure_RMS( &VAFE.RMS[Sa],Sa );
		Measure_RMS( &VAFE.RMS[PFa],PFa );
		Measure_RMS( &VAFE.RMS[Frq],Frq );
		
		Measure_RMS( &VAFE.RMS[CALStart],CALStart );	
		Measure_RMS( &VAFE.RMS[ADJStart],ADJStart );
		Measure_RMS( &VAFE.RMS[FUNCEn0],FUNCEn0 );
		Measure_RMS( &VAFE.RMS[SYSStatus1],SYSStatus1 );
	
	if( (VAFE.id!=AT90E25) && (VAFE.id!=AT90E24) && (VAFE.id!=AT90E23) )
	{	
		Measure_RMS( &VAFE.RMS[FUNCEn1],FUNCEn1 );
		Measure_RMS( &VAFE.RMS[SYSStatus1],SYSStatus1 );
		
		Measure_RMS( &VAFE.RMS[Ub],Ub );
		Measure_RMS( &VAFE.RMS[Uc],Uc );
		Measure_RMS( &VAFE.RMS[Ib],Ib );
		Measure_RMS( &VAFE.RMS[Ic],Ic );
		Measure_RMS( &VAFE.RMS[Pt],Pt );
		Measure_RMS( &VAFE.RMS[Pb],Pb );
		Measure_RMS( &VAFE.RMS[Pc],Pc );
		Measure_RMS( &VAFE.RMS[Qt],Qt );
		Measure_RMS( &VAFE.RMS[Qb],Qb );
		Measure_RMS( &VAFE.RMS[Qc],Qc );
		Measure_RMS( &VAFE.RMS[SAt],SAt );
		Measure_RMS( &VAFE.RMS[SVt],SVt );
		Measure_RMS( &VAFE.RMS[Sb],Sb );
		Measure_RMS( &VAFE.RMS[Sc],Sc );
		Measure_RMS( &VAFE.RMS[PFt],PFt );
		Measure_RMS( &VAFE.RMS[PFb],PFb );
		Measure_RMS( &VAFE.RMS[PFc],PFc );
		
		Measure_RMS( &VAFE.RMS[Pha],Pha );
		Measure_RMS( &VAFE.RMS[Phb],Phb );
		Measure_RMS( &VAFE.RMS[Phc],Phc );
		
		Measure_RMS( &VAFE.RMS[Temperature],Temperature );
		
		Measure_RMS( &VAFE.RMS[UangleA],UangleA );
		Measure_RMS( &VAFE.RMS[UangleB],UangleB );
		Measure_RMS( &VAFE.RMS[UangleC],UangleC );
		
		Measure_RMS( &VAFE.RMS[THDNUA],THDNUA );
		Measure_RMS( &VAFE.RMS[THDNUB],THDNUB );
		Measure_RMS( &VAFE.RMS[THDNUC],THDNUC );		
		Measure_RMS( &VAFE.RMS[THDNIA],THDNIA );
		Measure_RMS( &VAFE.RMS[THDNIB],THDNIB );
		Measure_RMS( &VAFE.RMS[THDNIC],THDNIC );
		
		if( VAFE.thd_status ==IsSuccess )
		{
		/*
			VAFE.RMS[AI_HRx] =Calculate_I_V_HarmonicRatio( 0x100 );
			VAFE.RMS[AI_THD] =Calculate_I_V_HarmonicRatio( 0x11F );			
			VAFE.RMS[BI_HRx] =Calculate_I_V_HarmonicRatio( 0x120 );
			VAFE.RMS[BI_THD] =Calculate_I_V_HarmonicRatio( 0x13F );			
			VAFE.RMS[CI_HRx] =Calculate_I_V_HarmonicRatio( 0x140 );
			VAFE.RMS[CI_THD] =Calculate_I_V_HarmonicRatio( 0x15F );
			
			VAFE.RMS[AV_HRx] =Calculate_I_V_HarmonicRatio( 0x160 );
			VAFE.RMS[AV_THD] =Calculate_I_V_HarmonicRatio( 0x17F );			
			VAFE.RMS[BV_HRx] =Calculate_I_V_HarmonicRatio( 0x180 );
			VAFE.RMS[BV_THD] =Calculate_I_V_HarmonicRatio( 0x19F );			
			VAFE.RMS[CV_HRx] =Calculate_I_V_HarmonicRatio( 0x1A0 );
			VAFE.RMS[CV_THD] =Calculate_I_V_HarmonicRatio( 0x1BF );
			
			VAFE.RMS[AI_FUND] =Calculate_I_V_Fundamental( 0x1C0,1000*(1<<(VAFE.dft_scale.BIT.DFT_AI)) );
			VAFE.RMS[AV_FUND] =Calculate_I_V_Fundamental( 0x1C1,100*(1<<(VAFE.dft_scale.BIT.DFT_AV)) );			
			VAFE.RMS[BI_FUND] =Calculate_I_V_Fundamental( 0x1C2,1000*(1<<(VAFE.dft_scale.BIT.DFT_BI)) );
			VAFE.RMS[BV_FUND] =Calculate_I_V_Fundamental( 0x1C3,100*(1<<(VAFE.dft_scale.BIT.DFT_BV)) );			
			VAFE.RMS[CI_FUND] =Calculate_I_V_Fundamental( 0x1C4,1000*(1<<(VAFE.dft_scale.BIT.DFT_CI)) );
			VAFE.RMS[CV_FUND] =Calculate_I_V_Fundamental( 0x1C5,100*(1<<(VAFE.dft_scale.BIT.DFT_CV)) );			
		*/
		}
		else
		{
			if(VAFE.thd_timer ==0)
			{
				Enable_Harmonic_Calculate();	//enable dft calculate
			}
		}

		Measure_RMS( &VAFE.RMS[CNFStart],CNFStart );
		Measure_RMS( &VAFE.RMS[HMStart],HMStart );
	}
	Sag_check();
}


/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
}
#endif
/**INDENT-ON**/
/// @endcond