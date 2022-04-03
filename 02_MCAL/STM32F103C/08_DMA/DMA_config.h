/*************************************************************************/
/* Author        : Abdelrahman Hepish                                    */
/* File          : DMA_config.h                                          */
/* Date          : 30 MARCH 2022                                         */
/* Version       : V01                                                   */
/* GitHub        : https://github.com/Abdelrahman-Hepish                 */
/*************************************************************************/
#ifndef __DMA_CONFIG_H__
#define __DMA_CONFIG_H__
/* MEM2MEM: Memory to memory mode */ 
#define MEM2MEM_DISABLED        0
#define MEM2MEM_ENABLED         1 
/* PL: Channel priority level */ 
#define PRIORITY_LEVEL_LOW          0
#define PRIORITY_LEVEL_MEDIUM       1
#define PRIORITY_LEVEL_HIGH         2
#define PRIORITY_LEVEL_VERY_HIGH    3
/* MSIZE: Memory size */ 
#define WIDTH_MSIZE_8BIT            0
#define WIDTH_MSIZE_16BIT           1
#define WIDTH_MSIZE_32BIT           2 
/* PSIZE: Peripheral size */ 	
#define WIDTH_PSIZE_8BIT            0
#define WIDTH_PSIZE_16BIT           1
#define WIDTH_PSIZE_32BIT           2
/* MINC: Memory increment mode */ 
#define MINC_DISABLED	            0
#define MINC_ENABLED                1
/* PINC: Peripheral increment mode */ 
#define PINC_DISABLED	            0
#define PINC_ENABLED                1
/* CIRC: Circular mode */ 
#define CIRC_DISABLED	            0
#define CIRC_ENABLED                1
/* DIR: Data transfer direction */ 
#define DATA_TX_FROM_PERIPHERAL     0 
#define DATA_TX_FROM_MEMORY         1
/* TEIE: Transfer error interrupt enable */ 
#define TE_INTERRUPT_DISABLED       0
#define TE_INTERRUPT_ENABLED        1
/* HTIE: Half transfer interrupt enable */ 
#define HT_INTERRUPT_DISABLED       0
#define HT_INTERRUPT_ENABLED        1
/* TCIE: Transfer complete interrupt enable */
#define TC_INTERRUPT_DISABLED       0
#define TC_INTERRUPT_ENABLED        1
/* EN: Channel enable */ 
#define CHANNEL_DISABLED            0
#define CHANNEL_ENABLED             1



/* --------------- Channel 0 configuration ----------------- */ 
#define CHANNEL_0_MEM2MEM_STATE   MEM2MEM_ENABLED        
#define CHANNEL_0_PRIORITY_LEVEL  PRIORITY_LEVEL_MEDIUM   
#define CHANNEL_0_MSIZE           WIDTH_MSIZE_32BIT       
#define CHANNEL_0_PSIZE           WIDTH_PSIZE_32BIT       
#define CHANNEL_0_MINC_STATE      MINC_ENABLED
#define CHANNEL_0_PINC_STATE      PINC_ENABLED
#define CHANNEL_0_CIRC_STATE      CIRC_DISABLED
#define CHANNEL_0_DIR             DATA_TX_FROM_MEMORY
#define CHANNEL_0_TEIE_STATE      TE_INTERRUPT_DISABLED
#define CHANNEL_0_HTIE_STATE      HT_INTERRUPT_DISABLED
#define CHANNEL_0_TCIE_STATE      TC_INTERRUPT_DISABLED
#define CHANNEL_0_STATE           CHANNEL_ENABLED
/* --------------------------------------------------------- */ 

