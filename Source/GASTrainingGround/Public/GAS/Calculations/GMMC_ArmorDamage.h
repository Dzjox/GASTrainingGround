// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayModMagnitudeCalculation.h"
#include "GMMC_ArmorDamage.generated.h"

/**
 * 
 */
UCLASS()
class GASTRAININGGROUND_API UGMMC_ArmorDamage : public UGameplayModMagnitudeCalculation
{
	GENERATED_BODY()

	UGMMC_ArmorDamage();

	virtual float CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const override;
	
	FGameplayEffectAttributeCaptureDefinition HealthDef;
	FGameplayEffectAttributeCaptureDefinition ArmorDef;
};
