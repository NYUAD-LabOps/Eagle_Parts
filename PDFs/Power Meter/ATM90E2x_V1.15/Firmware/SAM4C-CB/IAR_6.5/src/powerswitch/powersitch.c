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


//*--------------------------------------------------------------------------------------
//* Function Name       : ConfigurePIO_ForConsumption
//* Object              : 
//* Input Parameters    : none.
//* Output Parameters   : none.
//*--------------------------------------------------------------------------------------
void ConfigurePIO_ForConsumption(ST_COMSUMPTION_MODE_DEVICE_SET *stconso_mode )
{

    pmc_enable_periph_clk(ID_PIOA);
    pmc_enable_periph_clk(ID_PIOB);
//    pmc_enable_periph_clk(ID_PIOC);                   

    if (\
         (stconso_mode->consumtionMode == CONSOMODE_LOWP_BACKUP_MODE) || \
         (stconso_mode->consumtionMode == CONSOMODE_SLEEP_MODE)||\
         (stconso_mode->consumtionMode == CONSOMODE_WAIT_MODE)  \
       ) 
      {
        // ------------ input mode
        PIOA->PIO_ODR  = 0xFFFFFFFF;
        PIOB->PIO_ODR  = 0xFFFFFFFF;        
//        PIOC->PIO_ODR  = 0x000003FF;  
        
        PIOA->PIO_PER  = 0xFFFFFFFF;
        PIOB->PIO_PER  = 0xFFFFFFFF;
//        PIOC->PIO_PER  = 0x000003FF;
        
        // ------------ All PIO pulldown disable
        PIOA->PIO_PPDDR = 0xFFFFFFFF;
        PIOB->PIO_PPDDR = 0xFFFFFFFF;
//        PIOC->PIO_PPDDR = 0x000003FF;
        
        // Pull-up Enable Register 
        PIOA->PIO_PUER = 0xFFFFFFFF;
        PIOB->PIO_PUER = 0xFFFFFFEF; //PB4 URXD0
//        PIOC->PIO_PUER = 0x000003FF;
    } //Default settings
}

//*--------------------------------------------------------------------------------------
//* Function Name       : All_PIO_input_pullup
//* Object              : 
//* Input Parameters    : none.
//* Output Parameters   : none.
//*--------------------------------------------------------------------------------------
void All_PIO_input_pullup(ST_COMSUMPTION_MODE_DEVICE_SET *stconso_mode )
{

    pmc_enable_periph_clk(ID_PIOA);
    pmc_enable_periph_clk(ID_PIOB);
    pmc_enable_periph_clk(ID_PIOC);                   
    
//    MATRIX->CCFG_SYSIO =    CCFG_SYSIO_SYSIO5|CCFG_SYSIO_SYSIO7  | CCFG_SYSIO_SYSIO6 |CCFG_SYSIO_SYSIO10 |CCFG_SYSIO_SYSIO11|CCFG_SYSIO_SYSIO12;
    #define Reg_CCFG_SYSIO (unsigned int *) (0x400E0200 + 0x114)
    * Reg_CCFG_SYSIO = CCFG_SYSIO_SYSIO4 | CCFG_SYSIO_SYSIO5 | CCFG_SYSIO_SYSIO6  | CCFG_SYSIO_SYSIO7 | CCFG_SYSIO_SYSIO12;
    
    // ------------ All PIO in input mode
    pio_set_input(PIOA, 0xFFFFFFFF,PIO_PULLUP);
    pio_set_input(PIOB, 0xFFFFFFEF,PIO_PULLUP);      
    pio_set_input(PIOC, 0x000003FF,PIO_PULLUP);
    
    // ------------ All PIO open-drain disable  
    PIOA->PIO_MDDR = 0xFFFFFFFF;
    PIOB->PIO_MDDR = 0xFFFFFFEF; //PB4 URXD0
    PIOC->PIO_MDDR = 0x000003FF;
    if (stconso_mode->consumtionMode == CONSOMODE_LOWP_BACKUP_MODE)
    {
        // ------------ All PIO pulldown disable
        PIOA->PIO_PPDDR = 0xFFFFFFFF;
        PIOB->PIO_PPDDR = 0xFFFFFFFF;
        PIOC->PIO_PPDDR = 0x000003FF;
        // ------------ All PIO pullup enable      
        PIOA->PIO_PUER = 0xFFFFFFFF;
        PIOB->PIO_PUER = 0xFFFFFFEF; //PB4 URXD0
        PIOC->PIO_PUER = 0x000003FF;  
    }
     
    if ((stconso_mode->consumtionMode  == CONSOMODE_ACTIVE_MODE)     ||  \
        (stconso_mode->consumtionMode == CONSOMODE_SLEEP_MODE) ||\
        (stconso_mode->consumtionMode == CONSOMODE_WAIT_MODE))
    {

    // ------------ All PIO pulldown disable

        PIOA->PIO_PPDDR = 0xFFFFFFFF;
        PIOB->PIO_PPDDR = 0xFFFFFFFF;
        PIOC->PIO_PPDDR = 0x000003FF;
           // ------------ All PIO pullup enable      
        PIOA->PIO_PUER = 0xFFFFFFFF;
        PIOB->PIO_PUER = 0xFFFFFFEF; //PB4 URXD0
        PIOC->PIO_PUER = 0x000003FF;  
    }    
}


