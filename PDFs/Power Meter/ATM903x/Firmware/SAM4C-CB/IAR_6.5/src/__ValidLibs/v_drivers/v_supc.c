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

#include "v_supc.h"





/**
 * \brief Enable the internal voltage regulator.
 * \param p_supc Pointer to a supc registers set instance
 * \note Coming back on the RC oscillator is only possible by shutting down the VDDIO power supply
 */
extern void supc_enable_voltage_regulator( Supc* p_supc )
{  
  uint32_t mode;
  
    mode =  p_supc->SUPC_MR;
    p_supc->SUPC_MR = SUPC_MR_KEY(SUPC_KEY_VAL) | ( mode | SUPC_MR_ONREG );
    //p_supc->SUPC_CR = SUPC_CR_KEY(SUPC_KEY_VAL) | SUPC_CR_VROFF_STOP_VREG ;
}


/**
 * \brief Disable the internal voltage regulator to supply VDDCORE by an external supply
 * \param p_supc Pointer to a supc registers set instance
 */
extern void supc_disable_voltage_regulator( Supc* p_supc )
{
  uint32_t mode;
  
    mode =  p_supc->SUPC_MR;
    p_supc->SUPC_MR = SUPC_MR_KEY(SUPC_KEY_VAL) | ( mode & ~SUPC_MR_ONREG );
    
    // generates reset
    //p_supc->SUPC_CR = SUPC_CR_KEY(SUPC_KEY_VAL) | SUPC_CR_VROFF_STOP_VREG ;
    //while ( 1 ) ;
}


/**
 * \brief Enable the core brownout detector
 * \param p_supc Pointer to a supc registers set instance
 */
extern void supc_enable_brownout_detector( Supc* p_supc )
{
  uint32_t mode;
  
    mode =  p_supc->SUPC_MR;
    p_supc->SUPC_MR = SUPC_MR_KEY(SUPC_KEY_VAL) | ( mode & ~SUPC_MR_BODDIS );
}


/**
 * \brief Disable the core brownout detector
 * \param p_supc Pointer to a supc registers set instance
 */
extern void supc_disable_brownout_detector( Supc* p_supc )
{
  uint32_t mode;
  
    mode =  p_supc->SUPC_MR;
    p_supc->SUPC_MR = SUPC_MR_KEY(SUPC_KEY_VAL) | ( mode | SUPC_MR_BODDIS );
}


/**
 * \brief The core reset signal when a brownout detection occurs
 * \param p_supc Pointer to a supc registers set instance
 */
extern void supc_enable_brownout_resetsignal( Supc* p_supc )
{
  uint32_t mode;
  
    mode =  p_supc->SUPC_MR;
    p_supc->SUPC_MR = SUPC_MR_KEY(SUPC_KEY_VAL) | ( mode | SUPC_MR_BODRSTEN );
}


/**
 * \brief No core reset signal when a brownout detection occurs
 * \param p_supc Pointer to a supc registers set instance
 */
extern void supc_disable_brownout_resetsignal( Supc* p_supc )
{
  uint32_t mode;
  
    mode =  p_supc->SUPC_MR;
    p_supc->SUPC_MR = SUPC_MR_KEY(SUPC_KEY_VAL) | ( mode & ~SUPC_MR_BODRSTEN );
}



/**
 * \brief Set Supply monitor threshold
 * \param p_supc Pointer to a supc registers set instance
 *
 * \param dw_threshold Supply monitor threshold
 *            SUPC_SMMR_SMTH_x_xV between _1_9V and _3_4V
 * //ERr(0x00-0x0F)
 */
extern uint32_t supc_set_monitor_threshold( Supc* p_supc , uint32_t dw_threshold)
{
  uint32_t sm_mode;
  
    sm_mode = p_supc->SUPC_SMMR & (~SUPC_SMMR_SMTH_Msk);
    //p_supc->SUPC_SMMR = sm_mode | (SUPC_SMMR_SMTH_Msk&(dw_threshold<<SUPC_SMMR_SMTH_Pos));
    p_supc->SUPC_SMMR = sm_mode | (SUPC_SMMR_SMTH_Msk&dw_threshold);
    
    return 0;
}


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
extern uint32_t supc_set_monitor_sampling_period( Supc* p_supc , uint32_t dw_period)
{
  uint32_t sm_mode;
  
    sm_mode = p_supc->SUPC_SMMR & (~SUPC_SMMR_SMSMPL_Msk);
    //p_supc->SUPC_SMMR = sm_mode | (SUPC_SMMR_SMSMPL_Msk&(dw_period<<SUPC_SMMR_SMSMPL_Pos));
    p_supc->SUPC_SMMR = sm_mode | (SUPC_SMMR_SMSMPL_Msk&dw_period);
    
    return 0;
}


/**
 * \brief The core reset signal, vddcore_nreset is asserted when a supply monitor detection occurs
 * \param p_supc Pointer to a supc registers set instance
 */
extern void supc_enable_monitor_reset( Supc* p_supc )
{
  uint32_t sm_mode;
  
    sm_mode = p_supc->SUPC_SMMR;
    p_supc->SUPC_SMMR = sm_mode | SUPC_SMMR_SMRSTEN;
}


/**
 * \brief No core reset signal, vddcore_nreset when a supply monitor detection occurs
 * \param p_supc Pointer to a supc registers set instance
 */
extern void supc_disable_monitor_reset( Supc* p_supc )
{
  uint32_t sm_mode;
  
    sm_mode = p_supc->SUPC_SMMR;
    p_supc->SUPC_SMMR = sm_mode & (~SUPC_SMMR_SMRSTEN);
}


/**
 * \brief the SUPC interrupt signal is asserted when a supply monitor detection occurs
 * \param p_supc Pointer to a supc registers set instance
 */
extern void supc_enable_monitor_interrupt( Supc* p_supc )
{
  uint32_t sm_mode;
  
    sm_mode = p_supc->SUPC_SMMR;
    p_supc->SUPC_SMMR = sm_mode | SUPC_SMMR_SMIEN;
}



/**
 * \brief the SUPC interrupt signal is not affected when a supply monitor detection occurs
 * \param p_supc Pointer to a supc registers set instance
 */
extern void supc_disable_monitor_interrupt( Supc* p_supc )
{
  uint32_t sm_mode;
  
    sm_mode = p_supc->SUPC_SMMR;
    p_supc->SUPC_SMMR = sm_mode & (~SUPC_SMMR_SMIEN);
}




////////////////////////////////////////////////////////////////////////////////

