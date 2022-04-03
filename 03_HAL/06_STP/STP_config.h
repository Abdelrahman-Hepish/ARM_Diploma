/*************************************************************************/
/* Author        : Abdelrahman Hepish                                    */
/* File          : STP_config.h                                          */
/* Date          :                                                       */
/* Version       : V01                                                   */
/* GitHub        : https://github.com/Abdelrahman-Hepish                 */
/*************************************************************************/
#ifndef __STP_CONFIG_H__
#define __STP_CONFIG_H__
/* Please Write pins in pairs  Port , Pin */
/* Availabe ports :  
   - GPIO_PORTA
   - GPIO_PORTB
   - GPIO_PORTC	
*/ 
/* Availabe pins : 
   - GPIO_PIN_0   
   - GPIO_PIN_1 
   - GPIO_PIN_2 
   - GPIO_PIN_3 
   - GPIO_PIN_4 
   - GPIO_PIN_5 
   - GPIO_PIN_6 
   - GPIO_PIN_7 
   - GPIO_PIN_8 
   - GPIO_PIN_9 
   - GPIO_PIN_10
   - GPIO_PIN_11
   - GPIO_PIN_12
   - GPIO_PIN_13
   - GPIO_PIN_14
   - GPIO_PIN_15
*/   
#define STP_SERIAL_DATA  GPIO_PORTA , GPIO_PIN_0
#define STP_SHIFT_CLOCK  GPIO_PORTA , GPIO_PIN_2
#define STP_STORE_CLOCK  GPIO_PORTA , GPIO_PIN_1



#endif  //__STP_CONFIG_H__