//*--------------------------------------------------------------------------------------
//* Function Name       : Save_Power_Consumption
//* Object              : 
//* Input Parameters    : none.
//* Output Parameters   : none.
//*--------------------------------------------------------------------------------------
void Save_Power_Consumption(ST_COMSUMPTION_MODE_DEVICE_SET *stconso_mode)
{
    //All_PIO_input_pullup(stconso_mode);
    if( stconso_mode->PeripheralStates==PERIPH_CLOCK_ON)
    {   
         //pmc_enable_all_periph_clk
         pmc_enable_all_periph_clk();
    }
    else 
    {
         // pmc_disable_periph_clk(ID_UDP);
         pmc_disable_all_periph_clk();   
//          UDP->UDP_TXVC=UDP_TXVC_TXVDIS;        
    }
}


//*--------------------------------------------------------------------------------------
//* Function Name       : prepare_mode
//* Object              : 
//* Input Parameters    : none.
//* Output Parameters   : none.
//*--------------------------------------------------------------------------------------
void prepare_mode(void)
{
     unsigned int   read_reg;
                  
     read_reg = *((unsigned int *)SUPC->SUPC_MR);  
     
     if (read_reg & SUPC_MR_OSCBYPASS_BYPASS) // if the 32-KHz XTAL oscillator is selected and is put in bypass mode
     {
        SUPC->SUPC_MR = SUPC_CR_KEY(0xA5)  |SUPC_MR_ONREG_ONREG_USED |  SUPC_MR_BODDIS_DISABLE  | SUPC_MR_OSCBYPASS_BYPASS; // KEY + BOD disable + VDDIO Ready set + Bypass 
     }
     else 
     {
           SUPC->SUPC_MR = SUPC_CR_KEY(0xA5)  |SUPC_MR_ONREG_ONREG_USED |  SUPC_MR_BODDIS_DISABLE  ;  
     }
     //LCD Voltage regulator enable
     SUPC->SUPC_MR |= (SUPC_MR_KEY((uint32_t)0xA5u) | SUPC_MR_LCDMODE_LCDON_INVR | SUPC_MR_LCDVROUT(0xB)); // LCD regulator enable, internal supply, 3.29V
     
     ////Supply Monitor Reset disable
     read_reg = SUPC->SUPC_SMMR;
     read_reg&= SUPC_SMMR_SMRSTEN_NOT_ENABLE;
     SUPC->SUPC_SMMR = read_reg ;
     
     pmc_disable_pllack(); // PLLA 8MHz de-activated

     pmc_disable_all_pck();
} 


