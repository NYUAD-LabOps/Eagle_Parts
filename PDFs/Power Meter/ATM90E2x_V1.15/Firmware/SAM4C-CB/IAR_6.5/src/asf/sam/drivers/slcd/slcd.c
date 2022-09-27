// $asf_license$

/*! \file *********************************************************************
 *
 * \brief SLCD driver for SAM4C.
 *
 * \par Purpose
 *
 * This file contains basic functions for the SAM4C SLCD, with support for all
 * modes, settings and clock speeds.
 *
 * \par Usage
 *
 * - Compiler:           IAR EWARM and GNU GCC for SAM4
 * - Supported devices:  Only SAM4C devices with a SLCD module can be used.
 * - AppNote:
 *
 * \author               Atmel Corporation: http://www.atmel.com \n
 *                       Support and FAQ: http://support.atmel.no/
 *
 ******************************************************************************/


// ****************************************************************************
// first release based on SLCD driver : //KZH SLCD driver
// ****************************************************************************
#include "slcd.h"


uint32_t dev_slcd_config_frame_rate(Slcdc* pslcdc, uint32_t sclk, uint32_t pres, uint32_t div)
{
    uint32_t ncom[6] = {16,16, 15,16,15,18};
    uint32_t presc[8] = {8,16,32,64,128,256,512,1024};
    uint32_t div_t[8] = {1,2,3,4,5,6,7,8};
    uint32_t frame_rate;

    frame_rate = (sclk)/(presc[pres] * div_t[div] * ncom[LCD_COM_NB-1]);
    slcdc_config_frame_rate(pslcdc,pres, div);

    return frame_rate;
}


void slcdc_config_interrupt(void)
{
    NVIC_DisableIRQ( SLCDC_IRQn ) ;
    NVIC_ClearPendingIRQ( SLCDC_IRQn ) ;
    NVIC_SetPriority( SLCDC_IRQn, 5 ) ;
    NVIC_EnableIRQ( SLCDC_IRQn ) ;
}

void slcdc_software_reset(Slcdc*  pslcdc)
{
    pslcdc->SLCDC_CR = SLCDC_CR_SWRST;
}

void slcdc_enable(Slcdc*  pslcdc)
{
    pslcdc->SLCDC_CR = SLCDC_CR_LCDEN;
}

//Loc
void slcdc_disable(Slcdc*  pslcdc)
{
    pslcdc->SLCDC_CR = SLCDC_CR_LCDDIS;
}

void slcdc_sel_COM_num(Slcdc*  pslcdc, uint32_t num_COM)
{
    uint32_t sel;
    uint32_t tmp;
    //assert(num_COM > 5);
    switch(num_COM)
    {
        case 0:
                sel =  SLCDC_MR_COMSEL_COM_0;
            break;
        case 1:
                sel =  SLCDC_MR_COMSEL_COM_0TO1;
            break;
        case 2:
                sel = SLCDC_MR_COMSEL_COM_0TO2;
            break;
        case 3:
                sel = SLCDC_MR_COMSEL_COM_0TO3;
            break;
        case 4:
                sel = SLCDC_MR_COMSEL_COM_0TO4;
            break;
        case 5:
                 sel = SLCDC_MR_COMSEL_COM_0TO5;
            break;

        default:
                sel = SLCDC_MR_COMSEL_COM_0;
            break;
    }
    tmp = pslcdc->SLCDC_MR;
    tmp &= ~SLCDC_MR_COMSEL_Msk;
    tmp |= sel;
    pslcdc->SLCDC_MR = tmp;
}

void slcdc_sel_segment(Slcdc* pslcdc, uint32_t num_seg)
{
    uint32_t tmp;
    //assert(num_seg > 49);
    tmp = pslcdc->SLCDC_MR;
    tmp &= ~SLCDC_MR_SEGSEL_Msk;
    tmp |= SLCDC_MR_SEGSEL(num_seg);
    pslcdc->SLCDC_MR = tmp;
}

void slcdc_set_buftime(Slcdc* pslcdc, uint32_t time)
{
    uint32_t tmp, sel_time;
    //assert(time > 9);
    switch(time)
    {
        case 0:
                sel_time = SLCDC_MR_BUFTIME_OFF;
            break;
        case 1:
                sel_time = SLCDC_MR_BUFTIME_X2_SCLK_PERIOD;
            break;
        case 2:
                sel_time = SLCDC_MR_BUFTIME_X4_SCLK_PERIOD;
            break;
        case 3:
               sel_time = SLCDC_MR_BUFTIME_X8_SCLK_PERIOD;
            break;
        case 4:
               sel_time = SLCDC_MR_BUFTIME_X16_SCLK_PERIOD;
            break;
        case 5:
               sel_time = SLCDC_MR_BUFTIME_X32_SCLK_PERIOD;
            break;
        case 6:
                sel_time = SLCDC_MR_BUFTIME_X64_SCLK_PERIOD;
            break;
        case 7:
                sel_time = SLCDC_MR_BUFTIME_X128_SCLK_PERIOD;
            break;
        case 8:
                sel_time = SLCDC_MR_BUFTIME_PERCENT_50;
            break;
        case 9:
                sel_time = SLCDC_MR_BUFTIME_PERCENT_100;
            break;
        default:
                sel_time = SLCDC_MR_BUFTIME_OFF;
            break;
    }
    tmp = pslcdc->SLCDC_MR;
    tmp &= ~SLCDC_MR_SEGSEL_Msk;
    tmp |= sel_time;
    pslcdc->SLCDC_MR = tmp;
}

