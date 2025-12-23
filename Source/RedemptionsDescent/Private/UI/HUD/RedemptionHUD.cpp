// Copyright RedemptionStudios


#include "UI/HUD/RedemptionHUD.h"

#include "Blueprint/UserWidget.h"
#include "UI/Widget/RedemptionUserWidget.h"

void ARedemptionHUD::BeginPlay()
{
	Super::BeginPlay();
	
	UUserWidget* Widget =  CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
	Widget->AddToViewport();
}
