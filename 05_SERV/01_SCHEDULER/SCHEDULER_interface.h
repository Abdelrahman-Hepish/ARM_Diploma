/*************************************************************************/
/* Author        : Abdelrahman Hepish                                    */
/* File          : SCHEDULER_interface.h                                 */
/* Date          : 24 MARCH 2021                                         */
/* Version       : V01                                                   */
/* GitHub        : https://github.com/Abdelrahman-Hepish                 */
/*************************************************************************/
#ifndef __SCHEDULER_INTERFACE_H__
#define __SCHEDULER_INTERFACE_H__
void 	SCHEDULER_voidInit(void) ;
void    SCHEDULER_voidCreateTask(u8 Copy_u8TaskPriority,u8 Copy_u8TaskPriodicity,void (*Task_Callback)(void)) ;  		
#endif  //__SCHEDULER_INTERFACE_H__