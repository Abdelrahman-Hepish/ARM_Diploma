/*************************************************************************/
/* Author        : Abdelrahman Hepish                                    */
/* File          : DAC_program.c                                         */
/* Date          : 27 MARCH 2022                                         */
/* Version       : V01                                                   */
/* GitHub        : https://github.com/Abdelrahman-Hepish                 */
/*************************************************************************/
#include "..\..\..\01_LIB\01_STD_TYPES\STD_TYPES.h"
#include "..\..\..\01_LIB\02_BIT_MATH\BIT_MATH.h"
#include "..\..\..\03_HAL\05_DAC\DAC_interface.h"
#include "..\..\..\03_HAL\05_DAC\DAC_private.h"
#include "..\..\..\03_HAL\05_DAC\DAC_config.h"
#include "..\..\..\02_MCAL\STM32F103C\07_STK\STK_interface.h"
#include "..\..\..\02_MCAL\STM32F103C\02_GPIO\GPIO_interface.h"
#include "..\..\..\03_HAL\05_DAC\SONG.h"
static void DAC(void) ; 
u32 currentSample ; 

void DAC_voidInit(void) 
{
	u32 sampleTicks = 1000000 / AUDIO_RATE ; 
	STK_voidInit(STK_ENABLED,STK_CLKSRC_AHB_BY_8,STK_INT_ENABLE) ;
	GPIO_voidInitByte(DAC_PORT,DAC_BYTE,PIN_NM_OUTPUT_2MHZ,0X00) ;
	STK_voidSetIntervalPeriodic(125,DAC) ;
}
static void DAC(void)
{
	GPIO_voidSetByteState(DAC_PORT,DAC_BYTE,Song_raw[currentSample]) ;
	currentSample = (currentSample+1)%AUDIO_SIZE ;
}
