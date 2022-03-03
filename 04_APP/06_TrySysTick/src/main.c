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
#include "..\..\..\02_MCAL\STM32F103C\07_STK\STK_interface.h"
void Pattern_1(void) ;
void Pattern_2(void) ;
void Pattern_3(void) ;
u8 led ;
void main(void)
{
	/* initialize clk for system */
	RCC_voidInitSystemClk(RCC_PLL_OFF_HSI_OFF_HSE_ON_BYPASS_OFF,RCC_SYSTCLK_HSE,RCC_PLL_NOT_USED ,PLL_IN_X_1) ;
	/* initialize gpioa clk */
	RCC_voidSetPeripheralClkState(RCC_APB2_IOPA,RCC_PERIPHERAL_ENABLE) ;
	/* initialize used pins */
	GPIO_voidInitByte(GPIO_PORTA,GPIO_LOW_BYTE,PIN_NM_OUTPUT_2MHZ,GPIO_PIN_LOW);
	STK_voidInit(STK_ENABLED,STK_CLKSRC_AHB_BY_8,STK_INT_ENABLE	) ;
	while(1)
	{
     STK_voidSetIntervalSingle(1000,Pattern_3) ;
     // Pattern_1() ;
     // Pattern_2() ;
	 // Pattern_3() ;
	}
}
void Pattern_1(void)
{
	  GPIO_voidSetByteState(GPIO_PORTA,GPIO_LOW_BYTE,0X00) ;
	for(int i = 1 ;i<=4;i++)
	{
		for(int j = 0;j<8;j++)
		{
			GPIO_voidSetByteState(GPIO_PORTA,GPIO_LOW_BYTE,0X00) ;
			GPIO_voidSetPinState(GPIO_PORTA,j,GPIO_PIN_HIGH) ;
			Delay_ms(200) ;
		}
		for(int j = 7;j>=0;j--)
		{
			GPIO_voidSetByteState(GPIO_PORTA,GPIO_LOW_BYTE,0X00) ;
			GPIO_voidSetPinState(GPIO_PORTA,j,GPIO_PIN_HIGH) ;
			Delay_ms(200) ;
		}
	}
}
void Pattern_2(void)
{
	  GPIO_voidSetByteState(GPIO_PORTA,GPIO_LOW_BYTE,0X00) ;
	for(int i = 1 ;i<=4;i++)
	{
		for(int j = 3 , k = 4 ;j>=0;j--,k++)
		{
			GPIO_voidSetPinState(GPIO_PORTA,j,GPIO_PIN_HIGH) ;
			GPIO_voidSetPinState(GPIO_PORTA,k,GPIO_PIN_HIGH) ;
			Delay_ms(200) ;
		}
		for(int j = 0 , k = 7 ;j<=3;j++,k--)
		{
			GPIO_voidSetPinState(GPIO_PORTA,j,GPIO_PIN_LOW) ;
			GPIO_voidSetPinState(GPIO_PORTA,k,GPIO_PIN_LOW) ;
			Delay_ms(200) ;
		}
	}
}
void Pattern_3(void)
{
	  GPIO_voidSetByteState(GPIO_PORTA,GPIO_LOW_BYTE,0X00) ;
	for(int i = 1 ;i<=10;i++)
	{
		GPIO_voidSetByteState(GPIO_PORTA,GPIO_LOW_BYTE,0X00) ;
		for(int k = 0 ;k<=1000;k++)
		{
			for(int l = 0 ;l<=100;l++)
			{

			}
		}
		GPIO_voidSetByteState(GPIO_PORTA,GPIO_LOW_BYTE,0xff) ;
		for(int k = 0 ;k<=1000;k++)
		{
			for(int l = 0 ;l<=100;l++)
			{

			}
		}
	}
	 GPIO_voidSetByteState(GPIO_PORTA,GPIO_LOW_BYTE,0X00) ;
}

