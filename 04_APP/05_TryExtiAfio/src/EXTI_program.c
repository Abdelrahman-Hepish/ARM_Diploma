/*************************************************************************/
/* Author        : Abdelrahman Hepish                                    */
/* File          : EXTI_program.c                                        */
/* Date          : 11 DEC 2021                                           */
/* Version       : V01                                                   */
/* GitHub        : https://github.com/Abdelrahman-Hepish                 */
/*************************************************************************/
#include "..\..\..\01_LIB\01_STD_TYPES\STD_TYPES.h"
#include "..\..\..\01_LIB\02_BIT_MATH\BIT_MATH.h"
#include "..\..\..\02_MCAL\STM32F103C\05_EXTI\EXTI_interface.h"
#include "..\..\..\02_MCAL\STM32F103C\05_EXTI\EXTI_config.h"
#include "..\..\..\02_MCAL\STM32F103C\05_EXTI\EXTI_private.h"

void (*CallBackFunctEXTI_LINE[16]) (void) ; 
 
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
void EXTI_voidSetLineCallBackFunc(tEXTI_Line Copy_ExtiLine , void (*ptrfunc) (void)) 
{
	CallBackFunctEXTI_LINE[Copy_ExtiLine] = ptrfunc ; 
}

void EXTI0_IRQHandler(void)
{
	CallBackFunctEXTI_LINE[0]() ;
	/* Clear Pending Flag */ 
	SET_BIT(EXTI->PR,EXTI_LINE_0) ; 
}
void EXTI1_IRQHandler(void)
{
	CallBackFunctEXTI_LINE[1]() ;
	/* Clear Pending Flag */ 
    SET_BIT(EXTI->PR,EXTI_LINE_1) ;	
}
void EXTI2_IRQHandler(void)
{
	CallBackFunctEXTI_LINE[2]() ;
	/* Clear Pending Flag */ 
	SET_BIT(EXTI->PR,EXTI_LINE_2) ;	
}
void EXTI3_IRQHandler(void)
{
	CallBackFunctEXTI_LINE[3]() ;
	/* Clear Pending Flag */ 
	SET_BIT(EXTI->PR,EXTI_LINE_3) ;	
}
void EXTI4_IRQHandler(void)
{
	CallBackFunctEXTI_LINE[4]() ;
	/* Clear Pending Flag */ 
    SET_BIT(EXTI->PR,EXTI_LINE_4) ;		
}
EXTI9_5_IRQHandler(void)
{
	
}
EXTI15_10_IRQHandler(void)
{
	
}
