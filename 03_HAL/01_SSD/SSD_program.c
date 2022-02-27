/*************************************************************************/
/* Author        : Abdelrahman Hepish                                    */
/* File          :                                                       */
/* Date          :                                                       */
/* Version       : V01                                                   */
/* GitHub        : https://github.com/Abdelrahman-Hepish                 */
/*************************************************************************/
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "GPIO_interface.h"
#include "SSD_interface.h" 
#include "SSD_private.h"
#include "SSD_config.h" 

typedef struct
{
    tSSD_Symbol ssd_symbol ;
    tSSD_State  ssd_state ;
}tSSD_Info ;
tSSD_Info ssd_info [NUMBER_OF_SDDs]  ;
static unsigned char ssd_data [NUMBER_OF_SYMBOLS] =
{
    0b00111111,
    0b00000110,
    0b01011011,
    0b01001111,
    0b01100110,
    0b01101101,
    0b01111101,
    0b00000111,
    0b01111111,
    0b01101111,
    0b00000000
};

void static SSD_SetPinsAsOutput(tSSD ssd) ;
void static SSD_TurnAllOff(void) ;
void static SSD_SetHardWare(tSSD ssd ) ;
void static UTILITES_DelayMS(u16 TIME) ;

void SSD_Init(tSSD ssd ,tSSD_State init_state ,tSSD_Symbol init_symbol )
{
    /* initialize direction port of Port-D & 4 pins "State" from Port-B */
    SSD_SetPinsAsOutput(ssd) ;
    SSD_SetSymbol(ssd,init_symbol) ;
    SSD_SetState(ssd ,init_state) ;
}
void SSD_Update (void)
{
  tSSD current_ssd = SSD_1 ;
  for(current_ssd = SSD_1 ;current_ssd <= SSD_4 ;current_ssd ++ )
  {
    if(ssd_info[current_ssd].ssd_state == SSD_ON )
    {
        /* Turn all off SSDs */
      SSD_TurnAllOff() ;
        /* Set current ssd data on Port-D and then makes it work */
      SSD_SetHardWare(current_ssd ) ;
        /* Delay */
      // UTILITES_DelayMS(DELAY_TEIM) ;
    }
  }
}

tSSD_Symbol SSD_GetSymbol (tSSD ssd)
{
    /* initialization */
    tSSD_Symbol ret = SSD_NUMBER_NULL ;
    /* get symbol of wanted ssd from */
    ret = ssd_info[ssd].ssd_symbol ;
    return ret ;
}
tSSD_State  SSD_GetState (tSSD ssd )
{
    tSSD_State ret = SSD_OFF ;
    ret = ssd_info[ssd].ssd_state ;
    return ret ;
}
void SSD_SetSymbol(tSSD ssd ,tSSD_Symbol symbol)
{
    /* set element ssd in array ssd_info with it's symbol */
    ssd_info[ssd].ssd_symbol = symbol ;
}
void SSD_SetState(tSSD ssd ,tSSD_State state)
{
    /* set element ssd in array ssd_info with it's symbol */
    ssd_info[ssd].ssd_state = state ;
}
void static SSD_SetPinsAsOutput(tSSD ssd)
{
    /* Set Data Register as Output */
	GPIO_voidSetByteMode(SSD_PORT,SSD_BYTE,PIN_NM_OUTPUT_2MHZ) ;
    /* Set State pin as Output */
     switch(ssd)
    {
        case SSD_1 :
            GPIO_voidSetPinMode(SSD_EN_PORT, SSD1_EN_PIN ,PIN_NM_OUTPUT_2MHZ) ;
        break ;
        case SSD_2 :
            GPIO_voidSetPinMode(SSD_EN_PORT, SSD2_EN_PIN ,PIN_NM_OUTPUT_2MHZ) ;
        break ;
        case SSD_3 :
            GPIO_voidSetPinMode(SSD_EN_PORT, SSD3_EN_PIN ,PIN_NM_OUTPUT_2MHZ) ;
        break ;
        case SSD_4 :
            GPIO_voidSetPinMode(SSD_EN_PORT, SSD4_EN_PIN ,PIN_NM_OUTPUT_2MHZ) ;
        break ;
    }
}
void static SSD_TurnAllOff(void)
{
	if(NUMBER_OF_SDDs >= 1 ) 
    GPIO_voidSetPinState(SSD_EN_PORT,SSD1_EN_PIN, SSD_OFF) ;
    if(NUMBER_OF_SDDs >= 2 ) 
    GPIO_voidSetPinState(SSD_EN_PORT,SSD2_EN_PIN, SSD_OFF) ;
    if(NUMBER_OF_SDDs >= 3 ) 
    GPIO_voidSetPinState(SSD_EN_PORT,SSD3_EN_PIN, SSD_OFF) ;
    if(NUMBER_OF_SDDs >= 4 ) 
    GPIO_voidSetPinState(SSD_EN_PORT,SSD4_EN_PIN, SSD_OFF) ;
}
void static SSD_SetHardWare(tSSD ssd )
{
      /* Set data of current SSD on Port-D */
      /* this form is a bit hard ssd_data[ssd_symbols[current_ssd].ssd_symbol]
         + ssd_data    : is an array of unsigned char it's value is binary representation of each symbol.
                       : index of ssd_data is mapped with tSSD_Symbol.
         + ssd_symbols : is an array of 4 "we have 4 ssds in our kit" from data type struct SSD_Info that groups the current symbol of that SSD and it's state.
                       : as we want to get the current ssd symbol we go to the current ssd and get it's value
      */
    GPIO_voidSetByteState(SSD_PORT,SSD_BYTE,  ssd_data[ssd_info[ssd].ssd_symbol]) ;
     /* Turn on current SSD */
    switch(ssd)
    {
        case SSD_1 :
            GPIO_voidSetPinState(SSD_EN_PORT,SSD1_EN_PIN, SSD_ON) ;
        break ;
        case SSD_2 :
            GPIO_voidSetPinState(SSD_EN_PORT,SSD1_EN_PIN, SSD_ON) ;
        break ;
        case SSD_3 :
            GPIO_voidSetPinState(SSD_EN_PORT,SSD1_EN_PIN, SSD_ON) ;
        break ;
        case SSD_4 :
            GPIO_voidSetPinState(SSD_EN_PORT,SSD1_EN_PIN, SSD_ON) ;
        break ;
    }
}
void static UTILITES_DelayMS(u16 TIME)
{
	for(int i = 0 ;i<=TIME;i++)
	{
		for(int j = 0 ;j<=TIME;j++)
		{
			asm("NOP") ;
		}
	}
}