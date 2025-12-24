// Copyright RedemptionStudios


#include "Actor/RedemptionEffectActor.h"


ARedemptionEffectActor::ARedemptionEffectActor()
{
	PrimaryActorTick.bCanEverTick = false;
	SetRootComponent(CreateDefaultSubobject<USceneComponent>("SceneRoot"));
}


void ARedemptionEffectActor::BeginPlay()
{
	Super::BeginPlay();

}


