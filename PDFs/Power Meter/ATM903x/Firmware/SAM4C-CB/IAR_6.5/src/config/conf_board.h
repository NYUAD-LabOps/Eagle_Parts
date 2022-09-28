/**
 * \file
 *
 * \brief Board configuration.
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

#ifndef CONF_BOARD_H_INCLUDED
#define CONF_BOARD_H_INCLUDED

#include "board.h"
   
/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */
// Use the following defines to select Vref and manual calibration data
//#define __DEBUG_FIXED_VREF_OVER_TEMP__  // disables Vref temperature compensation

#define __OVERRIDE__USE_MANUAL_TRIM_VALUES__  // if using manual trim values, select this and one following board select

//#define __SELECT__BOARD_TEMPLATE__
//#define __SELECT__BOARD_1A__
//#define __SELECT__BOARD_2A__
//#define __SELECT__BOARD_9A__
//#define __SELECT__BOARD_10A__
//#define __SELECT__BOARD_B25__
//#define __SELECT__BOARD_B26__
//#define __SELECT__BOARD_B27__
//#define __SELECT__BOARD_B32__
#define __SELECT__BOARD_B55__
//#define __SELECT__BOARD_B56__
//#define __SELECT__BOARD_tc1__
//#define __SELECT__BOARD_template2__


//#############PIN DEFINITIONS#############################   
/** UART0 pins (UTXD0 and URXD0) definitions, PB4,5. */
#define PINS_UART0			(PIO_PB4A_URXD0 | PIO_PB5A_UTXD0)
#define PINS_UART0_FLAGS	(PIO_PERIPH_A | PIO_DEFAULT)

#define PINS_UART0_MASK 	PIO_PB4A_URXD0|PIO_PB5A_UTXD0
#define PINS_UART0_PIO 		PIOB
#define PINS_UART0_ID 		ID_PIOB
#define PINS_UART0_TYPE 	PIO_PERIPH_A
#define PINS_UART0_ATTR 	PIO_DEFAULT

#define CONSOLE_UART		UART0
#define CONSOLE_UART_ID		ID_UART0

//--- UART1 pins (UTXD1 and URXD1) definitions, PC1,0. ---//
#define PINS_UART1        	(PIO_PC1A_URXD1 | PIO_PC0A_UTXD1)
#define PINS_UART1_FLAGS    (PIO_PERIPH_C | PIO_DEFAULT)

#define PINS_UART1_MASK 	PIO_PC1A_URXD1 | PIO_PC0A_UTXD1
#define PINS_UART1_PIO 		PIOC
#define PINS_UART1_ID 		ID_PIOC
#define PINS_UART1_TYPE 	PIO_PERIPH_C
#define PINS_UART1_ATTR 	PIO_DEFAULT

#define	Ir_UART				UART1
#define	Ir_UART_ID			ID_UART1

//#if 0
///** Push button #1 definition. Attributes = pull-up + debounce + interrupt on falling edge. */
//#define PUSHBUTTON_2_NAME    "TMP0"
//#define GPIO_PUSH_BUTTON_2   (PIO_PC12_IDX)
//#define GPIO_PUSH_BUTTON_2_FLAGS    (PIO_INPUT | PIO_PULLUP | PIO_DEBOUNCE | PIO_IT_FALL_EDGE)
//
//#define PIN_PUSHBUTTON_2    {PIO_PC12, PIOC, ID_PIOC, PIO_INPUT, PIO_PULLUP | PIO_DEBOUNCE | PIO_IT_FALL_EDGE}
//#define PIN_PUSHBUTTON_2_MASK PIO_PC12
//#define PIN_PUSHBUTTON_2_PIO PIOC
//#define PIN_PUSHBUTTON_2_ID ID_PIOC
//#define PIN_PUSHBUTTON_2_TYPE PIO_INPUT
//#define PIN_PUSHBUTTON_2_ATTR PIO_PULLUP | PIO_DEBOUNCE | PIO_IT_FALL_EDGE
//
///** List of all push button definitions. */
//#define PINS_PUSHBUTTONS    PIN_PUSHBUTTON_1, PIN_PUSHBUTTON_2
//
//#endif


