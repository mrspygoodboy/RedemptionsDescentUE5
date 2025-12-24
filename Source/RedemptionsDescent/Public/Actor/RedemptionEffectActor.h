// Copyright RedemptionStudios

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RedemptionEffectActor.generated.h"

class UGameplayEffect;

UCLASS()
class REDEMPTIONSDESCENT_API ARedemptionEffectActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ARedemptionEffectActor();

protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere, Category = "Applied Effects")
	TSubclassOf<UGameplayEffect> InstantGameplayEffectClass;

};
