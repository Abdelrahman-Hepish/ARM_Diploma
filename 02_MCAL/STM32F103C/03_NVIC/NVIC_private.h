/*************************************************************************/
/* Author        : Abdelrahman Hepish                                    */
/* File          : NVIC_private.h                                        */
/* Date          : 5 Dec 2021                                            */
/* Version       : V01                                                   */
/* GitHub        : https://github.com/Abdelrahman-Hepish                 */
/*************************************************************************/
#ifndef __NVIC_PRIVATE_H__
#define __NVIC_PRIVATE_H__

#define NVIC_BASE_ADDRESS         0xE000E100
#define NVIC_ISER0_OFFSET         0x000
#define NVIC_ISER1_OFFSET         0x004
#define NVIC_ICER0_OFFSET         0x080
#define NVIC_ICER1_OFFSET         0x084
#define NVIC_ISPR0_OFFSET         0x100
#define NVIC_ISPR1_OFFSET         0x104
#define NVIC_ICPR0_OFFSET         0x180
#define NVIC_ICPR1_OFFSET         0x184
#define NVIC_IABR0_OFFSET         0x200
#define NVIC_IABR1_OFFSET         0x204
#define NVIC_IPR_OFFSET           0x300
#define NVIC_STIR_OFFSET          0xE00

#define NVIC_ISER0          *(( volatile u32 *) ( NVIC_BASE_ADDRESS +  NVIC_ISER0_OFFSET ))
#define NVIC_ISER1          *(( volatile u32 *) ( NVIC_BASE_ADDRESS +  NVIC_ISER1_OFFSET ))
#define NVIC_ICER0          *(( volatile u32 *) ( NVIC_BASE_ADDRESS +  NVIC_ICER0_OFFSET ))
#define NVIC_ICER1          *(( volatile u32 *) ( NVIC_BASE_ADDRESS +  NVIC_ICER1_OFFSET ))
#define NVIC_ISPR0          *(( volatile u32 *) ( NVIC_BASE_ADDRESS +  NVIC_ISPR0_OFFSET ))
#define NVIC_ISPR1          *(( volatile u32 *) ( NVIC_BASE_ADDRESS +  NVIC_ISPR1_OFFSET ))
#define NVIC_ICPR0          *(( volatile u32 *) ( NVIC_BASE_ADDRESS +  NVIC_ICPR0_OFFSET ))
#define NVIC_ICPR1          *(( volatile u32 *) ( NVIC_BASE_ADDRESS +  NVIC_ICPR1_OFFSET ))
#define NVIC_IABR0          *(( volatile u32 *) ( NVIC_BASE_ADDRESS +  NVIC_IABR0_OFFSET ))
#define NVIC_IABR1          *(( volatile u32 *) ( NVIC_BASE_ADDRESS +  NVIC_IABR1_OFFSET ))
#define NVIC_IPR             (( volatile u8  *) ( NVIC_BASE_ADDRESS +  NVIC_IPR_OFFSET   ))
#define NVIC_STIR           *(( volatile u32 *) ( NVIC_BASE_ADDRESS +  NVIC_STIR_OFFSET  ))

#define EXTERNAL_INTERRUPTS_START_POSITION  0
#define PRIORITY_NIPPLE_START_POSITION             4

#endif //  __NVIC_PRIVATE_H__
