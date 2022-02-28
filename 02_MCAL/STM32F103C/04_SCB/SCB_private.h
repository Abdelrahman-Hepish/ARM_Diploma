/*************************************************************************/
/* Author        : Abdelrahman Hepish                                    */
/* File          : SCB_private.h                                         */
/* Date          : 11 DEC 2021                                           */
/* Version       : V01                                                   */
/* GitHub        : https://github.com/Abdelrahman-Hepish                 */
/*************************************************************************/
#ifndef __SCB_PRIVATE_H__
#define __SCB_PRIVATE_H__

#define   SCB_BASE_ADDRESS   0xE000ED00 
#define   SCB_AIRCR_OFFSET   0x0C
#define   SCB_AIRCR_LOCK_KEY 0x05FA
#define   SCB_AIRCR         *((volatile u32 *) (SCB_BASE_ADDRESS + SCB_AIRCR_OFFSET ))
		
#endif // __SCB_PRIVATE_H__