//display key pin
#define GPIO_DISPKEYDN_PIN   	(PIO_PB14_IDX)
#define GPIO_DISPKEY_DN_FLAGS    (PIO_INPUT | PIO_PULLUP | PIO_DEBOUNCE | PIO_IT_FALL_EDGE)

#define DISPKEY_DN_MASK 	PIO_PB14
#define DISPKEY_DN_PIO 		PIOB
#define DISPKEY_DN_ID 		ID_PIOB
#define DISPKEY_DN_TYPE 	PIO_INPUT
#define DISPKEY_DN_ATTR 	PIO_PULLUP | PIO_DEBOUNCE | PIO_IT_FALL_EDGE

#define GPIO_DISPKEYUP_PIN   	(PIO_PB13_IDX)
#define GPIO_DISPKEY_UP_FLAGS    (PIO_INPUT | PIO_PULLUP | PIO_DEBOUNCE | PIO_IT_FALL_EDGE)

#define DISPKEY_UP_MASK 	PIO_PB13
#define DISPKEY_UP_PIO 		PIOB
#define DISPKEY_UP_ID 		ID_PIOB
#define DISPKEY_UP_TYPE 	PIO_INPUT
#define DISPKEY_UP_ATTR 	PIO_PULLUP | PIO_DEBOUNCE | PIO_IT_FALL_EDGE

//POWER FAIL PIN
#define GPIO_POWER_FAIL   		(PIO_PA17_IDX)
#define GPIO_POWER_FAIL_FLAGS    (PIO_INPUT | PIO_PULLUP | PIO_DEBOUNCE | PIO_IT_FALL_EDGE)

#define POWER_FAIL_MASK 	PIO_PA17
#define POWER_FAIL_PIO 		PIOA
#define POWER_FAIL_ID 		ID_PIOA
#define POWER_FAIL_TYPE 	PIO_INPUT
#define POWER_FAIL_ATTR 	PIO_PULLUP | PIO_DEBOUNCE | PIO_IT_FALL_EDGE


//test PIN
#define GPIO_TEST_OUT_PIN  		(PIO_PA6_IDX)
#define GPIO_TEST_OUT_FLAGS    (PIO_OUTPUT_0 | PIO_PULLUP | PIO_DEBOUNCE | PIO_IT_FALL_EDGE)

#define TEST_OUT_MASK 		PIO_PA6
#define TEST_OUT_PIO 		PIOA
#define TEST_OUT_ID 		ID_PIOA
#define TEST_OUT_TYPE 		PIO_OUTPUT_0
#define TEST_OUT_ATTR 		PIO_PULLUP | PIO_DEBOUNCE | PIO_IT_FALL_EDGE

#define GPIO_TEST_IN_PIN   		(PIO_PA7_IDX)
#define GPIO_TEST_IN_FLAGS    (PIO_INPUT | PIO_PULLUP | PIO_DEBOUNCE | PIO_IT_FALL_EDGE)

#define TEST_IN_MASK 		PIO_PA7
#define TEST_IN_PIO 		PIOA
#define TEST_IN_ID 			ID_PIOA
#define TEST_IN_TYPE 		PIO_INPUT
#define TEST_IN_ATTR 		PIO_PULLUP | PIO_DEBOUNCE | PIO_IT_FALL_EDGE

