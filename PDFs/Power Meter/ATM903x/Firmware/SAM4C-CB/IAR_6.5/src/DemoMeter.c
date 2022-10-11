//===================================================================
#include <stdio.h>
#include <stdlib.h>

#include "asf.h"
#include "conf_clock.h"
#include "conf_board.h"

// added manually for meter application 
#include "sleepmgr.h"
#include "v_relocate.h"

#include "target.h"

/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
extern "C" {
#endif
/**INDENT-ON**/
/// @endcond



/** All interrupt mask. */
#define ALL_INTERRUPT_MASK  0xffffffff

// Demo Meter variables
sys_t       sys;		// System variable structure


//=========================================================
//decription	::	reset interrupt process
//function		::	RSTC_IrqHandler
//input			::	none
//output		::	none
//call			::	none
//effect		::	none
//=========================================================
void RSTC_IrqHandler(void)
{
	if (RSTC_WATCHDOG_RESET <= rstc_get_reset_cause(RSTC)) 
	{
		sys.mode = RESTART_MODE;
	}
}
//=========================================================
//decription	::	power down interrupt process
//function		::	fail_detect_handler
//input			::	none
//output		::	none
//call			::	none
//effect		::	none
//=========================================================
void fail_detect_handler(void)
{
    sys.mode = BATTERY_MODE;
}
//Init power fail
//=========================================================
//decription	::	power down check process
//function		::	power_fail_detect
//input			::	none
//output		::	none
//call			::	none
//effect		::	none
//=========================================================
void power_fail_detect(void)
{
    pmc_enable_periph_clk(POWER_FAIL_ID);
    gpio_configure_pin(GPIO_POWER_FAIL, GPIO_POWER_FAIL_FLAGS);
    //pio_set_debounce_filter(PIOC, POWER_FAIL_MASK, 1000);
    pio_handler_set(POWER_FAIL_PIO, POWER_FAIL_ID, POWER_FAIL_MASK, PIO_IT_FALL_EDGE, fail_detect_handler);
    pio_enable_interrupt(POWER_FAIL_PIO, POWER_FAIL_MASK);
    NVIC_DisableIRQ(PIOA_IRQn);
    NVIC_ClearPendingIRQ(PIOA_IRQn);
    NVIC_SetPriority(PIOA_IRQn, 0);
    NVIC_EnableIRQ(PIOA_IRQn);    
}

//=========================================================
//decription	::	diplay down key interrupt process
//function		::	DispDnkey_detect_handler
//input			::	none
//output		::	none
//call			::	none
//effect		::	none
//=========================================================
void	DispDnkey_INT_handler(void)
{
	sys.dispkeydn =0x55;
	__NOP();
}
//=========================================================
//decription	::	power down check process
//function		::	power_fail_detect
//input			::	none
//output		::	none
//call			::	none
//effect		::	none
//=========================================================
void	DispDnkey_detect_config(void)
{
    pmc_enable_periph_clk(DISPKEY_DN_ID);
    gpio_configure_pin(GPIO_DISPKEYDN_PIN, GPIO_DISPKEY_DN_FLAGS);
    //pio_set_debounce_filter(PIOC, DISPKEY_DN_MASK, 1000);
    pio_handler_set(DISPKEY_DN_PIO, DISPKEY_DN_ID, DISPKEY_DN_MASK, PIO_IT_FALL_EDGE, DispDnkey_INT_handler);
    pio_enable_interrupt(DISPKEY_DN_PIO, DISPKEY_DN_MASK);
    NVIC_DisableIRQ(PIOB_IRQn);
    NVIC_ClearPendingIRQ(PIOB_IRQn);
    NVIC_SetPriority(PIOB_IRQn, 0);
    NVIC_EnableIRQ(PIOB_IRQn);    
}
//=========================================================
//decription	::	diplay down key interrupt process
//function		::	DispDnkey_detect_handler
//input			::	none
//output		::	none
//call			::	none
//effect		::	none
//=========================================================
void	DispUpkey_INT_handler(void)
{
	sys.dispkeyup =0x55;
}
//=========================================================
//decription	::	display up key configure
//function		::	DispUpkey_detect_config
//input			::	none
//output		::	none
//call			::	none
//effect		::	none
//=========================================================
void	DispUpkey_detect_config(void)
{
    pmc_enable_periph_clk(DISPKEY_UP_ID);
    gpio_configure_pin(GPIO_DISPKEYUP_PIN, GPIO_DISPKEY_UP_FLAGS);
    //pio_set_debounce_filter(PIOC, DISPKEY_UP_MASK, 1000);
    pio_handler_set(DISPKEY_UP_PIO, DISPKEY_UP_ID, DISPKEY_UP_MASK, PIO_IT_FALL_EDGE, DispUpkey_INT_handler);
    pio_enable_interrupt(DISPKEY_UP_PIO, DISPKEY_UP_MASK);
//    NVIC_DisableIRQ(PIOB_IRQn);
//    NVIC_ClearPendingIRQ(PIOB_IRQn);
//    NVIC_SetPriority(PIOB_IRQn, 0);
//    NVIC_EnableIRQ(PIOB_IRQn);    
}
//=========================================================
//decription	::	wdt intrerupt process
//function		::	WDT_IrqHandler
//input			::	none
//output		::	none
//call			::	none
//effect		::	none
//=========================================================
void WDT_IrqHandler(void)
{
/*
	puts("Enter watchdog interrupt.\r");

	// Clear status bit to acknowledge interrupt by dummy read. //
	wdt_get_status(WDT);
	// Restart the WDT counter. //
	//wdt_restart(WDT);//---ztz----
	puts("The watchdog timer was restarted.\r");

	// Restart meter
        sys.alert |= WATCH_DOG_RESTART;
	sys.mode = RESTART_MODE;
*/
	
}
//=========================================================
//decription	::	battery mode initialize
//function		::	battery_mode_init
//input			::	none
//output		::	none
//call			::	none
//effect		::	
//=========================================================
void battery_mode_init(void)
{
	uint32_t	i;
    // clear rms display ram.
	for(i=0;i<RMS_Num_Max;i++)
	{
		VAFE.RMS[i]=0;
	}
	// Set up for brown-out mode.
    
    // Registers were already saved in the power failure interrupt.
	
//	*((uint32_t *)(0x400E1490)) =SUPC->SUPC_MR;//( supc_get_slcd_power_mode(SUPC) );		
	
	//Configure the force start pin
	SUPC->SUPC_WUMR	= SUPC_WUMR_FWUPDBC_512_SCLK;
    SUPC->SUPC_WUMR |= SUPC_WUMR_FWUPEN;	//enable FWUP wakeup core when FWUP is "0" 
    //Configure TMP0 pin for low power debouncer
//    SUPC->SUPC_WUMR |= SUPC_WUMR_LPDBCEN0;				//enable TMP0 wakeup core when TMP0 is "0" 
//    SUPC->SUPC_WUMR |= SUPC_WUMR_LPDBC_2_RTCOUT0;	
    
    //Configure WKUP7 pin (PA17)
    SUPC->SUPC_WUMR |= SUPC_WUMR_WKUPDBC_512_SCLK;
	SUPC->SUPC_WUIR &= (~SUPC_WUIR_WKUPT0_HIGH); //wakeup0 is "0" wakeup core
	SUPC->SUPC_WUIR = SUPC_WUIR_WKUPEN0;		//enable wkup0 wakeup core
    SUPC->SUPC_WUIR |=(SUPC_WUIR_WKUPEN7 | SUPC_WUIR_WKUPT7);		//power_check is "1" wakeup core
		
	//Configure WKUP RTCEN
	rtc_clear_time_alarm(RTC);	
	rtc_set_time_alarm(RTC, 0, 0, 0, 0,	1,VRTC.second);
    SUPC->SUPC_WUMR |= SUPC_WUMR_RTCEN;
	
    // Switch to battery mode
	
}
//=========================================================
//decription	::	battery mode process
//function		::	battery_mode
//input			::	none
//output		::	none
//call			::	battery_mode_init,slcdc_disable,sleepmgr_sleep
//effect		::	
//=========================================================
void battery_mode(void)
{
   int32_t  status;
   __NOP();
   __NOP();
    battery_mode_init();
	VDisplay.Number=0;
	VDisplay.LpTimer=0;
	__NOP();
	//GPBR->SYS_GPBR[0] =0x6886;
	__NOP();
    while (BATTERY_MODE == sys.mode) 
	{
        //-------
		slcdc_disable(SLCDC);
        __NOP();
        __NOP();
		sleepmgr_sleep((enum sleepmgr_mode) SAM_PM_SMODE_WAIT);//sleep
		//------wake up -----------------------------------
		sys.mode =LCD_MODE;
		//backup-mode wakeup core is reset 
        //Processor C0 should sleep right here		
	}//endwhile(battery_mode)
	
}
//=========================================================
//decription	::	reset mcu process
//function		::	restart_mode
//input			::	none
//output		::	none
//call			::	slcdc_disable,rstc_start_software_reset
//effect		::	reset mcu
//=========================================================
void	restart_mode(void)
{
    slcdc_disable(SLCDC);
    //rstc_set_external_reset(RSTC, 8);  // this function does not restart the chip
    
    rstc_start_software_reset(RSTC);
}
//=========================================================
//decription	::	lcd mode process
//function		::	LCD_mode
//input			::	none
//output		::	none
//call			::	slcdc_enable,slcdc_disable,sleepmgr_sleep
//effect		::	
//=========================================================
void LCD_mode(void)
{
	uint32_t	i,status;
    uint32_t    key=0xF0;
	
	VDisplay.Number=0;
	VDisplay.LpTimer =5;
	UpdataDisplayProcess();
	slcdc_enable(SLCDC);
	wdt_restart(WDT);
	while (LCD_MODE == sys.mode)
	{				
		sleepmgr_sleep((enum sleepmgr_mode) SAM_PM_SMODE_WAIT);
		//------------wake up------------------------------
		/*
		status =rtc_get_status(RTC);
		if( (status&0x02) ==0x02 )
		{
			RTC->RTC_TIMALR &=0x7F;
			RTC->RTC_SCCR |=0x02;		//clear rtc alarm flag
			if( (RTC->RTC_TIMALR+1)%60==0 )
			{
				RTC->RTC_TIMALR =1;
			}
			else
			{
				RTC->RTC_TIMALR =((RTC->RTC_TIMALR+1)%60);
			}
			RTC->RTC_TIMALR |=0x80;		//enable rtc sec alarm
			
			wdt_restart(WDT);
			
			if( VDisplay.LpTimer !=0 )
			{
				VDisplay.LpTimer--;
				if( VDisplay.Number==DISPLAY_RTC_TIME || VDisplay.Number==DISPLAY_RTC_DATE )
				{
					UpdataDisplayProcess();
				}
			}			
		}//sencond alarm wakeup reset wdt
		
		status =supc_get_status(SUPC);       
        if( (status&SUPC_SR_FWUPS)==SUPC_SR_FWUPS || (status&SUPC_SR_WKUPS)==SUPC_SR_WKUPS )
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
			VDisplay.LpTimer =5;	//VDisplay.GapTimer
			UpdataDisplayProcess();
			__NOP();
			__NOP();
		}
		else
		{
			__NOP();
			__NOP();
			sys.mode =NORMAL_MODE;
		}
		*/		
	}//endwhile(LCD_mode)
	
}
//=========================================================
//decription	::	normal mode initialize
//function		::	Normal_mode_init
//input			::	none
//output		::	none
//call			::	none
//effect		::	none
//=========================================================
void	Normal_mode_init(void)
{
	InitTaskQue();
	VDisplay.Number =DISPLAY_ALL;
	VDisplay.LpTimer =1;//display 1s=2*500ms
	VBaseTimer.T5ms =0;
	VBaseTimer.T500ms =0;
	VBaseTimer.T1s =0;
	VBaseTimer.T1Min =0;
	sys.dispkeydn =0;
	sys.dispkeyup =0;
	
	VCom.lamptimer =0;
	Init_Uart_App(Rs485_ID);
	Init_Uart_App(Ir_ID);
	Init_Usart_App(ZigBee_ID);	
	Init_Usart_App(PLC_ID);
	
	PutTaskIntoQue(UpdataDisplay);
    PutTaskIntoQue(ReadRTC);
	PutTaskIntoQue(CheckMajorPara);
    PutTaskIntoQue(ResumeCalibrationPara); 
    AFE_Configure_CF1();
}
//=========================================================
//decription	::	normal mode process
//function		::	Normal_mode
//input			::	none
//output		::	none
//call			::	none
//effect		::	none
//=========================================================
void	Normal_mode(void)
{
	//-----------------------------------------------------
	Normal_mode_init();
	//-----------------------------------------------------
	while( sys.mode ==NORMAL_MODE )
	{
		if(VBaseTimer.T5ms)
        {
          BaseTimerProcess();
        }		
		switch( GetTaskFromQue() )
        {
            case  ReadRTC:
            {
                ReadRTCProcess();
            }
            break;        
            case  UpdataDisplay:
            {
                UpdataDisplayProcess();
            }
            break;
            case  UpdataDisplayNumber:
            {
                UpdataDisplayNumberProcess();
            }
            break;
            case    Rs485CmdProc:
            {
            	ComProcess(Rs485_ID);
			}
			break;
			case    Rs485Transmit:
            {
				ComSendProcess(Rs485_ID);
			}
			break;
			case    IrCmdProc:
            {
            	ComProcess(Ir_ID);
			}
			break;
			case    IrTransmit:
            {
				ComSendProcess(Ir_ID);
			}
			break;
			case    ZigBeeCmdProc:
            {
            	ComProcess(ZigBee_ID);
			}
			break;
			case    ZigBeeTransmit:
            {
				ComSendProcess(ZigBee_ID);
			}
			break;
			case    PulseProc:
            {
				PulseProcess();
			}
			break;
			case    EnergyProc:
            {
				EnergyProcess();
			}
			break;
			case    SecondProc:
            {
				SecondProcess();
			}
			break;
			case	CheckMajorPara:
			{
				CheckMajorParaProcess();
			}
			break;
            case    ResumeCalibrationPara:
            {
                Load_AFE_Cal_Para_From_Eprom();
            }
            break;
            default :
            break;
        }
	}//end while(normal_mode)
}
// -----------------------------------------------------------------------------
//  Function Name       : set_PCK_output
//  Object              : Enable 4 MHZ PCK0 on AT91C_PA29_PCK1
// -----------------------------------------------------------------------------
void set_PCK_output (void)
{
   // Configure PIO controllers to periph mode
   pio_set_peripheral(PIOA,PIO_PERIPH_A,(uint32_t)(PIO_PA29A_PCK1));
   // PCK 1 = output main clk/2 on PA29
   pmc_switch_pck_to_mainck(1,PMC_PCK_PRES(1));
   pmc_enable_pck(1);
}
//=========================================================
//decription	::	configure core1 processor
//function		::	configure_coprocessor
//input			::	none
//output		::	none
//call			::	none
//effect		::	none
//=========================================================
void configure_coprocessor(void)
{
	uint32_t  read_reg;
	
	//Enables Coprocessor Bus Master Clock
	REG_PMC_SCER = PMC_SCER_CPBMCK | PMC_SCER_CPKEY(CP_KEY_VAL); //CPBMCK+KEY
	//Enables the  Coprocessor Clocks
	REG_PMC_SCER = PMC_SCER_CPCK | PMC_SCER_CPKEY(CP_KEY_VAL);   //CPCK+KEY
	
	//Set co-p Prescaler
	read_reg = REG_PMC_MCKR;
	read_reg &= ~PMC_MCKR_CPPRES_Msk;      //Reset co-p Prescaler
	read_reg |= PMC_MCKR_CPPRES(0) ;     //Selected clock devided by 1(CPRES_VALUE+1)
	REG_PMC_MCKR = read_reg;
	
	//Choose MAINCK
	read_reg = REG_PMC_MCKR;
	read_reg &= ~PMC_MCKR_CPCSS_Msk;
	read_reg |= PMC_MCKR_CPCSS_MCK;
	REG_PMC_MCKR = read_reg;
	
	//Release c1 peripheral reset
	REG_RSTC_CPMR = RSTC_CPMR_CPKEY(RSTC_CP_KEY_VAL)|RSTC_CPMR_CPEREN;
	
	pmc_enable_periph_clk(ID_SRAM1_2);
}
//=========================================================
//------------- main -------------------------------------- 
//=========================================================
int main(void)
{
    uint32_t timeout_value;
    uint32_t wdt_mode;

//    #ifdef ENABLE_CACHE
//    //Matrix0 settings
//		MATRIX0->MATRIX_SCFG[2] = MATRIX_SCFG_DEFMSTR_TYPE(2) | MATRIX_SCFG_FIXED_DEFMSTR(6);  
//		//Enable cache
//		CMCC0->CMCC_CTRL = CMCC_CTRL_CEN;  
//    #else
//		CMCC0->CMCC_CTRL &= ~CMCC_CTRL_CEN;
//    #endif
/*    
    //Configure the force start pin
    SUPC->SUPC_WUMR |= SUPC_WUMR_FWUPDBC_512_SCLK | SUPC_WUMR_FWUPEN;	//enable FWUP wakeup core when FWUP is "0" 
    //Configure TMP0 pin for low power debouncer
    SUPC->SUPC_WUMR |= SUPC_WUMR_LPDBCEN0;
    SUPC->SUPC_WUMR |= SUPC_WUMR_LPDBC_2_RTCOUT0;	//enable TMP0 wakeup core when TMP0 is "0" 
    
    //Configure WKUP7 pin (PA17)
    SUPC->SUPC_WUMR |= SUPC_WUMR_WKUPDBC_512_SCLK;
    SUPC->SUPC_WUIR = SUPC_WUIR_WKUPEN7 | SUPC_WUIR_WKUPT7;		//power_check is "1" wakeup core
*/	
    relocate_int_table(0);
	
    pmc_enable_periph_clk(ID_PIOB); //inition PIOB clk for 
	
	
    sys.mode =NORMAL_MODE;
    
    power_fail_detect();
    
	sysclk_init();
    
    //----------enable 32768 xtal----------------------
	osc_enable(OSC_SLCK_32K_XTAL);	 
	osc_wait_ready(OSC_SLCK_32K_XTAL);
    
//    osc_enable(OSC_SLCK_32K_RC);	 
//	  osc_wait_ready(OSC_SLCK_32K_RC);
	//-----------configure lcd-------------------------        
	LCD_init();
	set_slcd_ram(0xFFFFFFFF);
	//-----------------------------------------------------
    
//	set_PCK_output();  // check all clock frequency using PCKx on output PIO
    configure_coprocessor();	//
    board_init();
	//pmc_enable_periph_clk(ID_SUPC); //inition supc clk    
	//-----------inition i2c bus-----------------------
	pmc_enable_periph_clk(ID_PIOA); //inition PIOA clk for I2C
	BSP_E2promBus_Init();        
	//----------delay wait for stable------------------
	Delay_N_ms(100);
	//----------enable 32768 xtal----------------------
	osc_enable(OSC_SLCK_32K_XTAL);	 
	osc_wait_ready(OSC_SLCK_32K_XTAL);
    
//    osc_enable(OSC_SLCK_32K_RC);	 
//	  osc_wait_ready(OSC_SLCK_32K_RC);
	//-----------configure lcd-------------------------        
	LCD_init();
	set_slcd_ram(0xFFFFFFFF);
	//-----------------------------------------------------
	//--if slck=32k_rc then the next code should be used--
	//--else lcd ghost is bigger
	//-----------------------------------------------------
	//set internal LDO output
    supc_enable_slcd_ldo_output(SUPC ,0x3);	//vlcd=2.6v
	//set LCD buffer on time
	slcdc_set_buftime(SLCDC, 7);	//buffer on time =slck/1024
	//-----------------------------------------------------
	// Default RTC configuration, 24-hour mode 
	rtc_set_hour_mode(RTC, RTC_24_HOUR_MODE);
	//--------set rtc 1hz out--------------------
//	rtc_set_waveform(RTC, 0, 1);    
	
	//----------configure uart parameter---------------
//	configure_console();
	VCom.ZigBee.baud_sym =0x20;		//baud=4800
	Init_Usart_App(ZigBee_ID);
	VCom.Rs485.baud_sym =0x80;		//baud=115200
    Init_Uart_App(Rs485_ID);
	VCom.IR.baud_sym =0x08;			//baud=1200
	Init_Uart_App(Ir_ID);
	//---------configure base timer--------------------    
	SysTick_Config(SystemCoreClock / 200);//5ms
/*
	// Get timeout value. 
	timeout_value = wdt_get_timeout_value(WDT_PERIOD * 1000, BOARD_FREQ_SLCK_XTAL);
	if (WDT_INVALID_ARGUMENT == timeout_value) 
		while (1);  	//todo Invalid timeout value, error. 
        
	// Configure WDT to trigger an interrupt (or reset). 
	wdt_mode = WDT_MR_WDFIEN |	// Enable WDT fault interrupt.
	WDT_MR_WDRPROC |	// WDT fault resets processor only.
	WDT_MR_WDRSTEN  |   //WDT reset is enable.//-----ztz-----------
	WDT_MR_WDDBGHLT |	// WDT stops in debug state. 
	WDT_MR_WDIDLEHLT;	// WDT stops in idle state. 
	// Initialize WDT with the given parameters. 
	wdt_init(WDT, wdt_mode, timeout_value, timeout_value);	
*/	
    //----------------initialize i2c bus-----------------------------
	pmc_enable_periph_clk(ID_PIOA); //inition PIOA clk for I2C
	BSP_E2promBus_Init();
	//----------------initialize spi bus-----------------------------
    pmc_enable_periph_clk(ID_PIOB); //inition PIOB clk for AFE
    pmc_enable_periph_clk(ID_PIOC); //inition PIOC clk for SPI   
    Identify_AFE_Type();
	Configure_AFE_Int();
    //---------------------------------------------------------------
	// Restart watchdog at the given period. //
	if ((sys.ms_ticks % WDT_RESTART_PERIOD) == 0) 
		wdt_restart(WDT);
	// background processing loop
	DispDnkey_detect_config();
    DispUpkey_detect_config();
	//---------------------------------------------------------------
    //------------main loop------------------------------------------
    //---------------------------------------------------------------
	while (1) 	
	{
		switch(sys.mode)
		{
			case	BATTERY_MODE:
			{
				battery_mode();
			}//battery mode
			break;
			case	LCD_MODE:
			{
				LCD_mode();
			}//lcd mode
			break;
			case	NORMAL_MODE:
			{
				Normal_mode();
			}//normal mode
			break;
			case	RESTART_MODE:
			{
				restart_mode();
			}//restart mode
			break;
			default :
			{
				sys.mode = RESTART_MODE;
			}
			break;
		}//end switch(sys.mode)		
	}
}	





/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
}
#endif
/**INDENT-ON**/
/// @endcond

