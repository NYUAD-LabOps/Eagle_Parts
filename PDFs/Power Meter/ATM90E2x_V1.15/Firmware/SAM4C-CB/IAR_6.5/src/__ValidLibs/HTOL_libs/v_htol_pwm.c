/*-----------------------------------------------------------------------------
 *           ATMEL Microcontroller Software Support  -  ROUSSET  -
 *-----------------------------------------------------------------------------
 * DISCLAIMER:  THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *----------------------------------------------------------------------------
 * File Name           : v_htol_pwm.c
 *----------------------------------------------------------------------------
*/

#include "v_htol_pwm.h"


// global variables
//extern uint32_t htol_iter;    // v_htol_main_functions.c definition
//extern unsigned int MCK_Freq; // v_htol_main_functions.c definition
extern volatile uint32_t periph_read_reg; // v_htol_main_functions.c definition
//extern volatile unsigned int it_flag[2]; // v_htol_it_routines.c definition


/*----------------------------------------------------------------------------*/
//* Function Name : run_pwm_htol
//* Object       : run PWM test for HTOL
//*               
//*
//* Parameters: pwm          = tested peripheral base address
//*             test_mode    = tested peripheral config (Parity mode)
//*             test_nb_iter = number of bytes to copy /or INFINITE_LOOP
//*---------------------------------------------------------------------------*/
extern void run_pwm_htol(Pwm *pwm, uint32_t test_mode)
{
 uint8_t  mode;

 
  Valid_DebugTrace( "* HTOL PWM TEST *\n\r");

  // ----- Disable PWM write protect
  pwm->PWM_WPCR = PWM_KEY_VAL | PWM_ALL_REG_GROUPS;

  // ----- PWM disable all channels & interrupts
  pwm->PWM_IDR1 = 0xFFFFFFFF;
  pwm->PWM_IDR2 = 0xFFFFFFFF;

  // ----- PWM init
  mode = init_pwm_htol(pwm,test_mode);

  // ----- PWM test
  switch (mode){
                case 0: // not functional (reg access)
                  pwm_reg_access(pwm);
                  break;
                case 1:
                  break;
  default: break;}

  // ----- Enable PWM write protect
  pwm->PWM_WPCR = PWM_KEY_VAL | PWM_ALL_REG_GROUPS | PWM_WPCR_WPCMD(1);
  pwm->PWM_WPCR = PWM_KEY_VAL | PWM_ALL_REG_GROUPS | PWM_WPCR_WPCMD(2);
  pwm->PWM_CLK  = ~(pwm->PWM_CLK); // triggers WPVS flag;

  return;
}



/*----------------------------------------------------------------------------*/
//* Function Name : init_pwm_htol
//* Object       : run PWM test for HTOL
//*---------------------------------------------------------------------------*/
uint32_t init_pwm_htol(Pwm *pwm, uint32_t test_mode)
{
 uint32_t pwm_next_mode;
 uint8_t  mode;
 
  mode = test_mode % HTOL_PWM_NB_TEST_MODE;
  switch (mode){
                case 0: // not functional (reg access)
                  pwm_next_mode = PWM_MODE0;
                  break;
                case 1:
                  //pwm_next_mode = PWM_MODE1;
                  // pseudo random config update
                  //reg32_update_fields(&pwm_next_mode,PWM_CONFIG_FIELDS);
                  break;
  default: break;}
  
  // Program modes
  pwm->PWM_SCM = pwm_next_mode;

  // enable ALL PWM interrupt (core level)
  nvic_pwm_it_enable();
  
  // pseudo random config update
  reg32_update_fields(&pwm_next_mode,PWM_CONFIG_FIELDS);
  
  // PWM interrupt enable
  pwm->PWM_IER1 = PWM_IT_SOURCES_EN1;
  pwm->PWM_IER2 = PWM_IT_SOURCES_EN2;

  return(mode);
}


