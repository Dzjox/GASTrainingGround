// Fill out your copyright notice in the Description page of Project Settings.


#include "AttributeSetBasePlayer.h"

#include "Net/UnrealNetwork.h"

void UAttributeSetBasePlayer::OnRep_Level(const FGameplayAttributeData& OldLevel)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAttributeSetBasePlayer, Level, OldLevel);
}

void UAttributeSetBasePlayer::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION_NOTIFY(UAttributeSetBasePlayer, Level, COND_None, REPNOTIFY_Always);
}
