/*************************************************************************/
/* Author        : Abdelrahman Hepish                                    */
/* File          : TFT_config.h                                          */
/* Date          : 19 APRIL 2022                                         */
/* Version       : V01                                                   */
/* GitHub        : https://github.com/Abdelrahman-Hepish                 */
/*************************************************************************/
#ifndef __TFT_CONFIG_H__
#define __TFT_CONFIG_H__
 // In system Init 
 // GPIO_voidInitPin(TFT_A0_PIN,PIN_NM_OUTPUT_50MHZ,GPIO_PIN_LOW) ; 
 // GPIO_voidInitPin(TFT_RST_PIN,PIN_NM_OUTPUT_50MHZ,GPIO_PIN_LOW) ;
 // STK_voidInit(STK_ENABLED,STK_CLKSRC_AHB_BY_8,STK_INT_DISABLE) ; 	


// WRITE PIN PAIR           PORT,PIN  ->  GPIO_PORTx , GPIO_PIN_x
#define TFT_A0_PIN         GPIO_PORTA,GPIO_PIN_2
#define TFT_RST_PIN        GPIO_PORTA,GPIO_PIN_1

#endif  __TFT_CONFIG_H__