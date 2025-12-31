// Copyright RedemptionStudios

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "RedemptionAbilitySystemComponent.generated.h"

/**
 * 
 */
UCLASS()
class REDEMPTIONSDESCENT_API URedemptionAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()
public:
	/* When this function is called we know that the AbilityActorInfo has been set */
	void AbilityActorInfoSet();
	
protected:
	/* This function is bound to a delegate from UAbilitySystemComponent, called on server when effect is applied to self */
	void EffectApplied
	(UAbilitySystemComponent* AbilitySystemComponent, const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle EffectHandle);
	
	
};
