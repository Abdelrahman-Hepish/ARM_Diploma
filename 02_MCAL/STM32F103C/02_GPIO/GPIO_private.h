/*************************************************************************/
/* Author        : Abdelrahman Hepish                                    */
/* File          : GPIO_private.h                                        */
/* Date          : 8 NOV 2021                                            */
/* Version       : V01                                                   */
/* GitHub        : https://github.com/Abdelrahman-Hepish                 */
/*************************************************************************/
#ifndef __GPIO_PRIVATE_H__
#define __GPIO_PRIVATE_H__

#define GPIO_PORTA_BASE         0x40010800
#define GPIO_PORTB_BASE         0x40010C00
#define GPIO_PORTC_BASE         0x40011000
#define GPIO_PORTX_CRL_OFFSET   0X00
#define GPIO_PORTX_CRH_OFFSET   0X04
#define GPIO_PORTX_IDR_OFFSET   0X08
#define GPIO_PORTX_ODR_OFFSET   0X0C
#define GPIO_PORTX_BSRR_OFFSET  0X10
#define GPIO_PORTX_BRR_OFFSET   0X14
#define GPIO_PORTX_LCKR_OFFSET  0X18

#define GPIOA_CRL         *((volatile u32 *)( GPIO_PORTA_BASE + GPIO_PORTX_CRL_OFFSET  ))
#define GPIOA_CRH         *((volatile u32 *)( GPIO_PORTA_BASE + GPIO_PORTX_CRH_OFFSET  ))
#define GPIOA_IDR         *((volatile u32 *)( GPIO_PORTA_BASE + GPIO_PORTX_IDR_OFFSET  ))
#define GPIOA_ODR         *((volatile u32 *)( GPIO_PORTA_BASE + GPIO_PORTX_ODR_OFFSET  ))
#define GPIOA_BSRR        *((volatile u32 *)( GPIO_PORTA_BASE + GPIO_PORTX_BSRR_OFFSET ))
#define GPIOA_BRR         *((volatile u32 *)( GPIO_PORTA_BASE + GPIO_PORTX_BRR_OFFSET  ))
#define GPIOA_LCKR        *((volatile u32 *)( GPIO_PORTA_BASE + GPIO_PORTX_LCKR_OFFSET ))

#define GPIOB_CRL         *((volatile u32 *)( GPIO_PORTB_BASE + GPIO_PORTX_CRL_OFFSET  ))
#define GPIOB_CRH         *((volatile u32 *)( GPIO_PORTB_BASE + GPIO_PORTX_CRH_OFFSET  ))
#define GPIOB_IDR         *((volatile u32 *)( GPIO_PORTB_BASE + GPIO_PORTX_IDR_OFFSET  ))
#define GPIOB_ODR         *((volatile u32 *)( GPIO_PORTB_BASE + GPIO_PORTX_ODR_OFFSET  ))
#define GPIOB_BSRR        *((volatile u32 *)( GPIO_PORTB_BASE + GPIO_PORTX_BSRR_OFFSET ))
#define GPIOB_BRR         *((volatile u32 *)( GPIO_PORTB_BASE + GPIO_PORTX_BRR_OFFSET  ))
#define GPIOB_LCKR        *((volatile u32 *)( GPIO_PORTB_BASE + GPIO_PORTX_LCKR_OFFSET ))

#define GPIOC_CRL         *((volatile u32 *)( GPIO_PORTC_BASE + GPIO_PORTX_CRL_OFFSET  ))
#define GPIOC_CRH         *((volatile u32 *)( GPIO_PORTC_BASE + GPIO_PORTX_CRH_OFFSET  ))
#define GPIOC_IDR         *((volatile u32 *)( GPIO_PORTC_BASE + GPIO_PORTX_IDR_OFFSET  ))
#define GPIOC_ODR         *((volatile u32 *)( GPIO_PORTC_BASE + GPIO_PORTX_ODR_OFFSET  ))
#define GPIOC_BSRR        *((volatile u32 *)( GPIO_PORTC_BASE + GPIO_PORTX_BSRR_OFFSET ))
#define GPIOC_BRR         *((volatile u32 *)( GPIO_PORTC_BASE + GPIO_PORTX_BRR_OFFSET  ))
#define GPIOC_LCKR        *((volatile u32 *)( GPIO_PORTC_BASE + GPIO_PORTX_LCKR_OFFSET ))

#define GPIO_CRL_PIN_0_ID                 0
#define GPIO_CRL_PIN_1_ID                 4
#define GPIO_CRL_PIN_2_ID                 8
#define GPIO_CRL_PIN_3_ID                 12
#define GPIO_CRL_PIN_4_ID                 16
#define GPIO_CRL_PIN_5_ID                 20
#define GPIO_CRL_PIN_6_ID                 24
#define GPIO_CRL_PIN_7_ID                 28

#define GPIO_CRH_PIN_8_ID                 0
#define GPIO_CRH_PIN_9_ID                 4
#define GPIO_CRH_PIN_10_ID                8
#define GPIO_CRH_PIN_11_ID                12
#define GPIO_CRH_PIN_12_ID                16
#define GPIO_CRH_PIN_13_ID                20
#define GPIO_CRH_PIN_14_ID                24
#define GPIO_CRH_PIN_15_ID                28

#define GPIO_IDR_PIN_0_ID                 0
#define GPIO_IDR_PIN_1_ID                 1
#define GPIO_IDR_PIN_2_ID                 2
#define GPIO_IDR_PIN_3_ID                 3
#define GPIO_IDR_PIN_4_ID                 4
#define GPIO_IDR_PIN_5_ID                 5
#define GPIO_IDR_PIN_6_ID                 6
#define GPIO_IDR_PIN_7_ID                 7
#define GPIO_IDR_PIN_8_ID                 8
#define GPIO_IDR_PIN_9_ID                 9
#define GPIO_IDR_PIN_10_ID                10
#define GPIO_IDR_PIN_11_ID                11
#define GPIO_IDR_PIN_12_ID                12
#define GPIO_IDR_PIN_13_ID                13
#define GPIO_IDR_PIN_14_ID                14
#define GPIO_IDR_PIN_15_ID                15

#define GPIO_ODR_PIN_0_ID                 0
#define GPIO_ODR_PIN_1_ID                 1
#define GPIO_ODR_PIN_2_ID                 2
#define GPIO_ODR_PIN_3_ID                 3
#define GPIO_ODR_PIN_4_ID                 4
#define GPIO_ODR_PIN_5_ID                 5
#define GPIO_ODR_PIN_6_ID                 6
#define GPIO_ODR_PIN_7_ID                 7
#define GPIO_ODR_PIN_8_ID                 8
#define GPIO_ODR_PIN_9_ID                 9
#define GPIO_ODR_PIN_10_ID                10
#define GPIO_ODR_PIN_11_ID                11
#define GPIO_ODR_PIN_12_ID                12
#define GPIO_ODR_PIN_13_ID                13
#define GPIO_ODR_PIN_14_ID                14
#define GPIO_ODR_PIN_15_ID                15
			
#endif //  __GPIO_PRIVATE_H__