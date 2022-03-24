/*************************************************************************/
/* Author        : Abdelrahman Hepish                                    */
/* File          :                                                       */
/* Date          : 14 DEC 2021                                           */
/* Version       : V01                                                   */
/* GitHub        : https://github.com/Abdelrahman-Hepish                 */
/*************************************************************************/
#include "..\..\..\01_LIB\01_STD_TYPES\STD_TYPES.h"
#include "..\..\..\01_LIB\02_BIT_MATH\BIT_MATH.h"
#include "..\..\..\02_MCAL\STM32F103C\07_STK\STK_interface.h"
#include "..\..\..\02_MCAL\STM32F103C\07_STK\STK_private.h"
#include "..\..\..\02_MCAL\STM32F103C\07_STK\STK_config.h"

typedef enum
{
    DELAY_MS_TIME  ,
	BUSY_WAITH_TICKS ,
	SET_INTERVAL_SINGLE ,
	SET_INTERVAL_PERIODIC
}tSTK_RUNNING_FUNCMODE ;

u32 DelayTime ;
tSTK_RUNNING_FUNCMODE CurrentRunningMode = DELAY_MS_TIME ;
static void(*MSTK_CallBack)(void);
void STK_voidInit(tSTK_State Copy_u8STK_State,tSTK_ClockSource Copy_u8STK_ClkSrc,tSTK_InterruptState Copy_u8STK_IntState) 
{
     MAN_BIT(STK_CTRL,STK_ENABLE_BIT,Copy_u8STK_State) ;
	 MAN_BIT(STK_CTRL,STK_TICKINT_BIT,Copy_u8STK_IntState) ;   
	 MAN_BIT(STK_CTRL,STK_CLKSOURCE_BIT,Copy_u8STK_ClkSrc) ;
		STK_VAL  = 0 ;
		STK_LOAD = 0 ;
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
void Delay_ms(u32 Copy_u8DelayTime)
{
	CurrentRunningMode = DELAY_MS_TIME ;
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
void STK_BusyWaitTicks(u32 Copy_u32NumberofTicks)
{
	MAN_BIT(STK_CTRL,STK_TICKINT_BIT,STK_INT_DISABLE) ;
	STK_LOAD = Copy_u32NumberofTicks ;
	MAN_BIT(STK_CTRL,STK_ENABLE_BIT,STK_ENABLED) ;
	/* Polling */
	while(GET_BIT(STK_CTRL,STK_COUNTFLAG_BIT) == 0 ) ;
	MAN_BIT(STK_CTRL,STK_ENABLE_BIT,STK_DISABLED) ;
	STK_LOAD = 0 ; STK_VAL = 0 ;
}
void STK_voidSetIntervalSingle(u32 Copy_u32NumberofTicks,void (*ptrfunc)(void))
{

	/* Clear Current SysTick if running */
	STK_VAL  = 0 ;
	MAN_BIT(STK_CTRL,STK_ENABLE_BIT,STK_DISABLED) ;

	STK_LOAD = Copy_u32NumberofTicks ;

	/* Make sure Timer & interrupt are working */
	MAN_BIT(STK_CTRL,STK_ENABLE_BIT,STK_ENABLED) ;
	MAN_BIT(STK_CTRL,STK_TICKINT_BIT,STK_INT_ENABLE) ;
	CurrentRunningMode = SET_INTERVAL_SINGLE ;
	MSTK_CallBack = ptrfunc ;
	MAN_BIT(STK_CTRL,STK_TICKINT_BIT,STK_INT_ENABLE) ;
}
void STK_voidSetIntervalPeriodic(u32 Copy_u32NumberofTicks,void (*ptrfunc)(void))
{
	MSTK_CallBack = ptrfunc ;
	CurrentRunningMode = SET_INTERVAL_PERIODIC ;
	STK_LOAD = Copy_u32NumberofTicks ;
}
u32  STK_u32GetElapsedTicks(void)
{
	return STK_LOAD - STK_VAL ;
}
u32  STK_u32GetRemainningTicks(void)
{
	return STK_VAL ;
}
void SysTick_Handler(void)
{
	if(CurrentRunningMode == DELAY_MS_TIME)
	{
		DelayTime -- ;
		if(DelayTime == 0 )
		{
			STK_LOAD = 0 ;
			MAN_BIT(STK_CTRL,STK_ENABLE_BIT,STK_DISABLED) ;
			MAN_BIT(STK_CTRL,STK_TICKINT_BIT,STK_INT_DISABLE) ;
		}
	}else if (CurrentRunningMode == SET_INTERVAL_SINGLE)
	{
		MSTK_CallBack() ;
		STK_LOAD = 0 ;
		MAN_BIT(STK_CTRL,STK_ENABLE_BIT,STK_DISABLED) ;
		MAN_BIT(STK_CTRL,STK_TICKINT_BIT,STK_INT_DISABLE) ;
	}else if (CurrentRunningMode == SET_INTERVAL_PERIODIC)
	{
		MSTK_CallBack() ;
	}
	/* Flag Clearence */
	GET_BIT(STK_CTRL,STK_COUNTFLAG_BIT) ; 
}
