// Copyright RedemptionStudios


#include "UI/WidgetController/OverlayWidgetController.h"

#include "AbilitySystem/RedemptionAttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	const URedemptionAttributeSet* RedemptionAttributeSet = CastChecked<URedemptionAttributeSet>(AttributeSet);
	OnHealthChanged.Broadcast(RedemptionAttributeSet->GetHealth());
	OnMaxHealthChanged.Broadcast(RedemptionAttributeSet->GetMaxHealth());
}
