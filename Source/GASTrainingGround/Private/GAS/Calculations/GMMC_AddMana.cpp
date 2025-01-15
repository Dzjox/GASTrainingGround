// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/Calculations/GMMC_AddMana.h"
#include "GAS/Attributes/AttributeSetBase.h"

UGMMC_AddMana::UGMMC_AddMana()
{
	ManaDef.AttributeToCapture = UAttributeSetBase::GetManaAttribute();
	ManaDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;
	ManaDef.bSnapshot = false;
	
	RelevantAttributesToCapture.Add(ManaDef);

	MaxManaDef.AttributeToCapture = UAttributeSetBase::GetMaxManaAttribute();
	MaxManaDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;
	MaxManaDef.bSnapshot = false;
	
	RelevantAttributesToCapture.Add(MaxManaDef);
}

float UGMMC_AddMana::CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const
{
	const FGameplayTagContainer* SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
	const FGameplayTagContainer* TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();

	FAggregatorEvaluateParameters EvaluationParameters;
	EvaluationParameters.SourceTags = SourceTags;
	EvaluationParameters.TargetTags = TargetTags;

	float Mana = 0.0f;
	GetCapturedAttributeMagnitude(ManaDef, Spec, EvaluationParameters, Mana);

	float MaxMana = 0.0f;
	GetCapturedAttributeMagnitude(MaxManaDef, Spec, EvaluationParameters, MaxMana);

	float Magnitude = 0.0f;
	Magnitude = Spec.GetSetByCallerMagnitude(FGameplayTag::RequestGameplayTag(FName("Data.Magnitude")));
	
	return FMath::Min(MaxMana - Mana, Magnitude);
}
