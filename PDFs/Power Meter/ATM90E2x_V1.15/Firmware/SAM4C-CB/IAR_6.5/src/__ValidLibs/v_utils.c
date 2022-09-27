/*-----------------------------------------------------------------------------
 *           ATMEL Microcontroller Software Support  -  ROUSSET  -
 *-----------------------------------------------------------------------------
 * DISCLAIMER:  THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *----------------------------------------------------------------------------
 * File Name           : v_utils.c
 *----------------------------------------------------------------------------
*/

#include "v_utils.h"


// global variables
extern unsigned int  MCK_clock_speed;


#define SLOW_CLOCK_SELECTED ((PMC->PMC_MCKR & PMC_MCKR_CSS_Msk)==(PMC_MCKR_CSS_SLOW_CLK & PMC_MCKR_CSS_Msk))

/*----------------------------------------------------------------------------*/
/* Reset sources messages                                                     */
/*----------------------------------------------------------------------------*/
#if (DEVICE_HAS_SUPC == 1)
const char reset_source_msg[NB_RST_SOURCE][RST_LABEL_SIZE]={"POR_RESET", \
  "WUP_RESET","WDT_RESET","SW_RESET","USR_RESET","BOD_RESET","SM_RESET"};
#else
const char reset_source_msg[NB_RST_SOURCE][RST_LABEL_SIZE]={"POR_RESET", \
  "BUP_RESET","WDT_RESET","SW_RESET","USR_RESET"};
#endif
/*----------------------------------------------------------------------------*/


#ifndef SAMA5 //ERr SAMA5
/*----------------------------------------------------------------------------*/
//* Function Name       : external_reset_enable
//* Object              : enable external reset
//*---------------------------------------------------------------------------*/
extern void external_reset_enable(void)
{
  REG_RSTC_MR = RSTC_CR_KEY(RSTC_KEY_VAL) | RSTC_MR_URSTEN;
}

/*----------------------------------------------------------------------------*/
//* Function Name       : external_reset_disable
//* Object              : disable external reset
//*---------------------------------------------------------------------------*/
extern void external_reset_disable(void)
{
  REG_RSTC_MR = RSTC_CR_KEY(RSTC_KEY_VAL) & (~RSTC_MR_URSTEN);
}
#endif //ERr SAMA5


/*----------------------------------------------------------------------------*/
//* Function Name       : watchdog_enable
//* Object              : enable watchdog with predefined parameters
//                          * time parameter (ms)
//                          * delay window disabled
//                          * wdt halts for debug state
//                          * wdt runs for idle mode
//                          * wdt fault triggers reset
//                                * wdt fault activates all resets
//                          * wdt fault asserts interrupt
//*---------------------------------------------------------------------------*/
extern void watchdog_enable(uint32_t time)
{
  uint32_t ul_wdv;

  if (time == WDT_MAX)ul_wdv = 0xFFF; // 12bits value
  else{
    ul_wdv = (time*1000)/(128*1000000/SLOW_CLOCK_FREQ);
    if (ul_wdv > 0xFFF)ul_wdv=0xFFF;
  }
  
  wdt_enable(WDT,ul_wdv,ul_wdv,WDT_INT_EN,WDT_RST_EN,ALL_RESET,STOP_DBG_STATE,RUN_IDLE_STATE);
}


// -----------------------------------------------------------------------------
//  Function Name       : config_clocks
//  Object              : configure master clock using project.h definitions
// -----------------------------------------------------------------------------
// 
////////////////////////////////////////////////////////////////////////////////
#if (PMC_HAS_MCKR_FIELD_MDIV==0)
  #undef  MCK_MDIV
  #define MCK_MDIV 0 //not used
#endif
extern uint32_t config_clocks(void)
{
  return (set_clocks(MAIN_CLK_CONFIG,MCK_CONFIG,PLLA_MUL,PLLA_DIV,PCK_PRESCALER,MCK_MDIV));
}


