// Copyright RedemptionStudios

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "RedemptionPlayerController.generated.h"

class UInputMappingContext;

/**
 * 
 */
UCLASS()
class REDEMPTIONSDESCENT_API ARedemptionPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ARedemptionPlayerController();
	
protected:	
	virtual void BeginPlay() override;
	
private:
	TObjectPtr<UInputMappingContext> RedemptionContext;
};
