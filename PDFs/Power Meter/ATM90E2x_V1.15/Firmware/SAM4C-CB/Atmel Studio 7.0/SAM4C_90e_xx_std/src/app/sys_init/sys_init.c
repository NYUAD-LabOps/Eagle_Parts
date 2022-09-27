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
//=========================================================
//------- initialize internal ram variable ----------------
//=========================================================
void	Initialize_RamVar( void )
{
    InitTaskQue();
	VDisplay.Number =DISPLAY_ALL;
	VDisplay.LpTimer =1;//display 1s=2*500ms
	VBaseTimer.T5ms =0;
	VBaseTimer.T500ms =0;
	VBaseTimer.T1s =0;
	VBaseTimer.T1Min =0;
	VPressKey.dnkey = 0;
	VPressKey.upkey = 0;
	VCom.lamptimer =0;
	
	PutTaskIntoQue(RefreshDisplay);
    PutTaskIntoQue(RTCPROC);
	PutTaskIntoQue(CheckMajorPara);
    PutTaskIntoQue(ResumeCalibrationPara); 
    AFE_Configure_CF1();  
    //-----------------------------------------------------
}
//===================================================================
//decription    ::  get chip id
//function      ::  get_chip_id
//input         ::  none
//output        ::  chip_id
//call          ::  none
//effect        ::  none
//===================================================================
uint32_t	get_chip_id( void )
{
	uint32_t	temp;
	temp = REG_CHIPID_EXID;
	if( ( temp & 0x0F ) == SAM4C_xx_CHIP_ID_VALUE )
	{
		return( SAM4C_xx_CHIP_ID );
	}
	else if( ( temp & 0x0F ) == SAM4CMS_xx_CHIP_ID_VALUE )
	{
		return( SAM4CMS_xx_CHIP_ID );
	}
	else
	{
		return( SAM4CMP_xx_CHIP_ID );
	}
}
//===================================================================
//description   ::  configure core1 processor
//function      ::  configure_core1_clock
//input         ::  none
//output        ::  none
//call          ::  none
//effect        ::
//===================================================================
void	configure_core1_clock( void )
{
    unsigned int  read_reg = 0;
	
	//---reset core1 and core1 peripheral------------------
	RSTC->RSTC_CPMR = RSTC_CPMR_KEY_PASSWD;	//reset core1
	
    // Enables Coprocessor Bus Master Clock //
    PMC->PMC_SCER = PMC_SCER_CPBMCK | PMC_SCER_CPKEY_PASSWD;

    // Enables the Co-processor Clocks //
    PMC->PMC_SCER = PMC_SCER_CPCK | PMC_SCER_CPKEY_PASSWD;

    // Set co-processor clock pre-scaler and source 
    read_reg = PMC->PMC_MCKR;
    read_reg &= ~PMC_MCKR_CPPRES_Msk;
	
	// 102.4MHz for poly-phase AFE
	read_reg |= PMC_MCKR_CPPRES( CONFIG_CPCLK_PRES - 1 );	//CONFIG_CPCLK_PRES =0;

    PMC->PMC_MCKR = read_reg;

    // Choose co-processor main clock source //
    read_reg = PMC->PMC_MCKR;
    read_reg &= ~PMC_MCKR_CPCSS_Msk;
    read_reg |= ( CONFIG_CPCLK_SOURCE << PMC_MCKR_CPCSS_Pos );
    PMC->PMC_MCKR = read_reg;

    // Release co-processor peripheral reset //
    RSTC->RSTC_CPMR |= ( RSTC_CPMR_CPKEY( 0x5Au ) | RSTC_CPMR_CPEREN );

    // Enable Core 1 SRAM1 and SRAM2 memories //
    pmc_enable_periph_clk( ID_SRAM ); // ID_SRAM1_2 //
	
	//deasserts Coprocessor reset
    RSTC->RSTC_CPMR = RSTC_CPMR_CPEREN | RSTC_CPMR_CPROCEN | RSTC_CPMR_KEY_PASSWD;
}
//===================================================================
//decription    ::  system clock initialize 
//function      ::  sysclock_init
//input         ::  none
//output        ::  none
//call          ::  none
//effect        ::  PLLA PLLB MCK  (PMC module)
//===================================================================
void	sysclock_init( void )
{
	
    uint32_t    i;
	//-------------set flash wait state--------------------
	system_init_flash( sysclk_get_cpu_hz() );		//set a flash wait state depending on the new cpu frequency
	//----------enable 32768 xtal--------------------------
    SUPC->SUPC_CR = SUPC_CR_KEY_PASSWD | SUPC_CR_XTALSEL;
	while( !( SUPC->SUPC_SR & SUPC_SR_OSCSEL ) );
	while( !( PMC->PMC_SR & PMC_SR_OSCSELS ) );
	//---------enable PLLA---------------------------------
	PMC->CKGR_PLLAR = 0;	//disable plla
    for( i=0; i<60; i++ )
    {
		__NOP();
	}
	PMC->CKGR_PLLAR = ( CKGR_PLLAR_MULA(CONFIG_PLL0_MUL-1) | CKGR_PLLAR_PLLACOUNT(PLL_COUNT) | CONFIG_PLL0_DIV );
    while ( ( PMC->PMC_SR & PMC_SR_LOCKA ) == 0 );
	//----------switch mck to PLLA-------------------------
	PMC->PMC_MCKR = ( PMC->PMC_MCKR & ( ~PMC_MCKR_PRES_Msk ) ) | CONFIG_SYSCLK_PRES;
	while( !( PMC->PMC_SR & PMC_SR_MCKRDY ) );
	PMC->PMC_MCKR = ( PMC->PMC_MCKR & ( ~PMC_MCKR_CSS_Msk ) ) | PMC_MCKR_CSS_PLLA_CLK;
	while( !( PMC->PMC_SR & PMC_SR_MCKRDY ) );
	//----------set flash wait state-----------------------
	system_init_flash( sysclk_get_cpu_hz() );
	////-----------enable 8.192MHz xtal----------------------
	//PMC->CKGR_MOR = ( ( PMC->CKGR_MOR & ~CKGR_MOR_MOSCXTBY ) | CKGR_MOR_KEY_PASSWD | CKGR_MOR_MOSCXTST(62) | CKGR_MOR_MOSCXTEN );
	//while( !( PMC->PMC_SR & PMC_SR_MOSCXTS ) );
    //PMC->CKGR_MOR |= CKGR_MOR_KEY_PASSWD | CKGR_MOR_MOSCSEL;	
	//--------enable PLLB----------------------------------
	PMC->CKGR_PLLBR = CKGR_PLLBR_MULB( 0 );	//disable pllb
	for( i=0; i<500; i++ )
    {
		__NOP();
	}
	//mul =24+1, count=100, div=2, src=main xtal
	//PMC->CKGR_PLLBR = CKGR_PLLBR_SRCB_MAINCK_IN_PLLB | CKGR_PLLBR_MULB(CONFIG_PLL1_MUL-1) | CKGR_PLLBR_PLLBCOUNT(PLL_COUNT) | CKGR_PLLBR_DIVB(CONFIG_PLL1_DIV);
    //mul =25, count=100, div=2, src=PLLA
	PMC->CKGR_PLLBR = ( uint32_t )( 0x80000000 | CKGR_PLLBR_SRCB_PLLA_IN_PLLB | CKGR_PLLBR_MULB(CONFIG_PLL1_MUL-1) | CKGR_PLLBR_PLLBCOUNT(PLL_COUNT) | CKGR_PLLBR_DIVB(CONFIG_PLL1_DIV) );
	while ( ( PMC->PMC_SR & PMC_SR_LOCKB ) == 0 );
	//----------switch mck to PLLB-------------------------
	PMC->PMC_MCKR = ( ( PMC->PMC_MCKR & ( ~PMC_MCKR_PRES_Msk ) ) | CONFIG_SYSCLK_PRES );
	while( !( PMC->PMC_SR & PMC_SR_MCKRDY ) );
	PMC->PMC_MCKR = ( ( PMC->PMC_MCKR & ( ~PMC_MCKR_CSS_Msk ) ) | PMC_MCKR_CSS_PLLB_CLK );
	while( !( PMC->PMC_SR & PMC_SR_MCKRDY ) );
	//----------set flash wait state-----------------------
	system_init_flash( sysclk_get_cpu_hz() );
	//-------------------------------------------
	SystemCoreClock =sysclk_get_cpu_hz();//SystemCoreClockUpdate();

    //sysclk_initialized = 1;
	//---configure coprocessor mck---------------
	configure_core1_clock();
}
//===================================================================
//decription    ::  system clock initialize 
//function      ::  sysclock_init
//input         ::  none
//output        ::  none
//call          ::  sysclock_init
//effect        ::  none
//===================================================================
void	sys_init(void)
{
	//---------configure core0 clock-----------------------
	sysclock_init();
	//---Enable PIO clock ---------------------------------
	pmc_enable_periph_clk(ID_PIOA);
	pmc_enable_periph_clk(ID_PIOB);
	pmc_enable_periph_clk(ID_PIOC);
	//---power failure configure---------------------------
	power_fail_detect();
	//----------delay wait for stable----------------------
    //delay_ms( 100 );
    //-----------configure lcd-----------------------------
    LCD_Disp_init();
	//-----------inition i2c bus---------------------------
	BSP_E2promBus_Init(); //inition E2bus	
	//---Default RTC configuration, 24-hour mode-----------
	rtc_set_hour_mode(RTC, RTC_24_HOUR_MODE);
	//datestr = __DATE__;
	//timestr =__TIME__;
	//---set date is 2016-08-17 5---------------------------
	//rtc_set_date( RTC, 2016, 6, 17, 5 );
	//---set time is 10:21:16------------------------------
    //rtc_set_time( RTC, 10,21, 16 );
	//---initialize communication port---------------------
	VCom.ZigBee.baud_sym =0x20;		//baud=4800
	Init_Usart_App(ZigBee_ID);
	VCom.Rs485.baud_sym =0x80;		//baud=115200
    Init_Uart_App(Rs485_ID);
	VCom.IR.baud_sym =0x08;			//baud=1200
	Init_Uart_App(Ir_ID);
	//Init_Usart_App(PLC_ID);
	//---configure AFE-------------------------------------
	Identify_AFE_Type();
	Configure_AFE_Int();
	//-----------------------------------------------------
	wdt_restart(WDT);
	//---press key configure-------------------------------
	DispDnkey_detect_config();
    DispUpkey_detect_config();
    //---------configure systick base timer----------------  
	SysTick_Config( SystemCoreClock / 200 );//5ms=(Fmck(Hz)*5/1000)	
	//---Intitialize Globle Variable-----------------------
	Initialize_RamVar();
	//---reset watchdog------------------------------------
	wdt_restart( WDT );	
	//=====================================================
}

/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
}
#endif
/**INDENT-ON**/
/// @endcond