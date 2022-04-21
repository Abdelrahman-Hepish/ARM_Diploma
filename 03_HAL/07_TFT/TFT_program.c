/*************************************************************************/
/* Author        : Abdelrahman Hepish                                    */
/* File          : TFT_program.c                                         */
/* Date          : 19 APRIL 2022                                         */
/* Version       : V01                                                   */
/* GitHub        : https://github.com/Abdelrahman-Hepish                 */
/*************************************************************************/
#include "..\..\..\01_LIB\01_STD_TYPES\STD_TYPES.h"
#include "..\..\..\01_LIB\02_BIT_MATH\BIT_MATH.h"
#include "..\..\..\02_MCAL\STM32F103C\07_STK\STK_interface.h"
#include "..\..\..\02_MCAL\STM32F103C\02_GPIO\GPIO_interface.h"
#include "..\..\..\02_MCAL\STM32F103C\09_SPI\SPI_interface.h"
#include "..\..\..\03_HAL\07_TFT\TFT_interface.h"
#include "..\..\..\03_HAL\07_TFT\TFT_private.h"
#include "..\..\..\03_HAL\07_TFT\TFT_config.h"
static void STFT_WritedData(u8 Data) ; 
static void STFT_WriteCmd(u8 Command)  ; 
void TFT_voidInit(void) 
{
   /* Reset pulses */  
  GPIO_voidSetPinState(TFT_RST_PIN,GPIO_PIN_HIGH) ;
  STK_BusyWaitTicks(100) ;
  GPIO_voidSetPinState(TFT_RST_PIN,GPIO_PIN_LOW) ;
  STK_BusyWaitTicks(1) ;
  GPIO_voidSetPinState(TFT_RST_PIN,GPIO_PIN_HIGH) ;
  STK_BusyWaitTicks(100) ;
  GPIO_voidSetPinState(TFT_RST_PIN,GPIO_PIN_LOW) ;
  STK_BusyWaitTicks(100) ;
  GPIO_voidSetPinState(TFT_RST_PIN,GPIO_PIN_HIGH) ;
  STK_BusyWaitTicks(120000) ;
 /* ***************************************** */ 
  /* Sleep out command */ 
  STFT_WriteCmd(SLEEP_OUT_CMD) ; 
  STK_BusyWaitTicks(150000) ;
 /* ***************************************** */  
  /* Colour Mode cmd + data */ 
  STFT_WriteCmd(COLOUR_MODE_CMD) ; 
  STFT_WritedData(COLOUR_MODE) ; 
 /* ***************************************** */ 
  STFT_WriteCmd(DISPLAY_ON_CMD) ;    

} 
void TFT_voidDisplayImage(const u16 *Copy_u16PtrToImage ) 
{

}
static void STFT_WritedData(u8 Data)
{
  u8 LocalTempRec ;    
 /* Set A0 pin on TFT to High */ 
  GPIO_voidSetPinState(TFT_A0_PIN,GPIO_PIN_HIGH) ; 
  /* Send Data over SPI */ 
  SPI_voidSendReceiveSynch(Data,&LocalTempRec) ; 
}
static void STFT_WriteCmd(u8 Command) 
{
 u8 LocalTempRec ;   
 /* Set A0 pin on TFT to Low */ 
 GPIO_voidSetPinState(TFT_A0_PIN,GPIO_PIN_LOW) ; 
 /* Send Command over SPI */ 
 SPI_voidSendReceiveSynch(Command,&LocalTempRec) ; 
}
