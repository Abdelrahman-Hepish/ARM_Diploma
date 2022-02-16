/*
 * main.c
 *
 *  Created on: Dec 12, 2021
 *      Author: Abdelrahman Hepish
 */
#include "..\..\..\01_LIB\01_STD_TYPES\STD_TYPES.h"
#include "..\..\..\01_LIB\02_BIT_MATH\BIT_MATH.h"
#include "..\..\..\02_MCAL\STM32F103C\01_RCC\RCC_interface.h"
#include "..\..\..\02_MCAL\STM32F103C\02_GPIO\GPIO_interface.h"

void _7net4yma(void) ;

void main(void)
{
	  /* initialize clk for system */
	  RCC_voidInitSystemClk(RCC_PLL_OFF_HSI_OFF_HSE_ON_BYPASS_OFF,RCC_SYSTCLK_HSE,RCC_PLL_NOT_USED ,PLL_IN_X_1) ;
	  /* initialize gpioa clk */
	  RCC_voidSetPeripheralClkState(RCC_APB2_IOPA,RCC_PERIPHERAL_ENABLE) ;
	  /* initialize used pins */
	  GPIO_voidInitByte(GPIO_PORTA,GPIO_LOW_BYTE,PIN_NM_OUTPUT_2MHZ,GPIO_PIN_LOW);

	while(1)
	{
		_7net4yma() ;
	}
}
void _7net4yma(void)
{
	int i , j , k  ;
	for(i=0;i<=7;i++)
	{
		GPIO_voidSetByteState(GPIO_PORTA,GPIO_LOW_BYTE,0) ;
		for(j=0;j<=1000;j++)
		{
			for(k=0;k<=1000;k++)
			{

			}
		}
		GPIO_voidSetPinState(GPIO_PORTA,i,GPIO_PIN_HIGH) ;
		for(j=0;j<=1000;j++)
		{
			for(k=0;k<=1000;k++)
			{

			}
		}
	}

}
