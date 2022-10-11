/* ----------------------------------------------------------------------------
 *         ATMEL Microcontroller Software Support
 * ----------------------------------------------------------------------------
 * Copyright (c) 2009, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */


// Base functions extracted from softpack


#include "v_efc.h"

/*----------------------------------------------------------------------------
 *        Exported functions (validation team addition)
 *----------------------------------------------------------------------------*/
extern uint32_t v_efc_get_flash_descriptor(Efc* efc, iflash_descriptor_t* fdes, uint32_t dwUseIAP )
{
 uint32_t i;
 
  v_EFC_PerformCommand(efc,EFC_FCMD_GETD,0,dwUseIAP);
  fdes->fl_id        = efc->EEFC_FRR;
  fdes->fl_size      = efc->EEFC_FRR;
  fdes->fl_page_size = efc->EEFC_FRR;
  fdes->fl_nb_plane  = efc->EEFC_FRR;
  for(i=0;i<fdes->fl_nb_plane;++i){
    fdes->fl_plane[i] = efc->EEFC_FRR;
    }
  fdes->fl_nb_lock  = efc->EEFC_FRR;
  for(i=0;i<fdes->fl_nb_lock;++i){
    fdes->fl_lock[i] = efc->EEFC_FRR;
    }

  return 0;
}


extern __ramfunc uint32_t v_EFC_PerformCommand( Efc* efc, uint8_t Command, uint16_t Argument, uint32_t dwUseIAP )
{
 uint32_t efc_index;
  
  if(!efc)return(0);
 
  if ( dwUseIAP != RAM_EXEC )
    {
        // Pointer on IAP function in ROM 
        static uint32_t (*IAP_PerformCommand)( uint32_t, uint32_t ) ;
        #if (DEVICE_HAS_EFC1 == 1)        
          if (efc==EFC1) efc_index = 1;
          else  efc_index = 0;
        #else
          efc_index = 0;
        #endif
        IAP_PerformCommand = (uint32_t (*)( uint32_t, uint32_t )) *((uint32_t*)CHIP_FLASH_IAP_ADDRESS ) ;
        IAP_PerformCommand(efc_index, EEFC_FCR_FKEY(EFC_KEY_VAL) | EEFC_FCR_FARG(Argument) | EEFC_FCR_FCMD(Command) ) ;

        return ( efc->EEFC_FSR & (WR_ERRORS_MASK) ) ;
    }
    else
    {
        uint32_t dwStatus ;

        efc->EEFC_FCR = EEFC_FCR_FKEY(EFC_KEY_VAL) | EEFC_FCR_FARG(Argument) | EEFC_FCR_FCMD(Command) ;
        do
        {
            dwStatus = efc->EEFC_FSR ;
        }
        while ( (dwStatus & EEFC_FSR_FRDY) != EEFC_FSR_FRDY ) ;

        return ( dwStatus & (WR_ERRORS_MASK) ) ;
    }
}

extern void v_EFC_ComputeAddress(uint16_t wPage, uint16_t wOffset, uint32_t *pdwAddress )
{
    uint32_t dwAddress ;
	
    /* Compute address */
    dwAddress = IFLASH_ADDR + wPage * IFLASH_PAGE_SIZE + wOffset ;
	
    /* Store result */
    if ( pdwAddress != 0 ) // !=NULL
	{
        *pdwAddress = dwAddress ;
    }
}
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/



//----------------------------------------------------------------------------
//        (validation team addition)
//----------------------------------------------------------------------------
extern __ramfunc uint32_t v_EFC_PerformCommand_parallel(Efc* efc0, Efc* efc1, uint8_t Command0, uint8_t Command1, uint16_t Argument0, uint16_t Argument1, uint32_t* pStatus0, uint32_t* pStatus1)
{
 uint8_t cmd0, cmd1;
 
  cmd1=cmd0=1;
  
  if(efc0){
    efc0->EEFC_FCR = EEFC_FCR_FKEY(EFC_KEY_VAL) | EEFC_FCR_FARG(Argument0) | EEFC_FCR_FCMD(Command0);
    cmd0 = 0;
    }
  if(efc1){
    efc1->EEFC_FCR = EEFC_FCR_FKEY(EFC_KEY_VAL) | EEFC_FCR_FARG(Argument1) | EEFC_FCR_FCMD(Command1);
    cmd1 = 0;
    }

  do
    {
      if(efc0){*pStatus0 = efc0->EEFC_FSR;
               cmd0 = (((*pStatus0) & EEFC_FSR_FRDY) == EEFC_FSR_FRDY );}
      if(efc1){*pStatus1 = efc1->EEFC_FSR;
               cmd1 = (((*pStatus1) & EEFC_FSR_FRDY) == EEFC_FSR_FRDY );}
    }
  while(!(cmd0 && cmd1));
  
  (*pStatus0)&=WR_ERRORS_MASK;
  (*pStatus1)&=WR_ERRORS_MASK;
    
  if ((*pStatus0)||(*pStatus1))
    return 1; // write error detected
  else
    return 0; // no write error detected
}
//----------------------------------------------------------------------------




/*----------------------------------------------------------------------------
 *        Exported functions (mainly extracted fromSoft pack)
 *----------------------------------------------------------------------------*/

/**
 * \brief Enables the flash ready interrupt source on the EEFC peripheral.
 *
 * \param efc  Pointer to a Efc instance
 */
extern void EFC_EnableFrdyIt( Efc* efc )
{
    efc->EEFC_FMR |= EEFC_FMR_FRDY ;
}