// -----------------------------------------------------------------------------
//  Function Name       : set_clocks
//  Object              : configure master clock
// -----------------------------------------------------------------------------
//  Parameters:
//       main_clk_config   : USE_RC_xMHZ or USE_EXT_CLK or USE_XTAL
//       mck_config        : USE_MAIN_CLK or USE_PLLA or USE_SLOW_CLOCK
//       plla_mul          : PLLA multiplier value
//       plla_div          : PLLA divider value
//       pck_prescaler     : processor clock divider value = 1,8,16,32,64
//       mck_div           : master clock divider value 1,2,4,3 (device dependant)
////////////////////////////////////////////////////////////////////////////////
extern uint32_t set_clocks(uint8_t main_clk_config, uint8_t mck_config, \
             uint8_t plla_mul, uint8_t plla_div, uint8_t pck_prescaler, \
             uint8_t mck_div)
{ 
 //unsigned int  main_clk_speed, pll_speed;
 uint32_t prescaler, mdiv, main_clk_speed, pll_speed;
 
  if(SLOW_CLOCK_SELECTED)pmc_switch_mck_to_mainck(0); 
    // Slow clock setting
   switch(SLOW_CLK_CONFIG)
   {
   case USE_XTAL:
     v_pmc_switch_sclk_to_32kxtal(0);
     break;
   case USE_EXT_CLK:
     v_pmc_switch_sclk_to_32kxtal(1); // Bypass
     break;
   default: // USE_RC_32KHZ
     break;
   }//switch SLOW_CLK_CONFIG

   
   // Prescaler
   switch(pck_prescaler)
   {
   case 1:
     prescaler = PMC_MCKR_PRES_CLK_1;
     break;
   case 2:
     prescaler = PMC_MCKR_PRES_CLK_2;
     break;
   case 4:
     prescaler = PMC_MCKR_PRES_CLK_4;
     break;
   case 8:
     prescaler = PMC_MCKR_PRES_CLK_8;
     break;
   case 16:
     prescaler = PMC_MCKR_PRES_CLK_16;
     break;
   case 32:
     prescaler = PMC_MCKR_PRES_CLK_32;
     break;
   case 64:
     prescaler = PMC_MCKR_PRES_CLK_64;
     break;
   // ERr: prescaler=3 not supported on all products
   //case 3:
   //  prescaler = PMC_MCKR_PRES_CLK_3;
   //  break;
   default:
     prescaler = PMC_MCKR_PRES_CLK_1;
     break;
   }//switch pck_prescaler

   if(!SLOW_CLOCK_SELECTED)pmc_switch_mck_to_sclk(prescaler); 

   // Main clock
   switch(main_clk_config)
   {
   case USE_RC_12MHZ:
           pmc_switch_mainck_to_fastrc(2); // select internal RC / RC=12MHz
           //main_clk_speed = (PMC->CKGR_MCFR)&CKGR_MCFR_MAINF_Msk;
           //main_clk_speed = main_clk_speed*SLOW_CLOCK_FREQ/16;
           main_clk_speed = 12000000;
           break;
               
   case USE_RC_8MHZ:
           pmc_switch_mainck_to_fastrc(1); // select internal RC / RC=8MHz
           //main_clk_speed = (PMC->CKGR_MCFR)&CKGR_MCFR_MAINF_Msk;
           //main_clk_speed = main_clk_speed*SLOW_CLOCK_FREQ/16;
           main_clk_speed = 8000000;
           break;
      
   case USE_RC_4MHZ:
           pmc_switch_mainck_to_fastrc(0); // select internal RC / RC=4MHz
           //main_clk_speed = (PMC->CKGR_MCFR)&CKGR_MCFR_MAINF_Msk;
           //main_clk_speed = main_clk_speed*SLOW_CLOCK_FREQ/16;
           main_clk_speed = 4000000;
           break;
      
   case USE_EXT_CLK:
           pmc_switch_mainck_to_xtal(1); // xtal / bypass mode
           main_clk_speed = EXT_CLOCK_FREQ;
           break;
 
   case USE_XTAL:
           pmc_switch_mainck_to_xtal(0); // xtal no bypass 
           main_clk_speed = BRD_MAIN_XTAL; // board.h definition
           break;   
   
   default:
           pmc_switch_mainck_to_xtal(0); // xtal no bypass (test)
           main_clk_speed = BRD_MAIN_XTAL;    
           break;
   }//End Switch main_clk_config

   
#if (PMC_HAS_MCKR_FIELD_MDIV==1)
  switch(mck_div)
   {
   case 1:
     mdiv = PMC_MCKR_MDIV_EQ_PCK;
     break;
   case 2:
     mdiv = PMC_MCKR_MDIV_PCK_DIV2;
     break;
   case 4:
     mdiv = PMC_MCKR_MDIV_PCK_DIV4;
     break;
   case 3:
     mdiv = PMC_MCKR_MDIV_PCK_DIV3;
     break;
   default:
     mdiv = PMC_MCKR_MDIV_PCK_DIV2;
     break;
   }//switch mck_div
#else
   mdiv = 0;
#endif

   
   switch(mck_config)
   {
   case USE_PLLA:
          // (PLLACOUNT max)
          pmc_enable_pllack((plla_mul-1),CKGR_PLLAR_PLLACOUNT_Msk,plla_div);
          pll_speed = (main_clk_speed*plla_mul)/plla_div;
          if(v_pmc_switch_mck_to_pllack(prescaler,mdiv,0)){return 1;}
          MCK_clock_speed = pll_speed / pck_prescaler;
          break;
/*
   case USE_PLLB:
           pmc_enable_pllbck((PLLB_MUL-1),CKGR_PLLBR_PLLBCOUNT_Msk,PLLB_DIV);
           pmc_switch_mck_to_pllbck(prescaler);
           pll_speed = main_clk_speed*PLLB_MUL/PLLB_DIV;
           MCK_clock_speed = pll_speed / pck_prescaler;
           break;
*/           
   case USE_MAIN_CLK:
           if(v_pmc_switch_mck_to_mainck(prescaler,mdiv)){return 1;}
           MCK_clock_speed = main_clk_speed / pck_prescaler;
           break;
   
   default: // Use slow clock
           //pmc_switch_mck_to_sclk(prescaler);
           MCK_clock_speed = 32768 / pck_prescaler;
           break;
   }//End Switch mck_config

#if (PMC_HAS_MCKR_FIELD_MDIV==1)
  MCK_clock_speed = MCK_clock_speed / mck_div;
#endif

   return 0;
}



