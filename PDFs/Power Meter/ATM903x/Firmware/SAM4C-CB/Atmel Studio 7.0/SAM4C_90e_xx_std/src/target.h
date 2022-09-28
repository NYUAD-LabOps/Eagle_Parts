
//=========================================================
#ifndef _TARGET_H_INCLUDED
#define _TARGET_H_INCLUDED
//=========================================================
/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
extern "C" {
#endif
/**INDENT-ON**/
/// @endcond
//---------------------------------------------------------
#define	PrgDebug	1

#define	SoftwareVersion		0x101		//1.01
//---------------------------------------------------------
#include "compiler.h"
//#include "status_codes.h"
#include "string.h"
#include "core_cmInstr.h"
#include "core_cm4.h"
#include "math.h"
  
#include "asf.h"
#include "conf_board.h"

#include "app\sys_init\sys_init.h"
#include "app\main\main.h"
#include "app\kenerl\task.h"
#include "app\basetimer\basetimer.h"
#include "app\display\display.h"
#include "app\rtcproc\rtcproc.h"
#include "app\communication\comprocess.h"
#include "app\secondproc\secondproc.h"
#include "app\touproc\touproc.h"
#include "app\checkmajorpara\checkmajorpara.h"
#include "app\presskey\presskey.h"
#include "app\energy\energy.h"
#include "app\at90e_xx\at90e_xx.h"
#include "app\eeprom\eeprom.h"
#include "app\meter_math\meter_math.h"

//---------------------------------------------------------
/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
}
#endif
/**INDENT-ON**/
/// @endcond
//---------------------------------------------------------
#endif /* _TARGET_H_INCLUDED */
//=========================================================
