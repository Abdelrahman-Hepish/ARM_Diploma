/*************************************************************************/
/* Author        : Abdelrahman Hepish                                    */
/* File          : DAC_program.c                                         */
/* Date          : 27 MARCH 2022                                         */
/* Version       : V01                                                   */
/* GitHub        : https://github.com/Abdelrahman-Hepish                 */
/*************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DAC_interface.h"
#include "DAC_private.h"
#include "DAC_config.h"
#include "SONG.h"
#include "STK_interface.h" 
#include "GPIO_interface.h"
static void DAC(void) ; 
u32 currentSample ; 

void DAC_voidInit(void) 
{
	u32 sampleTicks = 1000000 / AUDIO_RATE ; 
	STK_voidInit(STK_ENABLED,STK_CLKSRC_AHB_BY_8,STK_INT_ENABLE) ;
	GPIO_voidInitByte(DAC_PORT,DAC_BYTE,PIN_NM_OUTPUT_2MHZ,0X00) ;
	STK_voidSetIntervalPeriodic(sampleTicks,DAC) ;
}
static void DAC(void)
{
	GPIO_voidSetByteState(DAC_PORT,DAC_BYTE,Song_raw[currentSample]) ;
	currentSample = (currentSample+1)%AUDIO_SIZE ;
}