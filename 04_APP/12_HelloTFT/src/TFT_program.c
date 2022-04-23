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
	u32 local_u32Counter ;
	/* Set X starting address */
	STFT_WriteCmd(SET_X_ADDRESS_CMD) ;
	/* Writing Start address High byte first , then low byte */
	STFT_WritedData(0x00) ;
	STFT_WritedData(0x00) ;
	/* Writing End address High byte first , then low byte */
	STFT_WritedData(TFT_MAX_X_SIZE>>8) ;
	STFT_WritedData(TFT_MAX_X_SIZE&0XFF) ;
	/* Set X starting address */
	STFT_WriteCmd(SET_Y_ADDRESS_CMD) ;
	/* Writing Start address High byte first , then low byte */
	STFT_WritedData(0x00) ;
	STFT_WritedData(0x00) ;
	/* Writing End address High byte first , then low byte */
	STFT_WritedData(TFT_MAX_Y_SIZE>>8) ;
	STFT_WritedData(TFT_MAX_Y_SIZE&0XFF) ;
	/* ************************************************* */
	/* RAM write */
	STFT_WriteCmd(RAM_WRITE_CMD) ;
	for(local_u32Counter = 0 ;local_u32Counter <TFT_NUM_PIXELS;local_u32Counter ++ )
	{
		/* Write High byte */
		STFT_WritedData(Copy_u16PtrToImage[local_u32Counter]>>8) ;
		/* Write Low byte */
		STFT_WritedData(Copy_u16PtrToImage[local_u32Counter]&0xff) ;
	}

}
void TFT_voidFillSquare(u32 x_start,u32 x_end , u32 y_start ,u32 y_end , u32 Color)
{
	u32 local_u32Counter , local_u32Area;
	/* Set X starting address */
	STFT_WriteCmd(SET_X_ADDRESS_CMD) ;
	/* Writing Start address High byte first , then low byte */
	STFT_WritedData(x_start>>8) ;
	STFT_WritedData(x_start&0xff) ;
	/* Writing End address High byte first , then low byte */
	STFT_WritedData(x_end>>8) ;
	STFT_WritedData(x_end&0XFF) ;
	/* Set Y starting address */
	STFT_WriteCmd(SET_Y_ADDRESS_CMD) ;
	/* Writing Start address High byte first , then low byte */
	STFT_WritedData(y_start>>8) ;
	STFT_WritedData(y_start&0xff) ;
	/* Writing End address High byte first , then low byte */
	STFT_WritedData(y_end>>8) ;
	STFT_WritedData(y_end&0XFF) ;
	/* ************************************************* */
	/* ************************************************* */
	/* RAM write */
	STFT_WriteCmd(RAM_WRITE_CMD) ;
	local_u32Area = (x_end - x_start) * (y_end - y_start) - 1  ;
	for(local_u32Counter = 0 ;local_u32Counter <local_u32Area;local_u32Counter ++ )
	{
		/* Write High byte */
		STFT_WritedData(Color>>8) ;
		/* Write Low byte */
		STFT_WritedData(Color&0xff) ;
	}
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
