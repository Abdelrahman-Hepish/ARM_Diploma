/*************************************************************************/
/* Author        : Abdelrahman Hepish                                    */
/* Date          : 3 Sep 2021                                            */
/* Version       : V01                                                   */
/* GitHub        : https://github.com/Abdelrahman-Hepish                 */
/*************************************************************************/
#ifndef __BIT_MATH_H__
#define __BIT_MATH_H__
/* dealing with only 1 Bit */
#define MAN_BIT(VAR,BIT,_1BIT_VAL)                (VAR=((VAR & ~(1<<BIT))|(_1BIT_VAL<<BIT)))
#define SET_BIT(VAR,BIT)                          MAN_BIT(VAR,BIT,1)
#define CLR_BIT(VAR,BIT)                          MAN_BIT(VAR,BIT,0)
#define GET_BIT(VAR,BIT)                          ((VAR&(1<<BIT))>>BIT)
#define TOG_BIT(VAR,BIT)                          MAN_BIT(VAR,BIT,~GET_BIT(VAR,BIT))

/* dealing with nibble (4 Bit) */ 
#define MAN_NIBBLE(VAR,START_BIT,_4BIT_VAL)       (VAR=((VAR & ~(0xF<<START_BIT))|(_4BIT_VAL<<START_BIT)))
#define SET_NIBBLE(VAR,START_BIT)                  MAN_NIBBLE(VAR,START_BIT,0XF)
#define CLR_NIBBLE(VAR,START_BIT)                  MAN_NIBBLE(VAR,START_BIT,0X0)
#define GET_NIBBLE(VAR,START_BIT)                  ((VAR&(0XF<<START_BIT))>>START_BIT)
#define TOG_NIBBLE(VAR,START_BIT)        	       MAN_BIT(VAR,START_BIT,~GET_NIBBLE(VAR,START_BIT))

/* dealing with byte (8 Bit) */
#define MAN_BYTE(VAR,START_BIT,_8BIT_VAL)         (VAR=((VAR & ~(0xFF<<START_BIT))|(_8BIT_VAL<<START_BIT)))
#define SET_BYTE(VAR,START_BIT)                    MAN_BYTE(VAR,START_BIT,0XFF)
#define CLR_BYTE(VAR,START_BIT)                    MAN_BYTE(VAR,START_BIT,0X00)
#define GET_BYTE(VAR,START_BIT)                    ((VAR&(0XFF<<START_BIT))>>START_BIT)
#define TOG_BYTE(VAR,START_BIT)                    MAN_BIT(VAR,START_BIT,~GET_BYTE(VAR,START_BIT))
#endif 