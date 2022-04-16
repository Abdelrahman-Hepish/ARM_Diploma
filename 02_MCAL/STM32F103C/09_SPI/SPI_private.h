/*************************************************************************/
/* Author        : Abdelrahman Hepish                                    */
/* File          : SPI_private.h                                         */
/* Date          : 3 APRIL 2022                                          */
/* Version       : V01                                                   */
/* GitHub        : https://github.com/Abdelrahman-Hepish                 */
/*************************************************************************/
#ifndef __SPI_PRIVATE_H__
#define __SPI_PRIVATE_H__

typedef struct 
{
   volatile  u32 CR1     ; 
   volatile  u32 CR2     ; 
   volatile  u32 SR      ; 
   volatile  u32 DR      ; 
   volatile  u32 CRCPR   ; 
   volatile  u32 RXCRCR  ; 
   volatile  u32 TXCRCR  ; 
   volatile  u32 I2SCFGR ; 
   volatile  u32 I2SPR   ; 
}SPI_Register;

#define SPI ((volatile SPI_Register *) 0x40013000)
		
#endif //  __SPI_PRIVATE_H__