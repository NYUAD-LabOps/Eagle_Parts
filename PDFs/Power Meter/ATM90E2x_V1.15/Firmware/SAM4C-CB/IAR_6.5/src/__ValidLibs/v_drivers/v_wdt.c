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

#include "v_wdt.h"


/**
 * \brief enable the watchdog with given mode.
 *
 * \param ul_wdv   defines the value loaded in the 12-bit Watchdog Counter.
 * \param ul_wdrproc   a Watchdog fault (underflow or error) activates all or processor resets.
 * \param ul_wdd    defines the permitted range for reloading the Watchdog Timer. 
 * \param wdint   watchdog Fault Interrupt Enable
 * \param wdrst   watchdog Reset Enable
 * \param wdrproc  watchdog Reset mode
 * \param ul_wddbghlt   the Watchdog runs or stop when the processor is in debug state.
 * \param ul_wdidlehlt   the Watchdog runs or stop when the processor is in idle state.
 */
extern uint32_t wdt_enable( Wdt* p_wdt, uint32_t ul_wdv,uint32_t ul_wdd,wdtint_t wdint,wdtrst_t wdrst,
                                                   wdrproc_t wdrproc,wddbghltc_t wddbghlt,wdidlehlt_t wdidlehlt)
{
  uint32_t dwMode=0;
  
  dwMode=WDT_MR_WDV(ul_wdv)|WDT_MR_WDD(ul_wdd);
  if(wdint)dwMode|=WDT_MR_WDFIEN;
  if(wdrst)dwMode|=WDT_MR_WDRSTEN;
  if(wdrproc)dwMode|=WDT_MR_WDRPROC;
  if(wddbghlt)dwMode|=WDT_MR_WDDBGHLT;
  if(wdidlehlt)dwMode|=WDT_MR_WDIDLEHLT;
  
  p_wdt->WDT_MR = dwMode ;
  return 0;
}


extern uint32_t wdt_disable( Wdt* p_wdt )
{
  p_wdt->WDT_MR = WDT_MR_WDDIS;
  return 0;
}


/**
 * \brief Restart the watchdog.
 */
extern uint32_t wdt_restart( Wdt* p_dwt )
{
  //p_dwt->WDT_CR = 0xA5000001;
  p_dwt -> WDT_CR = WDT_CR_KEY(WDT_KEY_VAL) | WDT_CR_WDRSTT;
  return 0;
}


/**
 * \brief Read the watchdog status.
 */
extern uint32_t wdt_get_status( Wdt* p_dwt )
{
  return (p_dwt->WDT_SR & 0x3) ;
}

////////////////////////////////////////////////////////////////////////////////

