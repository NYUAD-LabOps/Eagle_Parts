// $asf_license$

/*! \file *********************************************************************
 *
 * \brief PMC driver for SAM3.
 *
 * Power Management Controller (PMC) driver module for SAM MCUs.
 *
 * - Compiler:           IAR EWARM and GNU GCC for SAM.
 * - Supported devices:  All SAM devices.
 * - AppNote:
 *
 ******************************************************************************/

#include "v_pmc.h"


// ERr : already defined in ASF drivers/pmc.c
#define MASK_STATUS0	0xFFFFFFFC
#define MASK_STATUS1	0xFFFFFFFF

#define PMC_TIMEOUT		2048



/**
 * \brief Switch master clock source selection to main clock.
 *
 * \param dw_pres Processor clock prescaler.
 * \param dw_mdiv system clock divider.
 * \param plldiv2 PLL output divider (0 or 1).
 *
 * \retval 0 Success.
 * \retval 1 Timeout error.
 */
//ERr: added MDIV & PLLDIV2 fields management
uint32_t v_pmc_switch_mck_to_mainck(uint32_t dw_pres,uint32_t dw_mdiv)
{
 uint32_t dw_timeout;
 uint32_t pres_mdiv;

  PMC->PMC_MCKR = (PMC->PMC_MCKR & (uint32_t) ~ PMC_MCKR_CSS_Msk) | PMC_MCKR_CSS_MAIN_CLK;
  for (dw_timeout = PMC_TIMEOUT; !(PMC->PMC_SR & PMC_SR_MCKRDY);--dw_timeout){
    if (dw_timeout == 0){return 1;}
    }

  pres_mdiv = (PMC->PMC_MCKR & (uint32_t) ~ PMC_MCKR_PRES_Msk) | dw_pres;
#if(PMC_HAS_MCKR_FIELD_MDIV==1)
   pres_mdiv = (PMC->PMC_MCKR & (uint32_t) ~ PMC_MCKR_MDIV_Msk) | dw_mdiv;
#endif
  
  PMC->PMC_MCKR = pres_mdiv;
  for (dw_timeout = PMC_TIMEOUT; !(PMC->PMC_SR & PMC_SR_MCKRDY);--dw_timeout){
    if (dw_timeout == 0){return 1;}
    }
  
  return 0;
}


/**
 * \brief Switch master clock source selection to plla clock.
 *
 * \param dw_pres Processor clock prescaler.
 * \param dw_mdiv system clock divider.
 * \param plldiv2 PLL output divider (0 or 1).
 *
 * \retval 0 Success.
 * \retval 1 Timeout error.
 */
//ERr: added MDIV & PLLDIV2 fields management
uint32_t v_pmc_switch_mck_to_pllack(uint32_t dw_pres,uint32_t dw_mdiv,uint8_t plldiv2)
{
 uint32_t dw_timeout;
 uint32_t pres_mdiv;


  pres_mdiv = (PMC->PMC_MCKR & (uint32_t) ~ PMC_MCKR_PRES_Msk) | dw_pres;
#if(PMC_HAS_MCKR_FIELD_MDIV==1)
  pres_mdiv = (pres_mdiv & (uint32_t) ~ PMC_MCKR_MDIV_Msk) | dw_mdiv;
#endif

#if (SAM3XA || SAM3S || SAM3S8 || SAM3U || SAM4S || SAMA5 || SAM4N || CM4P2 || SAM4C ) //ERr SAM4S SAM3S8 SAMA5 SAM4N CM4P2 AYi SAM4C
  if(plldiv2)
    {pres_mdiv = pres_mdiv | PMC_MCKR_PLLADIV2;}
  else
    {pres_mdiv = pres_mdiv & ~PMC_MCKR_PLLADIV2;}
#else //ERr??
  if(plldiv2)
    {pres_mdiv = pres_mdiv | PMC_MCKR_PLLDIV2;}
  else
    {pres_mdiv = pres_mdiv & ~PMC_MCKR_PLLDIV2;}
#endif
  
  PMC->PMC_MCKR = pres_mdiv;
  for (dw_timeout = PMC_TIMEOUT; !(PMC->PMC_SR & PMC_SR_MCKRDY);--dw_timeout){
    if (dw_timeout == 0){return 1;}
    }
 
#if (SAM3XA || SAM3S || SAM3S8 || SAM3U || SAM4S || SAMA5 || SAM4N || CM4P2 || SAM4C ) //ERr SAM4S SAM3S8 SAMA5 SAM4N CM4P2  AYi SAM4C
  PMC->PMC_MCKR = (PMC->PMC_MCKR & (uint32_t) ~ PMC_MCKR_CSS_Msk) | PMC_MCKR_CSS_PLLA_CLK;
#else
  PMC->PMC_MCKR = (PMC->PMC_MCKR & (uint32_t) ~ PMC_MCKR_CSS_Msk) | PMC_MCKR_CSS_PLL_CLK;
#endif
  for (dw_timeout = PMC_TIMEOUT; !(PMC->PMC_SR & PMC_SR_MCKRDY);--dw_timeout){
    if (dw_timeout == 0){return 1;}
    }

  return 0;
}



