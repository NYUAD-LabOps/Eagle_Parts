/**
 * \file help.c 
 *
 * \brief Demo Meter hekp messages.
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
 * Created: 9/25/2012 10:10:25 AM
 * By: LVN
 */
 
#include "asf.h"

/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
extern "C" {
#endif
/**INDENT-ON**/
/// @endcond


// Main command menu
const uint8_t Menu_1[]  = {"\r\n        Atmel Demo Meter command menu\r\n"};
const uint8_t Menu_2[]  = {"CMD[cmd] [option] [parameter] .. [parameter]\r"};
const uint8_t Menu_3[]  = {" Where CMD & cmd are an uppercase letter command. \r"};
const uint8_t Menu_4[]  = {"     option is a numeric character(s)\r"};
const uint8_t Menu_5[]  = {"     parameter(s) is numeric character string\r\n"};
const uint8_t Menu_6[]  = {"The following commands are available: \r"};
const uint8_t Menu_7[]  = {" ; - Comment line, 1st char : A or ! - Repeat last command Again\r"};
const uint8_t Menu_8[]  = {" D - DSP configuration      : E - Turn On/Off Energy measurements\r"};
const uint8_t Menu_9[]  = {" M - Meter configuration    : P - EEPROM Data blocks Fill/Display\r"};
const uint8_t Menu_10[] = {" R - RAM read/write         : S - Set/Display RTC clock\r"};     
const uint8_t Menu_11[] = {" T - Terminal display       : ? or H - Available commands\r"}; 
const uint8_t Menu_12[] = {"\r\n"};
const uint8_t Menu_13[] = {"For Example: ?D to get help for DSP command.\r\n"};

const uint8_t * menu[] = {
    Menu_1,    Menu_2,    Menu_3,    Menu_4,    Menu_5,
    Menu_6,    Menu_7,    Menu_8,    Menu_9,    Menu_10,
    Menu_11,   Menu_12,   Menu_13,   
	NULL         
};

// DSP command menu
const uint8_t dsp_1[] = {"       Display/Set DSP configuration parameters\r"};
const uint8_t dsp_2[] = {" D[cmd]	[Opt]	[parameter1] .. [parameter n]\r\n"};
const uint8_t dsp_3[] = {"  Where [Opt]: offset for DSP configuration table\r\n"};
const uint8_t dsp_4[] = {" D  - Display DSP configuration parameters\r"};
const uint8_t dsp_5[] = {" DA - Display/Write (adjust) DSP calibration constants\r"};
const uint8_t dsp_6[] = {" DC - Display/Write DSP controls\r"};
const uint8_t dsp_7[] = {" DF - Display/Write analog Front-end controls\r"};
const uint8_t dsp_8[] = {" DL - Display/Write DSP line voltage controls\r"};
const uint8_t dsp_9[] = {"The following commands do not need Opt, parameters\r"};
const uint8_t dsp_10[]= {" DH - Display DSP status\r"};
const uint8_t dsp_11[]= {" DD - Write default parameters to DSP configuration\r"};
const uint8_t dsp_12[]= {" DR - Restore DSP configuration  parameters from EEPROM\r"};
const uint8_t dsp_13[]= {" DS - Save DSP configuration  parameters to EEPROM\r\n"};
const uint8_t dsp_14[]= {"For Example: DA - Display DSP calibration constants.\r\n"};

const uint8_t * dsp_menu[] = {
    dsp_1,    dsp_2,    dsp_3,    dsp_4,    dsp_5,
    dsp_6,    dsp_7,    dsp_8,    dsp_9,    dsp_10,
    dsp_11,   dsp_12,   dsp_13,   dsp_14,  
	NULL         
};

// Energy Measurement On/Off commands
const uint8_t energy_1[] = {"          Energy Measurement On/Off commands\r"};
const uint8_t energy_2[] = {" E [Opt]\r"};
const uint8_t energy_3[] = {" E - Energy Measurement On/Off commands\r\n"};
const uint8_t energy_4[] = {"For Example: E 0 - Turn Off energy measurements\r"};
const uint8_t energy_5[] = {"              E 1 - Turn On energy measurements\r\n"};

const uint8_t * energy_menu[] = {
    energy_1,    energy_2,    energy_3,    energy_4,    energy_5,
	NULL         
};


// Display (LCD) commands  (Not Used)
const uint8_t display_1[] = {"            LCD display commands\r"};
const uint8_t display_2[] = {" L[cmd]	[Opt]\r"};
const uint8_t display_3[] = {"  Where [Opt] 0: Total;  1-4: Phase (A, B, C, N) \r\n"};
const uint8_t display_4[] = {" LA - Display Apparent Power (VAh) on LCD\r"};
const uint8_t display_5[] = {" LP - Display Active Power (Wh) on LCD\r"};
const uint8_t display_6[] = {" LR - Display Reactive Power (VArh) on LCD\r"};
const uint8_t display_7[] = {" LV - Display input Voltage on LCD\r"};
const uint8_t display_8[] = {" LI - Display input current on LCD\r"};
const uint8_t display_9[] = {" LF - Display line Frequency on LCD\r"};
const uint8_t display_10[]= {" LT - Display Time on LCD\r"};
//const uint8_t display_11[]= {" LS - Display Frequency on LCD\r\n"};
//const uint8_t display_12[]= {" LS - Display meter Mode on LCD\r\n"};
const uint8_t display_13[]= {"For Example: LV - Display phase A Voltage\r\n"};

const uint8_t * display_menu[] = {
    display_1,    display_2,    display_3,    display_4,    display_5,
    display_6,    display_7,    display_8,    display_9,    display_10,
    /*display_11,   display_12, */  display_13,
	NULL         
};


// Display on HyperTerminal commands
const uint8_t terminal_1[] = {"            Terminal display commands\r"};
const uint8_t terminal_2[] = {" T[cmd]\r\n"};
const uint8_t terminal_3[] = {" T  - Display snapshot of all the commands below\r"};
const uint8_t terminal_4[] = {" TA - Display live Apparent Power in Dec. (VAh X1000)\r"};
const uint8_t terminal_5[] = {" TI - Display live Voltage&Current in Dec. (V X100, I X100)\r"};
const uint8_t terminal_6[] = {" TP - Display live Active&Reactive Power in Dec. (Wh X1000, VArh X1000)\r"};
const uint8_t terminal_7[] = {" TE - Display live Raw DSP Active&Reactive Power in Hex. (Px, Qx)\r"};
const uint8_t terminal_8[] = {" TR - Display live Raw DSP Voltage&Current in Hex. (Vx, Ix)\r"};
const uint8_t terminal_9[] = {" TS - Display live meter status in Hex.\r\n"};
const uint8_t terminal_10[] = {"For Example: TI - Display Voltage&Current\r\n"};

const uint8_t * terminal_menu[] = {
    terminal_1,    terminal_2,    terminal_3,    terminal_4,    terminal_5,
    terminal_6,    terminal_7,    terminal_8,    terminal_9,    terminal_10,  
	NULL         
};

// Meter configuration commands
const uint8_t meter_1[] = {"           Meter Configuration commands\r"};
const uint8_t meter_2[] = {" M[cmd]	[Opt]	[parameter1] .. [parameter n]\r"};
const uint8_t meter_3[] = {"  Where [Opt]: offset for meter configuration table\r\n"};
const uint8_t meter_4[] = {" M  - Read and display meter configuration  parameters\r"};
const uint8_t meter_5[] = {" MC - Display/Write meter configuration parameters\r"};
const uint8_t meter_6[] = {" MT - Display/Write meter temperature cal. parameters\r\n"};

const uint8_t meter_10[]= {"For Example: MT 1 1234 - Write 1234 to 2nd entry\r"};
const uint8_t meter_11[]= {"             of meter temperature cal. parameters\r\n"};

const uint8_t * meter_menu[] = {
    meter_1,    meter_2,    meter_3,    meter_4,    meter_5,
    meter_6,   
    meter_10,   meter_11,   
	NULL         
};

// RAM read write commands
const uint8_t ram_1[] = {"             Memory (IRAM) commands\r"};
const uint8_t ram_2[] = {" R[cmd]	[Opt]	[parameter1] .. [parameter n]\r"};
const uint8_t ram_3[] = {"   Where [Opt]: Address offset from IRAM start (0x20000000)\r\n"};
const uint8_t ram_4[] = {" R  - Read and display IRAM contents at starting address (0X20000000)\r"};
const uint8_t ram_5[] = {" RW - Read/Write data(s) to IRAM starting address plus offset (bytes)\r"};
const uint8_t ram_6[] = {" RF - Fill data to IRAM starting address with offset for #words\r\n"};

const uint8_t ram_7[] = {"For Example: RF 0 55 256  Fill 55 to IRAM starting address for 256 words\r\n"};

const uint8_t * ram_menu[] = {
    ram_1,    ram_2,    ram_3,    ram_4,    ram_5,
    ram_6,    ram_7,   
	NULL         
};

// EEPROM data commands
const uint8_t prom_1[] = {"          EEPROM data commands\r"};
const uint8_t prom_2[] = {"\r\n"};
const uint8_t prom_3[] = {" PE - Erase EEPROM data (0xFF)\r"};
const uint8_t prom_4[] = {" PD - Read/Display EEPROM data\r"};
const uint8_t prom_5[] = {"\r\n"};
const uint8_t prom_6[] = {"For Example: PE - Erase EEPROM data (0xFF)\r\n"};

const uint8_t * prom_menu[] = {
    prom_1,    prom_2,    prom_3,    prom_4,    prom_5,
	prom_6,
	NULL         
};


// Set/Dislay time (RTC) commands
const uint8_t time_1[]  = {"          Set/Display time and date command\r"};
const uint8_t time_2[]  = {" S[cmd]	[Opt]	[parameter1] .. [parameter n]\r"};
const uint8_t time_3[]  = {"  Where [Opt]: 0: English;       1: International \r"};
const uint8_t time_4[]  = {"             0: 24-Hour mode;  1: 12-hour mode\r\n"};
const uint8_t time_5[]  = {" S  - Display time and date in English format\r"};
const uint8_t time_6[]  = {" ST - Set time\r"};
const uint8_t time_7[]  = {" SD - Set date\r\n"};
const uint8_t time_8[]  = {"For Example: ST 0 14:30:51  - Set time in 24H mode\r\n"};
const uint8_t time_9[]  = {"             SD 0 10/02/2012 - Set date in English format\r\n"};

const uint8_t * time_menu[] = {
    time_1,    time_2,    time_3,    time_4,    time_5,
    time_6,    time_7,    time_8,    time_9,   
 	NULL         
};

/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
}
#endif
/**INDENT-ON**/
/// @endcond


