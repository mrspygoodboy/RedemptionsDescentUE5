// Copyright RedemptionStudios


#include "UI/WidgetController/OverlayWidgetController.h"

#include "AbilitySystem/RedemptionAttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	const URedemptionAttributeSet* RedemptionAttributeSet = CastChecked<URedemptionAttributeSet>(AttributeSet);
	OnHealthChanged.Broadcast(RedemptionAttributeSet->GetHealth());
	OnMaxHealthChanged.Broadcast(RedemptionAttributeSet->GetMaxHealth());
	
	OnManaChanged.Broadcast(RedemptionAttributeSet->GetMana());
	OnMaxManaChanged.Broadcast(RedemptionAttributeSet->GetMaxMana());
}

void UOverlayWidgetController::BindCallbacksToDependencies()
{
	const URedemptionAttributeSet* RedemptionAttributeSet = CastChecked<URedemptionAttributeSet>(AttributeSet);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate
	(RedemptionAttributeSet->GetHealthAttribute()).AddUObject(this, &UOverlayWidgetController::HealthChanged);
	
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate
	(RedemptionAttributeSet->GetMaxHealthAttribute()).AddUObject(this, &UOverlayWidgetController::MaxHealthChanged);
	
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate
	(RedemptionAttributeSet->GetManaAttribute()).AddUObject(this, &UOverlayWidgetController::ManaChanged);
	
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate
	(RedemptionAttributeSet->GetMaxManaAttribute()).AddUObject(this, &UOverlayWidgetController::MaxManaChanged);
}

void UOverlayWidgetController::HealthChanged(const FOnAttributeChangeData& Data) const
{
	OnHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxHealthChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::ManaChanged(const FOnAttributeChangeData& Data) const
{
	OnManaChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxManaChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxManaChanged.Broadcast(Data.NewValue);
}
