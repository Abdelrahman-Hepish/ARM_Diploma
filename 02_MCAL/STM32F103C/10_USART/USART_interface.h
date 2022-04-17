/*************************************************************************/
/* Author        : Abdelrahman Hepish                                    */
/* File          : USART_interface.h                                     */
/* Date          : 16 APRIL 2022                                         */
/* Version       : V01                                                   */
/* GitHub        : https://github.com/Abdelrahman-Hepish                 */
/*************************************************************************/
#ifndef __USART_INTERFACE_H__
#define __USART_INTERFACE_H__

typedef enum 
{
    USART_DISABLED , 
    USART_ENABLED 
}UART_State_t ; 
typedef enum 
{
    USART_8BIT_L , 
    USART_9BIT_L 
}UART_WordLength_t ; 
typedef enum 
{
    USART_PARITY_DISABLED , 
    USART_PARITY_ENABLED 
}UART_ParitySate_t;
 typedef enum 
{
    USART_PARITY_EVEN , 
    USART_PARITY_ODD 
}UART_ParityTYPE_t;
 typedef enum 
{
    USART_PARITY_INTER_DISABLED , 
    USART_PARITY_INTER_ENABLED
}UART_ParityInterState_t;
 typedef enum 
{
    USART_TX_INTER_DISABLED , 
    USART_TX_INTER_ENABLED
}UART_TXInterrState_t;
 typedef enum 
{
    USART_TX_COM_INTER_DISABLED , 
    USART_TX_COM_INTER_ENABLED
}UART_TX_COM_InterrState_t;
typedef enum 
{
    USART_TX_DISABLED , 
    USART_TX_ENABLED 
}UART_TX_State_t ; 
typedef enum 
{
    USART_RX_DISABLED , 
    USART_RX_ENABLED 
}UART_RX_State_t ;
typedef enum 
{
    USART_1BIT_STOP = 0 , 
    USART_2BIT_STOP = 2 , 
}UART_StopBitMOde_t ; 
/* CPOL: Clock polarity */ 
typedef enum 
{
     CLK_0_WHEN_IDLE ,
     CLK_1_WHEN_IDLE 
}USART_CPOL_t ; 
/* CPHA: Clock phase */ 
typedef enum 
{
    READ_THEN_WRITE , 
    WRITE_THEN_READ 
}USART_CPHA_1 ;
void USART1_init(void) ;
void USART1_Transmit(u8 Copy_u8PtrToTx[]) ;
u8   USART1_Receive(void) ; 
#endif  //__USART_INTERFACE_H__