/*----------------------------------------------------------------------------*/
//* Function Name       : check_reset_source
//* Object              : returns last reset cause code (v_utils.h definitions):
//                          * POR_RESET : power up
//                          * BUP_RESET : return from backup mode
//                          * WDT_RESET : watchdog fault detect
//                          * SW_RESET  : software reset
//                          * USR_RESET : user reset (external NRST)
//                          * BOD_RESET : brownout detect
//                          * SM_RESET  : supply monitor detect
//*---------------------------------------------------------------------------*/
extern uint32_t check_reset_source()
{
 uint32_t reset_cause;
#if (DEVICE_HAS_SUPC == 1)
   if (SUPC->SUPC_SR & SUPC_SR_BODRSTS) reset_cause = BOD_RESET;
   else if (SUPC->SUPC_SR & SUPC_SR_SMRSTS) reset_cause = SM_RESET;
   else reset_cause = (RSTC->RSTC_SR & RSTC_SR_RSTTYP_Msk)>>RSTC_SR_RSTTYP_Pos;
#else
   reset_cause = (RSTC->RSTC_SR & RSTC_SR_RSTTYP_Msk)>>RSTC_SR_RSTTYP_Pos;
#endif
 return reset_cause;
}


/*----------------------------------------------------------------------------*/
//* Function Name       : wait_loop
//* Object              : basic counter loop
///*---------------------------------------------------------------------------*/
extern void wait_loop(uint32_t count)
{
 volatile unsigned int i;

  for(i=0;i<count;++i);
}


