/*************************************************************************/
/* Author        : Abdelrahman Hepish                                    */
/* File          : EXTI_private.h                                        */
/* Date          : 11 DEC 2021                                           */
/* Version       : V01                                                   */
/* GitHub        : https://github.com/Abdelrahman-Hepish                 */
/*************************************************************************/
#ifndef __EXTI_PRIVATE_H__
#define __EXTI_PRIVATE_H__

#define EXTI_BASE_ADDRESS 0x40010400 
typedef enum 
{
	volatile u32 IMR ; 
    volatile u32 EMR ; 
    volatile u32 RTSR ;
    volatile u32 FTSR ;
    volatile u32 SWIER ; 
    volatile u32 PR ; 
}tEXTI_REG ; 

#define EXTI ((volatile tEXTI_REG *)  EXTI_BASE_ADDRESS ) 
		
#endif  __EXTI_PRIVATE_H__