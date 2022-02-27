/*
 * main.c
 *
 *  Created on: Feb 27, 2022
 *      Author: Abdelrahman Hepish
 */
#include "..\..\..\01_LIB\01_STD_TYPES\STD_TYPES.h"
#include "..\..\..\01_LIB\02_BIT_MATH\BIT_MATH.h"
#include "..\..\..\02_MCAL\STM32F103C\01_RCC\RCC_interface.h"
#include "..\..\..\02_MCAL\STM32F103C\02_GPIO\GPIO_interface.h"
#include "..\..\..\03_HAL\01_SSD\SSD_interface.h"

void main(void)
{
	tGPIO_PinState inc = GPIO_PIN_HIGH , dec = GPIO_PIN_HIGH ;
	RCC_voidInitSystemClk(RCC_PLL_OFF_HSI_ON_HSE_OFF_BYPASS_OFF,RCC_SYSTCLK_HSI,RCC_PLL_NOT_USED,PLL_IN_X_1) ;
	RCC_voidSetPeripheralClkState(RCC_APB2_IOPA,RCC_PERIPHERAL_ENABLE) ;
	RCC_voidSetPeripheralClkState(RCC_APB2_IOPB,RCC_PERIPHERAL_ENABLE) ;
	RCC_voidSetPeripheralClkState(RCC_APB2_IOPC,RCC_PERIPHERAL_ENABLE) ;
	RCC_voidSetPeripheralClkState(RCC_APB2_IOPD,RCC_PERIPHERAL_ENABLE) ;
    SSD_Init(SSD_1,SSD_ON,SSD_NUMBER_0) ;
    GPIO_voidInitPin(GPIO_PORTB,GPIO_PIN_0,PIN_PU_INPUT,GPIO_PIN_HIGH) ;
    GPIO_voidInitPin(GPIO_PORTB,GPIO_PIN_1,PIN_PU_INPUT,GPIO_PIN_HIGH) ;
	while(1)
	{
		inc = GPIO_u8GetPinState(GPIO_PORTB,GPIO_PIN_0) ;
		dec = GPIO_u8GetPinState(GPIO_PORTB,GPIO_PIN_1) ;
        if(inc == GPIO_PIN_LOW)
        {
        	SSD_SetSymbol(SSD_1,(SSD_GetSymbol(SSD_1)+1)%11) ;
        }
        if(dec == GPIO_PIN_LOW)
        {
        	SSD_SetSymbol(SSD_1,(SSD_GetSymbol(SSD_1)-1)%11) ;
        }
        SSD_Update() ;
	}
}