//*--------------------------------------------------------------------------------------
//* Function Name       : Prepare_Sleep_Mode
//* Object              : 
//* Input Parameters    : none.
//* Output Parameters   : none.
//*--------------------------------------------------------------------------------------
void Prepare_Sleep_Mode(ST_COMSUMPTION_MODE_DEVICE_SET *stconso_mode)
{
    prepare_mode(); 
    #define Reg_CCFG_SYSIO (unsigned int *) (0x400E0200 + 0x114)
    * Reg_CCFG_SYSIO = CCFG_SYSIO_SYSIO4 | CCFG_SYSIO_SYSIO5 | CCFG_SYSIO_SYSIO6  | CCFG_SYSIO_SYSIO7 | CCFG_SYSIO_SYSIO12;
    
    Save_Power_Consumption(stconso_mode);  
                 
    // ------ SLEEP MODE -------
    pmc_enable_periph_clk(ID_SUPC);
    
    PMC->PMC_FSMR = PMC_FSMR_RTTAL | PMC_FSMR_RTCAL;     // Startup RTT, RTC interrupt enable
}

void Prepare_Sleep_Mode_Periph_Conso(ST_COMSUMPTION_MODE_DEVICE_SET *stconso_mode)
{
    prepare_mode(); 
    #define Reg_CCFG_SYSIO (unsigned int *) (0x400E0200 + 0x114)
    * Reg_CCFG_SYSIO = CCFG_SYSIO_SYSIO4 | CCFG_SYSIO_SYSIO5 | CCFG_SYSIO_SYSIO6  | CCFG_SYSIO_SYSIO7 | CCFG_SYSIO_SYSIO12;
    
    //Save_Power_Consumption(stconso_mode);  //Dual core, SRAM0/1 should be enabled
                 
    // ------ SLEEP MODE -------
    pmc_enable_periph_clk(ID_SUPC);
    
    PMC->PMC_FSMR = PMC_FSMR_RTTAL | PMC_FSMR_RTCAL;     // Startup RTT, RTC interrupt enable
}


void Prepare_Sleep_Mode_C0(ST_COMSUMPTION_MODE_DEVICE_SET *stconso_mode)
{
    prepare_mode(); 
    #define Reg_CCFG_SYSIO (unsigned int *) (0x400E0200 + 0x114)
    * Reg_CCFG_SYSIO = CCFG_SYSIO_SYSIO4 | CCFG_SYSIO_SYSIO5 | CCFG_SYSIO_SYSIO6  | CCFG_SYSIO_SYSIO7 | CCFG_SYSIO_SYSIO12;
    
    Save_Power_Consumption(stconso_mode);  // Will be disabled by CORE1
                 
    // ------ SLEEP MODE -------
    pmc_enable_periph_clk(ID_SUPC);
    
    SUPC-> SUPC_WUIR  = SUPC_WUIR_WKUPEN1_ENABLE;
    // Fast Startup Input Enable 2 to 4
    PMC->PMC_FSMR = PMC_FSMR_RTTAL |PMC_FSMR_FSTT1;     // fast startup input 1 enable
}
//*--------------------------------------------------------------------------------------
//* Function Name       : Prepare_Wait_Mode
//* Object              : 
//* Input Parameters    : none.
//* Output Parameters   : none.
//*--------------------------------------------------------------------------------------
void Prepare_Wait_Mode(ST_COMSUMPTION_MODE_DEVICE_SET *stconso_mode )
{
    volatile unsigned int reg;
    
    prepare_mode();
    
    Select_MAINOSC_for_MCK(); //4MHz RC selected
    //ConfigurePIO_ForConsumption(stconso_mode); 
	
	pmc_enable_periph_clk(ID_PIOA);
    pmc_enable_periph_clk(ID_PIOB);
//    pmc_enable_periph_clk(ID_PIOC);                   

    // ------------ input mode
    PIOA->PIO_ODR  = 0xFFFFFFFF;
    PIOB->PIO_ODR  = 0xFFFFFFFF;        
//        PIOC->PIO_ODR  = 0x000003FF;  
        
    PIOA->PIO_PER  = 0xFFFFFFFF;
    PIOB->PIO_PER  = 0xFFFFFFFF;
//        PIOC->PIO_PER  = 0x000003FF;
        
    // ------------ All PIO pulldown disable
    PIOA->PIO_PPDDR = 0xFFFFFFFF;
    PIOB->PIO_PPDDR = 0xFFFFFFFF;
//        PIOC->PIO_PPDDR = 0x000003FF;
        
        // Pull-up Enable Register 
    PIOA->PIO_PUER = 0xFFFFFFFF;
    PIOB->PIO_PUER = 0xFFFFFFEF; //PB4 URXD0
//        PIOC->PIO_PUER = 0x000003FF;
	
	
    #define Reg_CCFG_SYSIO (unsigned int *) (0x400E0200 + 0x114)
    * Reg_CCFG_SYSIO = CCFG_SYSIO_SYSIO4 | CCFG_SYSIO_SYSIO5 | CCFG_SYSIO_SYSIO6  | CCFG_SYSIO_SYSIO7 | CCFG_SYSIO_SYSIO12;
         
    // ------ WAIT MODE -------
    pmc_enable_periph_clk(ID_SUPC);

	SUPC->SUPC_WUIR = SUPC_WUIR_WKUPEN0_ENABLE | SUPC_WUIR_WKUPT0_LOW | SUPC_WUIR_WKUPEN1_ENABLE | SUPC_WUIR_WKUPT1_LOW ; //WKUP0/TMP0 Enable for wake-up source, LOW active

    SCB-> SCR=0;

    PMC->PMC_FSMR |= PMC_FSMR_FSTT1 | PMC_FSMR_FSTT0; // Fast startup input 0 & 1 enable to wakeup PMC
    
    //Disable external 8.192MHZ OSC
    pmc_osc_disable_xtal(0);
	
    //Save_Power_Consumption(stconso_mode );
	
	pmc_disable_all_periph_clk(); 
	
	
}


