//========================================================================
 
#ifndef _MAIN_H_INCLUDED
#define _MAIN_H_INCLUDED

//===============================================
#include "target.h"
//===============================================
// Macros for character conversion.
//! CHIP ID
#define SAM4CMP16C_CHIP_ID_VALUE	0xA64C0CE001
#define SAM4CMP8C_CHIP_ID_VALUE		0xA64C0AE001
#define SAM4CMS16C_CHIP_ID_VALUE	0xA64C0CE002
#define SAM4CMS8C_CHIP_ID_VALUE		0xA64C0AE002

typedef	enum
{
	SAM4C32C_A_CHIP_ID_VALUE		=0xA64D0EE000,
	SAM4C32E_A_CHIP_ID_VALUE		=0xA66D0EE000,
	SAM4C16C_A_CHIP_ID_VALUE		=0xA64C0CE000,
	SAM4C8C_A_CHIP_ID_VALUE			=0xA64C0AE000,
	SAM4C16C_B_CHIP_ID_VALUE		=0xA64C0CE100,
	SAM4C8C_B_CHIP_ID_VALUE			=0xA64C0AE100,
	
	SAM4CMP32C_A_CHIP_ID_VALUE		=0xA64D0EE001,	
	SAM4CMP16C_A_CHIP_ID_VALUE		=0xA64C0CE001,
	SAM4CMP8C_A_CHIP_ID_VALUE		=0xA64C0AE001,
	SAM4CMP16C_B_CHIP_ID_VALUE		=0xA64C0CE101,
	SAM4CMP8C_B_CHIP_ID_VALUE		=0xA64C0AE101,
	
	SAM4CMS32C_A_CHIP_ID_VALUE		=0xA64D0EE002,
	SAM4CMS16C_A_CHIP_ID_VALUE		=0xA64C0CE002,
	SAM4CMS8C_A_CHIP_ID_VALUE		=0xA64C0AE002,
	
	SAM4CMS16C_B_CHIP_ID_VALUE		=0xA64C0CE102,
	SAM4CMS8C_B_CHIP_ID_VALUE		=0xA64C0AE102,
	
}CHIP_ID_TYPE;

typedef enum
{ 	
	SAM4CMP16C_CHIP_ID	= 0,
    SAM4CMP8C_CHIP_ID	= 1,
    SAM4CMS16C_CHIP_ID	= 2,
    SAM4CMS8C_CHIP_ID	= 3,
	
	SAM4C32C_A_CHIP_ID		=4,
	SAM4C32E_A_CHIP_ID		=5,
	SAM4C16C_A_CHIP_ID		=6,
	SAM4C8C_A_CHIP_ID		=7,
	SAM4C16C_B_CHIP_ID		=8,
	SAM4C8C_B_CHIP_ID		=9,
	
	SAM4CMP32C_A_CHIP_ID	=10,
	SAM4CMP16C_A_CHIP_ID	=11,
	SAM4CMP8C_A_CHIP_ID		=12,
	SAM4CMP16C_B_CHIP_ID	=13,
	SAM4CMP8C_B_CHIP_ID		=14,
	
	SAM4CMS32C_A_CHIP_ID	=15,
	SAM4CMS16C_A_CHIP_ID	=16,
	SAM4CMS8C_A_CHIP_ID		=17,
	SAM4CMS16C_B_CHIP_ID	=18,
	SAM4CMS8C_B_CHIP_ID		=19,
	
	SAM4C_xx_CHIP_ID		=0x55,
	SAM4CMS_xx_CHIP_ID		=0x68,
	SAM4CMP_xx_CHIP_ID		=0x86,
	
    CHIP_ID_UNAVAILABLE = 0xFF
} E_CHIP_ID;

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
    //uint32_t    mode;
    //uint32_t    ms_ticks;
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


//------------------------------------------------------------------------
//	FUNCTION PROTOTYPES 
//------------------------------------------------------------------------                                                      
//extern  sys_t       sys;
//------------------------------------------------------------------------
// FUNCTION PROTOTYPES 
//------------------------------------------------------------------------                                                      

void	Normal_mode_init(void);

int main(void);



/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
}
#endif
/**INDENT-ON**/
/// @endcond

#endif /* _MAIN_H_INCLUDED */
