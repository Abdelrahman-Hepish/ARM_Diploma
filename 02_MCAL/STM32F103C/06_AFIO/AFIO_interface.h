/*************************************************************************/
/* Author        : Abdelrahman Hepish                                    */
/* File          : AFIO_interface.h                                      */
/* Date          : 12 DEC 2021                                           */
/* Version       : V01                                                   */
/* GitHub        : https://github.com/Abdelrahman-Hepish                 */
/*************************************************************************/
#ifndef __AFIO_INTERFACE_H__
#define __AFIO_INTERFACE_H__

typedef enum 
{
	AFIO_LINE_PORT_A = 0 , 
	AFIO_LINE_PORT_B     ,
	AFIO_LINE_PORT_C     ,
	AFIO_LINE_PORT_D     ,
	AFIO_LINE_PORT_E     ,
	AFIO_LINE_PORT_F     ,
	AFIO_LINE_PORT_G     
}tAFIO_LinePort ; 
typedef enum 
{
	AFIO_LINE_0   = 0 , 
	AFIO_LINE_1       , 
	AFIO_LINE_2       , 
	AFIO_LINE_3       , 
	AFIO_LINE_4       , 
	AFIO_LINE_5       , 
	AFIO_LINE_6       , 
	AFIO_LINE_7       , 
	AFIO_LINE_8       , 
	AFIO_LINE_9       ,
	AFIO_LINE_10      , 
	AFIO_LINE_11      , 
	AFIO_LINE_12      , 
	AFIO_LINE_13      , 
	AFIO_LINE_14      ,
	AFIO_LINE_15      , 
	AFIO_LINE_16      , 
	AFIO_LINE_17      , 
	AFIO_LINE_18      , 
	AFIO_LINE_19      
}tAFIO_Line ; 
void AFIO_voidSetEXTI_Configuration(tAFIO_Line Copy_u8Line ,tAFIO_LinePort Copy_u8Port) ;  
	
			
#endif // __AFIO_INTERFACE_H__