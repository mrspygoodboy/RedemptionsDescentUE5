// Copyright RedemptionStudios

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "RedemptionHUD.generated.h"

class URedemptionUserWidget;
/**
 * Responsible for creating and adding to viewport WBP_OverlayWidget
 */
UCLASS()
class REDEMPTIONSDESCENT_API ARedemptionHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	UPROPERTY()
	TObjectPtr<URedemptionUserWidget> OverlayWidget;
	
protected:	
	virtual void BeginPlay() override;
	
	
private:
	UPROPERTY(EditAnywhere)
	TSubclassOf<class URedemptionUserWidget> OverlayWidgetClass;
	
};
