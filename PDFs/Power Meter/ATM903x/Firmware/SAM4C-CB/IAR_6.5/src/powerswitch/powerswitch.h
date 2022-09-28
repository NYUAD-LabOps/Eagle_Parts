//===================================================================
#ifndef powerswitch_H_INCLUDED
#define powerswitch_H_INCLUDED

#include "compiler.h"

/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
extern "C" {
#endif
/**INDENT-ON**/
/// @endcond


#define AT91C_PERIPH_CLOCK_OFF     0
#define AT91C_PERIPH_CLOCK_ON      1


            

enum {\
          CONSOMODE_LOWP_BACKUP_MODE,\
          CONSOMODE_WAIT_MODE,\
          CONSOMODE_SLEEP_MODE,\
          CONSOMODE_ACTIVE_MODE
      
       };    


///////////////////////////////
#define ASM_ALGO_FLASH             1
#define ASM_ALGO_RAM               2

#define DIVISION_ALGO_FLASH        3
#define DIVISION_ALGO_RAM          4

#define FIBONACCI_ALGO_FLASH       5
#define FIBONACCI_ALGO_RAM         6

#define DHRYSTONE_ALGO             7

#define COREMARK_ALGO              0

/////////////////////////////////
#define FAM64     0
#define FAM128    1

#define CLOEDISABLE 0
#define CLOENABLE   1

#define SOCDDISABLE 1
#define SOCDENABLE  0

#define ENABLE     0
#define DISABLE    1

#define PERIPH_CLOCK_OFF     0
#define PERIPH_CLOCK_ON    1

/////////////////////////////////////////
typedef struct 
{
     char flashSetMode64_128;
     char flashWaitstate;
     char flashCloe;
     char flashSocd;
     char flashNc;
     unsigned int consumtionMode;
     unsigned int PeripheralStates;
     
} ST_COMSUMPTION_MODE_DEVICE_SET;

typedef struct 
{
         unsigned int index;
         char source[32]; 
         unsigned int corefreq;
         unsigned int selectCSS;
         unsigned int PrescalerPRES;


} ST_CLOCK_CORE;
///////////////////////////////////////
void prepare_mode(void);

/*Functions prototypes*/
void All_PIO_input_pullup(ST_COMSUMPTION_MODE_DEVICE_SET *stconso_mode);
void Save_Power_Consumption(ST_COMSUMPTION_MODE_DEVICE_SET *stconso_mode);
void Prepare_Sleep_Mode(ST_COMSUMPTION_MODE_DEVICE_SET *stconso_mode);
void Prepare_Sleep_Mode_C0(ST_COMSUMPTION_MODE_DEVICE_SET *stconso_mode);
void Prepare_Wait_Mode(ST_COMSUMPTION_MODE_DEVICE_SET *stconso_mode );
void Prepare_Backup_Mode_A(ST_COMSUMPTION_MODE_DEVICE_SET *stconso_mode);
void Prepare_Backup_Mode_B(ST_COMSUMPTION_MODE_DEVICE_SET *stconso_mode);
void All_PIO_output(void);
void Save_Active_Power_Consumption( ST_COMSUMPTION_MODE_DEVICE_SET *stconso_mode);
void Run_Active_Mode( ST_COMSUMPTION_MODE_DEVICE_SET *stconso_mode);
void ConfigureFlash(ST_COMSUMPTION_MODE_DEVICE_SET *stconso_mode);
void Select_MAINOSC_for_MCK(void);
void LowPower_Select_MAINOSC_for_32k(void);

void _pmc_enable_waitmodewithoutWFE(void);
void _pmc_enable_backupmode_vroff(void);
//===================================================================

/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
}
#endif
/**INDENT-ON**/
/// @endcond


#endif /* DISPLAY_H_INCLUDED */
