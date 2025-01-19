// Fill out your copyright notice in the Description page of Project Settings.


#include "BlueprintFunctionLibraryMix.h"

FGameplayAttribute UBlueprintFunctionLibraryMix::GetAttributeFromEffect(TSubclassOf<UGameplayEffect> GameplayEffect)
{
	return GameplayEffect->GetDefaultObject<UGameplayEffect>()->Modifiers[0].Attribute;
}
