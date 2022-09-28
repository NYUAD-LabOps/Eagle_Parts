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

#ifndef _SAM_WDT_H
#define _SAM_WDT_H

#include "project.h"

// ---- General purpose include files
//#include <stdio.h> //IAR
#include "device.h"


typedef enum{
       ALL_RESET = 0,
	 PROCESSOR_RESET = 1
}wdrproc_t;

typedef enum{
       RUN_IDLE_STATE = 0,
	 STOP_IDLE_STATE = 1
}wdidlehlt_t;

typedef enum{
       RUN_DBG_STATE = 0,
	 STOP_DBG_STATE = 1
}wddbghltc_t;

typedef enum{
       WDT_INT_EN = 1,
	 WDT_INT_DIS = 0
}wdtint_t;

typedef enum{
       WDT_RST_EN = 1,
	 WDT_RST_DIS = 0
}wdtrst_t;

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
                                                   wdrproc_t wdrproc,wddbghltc_t wddbghlt,wdidlehlt_t wdidlehlt);

/**
 * \brief Disable the watchdog timer.
 *
 */
extern uint32_t wdt_disable( Wdt* p_wdt ) ;

/**
 * \brief Restart the watchdog.
 */
extern uint32_t wdt_restart( Wdt* p_dwt ) ;

/**
 * \brief Read the watchdog status.
 */
extern uint32_t wdt_get_status( Wdt* p_dwt ) ;



#endif//#ifndef _SAM_WDT_H