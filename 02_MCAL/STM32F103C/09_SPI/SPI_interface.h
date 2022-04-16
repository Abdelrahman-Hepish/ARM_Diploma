/*************************************************************************/
/* Author        : Abdelrahman Hepish                                    */
/* File          : SPI_interface.h                                       */
/* Date          : 3 APRIL 2022                                          */
/* Version       : V01                                                   */
/* GitHub        : https://github.com/Abdelrahman-Hepish                 */
/*************************************************************************/
#ifndef __SPI_INTERFACE_H__
#define __SPI_INTERFACE_H__
typedef enum 
{
  UNIDIRECTION_MODE = 0 , 
  BIDIRECTION_MODE   
}SPI_BIDIMODE ;
/* This mode combined with the BIDImode bit selects the direction of transfer in bidirectional mode */
typedef enum 
{
  RX_ONLY_MODE = 0 , 
  TX_ONLY_MODE   
}SPI_BIDIOE ; 
/* Hardware CRC calculation state */ 	
typedef enum 
{
    CRC_DISABLED = 0 , 
    CRC_ENABLED 
}SPI_CRCstate ; 
/* CRCNEXT: CRC transfer next , idk what is this */ 
typedef enum 
{
    NO_CRC_PHASE = 0 , 
    CRC_PHASE 
}SPI_CRCNEXT ; 
/* Data frame format */ 
typedef enum 
{
    DATA_FORMAT_8_BIT = 0 , 
    DATA_FORMAT_16_BIT 
}SPI_DFF ; 
/* RXONLY: Receive only */ 
typedef enum
{
  TX_AND_RX = 0 , 
  RX_ONLY    
}SPI_RXONLY ; 
/* SSM: Software slave managemen */ 
typedef enum 
{
    SLAVE_MG_BY_HW = 0 , 
    SLAVE_MG_BY_SW 
}SPI_SSM ; 
/* LSBFIRST: Frame format */ 
typedef enum 
{
    MSB_TX_FIRST = 0 , 
    LSB_TX_FIRST 
}SPI_BITORDER ; 
typedef enum 
{
    SPI_DISABLED  = 0 , 
    SPI_ENABLED 
}SPI_State ; 

typedef enum 
{
    BAUD_RATE_BY_2     ,      
    BAUD_RATE_BY_4     ,
    BAUD_RATE_BY_8     ,
    BAUD_RATE_BY_16    ,
    BAUD_RATE_BY_32    ,
    BAUD_RATE_BY_64    ,
    BAUD_RATE_BY_128   ,
    BAUD_RATE_BY_256
}SPI_BaudRate ; 

typedef enum 
{
    SPI_SLAVE_NODE = 0 , 
    SPI_MASTER_NODE
}SPI_NodeRank ;
/* CPOL: Clock polarity */ 
typedef enum 
{
     CK_TO_0_WHEN_IDLE ,
     CK_TO_1_WHEN_IDLE 
}SPI_CPOL ; 
/* CPHA: Clock phase */ 
typedef enum 
{
    READ_THEN_WRITE , 
    WRITE_THEN_READ 
}SPI_CPHA ; 
void SPI_voidInit(void) ; 
void SPI_voidSetState(SPI_State Copy_u8SPIstate) ; 
void SPI_voidSetRank(SPI_NodeRank Copy_u8SPIrank) ; 
void SPI_voidSetBaudRate(SPI_BaudRate Copy_u8SPIbaudRate) ; 
void SPI_voidSetClkPolarity(SPI_CPOL Copy_u8ClkPol) ; 
void SPI_voidSetClkPhase(SPI_CPHA Copy_u8ClkPhase) ;
void SPI_voidSendReceiveSynch(u8 Copy_u8DataToSend,u8 * Copy_u8PtrToRec) ; 
void SPI_voidSendReceiveAsynch(u8 Copy_u8DataToSend,void (*ptrCallBackFunc)(u8)) ; 
#endif // __SPI_INTERFACE_H__