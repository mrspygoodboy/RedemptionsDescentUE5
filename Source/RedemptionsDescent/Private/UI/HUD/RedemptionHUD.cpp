// Copyright RedemptionStudios


#include "UI/HUD/RedemptionHUD.h"

#include "Blueprint/UserWidget.h"
#include "UI/Widget/RedemptionUserWidget.h"
#include "UI/WidgetController/OverlayWidgetController.h"

UOverlayWidgetController* ARedemptionHUD::GetOverlayWidgetController(const FWidgetControllerParams& Params)
{
	if (OverlayWidgetController == nullptr)
	{
		OverlayWidgetController = NewObject<UOverlayWidgetController>(this, OverlayWidgetControllerClass);
		OverlayWidgetController->SetWidgetControllerParams(Params);
		OverlayWidgetController->BindCallbacksToDependencies();
		return OverlayWidgetController;
	}

	return OverlayWidgetController;
}

/*
 * InitOverlay needs to create two things now, we need to create a Widget & a WidgetController
 */

void ARedemptionHUD::InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC,
	UAttributeSet* AS)
{
	checkf(OverlayWidgetClass, TEXT("OverlayWidgetClass is uninitialized, check BP_RedemptionHUD"));
	checkf(OverlayWidgetControllerClass, TEXT("OverlayWidgetController is uninitialized, check BP_RedemptionHUD"));
	
	UUserWidget* Widget =  CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
	OverlayWidget = Cast<URedemptionUserWidget>(Widget);
	
	const FWidgetControllerParams WidgetControllerParams(PC, PS, ASC, AS);
	UOverlayWidgetController* WidgetController = GetOverlayWidgetController(WidgetControllerParams);
	
	OverlayWidget->SetWidgetController(WidgetController);
	OverlayWidgetController->BroadcastInitialValues();
	
	Widget->AddToViewport();
}

