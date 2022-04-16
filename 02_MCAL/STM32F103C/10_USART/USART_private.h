/*************************************************************************/
/* Author        : Abdelrahman Hepish                                    */
/* File          : USART_private.h                                       */
/* Date          : 16 APRIL 2022                                         */
/* Version       : V01                                                   */
/* GitHub        : https://github.com/Abdelrahman-Hepish                 */
/*************************************************************************/
#ifndef __USART_PRIVATE_H__
#define __USART_PRIVATE_H__
typedef struct 
{
   volatile u32 SR   ; 
   volatile u32 DR   ; 
   volatile u32 BRR  ; 
   volatile u32 CR1  ; 
   volatile u32 CR2  ; 
   volatile u32 CR3  ; 
   volatile u32 GTPR ; 
}USART_T ; 

#define USART1 ((volatile USART_T * ) 0x40013800)
		
#endif  // __USART_PRIVATE_H__