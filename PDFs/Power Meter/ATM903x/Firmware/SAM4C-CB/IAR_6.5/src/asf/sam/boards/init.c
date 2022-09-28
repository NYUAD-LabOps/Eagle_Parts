/**
 * \file
 *
 * \brief SAM4S-EK board init.
 *
 * Copyright (c) 2011 - 2012 Atmel Corporation. All rights reserved.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. The name of Atmel may not be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * 4. This software may only be redistributed and used in connection with an
 *    Atmel microcontroller product.
 *
 * THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * EXPRESSLY AND SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * \asf_license_stop
 *
 */

#include "compiler.h"
#include "board.h"
#include "conf_board.h"
#include "gpio.h"
#include "asf.h"
#include "DemoMeter.h"

//#include "target.h"

void board_init(void)
{
        pmc_enable_periph_clk(ID_PIOC);
        pmc_enable_periph_clk(ID_PIOA); 
		
#ifndef CONF_BOARD_KEEP_WATCHDOG_AT_INIT 
	/* Disable the watchdog */
	WDT->WDT_MR = WDT_MR_WDDIS;
#endif
	
		
#ifdef CONF_BOARD_UART_CONSOLE
	/* Configure UART pins */
	gpio_configure_group(PINS_UART0_PIO, PINS_UART0, PINS_UART0_FLAGS);
#endif

	/* Configure ADC example pins */
#ifdef CONF_BOARD_ADC
	/* TC TIOA configuration */
	gpio_configure_pin(PIN_TC0_TIOA0,PIN_TC0_TIOA0_FLAGS);

	/* ADC Trigger configuration */
	gpio_configure_pin(PINS_ADC_TRIG, PINS_ADC_TRIG_FLAG);

	/* PWMH0 configuration */
	gpio_configure_pin(PIN_PWMC_PWMH0_TRIG, PIN_PWMC_PWMH0_TRIG_FLAG);
#endif

#ifdef CONF_BOARD_PWM_LED0
	/* Configure PWM LED0 pin */
	gpio_configure_pin(PIN_PWM_LED0_GPIO, PIN_PWM_LED0_FLAGS);
#endif

#ifdef CONF_BOARD_PWM_LED1
	/* Configure PWM LED1 pin */
	gpio_configure_pin(PIN_PWM_LED1_GPIO, PIN_PWM_LED1_FLAGS);
#endif

#ifdef CONF_BOARD_PWM_LED2
	/* Configure PWM LED2 pin */
	gpio_configure_pin(PIN_PWM_LED2_GPIO, PIN_PWM_LED2_FLAGS);
#endif

#ifdef CONF_BOARD_TWI0
	gpio_configure_pin(TWI0_DATA_GPIO, TWI0_DATA_FLAGS);
	gpio_configure_pin(TWI0_CLK_GPIO, TWI0_CLK_FLAGS);
#endif

#ifdef CONF_BOARD_TWI1
	gpio_configure_pin(TWI1_DATA_GPIO, TWI1_DATA_FLAGS);
	gpio_configure_pin(TWI1_CLK_GPIO, TWI1_CLK_FLAGS);
#endif

	/* Configure SPI pins */
#ifdef CONF_BOARD_SPI
	gpio_configure_pin(SPI_MISO_GPIO, SPI_MISO_FLAGS);
	gpio_configure_pin(SPI_MOSI_GPIO, SPI_MOSI_FLAGS);
	gpio_configure_pin(SPI_SPCK_GPIO, SPI_SPCK_FLAGS);
	
	/**
	 * For NPCS 1, 2, and 3, different PINs can be used to access the same NPCS line.
	 * Depending on the application requirements, the default PIN may not be available. 
	 * Hence a different PIN should be selected using the CONF_BOARD_SPI_NPCS_GPIO and 
	 * CONF_BOARD_SPI_NPCS_FLAGS macros.
	 */
	
	#ifdef CONF_BOARD_SPI_NPCS0
		gpio_configure_pin(SPI_NPCS0_GPIO, SPI_NPCS0_FLAGS);
	#endif

	#ifdef CONF_BOARD_SPI_NPCS1
		gpio_configure_pin(SPI_NPCS1_PA21_GPIO, SPI_NPCS1_PA21_FLAGS);

	#endif

	#ifdef CONF_BOARD_SPI_NPCS2
		gpio_configure_pin(SPI_NPCS2_PA22_GPIO, SPI_NPCS2_PA22_FLAGS);
	#endif

	#ifdef CONF_BOARD_SPI_NPCS3
		gpio_configure_pin(SPI_NPCS3_PA23_GPIO, SPI_NPCS3_PA23_FLAGS);
	#endif
#endif

#ifdef CONF_BOARD_USART_RXD
	/* Configure USART RXD pin */
	//gpio_configure_pin(PIN_USART1_RXD_IDX, PIN_USART1_RXD_FLAGS);
	gpio_configure_pin(PIN_USART2_RXD_IDX, PIN_USART2_RXD_FLAGS);
#endif

#ifdef CONF_BOARD_USART_TXD
	/* Configure USART TXD pin */
	//gpio_configure_pin(PIN_USART1_TXD_IDX, PIN_USART1_TXD_FLAGS);
	gpio_configure_pin(PIN_USART2_TXD_IDX, PIN_USART2_TXD_FLAGS);
#endif

#ifdef CONF_BOARD_USART_CTS
	/* Configure USART CTS pin */
	//gpio_configure_pin(PIN_USART1_CTS_IDX, PIN_USART1_CTS_FLAGS);
	gpio_configure_pin(PIN_USART2_CTS_IDX, PIN_USART2_CTS_FLAGS);
#endif

#ifdef CONF_BOARD_USART_RTS
	/* Configure USART RTS pin */
	//gpio_configure_pin(PIN_USART1_RTS_IDX, PIN_USART1_RTS_FLAGS);
	gpio_configure_pin(PIN_USART2_RTS_IDX, PIN_USART2_RTS_FLAGS);
#endif

#ifdef CONF_BOARD_USART_SCK
	/* Configure USART synchronous communication SCK pin */
	//gpio_configure_pin(PIN_USART1_SCK_IDX, PIN_USART1_SCK_FLAGS);
	gpio_configure_pin(PIN_USART2_SCK_IDX, PIN_USART2_SCK_FLAGS);
#endif

#ifdef CONF_BOARD_ADM3312_EN
	/* Configure ADM33312 enable pin */
	gpio_configure_pin(PIN_USART1_EN_IDX, PIN_USART1_EN_FLAGS);
	gpio_set_pin_low(PIN_USART1_EN_IDX);
#endif

#ifdef CONF_BOARD_TFDU4300_SD
	/* Configure IrDA transceiver shutdown pin */
	gpio_configure_pin(PIN_IRDA_SD_IDX, PIN_IRDA_SD_FLAGS);
	gpio_set_pin_low(PIN_IRDA_SD_IDX);
#endif

#ifdef CONF_BOARD_ADM3485_RE
	/* Configure RS485 transceiver RE pin */
    gpio_configure_pin(PIN_RE_IDX, PIN_RE_FLAGS);
	gpio_set_pin_low(PIN_RE_IDX);
#endif

#ifdef CONF_BOARD_ILI9325
	/* Configure LCD EBI pins */
	gpio_configure_pin(PIN_EBI_DATA_BUS_D0, PIN_EBI_DATA_BUS_FLAGS);
	gpio_configure_pin(PIN_EBI_DATA_BUS_D1, PIN_EBI_DATA_BUS_FLAGS);
	gpio_configure_pin(PIN_EBI_DATA_BUS_D2, PIN_EBI_DATA_BUS_FLAGS);
	gpio_configure_pin(PIN_EBI_DATA_BUS_D3, PIN_EBI_DATA_BUS_FLAGS);
	gpio_configure_pin(PIN_EBI_DATA_BUS_D4, PIN_EBI_DATA_BUS_FLAGS);
	gpio_configure_pin(PIN_EBI_DATA_BUS_D5, PIN_EBI_DATA_BUS_FLAGS);
	gpio_configure_pin(PIN_EBI_DATA_BUS_D6, PIN_EBI_DATA_BUS_FLAGS);
	gpio_configure_pin(PIN_EBI_DATA_BUS_D7, PIN_EBI_DATA_BUS_FLAGS);
	gpio_configure_pin(PIN_EBI_NRD, PIN_EBI_NRD_FLAGS);
	gpio_configure_pin(PIN_EBI_NWE, PIN_EBI_NWE_FLAGS);
	gpio_configure_pin(PIN_EBI_NCS1, PIN_EBI_NCS1_FLAGS);
	gpio_configure_pin(PIN_EBI_LCD_RS, PIN_EBI_LCD_RS_FLAGS);
#endif

#ifdef CONF_BOARD_AAT3155
	/* Configure Backlight control pin */
	gpio_configure_pin(BOARD_AAT31XX_SET_GPIO, BOARD_AAT31XX_SET_FLAGS);
#endif

#ifdef CONF_BOARD_ADS7843
	/* Configure Touchscreen SPI pins */
    gpio_configure_pin(BOARD_ADS7843_IRQ_GPIO,BOARD_ADS7843_IRQ_FLAGS);
	gpio_configure_pin(BOARD_ADS7843_BUSY_GPIO, BOARD_ADS7843_BUSY_FLAGS);
	gpio_configure_pin(SPI_MISO_GPIO, SPI_MISO_FLAGS);
	gpio_configure_pin(SPI_MOSI_GPIO, SPI_MOSI_FLAGS);
	gpio_configure_pin(SPI_SPCK_GPIO, SPI_SPCK_FLAGS);
	gpio_configure_pin(SPI_NPCS0_GPIO, SPI_NPCS0_FLAGS);
#endif

#ifdef CONF_BOARD_MMA7341L
	/* Configure MMA7341L mode set control pin */
	gpio_configure_pin(PIN_MMA7341L_MODE, PIN_MMA7341L_MODE_FLAG);
	/* Configure MMA7341L x,y,z axis output voltage pin */
	gpio_configure_pin(PIN_MMA7341L_X_AXIS, PIN_MMA7341L_X_AXIS_FLAG);
	gpio_configure_pin(PIN_MMA7341L_Y_AXIS, PIN_MMA7341L_Y_AXIS_FLAG);
	gpio_configure_pin(PIN_MMA7341L_Z_AXIS, PIN_MMA7341L_Z_AXIS_FLAG);
#endif

#ifdef CONF_BOARD_ISO7816_RST
	/* Configure ISO7816 card reset pin */
	gpio_configure_pin(PIN_ISO7816_RST_IDX, PIN_ISO7816_RST_FLAG);
#endif

#ifdef CONF_BOARD_ISO7816
	/* Configure ISO7816 interface TXD & SCK pin */
	gpio_configure_pin(PIN_USART1_TXD_IDX, PIN_USART1_TXD_FLAGS);
	gpio_configure_pin(PIN_USART1_SCK_IDX, PIN_USART1_SCK_FLAGS);
#endif


        
//#ifdef CONF_BOARD_ENABLE_COPROCESSOR
//        configure_coprocessor();
//        fill_sram1_memory();
//        deassert_c1_reset();         
//#endif   
//        
//#ifdef ENABLE_CACHE //defined in project settings
//  //Matrix0 settings
//  MATRIX0->MATRIX_SCFG[2] = MATRIX_SCFG_DEFMSTR_TYPE(2) | MATRIX_SCFG_FIXED_DEFMSTR(6);
//  
//  //Enable cache
//  CMCC0->CMCC_CTRL = CMCC_CTRL_CEN;
//  
//#else
//  CMCC0->CMCC_CTRL &= ~CMCC_CTRL_CEN;
//#endif

        

        
}
