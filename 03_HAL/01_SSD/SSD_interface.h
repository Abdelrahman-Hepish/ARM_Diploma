/*************************************************************************/
/* Author        : Abdelrahman Hepish                                    */
/* File          :                                                       */
/* Date          :                                                       */
/* Version       : V01                                                   */
/* GitHub        : https://github.com/Abdelrahman-Hepish                 */
/*************************************************************************/
#ifndef __SSD_INTERFACE_H__
#define __SSD_INTERFACE_H__
typedef enum
{
    SSD_1 = 0  ,
    SSD_2 ,
    SSD_3 ,
    SSD_4
}tSSD ;
typedef enum
{
    SSD_NUMBER_0 ,
    SSD_NUMBER_1 ,
    SSD_NUMBER_2 ,
    SSD_NUMBER_3 ,
    SSD_NUMBER_4 ,
    SSD_NUMBER_5 ,
    SSD_NUMBER_6 ,
    SSD_NUMBER_7 ,
    SSD_NUMBER_8 ,
    SSD_NUMBER_9 ,
    SSD_NUMBER_NULL
}tSSD_Symbol  ;
typedef enum
{
    SSD_OFF ,
    SSD_ON
}tSSD_State ;
void SSD_Init(tSSD ssd ,tSSD_State init_state ,tSSD_Symbol symbol ) ;
void SSD_Update (void) ;
tSSD_Symbol SSD_GetSymbol (tSSD ssd) ;
tSSD_State  SSD_GetState (tSSD ssd ) ;
void SSD_SetSymbol(tSSD ssd ,tSSD_Symbol symbol) ;
void SSD_SetState(tSSD ssd ,tSSD_State state) ;
#endif //  __SSD_INTERFACE_H__