/* --------------- Channel 1 configuration ----------------- */ 
#define CHANNEL_1_MEM2MEM_STATE   MEM2MEM_ENABLED        
#define CHANNEL_1_PRIORITY_LEVEL  PRIORITY_LEVEL_MEDIUM   
#define CHANNEL_1_MSIZE           WIDTH_MSIZE_32BIT       
#define CHANNEL_1_PSIZE           WIDTH_PSIZE_32BIT       
#define CHANNEL_1_MINC_STATE      MINC_ENABLED
#define CHANNEL_1_PINC_STATE      PINC_ENABLED
#define CHANNEL_1_CIRC_STATE      CIRC_DISABLED
#define CHANNEL_1_DIR             DATA_TX_FROM_MEMORY
#define CHANNEL_1_TEIE_STATE      TE_INTERRUPT_DISABLED
#define CHANNEL_1_HTIE_STATE      HT_INTERRUPT_DISABLED
#define CHANNEL_1_TCIE_STATE      TC_INTERRUPT_DISABLED
#define CHANNEL_1_STATE           CHANNEL_DISABLED
/* --------------------------------------------------------- */

/* --------------- Channel 2 configuration ----------------- */ 
#define CHANNEL_2_MEM2MEM_STATE   MEM2MEM_ENABLED        
#define CHANNEL_2_PRIORITY_LEVEL  PRIORITY_LEVEL_MEDIUM   
#define CHANNEL_2_MSIZE           WIDTH_MSIZE_32BIT       
#define CHANNEL_2_PSIZE           WIDTH_PSIZE_32BIT       
#define CHANNEL_2_MINC_STATE      MINC_ENABLED
#define CHANNEL_2_PINC_STATE      PINC_ENABLED
#define CHANNEL_2_CIRC_STATE      CIRC_DISABLED
#define CHANNEL_2_DIR             DATA_TX_FROM_MEMORY
#define CHANNEL_2_TEIE_STATE      TE_INTERRUPT_DISABLED
#define CHANNEL_2_HTIE_STATE      HT_INTERRUPT_DISABLED
#define CHANNEL_2_TCIE_STATE      TC_INTERRUPT_DISABLED
#define CHANNEL_2_STATE           CHANNEL_DISABLED
/* --------------------------------------------------------- */ 

/* --------------- Channel 3 configuration ----------------- */ 
#define CHANNEL_3_MEM2MEM_STATE   MEM2MEM_ENABLED        
#define CHANNEL_3_PRIORITY_LEVEL  PRIORITY_LEVEL_MEDIUM   
#define CHANNEL_3_MSIZE           WIDTH_MSIZE_32BIT       
#define CHANNEL_3_PSIZE           WIDTH_PSIZE_32BIT       
#define CHANNEL_3_MINC_STATE      MINC_ENABLED
#define CHANNEL_3_PINC_STATE      PINC_ENABLED
#define CHANNEL_3_CIRC_STATE      CIRC_DISABLED
#define CHANNEL_3_DIR             DATA_TX_FROM_MEMORY
#define CHANNEL_3_TEIE_STATE      TE_INTERRUPT_DISABLED
#define CHANNEL_3_HTIE_STATE      HT_INTERRUPT_DISABLED
#define CHANNEL_3_TCIE_STATE      TC_INTERRUPT_DISABLED
#define CHANNEL_3_STATE           CHANNEL_DISABLED
/* --------------------------------------------------------- */

/* --------------- Channel 4 configuration ----------------- */ 
#define CHANNEL_4_MEM2MEM_STATE   MEM2MEM_ENABLED        
#define CHANNEL_4_PRIORITY_LEVEL  PRIORITY_LEVEL_MEDIUM   
#define CHANNEL_4_MSIZE           WIDTH_MSIZE_32BIT       
#define CHANNEL_4_PSIZE           WIDTH_PSIZE_32BIT       
#define CHANNEL_4_MINC_STATE      MINC_ENABLED
#define CHANNEL_4_PINC_STATE      PINC_ENABLED
#define CHANNEL_4_CIRC_STATE      CIRC_DISABLED
#define CHANNEL_4_DIR             DATA_TX_FROM_MEMORY
#define CHANNEL_4_TEIE_STATE      TE_INTERRUPT_DISABLED
#define CHANNEL_4_HTIE_STATE      HT_INTERRUPT_DISABLED
#define CHANNEL_4_TCIE_STATE      TC_INTERRUPT_DISABLED
#define CHANNEL_4_STATE           CHANNEL_DISABLED
/* --------------------------------------------------------- */ 

