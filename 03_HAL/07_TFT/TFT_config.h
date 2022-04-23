/*************************************************************************/
/* Author        : Abdelrahman Hepish                                    */
/* File          : TFT_config.h                                          */
/* Date          : 19 APRIL 2022                                         */
/* Version       : V01                                                   */
/* GitHub        : https://github.com/Abdelrahman-Hepish                 */
/*************************************************************************/
#ifndef __TFT_CONFIG_H__
#define __TFT_CONFIG_H__
 // In system Init 
//
//	  /* initialize clk for system */
//	  RCC_voidInitSystemClk(RCC_PLL_OFF_HSI_OFF_HSE_ON_BYPASS_OFF,RCC_SYSTCLK_HSE,RCC_PLL_NOT_USED ,PLL_IN_X_1) ;
//	  /* initialize gpioa clk */
//	  RCC_voidSetPeripheralClkState(RCC_APB2_IOPA,RCC_PERIPHERAL_ENABLE) ;
//	  RCC_voidSetPeripheralClkState(RCC_APB2_SPI1,RCC_PERIPHERAL_ENABLE) ;
//	  GPIO_voidInitPin(TFT_A0_PIN,PIN_NM_OUTPUT_50MHZ,GPIO_PIN_LOW) ;
//	  GPIO_voidInitPin(TFT_RST_PIN,PIN_NM_OUTPUT_50MHZ,GPIO_PIN_LOW) ;
//	  GPIO_voidInitPin(GPIO_PORTA,GPIO_PIN_5,PINT_AF_NM_OUTPUT_10MHZ,GPIO_PIN_LOW) ;
//	  GPIO_voidInitPin(GPIO_PORTA,GPIO_PIN_7,PINT_AF_NM_OUTPUT_10MHZ,GPIO_PIN_LOW) ;
//	  SPI_voidInit() ;
//	  STK_voidInit(STK_ENABLED,STK_CLKSRC_AHB_BY_8,STK_INT_DISABLE) ;
//	  TFT_voidInit() ;
//




// WRITE PIN PAIR           PORT,PIN  ->  GPIO_PORTx , GPIO_PIN_x
#define TFT_A0_PIN         GPIO_PORTA,GPIO_PIN_2
#define TFT_RST_PIN        GPIO_PORTA,GPIO_PIN_1

#define TFT_MAX_X_SIZE     0X007F
#define TFT_MAX_Y_SIZE     0X009F
#define TFT_NUM_PIXELS     20480
#endif  __TFT_CONFIG_H__
