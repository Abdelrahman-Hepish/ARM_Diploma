/*************************************************************************/
/* Author        : Abdelrahman Hepish                                    */
/* File          : DMA_private.h                                         */
/* Date          : 30 MARCH 2022                                         */
/* Version       : V01                                                   */
/* GitHub        : https://github.com/Abdelrahman-Hepish                 */
/*************************************************************************/
#ifndef __DMA_PRIVATE_H__
#define __DMA_PRIVATE_H__
typedef struct
{
	u32 CCR       ; 
	u32 CNDTR     ;
    u32 CPAR      ; 
    u32 CPAR      ; 
	u32 CMAR      ; 
	u32 RESERVED  ; 
}CHANNEL_t; 	
typedef struct 
{
	u32 ISR ; 
	u32 IFCR ; 
	u32 CHANNEL_t [7] ; 
}DMA_t ; 

#define DMA ((volatile DMA_t *)0x40020000)   	
			
#endif  // __DMA_PRIVATE_H__