/*************************************************************************/
/* Author        : Abdelrahman Hepish                                    */
/* File          : SPI_program.c                                         */
/* Date          : 3 APRIL 2022                                          */
/* Version       : V01                                                   */
/* GitHub        : https://github.com/Abdelrahman-Hepish                 */
/*************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_interface.h"
/* Violate Rules ? */ 
#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"
void (*SPI1_CallBackFunc)(u8) ; 
void SPI_voidInit(void) 
{
   MAN_BIT(SPI->CR1,15,BIDIMODE)                      ; 
   MAN_BIT(SPI->CR1,14,BIDIOE)                        ;
   MAN_BIT(SPI->CR1,13,CRC_STATE)                     ;
   MAN_BIT(SPI->CR1,12,CRCNEXT)                       ;
   MAN_BIT(SPI->CR1,11,DATA_FORMAT)                   ;
   MAN_BIT(SPI->CR1,10,RXONLY)                        ;
   MAN_BIT(SPI->CR1,9,SSM_STATE)                      ;
   MAN_BIT(SPI->CR1,8,SSI_STATE)                      ;
   MAN_BIT(SPI->CR1,7,BIT_ORDER)                      ;
   MAN_BIT(SPI->CR1,6,SPI_STATE)                      ;
   MAN_BIT(SPI->CR1,5,GET_BIT(SPI_BDRATE,2) )         ;
   MAN_BIT(SPI->CR1,4,GET_BIT(SPI_BDRATE,1) )         ;
   MAN_BIT(SPI->CR1,3,GET_BIT(SPI_BDRATE,0) )         ;
   MAN_BIT(SPI->CR1,2,NODE_RANK)                      ;
   MAN_BIT(SPI->CR1,1,CLK_POL)                        ;
   MAN_BIT(SPI->CR1,0,CLK_PHASE)                      ;
   GPIO_voidInitPin(SPI1_SLAVE_SELCET_PIN,PIN_NM_OUTPUT_2MHZ,GPIO_PIN_HIGH) ;
}       
void SPI_voidSetState(SPI_State Copy_u8SPIstate) 
{
   MAN_BIT(SPI->CR1,6,Copy_u8SPIstate)  ; 
}
void SPI_voidSetRank(SPI_NodeRank Copy_u8SPIrank) 
{
    MAN_BIT(SPI->CR1,2,Copy_u8SPIrank) ;  
}             
void SPI_voidSetBaudRate(SPI_BaudRate Copy_u8SPIbaudRate) 
{
   MAN_BIT(SPI->CR1,5,GET_BIT(Copy_u8SPIbaudRate,2) )         ;
   MAN_BIT(SPI->CR1,4,GET_BIT(Copy_u8SPIbaudRate,1) )         ;
   MAN_BIT(SPI->CR1,3,GET_BIT(Copy_u8SPIbaudRate,0) )         ;    
}
void SPI_voidSetClkPolarity(SPI_CPOL Copy_u8ClkPol) 
{
      MAN_BIT(SPI->CR1,1,Copy_u8ClkPol)                       ;
}
void SPI_voidSetClkPhase(SPI_CPHA Copy_u8ClkPhase) 
{
       MAN_BIT(SPI->CR1,0,Copy_u8ClkPhase) ; 
}
void SPI_voidSendReceiveSynch(u8 Copy_u8DataToSend,u8 * Copy_u8PtrToRec) 
{
   /* Select Slave */ 
    GPIO_voidSetPinState(SPI1_SLAVE_SELCET_PIN,GPIO_PIN_LOW) ;
    /* Wait so that doesn't over write another message */ 
    while(GET_BIT(SPI1 -> SR , 7) == 1 ) ; 
    /* Send data */ 
    SPI1 -> DR = Copy_u8DataToSend ; 
    /* Wait until transfere finished */ 
    while(GET_BIT(SPI1 -> SR , 7) == 1 ) ;
    /* assign recived to variable */  
    * Copy_u8PtrToRec = SPI1 -> DR ; 
    /* Unslect slave */ 
    GPIO_voidSetPinState(SPI1_SLAVE_SELCET_PIN,GPIO_PIN_HIGH) ;  
}  
void SPI_voidSendReceiveAsynch(u8 Copy_u8DataToSend,void (*ptrCallBackFunc)(u8)) 
{
		/* Set Call Back function */ 
	SPI1_CallBackFunc = ptrCallBackFunc ; 
	    /* Select Slave */ 
    GPIO_voidSetPinState(SPI1_SLAVE_SELCET_PIN,GPIO_PIN_LOW) ;
	    /* Wait so that doesn't over write another message */ 
    while(GET_BIT(SPI1 -> SR , 7) == 1 ) ;
	    /* Send data */ 
    SPI1 -> DR = Copy_u8DataToSend ;
}
void SPI1_IRQHandler(void)
{
	    /* Unslect slave */ 
    GPIO_voidSetPinState(SPI1_SLAVE_SELCET_PIN,GPIO_PIN_HIGH) ;
		/* Send RX data to Call Back function */ 
	SPI1_CallBackFunc(SPI1 -> DR ) ; 
}