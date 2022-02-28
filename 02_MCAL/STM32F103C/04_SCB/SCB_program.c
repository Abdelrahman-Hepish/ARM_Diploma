/*************************************************************************/
/* Author        : Abdelrahman Hepish                                    */
/* File          : SCB_program.c                                         */
/* Date          : 11 DEC 2021                                           */
/* Version       : V01                                                   */
/* GitHub        : https://github.com/Abdelrahman-Hepish                 */
/*************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "SCB_interface.h"
#include "SCB_private.h"
#include "SCB_config.h"

void SCB_SetInterruptGroupingSystem(tSCB_InterruptGroupSys Copy_u32SysGrp) 
{
	SCB_AIRCR = Copy_u32SysGrp ; 
}
