/*************************************************************************/
/* Author        : Abdelrahman Hepish                                    */
/* File          : RGB_interface.h                                       */
/* Date          : 11 MARCH 2022                                         */
/* Version       : V01                                                   */
/* GitHub        : https://github.com/Abdelrahman-Hepish                 */
/*************************************************************************/
#ifndef __RGB_INTERFACE_H__
#define __RGB_INTERFACE_H__
typedef enum
{
	RED ,
	GREEN ,
	BLUE ,
	YELLOW ,
	MAGENTA ,
	CYAN ,
	WHITE ,
	OFF
}tRGB_Colour;
void RGB_voidInit(tRGB_Colour Copy_u8Colour) ; 
void RGB_SetMode(tRGB_Colour Copy_u8Colour) ; 			
#endif  // __RGB_INTERFACE_H__
