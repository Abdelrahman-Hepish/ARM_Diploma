/*************************************************************************/
/* Author        : Abdelrahman Hepish                                    */
/* File          : DMA_program.c                                         */
/* Date          : 30 MARCH 2022                                         */
/* Version       : V01                                                   */
/* GitHub        : https://github.com/Abdelrahman-Hepish                 */
/*************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DMA_interface.h"
#include "DMA_private.h"
#include "DMA_config.h"
static void DMA_voidInitChannel(DMA_ChannelConfig Channel) ; 
void DMA_voidInit(void) 
{
    for(u8 i = 0 ;i<7;i++)
    {
        DMA_voidInitChannel(CHANNELS[i]) ; 
    }
}

static void DMA_voidInitChannel(DMA_ChannelConfig Channel) 
{
    /* Init Memory to Memroy State */ 
   MAN_BIT( DMA ->CHANNEL_t[Channel.channelId] ,14,Channel.m2mState) ;
   MAN_BIT(DMA ->CHANNEL_t[Channel.channelId],BIT,_1BIT_VAL)
}