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
#include "..\..\..\02_MCAL\STM32F103C\09_SPI\SPI_interface.h"
#include "..\..\..\03_HAL\07_TFT\TFT_interface.h"
#include "..\..\..\03_HAL\07_TFT\TFT_config.h"
#include "image.h"
void main(void)
{
	  /* initialize clk for system */
	  RCC_voidInitSystemClk(RCC_PLL_OFF_HSI_OFF_HSE_ON_BYPASS_OFF,RCC_SYSTCLK_HSE,RCC_PLL_NOT_USED ,PLL_IN_X_1) ;
	  /* initialize gpioa clk */
	  RCC_voidSetPeripheralClkState(RCC_APB2_IOPA,RCC_PERIPHERAL_ENABLE) ;
	  RCC_voidSetPeripheralClkState(RCC_APB2_SPI1,RCC_PERIPHERAL_ENABLE) ;
	  GPIO_voidInitPin(TFT_A0_PIN,PIN_NM_OUTPUT_50MHZ,GPIO_PIN_LOW) ;
	  GPIO_voidInitPin(TFT_RST_PIN,PIN_NM_OUTPUT_50MHZ,GPIO_PIN_LOW) ;
	  GPIO_voidInitPin(GPIO_PORTA,GPIO_PIN_5,PINT_AF_NM_OUTPUT_10MHZ,GPIO_PIN_LOW) ;
	  GPIO_voidInitPin(GPIO_PORTA,GPIO_PIN_7,PINT_AF_NM_OUTPUT_10MHZ,GPIO_PIN_LOW) ;
	  SPI_voidInit() ;
	  STK_voidInit(STK_ENABLED,STK_CLKSRC_AHB_BY_8,STK_INT_DISABLE) ;
	  TFT_voidInit() ;
	  TFT_voidFillSquare(0,128 ,0 ,160 , 0xffff) ;
	  TFT_voidFillSquare(34,94 ,50 ,110 , 0x0000) ;
	  TFT_voidDisplayImage(image) ;
      while(1)
      {

      }

}