void Save_Active_Power_Consumption( ST_COMSUMPTION_MODE_DEVICE_SET *stconso_mode)
{

    All_PIO_input_pullup(stconso_mode );
    // ---------- disable USB transceiver   

//     pmc_enable_periph_clk(ID_UDP);   
//    UDP->UDP_TXVC = UDP_TXVC_TXVDIS;
 
    pmc_enable_all_periph_clk();  
     
}

//*--------------------------------------------------------------------------------------
//* Function Name       : Run_Active_Mode
//* Object              : 
//* Input Parameters    : select all peripheral clocks ON or OFF
//* Output Parameters   : none.
//*--------------------------------------------------------------------------------------
void Run_Active_Mode(ST_COMSUMPTION_MODE_DEVICE_SET *stconso_mode)
{
    Save_Power_Consumption(stconso_mode);
    ConfigureFlash(stconso_mode);
}
/***************************************
****************************************/
void ConfigureFlash(ST_COMSUMPTION_MODE_DEVICE_SET *stconso_mode)
{
    if  (stconso_mode->flashCloe == CLOENABLE) //colde loop
    {
         EFC-> EEFC_FMR |= EEFC_FMR_CLOE;        
    }
    else 
    {
          EFC-> EEFC_FMR &= ~EEFC_FMR_CLOE;
    }
   while(!(EFC->EEFC_FSR & EEFC_FMR_FRDY));
   
    if  (stconso_mode->flashSocd == SOCDDISABLE) //Sequential code Optimization
    {
         EFC-> EEFC_FMR |= EEFC_FMR_CLOE;        
    }
    else 
    {
          EFC-> EEFC_FMR &= ~EEFC_FMR_CLOE;
    }
   while(!(EFC->EEFC_FSR & EEFC_FMR_FRDY));
    
     if (stconso_mode -> flashSetMode64_128== FAM64)  // by default flash is in 128 bits mode
    {       
         EFC->EEFC_FMR |= EEFC_FMR_FAM;  
    }
    else  //128
    {      
         EFC->EEFC_FMR&= ~EEFC_FMR_FAM;  
    }
    
   while(!(EFC->EEFC_FSR & EEFC_FMR_FRDY));
   
   ///SetWait State Depends of speed
}

