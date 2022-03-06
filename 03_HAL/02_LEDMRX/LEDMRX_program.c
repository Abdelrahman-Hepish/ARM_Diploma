/*************************************************************************/
/* Author        : Abdelrahman Hepish                                    */
/* File          : LEDMRX_program.c                                      */
/* Date          : 6 march 2022                                          */
/* Version       : V01                                                   */
/* GitHub        : https://github.com/Abdelrahman-Hepish                 */
/*************************************************************************/
#include "..\..\..\01_LIB\01_STD_TYPES\STD_TYPES.h"
#include "..\..\..\01_LIB\02_BIT_MATH\BIT_MATH.h"
#include "..\..\..\02_MCAL\STM32F103C\02_GPIO\GPIO_interface.h"
#include "..\..\..\02_MCAL\STM32F103C\07_STK\STK_interface.h"
#include "..\..\..\03_HAL\02_LEDMRX\LEDMRX_interface.h"
#include "..\..\..\03_HAL\02_LEDMRX\LEDMRX_private.h"
#include "..\..\..\03_HAL\02_LEDMRX\LEDMRX_config.h"
static void LEDMRX_voidDisableAllCol(void) ;
static void LEDMRX_voidSetRowData(u8) ;
void LEDMRX_voidInit(void)
{
	GPIO_voidInitPin(LEDMRX_ROW_0_PIN , PIN_NM_OUTPUT_2MHZ , GPIO_PIN_LOW ) ;
    GPIO_voidInitPin(LEDMRX_ROW_1_PIN , PIN_NM_OUTPUT_2MHZ , GPIO_PIN_LOW ) ;
    GPIO_voidInitPin(LEDMRX_ROW_2_PIN , PIN_NM_OUTPUT_2MHZ , GPIO_PIN_LOW ) ;
    GPIO_voidInitPin(LEDMRX_ROW_3_PIN , PIN_NM_OUTPUT_2MHZ , GPIO_PIN_LOW ) ;
    GPIO_voidInitPin(LEDMRX_ROW_4_PIN , PIN_NM_OUTPUT_2MHZ , GPIO_PIN_LOW ) ;
    GPIO_voidInitPin(LEDMRX_ROW_5_PIN , PIN_NM_OUTPUT_2MHZ , GPIO_PIN_LOW ) ;
    GPIO_voidInitPin(LEDMRX_ROW_6_PIN , PIN_NM_OUTPUT_2MHZ , GPIO_PIN_LOW ) ;
    GPIO_voidInitPin(LEDMRX_ROW_7_PIN , PIN_NM_OUTPUT_2MHZ , GPIO_PIN_LOW ) ;
    GPIO_voidInitPin(LEDMRX_COL_0_PIN , PIN_NM_OUTPUT_2MHZ , GPIO_PIN_HIGH ) ;
    GPIO_voidInitPin(LEDMRX_COL_1_PIN , PIN_NM_OUTPUT_2MHZ , GPIO_PIN_HIGH ) ;
    GPIO_voidInitPin(LEDMRX_COL_2_PIN , PIN_NM_OUTPUT_2MHZ , GPIO_PIN_HIGH ) ;
    GPIO_voidInitPin(LEDMRX_COL_3_PIN , PIN_NM_OUTPUT_2MHZ , GPIO_PIN_HIGH ) ;
    GPIO_voidInitPin(LEDMRX_COL_4_PIN , PIN_NM_OUTPUT_2MHZ , GPIO_PIN_HIGH ) ;
    GPIO_voidInitPin(LEDMRX_COL_5_PIN , PIN_NM_OUTPUT_2MHZ , GPIO_PIN_HIGH ) ;
    GPIO_voidInitPin(LEDMRX_COL_6_PIN , PIN_NM_OUTPUT_2MHZ , GPIO_PIN_HIGH ) ;
    GPIO_voidInitPin(LEDMRX_COL_7_PIN , PIN_NM_OUTPUT_2MHZ , GPIO_PIN_HIGH ) ;
}
void LEDMRX_voidDisplay(u8 *Copy_u8Data)
{
    /*        0           */
    /* disable all columns */
    LEDMRX_voidDisableAllCol() ;
	/* Enalbe Column 0 */
	GPIO_voidSetPinState(LEDMRX_COL_0_PIN , GPIO_PIN_LOW) ;
	/* Set Row Data */
    LEDMRX_voidSetRowData(Copy_u8Data[0]);
	/* Delay 2ms */
	Delay_ms(2) ;

	/*        1           */
    /* disable all columns */
    LEDMRX_voidDisableAllCol() ;
	/* Enalbe Column 0 */
	GPIO_voidSetPinState(LEDMRX_COL_1_PIN , GPIO_PIN_LOW) ;
	/* Set Row Data */
    LEDMRX_voidSetRowData(Copy_u8Data[1]);
	/* Delay 2ms */
	Delay_ms(2) ;

	/*        2           */
	/* disable all columns */
    LEDMRX_voidDisableAllCol() ;
	/* Enalbe Column 0 */
	GPIO_voidSetPinState(LEDMRX_COL_2_PIN , GPIO_PIN_LOW) ;
	/* Set Row Data */
    LEDMRX_voidSetRowData(Copy_u8Data[2]);
	/* Delay 2ms */
	Delay_ms(2) ;

	/*        3           */
	/* disable all columns */
    LEDMRX_voidDisableAllCol() ;
	/* Enalbe Column 0 */
	GPIO_voidSetPinState(LEDMRX_COL_3_PIN , GPIO_PIN_LOW) ;
	/* Set Row Data */
    LEDMRX_voidSetRowData(Copy_u8Data[3]);
	/* Delay 2ms */
	Delay_ms(2) ;

	/*        4           */
	/* disable all columns */
    LEDMRX_voidDisableAllCol() ;
	/* Enalbe Column 0 */
	GPIO_voidSetPinState(LEDMRX_COL_4_PIN , GPIO_PIN_LOW) ;
	/* Set Row Data */
    LEDMRX_voidSetRowData(Copy_u8Data[4]);
	/* Delay 2ms */
	Delay_ms(2) ;

	/*        5           */
	/* disable all columns */
    LEDMRX_voidDisableAllCol() ;
	/* Enalbe Column 0 */
	GPIO_voidSetPinState(LEDMRX_COL_5_PIN , GPIO_PIN_LOW) ;
	/* Set Row Data */
    LEDMRX_voidSetRowData(Copy_u8Data[5]);
	/* Delay 2ms */
	Delay_ms(2) ;

	/*        6           */
	/* disable all columns */
    LEDMRX_voidDisableAllCol() ;
	/* Enalbe Column 0 */
	GPIO_voidSetPinState(LEDMRX_COL_6_PIN , GPIO_PIN_LOW) ;
	/* Set Row Data */
    LEDMRX_voidSetRowData(Copy_u8Data[6]);
	/* Delay 2ms */
	Delay_ms(2) ;

	/*        7           */
	/* disable all columns */
    LEDMRX_voidDisableAllCol() ;
	/* Enalbe Column 0 */
	GPIO_voidSetPinState(LEDMRX_COL_7_PIN , GPIO_PIN_LOW) ;
	/* Set Row Data */
    LEDMRX_voidSetRowData(Copy_u8Data[7]);
	/* Delay 2ms */
	Delay_ms(2) ;
}
static void LEDMRX_voidDisableAllCol(void)
{
		/* disable all columns */
	GPIO_voidSetPinState(LEDMRX_COL_0_PIN , GPIO_PIN_HIGH) ;
	GPIO_voidSetPinState(LEDMRX_COL_1_PIN , GPIO_PIN_HIGH) ;
	GPIO_voidSetPinState(LEDMRX_COL_2_PIN , GPIO_PIN_HIGH) ;
	GPIO_voidSetPinState(LEDMRX_COL_3_PIN , GPIO_PIN_HIGH) ;
	GPIO_voidSetPinState(LEDMRX_COL_4_PIN , GPIO_PIN_HIGH) ;
	GPIO_voidSetPinState(LEDMRX_COL_5_PIN , GPIO_PIN_HIGH) ;
	GPIO_voidSetPinState(LEDMRX_COL_6_PIN , GPIO_PIN_HIGH) ;
	GPIO_voidSetPinState(LEDMRX_COL_7_PIN , GPIO_PIN_HIGH) ;
}
static void LEDMRX_voidSetRowData(u8 Copy_u8Data)
{
	GPIO_voidSetPinState(LEDMRX_ROW_0_PIN , GET_BIT(Copy_u8Data,0)) ;
    GPIO_voidSetPinState(LEDMRX_ROW_1_PIN , GET_BIT(Copy_u8Data,1)) ;
    GPIO_voidSetPinState(LEDMRX_ROW_2_PIN , GET_BIT(Copy_u8Data,2)) ;
    GPIO_voidSetPinState(LEDMRX_ROW_3_PIN , GET_BIT(Copy_u8Data,3)) ;
    GPIO_voidSetPinState(LEDMRX_ROW_4_PIN , GET_BIT(Copy_u8Data,4)) ;
    GPIO_voidSetPinState(LEDMRX_ROW_5_PIN , GET_BIT(Copy_u8Data,5)) ;
    GPIO_voidSetPinState(LEDMRX_ROW_6_PIN , GET_BIT(Copy_u8Data,6)) ;
    GPIO_voidSetPinState(LEDMRX_ROW_7_PIN , GET_BIT(Copy_u8Data,7)) ;
}
