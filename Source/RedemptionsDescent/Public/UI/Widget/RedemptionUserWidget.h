// Copyright RedemptionStudios

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "RedemptionUserWidget.generated.h"


UCLASS()
class REDEMPTIONSDESCENT_API URedemptionUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	void SetWidgetController(UObject* InWidgetController);
	
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UObject> WidgetController;
	
protected:
	// Kicked off when the WidgetController is set, when this is kicked it is safe to assume that the WidgetController
	// will be set
	UFUNCTION(BlueprintImplementableEvent)
	void WidgetControllerSet();
};
