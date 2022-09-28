// $asf_license$

/*! \file *********************************************************************
 *
 * \brief PIO driver for SAM3.
 *
 * Power Management Controller (PMC) driver module for SAM MCUs.
 *
 * - Compiler:           IAR EWARM and GNU GCC for SAM.
 * - Supported devices:  All SAM devices.
 * - AppNote:
 *
 ******************************************************************************/

#ifndef _V_PIO_H
#define _V_PIO_H

#include "project.h"

// ---- General purpose include files
#include "device.h"

// ---- Peripherals (ASF drivers)
//#include "drivers/pio/pio.h"




/**
 * \brief toogle output level on all the PIOs defined in the given Pin instance.
 * This has no immediate effects on PIOs that are not output, but the PIO
 * controller will memorize the value they are changed to outputs.
 *
 * \param pin  Pointer to a Pin instance describing one or more pins.
 */
extern void pio_toggle(Pio * p_pio, const uint32_t dw_mask);



#endif // _V_PIO_H

