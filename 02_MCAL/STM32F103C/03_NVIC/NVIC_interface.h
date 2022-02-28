/*************************************************************************/
/* Author        : Abdelrahman Hepish                                    */
/* File          : NVIC_interface.h                                      */
/* Date          : 5 Dec 2021                                            */
/* Version       : V01                                                   */
/* GitHub        : https://github.com/Abdelrahman-Hepish                 */
/*************************************************************************/
#ifndef __NVIC_INTERFACE_H__
#define __NVIC_INTERFACE_H__
/* numbers for debugging */ 
typedef enum
{
  NVIC_WWDG            = 0    ,  
  NVIC_PVD             = 1    , 
  NVIC_TAMPER          = 2    ,  
  NVIC_RTC             = 3    , 
  NVIC_FLASH           = 4    , 
  NVIC_RCC             = 5    ,  
  NVIC_EXTI0           = 6    , 
  NVIC_EXTI1           = 7    , 
  NVIC_EXTI2           = 8    , 
  NVIC_EXTI3           = 9    , 
  NVIC_EXTI4           = 10   ,
  NVIC_DMA1_Channel    = 11   , 
  NVIC_DMA1_Channe2    = 12   , 
  NVIC_DMA1_Channe3    = 13   , 
  NVIC_DMA1_Channel4   = 14   , 
  NVIC_DMA1_Channel5   = 15   ,  
  NVIC_DMA1_Channel6   = 16   ,  
  NVIC_DMA1_Channel7   = 17   ,  
  NVIC_ADC1_2          = 18   ,  
  NVIC_USB_HP_CAN_TX   = 19   ,  
  NVIC_USB_LP_CAN_RX0  = 20   ,  
  NVIC_CAN_RX1         = 21   , 
  NVIC_CAN_SCE         = 22   , 
  NVIC_EXTI9_5         = 23   , 
  NVIC_TIM1_BRK        = 24   ,  
  NVIC_TIM1_UP         = 25   ,  
  NVIC_TIM1_TRG_COM    = 26   ,  
  NVIC_TIM1_CC         = 27   ,  
  NVIC_TIM2            = 28   ,  
  NVIC_TIM3            = 29   ,  
  NVIC_TIM4            = 30   ,  
  NVIC_I2C1_EV         = 31   ,  
  NVIC_I2C1_ER         = 32   ,  
  NVIC_I2C2_EV         = 33   ,  
  NVIC_I2C2_ER         = 34   ,  
  NVIC_SPI1            = 35   ,  
  NVIC_SPI2            = 36   ,  
  NVIC_USART1          = 37   ,  
  NVIC_USART2          = 38   ,  
  NVIC_USART3          = 39   ,  
  NVIC_EXTI15_10       = 40   ,  
  NVIC_RTCAlarm        = 41   ,  
  NVIC_USBWakeup       = 42   ,
  NVIC_TIM8_BRK        = 43   ,
  NVIC_TIM8_UP         = 44   ,
  NVIC_TIM8_TRG_COM    = 45   ,
  NVIC_TIM8_CC         = 46   ,
  NVIC_ADC3            = 47   ,
  NVIC_FSMC            = 48   ,
  NVIC_SDIO            = 49   ,
  NVIC_TIM5            = 50   ,
  NVIC_SPI3            = 51   ,
  NVIC_UART4           = 52   ,
  NVIC_UART5           = 53   ,
  NVIC_TIM6            = 54   ,
  NVIC_TIM7            = 55   ,
  NVIC_DMA2_Channel1   = 56   ,
  NVIC_DMA2_Channel2   = 57   ,
  NVIC_DMA2_Channel3   = 58   ,
  NVIC_DMA2_Channel4_5 = 59             
}tNVIC_tPeripheral ;
typedef enum
{
   NVIC_PERIPHERAL_DISABLE = 0 , 
   NVIC_PERIPHERAL_ENABLE 
}tNVIC_PeripheralState ; 
typedef enum 
{
   NVIC_ACTIVE_FLAG_DISABLED = 0 , 
   NVIC_ACTIVE_FLAG_ENABLED 
}tNVIC_ActiveFlagStatus ; 

void NVIC_voidEnablePerInterrupt(tNVIC_tPeripheral Copy_u8PeripheralName) ; 
void NVIC_voidDisablePerInterrupt(tNVIC_tPeripheral Copy_u8PeripheralName) ; 
void NVIC_voidSetPendingFlagPerInterrupt(tNVIC_tPeripheral Copy_u8PeripheralName)  ; 
void NVIC_voidClearPendingFlagPerInterrupt(tNVIC_tPeripheral Copy_u8PeripheralName) ; 
tNVIC_ActiveFlagStatus NVIC_u8GetActiveFlagStatus(tNVIC_tPeripheral Copy_u8PeripheralName) ;
void NVIC_voidSetInterruptGroup_SubGroup_16G_0S(tNVIC_tPeripheral PeripheralId,u8 Copy_u8Group,u8 Copy_u8Sub) ; 
void NVIC_voidSetInterruptGroup_SubGroup_8G_2S (tNVIC_tPeripheral PeripheralId,u8 Copy_u8Group,u8 Copy_u8Sub) ; 
void NVIC_voidSetInterruptGroup_SubGroup_4G_4S (tNVIC_tPeripheral PeripheralId,u8 Copy_u8Group,u8 Copy_u8Sub) ;
void NVIC_voidSetInterruptGroup_SubGroup_2G_8S (tNVIC_tPeripheral PeripheralId,u8 Copy_u8Group,u8 Copy_u8Sub) ; 
void NVIC_voidSetInterruptGroup_SubGroup_0G_16S(tNVIC_tPeripheral PeripheralId,u8 Copy_u8Group,u8 Copy_u8Sub) ; 

#endif // __NVIC_INTERFACE_H__
