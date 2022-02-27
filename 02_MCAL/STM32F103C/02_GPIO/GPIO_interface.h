/*************************************************************************/
/* Author        : Abdelrahman Hepish                                    */
/* File          : GPIO_interface.h                                      */
/* Date          : 8 NOV 2021                                            */
/* Version       : V01                                                   */
/* GitHub        : https://github.com/Abdelrahman-Hepish                 */
/*************************************************************************/
#ifndef __GPIO_INTERFACE_H__
#define __GPIO_INTERFACE_H__

typedef enum 
{
		PIN_AN_INPUT             = 0B00000000 ,
		PIN_FL_INPUT             = 0B00000100 ,
		PIN_PU_INPUT             = 0B00001000 ,
		PIN_NM_OUTPUT_2MHZ       = 0B00000010 ,
		PIN_OD_OUTPUT_2MHZ       = 0B00000110 ,
		PINT_AF_NM_OUTPUT_2MHZ   = 0B00001010 ,
		PINT_AF_OD_OUTPUT_2MHZ   = 0B00001110 ,
		PIN_NM_OUTPUT_10MHZ      = 0B00000001 ,
		PIN_OD_OUTPUT_10MHZ      = 0B00000101 ,
		PINT_AF_NM_OUTPUT_10MHZ  = 0B00001001 ,
		PINT_AF_OD_OUTPUT_10MHZ  = 0B00001101 ,
		PIN_NM_OUTPUT_50MHZ      = 0B00000011 ,
		PIN_OD_OUTPUT_50MHZ      = 0B00000111 ,
		PINT_AF_NM_OUTPUT_50MHZ  = 0B00001011 ,
		PINT_AF_OD_OUTPUT_50MHZ  = 0B00001111
}tGPIO_PinMode ; 
typedef enum 
{
    GPIO_PIN_0    = 0   ,
    GPIO_PIN_1    = 1   ,
    GPIO_PIN_2    = 2   ,
    GPIO_PIN_3    = 3   ,
    GPIO_PIN_4    = 4   ,
    GPIO_PIN_5    = 5   ,
    GPIO_PIN_6    = 6   ,
    GPIO_PIN_7    = 7   ,
    GPIO_PIN_8    = 8   ,
    GPIO_PIN_9    = 9   ,
    GPIO_PIN_10   = 10  ,
    GPIO_PIN_11   = 11  ,
    GPIO_PIN_12   = 12  ,
    GPIO_PIN_13   = 13  ,
    GPIO_PIN_14   = 14  ,
    GPIO_PIN_15   = 15
}tGPIO_Pin ; 
typedef enum 
{
	GPIO_PORTA    = 0  , 
	GPIO_PORTB    = 1  , 
	GPIO_PORTC    = 2 
}tGPIO_Port ; 
typedef enum 
{
	GPIO_PIN_LOW  = 0 , 
	GPIO_PIN_HIGH = 1 
}tGPIO_PinState ; 
typedef enum
{
	GPIO_LOW_BYTE = 0 ,
	GPIO_HIGH_BYTE = 1
}tGPIO_BytePosition;
void GPIO_voidInitPin(tGPIO_Port Copy_u8Port,tGPIO_Pin Copy_u8Pin,tGPIO_PinMode Copy_u8PinMode,tGPIO_PinState Copy_u8PinState) ; 
void GPIO_voidInitByte(tGPIO_Port Copy_u8Port,tGPIO_BytePosition Copy_u8Position,tGPIO_PinMode Copy_u8PinsMode,u8 Copy_u8PinsState) ;
void GPIO_voidSetPinMode(tGPIO_Port Copy_u8Port,tGPIO_Pin Copy_u8Pin,tGPIO_PinMode Copy_u8PinMode) ;
void GPIO_voidSetByteMode(tGPIO_Port Copy_u8Port,tGPIO_BytePosition Copy_u8Position,tGPIO_PinMode Copy_u8PinsMode) ;
void GPIO_voidSetPinState(tGPIO_Port Copy_u8Port,tGPIO_Pin Copy_u8Pin,tGPIO_PinState Copy_u8PinState) ; 
void GPIO_voidSetByteState(tGPIO_Port Copy_u8Port,tGPIO_BytePosition Copy_u8Position,u8 Copy_u8PinsState) ;
tGPIO_PinState GPIO_u8GetPinState(tGPIO_Port Copy_u8Port,tGPIO_Pin Copy_u8Pin) ; 
#endif // __GPIO_INTERFACE_H__
