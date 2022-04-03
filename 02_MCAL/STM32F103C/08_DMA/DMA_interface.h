/*************************************************************************/
/* Author        : Abdelrahman Hepish                                    */
/* File          : DMA_interface.h                                       */
/* Date          : 30 MARCH 2022                                         */
/* Version       : V01                                                   */
/* GitHub        : https://github.com/Abdelrahman-Hepish                 */
/*************************************************************************/
#ifndef __DMA_INTERFACE_H__
#define __DMA_INTERFACE_H__
/* MEM2MEM: Memory to memory mode */ 
typedef enum
{
    MEM2MEM_DISABLED = 0 , 
    MEM2MEM_ENABLED  
}CH_DMA_M2M_S ; 
/* PL: Channel priority level */ 
typedef enum 
{
   PRIORITY_LEVEL_LOW             , 
   PRIORITY_LEVEL_MEDIUM          , 
   PRIORITY_LEVEL_HIGH            , 
   PRIORITY_LEVEL_VERY_HIGH 
}CH_DMA_PL ;
/* MSIZE: Memory size */ 
typedef enum 
{
  WIDTH_MSIZE_8BIT     , 
  WIDTH_MSIZE_16BIT    , 
  WIDTH_MSIZE_32BIT    , 
}CH_DMA_MEM_W ; 
/* PSIZE: Peripheral size */ 
typedef enum
{
  WIDTH_PSIZE_8BIT     , 
  WIDTH_PSIZE_16BIT    , 
  WIDTH_PSIZE_32BIT
}CH_DMA_PER_W ;
/* MINC: Memory increment mode */ 
typedef enum 
{
  MINC_DISABLED        , 
  MINC_ENABLED      
}CH_DMA_MINC_S ;  
/* PINC: Peripheral increment mode */ 
typedef enum 
{
  PINC_DISABLED        , 
  PINC_ENABLED      
}CH_DMA_PINC_S ;
/* CIRC: Circular mode */ 
typedef enum 
{
  CIRC_DISABLED	 , 
  CIRC_ENABLED   
}CH_DMA_CIRC_S ; 
/* DIR: Data transfer direction */ 
typedef enum 
{
  DATA_TX_FROM_PERIPHERAL  و 
  DATA_TX_FROM_MEMORY       
}CH_DMA_TD ;
/* TEIE: Transfer error interrupt enable */ 
typedef enum 
{
   TE_INTERRUPT_DISABLED    , 
   TE_INTERRUPT_ENABLED 
} CH_DMA_TEI_S ; 
/* HTIE: Half transfer interrupt enable */
typedef enum 
{
   HT_INTERRUPT_DISABLED    , 
   HT_INTERRUPT_ENABLED 
} CH_DMA_HTI_S ;
/* TCIE: Transfer complete interrupt enable */ 
typedef enum 
{
   TC_INTERRUPT_DISABLED    , 
   TC_INTERRUPT_ENABLED 
} CH_DMA_TCI_S ; 
typedef enum 
{
  CHANNEL_DISABLED , 
  CHANNEL_ENABLED  
}Ch_DMA_State ; 
typedef struct 
{
    unsigned u8            channelId      : 3 ; 
    unsigned Ch_DMA_State  channelState   : 1 ; 
    unsigned CH_DMA_M2M_S  m2mState       : 1 ; 
    unsigned CH_DMA_PL     plState        : 2 ; 
    unsigned CH_DMA_MEM_W  mwidthSize     : 2 ; 
    unsigned CH_DMA_PER_W  pwidthSize     : 2 ;  
    unsigned CH_DMA_MINC_S memIncMode     : 1 ;
    unsigned CH_DMA_PINC_S perIncMode     : 1 ; 
    unsigned CH_DMA_CIRC_S circMode       : 1 ; 
    unsigned CH_DMA_TD     dataTxDir      : 1 ; 
    unsigned CH_DMA_TEI_S  transErrInt    : 1 ; 
    unsigned CH_DMA_HTI_S  htransErrInt   : 1 ; 
    unsigned CH_DMA_TCI_S  transCompInt   : 1 ; 
}DMA_ChannelConfig;

void DMA_voidInit(void) ; 	
	
#endif  // __DMA_INTERFACE_H__