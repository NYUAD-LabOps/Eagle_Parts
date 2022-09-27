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

#include "v_nvic.h"


/**
 * \brief Enable peripheral interrupt (core level)
 */
extern void nvic_enable_it(uint32_t periph_id)
{
 uint8_t index;
 uint32_t pos;
  
  index = periph_id/32;
  pos = periph_id%32;
  
  NVIC -> ICER[index] = (1 << pos) ; // Disable the interrupt first
  NVIC -> ICPR[index] = (1 << pos) ; // Clear any pending status
  NVIC -> ISER[index] = (1 << pos) ; // Enable IT*/
  
/*  NVIC -> ICER[0] = (1 << periph_id) ; // Disable the interrupt first
  NVIC -> ICPR[0] = (1 << periph_id) ; // Clear any pending status
  NVIC -> ISER[0] = (1 << periph_id) ; // Enable IT*/
}

