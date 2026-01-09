// Copyright RedemptionStudios


#include "UI/WidgetController/OverlayWidgetController.h"

#include "AbilitySystem/RedemptionAbilitySystemComponent.h"
#include "AbilitySystem/RedemptionAttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	const URedemptionAttributeSet* RedemptionAttributeSet = CastChecked<URedemptionAttributeSet>(AttributeSet);
	
	/* broadcast attribute initial values */
	OnHealthChanged.Broadcast(RedemptionAttributeSet->GetHealth());
	OnMaxHealthChanged.Broadcast(RedemptionAttributeSet->GetMaxHealth());
	
	OnManaChanged.Broadcast(RedemptionAttributeSet->GetMana());
	OnMaxManaChanged.Broadcast(RedemptionAttributeSet->GetMaxMana());
}

void UOverlayWidgetController::BindCallbacksToDependencies()
{
	/* bind callbacks functions to attributes */
	const URedemptionAttributeSet* RedemptionAttributeSet = CastChecked<URedemptionAttributeSet>(AttributeSet);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate
	(RedemptionAttributeSet->GetHealthAttribute()).AddUObject(this, &UOverlayWidgetController::HealthChanged);
	
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate
	(RedemptionAttributeSet->GetMaxHealthAttribute()).AddUObject(this, &UOverlayWidgetController::MaxHealthChanged);
	
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate
	(RedemptionAttributeSet->GetManaAttribute()).AddUObject(this, &UOverlayWidgetController::ManaChanged);
	
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate
	(RedemptionAttributeSet->GetMaxManaAttribute()).AddUObject(this, &UOverlayWidgetController::MaxManaChanged);
	
	Cast<URedemptionAbilitySystemComponent>(AbilitySystemComponent)->EffectAssetTags.AddLambda(
		[this](const FGameplayTagContainer& AssetTags)
		{
			for (const FGameplayTag& Tag : AssetTags)
			{
				// For example, say that Tag = Message.HealthPotion
				// "Message.HealthPotion".MatchesTag("Message") will return True, "Message".MatchesTag("Message.HealthPotion") will return False
				FGameplayTag MessageTag = FGameplayTag::RequestGameplayTag(FName("Message"));
				
				if (Tag.MatchesTag(MessageTag))
				{
					/* Find the name of the row associated with the given tag */
					FUIWidgetRow* Row = GetDataTableRowByTag<FUIWidgetRow>(MessageWidgetDataTable, Tag);
					MessageWidgetRowDelegate.Broadcast(*Row);	
				}
			}
		});
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