/*----------------------------------------------------------------------------*/
//* Function Name       : wait_loop
//* Object              : counter loop based wait time function (approximation)
//*                       time = time to wait (ms)
///*---------------------------------------------------------------------------*/
extern void wait_time(uint32_t time)
{
 //volatile unsigned int i;
 unsigned int i;
 uint32_t count;

   count = ((MCK_clock_speed/1000)/WAIT_LOOP_ITER_CYCLES)*time;
   for(i=count;i--;);
}


/*----------------------------------------------------------------------------*/
//* Function Name       : brownout_detector_enable
//* Object              : enable BOD with predefined parameters
//                          * vddcore_nreset asserted on brownout detection
//*---------------------------------------------------------------------------*/
#if DEVICE_HAS_SUPC
extern void brownout_detector_enable()
{
  supc_enable_brownout_resetsignal(SUPC);
  supc_enable_brownout_detector(SUPC);
}
#endif


/*----------------------------------------------------------------------------*/
//* Function Name       : supply_monitor_enable
//* Object              : enable SM with predefined parameters
//                          * threshold value defined in project.h
//                          * continuous sampling
//                          * vddcore_nreset asserted on SM detection
//                          * SUPC interrupt signal asserted on SM detection
//*---------------------------------------------------------------------------*/
#if DEVICE_HAS_SUPC
extern void supply_monitor_enable()
{
  supc_set_monitor_threshold(SUPC,SM_THRESHOLD);
  supc_enable_monitor_reset(SUPC);
  supc_enable_monitor_interrupt(SUPC);
  supc_set_monitor_sampling_period(SUPC,SUPC_SMMR_SMSMPL_CSM); //enable
}
#endif


/*----------------------------------------------------------------------------*/
//* Function Name       : supply_monitor_disable
//* Object              : disable Supply Monitor
//*---------------------------------------------------------------------------*/
#if DEVICE_HAS_SUPC
extern void supply_monitor_disable()
{
  supc_set_monitor_sampling_period(SUPC,SUPC_SMMR_SMSMPL_SMD); 
}
#endif


/*----------------------------------------------------------------------------*/
//* Function Name       : Display embedded flash descriptor on DBGU
//* Object              : display_flash_desc_dbgu
//*---------------------------------------------------------------------------*/
#if DEVICE_HAS_EFC0
extern void display_flash_desc_dbgu(iflash_descriptor_t* fdes)
{
  uint32_t i;
  char msg[50];
  
    DEBUG_Printk("  ============================================\n\r");
    sprintf(msg,"  ========> Flash ID = %X\n\r",fdes->fl_id); DEBUG_Printk(msg);
    sprintf(msg,"  ======> Flash Size = %d\n\r",fdes->fl_size); DEBUG_Printk(msg);
    sprintf(msg,"  => Flash Page Size = %d\n\r",fdes->fl_page_size); DEBUG_Printk(msg);
    sprintf(msg,"  => Flash Nb Planes = %d\n\r",fdes->fl_nb_plane); DEBUG_Printk(msg);
    sprintf(msg,"  ==> Flash Nb Locks = %d\n\r",fdes->fl_nb_lock); DEBUG_Printk(msg);
    DEBUG_Printk("  --------------------------------------------\n\r");
  for(i=0;i<fdes->fl_nb_plane;++i){
    sprintf(msg,"  => Flash Plane %d: %d Bytes\n\r",i,fdes->fl_plane[i]); DEBUG_Printk(msg);
    }
    DEBUG_Printk("  --------------------------------------------\n\r");
  for(i=0;i<fdes->fl_nb_lock;++i){
    sprintf(msg,"  => Lock Region %d: %d Bytes\n\r",i,fdes->fl_lock[i]); DEBUG_Printk(msg);
    }
    DEBUG_Printk("  --------------------------------------------\n\r");
    DEBUG_Printk("  ============================================\n\r");
    DEBUG_Printk("\n\r");
    DEBUG_Printk("\n\r");
}
#endif
