// Copyright RedemptionStudios

#pragma once

#include "CoreMinimal.h"
#include "RedemptionCharacterBase.h"
#include "RedemptionCharacter.generated.h"

class ARedemptionPlayerState;

UCLASS()
class REDEMPTIONSDESCENT_API ARedemptionCharacter : public ARedemptionCharacterBase
{
	GENERATED_BODY()

public:
	ARedemptionCharacter();
	void InitAbilityActorInfo();
	virtual void PossessedBy(AController* NewController) override;
	
	virtual void OnRep_PlayerState() override;
	
private:

};
