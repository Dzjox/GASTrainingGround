// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "GameplayEffect.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BlueprintFunctionLibraryMix.generated.h"

/**
 * 
 */
UCLASS()
class GASTRAININGGROUND_API UBlueprintFunctionLibraryMix : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject", CallableWithoutWorldContext))
	static FGameplayAttribute GetAttributeFromEffect(TSubclassOf<UGameplayEffect> GameplayEffect);
};
