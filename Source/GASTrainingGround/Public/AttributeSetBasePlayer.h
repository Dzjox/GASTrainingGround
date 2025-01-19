// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GAS/Attributes/AttributeSetBase.h"
#include "AttributeSetBasePlayer.generated.h"

/**
 * 
 */
UCLASS()
class GASTRAININGGROUND_API UAttributeSetBasePlayer : public UAttributeSetBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_Level)
	FGameplayAttributeData Level;
	ATTRIBUTE_ACCESSORS(UAttributeSetBasePlayer, Level)

	UFUNCTION()
	virtual void OnRep_Level(const FGameplayAttributeData& OldLevel);

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	
};
