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
	
	UFUNCTION(BlueprintCallable)
	void ApplyEffectToTarget(AActor* Target, TSubclassOf<UGameplayEffect> GameplayEffectClass);
	
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Applied Effects")
	TSubclassOf<UGameplayEffect> InstantGameplayEffectClass;
	
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Applied Effects")
	TSubclassOf<UGameplayEffect> DurationGameplayEffectClass;
};