/*----------------------------------------------------------------------------*/
//* Function Name : pwm_reg_access
//* Object        : read/write peripheral register access
//*---------------------------------------------------------------------------*/
void pwm_reg_access(Pwm *pwm)
{
 uint32_t i;
  
  pwm->PWM_CLK     = ~(pwm->PWM_CLK);
  pwm->PWM_ENA     = ~(pwm->PWM_ENA);
  pwm->PWM_DIS     = ~(pwm->PWM_DIS);
  periph_read_reg  = ~(pwm->PWM_SR);   //RO
  pwm->PWM_IER1    = ~(pwm->PWM_IER1);
  pwm->PWM_IDR1    = ~(pwm->PWM_IDR1);
  periph_read_reg  = ~(pwm->PWM_IMR1); //RO
  periph_read_reg  = ~(pwm->PWM_ISR1); //RO
  pwm->PWM_SCM     = ~(pwm->PWM_SCM);
  pwm->PWM_SCUC    = ~(pwm->PWM_SCUC);
  pwm->PWM_SCUP    = ~(pwm->PWM_SCUP);  
  pwm->PWM_SCUPUPD = ~(pwm->PWM_SCUPUPD);  
  pwm->PWM_IER2    = ~(pwm->PWM_IER2);
  pwm->PWM_IDR2    = ~(pwm->PWM_IDR2);
  periph_read_reg  = ~(pwm->PWM_IMR2); //RO
  periph_read_reg  = ~(pwm->PWM_ISR2); //RO
  pwm->PWM_OOV     = ~(pwm->PWM_OOV);
  pwm->PWM_OS      = ~(pwm->PWM_OS);
  pwm->PWM_OSS     = ~(pwm->PWM_OSS);  
  pwm->PWM_OSC     = ~(pwm->PWM_OSC);  
  pwm->PWM_OSSUPD  = ~(pwm->PWM_OSSUPD);
  pwm->PWM_OSCUPD  = ~(pwm->PWM_OSCUPD);
  pwm->PWM_FMR     = ~(pwm->PWM_FMR);
  periph_read_reg  = ~(pwm->PWM_FSR);  //RO
  pwm->PWM_FCR     = ~(pwm->PWM_FCR);
  pwm->PWM_FPV     = ~(pwm->PWM_FPV);
  pwm->PWM_FPE     = ~(pwm->PWM_FPE);
  pwm->PWM_ELMR[0] = ~(pwm->PWM_ELMR[0]);
  pwm->PWM_ELMR[1] = ~(pwm->PWM_ELMR[1]);
  pwm->PWM_SMMR    = ~(pwm->PWM_SMMR);
  pwm->PWM_WPCR    = ~(pwm->PWM_WPCR); // no effect (no key)
  periph_read_reg  = ~(pwm->PWM_WPSR); //RO
  for (i=0;i<PWMCMP_NUMBER;++i){pwm->PWM_CMP[i].PWM_CMPV = ~(pwm->PWM_CMP[i].PWM_CMPV);}
  for (i=0;i<PWMCMP_NUMBER;++i){pwm->PWM_CMP[i].PWM_CMPVUPD = ~(pwm->PWM_CMP[i].PWM_CMPVUPD);}
  for (i=0;i<PWMCMP_NUMBER;++i){pwm->PWM_CMP[i].PWM_CMPM = ~(pwm->PWM_CMP[i].PWM_CMPM);}
  for (i=0;i<PWMCMP_NUMBER;++i){pwm->PWM_CMP[i].PWM_CMPMUPD = ~(pwm->PWM_CMP[i].PWM_CMPMUPD);}
  for (i=0;i<PWMCH_NUM_NUMBER;++i){pwm->PWM_CH_NUM[i].PWM_CMR = ~(pwm->PWM_CH_NUM[i].PWM_CMR);}
  for (i=0;i<PWMCH_NUM_NUMBER;++i){pwm->PWM_CH_NUM[i].PWM_CDTY = ~(pwm->PWM_CH_NUM[i].PWM_CDTY);}
  for (i=0;i<PWMCH_NUM_NUMBER;++i){pwm->PWM_CH_NUM[i].PWM_CDTYUPD = ~(pwm->PWM_CH_NUM[i].PWM_CDTYUPD);}
  for (i=0;i<PWMCH_NUM_NUMBER;++i){pwm->PWM_CH_NUM[i].PWM_CPRD = ~(pwm->PWM_CH_NUM[i].PWM_CPRD);}
  for (i=0;i<PWMCH_NUM_NUMBER;++i){pwm->PWM_CH_NUM[i].PWM_CPRDUPD = ~(pwm->PWM_CH_NUM[i].PWM_CPRDUPD);}
  for (i=0;i<PWMCH_NUM_NUMBER;++i){pwm->PWM_CH_NUM[i].PWM_CCNT = ~(pwm->PWM_CH_NUM[i].PWM_CCNT);}
  for (i=0;i<PWMCH_NUM_NUMBER;++i){pwm->PWM_CH_NUM[i].PWM_DT = ~(pwm->PWM_CH_NUM[i].PWM_DT);}
  for (i=0;i<PWMCH_NUM_NUMBER;++i){pwm->PWM_CH_NUM[i].PWM_DTUPD = ~(pwm->PWM_CH_NUM[i].PWM_DTUPD);}
}



/*----------------------------------------------------------------------------*/
//* Function Name : nvic_pwm_it_enable
//* Object        : enable ALL PWM interrupt (core level)
//*---------------------------------------------------------------------------*/
void nvic_pwm_it_enable()
{
#ifdef ID_PWM
  nvic_enable_it(ID_PWM);
#endif
}


