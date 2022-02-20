
#include "..\..\..\01_LIB\01_STD_TYPES\STD_TYPES.h"
#include "..\..\..\01_LIB\02_BIT_MATH\BIT_MATH.h"
#include "..\..\..\02_MCAL\STM32F103C\01_RCC\RCC_interface.h"
#include "..\..\..\02_MCAL\STM32F103C\02_GPIO\GPIO_interface.h"

void main(void)
{
    volatile u8 ticks = 0 , state = 1  ;
	RCC_voidInitSystemClk(RCC_PLL_OFF_HSI_OFF_HSE_ON_BYPASS_OFF,RCC_SYSTCLK_HSE,RCC_PLL_NOT_USED ,PLL_IN_X_1) ;
    RCC_voidSetPeripheralClkState(RCC_APB2_IOPA,RCC_PERIPHERAL_ENABLE) ;
    RCC_voidSetPeripheralClkState(RCC_APB2_IOPB,RCC_PERIPHERAL_ENABLE) ;
    /* gpio pin 0 is in pull up mode now so you have to connect switch as follows : GND -> Switch -> Pin 0 Port B. */
    GPIO_voidInitPin(GPIO_PORTB,GPIO_PIN_0,PIN_PU_INPUT,GPIO_PIN_HIGH) ;
    GPIO_voidInitByte(GPIO_PORTA,GPIO_LOW_BYTE,PIN_NM_OUTPUT_2MHZ,0X00) ;
	while(1)
	{
		state = GPIO_u8GetPinState(GPIO_PORTB,GPIO_PIN_0) ;
		if(state == GPIO_PIN_LOW)
		{
			ticks = (ticks+1)%8 ;
			GPIO_voidSetByteState(GPIO_PORTA,GPIO_LOW_BYTE,0X00) ;
			GPIO_voidSetPinState(GPIO_PORTA,ticks,GPIO_PIN_HIGH) ;
			for(int i = 0 ;i <=100000;i++)
			{

			}
		}

	}
}
