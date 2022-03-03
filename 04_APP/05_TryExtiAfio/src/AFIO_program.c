/*************************************************************************/
/* Author        : Abdelrahman Hepish                                    */
/* File          : AFIO_program.c                                        */
/* Date          : 12 DEC 2021                                           */
/* Version       : V01                                                   */
/* GitHub        : https://github.com/Abdelrahman-Hepish                 */
/*************************************************************************/
#include "..\..\..\01_LIB\01_STD_TYPES\STD_TYPES.h"
#include "..\..\..\01_LIB\02_BIT_MATH\BIT_MATH.h"
#include "..\..\..\02_MCAL\STM32F103C\06_AFIO\AFIO_interface.h"
#include "..\..\..\02_MCAL\STM32F103C\06_AFIO\AFIO_private.h"
#include "..\..\..\02_MCAL\STM32F103C\06_AFIO\AFIO_config.h"
void AFIO_voidSetEXTI_Configuration(tAFIO_Line Copy_u8Line ,tAFIO_LinePort Copy_u8Port)
{
	u8 Copy_RegisterId = Copy_u8Line / 4 ;
	u8 Copy_offset = Copy_u8Line % 4 ;
	u8 Copy_shift  = Copy_offset * 4 ;
	MAN_NIBBLE(AFIO->EXTICR[Copy_RegisterId],Copy_shift,Copy_u8Port) ;
}
