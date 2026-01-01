// Copyright RedemptionStudios


#include "AbilitySystem/RedemptionAbilitySystemComponent.h"

void URedemptionAbilitySystemComponent::AbilityActorInfoSet()
{
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &URedemptionAbilitySystemComponent::EffectApplied);
}

void URedemptionAbilitySystemComponent::EffectApplied(UAbilitySystemComponent* AbilitySystemComponent,
	const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle EffectHandle)
{
	GEngine->AddOnScreenDebugMessage(1, 8.f, FColor::Blue, FString("Effect Applied"));
}
