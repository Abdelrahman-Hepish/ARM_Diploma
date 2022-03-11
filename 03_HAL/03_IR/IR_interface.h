/*************************************************************************/
/* Author        : Abdelrahman Hepish                                    */
/* File          : IR_interface.h                                        */
/* Date          : 7 MARCH 2022                                          */
/* Version       : V01                                                   */
/* GitHub        : https://github.com/Abdelrahman-Hepish                 */
/*************************************************************************/
#ifndef __IR_INTERFACE_H__
#define __IR_INTERFACE_H__

typedef enum
{
	IR_POWER_BUTTON    = 69 ,
	IR_MODE_BUTTON     = 70 ,
	IR_MUTE_BUTTON     = 71 ,
	IR_PAUSE_BUTTON    = 68 ,
	IR_PREVIOUS_BUTTON = 64 ,
	IR_NEXT_BUTTON     = 67 ,
	IR_EQ_BUTTON       = 7  ,
	IR_VOL_DE_BUTTON   = 21 ,
	IR_VOL_IN_BUTTON   = 9  ,
	IR_0_BUTTON        = 22 ,
	IR_RPT_BUTTON      = 25 ,
	IR_U_USD_BUTTON    = 13 ,
	IR_1_BUTTON        = 12 ,
	IR_2_BUTTON        = 24 ,
	IR_3_BUTTON        = 94 ,
	IR_4_BUTTON        = 8  ,
	IR_5_BUTTON        = 28 ,
	IR_6_BUTTON        = 90 ,
	IR_7_BUTTON        = 66 ,
	IR_8_BUTTON        = 82 ,
	IR_9_BUTTON        = 74 ,
	IR_ERROR_STATE     = 0
}tIR_NECRemoteButtons;

/* For STM32F104C family you can use PIN 0 , 1 , 2 , 3 , 4 , prefered Port :  A " */
/* Enable RCC for the Selected GPIO */
void IR_voidInit(tGPIO_Port Copy_u8IR_GpioPort,tGPIO_Pin Copy_u8IRSingalPin) ;
tIR_NECRemoteButtons   IR_u8GetData(void) ;
u8   IR_u8GetAddress(void) ;
#endif  // __IR_INTERFACE_H__