void slcdc_config_bias(Slcdc* pslcdc, uint32_t bias)
{
    uint32_t tmp, sel_bias;
    //assert(bias > 2);

    if(bias == 0)
    {
        sel_bias = SLCDC_MR_BIAS_STATIC;
    }
    else if(bias == 1)
    {
        sel_bias = SLCDC_MR_BIAS_BIAS_1_2;
    }
    else if(bias == 2)
    {
        sel_bias = SLCDC_MR_BIAS_BIAS_1_3;
    }
    else
    {
        sel_bias = SLCDC_MR_BIAS_STATIC;
    }
    tmp = pslcdc->SLCDC_MR;
    tmp &= ~SLCDC_MR_SEGSEL_Msk;
    tmp |= sel_bias;
    pslcdc->SLCDC_MR = tmp;
}

void slcdc_entern_lp_mode(Slcdc* pslcdc)
{
    uint32_t tmp;
    tmp = pslcdc->SLCDC_MR;
    //tmp &= ~pslcdc_MR_LPMODE;
    tmp |= SLCDC_MR_LPMODE;
    pslcdc->SLCDC_MR = tmp;
}

void slcdc_exit_lp_mode(Slcdc* pslcdc)
{
    uint32_t tmp;
    tmp = pslcdc->SLCDC_MR;
    tmp &= ~SLCDC_MR_LPMODE;
    //tmp |= pslcdc_MR_LPMODE;
    pslcdc->SLCDC_MR = tmp;
}

void slcdc_config_frame_rate(Slcdc* pslcdc, uint32_t pres, uint32_t div)
{
    //assert(pres > 7);
    //assert(div > 7);
    pslcdc->SLCDC_FRR = (pres << SLCDC_FRR_PRESC_Pos)|(div << SLCDC_FRR_DIV_Pos);

}

void slcdc_set_display_mode(Slcdc* pslcdc, uint32_t mode)
{
    uint32_t tmp, sel_mode;
    //assert(mode > 7);

    switch(mode)
    {
        case 0:
                sel_mode = SLCDC_DR_DISPMODE_NORMAL;
            break;
        case 1:
                sel_mode = SLCDC_DR_DISPMODE_FORCE_OFF;
            break;
        case 2:
                sel_mode = SLCDC_DR_DISPMODE_FORCE_ON;
            break;
        case 3:
                sel_mode = SLCDC_DR_DISPMODE_BLINKING;
            break;
        case 4:
                sel_mode = SLCDC_DR_DISPMODE_INVERTED;
            break;
        case 5:
                sel_mode = SLCDC_DR_DISPMODE_INVERTED_BLINK;
            break;
        case 6:
                sel_mode = SLCDC_DR_DISPMODE_USER_BUFFER_LOAD;
            break;
        case 7:
                sel_mode = SLCDC_DR_DISPMODE_BUFFERS_SWAP;
            break;
        default:
                sel_mode = SLCDC_DR_DISPMODE_NORMAL;
            break;

    }
    tmp = pslcdc->SLCDC_DR;
    tmp &= ~SLCDC_DR_DISPMODE_Msk;
    tmp |= sel_mode;
    pslcdc->SLCDC_DR = tmp;
}

void slcdc_set_blink_frq(Slcdc* pslcdc, uint32_t frq)
{
    uint32_t tmp;

    //assert(frq > 0x7F);

    tmp = pslcdc->SLCDC_DR;
    tmp &= ~SLCDC_DR_LCDBLKFREQ_Msk;
    tmp |= SLCDC_DR_LCDBLKFREQ(frq);
    pslcdc->SLCDC_DR = tmp;
}

uint32_t slcdc_get_status(Slcdc* pslcdc)
{
    return pslcdc->SLCDC_SR;
}

void slcdc_enable_interrupt(Slcdc* pslcdc, uint32_t irq)
{
    pslcdc->SLCDC_IER = irq;
}

void slcdc_disable_interrupt(Slcdc* pslcdc, uint32_t irq)
{
    pslcdc->SLCDC_IDR = irq;
}

uint32_t slcdc_get_interrupt_mask(Slcdc* pslcdc)
{
    return pslcdc->SLCDC_IMR;
}

uint32_t slcdc_get_interrupt_status(Slcdc* pslcdc)
{
    return pslcdc->SLCDC_ISR;
}

void slcdc_segment_map0(Slcdc* pslcdc, uint32_t map)
{
    pslcdc->SLCDC_SMR0 = map;
}

void slcdc_segment_map1(Slcdc* pslcdc, uint32_t map)
{
    pslcdc->SLCDC_SMR1 = map & 0x3FFFF;
}

void slcdc_write_lsb_memory(Slcdc* pslcdc, uint32_t index,uint32_t val)
{
    pslcdc->SLCDC_COM[index].SLCDC_LMEMR |= val;//SLCDC_LMEMR_LPIXEL(val);
}

void slcdc_write_msb_memory(Slcdc* pslcdc, uint32_t index,uint32_t val)
{
    pslcdc->SLCDC_COM[index].SLCDC_MMEMR |= val;//SLCDC_MMEMR_MPIXEL(val);
}

void slcdc_clear_lsb_memory(Slcdc* pslcdc, uint32_t index,uint32_t val)
{
    pslcdc->SLCDC_COM[index].SLCDC_LMEMR &= ~val;//SLCDC_LMEMR_LPIXEL(val);
}

void slcdc_clear_msb_memory(Slcdc* pslcdc, uint32_t index,uint32_t val)
{
    pslcdc->SLCDC_COM[index].SLCDC_MMEMR &= ~val;//SLCDC_MMEMR_MPIXEL(val);
}
