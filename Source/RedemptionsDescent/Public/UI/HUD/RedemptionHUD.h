// Copyright RedemptionStudios

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "RedemptionHUD.generated.h"

class UAbilitySystemComponent;
struct FWidgetControllerParams;
class UOverlayWidgetController;
class URedemptionUserWidget;
class UAttributeSet;
/**
 * Responsible for creating and adding to viewport OverlayWidget and WidgetController(s)
 */
UCLASS()
class REDEMPTIONSDESCENT_API ARedemptionHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	UOverlayWidgetController* GetOverlayWidgetController(const FWidgetControllerParams& Params);
	
	
	UPROPERTY()
	TObjectPtr<URedemptionUserWidget> OverlayWidget;
	void InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS);

	
private:
	UPROPERTY(EditAnywhere)
	TSubclassOf<class URedemptionUserWidget> OverlayWidgetClass;
	
	UPROPERTY()
	TObjectPtr<UOverlayWidgetController> OverlayWidgetController;
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<UOverlayWidgetController> OverlayWidgetControllerClass;
	
};
