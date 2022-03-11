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
#include "..\..\..\03_HAL\02_LEDMRX\LEDMRX_interface.h"
void main(void)
{
	/* initialize clk for system */
	RCC_voidInitSystemClk(RCC_PLL_OFF_HSI_OFF_HSE_ON_BYPASS_OFF,RCC_SYSTCLK_HSE,RCC_PLL_NOT_USED ,PLL_IN_X_1) ;
	/* initialize gpioa clk */
	RCC_voidSetPeripheralClkState(RCC_APB2_IOPA,RCC_PERIPHERAL_ENABLE) ;
	RCC_voidSetPeripheralClkState(RCC_APB2_IOPB,RCC_PERIPHERAL_ENABLE) ;
    LEDMRX_voidInit() ;
    u8 A[8] = {0,0,0,0,0,0,0,0} ;
    char *ptr = "ABCDE" ; u8 index = 0 ;
	while(1)
	{
	for(int i = 0 ;i<=99;i++)
	{
	    LEDMRX_voidDisplayChar(ptr[index]) ;
	}
    LEDMRX_voidDisplay(A) ;
    index = (index + 1) % 5 ;
    Delay_ms(1000) ;
	}
}


