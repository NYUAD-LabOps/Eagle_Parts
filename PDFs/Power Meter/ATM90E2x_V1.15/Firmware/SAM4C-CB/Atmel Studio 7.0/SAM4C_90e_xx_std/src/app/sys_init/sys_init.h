//===================================================================
#ifndef SYS_INIT_H_INCLUDED
#define SYS_INIT_H_INCLUDED

#include "compiler.h"

/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
extern "C" {
#endif
/**INDENT-ON**/
/// @endcond

#define	SAM4C_xx_CHIP_ID_VALUE		0x00
#define	SAM4CMP_xx_CHIP_ID_VALUE	0x01
#define	SAM4CMS_xx_CHIP_ID_VALUE	0x02
//===================================================================
void	Initialize_RamVar( void );
uint32_t	get_chip_id( void );
void	sysclock_init( void );
void	sys_init(void);

/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
}
#endif
/**INDENT-ON**/
/// @endcond


#endif /* SYS_INIT_H_INCLUDED */
