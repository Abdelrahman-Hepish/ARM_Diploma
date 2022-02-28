/*************************************************************************/
/* Author        : Abdelrahman Hepish                                    */
/* File          : EXTI_program.c                                        */
/* Date          : 11 DEC 2021                                           */
/* Version       : V01                                                   */
/* GitHub        : https://github.com/Abdelrahman-Hepish                 */
/*************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

void EXTI_voidInitLine(tEXTI_Line Copy_ExtiLine ,tEXTI_TriggerMode Copy_TriggerMode ,tEXTI_State Copy_ExtiState)
{
	switch(Copy_TriggerMode) 
	{
		case EXTI_RISING_TRIGGER    : SET_BIT(EXTI->RTSR,Copy_ExtiLine) ; break ; 
		case EXTI_FALING_TRIGGER    : SET_BIT(EXTI->FTSR,Copy_ExtiLine) ; break ; 
		case EXTI_ON_CHANGE_TRIGGER : SET_BIT(EXTI->RTSR,Copy_ExtiLine) ; SET_BIT(EXTI->FTSR,Copy_ExtiLine) ; break ; 
	}
	MAN_BIT(EXTI->IMR,Copy_ExtiLine,Copy_ExtiState) ; 
}
void EXTI_voidSetMode(tEXTI_Line Copy_ExtiLine ,tEXTI_TriggerMode Copy_TriggerMode) 
{
		switch(Copy_TriggerMode) 
	{
		case EXTI_RISING_TRIGGER    : SET_BIT(EXTI->RTSR,Copy_ExtiLine) ; break ; 
		case EXTI_FALING_TRIGGER    : SET_BIT(EXTI->FTSR,Copy_ExtiLine) ; break ; 
		case EXTI_ON_CHANGE_TRIGGER : SET_BIT(EXTI->RTSR,Copy_ExtiLine) ; SET_BIT(EXTI->FTSR,Copy_ExtiLine) ; break ; 
	}
}	
void EXTI_voidSetState(tEXTI_Line Copy_ExtiLine ,tEXTI_State Copy_ExtiState) 
{
	MAN_BIT(EXTI->IMR,Copy_ExtiLine,Copy_ExtiState) ;
}
void EXTI_voidSetSoftWareTrigger(tEXTI_Line Copy_ExtiLine )
{
	SET_BIT(EXTI->SWIER,Copy_ExtiLine) ;  
}