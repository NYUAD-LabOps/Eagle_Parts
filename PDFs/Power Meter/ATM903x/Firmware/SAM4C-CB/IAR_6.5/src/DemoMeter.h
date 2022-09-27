//========================================================================
 
#ifndef _DEMOMETER_H_INCLUDED
#define _DEMOMETER_H_INCLUDED


#include "target.h"

#define IPC_ENABLE 1    // enable dual core data transfer

//#define DSP_VERSION    "DSP FW Ver. 0.6.6" // first release
//#define DSP_VERSION    "DSP FW Ver. 0.6.7"   // settling time reduced to ~6sec
//#define DSP_VERSION    "DSP FW Ver. 0.6.8"   // settling time reduced to ~2sec for 50/60Hz (~6sec for off freq).
//#define METER_VERSION  "Meter FW Ver. 0.6.6"
//#define STRING_HEADER   "\r\n-- Atmel Demo Meter - "BOARD_NAME" - "DSP_VERSION"  --\r\n" \
//                            "-- "METER_VERSION" Compiled: "__DATE__" "__TIME__" -- \r\n"

// Maximum size of edited string. //
//#define MAX_EDIT_SIZE			10

enum mode 
{
	IDLE_MODE = 0,
    BATTERY_MODE,
    RESTART_MODE,
	LCD_MODE,
	SLEEP_MODE,
    NORMAL_MODE
};

enum host_cmd_state 
{
	IDLE = 0,
	USER_CMD_RX,
	USER_CMD_ACK,
	USER_CMD_TIMOUT,
	USER_CMD_ERROR,
	RESULT,
	WAIT,
	SLEEP,
	WAKE
};
enum second_state 
{
	DONE = 0,
	SECOND_DATA,
	PROCESS,
	MONITOR
};
enum minute_state 
{
	ACCUMMULATION = 0,
	ENERGY,
	DEMAND,
	TOU
};
// system parameters
typedef struct 
{
    uint32_t    mode;
    uint32_t    ms_ticks;
	uint32_t	dispkeydn;
	uint32_t	dispkeyup;
} sys_t, * p_sys;
#define SYS_SIZE (sizeof(sys_t)/sizeof(uint32_t))


#define POWER_FAIL_EVENT    

// Macros for character conversion.
#define upper(c)         ((c >= 'a') ? (c - ('a'-'A')) : c)
#define char_to_digit(c) ((c) - '0')
#define is_num(c)        ((c) >= '0' && (c) <= '9')
#define is_hex(c)        (((c) >= '0' && (c) <= '9') || ((c) >= 'A' && (c) <= 'F'))
#define is_cmd(c)        (((c) == '!' || (c) == '?'|| (c) == ';') || ((c) >= 'A' && (c) <= 'Z'))
#define is_blank(c)      (0x20 == (c) || '\t' == (c))


/******************************************************************************
 * FUNCTION PROTOTYPES 
 *****************************************************************************/                                                      
extern  sys_t       sys;
//------------------------------------------------------------------------
// FUNCTION PROTOTYPES 
//------------------------------------------------------------------------                                                      
void    fail_detect_handler(void);
void    power_fail_detect(void);
void	DispDnkey_INT_handler(void);
void	DispDnkey_detect_config(void);
void	DispUpkey_INT_handler(void);
void	DispUpkey_detect_config(void);

void battery_mode_init(void);
void battery_mode(void);
void restart_mode(void);
void idle_mode(void);
void LCD_mode(void);
void Normal_mode(void);
void configure_coprocessor(void);

int main(void);



/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
}
#endif
/**INDENT-ON**/
/// @endcond

#endif /* _DEMOMETER_H_INCLUDED */
