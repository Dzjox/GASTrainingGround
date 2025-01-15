// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayModMagnitudeCalculation.h"
#include "GMMC_AddMana.generated.h"

/**
 * 
 */
UCLASS()
class GASTRAININGGROUND_API UGMMC_AddMana : public UGameplayModMagnitudeCalculation
{
	GENERATED_BODY()

	UGMMC_AddMana();

	virtual float CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const override;
	
	FGameplayEffectAttributeCaptureDefinition ManaDef;
	FGameplayEffectAttributeCaptureDefinition MaxManaDef;
	
};
