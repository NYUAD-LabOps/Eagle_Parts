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

#ifndef IPC_H_INCLUDED
#define IPC_H_INCLUDED

#include "compiler.h"

#ifdef SAM4C

extern void ipc_set_interrupt(Ipc * ipc, const uint32_t dw_mask);
extern void ipc_clear_interrupt(Ipc * ipc, const uint32_t dw_mask);
extern uint32_t ipc_get_status(Ipc * ipc, const uint32_t dw_mask);
extern uint32_t ipc_is_pending(Ipc * ipc, const uint32_t dw_mask);
extern void ipc_enable_interrupt(Ipc * ipc, const uint32_t dw_mask);
extern void ipc_disable_interrupt(Ipc * ipc, const uint32_t dw_mask);
extern uint32_t ipc_get_status(Ipc * ipc, const uint32_t dw_mask);
#endif

/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
}
#endif
/**INDENT-ON**/
/// @endcond

#endif /* IPC_H_INCLUDED */