//#define PIN_TC0_TIOA0		(PIO_PA13_IDX)
//#define PIN_TC0_TIOA0_FLAGS	(PIO_PERIPH_B | PIO_DEFAULT)
//
//#define PIN_TC0_TIOA1		(PIO_PB7_IDX)
//#define PIN_TC0_TIOA1_FLAGS	(PIO_PERIPH_A | PIO_DEFAULT)
//
//#define PIN_TC0_TIOA1_PIO     PIOB
//#define PIN_TC0_TIOA1_MASK  PIO_PB7A_TIOA1
//#define PIN_TC0_TIOA1_ID      ID_PIOB
//#define PIN_TC0_TIOA1_TYPE   PIO_PERIPH_A
//#define PIN_TC0_TIOA1_ATTR   PIO_DEFAULT
//
//#define PIN_TC0_TIOA2		(PIO_PB10_IDX)
//#define PIN_TC0_TIOA2_FLAGS	(PIO_INPUT | PIO_DEFAULT)
//
//#define PIN_TC0_TIOA2_PIO     PIOB
//#define PIN_TC0_TIOA2_MASK  PIO_PB10A_TIOA2
//#define PIN_TC0_TIOA2_ID      ID_PIOB
//#define PIN_TC0_TIOA2_TYPE   PIO_INPUT
//#define PIN_TC0_TIOA2_ATTR   PIO_DEFAULT

/** SPI MISO pin definition. */
//#define SPI_MISO_GPIO 		      (PIO_PA6_IDX)
//#define SPI_MISO_FLAGS       (PIO_PERIPH_A | PIO_DEFAULT)
/** SPI MOSI pin definition. */
//#define SPI_MOSI_GPIO 		      (PIO_PA7_IDX)
//#define SPI_MOSI_FLAGS       (PIO_PERIPH_A | PIO_DEFAULT)
/** SPI SPCK pin definition. */
#define SPI_SPCK_GPIO 		      (PIO_PA8_IDX)
#define SPI_SPCK_FLAGS       (PIO_PERIPH_A | PIO_DEFAULT)

/** SPI chip select 0 pin definition. (Only one configuration is possible) */
//#define SPI_NPCS0_GPIO 		      (PIO_PA5_IDX)
//#define SPI_NPCS0_FLAGS           (PIO_PERIPH_A | PIO_DEFAULT)
/** SPI chip select 1 pin definition. (multiple configurations are possible) */
#define SPI_NPCS1_PA21_GPIO 		  (PIO_PA21_IDX)
#define SPI_NPCS1_PA21_FLAGS       (PIO_PERIPH_A | PIO_DEFAULT)
/** SPI chip select 2 pin definition. (multiple configurations are possible) */
//#define SPI_NPCS2_PA22_GPIO 	  (PIO_PA22_IDX)
//#define SPI_NPCS2_PA22_FLAGS      (PIO_PERIPH_A | PIO_DEFAULT)
/** SPI chip select 3 pin definition. (multiple configurations are possible) */
//#define SPI_NPCS3_PA23_GPIO 		  (PIO_PA23_IDX)
//#define SPI_NPCS3_PA23_FLAGS       (PIO_PERIPH_A | PIO_DEFAULT)


/** TWI0 pins definition */
#define TWI0_DATA_GPIO   PIO_PA24_IDX
#define TWI0_DATA_FLAGS  (PIO_PERIPH_A | PIO_DEFAULT)
#define TWI0_CLK_GPIO    PIO_PA25_IDX
#define TWI0_CLK_FLAGS   (PIO_PERIPH_A | PIO_DEFAULT)

