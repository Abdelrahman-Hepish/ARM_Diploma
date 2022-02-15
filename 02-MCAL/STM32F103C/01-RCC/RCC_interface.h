/*************************************************************************/
/* Author        : Abdelrahman Hepish                                    */
/* File          : RCC_interface.h                                       */
/* Date          :                                                       */
/* Version       : V01                                                   */
/* GitHub        : https://github.com/Abdelrahman-Hepish                 */
/*************************************************************************/
#ifndef __RCC_INTERFACE_H__
#define __RCC_INTERFACE_H__
#define AHB_OFFSET   0
#define APB2_OFFSET  32
#define APB1_OFFSET  64
/* 
 tRCC_Peripheral is an Enum (user defined data type) 
 to facilitate dealing with different peripherals and which bus the peripheral located on
*/
typedef enum
{
    RCC_AHB_DMA1      = AHB_OFFSET  + 0   ,
	RCC_AHB_DMA2      = AHB_OFFSET  + 1   ,
	RCC_AHB_SRAM      = AHB_OFFSET  + 2   ,
	RCC_AHB_FLITF     = AHB_OFFSET  + 4   ,
	RCC_AHB_CRCEN     = AHB_OFFSET  + 6   ,
	RCC_AHB_FSMC      = AHB_OFFSET  + 8   ,
	RCC_AHB_SDIO      = AHB_OFFSET  + 10  ,
	RCC_APB2_AFIO     = APB2_OFFSET + 0   ,
	RCC_APB2_IOPA     = APB2_OFFSET + 2   ,
	RCC_APB2_IOPB     = APB2_OFFSET + 3   ,
	RCC_APB2_IOPC     = APB2_OFFSET + 4   ,
	RCC_APB2_IOPD     = APB2_OFFSET + 5   ,
	RCC_APB2_IOPE     = APB2_OFFSET + 6   ,
	RCC_APB2_IOPF     = APB2_OFFSET + 7   ,
	RCC_APB2_IOPG     = APB2_OFFSET + 8   ,
	RCC_APB2_ADC1     = APB2_OFFSET + 9   ,
	RCC_APB2_ADC2     = APB2_OFFSET + 10  ,
	RCC_APB2_TIM1     = APB2_OFFSET + 11  ,
	RCC_APB2_SPI1     = APB2_OFFSET + 12  ,
	RCC_APB2_TIM8     = APB2_OFFSET + 13  ,
	RCC_APB2_USART1   = APB2_OFFSET + 14  ,
	RCC_APB2_ADC3     = APB2_OFFSET + 15  ,
	RCC_APB2_TIM9     = APB2_OFFSET + 19  ,
	RCC_APB2_TIM10    = APB2_OFFSET + 20  ,
	RCC_APB2_TIM11    = APB2_OFFSET + 21  ,
	RCC_APB1_TIM2     = APB1_OFFSET + 0   ,
	RCC_APB1_TIM3     = APB1_OFFSET + 1   ,
	RCC_APB1_TIM4     = APB1_OFFSET + 2   ,
	RCC_APB1_TIM5     = APB1_OFFSET + 3   ,
	RCC_APB1_TIM6     = APB1_OFFSET + 4   ,
	RCC_APB1_TIM7     = APB1_OFFSET + 5   ,
	RCC_APB1_TIM12    = APB1_OFFSET + 6   ,
	RCC_APB1_TIM13    = APB1_OFFSET + 7   ,
	RCC_APB1_TIM14    = APB1_OFFSET + 9   ,
	RCC_APB1_WWDG     = APB1_OFFSET + 10  ,
	RCC_APB1_SPI2     = APB1_OFFSET + 14  ,
	RCC_APB1_SPI3     = APB1_OFFSET + 15  ,
	RCC_APB1_USART2   = APB1_OFFSET + 17  ,
	RCC_APB1_USART3   = APB1_OFFSET + 18  ,
	RCC_APB1_UART4    = APB1_OFFSET + 19  ,
	RCC_APB1_UART5    = APB1_OFFSET + 20  ,
	RCC_APB1_I2C1     = APB1_OFFSET + 21  ,
	RCC_APB1_I2C2     = APB1_OFFSET + 22  ,
	RCC_APB1_USB      = APB1_OFFSET + 23  ,
	RCC_APB1_CAN      = APB1_OFFSET + 25  ,
	RCC_APB1_BKP      = APB1_OFFSET + 27  ,
	RCC_APB1_PWR      = APB1_OFFSET + 28  ,
	RCC_APB1_DAC      = APB1_OFFSET + 29
}tRCC_Peripheral ; 
/* 
 tRCC_PeripheralClkState is an Enum (user defined data type) 
 to facilitate dealing with peripherals clock states 
*/
typedef enum
{
	RCC_PERIPHERAL_DISABLE = 0 , 
	RCC_PERIPHERAL_ENABLE  = 1 
}tRCC_PeripheralClkState ; 
/* 
 tRCC_ClksState is an Enum (user defined data type) 
 to facilitate dealing with different clock sources states (PLL , HSI , HSE )  
 and which passes & which not 
*/	
typedef enum
{
	RCC_PLL_OFF_HSI_OFF_HSE_OFF_BYPASS_OFF =  0B00000000,
	RCC_PLL_OFF_HSI_ON_HSE_OFF_BYPASS_OFF  =  0B00000100,
	RCC_PLL_OFF_HSI_OFF_HSE_ON_BYPASS_OFF  =  0B00000010,
	RCC_PLL_OFF_HSI_ON_HSE_ON_BYPASS_ON    =  0B00000111,
	RCC_PLL_ON_HSI_OFF_HSE_OFF_BYPASS_OFF  =  0B00001000,
	RCC_PLL_ON_HSI_ON_HSE_OFF_BYPASS_OFF   =  0B00001100,
	RCC_PLL_ON_HSI_OFF_HSE_ON_BYPASS_OFF   =  0B00001010,
	RCC_PLL_ON_HSI_ON_HSE_ON_BYPASS_ON     =  0B00001111
}tRCC_ClksState ; 
/* 
 tRCC_ClkSecurityState is an Enum (user defined data type) 
 to facilitate dealing with security states (En/Dis) 
*/		
typedef enum 
{
    RCC_CLKSECURITY_DISABLE = 0 , 
	RCC_CLKSECURITY_ENABLE  = 1 
}tRCC_ClkSecurityState ; 
/* 
 tRCC_MCuClkOutput is an Enum (user defined data type) 
 to facilitate dealing with output clock 
*/	
typedef enum
{
	RCC_MCO_NO_CLK     = 0 , 
	RCC_MCO_SYSTEM_CLK = 4 , 
	RCC_MCO_HSI_CLK    = 5 , 
	RCC_MCO_HSE_CLK    = 6 , 
	RCC_MCO_PLL_BY_2   = 7 
}tRCC_MCuClkOutput ; 
/* 
 tRCC_PllInput is an Enum (user defined data type) 
 to facilitate dealing with pll input states  
*/
typedef enum 
{
    RCC_PLL_IN_HSI_BY_2 = 0 , 
    RCC_PLL_IN_HSE      = 1 , 
    RCC_PLL_IN_HSE_BY_2 = 3 ,
	RCC_PLL_NOT_USED    = 4
}tRCC_PllInput ; 
/* 
 tRCC_SystemClk is an Enum (user defined data type) 
 to facilitate dealing with System clock which is directly enter to the processor  
*/
typedef enum 
{
    RCC_SYSTCLK_HSI = 0 , 
    RCC_SYSTCLK_HSE = 1 , 
    RCC_SYSTCLK_PLL = 2 
}tRCC_SystemClk ; 
/* 
 tRCC_PllMulFactor is an Enum (user defined data type) 
 to facilitate dealing with pll multiplaction factor  
*/	
typedef enum 
{
	PLL_IN_X_1  = 0b00001111 ,
	PLL_IN_X_2  = 0b00000000 ,
    PLL_IN_X_3  = 0b00000001 ,
    PLL_IN_X_4  = 0b00000010 , 
    PLL_IN_X_5  = 0b00000011 , 
    PLL_IN_X_6  = 0b00000100 , 
    PLL_IN_X_7  = 0b00000101 , 
    PLL_IN_X_8  = 0b00000110 , 
    PLL_IN_X_9  = 0b00000111 , 
    PLL_IN_X_10 = 0b00001000 , 
    PLL_IN_X_11 = 0b00001001 , 
    PLL_IN_X_12 = 0b00001010 , 
    PLL_IN_X_13 = 0b00001011 , 
    PLL_IN_X_14 = 0b00001100 , 
    PLL_IN_X_15 = 0b00001101 , 
    PLL_IN_X_16 = 0b00001110  
}tRCC_PllMulFactor ; 
/* 
 tRCC_APB2Prescaler is an Enum (user defined data type) 
 to facilitate dealing with APB2 Prescaler from AHB bus  
*/	
typedef enum 
{
   APB2_EQ_AHBCLK_BY_1  = 0 , 
   APB2_EQ_AHBCLK_BY_2  = 4 ,
   APB2_EQ_AHBCLK_BY_4  = 5 ,
   APB2_EQ_AHBCLK_BY_8  = 6 ,
   APB2_EQ_AHBCLK_BY_16 = 7 
}tRCC_APB2Prescaler ; 
/* 
 tRCC_APB1Prescaler is an Enum (user defined data type) 
 to facilitate dealing with APB1 Prescaler from AHB bus  
*/	
typedef enum 
{
   APB1_EQ_AHBCLK_BY_1  = 0 , 	
   APB1_EQ_AHBCLK_BY_2  = 4 ,
   APB1_EQ_AHBCLK_BY_4  = 5 ,
   APB1_EQ_AHBCLK_BY_8  = 6 ,
   APB1_EQ_AHBCLK_BY_16 = 7 
}tRCC_APB1Prescaler ;
/* 
 tRCC_APB2Prescaler is an Enum (user defined data type) 
 to facilitate dealing with AHB Prescaler from system clock 
*/	
typedef enum 
{
   AHB_EQ_SYSCLK_BY_1  = 0 , 
   AHB_EQ_SYSCLK_BY_2  = 8 ,
   AHB_EQ_SYSCLK_BY_4  = 9 ,
   AHB_EQ_SYSCLK_BY_8  = 10 ,
   AHB_EQ_SYSCLK_BY_16 = 11 ,
   AHB_EQ_SYSCLK_BY_64  = 12 ,
   AHB_EQ_SYSCLK_BY_128  = 13 ,
   AHB_EQ_SYSCLK_BY_256  = 14 ,
   AHB_EQ_SYSCLK_BY_512 = 15 
}tRCC_AHBPrescaler ;
/* 
  function name : RCC_voidInitSystemClk
  return type   : void 
  complexity    : O(1) 
  paramters     : 
                 1- tRCC_ClksState    : defines all clock resources states (pll , HSI , HSE) & does HSE passes from pins or not 
  			                        {RCC_PLL_OFF_HSI_OFF_HSE_OFF_BYPASS_OFF , RCC_PLL_OFF_HSI_ON_HSE_OFF_BYPASS_OFF , RCC_PLL_OFF_HSI_OFF_HSE_ON_BYPASS_OFF , RCC_PLL_OFF_HSI_ON_HSE_ON_BYPASS_ON
  			                         RCC_PLL_ON_HSI_OFF_HSE_OFF_BYPASS_OFF  , RCC_PLL_ON_HSI_ON_HSE_OFF_BYPASS_OFF  , RCC_PLL_ON_HSI_OFF_HSE_ON_BYPASS_OFF  , RCC_PLL_ON_HSI_ON_HSE_ON_BYPASS_ON }
  			     2- tRCC_SystemClk    : defines which clock source the system runs on 			   
  			                        {RCC_SYSTCLK_HSI , RCC_SYSTCLK_HSE , RCC_SYSTCLK_PLL } 
  			     3- tRCC_PllInput     : defines pll ciruit input 	                   
  			                        {RCC_PLL_IN_HSI_BY_2 , RCC_PLL_IN_HSE , RCC_PLL_IN_HSE_BY_2 , RCC_PLL_NOT_USED }
  			     4- tRCC_PllMulFactor : defines pll circuit multiplaction factor 			   
  			                        {PLL_IN_X_1 , PLL_IN_X_2  , PLL_IN_X_3  , PLL_IN_X_4  , PLL_IN_X_5  , PLL_IN_X_6  , PLL_IN_X_7  , PLL_IN_X_8
  									PLL_IN_X_9 , PLL_IN_X_10 , PLL_IN_X_11 , PLL_IN_X_12 , PLL_IN_X_13	, PLL_IN_X_14 , PLL_IN_X_15	, PLL_IN_X_16}						
  Description  : initalize the previous paramters. 		   
*/	
void RCC_voidInitSystemClk(tRCC_ClksState Copy_u8ClkStates , tRCC_SystemClk Copy_u8SystemClk ,tRCC_PllInput Copy_u8PllIn ,tRCC_PllMulFactor Copy_u8Pllmulfactor) ;  
/* 
  function name : RCC_voidSetClksState
  return type   : void 
  complexity    : O(1) 
  paramters     : 
                 1- tRCC_ClksState  : defines all clock resources states (pll , HSI , HSE) & does HSE passes from pins or not 
  			                        {RCC_PLL_OFF_HSI_OFF_HSE_OFF_BYPASS_OFF , RCC_PLL_OFF_HSI_ON_HSE_OFF_BYPASS_OFF , RCC_PLL_OFF_HSI_OFF_HSE_ON_BYPASS_OFF , RCC_PLL_OFF_HSI_ON_HSE_ON_BYPASS_ON
  			                         RCC_PLL_ON_HSI_OFF_HSE_OFF_BYPASS_OFF  , RCC_PLL_ON_HSI_ON_HSE_OFF_BYPASS_OFF  , RCC_PLL_ON_HSI_OFF_HSE_ON_BYPASS_OFF  , RCC_PLL_ON_HSI_ON_HSE_ON_BYPASS_ON }					
  Description  : initalize clocks states. 		   
*/	
void RCC_voidSetClksState(tRCC_ClksState Copy_u8ClkStates) ;
/* 
  function name : RCC_voidSetClkSecurityState
  return type   : void 
  complexity    : O(1) 
  paramters     : 
                 1- tRCC_ClkSecurityState : defines clock security state 
  			                              {RCC_CLKSECURITY_DISABLE , RCC_CLKSECURITY_ENABLE }
  			                           
  Description  : initalize clocks security state. 		   
*/
void RCC_voidSetClkSecurityState(tRCC_ClkSecurityState Copy_u8ClkSecurityStates) ; 
/* 
  function name : RCC_voidTrimInternalHighSpeedClk
  return type   : void 
  complexity    : O(1) 
  paramters     : 
                 1- s16 : defines amount of increment / decrement  
				 {-640 , 640 } 
  Description  : if there is an error in internal clock you can trim it. 		   
*/
void RCC_voidTrimInternalHighSpeedClk(s16 Copy_s16Offset) ; 

void RCC_voidSetMCuClkOutput(tRCC_MCuClkOutput Copy_u8MCO) ; 
void RCC_voidSetPllInput(tRCC_PllInput Copy_u8PllIn) ; 
void RCC_voidSetPeripheralClkState(tRCC_Peripheral Copy_u8PeripheralID,tRCC_PeripheralClkState Copy_u8PeripheralClkState) ; 
void RCC_voidSetSystemClk(tRCC_SystemClk Copy_u8SystemClk) ; 
void RCC_voidSetPllMulFactor(tRCC_PllMulFactor Copy_u8Pllmulfactor) ; 
tRCC_SystemClk RCC_tRCC_SystemClkGetSystClk(void) ;

void RCC_voidSetBusClks(tRCC_AHBPrescaler Copy_u8AHBPresc,tRCC_APB1Prescaler Copy_u8APB1Presc,tRCC_APB2Prescaler Copy_u8APB2Presc) ; 
#endif  __RCC_INTERFACE_H__
