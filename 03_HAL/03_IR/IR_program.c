/*************************************************************************/
/* Author        : Abdelrahman Hepish                                    */
/* File          : IR_program.c                                          */
/* Date          : 7 MARCH 2022                                          */
/* Version       : V01                                                   */
/* GitHub        : https://github.com/Abdelrahman-Hepish                 */
/*************************************************************************/
#include "..\..\..\01_LIB\01_STD_TYPES\STD_TYPES.h"
#include "..\..\..\01_LIB\02_BIT_MATH\BIT_MATH.h"
#include "..\..\..\02_MCAL\STM32F103C\01_RCC\RCC_interface.h"
#include "..\..\..\02_MCAL\STM32F103C\02_GPIO\GPIO_interface.h"
#include "..\..\..\02_MCAL\STM32F103C\03_NVIC\NVIC_interface.h"
#include "..\..\..\02_MCAL\STM32F103C\05_EXTI\EXTI_interface.h"
#include "..\..\..\02_MCAL\STM32F103C\06_AFIO\AFIO_interface.h"
#include "..\..\..\02_MCAL\STM32F103C\07_STK\STK_interface.h"
#include "..\..\..\03_HAL\03_IR\IR_interface.h"
#include "..\..\..\03_HAL\03_IR\IR_private.h"
#include "..\..\..\03_HAL\03_IR\IR_config.h"

typedef enum
{
	ZERO_BIT   ,
	ONE_BIT    ,
	START_BIT  ,
	ERROR_BIT
}tIR_BitType;

volatile u32 TimeStamps[35] = {0} ;
volatile u8 startedBit = 0 , rxData  = 0 , rxAddress  = 0 , comError = 0  ;
static void IR_GetFrame(void) ;
static void IR_voidComEnded(void) ;
static tIR_BitType IR_BitType(u32 Copy_u32Bit) ;
void IR_voidInit(tGPIO_Port Copy_u8IR_GpioPort,tGPIO_Pin Copy_u8IRSingalPin)
{
	startedBit = 0 , rxData  = 0 , rxAddress  = 0  ,  comError = 0 ;
	/* Enale RCC for AFIO */
	RCC_voidSetPeripheralClkState(RCC_APB2_AFIO,RCC_PERIPHERAL_ENABLE) ;
	/* Select EXTI line to be chosen Port  */
	AFIO_voidSetEXTI_Configuration(Copy_u8IRSingalPin ,Copy_u8IR_GpioPort) ;
	/* Selcet chosen pin to be Floating pin to sense high & low */
	GPIO_voidSetPinMode(Copy_u8IR_GpioPort,Copy_u8IRSingalPin,PIN_FL_INPUT) ;
	/* Assign Call back function */
	/* Enable Interrupt for the EXTI on chosen pin */
	NVIC_voidEnablePerInterrupt(Copy_u8IRSingalPin + NVIC_EXTI0) ;
	EXTI_voidSetLineCallBackFunc(Copy_u8IRSingalPin , IR_GetFrame) ;
	/* Assign Sensing mode & enable EXTI */
	EXTI_voidInitLine(Copy_u8IRSingalPin ,EXTI_FALING_TRIGGER ,EXTI_ENABLE) ;
}
static void IR_GetFrame(void)
{
   u32  elapsedTicks = 0  ;
   if(startedBit == 0 )
   {
	  /* Assign very long time to start counting then get elapsed time */
	  STK_voidSetIntervalSingle(1000000,IR_voidComEnded) ;
	  /* Clear Communication error */
	  comError = 0 ;
   }else if (startedBit != 33)
   {
	   elapsedTicks = STK_u32GetElapsedTicks() ;
	   TimeStamps[startedBit - 1 ] = elapsedTicks ;
	   STK_voidSetIntervalSingle(1000000,IR_voidComEnded) ;
   }else // startedBit == 33 , Reciv ing Finished
   {
	   elapsedTicks = STK_u32GetElapsedTicks() ;
	   TimeStamps[startedBit - 1 ] = elapsedTicks ;
   }
   startedBit = ( startedBit + 1 ) % 34 ;
}
static void IR_voidComEnded(void)
{
	rxData  = 0 , rxAddress  = 0  ;
	u8 error_bit = 0 , startBitCorrect = 0 ,  comData  = 0 , comAddress  = 0 ;
	tIR_BitType currentBitType = ERROR_BIT ;
	if(IR_BitType(TimeStamps[0]) == START_BIT )
	{
		startBitCorrect = 1 ;
	}
	for(int i = 1 , j = 0  ;i<=8 ;i++,j++)
	{
		currentBitType = IR_BitType(TimeStamps[i]) ;
		if(currentBitType == ERROR_BIT)
		{
			error_bit ++ ;
		}else
		{
			MAN_BIT(comAddress,j,currentBitType) ;
		}
	}
	for(int i = 17 , j = 0  ;i<=24 ;i++,j++)
	{
		currentBitType = IR_BitType(TimeStamps[i]) ;
		if(currentBitType == ERROR_BIT)
		{
			error_bit ++ ;
		}else
		{
			MAN_BIT(comData,j,currentBitType) ;
		}
	}
	if(error_bit !=  0 && !startBitCorrect )
	{
		comError = 1 ;
	}else
	{
		comError = 0 ;
		rxAddress = comAddress ;
		rxData    = comData ;
	}
 	startedBit = 0 ;
	for(int i = 0 ;i<35;i++)
	{
		TimeStamps[i] = 0 ;
	}
}
static tIR_BitType IR_BitType(u32 Copy_u32Bit)
{
	tIR_BitType ret_bitTyep = ERROR_BIT ;
	 if(Copy_u32Bit >= 11000 && Copy_u32Bit <= 14500)
	 {
		 ret_bitTyep =  START_BIT ;
	 }else if (Copy_u32Bit >= 1000 && Copy_u32Bit <= 1200)
	 {
		 ret_bitTyep =  ZERO_BIT  ;
	 }
	 else if (Copy_u32Bit >= 2200 && Copy_u32Bit <= 2400)
	 {
	 	ret_bitTyep =  ONE_BIT  ;
	 }else
	 {
		 ret_bitTyep = ERROR_BIT ;
	 }
	 return ret_bitTyep ;
}
u8   IR_u8GetData(void)
{
	return rxData ;
}
u8   IR_u8GetAddress(void)
{
	return rxAddress ;
}
