/*************************************************************************/
/* Author        : Abdelrahman Hepish                                    */
/* File          : USART_config.h                                        */
/* Date          : 16 APRIL 2022                                         */
/* Version       : V01                                                   */
/* GitHub        : https://github.com/Abdelrahman-Hepish                 */
/*************************************************************************/
#ifndef __USART_CONFIG_H__
#define __USART_CONFIG_H__
/* Baud Rate of transimition */ 
#define BAUD_RATE_4800       0x643
#define BAUD_RATE_9600       0x341
#define BAUD_RATE_115800     0x045

#define USART1_BAUD_RATE     BAUD_RATE_9600

#define USART1_STATE               USART_ENABLED     
#define USART1_WORD_LENGHT         USART_8BIT_L
#define USART1_PARITY_STATE        USART_PARITY_DISABLED
#define USART1_PARITY_TYPE         USART_PARITY_EVEN
#define USART1_PARITY_INTER_STATE  USART_PARITY_INTER_DISABLED
#define USART1_TX_INTER_STATE      USART_TX_INTER_DISABLED
#define USART1_TX_COM_INTER_STATE  USART_TX_COM_INTER_DISABLED
#define USART1_TX_STATE            USART_TX_ENABLED
#define USART1_RX_STATE            USART_TX_ENABLED
#define USART1_N_STOP_BIT          USART_1BIT_STOP
#define USART1_CLK_POLARITY        CLK_1_WHEN_IDLE
#define USART1_CLK_PHASE           WRITE_THEN_READ
#endif // __USART_CONFIG_H__