/**
 * \brief Disables the flash ready interrupt source on the EEFC peripheral.
 *
 * \param efc  Pointer to a Efc instance
 */

extern void EFC_DisableFrdyIt( Efc* efc )
{
    efc->EEFC_FMR &= ~((uint32_t)EEFC_FMR_FRDY) ;
}



/**
 * \brief Set read/write wait state on the EEFC perpherial.
 *
 * \param efc  Pointer to a Efc instance
 * \param cycles  the number of wait states in cycle.
 */

extern void EFC_SetWaitState( Efc* efc, uint8_t ucCycles )
{
    uint32_t dwValue ;

    dwValue = efc->EEFC_FMR ;
    dwValue &= ~((uint32_t)EEFC_FMR_FWS_Msk) ;
    dwValue |= EEFC_FMR_FWS(ucCycles);
    efc->EEFC_FMR = dwValue ;
}



/**
 * \brief Returns the current status of the EEFC.
 *
 * \note Keep in mind that this function clears the value of some status bits (LOCKE, PROGE).
 *
 * \param efc  Pointer to a Efc instance
 */
extern uint32_t EFC_GetStatus( Efc* efc )
{
    return efc->EEFC_FSR ;
}



/**
 * \brief Returns the result of the last executed command.
 *
 * \param efc  Pointer to a Efc instance
 */
extern uint32_t EFC_GetResult( Efc* efc )
{
    return efc->EEFC_FRR ;
}



/**
 * \brief Translates the given address page and offset values.
 * \note The resulting values are stored in the provided variables if they are not null.
 *
 * \param efc  Pointer to a Efc instance
 * \param address  Address to translate.
 * \param pPage  First page accessed.
 * \param pOffset  Byte offset in first page.
 */
/*
extern void EFC_TranslateAddress( Efc** ppEfc, uint32_t dwAddress, uint16_t* pwPage, uint16_t* pwOffset )
{
    Efc *pEfc ;
    uint16_t wPage ;
    uint16_t wOffset ;

    pEfc = EFC ;
    wPage = (dwAddress - IFLASH_ADDR) / IFLASH_PAGE_SIZE;
    wOffset = (dwAddress - IFLASH_ADDR) % IFLASH_PAGE_SIZE;

     // Store values
    if ( pEfc )
    {
        *ppEfc = pEfc ;
    }

    if ( pwPage )
    {
        *pwPage = wPage ;
    }

    if ( pwOffset )
    {
        *pwOffset = wOffset ;
    }
}
*/


/**
 * \brief Computes the address of a flash access given the page and offset.
 *
 * \param efc  Pointer to a Efc instance
 * \param page  Page number.
 * \param offset  Byte offset inside page.
 * \param pAddress  Computed address (optional).
 */
/*
extern void EFC_ComputeAddress( Efc *efc, uint16_t wPage, uint16_t wOffset, uint32_t *pdwAddress )
{
    uint32_t dwAddress ;
	
    // Compute address 
    dwAddress = IFLASH_ADDR + wPage * IFLASH_PAGE_SIZE + wOffset ;
	
    // Store result 
    if ( pdwAddress != 0 ) // !=NULL
	{
        *pdwAddress = dwAddress ;
    }
}
*/


/**
 * \brief Starts the executing the given command on the EEFC and returns as soon as the command is started.
 *
 * \note It does NOT set the FMCN field automatically.
 * \param efc  Pointer to a Efc instance
 * \param command  Command to execute.
 * \param argument  Command argument (should be 0 if not used).
 */
extern void EFC_StartCommand( Efc* efc, uint32_t dwCommand, uint32_t dwArgument )
{
    /* Start command Embedded flash */
    efc->EEFC_FCR = EEFC_FCR_FKEY(EFC_KEY_VAL) | EEFC_FCR_FARG(dwArgument) | EEFC_FCR_FCMD(dwCommand) ;
}



/**
 * \brief Performs the given command and wait until its completion (or an error).
 *
 * \param efc  Pointer to a Efc instance
 * \param command  Command to perform.
 * \param argument  Optional command argument.
 *
 * \return 0 if successful, otherwise returns an error code.
 */
/*
extern uint32_t EFC_PerformCommand( Efc* efc, uint32_t dwCommand, uint32_t dwArgument, uint32_t dwUseIAP )
{
    if ( dwUseIAP != 0 )
    {
        // Pointer on IAP function in ROM
        static uint32_t (*IAP_PerformCommand)( uint32_t, uint32_t ) ;

        IAP_PerformCommand = (uint32_t (*)( uint32_t, uint32_t )) *((uint32_t*)CHIP_FLASH_IAP_ADDRESS ) ;
        IAP_PerformCommand( 0, EEFC_FCR_FKEY(EFC_KEY_VAL) | EEFC_FCR_FARG(dwArgument) | EEFC_FCR_FCMD(dwCommand) ) ;

        return (efc->EEFC_FSR & (EEFC_FSR_FLOCKE | EEFC_FSR_FCMDE)) ;
    }
    else
    {
        uint32_t dwStatus ;

        efc->EEFC_FCR = EEFC_FCR_FKEY(EFC_KEY_VAL) | EEFC_FCR_FARG(dwArgument) | EEFC_FCR_FCMD(dwCommand) ;
        do
        {
            dwStatus = efc->EEFC_FSR ;
        }
        while ( (dwStatus & EEFC_FSR_FRDY) != EEFC_FSR_FRDY ) ;

        return ( dwStatus & (EEFC_FSR_FLOCKE | EEFC_FSR_FCMDE) ) ;
    }
}
*/

