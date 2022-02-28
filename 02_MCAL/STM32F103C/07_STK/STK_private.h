/*************************************************************************/
/* Author        : Abdelrahman Hepish                                    */
/* File          :                                                       */
/* Date          : 14 DEC 2021                                           */
/* Version       : V01                                                   */
/* GitHub        : https://github.com/Abdelrahman-Hepish                 */
/*************************************************************************/
#ifndef __STK_PRIVATE_H__
#define __STK_PRIVATE_H__

#define  STK_BASE_ADDRESS    0xE000E010
#define  STK_CTRL_OFFSET     0x00
#define  STK_LOAD_OFFSET     0x04
#define  STK_VAL_OFFSET      0x08
#define  STK_CALIB_OFFSET    0x0C

#define  STK_CTRL       *((volatile u32 * ) (STK_BASE_ADDRESS + STK_CTRL_OFFSET  ))
#define  STK_LOAD       *((volatile u32 * ) (STK_BASE_ADDRESS + STK_LOAD_OFFSET  ))
#define  STK_VAL        *((volatile u32 * ) (STK_BASE_ADDRESS + STK_VAL_OFFSET   ))
#define  STK_CALIB      *((volatile u32 * ) (STK_BASE_ADDRESS + STK_CALIB_OFFSET ))

#define STK_COUNTFLAG_BIT             16
#define STK_CLKSOURCE_BIT             2 
#define STK_TICKINT_BIT               1 
#define STK_ENABLE_BIT                0 

#define DELAY_1_MS_TIME               1000
		
#endif  __STK_PRIVATE_H__