///** USART0 pin RX */
//#define PIN_USART0_RXD    {PIO_PB16A_RXD0, PIOB, ID_PIOB, PIO_PERIPH_A, PIO_DEFAULT}
//#define PIN_USART0_RXD_IDX        (PIO_PB16_IDX)
//#define PIN_USART0_RXD_FLAGS      (PIO_PERIPH_A | PIO_DEFAULT)
///** USART0 pin TX */
//#define PIN_USART0_TXD    {PIO_PB17A_TXD0, PIOB, ID_PIOB, PIO_PERIPH_A, PIO_DEFAULT}
//#define PIN_USART0_TXD_IDX        (PIO_PB17_IDX)
//#define PIN_USART0_TXD_FLAGS      (PIO_PERIPH_A | PIO_DEFAULT)
///** USART0 pin CTS */
//#define PIN_USART0_CTS    {PIO_PA20A_CTS0, PIOA, ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT}
//#define PIN_USART0_CTS_IDX        (PIO_PA20_IDX)
//#define PIN_USART0_CTS_FLAGS      (PIO_PERIPH_A | PIO_DEFAULT)
///** USART0 pin RTS */
//#define PIN_USART0_RTS    {PIO_PA19A_RTS0, PIOA, ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT}
//#define PIN_USART0_RTS_IDX        (PIO_PA19_IDX)
//#define PIN_USART0_RTS_FLAGS      (PIO_PERIPH_A | PIO_DEFAULT)
///** USART0 pin SCK */
//#define PIN_USART0_SCK    {PIO_PB18A_SCK0, PIOA, ID_PIOB, PIO_PERIPH_A, PIO_DEFAULT}
//#define PIN_USART0_SCK_IDX        (PIO_PB18_IDX)
//#define PIN_USART0_SCK_FLAGS      (PIO_PERIPH_A | PIO_DEFAULT)
//
//--- USART1 pin RX --//
#define PIN_USART1_RXD    {PIO_PA11A_RXD1, PIOA, ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT}
#define PIN_USART1_RXD_IDX        (PIO_PA11_IDX)
#define PIN_USART1_RXD_FLAGS      (PIO_PERIPH_A | PIO_DEFAULT)
//-- USART1 pin TX --//
#define PIN_USART1_TXD    {PIO_PA12A_TXD1, PIOA, ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT}
#define PIN_USART1_TXD_IDX        (PIO_PA12_IDX)
#define PIN_USART1_TXD_FLAGS      (PIO_PERIPH_A | PIO_DEFAULT)
//-- USART1 pin RTS --//
#define PIN_USART1_CTS    {PIO_PA18A_CTS1, PIOA, ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT}
#define PIN_USART1_CTS_IDX        (PIO_PA18_IDX)
#define PIN_USART1_CTS_FLAGS      (PIO_PERIPH_A | PIO_DEFAULT)
//-- USART1 pin CTS --//
#define PIN_USART1_RTS    {PIO_PA17A_RTS1, PIOA, ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT}
#define PIN_USART1_RTS_IDX        (PIO_PA17_IDX)
#define PIN_USART1_RTS_FLAGS      (PIO_PERIPH_A | PIO_DEFAULT)
//-- RE pin. --//
#define PIN_USART1_RE_IDX           PIN_USART1_CTS_IDX
#define PIN_USART1_RE_FLAGS         (PIO_OUTPUT_0 | PIO_PULLUP | PIO_DEFAULT)

//--- USART2 pin RX --//
#define PIN_USART2_RXD    {PIO_PA9A_RXD2, PIOA, ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT}
#define PIN_USART2_RXD_IDX        (PIO_PA9_IDX)
#define PIN_USART2_RXD_FLAGS      (PIO_PERIPH_A | PIO_PULLUP | PIO_DEFAULT)
//-- USART2 pin TX --//
#define PIN_USART2_TXD    {PIO_PA10A_TXD2, PIOA, ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT}
#define PIN_USART2_TXD_IDX        (PIO_PA10_IDX)
#define PIN_USART2_TXD_FLAGS      (PIO_PERIPH_A | PIO_DEFAULT)
//-- USART2 pin RTS --//
#define PIN_USART2_RTS    {PIO_PA14A_RTS2, PIOA, ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT}
#define PIN_USART2_RTS_IDX        (PIO_PA14_IDX)
#define PIN_USART2_RTS_FLAGS      (PIO_PERIPH_A | PIO_PULLUP | PIO_DEFAULT)
//-- USART2 pin CTS --//
#define PIN_USART2_CTS    {PIO_PA15A_CTS2, PIOA, ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT}
#define PIN_USART2_CTS_IDX        (PIO_PA15_IDX)
#define PIN_USART2_CTS_FLAGS      (PIO_OUTPUT_0 | PIO_PULLUP | PIO_DEFAULT)//(PIO_PERIPH_A | PIO_DEFAULT)
//-- RE pin. --//
#define PIN_USART2_RE_IDX           PIN_USART2_CTS_IDX
#define PIN_USART2_RE_FLAGS         (PIO_OUTPUT_0 | PIO_PULLUP | PIO_DEFAULT)

