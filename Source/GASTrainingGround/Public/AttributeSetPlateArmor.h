// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GAS/Attributes/AttributeSetBase.h"
#include "AttributeSetPlateArmor.generated.h"

/**
 * 
 */
UCLASS()
class GASTRAININGGROUND_API UAttributeSetPlateArmor : public UAttributeSetBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_ArmorHealth_1)
	FGameplayAttributeData ArmorHealth_1;
	ATTRIBUTE_ACCESSORS(UAttributeSetPlateArmor, ArmorHealth_1)
	
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_ArmorHealth_2)
	FGameplayAttributeData ArmorHealth_2;
	ATTRIBUTE_ACCESSORS(UAttributeSetPlateArmor, ArmorHealth_2)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_ArmorHealth_3)
	FGameplayAttributeData ArmorHealth_3;
	ATTRIBUTE_ACCESSORS(UAttributeSetPlateArmor, ArmorHealth_3)

	UFUNCTION()
	virtual void OnRep_ArmorHealth_1(const FGameplayAttributeData& OldArmorHealth_1);

	UFUNCTION()
	virtual void OnRep_ArmorHealth_2(const FGameplayAttributeData& OldArmorHealth_2);

	UFUNCTION()
	virtual void OnRep_ArmorHealth_3(const FGameplayAttributeData& OldArmorHealth_3);

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	
};
