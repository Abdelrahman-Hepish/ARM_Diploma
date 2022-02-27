/*************************************************************************/
/* Author        : Abdelrahman Hepish                                    */
/* File          :                                                       */
/* Date          :                                                       */
/* Version       : V01                                                   */
/* GitHub        : https://github.com/Abdelrahman-Hepish                 */
/*************************************************************************/
#ifndef __SSD_CONFIG_H__
#define __SSD_CONFIG_H__

#define NUMBER_OF_SDDs 4

/* 
  Choices : 
          - SSD_COMMON_ANODE
          - SSD_COMMON_CATHODE 
*/ 		  
#define SSD_TYPE  SSD_COMMON_CATHODE
/* 
  Choices : 
          -	GPIO_PORTA   
		  -	GPIO_PORTB   
		  -	GPIO_PORTC  
*/
		  
#define SSD_PORT GPIO_PORTA
/* 
  Choices : 
          - GPIO_LOW_BYTE 
          - GPIO_HIGH_BYTE 
*/ 
#define SSD_BYTE GPIO_LOW_BYTE
/* 
  Choices : 
          -  GPIO_PORTA
          -  GPIO_PORTB
          -  GPIO_PORTC
*/
#define SSD_EN_PORT GPIO_PORTA
/* 
  Choices : 
          -  GPIO_PIN_0 
	   	  -	 GPIO_PIN_1 
		  -	 GPIO_PIN_2 
          -  GPIO_PIN_3 
          -  GPIO_PIN_4 
          -  GPIO_PIN_5 
          -  GPIO_PIN_6 
          -  GPIO_PIN_7 
          -  GPIO_PIN_8 
          -  GPIO_PIN_9 
          -  GPIO_PIN_10
          -  GPIO_PIN_11
          -  GPIO_PIN_12
          -  GPIO_PIN_13
          -  GPIO_PIN_14
          -  GPIO_PIN_15
*/
#define SSD1_EN_PIN GPIO_PIN_8 
#define SSD2_EN_PIN GPIO_PIN_9 
#define SSD3_EN_PIN GPIO_PIN_10
#define SSD4_EN_PIN GPIO_PIN_11		  
		  
#endif //  __SSD_CONFIG_H__