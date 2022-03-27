/*************************************************************************/
/* Author        : Abdelrahman Hepish                                    */
/* File          : DAC_config.h                                          */
/* Date          : 27 MARCH 2022                                         */
/* Version       : V01                                                   */
/* GitHub        : https://github.com/Abdelrahman-Hepish                 */
/*************************************************************************/
#ifndef __DAC_CONFIG_H__
#define __DAC_CONFIG_H__
/* Please select which port you have choosen for DAC 
   GPIO_PORTA
   GPIO_PORTB
   GPIO_PORTC
*/  
#define  DAC_PORT   GPIO_PORTA
/* Please select which byte you have choosen from port 
   GPIO_LOW_BYTE 
   GPIO_HIGH_BYTE
*/
#define DAC_BYTE    GPIO_LOW_BYTE  
/* You have to make song in unsigned char format -> the whole audio will be an array of unsigned char 
   please put the size of that array here 
*/   
#define AUDIO_SIZE  30000

#define AUDIO_RATE  8000

/* Please make sure that Song Array called :: Song_raw */ 
#endif  // __DAC_CONFIG_H__