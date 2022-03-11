/*************************************************************************/
/* Author        : Abdelrahman Hepish                                    */
/* File          :                                                       */
/* Date          : 14 DEC 2021                                           */
/* Version       : V01                                                   */
/* GitHub        : https://github.com/Abdelrahman-Hepish                 */
/*************************************************************************/
#ifndef __STK_INTERFACE_H__
#define __STK_INTERFACE_H__
typedef enum 
{
	STK_CLKSRC_AHB_BY_8 = 0 , 
	STK_CLKSRC_AHB 
}tSTK_ClockSource ; 
typedef enum 
{
	STK_INT_DISABLE     = 0 , 
	STK_INT_ENABLE 
}tSTK_InterruptState ; 
typedef enum 
{
	STK_DISABLED  = 0 , 
	STK_ENABLED 
}tSTK_State ; 
void STK_voidInit(tSTK_State Copy_u8STK_State,tSTK_ClockSource Copy_u8STK_ClkSrc,tSTK_InterruptState Copy_u8STK_IntState) ; 	
void STK_voidSetState(tSTK_State Copy_u8STK_State ) ; 
void STK_voidSetInterruptState(tSTK_InterruptState Copy_u8STK_IntState) ;  
void STK_voidSetClkSrc(tSTK_ClockSource Copy_u8STK_ClkSrc) ; 
void Delay_ms(u32 Copy_u8DelayTime) ;
void STK_BusyWaitTicks(u32 Copy_u32NumberofTicks) ;
void STK_voidSetIntervalSingle(u32 Copy_u32NumberofTicks,void (*ptrfunc)(void)) ;
void STK_voidSetIntervalPeriodic(u32 Copy_u32NumberofTicks,void (*ptrfunc)(void)) ;
u32  STK_u32GetElapsedTicks(void) ;
u32  STK_u32GetRemainningTicks(void) ;
#endif  __STK_INTERFACE_H__
