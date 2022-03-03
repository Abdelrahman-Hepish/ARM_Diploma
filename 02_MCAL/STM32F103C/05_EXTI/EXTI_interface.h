/*************************************************************************/
/* Author        : Abdelrahman Hepish                                    */
/* File          : EXTI_private.h                                         */
/* Date          : 11 DEC 2021                                           */
/* Version       : V01                                                   */
/* GitHub        : https://github.com/Abdelrahman-Hepish                 */
/*************************************************************************/
#ifndef __EXTI_INTERFACE_H__
#define __EXTI_INTERFACE_H__

typedef enum 
{
	EXTI_RISING_TRIGGER  , 
	EXTI_FALING_TRIGGER  , 
	EXTI_ON_CHANGE_TRIGGER 
}tEXTI_TriggerMode ; 
typedef enum 
{
	EXTI_DISABLED = 0 , 
	EXTI_ENABLE   = 1 
}tEXTI_State ; 
typedef enum 
{
	EXTI_LINE_0   = 0 , 
	EXTI_LINE_1       , 
	EXTI_LINE_2       , 
	EXTI_LINE_3       , 
	EXTI_LINE_4       , 
	EXTI_LINE_5       , 
	EXTI_LINE_6       , 
	EXTI_LINE_7       , 
	EXTI_LINE_8       , 
	EXTI_LINE_9       ,
	EXTI_LINE_10      , 
	EXTI_LINE_11      , 
	EXTI_LINE_12      , 
	EXTI_LINE_13      , 
	EXTI_LINE_14      ,
	EXTI_LINE_15     
}tEXTI_Line ; 

void EXTI_voidInitLine(tEXTI_Line Copy_ExtiLine ,tEXTI_TriggerMode Copy_TriggerMode ,tEXTI_State Copy_ExtiState) ; 
void EXTI_voidSetMode(tEXTI_Line Copy_ExtiLine ,tEXTI_TriggerMode Copy_TriggerMode) ; 
void EXTI_voidSetState(tEXTI_Line Copy_ExtiLine ,tEXTI_State Copy_ExtiState) ; 
void EXTI_voidSetSoftWareTrigger(tEXTI_Line Copy_ExtiLine ) ; 
void EXTI_voidSetLineCallBackFunc(tEXTI_Line Copy_ExtiLine , void (*ptrfunc) (void)) ; 		
#endif  __EXTI_INTERFACE_H__