//*--------------------------------------------------------------------------------------
//* Function Name       : EnableDisablePeripheral
//* Object              : 
//* Input Parameters    : none.
//* Output Parameters   : none.
//*--------------------------------------------------------------------------------------
void EnableDisablePeripheral(ST_COMSUMPTION_MODE_DEVICE_SET *stconso_mode)
{
     
volatile unsigned int ii;
  
    if( stconso_mode->PeripheralStates==PERIPH_CLOCK_ON)
    {   
     //pmc_enable_all_periph_clk
        PMC->PMC_PCER0 = 0xffffffff;         
        for ( ii=0; ii< 1000; ii++ ); 
        PMC->PMC_PCER1 = 0xffffffff;

    }
    else 
    {      
        PMC->PMC_PCER0 = 0xffffffff;
        PMC->PMC_PCER1 = 0xffffffff;
        for ( ii=0; ii< 1000; ii++ );          
        PMC->PMC_PCDR0 = 0xffffffff;
        PMC->PMC_PCDR1 = 0xffffffff;
    }
}

void   SetWaitState(  unsigned int  value   )
{
    
    unsigned int  r=EFC->EEFC_FMR;
    
    r &= ~EEFC_FMR_FWS_Msk;
    r |= EEFC_FMR_FWS(value) ;
    EFC->EEFC_FMR=r;
    
    while(!(EFC->EEFC_FSR & EEFC_FMR_FRDY)); 
}
//*--------------------------------------------------------------------------------------
//* Function Name       : Select_MAINOSC_for_MCK
//* Object              : 
//* Input Parameters    : none.
//* Output Parameters   : none.
//*--------------------------------------------------------------------------------------

void Select_MAINOSC_for_MCK(void)
{
    pmc_disable_all_pck();
    pmc_osc_enable_fastrc(CKGR_MOR_MOSCRCF_4_MHz);
    pmc_switch_mainck_to_fastrc(0); // 0 for 4Mhz, 1 for 8Mhz and 2 for 12Mhz.
    
    PMC->PMC_MCKR = (PMC->PMC_MCKR & ~PMC_MCKR_CSS_Msk) | PMC_MCKR_CSS_MAIN_CLK;
    while( !(PMC->PMC_SR & PMC_SR_MCKRDY) );
    pmc_osc_disable_xtal(1);
    
    PMC->PMC_MCKR = (PMC->PMC_MCKR & ~PMC_MCKR_PRES_Msk) | PMC_MCKR_PRES_CLK_1;
    
    // -------- Wait until the master clock is established
    
    while( !(PMC->PMC_SR & PMC_SR_MCKRDY) );
    
    pmc_disable_pllbck(); //PLLB deactivated
}

//=========================================================
//decription	::	low power mode select main osc is 32khz
//function		::	LowPower_Select_MAINOSC_for_32k
//input			::	none
//output		::	none
//call			::	none
//effect		::	none
//=========================================================
void LowPower_Select_MAINOSC_for_32k(void)
{
    pmc_disable_all_pck();
    pmc_switch_mck_to_sclk(0);//switch clock to 32kHz

    while( !(PMC->PMC_SR & PMC_SR_MCKRDY) );
	
	PMC->PMC_MCKR &=0xFF00FFFF;	//coprocessor clock is slock
	
    pmc_osc_disable_xtal(1);
       
    pmc_disable_pllbck(); //PLLB deactivated
	
}

void _pmc_enable_waitmodewithoutWFE(void)
{
        //#define Reg_PMC_FSMR (unsigned int *) (0x400E0470)
        //* Reg_PMC_FSMR |= (1<<20);
  	//PMC->PMC_FSMR |= PMC_FSMR_LPM;	// Enter Wait mode
	SCB->SCR &= (uint32_t) ~ SCB_SCR_SLEEPDEEP_Msk;	// sleep no deep 
        
        PMC->CKGR_MOR |= CKGR_MOR_KEY(0x37u) | CKGR_MOR_WAITMODE;
        while( !(PMC->PMC_SR & PMC_SR_MCKRDY) );
/*        
        //For wake-up time measurement
        REG_PIOA_CODR |= (1<<0);
*/
}

void _pmc_enable_backupmode_vroff(void)
{
	SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;
        SUPC->SUPC_CR= (0xA5 << 24 ) | SUPC_CR_VROFF_STOP_VREG ;
}



/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
}
#endif
/**INDENT-ON**/
/// @endcond