//--- USART3 pin RX --//
#define PIN_USART3_RXD    {PIO_PA3A_RXD3, PIOA, ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT}
#define PIN_USART3_RXD_IDX        (PIO_PA3_IDX)
#define PIN_USART3_RXD_FLAGS      (PIO_PERIPH_A | PIO_DEFAULT)
//-- USART3 pin TX --//
#define PIN_USART3_TXD    {PIO_PA4A_TXD3, PIOA, ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT}
#define PIN_USART3_TXD_IDX        (PIO_PA4_IDX)
#define PIN_USART3_TXD_FLAGS      (PIO_PERIPH_A | PIO_DEFAULT)
//-- USART3 pin RTS --//
#define PIN_USART3_RTS    {PIO_PA0A_RTS3, PIOA, ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT}
#define PIN_USART3_RTS_IDX        (PIO_PA0_IDX)
#define PIN_USART3_RTS_FLAGS      (PIO_PERIPH_A | PIO_PULLUP | PIO_DEFAULT)
//-- USART3 pin CTS --//
#define PIN_USART3_CTS    {PIO_PA1A_CTS3, PIOA, ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT}
#define PIN_USART3_CTS_IDX        (PIO_PA1_IDX)
#define PIN_USART3_CTS_FLAGS      (PIO_OUTPUT_0 | PIO_PULLUP | PIO_DEFAULT)//(PIO_PERIPH_A | PIO_DEFAULT)
//-- RE pin. --//
#define PIN_USART3_RE_IDX           PIN_USART3_CTS_IDX
#define PIN_USART3_RE_FLAGS         (PIO_OUTPUT_0 | PIO_PULLUP | PIO_DEFAULT)

//#if 0
///** USART1 pin ENABLE */
//#define PIN_USART1_EN     {PIO_PA17A_SCK1, PIOA, ID_PIOA, PIO_OUTPUT_0, PIO_DEFAULT}
//#define PIN_USART1_EN_IDX         (PIO_PA23_IDX)
//#define PIN_USART1_EN_FLAGS       (PIO_OUTPUT_0 | PIO_DEFAULT)
//#endif
//
///** USART1 pin SCK */
//#define PIN_USART1_SCK    {PIO_PA16A_SCK1, PIOA, ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT}
//#define PIN_USART1_SCK_IDX        (PIO_PA16_IDX)
//#define PIN_USART1_SCK_FLAGS      (PIO_PERIPH_A | PIO_DEFAULT)
//
///*----------------------------------------------------------------------------*/
//
///* IRDA SD pin. */
//#define PIN_IRDA_SD_IDX            PIN_USART1_CTS_IDX
//#define PIN_IRDA_SD_FLAGS          (PIO_OUTPUT_1 | PIO_DEFAULT)
//
///* TXD pin configuration. */
//#define PIN_USART_TXD_IDX          PIN_USART1_TXD_IDX
//#define PIN_USART_TXD_FLAGS        (PIO_PERIPH_A | PIO_DEFAULT)
//#define PIN_USART_TXD_IO_FLAGS     (PIO_OUTPUT_0 | PIO_DEFAULT)


//#########################################################   
   

/* Configure UART pins */
#define CONF_BOARD_UART_CONSOLE

/* Configure ADC example pins */
//#define CONF_BOARD_ADC

