/*************************************************************************/
/* Author        : Abdelrahman Hepish                                    */
/* File          : Nvic_program.c                                        */
/* Date          : 5 Dec 2021                                            */
/* Version       : V01                                                   */
/* GitHub        : https://github.com/Abdelrahman-Hepish                 */
/*************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"
void NVIC_voidEnablePerInterrupt(tNVIC_tPeripheral Copy_u8PeripheralName) 
{
	 if(Copy_u8PeripheralName <= NVIC_I2C1_EV ) 
	 {
		 SET_BIT(NVIC_ISER0,Copy_u8PeripheralName) ; 
	 }else 
	 {
		Copy_u8PeripheralName -=  NVIC_I2C1_ER ; 
		SET_BIT(NVIC_ISER1,Copy_u8PeripheralName) ;  
	 }
}
void NVIC_voidDisablePerInterrupt(tNVIC_tPeripheral Copy_u8PeripheralName) 
{
	 if(Copy_u8PeripheralName <= NVIC_I2C1_EV ) 
	 {
		 SET_BIT(NVIC_ICER0,Copy_u8PeripheralName) ; 
	 }else 
	 {
		Copy_u8PeripheralName -=  NVIC_I2C1_ER ; 
		SET_BIT(NVIC_ICER1,Copy_u8PeripheralName) ;  
	 }
}
void NVIC_voidSetPendingFlagPerInterrupt(tNVIC_tPeripheral Copy_u8PeripheralName) 
{
	 if(Copy_u8PeripheralName <= NVIC_I2C1_EV ) 
	 {
		 SET_BIT(NVIC_ISPR0,Copy_u8PeripheralName) ; 
	 }else 
	 {
		Copy_u8PeripheralName -=  NVIC_I2C1_ER ; 
		SET_BIT(NVIC_ISPR1,Copy_u8PeripheralName) ;  
	 }
}
void NVIC_voidClearPendingFlagPerInterrupt(tNVIC_tPeripheral Copy_u8PeripheralName) 
{
	 if(Copy_u8PeripheralName <= NVIC_I2C1_EV ) 
	 {
		 SET_BIT(NVIC_ICPR0,Copy_u8PeripheralName) ; 
	 }else 
	 {
		Copy_u8PeripheralName -=  NVIC_I2C1_ER ; 
		SET_BIT(NVIC_ICPR1,Copy_u8PeripheralName) ;  
	 }
}
tNVIC_ActiveFlagStatus NVIC_u8GetActiveFlagStatus(tNVIC_tPeripheral Copy_u8PeripheralName) 
{
	tNVIC_ActiveFlagStatus ret = NVIC_ACTIVE_FLAG_DISABLED ; 
     if(Copy_u8PeripheralName <= NVIC_I2C1_EV ) 
	 {
		ret =  GET_BIT(NVIC_IABR0,Copy_u8PeripheralName) ; 
	 }else 
	 {
		Copy_u8PeripheralName -=  NVIC_I2C1_ER ; 
		ret =  GET_BIT(NVIC_IABR1,Copy_u8PeripheralName) ;  
	 }
	 return ret ; 
}
void NVIC_voidSetInterruptGroup_SubGroup_16G_0S(tNVIC_tPeripheral PeripheralId,u8 Copy_u8Group,u8 Copy_u8Sub)
{
	u8 Copy_u8LocalPrioritySystem = (Copy_u8Group) ; 
	if(PeripheralId >= EXTERNAL_INTERRUPTS_START_POSITION ) 
	{
		MAN_NIBBLE(NVIC_IPR[PeripheralId],PRIORITY_NIPPLE_START_POSITION,Copy_u8LocalPrioritySystem) ; 
	} 
}
void NVIC_voidSetInterruptGroup_SubGroup_8G_2S(tNVIC_tPeripheral PeripheralId,u8 Copy_u8Group,u8 Copy_u8Sub)
{
	u8 Copy_u8LocalPrioritySystem = (Copy_u8Sub | (Copy_u8Group << 1 )) ; 
	if(PeripheralId >= EXTERNAL_INTERRUPTS_START_POSITION ) 
	{
		MAN_NIBBLE(NVIC_IPR[PeripheralId],PRIORITY_NIPPLE_START_POSITION,Copy_u8LocalPrioritySystem) ; 
	}
}
void NVIC_voidSetInterruptGroup_SubGroup_4G_4S(tNVIC_tPeripheral PeripheralId,u8 Copy_u8Group,u8 Copy_u8Sub)
{
	u8 Copy_u8LocalPrioritySystem = (Copy_u8Sub | (Copy_u8Group << 2 )) ; 
	if(PeripheralId >= EXTERNAL_INTERRUPTS_START_POSITION ) 
	{
		MAN_NIBBLE(NVIC_IPR[PeripheralId],PRIORITY_NIPPLE_START_POSITION,Copy_u8LocalPrioritySystem) ; 
	}
}
void NVIC_voidSetInterruptGroup_SubGroup_2G_8S(tNVIC_tPeripheral PeripheralId,u8 Copy_u8Group,u8 Copy_u8Sub)
{
    u8 Copy_u8LocalPrioritySystem = (Copy_u8Sub | (Copy_u8Group << 3 )) ; 
	if(PeripheralId >= EXTERNAL_INTERRUPTS_START_POSITION ) 
	{
		MAN_NIBBLE(NVIC_IPR[PeripheralId],PRIORITY_NIPPLE_START_POSITION,Copy_u8LocalPrioritySystem) ; 
	}
}	
void NVIC_voidSetInterruptGroup_SubGroup_0G_16S(tNVIC_tPeripheral PeripheralId,u8 Copy_u8Group,u8 Copy_u8Sub)
{
	u8 Copy_u8LocalPrioritySystem = (Copy_u8Sub)  ; 
	if(PeripheralId >= EXTERNAL_INTERRUPTS_START_POSITION ) 
	{
		MAN_NIBBLE(NVIC_IPR[PeripheralId],PRIORITY_NIPPLE_START_POSITION,Copy_u8LocalPrioritySystem) ; 
	}
}
