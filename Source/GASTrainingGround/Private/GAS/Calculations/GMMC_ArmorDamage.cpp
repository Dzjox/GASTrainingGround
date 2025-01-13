// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/Calculations/GMMC_ArmorDamage.h"

#include "EditorCategoryUtils.h"
#include "GAS/Attributes/AttributeSetBase.h"

UGMMC_ArmorDamage::UGMMC_ArmorDamage()
{
	ArmorDef.AttributeToCapture = UAttributeSetBase::GetArmorAttribute();
	ArmorDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;
	ArmorDef.bSnapshot = false;
	
	RelevantAttributesToCapture.Add(ArmorDef);
}

float UGMMC_ArmorDamage::CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const
{
	const FGameplayTagContainer* SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
	const FGameplayTagContainer* TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();

	FAggregatorEvaluateParameters EvaluationParameters;
	EvaluationParameters.SourceTags = SourceTags;
	EvaluationParameters.TargetTags = TargetTags;

	float Armor = 0.0f;
	GetCapturedAttributeMagnitude(ArmorDef, Spec, EvaluationParameters, Armor);

	float Damage = 0.0f;
	Damage = Spec.GetSetByCallerMagnitude(FGameplayTag::RequestGameplayTag(FName("Data.Damage")));
	
	return FMath::Min(Armor - Damage, -1);
}
