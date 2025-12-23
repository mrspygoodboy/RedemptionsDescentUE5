// Copyright RedemptionStudios

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "RedemptionWidgetController.generated.h"


class UAttributeSet;
class UAbilitySystemComponent;

UCLASS()
class REDEMPTIONSDESCENT_API URedemptionWidgetController : public UObject
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(BlueprintReadWrite, Category="WidgetController")
	TObjectPtr<APlayerController> PlayerController;
	
	UPROPERTY(BlueprintReadWrite, Category="WidgetController")
	TObjectPtr<APlayerState> PlayerState;
	
	UPROPERTY(BlueprintReadWrite, Category="WidgetController")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
	
	UPROPERTY(BlueprintReadWrite, Category="WidgetController")
	TObjectPtr<UAttributeSet> AttributeSet;
};
