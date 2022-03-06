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
void Exti_0_func(void) ;
void Exti_1_func(void) ;
void main(void)
{
	/* Set System Clk */
	RCC_voidInitSystemClk(RCC_PLL_OFF_HSI_OFF_HSE_ON_BYPASS_OFF, RCC_SYSTCLK_HSE ,RCC_PLL_NOT_USED,PLL_IN_X_1) ;
	/* Enable RCC for GPIO A , B */
	RCC_voidSetPeripheralClkState(RCC_APB2_IOPA,RCC_PERIPHERAL_ENABLE) ;
	RCC_voidSetPeripheralClkState(RCC_APB2_IOPB,RCC_PERIPHERAL_ENABLE) ;
	/* Init Pins of PortB as input , PortA as Output */
	GPIO_voidInitPin(GPIO_PORTB,GPIO_PIN_0,PIN_PU_INPUT,GPIO_PIN_HIGH) ;
	GPIO_voidInitPin(GPIO_PORTB,GPIO_PIN_1,PIN_PU_INPUT,GPIO_PIN_HIGH) ;
	GPIO_voidInitPin(GPIO_PORTA,GPIO_PIN_8,PIN_NM_OUTPUT_2MHZ,GPIO_PIN_LOW) ;
	GPIO_voidInitPin(GPIO_PORTA,GPIO_PIN_9,PIN_NM_OUTPUT_2MHZ,GPIO_PIN_LOW) ;
	/* Set System Group , SubGroup Format */
	SCB_SetInterruptGroupingSystem(SCB_4_GRP_4_SUB) ;
	/* Enable EXTI_0 & EXTI_1 */
	NVIC_voidEnablePerInterrupt(NVIC_EXTI0) ;
	NVIC_voidEnablePerInterrupt(NVIC_EXTI1) ;
	/* Assign EXTI_0 to group 0 & sub 1
	 * Assign EXTI_1 to group 1 & sub 0
	 */
	NVIC_voidSetInterruptGroup_SubGroup_4G_4S (NVIC_EXTI0,0,1) ;
	NVIC_voidSetInterruptGroup_SubGroup_4G_4S (NVIC_EXTI1,1,0) ;
	/*
	 * Assign Line 0 to Port B
	 * Assign Line 1 to Port B
	 */
	AFIO_voidSetEXTI_Configuration(AFIO_LINE_0 ,AFIO_LINE_PORT_B) ;
	AFIO_voidSetEXTI_Configuration(AFIO_LINE_1 ,AFIO_LINE_PORT_B) ;
	/*
	 *  Assign Call back function
	 */
	EXTI_voidSetLineCallBackFunc(EXTI_LINE_0 , Exti_0_func) ;
	EXTI_voidSetLineCallBackFunc(EXTI_LINE_0 , Exti_1_func) ;
	/*
	 *  Assign Triggering mode for Exti_0 , Exti_1 & Enable poth
	 */
	EXTI_voidInitLine(EXTI_LINE_0 ,EXTI_ON_CHANGE_TRIGGER,EXTI_ENABLE) ;
	EXTI_voidInitLine(EXTI_LINE_1 ,EXTI_ON_CHANGE_TRIGGER,EXTI_ENABLE) ;

	while(1)
	{

	}
}
void Exti_0_func(void)
{
	GPIO_voidSetPinState(GPIO_PORTA,GPIO_PIN_8,GPIO_PIN_HIGH) ;
	GPIO_voidSetPinState(GPIO_PORTA,GPIO_PIN_9,GPIO_PIN_LOW) ;
}
void Exti_1_func(void)
{
	GPIO_voidSetPinState(GPIO_PORTA,GPIO_PIN_8,GPIO_PIN_LOW) ;
	GPIO_voidSetPinState(GPIO_PORTA,GPIO_PIN_9,GPIO_PIN_HIGH) ;
}
