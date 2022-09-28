// $asf_license$
/*! \file *********************************************************************
 *
 * \brief SLCD driver for SAM4C.
 *
 * Segment LCD Controller (SLCD); driver module for SAM4C MCUs.
 *
 * - Compiler:           IAR EWARM and GNU GCC for SAM.
 * - Supported devices:  All SAM devices.
 * - AppNote:
 *
 ******************************************************************************/
#ifndef _V_SLCD_H
#define _V_SLCD_H


#include "compiler.h"

#define LCD_SEG_NB		40
#define LCD_COM_NB		SLCDC_MR_COMSEL_COM_0TO5

extern uint32_t dev_slcd_config_frame_rate(Slcdc* pslcdc, uint32_t sclk, uint32_t pres, uint32_t div);
extern void slcdc_config_interrupt(void);
extern void slcdc_software_reset(Slcdc*  pslcdc);
extern void slcdc_enable(Slcdc*  pslcdc);
//Loc
extern void slcdc_disable(Slcdc*  pslcdc);
extern void slcdc_sel_COM_num(Slcdc*  pslcdc, uint32_t num_COM);
extern void slcdc_set_buftime(Slcdc* pslcdc, uint32_t time);
extern void slcdc_config_bias(Slcdc* pslcdc, uint32_t bias);
extern void slcdc_entern_lp_mode(Slcdc* pslcdc);
extern void slcdc_exit_lp_mode(Slcdc* pslcdc);
extern void slcdc_config_frame_rate(Slcdc* pslcdc, uint32_t pres, uint32_t div);
extern void slcdc_set_display_mode(Slcdc* pslcdc, uint32_t mode);
extern void slcdc_set_blink_frq(Slcdc* pslcdc, uint32_t frq);
extern uint32_t slcdc_get_status(Slcdc* pslcdc);
extern void slcdc_enable_interrupt(Slcdc* pslcdc, uint32_t irq);
extern void slcdc_disable_interrupt(Slcdc* pslcdc, uint32_t irq);
extern uint32_t slcdc_get_interrupt_mask(Slcdc* pslcdc);
extern uint32_t slcdc_get_interrupt_status(Slcdc* pslcdc);
extern void slcdc_segment_map0(Slcdc* pslcdc, uint32_t map);
extern void slcdc_segment_map1(Slcdc* pslcdc, uint32_t map);
extern void slcdc_write_lsb_memory(Slcdc* pslcdc, uint32_t index,uint32_t val);
extern void slcdc_write_msb_memory(Slcdc* pslcdc, uint32_t index,uint32_t val);
extern void slcdc_config_backlight_pwr(void);
extern void slcdc_turnoff_backlight(void);
extern void slcdc_trunon_backlight(void);
extern void slcdc_clear_lsb_memory(Slcdc* pslcdc, uint32_t index,uint32_t val);
extern void slcdc_clear_msb_memory(Slcdc* pslcdc, uint32_t index,uint32_t val);

#endif
