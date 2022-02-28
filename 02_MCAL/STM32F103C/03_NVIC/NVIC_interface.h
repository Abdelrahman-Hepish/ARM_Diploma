/*************************************************************************/
/* Author        : Abdelrahman Hepish                                    */
/* File          : NVIC_interface.h                                      */
/* Date          : 5 Dec 2021                                            */
/* Version       : V01                                                   */
/* GitHub        : https://github.com/Abdelrahman-Hepish                 */
/*************************************************************************/
#ifndef __NVIC_INTERFACE_H__
#define __NVIC_INTERFACE_H__
typedef enum 
{
  NVIC_WWDG          = 0   ,
  NVIC_PVD                 ,
  NVIC_TAMPER              ,
  NVIC_RTC                 ,
  NVIC_FLASH               ,
  NVIC_RCC                 ,
  NVIC_EXTI0               ,
  NVIC_EXTI1               ,
  NVIC_EXTI2               ,
  NVIC_EXTI3               ,
  NVIC_EXTI4               ,
  NVIC_DMA1_Channel1       ,
  NVIC_DMA1_Channel2       ,
  NVIC_DMA1_Channel3       ,
  NVIC_DMA1_Channel4       ,
  NVIC_DMA1_Channel5       ,
  NVIC_DMA1_Channel6       ,
  NVIC_DMA1_Channel7       ,
  NVIC_ADC1_2              ,
  NVIC_USB_HP_CAN_         ,
  NVIC_TX                  ,
  NVIC_USB_LP_CAN_         ,
  NVIC_RX0                 ,
  NVIC_CAN_RX1             ,
  NVIC_CAN_SCE             ,
  NVIC_EXTI9_5             ,
  NVIC_TIM1_BRK            ,
  NVIC_TIM1_UP             ,
  NVIC_TIM1_TRG_COM        ,
  NVIC_TIM1_CC             ,
  NVIC_TIM2                ,
  NVIC_TIM3                ,
  NVIC_TIM4                ,
  NVIC_I2C1_EV             ,
  NVIC_I2C1_ER             ,
  NVIC_I2C2_EV             ,
  NVIC_I2C2_ER             ,
  NVIC_SPI1                ,
  NVIC_SPI2                ,
  NVIC_USART1              ,
  NVIC_USART2              ,
  NVIC_USART3              ,
  NVIC_EXTI15_10           ,
  NVIC_RTCAlarm            ,
  NVIC_USBWakeup           ,
  NVIC_TIM8_BRK            ,
  NVIC_TIM8_UP             ,
  NVIC_TIM8_TRG_COM        ,
  NVIC_TIM8_CC             ,
  NVIC_ADC3                ,
  NVIC_FSMC                ,
  NVIC_SDIO                ,
  NVIC_TIM5                ,
  NVIC_SPI3                ,
  NVIC_UART4               ,
  NVIC_UART5               ,
  NVIC_TIM6                ,
  NVIC_TIM7                ,
  NVIC_DMA2_Channel1       ,
  NVIC_DMA2_Channel2       ,
  NVIC_DMA2_Channel3       ,
  NVIC_DMA2_Channel4_5
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