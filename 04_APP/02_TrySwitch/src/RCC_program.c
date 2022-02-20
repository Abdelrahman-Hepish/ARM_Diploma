/*************************************************************************/
/* Author        : Abdelrahman Hepish                                    */
/* File          : RCC_program.c                                         */
/* Date          :                                                       */
/* Version       : V01                                                   */
/* GitHub        : https://github.com/Abdelrahman-Hepish                 */
/*************************************************************************/
#include "..\..\..\01_LIB\01_STD_TYPES\STD_TYPES.h"
#include "..\..\..\01_LIB\02_BIT_MATH\BIT_MATH.h"
#include "..\..\..\02_MCAL\STM32F103C\01_RCC\RCC_interface.h"
#include "..\..\..\02_MCAL\STM32F103C\01_RCC\RCC_config.h"
#include "..\..\..\02_MCAL\STM32F103C\01_RCC\RCC_private.h"
void RCC_voidInitSystemClk(tRCC_ClksState Copy_u8ClkStates , tRCC_SystemClk Copy_u8SystemClk ,tRCC_PllInput Copy_u8PllIn ,tRCC_PllMulFactor Copy_u8Pllmulfactor)
{
	RCC_voidSetClksState(Copy_u8ClkStates) ; 
	RCC_voidSetPllInput(Copy_u8PllIn) ; 
	RCC_voidSetPllMulFactor(Copy_u8Pllmulfactor) ; 
	RCC_voidSetSystemClk(Copy_u8SystemClk) ; 
}

void RCC_voidSetPeripheralClkState(tRCC_Peripheral Copy_u8PeripheralID,tRCC_PeripheralClkState Copy_u8PeripheralClkState)
{
	if(Copy_u8PeripheralID < APB2_OFFSET )
	{
		MAN_BIT(RCC_AHBENR,Copy_u8PeripheralID,Copy_u8PeripheralClkState) ; 
	}else if (Copy_u8PeripheralID < APB1_OFFSET)
	{
		Copy_u8PeripheralID -= APB2_OFFSET ; 
		MAN_BIT(RCC_APB2ENR,Copy_u8PeripheralID,Copy_u8PeripheralClkState) ; 
	}else
	{
		Copy_u8PeripheralID -= APB1_OFFSET ; 
		MAN_BIT(RCC_APB1ENR,Copy_u8PeripheralID,Copy_u8PeripheralClkState) ;
	}
}	
void RCC_voidSetClksState(tRCC_ClksState Copy_u8ClkStates) 
{	
	MAN_BIT(RCC_CR,RCC_CR_PLLON_PIN ,GET_BIT(Copy_u8ClkStates,PLLON_BIT_ID)) ;
    if(	GET_BIT(Copy_u8ClkStates,PLLON_BIT_ID) == HIGH) while(GET_BIT(RCC_CR,RCC_CR_PLL_RDY_PIN) != HIGH) ;
	MAN_BIT(RCC_CR,RCC_CR_HSION_PIN ,GET_BIT(Copy_u8ClkStates,HSION_BIT_ID)) ;
	if(	GET_BIT(Copy_u8ClkStates,HSION_BIT_ID) == HIGH) while(GET_BIT(RCC_CR,RCC_CR_HSIRDY_PIN) != HIGH) ;
	MAN_BIT(RCC_CR,RCC_CR_HSEON_PIN ,GET_BIT(Copy_u8ClkStates,HSEON_BIT_ID)) ;
	if(	GET_BIT(Copy_u8ClkStates,HSEON_BIT_ID) == HIGH) while(GET_BIT(RCC_CR,RCC_CR_HSERDY_PIN) != HIGH) ;
	MAN_BIT(RCC_CR,RCC_CR_HSEBPY_PIN,GET_BIT(Copy_u8ClkStates,HSEBPY_BIT_ID)) ;
}
void RCC_voidSetClkSecurityState(tRCC_ClkSecurityState Copy_u8ClkSecurityStates) 
{
	MAN_BIT(RCC_CR,RCC_CR_CSS_ON_PIN ,Copy_u8ClkSecurityStates) ;
}
void RCC_voidTrimInternalHighSpeedClk(s16 Copy_s32Offset)
{
	u8 val = Copy_s32Offset / TRIM_STEP ; 
	u8 currentHSI_Trim = GET_BYTE(RCC_CR,RCC_CR_HSITRIM_START_PIN) ; 
	/* out of scoope */ 
	CLR_BIT(currentHSI_Trim,5) ;
	CLR_BIT(currentHSI_Trim,6) ;
	CLR_BIT(currentHSI_Trim,7) ;
	currentHSI_Trim += val ; 
	MAN_NIBBLE(RCC_CR,RCC_CR_HSITRIM_START_PIN,currentHSI_Trim) ; 
	MAN_BIT(RCC_CR,RCC_CR_HSITRIM_START_PIN + 4,GET_BIT(currentHSI_Trim,4)) ;
}
void RCC_voidSetMCuClkOutput(tRCC_MCuClkOutput Copy_u8MCO)
{
	MAN_NIBBLE(RCC_CFGR,RCC_CFGR_MCO_START_PIN ,Copy_u8MCO) ;
}
void RCC_voidSetPllInput(tRCC_PllInput Copy_u8PllIn)  
{
	if(Copy_u8PllIn != RCC_PLL_NOT_USED )
	{
      MAN_BIT(RCC_CFGR,RCC_CFGR_PLLSRC_PIN ,GET_BIT(Copy_u8PllIn,PLLSRC_BIT_ID)) ;
      MAN_BIT(RCC_CFGR,RCC_CFGR_PLLXTPRE_PIN ,GET_BIT(Copy_u8PllIn,PLLXTPRE_BIT_ID)) ;
	}
}
void RCC_voidSetSystemClk(tRCC_SystemClk Copy_u8SystemClk) 
{
    MAN_BIT(RCC_CFGR,RCC_CFGR_SW_PIN_0 ,GET_BIT(Copy_u8SystemClk,SW_BIT_0_ID)) ;	
    MAN_BIT(RCC_CFGR,RCC_CFGR_SW_PIN_1 ,GET_BIT(Copy_u8SystemClk,SW_BIT_1_ID)) ;	
}

