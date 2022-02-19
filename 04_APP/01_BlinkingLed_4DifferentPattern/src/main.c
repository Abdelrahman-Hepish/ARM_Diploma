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
void Pattern_1(void) ;
void Pattern_2(void) ;
void Pattern_3(void) ;
void Pattern_4(void) ;
void NotAccurateDelay(u32 delay) ;
u8 led ;

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
		Pattern_1() ;
		Pattern_2() ;
		Pattern_3() ;
		Pattern_4() ;
	}
}
void NotAccurateDelay(u32 delay)
{
	int i = 0 , j  ;
	for(i = 0 ;i<=1000;i++)
	{
		for(j = 0 ;j<=delay;j++)
		{

		}
	}
}
void Pattern_1(void)
{
	for(int i = 1 ;i<=4;i++)
	{
		for(int j = 0;j<8;j++)
		{
			GPIO_voidSetByteState(GPIO_PORTA,GPIO_LOW_BYTE,0X00) ;
			GPIO_voidSetPinState(GPIO_PORTA,j,GPIO_PIN_HIGH) ;
			NotAccurateDelay(200) ;
		}
		for(int j = 7;j>=0;j--)
		{
			GPIO_voidSetByteState(GPIO_PORTA,GPIO_LOW_BYTE,0X00) ;
			GPIO_voidSetPinState(GPIO_PORTA,j,GPIO_PIN_HIGH) ;
			NotAccurateDelay(200) ;
		}
	}
}
void Pattern_2(void)
{
	for(int i = 1 ;i<=4;i++)
	{
		for(int j = 3 , k = 4 ;j>=0;j--,k++)
		{
			GPIO_voidSetPinState(GPIO_PORTA,j,GPIO_PIN_HIGH) ;
			GPIO_voidSetPinState(GPIO_PORTA,k,GPIO_PIN_HIGH) ;
			NotAccurateDelay(200) ;
		}
		for(int j = 0 , k = 7 ;j<=3;j++,k--)
		{
			GPIO_voidSetPinState(GPIO_PORTA,j,GPIO_PIN_LOW) ;
			GPIO_voidSetPinState(GPIO_PORTA,k,GPIO_PIN_LOW) ;
			NotAccurateDelay(200) ;
		}
	}
}
void Pattern_3(void)
{
	for(int i = 1 ;i<=8;i++)
	{
		GPIO_voidSetByteState(GPIO_PORTA,GPIO_LOW_BYTE,0X00) ;
		NotAccurateDelay(500) ;
		GPIO_voidSetByteState(GPIO_PORTA,GPIO_LOW_BYTE,0xff) ;
		NotAccurateDelay(500) ;
	}
}
void Pattern_4(void)
{
	GPIO_voidSetPinState(GPIO_PORTA,led,!GPIO_u8GetPinState(GPIO_PORTA,led)) ;
}
