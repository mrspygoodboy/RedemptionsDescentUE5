// Copyright RedemptionStudios

#pragma once

#include "CoreMinimal.h"
#include "RedemptionCharacterBase.h"
#include "RedemptionCharacter.generated.h"

UCLASS()
class REDEMPTIONSDESCENT_API ARedemptionCharacter : public ARedemptionCharacterBase
{
	GENERATED_BODY()

public:
	ARedemptionCharacter();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
