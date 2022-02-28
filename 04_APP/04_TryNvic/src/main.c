/*
 * main.c
 *
 *  Created on: Feb 28, 2022
 *      Author: Abdelrahman Hepish
 */
#include "..\..\..\01_LIB\01_STD_TYPES\STD_TYPES.h"
#include "..\..\..\01_LIB\02_BIT_MATH\BIT_MATH.h"
#include "..\..\..\02_MCAL\STM32F103C\01_RCC\RCC_interface.h"
#include "..\..\..\02_MCAL\STM32F103C\02_GPIO\GPIO_interface.h"
#include "..\..\..\02_MCAL\STM32F103C\03_NVIC\NVIC_interface.h"
#include "..\..\..\02_MCAL\STM32F103C\04_SCB\SCB_interface.h"

void TempDelay(void) ;
void main(void)
{
	RCC_voidInitSystemClk(RCC_PLL_OFF_HSI_ON_HSE_OFF_BYPASS_OFF,RCC_SYSTCLK_HSI,RCC_PLL_NOT_USED,PLL_IN_X_1) ;
	RCC_voidSetPeripheralClkState(RCC_APB2_IOPA,RCC_PERIPHERAL_ENABLE) ;
    SCB_SetInterruptGroupingSystem(SCB_4_GRP_4_SUB)  ;
    NVIC_voidSetInterruptGroup_SubGroup_4G_4S (NVIC_TIM2,3,1) ;
    NVIC_voidSetInterruptGroup_SubGroup_4G_4S (NVIC_UART4,1,0) ;
	GPIO_voidInitPin(GPIO_PORTA,GPIO_PIN_0,PIN_NM_OUTPUT_2MHZ,GPIO_PIN_LOW) ;
	GPIO_voidInitPin(GPIO_PORTA,GPIO_PIN_1,PIN_NM_OUTPUT_2MHZ,GPIO_PIN_LOW) ;
	NVIC_voidEnablePerInterrupt(NVIC_TIM2) ;
	NVIC_voidEnablePerInterrupt(NVIC_UART4) ;
	NVIC_voidSetPendingFlagPerInterrupt(NVIC_UART4) ;
	while(1)
	{

	}
}
void UART4_IRQHandler(void)
{
	GPIO_voidSetPinState(GPIO_PORTA,GPIO_PIN_1,1) ;
	TempDelay() ;
}
void TIM2_IRQHandler(void)
{
	TempDelay() ;
	NVIC_voidSetPendingFlagPerInterrupt(NVIC_UART4) ;
	GPIO_voidSetPinState(GPIO_PORTA,GPIO_PIN_0,1) ;
}
void TempDelay(void)
{
	for(int i = 0 ;i<=1000;i++)
	{
		for(int j = 0 ;j<=150;j++)
		{
			asm("NOP") ;
		}
	}
}