/*
 * LED pins are not configured for PWM function here.
 * Because those LED pins are enabled for PIO function by default.
 * You can enable them according to application.
 */
/* Configure PWM LED0 pin */
//#define CONF_BOARD_PWM_LED0

/* Configure PWM LED1 pin */
//#define CONF_BOARD_PWM_LED1

/* Configure PWM LED2 pin */
//#define CONF_BOARD_PWM_LED2

/* Configure SPI pins */
//#define CONF_BOARD_SPI
//#define CONF_BOARD_SPI_NPCS0
//#define CONF_BOARD_SPI_NPCS1
//#define CONF_BOARD_SPI_NPCS2
//#define CONF_BOARD_SPI_NPCS3

/*
 * USART pins are configured as basic serial port by default.
 * You can enable other pins according application.
 */
/* Configure USART RXD pin */
//#define CONF_BOARD_USART_RXD

/* Configure USART TXD pin */
//#define CONF_BOARD_USART_TXD

/*Configure TWI0 */
//#define CONF_BOARD_TWI0

/* Configure USART CTS pin */
//#define CONF_BOARD_USART_CTS

/* Configure USART RTS pin */
//#define CONF_BOARD_USART_RTS

/* Configure USART synchronous communication SCK pin */
//#define CONF_BOARD_USART_SCK

/* Configure ADM33312 enable pin */
//#define CONF_BOARD_ADM3312_EN

/* Configure IrDA transceiver shutdown pin */
//#define CONF_BOARD_TFDU4300_SD

//-- Configure RS485 transceiver RE pin --//
//#define CONF_BOARD_ADM3485_RE

/* Configure LCD EBI pins */
//#define CONF_BOARD_ILI9325

/* Configure Backlight control pin */
//#define CONF_BOARD_AAT3155

/* Configure Touchscreen SPI pins */
//#define CONF_BOARD_ADS7843

/** Push button 1, "Wake up" definition */
//#define PB_WAKE_STRING		"USRPB1"
//#define PB_WAKE_IRQn		PIOB_IRQn
//#define PB_WAKE_MASK		PIN_PUSHBUTTON_1_MASK
//#define PB_WAKE_PIO		PIN_PUSHBUTTON_1_PIO
//#define PB_WAKE_ID		PIN_PUSHBUTTON_1_ID
//#define PB_WAKE_TYPE		PIN_PUSHBUTTON_1_TYPE
//#define PB_WAKE_ATTR		PIN_PUSHBUTTON_1_ATTR

/** Push button 2, "Tamper" definition */
//#define PB_TAMPER_STRING	"USRPB2"
//#define PB_TAMPER_IRQn		PIOC_IRQn
//#define PB_TAMPER_MASK		PIN_PUSHBUTTON_2_MASK
//#define PB_TAMPER_PIO		PIN_PUSHBUTTON_2_PIO
//#define PB_TAMPER_ID		PIN_PUSHBUTTON_2_ID
//#define PB_TAMPER_TYPE		PIN_PUSHBUTTON_2_TYPE
//#define PB_TAMPER_ATTR		PIN_PUSHBUTTON_2_ATTR

/** LED definition */
//#define LED_MASK	PIN_LED_0_MASK
//#define LED_PIO		PIN_LED_0_PIO
//#define LED_ID		PIN_LED_0_ID
//#define LED_TYPE	PIN_LED_0_TYPE
//#define LED_ATTR	PIN_LED_0_ATTR

/** PIO debounce filter parameters 10 Hz*/
#define PB_FILTER_GLITCH_VALUE		    10
/** LED blink time 300ms */
#define BLINK_PERIOD					300

/** Watchdog period 3000ms */
#define WDT_PERIOD					3000
/** Watchdog restart 2000ms */
#define WDT_RESTART_PERIOD			2000

/* Enable co-processor */
#define CONF_BOARD_ENABLE_COPROCESSOR

extern void board_init(void);


#endif /* CONF_BOARD_H_INCLUDED */
