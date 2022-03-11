/*************************************************************************/
/* Author        : Abdelrahman Hepish                                    */
/* File          : RGB_program.c                                         */
/* Date          : 11 MARCH 2022                                         */
/* Version       : V01                                                   */
/* GitHub        : https://github.com/Abdelrahman-Hepish                 */
/*************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RGB_interface.h"
#include "RGB_private.h"
#include "RGB_config.h"

void RGB_voidInit(tRGB_Colour Copy_u8Colour) 
{
	GPIO_voidInitPin(RGB_R_LED_PORT,RGB_R_LED_PIN,PIN_NM_OUTPUT_10MHZ,GPIO_PIN_LOW) ; 
	GPIO_voidInitPin(RGB_G_LED_PORT,RGB_G_LED_PIN,PIN_NM_OUTPUT_10MHZ,GPIO_PIN_LOW) ; 
	GPIO_voidInitPin(RGB_B_LED_PORT,RGB_B_LED_PIN,PIN_NM_OUTPUT_10MHZ,GPIO_PIN_LOW) ; 
	RGB_SetMode(Copy_u8Colour) ; 
}
void RGB_SetMode(tRGB_Colour Copy_u8Colour) 
{ 
   switch(Copy_u8Colour)
   {
    case RED : 
	    GPIO_voidSetPinState(RGB_R_LED_PORT,RGB_R_LED_PIN,GPIO_PIN_HIGH) ; 
        GPIO_voidSetPinState(RGB_G_LED_PORT,RGB_G_LED_PIN,GPIO_PIN_LOW)  ; 
        GPIO_voidSetPinState(RGB_B_LED_PORT,RGB_B_LED_PIN,GPIO_PIN_LOW)  ; 	
        break ; 		
    case GREEN : 
		GPIO_voidSetPinState(RGB_R_LED_PORT,RGB_R_LED_PIN,GPIO_PIN_LOW)  ; 
        GPIO_voidSetPinState(RGB_G_LED_PORT,RGB_G_LED_PIN,GPIO_PIN_HIGH) ; 
        GPIO_voidSetPinState(RGB_B_LED_PORT,RGB_B_LED_PIN,GPIO_PIN_LOW)  ; 	
        break ;
    case BLUE : 
		GPIO_voidSetPinState(RGB_R_LED_PORT,RGB_R_LED_PIN,GPIO_PIN_LOW)   ; 
        GPIO_voidSetPinState(RGB_G_LED_PORT,RGB_G_LED_PIN,GPIO_PIN_LOW)   ; 
        GPIO_voidSetPinState(RGB_B_LED_PORT,RGB_B_LED_PIN,GPIO_PIN_HIGH)  ; 	
        break ;	
    case YELLOW : 
		GPIO_voidSetPinState(RGB_R_LED_PORT,RGB_R_LED_PIN,GPIO_PIN_HIGH)   ; 
        GPIO_voidSetPinState(RGB_G_LED_PORT,RGB_G_LED_PIN,GPIO_PIN_HIGH)   ; 
        GPIO_voidSetPinState(RGB_B_LED_PORT,RGB_B_LED_PIN,GPIO_PIN_LOW)  ; 	
        break ;		
    case Magenta : 
		GPIO_voidSetPinState(RGB_R_LED_PORT,RGB_R_LED_PIN,GPIO_PIN_HIGH)   ; 
        GPIO_voidSetPinState(RGB_G_LED_PORT,RGB_G_LED_PIN,GPIO_PIN_LOW)   ; 
        GPIO_voidSetPinState(RGB_B_LED_PORT,RGB_B_LED_PIN,GPIO_PIN_HIGH)  ; 	
        break ;		
    case Cyan :
		GPIO_voidSetPinState(RGB_R_LED_PORT,RGB_R_LED_PIN,GPIO_PIN_LOW)   ; 
        GPIO_voidSetPinState(RGB_G_LED_PORT,RGB_G_LED_PIN,GPIO_PIN_HIGH)   ; 
        GPIO_voidSetPinState(RGB_B_LED_PORT,RGB_B_LED_PIN,GPIO_PIN_HIGH)  ; 	
        break ;		
    case BLACK : 
		GPIO_voidSetPinState(RGB_R_LED_PORT,RGB_R_LED_PIN,GPIO_PIN_HIGH)   ; 
        GPIO_voidSetPinState(RGB_G_LED_PORT,RGB_G_LED_PIN,GPIO_PIN_HIGH)   ; 
        GPIO_voidSetPinState(RGB_B_LED_PORT,RGB_B_LED_PIN,GPIO_PIN_HIGH)  ; 	
        break ;		
    case OFF : 
		GPIO_voidSetPinState(RGB_R_LED_PORT,RGB_R_LED_PIN,GPIO_PIN_LOW)   ; 
        GPIO_voidSetPinState(RGB_G_LED_PORT,RGB_G_LED_PIN,GPIO_PIN_LOW)   ; 
        GPIO_voidSetPinState(RGB_B_LED_PORT,RGB_B_LED_PIN,GPIO_PIN_LOW)  ; 	
        break ;
}	