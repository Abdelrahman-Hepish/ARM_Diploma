/*************************************************************************/
/* Author        : Abdelrahman Hepish                                    */
/* File          : USART_program.c                                       */
/* Date          : 16 APRIL 2022                                         */
/* Version       : V01                                                   */
/* GitHub        : https://github.com/Abdelrahman-Hepish                 */
/*************************************************************************/
#include "..\..\..\01_LIB\01_STD_TYPES\STD_TYPES.h"
#include "..\..\..\01_LIB\02_BIT_MATH\BIT_MATH.h"
#include "..\..\..\02_MCAL\STM32F103C\10_USART\USART_interface.h"
#include "..\..\..\02_MCAL\STM32F103C\10_USART\USART_private.h"
#include "..\..\..\02_MCAL\STM32F103C\10_USART\USART_config.h"

void USART1_init(void) 
{
   USART1->BRR = USART1_BAUD_RATE ; 
   MAN_BIT(USART1->CR1,12,USART1_WORD_LENGHT)                        ;
   MAN_BIT(USART1->CR1,10,USART1_PARITY_STATE)                     ;
   MAN_BIT(USART1->CR1,9 ,USART1_PARITY_TYPE)                       ;
   MAN_BIT(USART1->CR1,8 ,USART1_PARITY_INTER_STATE)                   ;
   MAN_BIT(USART1->CR1,7 ,USART1_TX_INTER_STATE)                        ;
   MAN_BIT(USART1->CR1,6 ,USART1_TX_COM_INTER_STATE)                      ;
   MAN_BIT(USART1->CR1,3,USART1_TX_STATE)                      ;
   MAN_BIT(USART1->CR1,2,USART1_RX_STATE)                      ;
   MAN_BIT(USART1->CR2,12,GET_BIT(USART1_N_STOP_BIT,0) )         ;
   MAN_BIT(USART1->CR2,13,GET_BIT(USART1_N_STOP_BIT,1) )         ;
   MAN_BIT(USART1->CR2,10,USART1_CLK_POLARITY)                      ;
   MAN_BIT(USART1->CR2,9,USART1_CLK_PHASE)                        ;
   MAN_BIT(USART1->CR1,13,USART1_STATE)                      ;
   USART1->SR = 0 ;
}
void USART1_Transmit(u8 Copy_u8PtrToTx[])
{
 u8 i = 0 ; 
 while(Copy_u8PtrToTx[i] != '\0')
 {
     USART1->DR = Copy_u8PtrToTx[i] ;
     /* Wait untill transmission is complete */  
     while(GET_BIT(USART1->SR,6) == 0) ; 
     i++ ;
 }
}
u8   USART1_Receive(void) 
{
     /* Wait untill Recieve is complete */  
     while(GET_BIT(USART1->SR,5) == 0) ; 
     return (u8)USART1->DR ; 
}
