/*************************************************************************/
/* Author        : Abdelrahman Hepish                                    */
/* File          : RGB_config.h                                          */
/* Date          : 11 MARCH 2022                                         */
/* Version       : V01                                                   */
/* GitHub        : https://github.com/Abdelrahman-Hepish                 */
/*************************************************************************/
#ifndef __RGB_CONFIG_H__
#define __RGB_CONFIG_H__
/*
    Choose among those ports 
  	{ GPIO_PORTA , GPIO_PORTB , GPIO_PORTC } 
*/
/*
    Choose among those pins 
  	{ GPIO_PIN_0 , GPIO_PIN_1 , GPIO_PIN_2 , GPIO_PIN_3 , GPIO_PIN_4 , GPIO_PIN_5 , GPIO_PIN_6 , GPIO_PIN_7 ,
	  GPIO_PIN_8 , GPIO_PIN_9 , GPIO_PIN_10, GPIO_PIN_11, GPIO_PIN_12, GPIO_PIN_13, GPIO_PIN_14, GPIO_PIN_15 }	
*/  
  
#define RGB_R_LED_PORT GPIO_PORTA
#define RGB_G_LED_PORT GPIO_PORTA
#define RGB_B_LED_PORT GPIO_PORTA 	
#define RGB_R_LED_PIN  GPIO_PIN_1
#define RGB_G_LED_PIN  GPIO_PIN_2
#define RGB_B_LED_PIN  GPIO_PIN_3	  
#endif // __RGB_CONFIG_H__