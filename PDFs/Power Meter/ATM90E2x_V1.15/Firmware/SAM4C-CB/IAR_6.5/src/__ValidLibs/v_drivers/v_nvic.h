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

#ifndef _V_NVIC_H
#define _V_NVIC_H

#include "project.h"

// ---- General purpose include files
#include "device.h"


/**
 * \brief Enable peripheral interrupt (core level)
 */
extern void nvic_enable_it(uint32_t periph_id);



#endif // _V_NVIC_H

