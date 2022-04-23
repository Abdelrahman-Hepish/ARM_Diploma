/*
 * main.c
 *
 *  Created on: March 24, 2022
 *      Author: Abdelrahman Hepish
 */
#include "..\..\..\01_LIB\01_STD_TYPES\STD_TYPES.h"
#include "..\..\..\01_LIB\02_BIT_MATH\BIT_MATH.h"
#include "..\..\..\02_MCAL\STM32F103C\01_RCC\RCC_interface.h"
#include "..\..\..\02_MCAL\STM32F103C\02_GPIO\GPIO_interface.h"
#include "..\..\..\02_MCAL\STM32F103C\10_USART\USART_interface.h"

void main(void)
{
	/* Set System Clk */
	RCC_voidInitSystemClk(RCC_PLL_OFF_HSI_OFF_HSE_ON_BYPASS_OFF, RCC_SYSTCLK_HSE ,RCC_PLL_NOT_USED,PLL_IN_X_1) ;
	/* Enable RCC for GPIO A , B */
	RCC_voidSetPeripheralClkState(RCC_APB2_USART1,RCC_PERIPHERAL_ENABLE) ;
	USART1_init() ;
	RCC_voidSetPeripheralClkState(RCC_APB2_IOPA,RCC_PERIPHERAL_ENABLE) ;
	RCC_voidSetPeripheralClkState(RCC_APB2_IOPB,RCC_PERIPHERAL_ENABLE) ;
	GPIO_voidInitPin(GPIO_PORTA,GPIO_PIN_9,PINT_AF_NM_OUTPUT_2MHZ,GPIO_PIN_LOW) ;
	GPIO_voidInitPin(GPIO_PORTA,GPIO_PIN_10,PIN_FL_INPUT,GPIO_PIN_LOW) ;
	GPIO_voidInitPin(GPIO_PORTA,GPIO_PIN_8,PIN_NM_OUTPUT_2MHZ,GPIO_PIN_LOW) ;
	u8 Ch = "Hello" , x  ;
	while(1)
	{
		USART1_Transmit("\nHello\t \n") ;
		x = USART1_Receive() ;
		if(x == 'O')
		{
			GPIO_voidSetPinState(GPIO_PORTA,GPIO_PIN_8,GPIO_PIN_HIGH) ;
		}else if (x == 'C')
		{
			GPIO_voidSetPinState(GPIO_PORTA,GPIO_PIN_8,GPIO_PIN_LOW) ;
		}
	}
}

