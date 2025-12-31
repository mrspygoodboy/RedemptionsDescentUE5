// Copyright RedemptionStudios

#pragma once

#include "CoreMinimal.h"
#include "Character/RedemptionCharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include "RedemptionEnemy.generated.h"

class UAbilitySystemComponent;
class UAttributeSet;

/**
 * 
 */
UCLASS()
class REDEMPTIONSDESCENT_API ARedemptionEnemy : public ARedemptionCharacterBase, public IEnemyInterface
{
	GENERATED_BODY()
	ARedemptionEnemy();
public:
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bHighlighted = false;
	
protected:
	virtual void BeginPlay() override;
	virtual void InitAbilityActorInfo() override;
	
};
