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

#ifndef _V_SUPC_H
#define _V_SUPC_H

#include "project.h"

// ---- General purpose include files
//#include <stdio.h> //IAR
#include "device.h"





/**
 * \brief Switch off the voltage regulator to put the device in backup mode
 * \param p_supc Pointer to a supc registers set instance
 */
//extern void supc_enter_backupmode( Supc* p_supc ) ;

/**
 * \brief Select the crystal oscillator to be the source of the slow clock
 * \param p_supc Pointer to a supc registers set instance
 */
//extern void supc_select_crystal_slowclock( Supc* p_supc ) ;

/**
 * \brief Set the crystal oscillator in bypass mode instead of connecting a crystal
 * \param p_supc Pointer to a supc registers set instance
 * \note Coming back on the RC oscillator is only possible by shutting down the VDDIO power supply
 */
//extern void supc_bypass_crystal_slowclock( Supc* p_supc ) ;

/**
 * \brief Enable the internal voltage regulator.
 * \param p_supc Pointer to a supc registers set instance
 * \note Coming back on the RC oscillator is only possible by shutting down the VDDIO power supply
 */
extern void supc_enable_voltage_regulator( Supc* p_supc ) ;

/**
 * \brief Disable the internal voltage regulator to supply VDDCORE by an external supply
 * \param p_supc Pointer to a supc registers set instance
 */
extern void supc_disable_voltage_regulator( Supc* p_supc ) ;

/**
 * \brief Enable the core brownout detector
 * \param p_supc Pointer to a supc registers set instance
 */
extern void supc_enable_brownout_detector( Supc* p_supc ) ;

/**
 * \brief Disable the core brownout detector
 * \param p_supc Pointer to a supc registers set instance
 */
extern void supc_disable_brownout_detector( Supc* p_supc ) ;

/**
 * \brief The core reset signal when a brownout detection occurs
 * \param p_supc Pointer to a supc registers set instance
 */
extern void supc_enable_brownout_resetsignal( Supc* p_supc ) ;

/**
 * \brief No core reset signal when a brownout detection occurs
 * \param p_supc Pointer to a supc registers set instance
 */
extern void supc_disable_brownout_resetsignal( Supc* p_supc ) ;



/**
 * \brief Set Supply monitor threshold
 * \param p_supc Pointer to a supc registers set instance
 *
 * \param dw_threshold Supply monitor threshold
 *            SUPC_SMMR_SMTH_x_xV between _1_9V and _3_4V
 * //ERr(0x00-0x0F)
 */
extern uint32_t supc_set_monitor_threshold( Supc* p_supc , uint32_t dw_threshold) ;

/**
 * \brief Set Supply monitor sampling period
 * \param p_supc Pointer to a supc registers set instance
 *
 * \param dw_period Supply monitor sampling period
 *          SUPC_SMMR_SMSMPL_SMD      => disable
 *          SUPC_SMMR_SMSMPL_CSM      => continuous sampling
 *          SUPC_SMMR_SMSMPL_32SLCK   => one period on 32 slow clock periods
 *          SUPC_SMMR_SMSMPL_256SLCK  => one period on 256 slow clock periods
 *          SUPC_SMMR_SMSMPL_2048SLCK => one period on 2048 slow clock periods
 * //ERr(0x00-0x07)
 */
extern uint32_t supc_set_monitor_sampling_period( Supc* p_supc , uint32_t dw_period) ;

/**
 * \brief The core reset signal, vddcore_nreset is asserted when a supply monitor detection occurs
 * \param p_supc Pointer to a supc registers set instance
 */
extern void supc_enable_monitor_reset( Supc* p_supc ) ;

/**
 * \brief No core reset signal, vddcore_nreset when a supply monitor detection occurs
 * \param p_supc Pointer to a supc registers set instance
 */
extern void supc_disable_monitor_reset( Supc* p_supc ) ;

/**
 * \brief the SUPC interrupt signal is asserted when a supply monitor detection occurs
 * \param p_supc Pointer to a supc registers set instance
 */
extern void supc_enable_monitor_interrupt( Supc* p_supc ) ;

/**
 * \brief the SUPC interrupt signal is not affected when a supply monitor detection occurs
 * \param p_supc Pointer to a supc registers set instance
 */
extern void supc_disable_monitor_interrupt( Supc* p_supc ) ;

/**
 * \brief Set system controller wake up mode
 * \param p_supc Pointer to a supc registers set instance
 * \param dw_mode Wake up mode.
 */
//extern void supc_set_wakeup_mode ( Supc* p_supc , uint32_t dw_mode) ;

/**
 * \brief Get system controller wake up mode
 * \param p_supc Pointer to a supc registers set instance
 * \return Wake up mode.
 */
//extern uint32_t supc_get_wakeup_mode ( Supc* p_supc ) ;

/**
 * \brief Set system controller wake up inputs
 * \param p_supc Pointer to a supc registers set instance
 * \param dw_inputs wake up inputs mode.
 */
//extern void supc_set_wakeup_inputs ( Supc* p_supc , uint32_t dw_inputs) ;

/**
 * \brief Get supply controller status register
 * \param p_supc Pointer to a supc registers set instance
 * \return The value of status register
 */
//extern uint32_t supc_read_status( Supc* p_supc ) ;


#endif//#ifndef _V_SUPC_H