/* --------------- Channel 5 configuration ----------------- */ 
#define CHANNEL_5_MEM2MEM_STATE   MEM2MEM_ENABLED        
#define CHANNEL_5_PRIORITY_LEVEL  PRIORITY_LEVEL_MEDIUM   
#define CHANNEL_5_MSIZE           WIDTH_MSIZE_32BIT       
#define CHANNEL_5_PSIZE           WIDTH_PSIZE_32BIT       
#define CHANNEL_5_MINC_STATE      MINC_ENABLED
#define CHANNEL_5_PINC_STATE      PINC_ENABLED
#define CHANNEL_5_CIRC_STATE      CIRC_DISABLED
#define CHANNEL_5_DIR             DATA_TX_FROM_MEMORY
#define CHANNEL_5_TEIE_STATE      TE_INTERRUPT_DISABLED
#define CHANNEL_5_HTIE_STATE      HT_INTERRUPT_DISABLED
#define CHANNEL_5_TCIE_STATE      TC_INTERRUPT_DISABLED
#define CHANNEL_5_STATE           CHANNEL_DISABLED
/* --------------------------------------------------------- */

/* --------------- Channel 6 configuration ----------------- */ 
#define CHANNEL_6_MEM2MEM_STATE   MEM2MEM_ENABLED        
#define CHANNEL_6_PRIORITY_LEVEL  PRIORITY_LEVEL_MEDIUM   
#define CHANNEL_6_MSIZE           WIDTH_MSIZE_32BIT       
#define CHANNEL_6_PSIZE           WIDTH_PSIZE_32BIT       
#define CHANNEL_6_MINC_STATE      MINC_ENABLED
#define CHANNEL_6_PINC_STATE      PINC_ENABLED
#define CHANNEL_6_CIRC_STATE      CIRC_DISABLED
#define CHANNEL_6_DIR             DATA_TX_FROM_MEMORY
#define CHANNEL_6_TEIE_STATE      TE_INTERRUPT_DISABLED
#define CHANNEL_6_HTIE_STATE      HT_INTERRUPT_DISABLED
#define CHANNEL_6_TCIE_STATE      TC_INTERRUPT_DISABLED
#define CHANNEL_6_STATE           CHANNEL_DISABLED
/* --------------------------------------------------------- */ 

/* --------------- Channel 7 configuration ----------------- */ 
#define CHANNEL_7_MEM2MEM_STATE   MEM2MEM_ENABLED        
#define CHANNEL_7_PRIORITY_LEVEL  PRIORITY_LEVEL_MEDIUM   
#define CHANNEL_7_MSIZE           WIDTH_MSIZE_32BIT       
#define CHANNEL_7_PSIZE           WIDTH_PSIZE_32BIT       
#define CHANNEL_7_MINC_STATE      MINC_ENABLED
#define CHANNEL_7_PINC_STATE      PINC_ENABLED
#define CHANNEL_7_CIRC_STATE      CIRC_DISABLED
#define CHANNEL_7_DIR             DATA_TX_FROM_MEMORY
#define CHANNEL_7_TEIE_STATE      TE_INTERRUPT_DISABLED
#define CHANNEL_7_HTIE_STATE      HT_INTERRUPT_DISABLED
#define CHANNEL_7_TCIE_STATE      TC_INTERRUPT_DISABLED
#define CHANNEL_7_STATE           CHANNEL_DISABLED
/* --------------------------------------------------------- */

