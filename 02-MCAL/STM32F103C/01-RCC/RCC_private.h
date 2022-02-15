/*************************************************************************/
/* Author        : Abdelrahman Hepish                                    */
/* File          : RCC_private.h                                         */
/* Date          : 5 NOV 2021                                            */
/* Version       : V01                                                   */
/* GitHub        : https://github.com/Abdelrahman-Hepish                 */
/*************************************************************************/
#ifndef __RCC_PRIVATE_H__
#define __RCC_PRIVATE_H__

#define  RCC_BASE_ADDRESS     0x40021000 
#define  RCC_CR_OFFSET       0x0 
#define  RCC_CFGR_OFFSET     0x4 
#define  RCC_CIR_OFFSET      0x8 
#define  RCC_APB2RSTR_OFFSET 0xC 
#define  RCC_APB1RSTR_OFFSET 0x10
#define  RCC_AHBENR_OFFSET   0x14 
#define  RCC_APB2ENR_OFFSET  0x18 
#define  RCC_APB1ENR_OFFSET  0x1C 
#define  RCC_BDCR_OFFSET     0x20 
#define  RCC_CSR_OFFSET		 0x24 


#define  RCC_CR              *((volatile u32 *)( RCC_BASE_ADDRESS + RCC_CR_OFFSET       ))
#define  RCC_CFGR            *((volatile u32 *)( RCC_BASE_ADDRESS + RCC_CFGR_OFFSET     ))
#define  RCC_CIR             *((volatile u32 *)( RCC_BASE_ADDRESS + RCC_CIR_OFFSET      ))
#define  RCC_APB2RSTR        *((volatile u32 *)( RCC_BASE_ADDRESS + RCC_APB2RSTR_OFFSET ))
#define  RCC_APB1RSTR        *((volatile u32 *)( RCC_BASE_ADDRESS + RCC_APB1RSTR_OFFSET ))
#define  RCC_AHBENR          *((volatile u32 *)( RCC_BASE_ADDRESS + RCC_AHBENR_OFFSET   ))
#define  RCC_APB2ENR         *((volatile u32 *)( RCC_BASE_ADDRESS + RCC_APB2ENR_OFFSET  ))
#define  RCC_APB1ENR         *((volatile u32 *)( RCC_BASE_ADDRESS + RCC_APB1ENR_OFFSET  ))
#define  RCC_BDCR     		 *((volatile u32 *)( RCC_BASE_ADDRESS + RCC_BDCR_OFFSET     ))
#define  RCC_CSR             *((volatile u32 *)( RCC_BASE_ADDRESS + RCC_CSR_OFFSET	   ))	)

#define RCC_CR_PLLON_PIN             24
#define RCC_CR_PLL_RDY_PIN           25 
#define RCC_CR_CSS_ON_PIN            19
#define RCC_CR_HSEBPY_PIN            18
#define RCC_CR_HSERDY_PIN            17
#define RCC_CR_HSEON_PIN             16
#define RCC_CR_HSICAL_START_PIN      8 
#define RCC_CR_HSITRIM_START_PIN     3
#define RCC_CR_HSIRDY_PIN            1
#define RCC_CR_HSION_PIN             0

#define PLLON_BIT_ID  3
#define HSION_BIT_ID  2
#define HSEON_BIT_ID  1
#define HSEBPY_BIT_ID 0
#define TRIM_STEP     40 

#define RCC_CFGR_MCO_START_PIN      24
#define RCC_CFGR_PLLSRC_PIN         16 
#define RCC_CFGR_PLLXTPRE_PIN       17 
#define RCC_CFGR_SW_PIN_0           0 
#define RCC_CFGR_SW_PIN_1           1
#define RCC_CFGR_SWS_PIN_0          2
#define RCC_CFGR_SWS_PIN_1          3
#define RCC_CFGR_PLLMULL_START_PIN  18
#define RCC_CFGR_HPRE_START_PIN     4
#define RCC_CFGR_PPRE1_START_PIN    8
#define RCC_CFGR_PPRE2_START_PIN    11

#define PLLSRC_BIT_ID                0 
#define PLLXTPRE_BIT_ID              1
#define SW_BIT_0_ID                  0 
#define SW_BIT_1_ID                  1

#define PRE1_BIT_0_ID                0
#define PRE1_BIT_1_ID                1
#define PRE1_BIT_2_ID                2
#define PRE2_BIT_0_ID                0
#define PRE2_BIT_1_ID                1
#define PRE2_BIT_2_ID                2
#endif  __RCC_PRIVATE_H__
