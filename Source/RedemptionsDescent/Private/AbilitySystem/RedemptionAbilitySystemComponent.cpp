// Copyright RedemptionStudios


#include "AbilitySystem/RedemptionAbilitySystemComponent.h"

void URedemptionAbilitySystemComponent::AbilityActorInfoSet()
{
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &URedemptionAbilitySystemComponent::EffectApplied);
}

void URedemptionAbilitySystemComponent::EffectApplied(UAbilitySystemComponent* AbilitySystemComponent,
	const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle EffectHandle)
{
	FGameplayTagContainer TagContainer;
	EffectSpec.GetAllAssetTags(TagContainer);
	
	/* Any class that binds to EffectAssetTags will receive a TagContainer
	 * The ability system component is going to broadcast the @TagContainer (AssetTags)
	 * in response to any effect being applied to it, and it is going to send this tag container. */
	
	EffectAssetTags.Broadcast(TagContainer);
}
