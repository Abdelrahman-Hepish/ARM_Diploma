/*************************************************************************/
/* Author        : Abdelrahman Hepish                                    */
/* File          : SCB_interface.h                                       */
/* Date          : 11 DEC 2021                                           */
/* Version       : V01                                                   */
/* GitHub        : https://github.com/Abdelrahman-Hepish                 */
/*************************************************************************/
#ifndef __SCB_INTERFACE_H__
#define __SCB_INTERFACE_H__
typedef enum
{
  SCB_16_GRP_0_SUB = 0x05FA03000 , 	
  SCB_8_GRP_2_SUB  = 0x05FA04000 , 
  SCB_4_GRP_4_SUB  = 0x05FA05000 , 
  SCB_2_GRP_8_SUB  = 0x05FA06000 , 
  SCB_0_GRP_16_SUB = 0x05FA07000 
}tSCB_InterruptGroupSys ; 

#endif  // __SCB_INTERFACE_H__
