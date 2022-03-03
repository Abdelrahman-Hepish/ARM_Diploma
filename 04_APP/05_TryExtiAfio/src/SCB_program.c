/*************************************************************************/
/* Author        : Abdelrahman Hepish                                    */
/* File          : SCB_program.c                                         */
/* Date          : 11 DEC 2021                                           */
/* Version       : V01                                                   */
/* GitHub        : https://github.com/Abdelrahman-Hepish                 */
/*************************************************************************/
#include "..\..\..\01_LIB\01_STD_TYPES\STD_TYPES.h"
#include "..\..\..\01_LIB\02_BIT_MATH\BIT_MATH.h"
#include "..\..\..\02_MCAL\STM32F103C\04_SCB\SCB_interface.h"
#include "..\..\..\02_MCAL\STM32F103C\04_SCB\SCB_config.h"
#include "..\..\..\02_MCAL\STM32F103C\04_SCB\SCB_private.h"

void SCB_SetInterruptGroupingSystem(tSCB_InterruptGroupSys Copy_u32SysGrp) 
{
	SCB_AIRCR = Copy_u32SysGrp ; 
}
