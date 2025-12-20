// Copyright RedemptionStudios


#include "Character/RedemptionEnemy.h"

#include "RedemptionsDescent/RedemptionsDescent.h"

ARedemptionEnemy::ARedemptionEnemy()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
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
