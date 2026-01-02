// Copyright RedemptionStudios

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "RedemptionAbilitySystemComponent.generated.h"

/**
 * 
 */

/* Broadcast this delegate from here and bind to it from the widget controller */
/* Any class that binds to EffectAssetTags will receive a TagContainer */
DECLARE_MULTICAST_DELEGATE_OneParam(FEffectAssetTags, const FGameplayTagContainer /*AssetTags*/);

UCLASS()
class REDEMPTIONSDESCENT_API URedemptionAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()
public:
	/* When this function is called we know that the AbilityActorInfo has been set */
	void AbilityActorInfoSet();
	
	
	FEffectAssetTags EffectAssetTags;
	
protected:
	/* This function is bound to a delegate from UAbilitySystemComponent, called on server when effect is applied to self */
	void EffectApplied
	(UAbilitySystemComponent* AbilitySystemComponent, const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle EffectHandle);
};
