/*************************************************************************/
/* Author        : Abdelrahman Hepish                                    */
/* File          : RGB_program.c                                         */
/* Date          : 11 MARCH 2022                                         */
/* Version       : V01                                                   */
/* GitHub        : https://github.com/Abdelrahman-Hepish                 */
/*************************************************************************/
#include "..\..\..\01_LIB\01_STD_TYPES\STD_TYPES.h"
#include "..\..\..\01_LIB\02_BIT_MATH\BIT_MATH.h"
#include "..\..\..\02_MCAL\STM32F103C\01_RCC\RCC_interface.h"
#include "..\..\..\02_MCAL\STM32F103C\02_GPIO\GPIO_interface.h"
#include "..\..\..\02_MCAL\STM32F103C\03_NVIC\NVIC_interface.h"
#include "..\..\..\02_MCAL\STM32F103C\05_EXTI\EXTI_interface.h"
#include "..\..\..\02_MCAL\STM32F103C\06_AFIO\AFIO_interface.h"
#include "..\..\..\02_MCAL\STM32F103C\07_STK\STK_interface.h"
#include "..\..\..\03_HAL\04_RGB\RGB_interface.h"
#include "..\..\..\03_HAL\04_RGB\RGB_private.h"
#include "..\..\..\03_HAL\04_RGB\RGB_config.h"

void RGB_voidInit(tRGB_Colour Copy_u8Colour) 
{
	GPIO_voidInitPin(RGB_R_LED_PORT,RGB_R_LED_PIN,PIN_NM_OUTPUT_2MHZ,GPIO_PIN_LOW) ;
	GPIO_voidInitPin(RGB_G_LED_PORT,RGB_G_LED_PIN,PIN_NM_OUTPUT_2MHZ,GPIO_PIN_LOW) ;
	GPIO_voidInitPin(RGB_B_LED_PORT,RGB_B_LED_PIN,PIN_NM_OUTPUT_2MHZ,GPIO_PIN_LOW) ;
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
    case MAGENTA :
		GPIO_voidSetPinState(RGB_R_LED_PORT,RGB_R_LED_PIN,GPIO_PIN_HIGH)   ; 
        GPIO_voidSetPinState(RGB_G_LED_PORT,RGB_G_LED_PIN,GPIO_PIN_LOW)   ; 
        GPIO_voidSetPinState(RGB_B_LED_PORT,RGB_B_LED_PIN,GPIO_PIN_HIGH)  ; 	
        break ;		
    case CYAN :
		GPIO_voidSetPinState(RGB_R_LED_PORT,RGB_R_LED_PIN,GPIO_PIN_LOW)   ; 
        GPIO_voidSetPinState(RGB_G_LED_PORT,RGB_G_LED_PIN,GPIO_PIN_HIGH)   ; 
        GPIO_voidSetPinState(RGB_B_LED_PORT,RGB_B_LED_PIN,GPIO_PIN_HIGH)  ; 	
        break ;		
    case WHITE :
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
}
