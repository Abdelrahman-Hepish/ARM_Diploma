/*************************************************************************/
/* Author        : Abdelrahman Hepish                                    */
/* File          : GPIO_program.c                                        */
/* Date          : 8 NOV 2021                                            */
/* Version       : V01                                                   */
/* GitHub        : https://github.com/Abdelrahman-Hepish                 */
/*************************************************************************/
#include "..\..\..\01_LIB\01_STD_TYPES\STD_TYPES.h"
#include "..\..\..\01_LIB\02_BIT_MATH\BIT_MATH.h"
#include "..\..\..\02_MCAL\STM32F103C\01_RCC\RCC_interface.h"
#include "..\..\..\02_MCAL\STM32F103C\02_GPIO\GPIO_interface.h"
#include "..\..\..\02_MCAL\STM32F103C\02_GPIO\GPIO_config.h"
#include "..\..\..\02_MCAL\STM32F103C\02_GPIO\GPIO_private.h"

void GPIO_voidInitPin(tGPIO_Port Copy_u8Port,tGPIO_Pin Copy_u8Pin,tGPIO_PinMode Copy_u8PinMode,tGPIO_PinState Copy_u8PinState) 
{
GPIO_voidSetPinMode(Copy_u8Port,Copy_u8Pin,Copy_u8PinMode) ; 	
GPIO_voidSetPinState( Copy_u8Port,Copy_u8Pin,Copy_u8PinState) ;
}	
void GPIO_voidSetPinMode(tGPIO_Port Copy_u8Port,tGPIO_Pin Copy_u8Pin,tGPIO_PinMode Copy_u8PinMode)
{
	switch(Copy_u8Port)
	{
		case GPIO_PORTA : 
		    if(Copy_u8Pin < GPIO_PIN_8 ) 
			{
				MAN_NIBBLE(GPIOA_CRL,Copy_u8Pin*4,Copy_u8PinMode) ;  
			}else 
			{ 
		        Copy_u8Pin -= GPIO_PIN_8 ;
				MAN_NIBBLE(GPIOA_CRH,Copy_u8Pin*4,Copy_u8PinMode) ;  
			}
		break ; 
		case GPIO_PORTB : 
			if(Copy_u8Pin < GPIO_PIN_8 ) 
			{
				MAN_NIBBLE(GPIOB_CRL,Copy_u8Pin*4,Copy_u8PinMode) ;  
			}else 
			{ 
		        Copy_u8Pin -= GPIO_PIN_8 ;
				MAN_NIBBLE(GPIOB_CRH,Copy_u8Pin*4,Copy_u8PinMode) ;  
			}
		break ;
		case GPIO_PORTC : 
			if(Copy_u8Pin < GPIO_PIN_8 ) 
			{
				MAN_NIBBLE(GPIOC_CRL,Copy_u8Pin*4,Copy_u8PinMode) ;  
			}else 
			{ 
		        Copy_u8Pin -= GPIO_PIN_8 ;
				MAN_NIBBLE(GPIOC_CRH,Copy_u8Pin*4,Copy_u8PinMode) ;  
			}
		break ;
	}
} 	
void GPIO_voidSetPinState(tGPIO_Port Copy_u8Port,tGPIO_Pin Copy_u8Pin,tGPIO_PinState Copy_u8PinState) 
{
	switch(Copy_u8Port)
	{
		case GPIO_PORTA : 
             MAN_BIT(GPIOA_ODR,Copy_u8Pin,Copy_u8PinState) ; 
		break ; 
		case GPIO_PORTB : 
             MAN_BIT(GPIOB_ODR,Copy_u8Pin,Copy_u8PinState) ; 
		break ;
		case GPIO_PORTC : 
             MAN_BIT(GPIOC_ODR,Copy_u8Pin,Copy_u8PinState) ; 
		break ;
	}
} 
	
tGPIO_PinState GPIO_u8GetPinState(tGPIO_Port Copy_u8Port,tGPIO_Pin Copy_u8Pin) 
{
	tGPIO_PinState ret = GPIO_PIN_LOW ; 
	switch(Copy_u8Port)
	{
		case GPIO_PORTA : 
             ret = GET_BIT(GPIOA_IDR,Copy_u8Pin) ;
		break ; 
		case GPIO_PORTB : 
             ret = GET_BIT(GPIOB_IDR,Copy_u8Pin) ; 
		break ;
		case GPIO_PORTC : 
             ret = GET_BIT(GPIOC_IDR,Copy_u8Pin) ;
		break ;
	}
	return ret ; 
}

void GPIO_voidInitByte(tGPIO_Port Copy_u8Port,tGPIO_BytePosition Copy_u8Position,tGPIO_PinMode Copy_u8PinsMode,u8 Copy_u8PinsState)
{
	GPIO_voidSetByteMode(Copy_u8Port,Copy_u8Position,Copy_u8PinsMode) ;
	GPIO_voidSetByteState(Copy_u8Port,Copy_u8Position,Copy_u8PinsState) ;
}
void GPIO_voidSetByteMode(tGPIO_Port Copy_u8Port,tGPIO_BytePosition Copy_u8Position,tGPIO_PinMode Copy_u8PinsMode)
{
	tGPIO_Pin Copy_u8StartPin , Copy_u8EndPin ;
	if(Copy_u8Position == GPIO_LOW_BYTE)
	{
		Copy_u8StartPin = GPIO_PIN_0 ;
		Copy_u8EndPin   = GPIO_PIN_7 ;
	}else
	{
		Copy_u8StartPin = GPIO_PIN_8 ;
		Copy_u8EndPin   = GPIO_PIN_15 ;
	}
	for(;Copy_u8StartPin<=Copy_u8EndPin;Copy_u8StartPin++)
	{
		GPIO_voidSetPinMode(Copy_u8Port,Copy_u8StartPin,Copy_u8PinsMode) ;
	}
}
void GPIO_voidSetByteState(tGPIO_Port Copy_u8Port,tGPIO_BytePosition Copy_u8Position,u8 Copy_u8PinsState)
{
	tGPIO_Pin Copy_u8StartBit ;
	if(Copy_u8Position == GPIO_LOW_BYTE)
	{
		Copy_u8StartBit = GPIO_PIN_0 ;
	}else
	{
		Copy_u8StartBit = GPIO_PIN_8 ;
	}
	switch(Copy_u8Port)
	{
		case GPIO_PORTA :
			MAN_BYTE(GPIOA_ODR,Copy_u8StartBit,Copy_u8PinsState);
		break ;
		case GPIO_PORTB :
			MAN_BYTE(GPIOB_ODR,Copy_u8StartBit,Copy_u8PinsState);
		break ;
		case GPIO_PORTC :
			MAN_BYTE(GPIOC_ODR,Copy_u8StartBit,Copy_u8PinsState);
		break ;
	}
}
