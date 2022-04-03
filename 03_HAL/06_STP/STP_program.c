/*************************************************************************/
/* Author        : Abdelrahman Hepish                                    */
/* File          : STP_program.c                                         */
/* Date          :                                                       */
/* Version       : V01                                                   */
/* GitHub        : https://github.com/Abdelrahman-Hepish                 */
/*************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "STP_interface.h"
#include "STP_private.h"
#include "STP_config.h"
#include "GPIO_interface.h" 
#include "STK_interface.h" 
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
 for(local_s8BitCounter ; local_s8BitCounter >= 0 ;local_s8BitCounter --) 
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