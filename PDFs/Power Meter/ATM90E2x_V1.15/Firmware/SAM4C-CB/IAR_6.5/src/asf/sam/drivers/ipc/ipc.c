/*! \file *********************************************************************
 *
 * \brief PIO driver for SAM3.
 *
 * $asf_license$
 *
 * Parallel Input/Output (PIO) Controller driver module for SAM3 MCUs.
 *
 * - Compiler:           IAR EWARM and GNU GCC for SAM.
 * - Supported devices:  All SAM devices.
 * - AppNote:
 *
 * \author               Atmel Corporation: http://www.atmel.com \n
 *                       Support and FAQ: http://support.atmel.com/
 *
 ******************************************************************************/

//#include "compiler.h" //ERr => moved to pio.h
#include "ipc.h"

/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
extern "C" {
#endif
/**INDENT-ON**/
/// @endcond

#ifndef SAM4C
#Error Device not supported  
#endif
  
/**
 * \brief Enables the IPC interrupt defined in dw_mask.
 *
 * \param p_pio       Pointer to a IPC controller.
 * \param dw_mask     Bitmask of one or more pin(s) to configure.
 */
void ipc_set_interrupt(Ipc * ipc, const uint32_t dw_mask)
{
	ipc->IPC_ISCR = dw_mask;
}

/**
 * \brief Disables the IPC interrupt defined in dw_mask.
 *
 * \param p_pio       Pointer to a IPC controller.
 * \param dw_mask     Bitmask of one or more pin(s) to configure.
 */
void ipc_clear_interrupt(Ipc * ipc, const uint32_t dw_mask)
{
	ipc->IPC_ICCR = dw_mask;
}

/**
 * \brief Returns 1 if the corresponding IPC interrupt is set
 *
 * \param p_pio       Pointer to a IPC controller.
 * \param dw_mask     Bitmask of one or more IRQs.
 *
 * \retval 1 at least one IPC IRQ currently has a high level.
 * \retval 0 all IPC IRQs have a low level.
 */
uint32_t ipc_get_status(Ipc * ipc, const uint32_t dw_mask)
{
	uint32_t dw_reg;

	dw_reg = ipc->IPC_ISR;
	
	if ((dw_reg & dw_mask) == 0) {
		return 0;
	} else {
		return 1;
	}
}



/**
 * \brief Returns 1 if the corresponding IPC interrupt is pending
 *
 * \param p_pio       Pointer to a IPC controller.
 * \param dw_mask     Bitmask of one or more IRQs.
 *
 * \retval 1 at least one IPC IRQ currently is pending.
 * \retval 0 all IPC IRQs have been serviced.
 */
uint32_t ipc_is_pending(Ipc * ipc, const uint32_t dw_mask)
{
	uint32_t dw_reg;

	dw_reg = ipc->IPC_IPR;
	
	if ((dw_reg & dw_mask) == 0) {
		return 0;
	} else {
		return 1;
	}
}

/**
 * \brief Enables the corresponding IPC IRQ channel
 *
 * \param p_pio       Pointer to a IPC controller.
 * \param dw_mask     Bitmask of one or more IRQs.
 *
 * \retval void
 */
void ipc_enable_interrupt(Ipc * ipc, const uint32_t dw_mask)
{
	ipc->IPC_IECR = dw_mask;
}

/**
 * \brief Disables the corresponding IPC IRQ channel
 *
 * \param p_pio       Pointer to a IPC controller.
 * \param dw_mask     Bitmask of one or more IRQs.
 *
 * \retval void
 */
void ipc_disable_interrupt(Ipc * ipc, const uint32_t dw_mask)
{
	ipc->IPC_IDCR = dw_mask;
}
/**
 * \brief Returns 1 if the corresponding IPC interrupt is set
 *
 * \param p_pio       Pointer to a IPC controller.
 * \param dw_mask     Bitmask of one or more IRQs.
 *
 * \retval 1 at least one IPC IRQ currently has a high level.
 * \retval 0 all IPC IRQs have a low level.
 */
uint32_t ipc_get_mask(Ipc * ipc, const uint32_t dw_mask)
{
	uint32_t dw_reg;

	dw_reg = ipc->IPC_IMR;
	
	if ((dw_reg & dw_mask) == 0) {
		return 0;
	} else {
		return 1;
	}
}



/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
}
#endif
/**INDENT-ON**/
/// @endcond
