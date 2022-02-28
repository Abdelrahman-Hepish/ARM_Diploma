/*************************************************************************/
/* Author        : Abdelrahman Hepish                                    */
/* File          :                                                       */
/* Date          : 14 DEC 2021                                           */
/* Version       : V01                                                   */
/* GitHub        : https://github.com/Abdelrahman-Hepish                 */
/*************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "STK_interface.h"
#include "STK_private.h"
#include "STK_config.h"

u32 DelayTime ;
void STK_voidInit(tSTK_State Copy_u8STK_State,tSTK_ClockSource Copy_u8STK_ClkSrc,tSTK_InterruptState Copy_u8STK_IntState) 
{
     MAN_BIT(STK_CTRL,STK_ENABLE_BIT,Copy_u8STK_State) ;  
	 MAN_BIT(STK_CTRL,STK_TICKINT_BIT,Copy_u8STK_IntState) ;   
	 MAN_BIT(STK_CTRL,STK_CLKSOURCE_BIT,Copy_u8STK_ClkSrc) ;
}	
void STK_voidSetState(tSTK_State Copy_u8STK_State ) 
{
	MAN_BIT(STK_CTRL,STK_ENABLE_BIT,Copy_u8STK_State) ;
}
void STK_voidSetInterruptState(tSTK_InterruptState Copy_u8STK_IntState) 
{
    MAN_BIT(STK_CTRL,STK_TICKINT_BIT,Copy_u8STK_IntState) ;
}	
void STK_voidSetClkSrc(tSTK_ClockSource Copy_u8STK_ClkSrc) 
{
	MAN_BIT(STK_CTRL,STK_CLKSOURCE_BIT,Copy_u8STK_ClkSrc) ;
}
void Delay_ms(u8 Copy_u8DelayTime) 
{
	DelayTime = Copy_u8DelayTime ; 
	tSTK_State Copy_u8STK_State =  GET_BIT(STK_CTRL,STK_ENABLE_BIT); 
	tSTK_InterruptState Copy_u8STK_IntState = GET_BIT(STK_CTRL,STK_TICKINT_BIT); 
	tSTK_ClockSource Copy_u8STK_ClkSrc = GET_BIT(STK_CTRL,STK_CLKSOURCE_BIT); 
	// GET_BIT(STK_CTRL,STK_COUNTFLAG_BIT) ;
	DelayTime -- ;
	STK_voidInit(STK_ENABLED,STK_CLKSRC_AHB_BY_8,STK_INT_ENABLE	) ;
	STK_LOAD = DELAY_1_MS_TIME ;
	while(DelayTime) ; 
	STK_voidInit(Copy_u8STK_State,Copy_u8STK_ClkSrc,Copy_u8STK_IntState) ;  
}
void SysTick_Handler(void)
{
	DelayTime -- ; 
	if(DelayTime != 0 ) STK_LOAD = DELAY_1_MS_TIME ;
	GET_BIT(STK_CTRL,STK_COUNTFLAG_BIT) ; 
}
