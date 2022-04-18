/*************************************************************************/
/* Author        : Abdelrahman Hepish                                    */
/* File          : SPI_config.h                                          */
/* Date          : 3 APRIL 2022                                          */
/* Version       : V01                                                   */
/* GitHub        : https://github.com/Abdelrahman-Hepish                 */
/*************************************************************************/
#ifndef __SPI_CONFIG_H__
#define __SPI_CONFIG_H__
/* Please Write pins in pairs  Port , Pin */
/* Availabe ports :  
   - GPIO_PORTA
   - GPIO_PORTB
   - GPIO_PORTC	
*/ 
/* Availabe pins : 
   - GPIO_PIN_0   
   - GPIO_PIN_1 
   - GPIO_PIN_2 
   - GPIO_PIN_3 
   - GPIO_PIN_4 
   - GPIO_PIN_5 
   - GPIO_PIN_6 
   - GPIO_PIN_7 
   - GPIO_PIN_8 
   - GPIO_PIN_9 
   - GPIO_PIN_10
   - GPIO_PIN_11
   - GPIO_PIN_12
   - GPIO_PIN_13
   - GPIO_PIN_14
   - GPIO_PIN_15
*/
#define SPI1_SLAVE_SELCET_PIN  GPIO_PORTA , GPIO_PIN_0 
#define BIDIMODE     UNIDIRECTION_MODE 
#define BIDIOE       RX_ONLY_MODE 
#define CRC_STATE    CRC_DISABLED 
#define CRCNEXT      NO_CRC_PHASE 
#define DATA_FORMAT  DATA_FORMAT_8_BIT 
#define RXONLY       TX_AND_RX 
#define SSM_STATE    SLAVE_MG_BY_SW
#define SSI_STATE    SLAVE_NOT_SELECTED
#define BIT_ORDER    MSB_TX_FIRST 
#define SPI_STATE    SPI_ENABLED 
#define SPI_BDRATE   BAUD_RATE_BY_2
#define NODE_RANK    SPI_MASTER_NODE 
#define CLK_POL      CK_TO_0_WHEN_IDLE 
#define CLK_PHASE    WRITE_THEN_READ 
#endif // __SPI_CONFIG_H__