// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/Calculations/GMMC_AddHealth.h"
#include "GAS/Attributes/AttributeSetBase.h"

UGMMC_AddHealth::UGMMC_AddHealth()
{
	HealthDef.AttributeToCapture = UAttributeSetBase::GetArmorAttribute();
	HealthDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;
	HealthDef.bSnapshot = false;
	
	RelevantAttributesToCapture.Add(HealthDef);

	MaxHealthDef.AttributeToCapture = UAttributeSetBase::GetArmorAttribute();
	MaxHealthDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;
	MaxHealthDef.bSnapshot = false;
	
	RelevantAttributesToCapture.Add(MaxHealthDef);
}

float UGMMC_AddHealth::CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const
{
	const FGameplayTagContainer* SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
	const FGameplayTagContainer* TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();

	FAggregatorEvaluateParameters EvaluationParameters;
	EvaluationParameters.SourceTags = SourceTags;
	EvaluationParameters.TargetTags = TargetTags;

	float Health = 0.0f;
	GetCapturedAttributeMagnitude(HealthDef, Spec, EvaluationParameters, Health);

	float MaxHealth = 0.0f;
	GetCapturedAttributeMagnitude(MaxHealthDef, Spec, EvaluationParameters, MaxHealth);

	float Magnitude = 0.0f;
	Magnitude = Spec.GetSetByCallerMagnitude(FGameplayTag::RequestGameplayTag(FName("Data.Magnitude")));
	
	return FMath::Min(MaxHealth - Health, Magnitude);
}
