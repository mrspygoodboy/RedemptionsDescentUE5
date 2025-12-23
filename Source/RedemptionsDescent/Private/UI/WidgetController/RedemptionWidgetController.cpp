// Copyright RedemptionStudios


#include "UI/WidgetController/RedemptionWidgetController.h"

void URedemptionWidgetController::SetWidgetControllerParams(const FWidgetControllerParams& Params)
{
	PlayerController = Params.PlayerController;
	PlayerState = Params.PlayerState;
	AbilitySystemComponent = Params.AbilitySystemComponent;
	AttributeSet = Params.AttributeSet;
}

void URedemptionWidgetController::BroadcastInitialValues()
{
	
}
