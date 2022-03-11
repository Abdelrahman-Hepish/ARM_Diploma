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
#include "..\..\..\02_MCAL\STM32F103C\05_EXTI\EXTI_interface.h"
#include "..\..\..\02_MCAL\STM32F103C\06_AFIO\AFIO_interface.h"
#include "..\..\..\02_MCAL\STM32F103C\07_STK\STK_interface.h"
#include "..\..\..\03_HAL\03_IR\IR_interface.h"
#include "..\..\..\03_HAL\04_RGB\RGB_interface.h"
void main(void)
{
	volatile u8  irData, rgbMode ;
	/* Set System Clk */
	RCC_voidInitSystemClk(RCC_PLL_OFF_HSI_OFF_HSE_ON_BYPASS_OFF, RCC_SYSTCLK_HSE ,RCC_PLL_NOT_USED,PLL_IN_X_1) ;
	/* Enable RCC for GPIO A , B */
	RCC_voidSetPeripheralClkState(RCC_APB2_IOPA,RCC_PERIPHERAL_ENABLE) ;
	RCC_voidSetPeripheralClkState(RCC_APB2_IOPB,RCC_PERIPHERAL_ENABLE) ;
	/* Init Pins of PortB as input , PortA as Output */
	RGB_voidInit(OFF) ;
	IR_voidInit(GPIO_PORTA,GPIO_PIN_0) ;
	STK_voidInit(STK_ENABLED,STK_CLKSRC_AHB_BY_8,STK_INT_ENABLE) ;
	while(1)
	{
		irData = IR_u8GetData() ;
		if(irData == IR_POWER_BUTTON)
		{
	     	RGB_SetMode(OFF) ;
		}
		else if (irData == IR_1_BUTTON)
		{
			RGB_SetMode(RED) ;
		}
		else if (irData == IR_2_BUTTON)
		{
			RGB_SetMode(GREEN) ;
		}
		else if (irData == IR_3_BUTTON)
		{
			RGB_SetMode(BLUE) ;
		}
		else if (irData == IR_4_BUTTON)
		{
			RGB_SetMode(YELLOW) ;
		}
		else if (irData == IR_5_BUTTON)
		{
			RGB_SetMode(Magenta) ;
		}
		else if (irData == IR_6_BUTTON)
		{
			RGB_SetMode(Cyan) ;
		}
		else if (irData == IR_7_BUTTON)
		{
			RGB_SetMode(BLACK) ;
		}
	}
}