DMA_ChannelConfig CHANNELS[7] ; 
/* --------------- Channel 0 configuration ----------------- */ 
CHANNEL[0].channelId       =  0 ; 
CHANNEL[0].channelState    =  CHANNEL_DISABLED ; 
CHANNEL[0].m2mState        =  MEM2MEM_ENABLED ; 
CHANNEL[0].plState         =  PRIORITY_LEVEL_MEDIUM ; 
CHANNEL[0].mwidthSize      =  WIDTH_MSIZE_32BIT ; 
CHANNEL[0].pwidthSize      =  WIDTH_PSIZE_32BIT ; 
CHANNEL[0].memIncMode      =  MINC_ENABLED ; 
CHANNEL[0].perIncMode      =  PINC_ENABLED ; 
CHANNEL[0].circMode        =  CIRC_DISABLED ; 
CHANNEL[0].dataTxDir       =  DATA_TX_FROM_MEMORY ; 
CHANNEL[0].transErrInt     =  TE_INTERRUPT_DISABLED ; 
CHANNEL[0].htransErrInt    =  HT_INTERRUPT_DISABLED ; 
CHANNEL[0].transCompInt    =  TC_INTERRUPT_DISABLED ; 
/* --------------------------------------------------------- */

/* --------------- Channel 1 configuration ----------------- */ 
CHANNEL[1].channelId       =  1 ; 
CHANNEL[1].channelState    =  CHANNEL_DISABLED ; 
CHANNEL[1].m2mState        =  MEM2MEM_ENABLED ; 
CHANNEL[1].plState         =  PRIORITY_LEVEL_MEDIUM ; 
CHANNEL[1].mwidthSize      =  WIDTH_MSIZE_32BIT ; 
CHANNEL[1].pwidthSize      =  WIDTH_PSIZE_32BIT ; 
CHANNEL[1].memIncMode      =  MINC_ENABLED ; 
CHANNEL[1].perIncMode      =  PINC_ENABLED ; 
CHANNEL[1].circMode        =  CIRC_DISABLED ; 
CHANNEL[1].dataTxDir       =  DATA_TX_FROM_MEMORY ; 
CHANNEL[1].transErrInt     =  TE_INTERRUPT_DISABLED ; 
CHANNEL[1].htransErrInt    =  HT_INTERRUPT_DISABLED ; 
CHANNEL[1].transCompInt    =  TC_INTERRUPT_DISABLED ;
/* --------------------------------------------------------- */

/* --------------- Channel 2 configuration ----------------- */ 
CHANNEL[2].channelId       =  2 ; 
CHANNEL[2].channelState    =  CHANNEL_DISABLED ; 
CHANNEL[2].m2mState        =  MEM2MEM_ENABLED ; 
CHANNEL[2].plState         =  PRIORITY_LEVEL_MEDIUM ; 
CHANNEL[2].mwidthSize      =  WIDTH_MSIZE_32BIT ; 
CHANNEL[2].pwidthSize      =  WIDTH_PSIZE_32BIT ; 
CHANNEL[2].memIncMode      =  MINC_ENABLED ; 
CHANNEL[2].perIncMode      =  PINC_ENABLED ; 
CHANNEL[2].circMode        =  CIRC_DISABLED ; 
CHANNEL[2].dataTxDir       =  DATA_TX_FROM_MEMORY ; 
CHANNEL[2].transErrInt     =  TE_INTERRUPT_DISABLED ; 
CHANNEL[2].htransErrInt    =  HT_INTERRUPT_DISABLED ; 
CHANNEL[2].transCompInt    =  TC_INTERRUPT_DISABLED ; 
/* --------------------------------------------------------- */

/* --------------- Channel 3 configuration ----------------- */ 
CHANNEL[3].channelId       =  3 ; 
CHANNEL[3].channelState    =  CHANNEL_DISABLED ; 
CHANNEL[3].m2mState        =  MEM2MEM_ENABLED ; 
CHANNEL[3].plState         =  PRIORITY_LEVEL_MEDIUM ; 
CHANNEL[3].mwidthSize      =  WIDTH_MSIZE_32BIT ; 
CHANNEL[3].pwidthSize      =  WIDTH_PSIZE_32BIT ; 
CHANNEL[3].memIncMode      =  MINC_ENABLED ; 
CHANNEL[3].perIncMode      =  PINC_ENABLED ; 
CHANNEL[3].circMode        =  CIRC_DISABLED ; 
CHANNEL[3].dataTxDir       =  DATA_TX_FROM_MEMORY ; 
CHANNEL[3].transErrInt     =  TE_INTERRUPT_DISABLED ; 
CHANNEL[3].htransErrInt    =  HT_INTERRUPT_DISABLED ; 
CHANNEL[3].transCompInt    =  TC_INTERRUPT_DISABLED ;
/* --------------------------------------------------------- */

