//===================================================================
#ifndef ENERGY_H_INCLUDED
#define ENERGY_H_INCLUDED

#include "compiler.h"

/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
extern "C" {
#endif
/**INDENT-ON**/
/// @endcond

#define	MeterConst	0x20		//3200imp/kWh

typedef	struct
{
	uint32_t	pulse;
	uint32_t	integer;	
}ENERGY_Str;

#define ENERGY_Str_SIZE   (sizeof(ENERGY_Str)/sizeof(uint32_t))

typedef struct 
{
	//Type      Name		Description
	uint32_t	pulse;
    ENERGY_Str	total;		//total energy
	ENERGY_Str	tou1;
	ENERGY_Str	tou2;
	ENERGY_Str	tou3;
	ENERGY_Str	tou4;	
}ENERGY_TYPE;

#define ENERGY_TYPE_SIZE   (sizeof(ENERGY_TYPE)/sizeof(uint32_t))


//====================================================================
extern	ENERGY_TYPE	VEnergy;

//--------------------------------------------------------------------
void	ReadEnergyDecimal(uint16_t E2PgInAddr,uint8_t *ptrram);
void	EnergyServe(uint16_t E2IntegerPgInAdr,uint32_t E2DecimalPgInAdr);
void	RestoreRamEnergyFromEprom(void);
void	Add_PulseEnergy(uint32_t val);
void	Clear_Energy(void);
void	PulseProcess(void);
void	EnergyProcess(void);




/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
}
#endif
/**INDENT-ON**/
/// @endcond


#endif /* ENERGY_H_INCLUDED */
