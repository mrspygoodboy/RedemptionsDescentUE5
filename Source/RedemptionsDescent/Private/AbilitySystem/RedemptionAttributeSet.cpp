// Copyright RedemptionStudios


#include "AbilitySystem/RedemptionAttributeSet.h"
#include "Net/UnrealNetwork.h"

URedemptionAttributeSet::URedemptionAttributeSet()
{
	InitHealth(25.f);
	InitMaxHealth(100.f);
	InitMana(50.f);
	InitMaxMana(60.f);
}

void URedemptionAttributeSet::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	
	DOREPLIFETIME_CONDITION_NOTIFY(URedemptionAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URedemptionAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	
	DOREPLIFETIME_CONDITION_NOTIFY(URedemptionAttributeSet, Mana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URedemptionAttributeSet, MaxMana, COND_None, REPNOTIFY_Always);
}

void URedemptionAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URedemptionAttributeSet, Health, OldHealth);
}

void URedemptionAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URedemptionAttributeSet, MaxHealth, OldMaxHealth);
}

void URedemptionAttributeSet::OnRep_Mana(const FGameplayAttributeData& OldMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URedemptionAttributeSet, Mana, OldMana);
}

void URedemptionAttributeSet::OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URedemptionAttributeSet, MaxMana, OldMaxMana);
}
