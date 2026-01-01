// Copyright RedemptionStudios


#include "Character/RedemptionEnemy.h"
#include "AbilitySystem/RedemptionAbilitySystemComponent.h"
#include "AbilitySystem/RedemptionAttributeSet.h"
#include "RedemptionsDescent/RedemptionsDescent.h"

ARedemptionEnemy::ARedemptionEnemy()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
	
	AbilitySystemComponent = CreateDefaultSubobject<URedemptionAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);
	
	AttributeSet = CreateDefaultSubobject<URedemptionAttributeSet>("AttributeSet");
}

void ARedemptionEnemy::HighlightActor()
{
	bHighlighted = true;
	GetMesh()->SetRenderCustomDepth(true);
	GetMesh()->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
	Weapon->SetRenderCustomDepth(true);
	Weapon->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
	UE_LOG(LogTemp, Warning, TEXT("Highlight Actor"));
}

void ARedemptionEnemy::UnHighlightActor()
{
	bHighlighted = false;
	GetMesh()->SetRenderCustomDepth(false);
	Weapon->SetRenderCustomDepth(false);
	UE_LOG(LogTemp, Warning, TEXT("Unhighlight Actor"));
}

void ARedemptionEnemy::BeginPlay()
{
	Super::BeginPlay();
	InitAbilityActorInfo();
}


void ARedemptionEnemy::InitAbilityActorInfo()
{
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
	Cast<URedemptionAbilitySystemComponent>(AbilitySystemComponent)->AbilityActorInfoSet();
}