/* --------------- Channel 4 configuration ----------------- */ 
CHANNEL[4].channelId       =  4 ; 
CHANNEL[4].channelState    =  CHANNEL_DISABLED ; 
CHANNEL[4].m2mState        =  MEM2MEM_ENABLED ; 
CHANNEL[4].plState         =  PRIORITY_LEVEL_MEDIUM ; 
CHANNEL[4].mwidthSize      =  WIDTH_MSIZE_32BIT ; 
CHANNEL[4].pwidthSize      =  WIDTH_PSIZE_32BIT ; 
CHANNEL[4].memIncMode      =  MINC_ENABLED ; 
CHANNEL[4].perIncMode      =  PINC_ENABLED ; 
CHANNEL[4].circMode        =  CIRC_DISABLED ; 
CHANNEL[4].dataTxDir       =  DATA_TX_FROM_MEMORY ; 
CHANNEL[4].transErrInt     =  TE_INTERRUPT_DISABLED ; 
CHANNEL[4].htransErrInt    =  HT_INTERRUPT_DISABLED ; 
CHANNEL[4].transCompInt    =  TC_INTERRUPT_DISABLED ; 
/* --------------------------------------------------------- */

/* --------------- Channel 5 configuration ----------------- */ 
CHANNEL[5].channelId       =  5 ; 
CHANNEL[5].channelState    =  CHANNEL_DISABLED ; 
CHANNEL[5].m2mState        =  MEM2MEM_ENABLED ; 
CHANNEL[5].plState         =  PRIORITY_LEVEL_MEDIUM ; 
CHANNEL[5].mwidthSize      =  WIDTH_MSIZE_32BIT ; 
CHANNEL[5].pwidthSize      =  WIDTH_PSIZE_32BIT ; 
CHANNEL[5].memIncMode      =  MINC_ENABLED ; 
CHANNEL[5].perIncMode      =  PINC_ENABLED ; 
CHANNEL[5].circMode        =  CIRC_DISABLED ; 
CHANNEL[5].dataTxDir       =  DATA_TX_FROM_MEMORY ; 
CHANNEL[5].transErrInt     =  TE_INTERRUPT_DISABLED ; 
CHANNEL[5].htransErrInt    =  HT_INTERRUPT_DISABLED ; 
CHANNEL[5].transCompInt    =  TC_INTERRUPT_DISABLED ;
/* --------------------------------------------------------- */

/* --------------- Channel 6 configuration ----------------- */ 
CHANNEL[6].channelId       =  6 ; 
CHANNEL[6].channelState    =  CHANNEL_DISABLED ; 
CHANNEL[6].m2mState        =  MEM2MEM_ENABLED ; 
CHANNEL[6].plState         =  PRIORITY_LEVEL_MEDIUM ; 
CHANNEL[6].mwidthSize      =  WIDTH_MSIZE_32BIT ; 
CHANNEL[6].pwidthSize      =  WIDTH_PSIZE_32BIT ; 
CHANNEL[6].memIncMode      =  MINC_ENABLED ; 
CHANNEL[6].perIncMode      =  PINC_ENABLED ; 
CHANNEL[6].circMode        =  CIRC_DISABLED ; 
CHANNEL[6].dataTxDir       =  DATA_TX_FROM_MEMORY ; 
CHANNEL[6].transErrInt     =  TE_INTERRUPT_DISABLED ; 
CHANNEL[6].htransErrInt    =  HT_INTERRUPT_DISABLED ; 
CHANNEL[6].transCompInt    =  TC_INTERRUPT_DISABLED ; 
/* --------------------------------------------------------- */

                                                      
                                                              
                                                                              
                                                                              
                                                                              
                                                                              
                                                              
                                                              
                                                              
                                                              
                                                              
                                                              
                                                              
                                                              
#endif  // __DMA_CONFIG_H__