/*************************************************************************/
/* Author        : Abdelrahman Hepish                                    */
/* File          : SCHEDULER_program.c                                   */
/* Date          : 24 MARCH 2021                                         */
/* Version       : V01                                                   */
/* GitHub        : https://github.com/Abdelrahman-Hepish                 */
/*************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "SCHEDULER_interface.h"
#include "SCHEDULER_private.h"
#include "SCHEDULER_config.h"
#include "STK_interface.h"
#define _1_ms_TICKS    1000000
typedef 
void (*ptrfucAlgorithm) (void) = ((void*) 0) ; 
void SCHEDULER_voidInit(void) 
{
	STK_voidInit(STK_ENABLED,STK_CLKSRC_AHB_BY_8,STK_INT_ENABLE) ; 
	STK_voidSetIntervalPeriodic(_1_ms_TICKS,) ;