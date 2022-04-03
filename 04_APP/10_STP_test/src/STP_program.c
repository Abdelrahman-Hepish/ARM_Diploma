/*************************************************************************/
/* Author        : Abdelrahman Hepish                                    */
/* File          : STP_program.c                                         */
/* Date          :                                                       */
/* Version       : V01                                                   */
/* GitHub        : https://github.com/Abdelrahman-Hepish                 */
/*************************************************************************/
#include "..\..\..\01_LIB\01_STD_TYPES\STD_TYPES.h"
#include "..\..\..\01_LIB\02_BIT_MATH\BIT_MATH.h"
#include "..\..\..\02_MCAL\STM32F103C\07_STK\STK_interface.h"
#include "..\..\..\02_MCAL\STM32F103C\02_GPIO\GPIO_interface.h"
#include "..\..\..\03_HAL\06_STP\STP_interface.h"
#include "..\..\..\03_HAL\06_STP\STP_private.h"
#include "..\..\..\03_HAL\06_STP\STP_config.h"
void STP_voidInit(void)
{
	GPIO_voidInitPin(STP_SERIAL_DATA,PIN_NM_OUTPUT_2MHZ,0x00) ;
	GPIO_voidInitPin(STP_SHIFT_CLOCK,PIN_NM_OUTPUT_2MHZ,0x00) ;
	GPIO_voidInitPin(STP_STORE_CLOCK,PIN_NM_OUTPUT_2MHZ,0x00) ;
}
void STP_voidSendSynchronus(u8 Copy_u8Data2Send)
{
 /* Send 8 bit data from MSB */
 s8 local_s8BitCounter ;
 u8 local_u8BitSend ;
 for(local_s8BitCounter = 7  ; local_s8BitCounter >= 0 ;local_s8BitCounter --)
 {
    local_u8BitSend = GET_BIT(Copy_u8Data2Send,local_s8BitCounter) ;
    GPIO_voidSetPinState(STP_SERIAL_DATA,local_u8BitSend) ;
    GPIO_voidSetPinState(STP_SHIFT_CLOCK,GPIO_PIN_HIGH) ;
	STK_BusyWaitTicks(1) ;
	GPIO_voidSetPinState(STP_SHIFT_CLOCK,GPIO_PIN_LOW) ;
 }
    GPIO_voidSetPinState(STP_STORE_CLOCK,GPIO_PIN_HIGH) ;
	STK_BusyWaitTicks(1) ;
	GPIO_voidSetPinState(STP_STORE_CLOCK,GPIO_PIN_LOW) ;
}
