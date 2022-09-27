/**
 * \file conf_meter.c 
 *
 * \brief Configure Demo Meter peripherals.
 *
 * Copyright (c) 2012 Atmel Corporation. All rights reserved.
 *
 * \asf_license_start
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
 * Created: 7/25/2012 10:10:25 AM
 * By: LVN
 */
 
#include "asf.h"
#include "conf_clock.h"
#include "conf_board.h"
#include "conf_meter.h"
#include "gpio.h"
#include "pmc.h"
#include "stdio_serial.h"
//#include "led.h"


/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
extern "C" {
#endif
/**INDENT-ON**/
/// @endcond

// external definition


/**
 *  Configure UART console.
 */
#if 0
void configure_console(void)
{
	//Gary temp
        volatile int i = sysclk_get_cpu_hz();
        const sam_uart_opt_t uart_console_settings =
			{ i, IEC_HandShake_BD, UART_MR_PAR_EVEN };
//        const sam_uart_opt_t uart_console_settings =
//			{ i, Baud_115200, UART_MR_PAR_NO };
	// Configure PIO //
	pio_configure(PINS_UART0_PIO, PINS_UART0_TYPE, PINS_UART0_MASK,
			PINS_UART0_ATTR);

	// Configure PMC //
	pmc_enable_periph_clk(CONSOLE_UART_ID);

	// Configure UART //
	uart_init(CONSOLE_UART, &uart_console_settings);
        //For printf and scanf
//        stdio_base = (void*) UART0;
//        ptr_get = &stdio_read;
//        ptr_put = &stdio_write;
        
        
	// Disable all the interrupts. //
	uart_enable_interrupt(CONSOLE_UART, US_IER_RXRDY);

	// Configure and enable interrupt of USART. //
	NVIC_EnableIRQ(UART0_IRQn);

	// Init. Console user command and console circular buffer //
//	console_cmd = cl_console_cmd_init();

	// Specify that stdout should not be buffered. //
#if defined(__GNUC__)
//	setbuf(stdout, NULL);
#else
	/* Already the case in IAR's Normal DLIB default configuration: printf()
	 * emits one character at a time.
	 */
#endif
}
#endif
#if 0 
/**
 *  \brief Configure the Pushbutton.
 */
void configure_button(void)
{

	/* Enable the peripheral clock for the push button 1 (wake) on board. */
	pmc_enable_periph_clk(PB_WAKE_ID);

	/* Configure PIOs as input pins. */
	pio_configure(PB_WAKE_PIO, PB_WAKE_TYPE, PB_WAKE_MASK, PB_WAKE_ATTR);

	/* Adjust PIO debounce filter parameters. */
	pio_set_debounce_filter(PB_WAKE_PIO, PB_WAKE_MASK, PB_FILTER_GLITCH_VALUE);

	/* Initialize PIO interrupt handler, interrupt on rising edge. */
	pio_handler_set(PB_WAKE_PIO, PB_WAKE_TYPE, PB_WAKE_MASK, PB_WAKE_ATTR, button_handler);

        //Gary:  Do not need to configure TMP0 button
 // add second push button in later
	/* Enable the peripheral clock for the push button 2 (tamper) on board. */
	pmc_enable_periph_clk(PB_TAMPER_ID);

	/* Configure PIOs as input pins. */
	pio_configure(PB_TAMPER_PIO, PB_TAMPER_TYPE, PB_TAMPER_MASK, PB_TAMPER_ATTR);

	/* Adjust PIO debounce filter parameters. */
	pio_set_debounce_filter(PB_TAMPER_PIO, PB_TAMPER_MASK, PB_FILTER_GLITCH_VALUE);

	/* Initialize PIO interrupt handler, interrupt on rising edge. */
	pio_handler_set(PB_TAMPER_PIO, PB_TAMPER_TYPE, PB_TAMPER_MASK, PB_TAMPER_ATTR, button_handler);


}
#endif

#if 0
/**
 *  \brief Configure LED.
 */
void configure_led(void)
{
  //Gary No LED in CMP spec
	/* Configure PIOs for LED. */
	//pio_configure(LED_PIO, LED_TYPE, LED_MASK, LED_ATTR);
}
#endif






/**
 * \brief .
 *
 * \param .
 *
 * \return .
 */
void at24cxx_init(void)
{
	/* Enable the peripheral clock for TWI */
	pmc_enable_periph_clk(BOARD_ID_TWI_EEPROM);
	twi_master_options_t opt = {
		.master_clk = sysclk_get_main_hz(),
		.speed = AT24C_TWI_CLK,
		//.chip  = 0x50
	};
	if(twi_master_init(BOARD_AT24C_TWI_INSTANCE, &opt) != TWI_SUCCESS)
            while (1);
}



/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
}
#endif
/**INDENT-ON**/
/// @endcond