/**
 * \brief Switch programmable clock source selection to master clock.
 *
 * \param dwId Id (number) of the programmable clock.
 * \param dwPres Programmable clock prescaler. The dwPres argument must not be shifted.
 *
 * \retval 0 Success.
 * \retval 1 Timeout error.
 * \retval 2 Invalid prescaler selection.
 */
extern uint32_t pmc_switch_pck_to_mck( uint32_t dwId, uint32_t dwPres )
{
	uint32_t timeout;
	
	if ( dwPres > 6 )
		return 2;
	
    PMC->PMC_PCK[dwId] = PMC_PCK_CSS_MCK | dwPres << 4 ;
    for ( timeout = PMC_TIMEOUT; !(PMC->PMC_SR & (PMC_SR_PCKRDY0 << dwId)); --timeout )
		if (timeout == 0)
			return 1;
			
	return 0;
}


/**
 * \brief Enable all peripheral clocks.
 */
// Corrected ASF function / ERr
extern void v_pmc_enable_all_periph_clk(void)
{
#if (SAM3N || SAM3U)
	PMC->PMC_PCER = MASK_STATUS0;
	//while ((PMC->PMC_PCSR & MASK_STATUS0) != MASK_STATUS0);
#elif (SAM4N)
	PMC->PMC_PCER0 = MASK_STATUS0;
	//while ((PMC->PMC_PCSR & MASK_STATUS0) != MASK_STATUS0);
#else
	PMC->PMC_PCER0 = MASK_STATUS0;
	//while ((PMC->PMC_PCSR0 & MASK_STATUS0) != MASK_STATUS0);

	PMC->PMC_PCER1 = MASK_STATUS1;
	//while ((PMC->PMC_PCSR1 & MASK_STATUS1) != MASK_STATUS1);
#endif
}



/**
 * \brief Switch slow clock source selection to external 32k (Xtal or Bypass).
 * This function disables the PLLs.
 *
 * Note: Switching back sclk to 32krc is only possible by shutting down the VDDIO power supply.
 *
 * \param dw_bypass 0 for Xtal, 1 for bypass.
 * 
 */
// ASF function updated for SAMA5 / ERr
void v_pmc_switch_sclk_to_32kxtal(uint32_t dw_bypass)
{
#if (SAMA5==1)
  if (dw_bypass == 1){SCKC->SCKC_CR |= SCKC_CR_OSC32BYP;}
  else {SCKC->SCKC_CR |= SCKC_CR_OSC32EN;}
  SCKC->SCKC_CR = (SCKC->SCKC_CR & ~SCKC_CR_OSCSEL)|SCKC_CR_OSCSEL_XTAL;
#else //#elif (SAM3S==1 || SAM3U==1 || SAM3N==1 || SAM3X==1 || SAM4S==1)
  if (dw_bypass == 1) SUPC->SUPC_MR |= SUPC_MR_KEY((uint32_t) 0xA5) | SUPC_MR_OSCBYPASS;
  SUPC->SUPC_CR |= SUPC_CR_KEY((uint32_t) 0xA5) | SUPC_CR_XTALSEL;
#endif
}
