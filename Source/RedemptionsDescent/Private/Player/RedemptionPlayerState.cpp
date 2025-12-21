// Copyright RedemptionStudios


#include "Player/RedemptionPlayerState.h"

#include "AbilitySystem/RedemptionAbilitySystemComponent.h"
#include "AbilitySystem/RedemptionAttributeSet.h"
#include "RedemptionsDescent/RedemptionsDescent.h"

ARedemptionPlayerState::ARedemptionPlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<URedemptionAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	
	AttributeSet = CreateDefaultSubobject<URedemptionAttributeSet>("AttributeSet");
	
	SetNetUpdateFrequency(NET_UPDATE_FREQUENCY);
}

UAbilitySystemComponent* ARedemptionPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

UAttributeSet* ARedemptionPlayerState::GetAttributeSet() const
{
	return AttributeSet;
}