tRCC_SystemClk RCC_tRCC_SystemClkGetSystClk(void)
{
	tRCC_SystemClk ret ; 
	MAN_BIT(ret,SW_BIT_0_ID ,GET_BIT(RCC_CFGR,RCC_CFGR_SWS_PIN_0)) ;	
    MAN_BIT(ret,SW_BIT_1_ID ,GET_BIT(RCC_CFGR,RCC_CFGR_SWS_PIN_1)) ;
    return ret ; 
}	
void RCC_voidSetPllMulFactor(tRCC_PllMulFactor Copy_u8Pllmulfactor) 
{
	if(Copy_u8Pllmulfactor != PLL_IN_X_1 )
	{
      u8 current_pll_state = GET_BIT(RCC_CR,RCC_CR_PLLON_PIN) ; 
      CLR_BIT(RCC_CR,RCC_CR_PLLON_PIN) ; 
      MAN_NIBBLE(RCC_CFGR,RCC_CFGR_PLLMULL_START_PIN,Copy_u8Pllmulfactor) ;
      MAN_BIT(RCC_CR,RCC_CR_PLLON_PIN ,current_pll_state) ;
	}
}

void RCC_voidSetBusClks(tRCC_AHBPrescaler Copy_u8AHBPresc,tRCC_APB1Prescaler Copy_u8APB1Presc,tRCC_APB2Prescaler Copy_u8APB2Presc)
{
	MAN_NIBBLE(RCC_CFGR,RCC_CFGR_HPRE_START_PIN,Copy_u8AHBPresc) ; 
	MAN_BIT(RCC_CFGR,RCC_CFGR_PPRE1_START_PIN+PRE1_BIT_0_ID,GET_BIT(Copy_u8APB1Presc,PRE1_BIT_0_ID)) ;
	MAN_BIT(RCC_CFGR,RCC_CFGR_PPRE1_START_PIN+PRE1_BIT_1_ID,GET_BIT(Copy_u8APB1Presc,PRE1_BIT_1_ID)) ;
	MAN_BIT(RCC_CFGR,RCC_CFGR_PPRE1_START_PIN+PRE1_BIT_2_ID,GET_BIT(Copy_u8APB1Presc,PRE1_BIT_2_ID)) ;
	MAN_BIT(RCC_CFGR,RCC_CFGR_PPRE2_START_PIN+PRE2_BIT_0_ID,GET_BIT(Copy_u8APB2Presc,PRE2_BIT_0_ID)) ;
	MAN_BIT(RCC_CFGR,RCC_CFGR_PPRE2_START_PIN+PRE2_BIT_1_ID,GET_BIT(Copy_u8APB2Presc,PRE2_BIT_1_ID)) ;
	MAN_BIT(RCC_CFGR,RCC_CFGR_PPRE2_START_PIN+PRE2_BIT_2_ID,GET_BIT(Copy_u8APB2Presc,PRE2_BIT_2_ID)) ;
}
