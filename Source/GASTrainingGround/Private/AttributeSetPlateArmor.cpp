// Fill out your copyright notice in the Description page of Project Settings.


#include "AttributeSetPlateArmor.h"

#include "Net/UnrealNetwork.h"

void UAttributeSetPlateArmor::OnRep_ArmorHealth_1(const FGameplayAttributeData& OldArmorHealth_1)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAttributeSetPlateArmor, ArmorHealth_1, OldArmorHealth_1);
}

void UAttributeSetPlateArmor::OnRep_ArmorHealth_2(const FGameplayAttributeData& OldArmorHealth_2)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAttributeSetPlateArmor, ArmorHealth_2, OldArmorHealth_2);
}

void UAttributeSetPlateArmor::OnRep_ArmorHealth_3(const FGameplayAttributeData& OldArmorHealth_3)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAttributeSetPlateArmor, ArmorHealth_3, OldArmorHealth_3);
}

void UAttributeSetPlateArmor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION_NOTIFY(UAttributeSetPlateArmor, ArmorHealth_1, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAttributeSetPlateArmor, ArmorHealth_2, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAttributeSetPlateArmor, ArmorHealth_3, COND_None, REPNOTIFY_Always);
	
}
