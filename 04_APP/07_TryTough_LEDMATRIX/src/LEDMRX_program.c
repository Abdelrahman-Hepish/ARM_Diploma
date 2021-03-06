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
#define CHAR_A_OFFSET 65
u8 Characters [26] [8] =
{
		{0, 124 , 18  , 18  , 124 , 0   , 0  , 0  } ,
		{0, 34  , 62  , 42  , 42  , 42  , 28 , 0  } ,
		{0, 62  , 34  , 34  , 34  , 0   , 0  , 0  } ,
		{0, 62  , 34  , 34  , 34  , 28  , 0  , 0  } ,
		{0, 62  , 42  , 42  , 42  , 0   , 0  , 0  }

};
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
	u8 delaytime = 3	 ;
	u32 Copy_u32NumberofTicks = 2500 ;
    /*        0           */
    /* disable all columns */
    LEDMRX_voidDisableAllCol() ;
	/* Set Row Data */
    LEDMRX_voidSetRowData(Copy_u8Data[0]);
	/* Enalbe Column 0 */
	GPIO_voidSetPinState(LEDMRX_COL_0_PIN , GPIO_PIN_LOW) ;
	/* Delay 2ms */
    Delay_ms(delaytime) ;
  // STK_BusyWaitTicks(Copy_u32NumberofTicks) ;

	/*        1           */
    /* disable all columns */
    LEDMRX_voidDisableAllCol() ;
	/* Set Row Data */
    LEDMRX_voidSetRowData(Copy_u8Data[1]);
	/* Enalbe Column 0 */
	GPIO_voidSetPinState(LEDMRX_COL_1_PIN , GPIO_PIN_LOW) ;
	/* Delay 2ms */
    Delay_ms(delaytime) ;
  // STK_BusyWaitTicks(Copy_u32NumberofTicks) ;

	/*        2           */
	/* disable all columns */
    LEDMRX_voidDisableAllCol() ;
	/* Set Row Data */
    LEDMRX_voidSetRowData(Copy_u8Data[2]);
	/* Enalbe Column 0 */
	GPIO_voidSetPinState(LEDMRX_COL_2_PIN , GPIO_PIN_LOW) ;
	/* Delay 2ms */
    Delay_ms(delaytime) ;
  // STK_BusyWaitTicks(Copy_u32NumberofTicks) ;

	/*        3           */
	/* disable all columns */
    LEDMRX_voidDisableAllCol() ;
	/* Set Row Data */
    LEDMRX_voidSetRowData(Copy_u8Data[3]);
	/* Enalbe Column 0 */
	GPIO_voidSetPinState(LEDMRX_COL_3_PIN , GPIO_PIN_LOW) ;
	/* Delay 2ms */
      Delay_ms(delaytime) ;
    // STK_BusyWaitTicks(Copy_u32NumberofTicks) ;

	/*        4           */
	/* disable all columns */
    LEDMRX_voidDisableAllCol() ;
	/* Set Row Data */
    LEDMRX_voidSetRowData(Copy_u8Data[4]);
	/* Enalbe Column 0 */
	GPIO_voidSetPinState(LEDMRX_COL_4_PIN , GPIO_PIN_LOW) ;
	/* Delay 2ms */
    Delay_ms(delaytime) ;
  // STK_BusyWaitTicks(Copy_u32NumberofTicks) ;

	/*        5           */
	/* disable all columns */
    LEDMRX_voidDisableAllCol() ;
	/* Set Row Data */
    LEDMRX_voidSetRowData(Copy_u8Data[5]);
	/* Enalbe Column 0 */
	GPIO_voidSetPinState(LEDMRX_COL_5_PIN , GPIO_PIN_LOW) ;
	/* Delay 2ms */
    Delay_ms(delaytime) ;
  // STK_BusyWaitTicks(Copy_u32NumberofTicks) ;

	/*        6           */
	/* disable all columns */
    LEDMRX_voidDisableAllCol() ;
	/* Set Row Data */
    LEDMRX_voidSetRowData(Copy_u8Data[6]);
	/* Enalbe Column 0 */
	GPIO_voidSetPinState(LEDMRX_COL_6_PIN , GPIO_PIN_LOW) ;
	/* Delay 2ms */
    Delay_ms(delaytime) ;
  // STK_BusyWaitTicks(Copy_u32NumberofTicks) ;

	/*        7           */
	/* disable all columns */
    LEDMRX_voidDisableAllCol() ;
	/* Set Row Data */
    LEDMRX_voidSetRowData(Copy_u8Data[7]);
	/* Enalbe Column 0 */
	GPIO_voidSetPinState(LEDMRX_COL_7_PIN , GPIO_PIN_LOW) ;
	/* Delay 2ms */
    Delay_ms(delaytime) ;
  // STK_BusyWaitTicks(Copy_u32NumberofTicks) ;
}
void LEDMRX_voidDisplayChar(u8 ch )
{
	u8 index = ch - CHAR_A_OFFSET ;
	LEDMRX_voidDisplay(Characters[index]) ;
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
