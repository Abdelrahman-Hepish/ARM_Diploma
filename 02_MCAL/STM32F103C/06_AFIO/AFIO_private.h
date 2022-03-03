/*************************************************************************/
/* Author        : Abdelrahman Hepish                                    */
/* File          : AFIO_private.h                                        */
/* Date          : 12 DEC 2021                                           */
/* Version       : V01                                                   */
/* GitHub        : https://github.com/Abdelrahman-Hepish                 */
/*************************************************************************/
#ifndef __AFIO_PRIVATE_H__
#define __AFIO_PRIVATE_H__

#define AFIO_BASE_ADDRESS 0x40010000
typedef struct
{
 volatile u32  EVCR    ; 
 volatile u32  MAPR    ; 
 volatile u32  EXTICR[4] ; 
 volatile u32  MAPR2   ; 
}tAFIO ; 
#define AFIO ((tAFIO *) AFIO_BASE_ADDRESS )
              
			 
#endif  // __AFIO_PRIVATE_H__
