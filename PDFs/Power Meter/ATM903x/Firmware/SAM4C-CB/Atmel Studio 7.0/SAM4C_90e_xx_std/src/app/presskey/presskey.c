//===================================================================
#include "target.h"
//-------------------------------------------------------------------
PRESSKEY_Str    VPressKey;
//-------------------------------------------------------------------

/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
extern "C" {
#endif
/**INDENT-ON**/
/// @endcond

//=========================================================
//decription	::	power down interrupt process
//function		::	fail_detect_handler
//input			::	none
//output		::	none
//call			::	none
//effect		::	none
//=========================================================
void	fail_detect_handler(uint32_t temp0, uint32_t temp1)
{
    //Vsys.mode = BATTERY_MODE;    
}
//=========================================================
//decription	::	power down check process
//function		::	power_fail_detect
//input			::	none
//output		::	none
//call			::	none
//effect		::	none
//=========================================================
void	power_fail_detect( void )
{
	pmc_enable_periph_clk( POWER_FAIL_ID );
	POWER_FAIL_In();
	POWER_FAIL_PIO_En();
	POWER_FAIL_PullUp_En();
	POWER_FAIL_PIO->PIO_IFER |= POWER_FAIL_MASK;
	//POWER_FAIL_PIO->PIO_SCDR =1000;
	POWER_FAIL_PIO->PIO_IFSCER |= POWER_FAIL_MASK;
	
	//pio_handler_set(POWER_FAIL_PIO, POWER_FAIL_ID, POWER_FAIL_MASK, PIO_IT_FALL_EDGE, fail_detect_handler);
    pio_enable_interrupt(POWER_FAIL_PIO, POWER_FAIL_MASK);
	
    NVIC_DisableIRQ(POWER_FAIL_IRQn);
    NVIC_ClearPendingIRQ(POWER_FAIL_IRQn);
    NVIC_SetPriority(POWER_FAIL_IRQn, 0);
    NVIC_EnableIRQ(POWER_FAIL_IRQn);	
}
//=========================================================
//decription	::	diplay down key interrupt process
//function		::	DispDnkey_detect_handler
//input			::	none
//output		::	none
//call			::	none
//effect		::	none
//=========================================================
void	DispDnkey_INT_handler(uint32_t temp0, uint32_t temp1)
{
	VPressKey.dnkey =0x55;
//	__NOP();
}
//=========================================================
//decription	::	diplay down key check process
//function		::	DispDnkey_detect_config
//input			::	none
//output		::	none
//call			::	none
//effect		::	none
//=========================================================
void	DispDnkey_detect_config(void)
{
    pmc_enable_periph_clk( DISPKEY_DN_ID );
	
	DISPKEY_DN_In();		//input
	DISPKEY_DN_PIO_En();	//is IO
	//DISPKEY_DN_PullDn_Dis();	//disable pull-down
	DISPKEY_DN_PullUp_En();	//pull-up
	
	//DISPKEY_DN_PIO->PIO_IFDR &= ( ~DISPKEY_DN_MASK );//configure Input Filter
	DISPKEY_DN_FILTER();	//
	
	//DISPKEY_DN_DEBOUNCE( 1000 );	//set debounce
	DISPKEY_DN_FILTER_EN();	//enable debounce
	
	//DISPKEY_DN_PIO->PIO_AIMER =DISPKEY_DN_MASK;		//enable event interrupt
	//
	//DISPKEY_DN_PIO->PIO_ESR =DISPKEY_DN_MASK;		//Edge triggle interrupt
	//DISPKEY_DN_PIO->PIO_FELLSR =DISPKEY_DN_MASK;	//Falling Edge triggle
	//	
	//DISPKEY_DN_PIO->PIO_ISR;					//read interrupt flag
	////DISPKEY_DN_PIO->PIO_IDR &= ( ~DISPKEY_DN_MASK );//disable other PIOB pin interrupt
	//DISPKEY_DN_PIO->PIO_IER =DISPKEY_DN_MASK;	//enable display key interrupt
	
	//// Disable the interrupt first
	//NVIC -> ICER[((uint32_t)DISPKEY_DN_IRQn>>5)] = (1 << (((uint32_t)DISPKEY_DN_IRQn)&0x1F) );
	//// Clear any pending status
	//NVIC -> ICPR[((uint32_t)DISPKEY_DN_IRQn>>5)] = (1 << (((uint32_t)DISPKEY_DN_IRQn)&0x1F) );
	//// Set priority
	//NVIC -> IP[((uint32_t)DISPKEY_DN_IRQn>>5)] = (1 << (((uint32_t)DISPKEY_DN_IRQn)&0x1F) );
	//// Enable IT
	//NVIC -> ISER[((uint32_t)DISPKEY_DN_IRQn>>5)] = (1 << (((uint32_t)DISPKEY_DN_IRQn)&0x1F) );
	
    pio_handler_set( DISPKEY_DN_PIO, DISPKEY_DN_ID, DISPKEY_DN_MASK, PIO_IT_FALL_EDGE, DispDnkey_INT_handler );
    pio_enable_interrupt( DISPKEY_DN_PIO, DISPKEY_DN_MASK );	
    NVIC_DisableIRQ(DISPKEY_DN_IRQn);
    NVIC_ClearPendingIRQ(DISPKEY_DN_IRQn);
    NVIC_SetPriority(DISPKEY_DN_IRQn, 1);
    NVIC_EnableIRQ(DISPKEY_DN_IRQn);    
}
//=========================================================
//decription	::	diplay down key interrupt process
//function		::	DispDnkey_detect_handler
//input			::	none
//output		::	none
//call			::	none
//effect		::	none
//=========================================================
void	DispUpkey_INT_handler(uint32_t temp0, uint32_t temp1)
{
	VPressKey.upkey =0x55;
}
//=========================================================
//decription	::	display up key configure
//function		::	DispUpkey_detect_config
//input			::	none
//output		::	none
//call			::	none
//effect		::	none
//=========================================================
void	DispUpkey_detect_config(void)
{
    pmc_enable_periph_clk( DISPKEY_UP_ID );
	DISPKEY_UP_In();
	DISPKEY_UP_PIO_En();
	DISPKEY_UP_PullUp_En();
	DISPKEY_UP_PIO->PIO_IFER |= DISPKEY_UP_MASK;
	//DISPKEY_UP_PIO->PIO_SCDR =1000;
	DISPKEY_UP_PIO->PIO_IFSCER |= DISPKEY_UP_MASK;
	
	pio_handler_set(DISPKEY_UP_PIO, DISPKEY_UP_ID, DISPKEY_UP_MASK, PIO_IT_FALL_EDGE, DispUpkey_INT_handler);
    pio_enable_interrupt(DISPKEY_UP_PIO, DISPKEY_UP_MASK);
	
    //NVIC_DisableIRQ(DISPKEY_UP_IRQn);
    //NVIC_ClearPendingIRQ(DISPKEY_UP_IRQn);
    //NVIC_SetPriority(DISPKEY_UP_IRQn, 1);
    //NVIC_EnableIRQ(DISPKEY_UP_IRQn);

}

/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
}
#endif
/**INDENT-ON**/
/// @endcond