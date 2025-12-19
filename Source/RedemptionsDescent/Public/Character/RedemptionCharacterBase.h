// Copyright RedemptionStudios

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "RedemptionCharacterBase.generated.h"

UCLASS(Abstract)
class REDEMPTIONSDESCENT_API ARedemptionCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	ARedemptionCharacterBase();

protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere, Category = "Combat")
	TObjectPtr<USkeletalMeshComponent> Weapon;
};
