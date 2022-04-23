/*************************************************************************/
/* Author        : Abdelrahman Hepish                                    */
/* File          : TFT_interface.h                                       */
/* Date          : 19 APRIL 2022                                         */
/* Version       : V01                                                   */
/* GitHub        : https://github.com/Abdelrahman-Hepish                 */
/*************************************************************************/
#ifndef __TFT_INTERFACE_H__
#define __TFT_INTERFACE_H__
void TFT_voidInit(void) ; 
void TFT_voidDisplayImage(const u16 *Copy_u16PtrToImage) ; 
void TFT_voidFillSquare(u32 x_start,u32 x_end , u32 y_start ,u32 y_end , u32 Color) ;
#endif  // __TFT_INTERFACE_H__
