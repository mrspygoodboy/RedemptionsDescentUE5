// Copyright RedemptionStudios


#include "Actor/RedemptionEffectActor.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystem/RedemptionAttributeSet.h"
#include "Components/SphereComponent.h"

ARedemptionEffectActor::ARedemptionEffectActor()
{
	PrimaryActorTick.bCanEverTick = false;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);
	Sphere = CreateDefaultSubobject<USphereComponent>("Sphere");
	
	Sphere->SetupAttachment(GetRootComponent());
}

void ARedemptionEffectActor::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// TODO: Change this to apply a GameplayEffect, for now using const_cast
	 if (const IAbilitySystemInterface* ASCInterface = Cast<IAbilitySystemInterface>(OtherActor))
	 {
		 const URedemptionAttributeSet* RedemptionAttributeSet = Cast<URedemptionAttributeSet>
	 	(ASCInterface->GetAbilitySystemComponent()->GetAttributeSet(URedemptionAttributeSet::StaticClass()));
	 	
	 	URedemptionAttributeSet* MutableAuraAttributeSet = const_cast<URedemptionAttributeSet*>(RedemptionAttributeSet);
	 	MutableAuraAttributeSet->SetHealth(RedemptionAttributeSet->GetHealth() + 25.f);
	 	Destroy();
	 }
	 	
}

void ARedemptionEffectActor::EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	
}

void ARedemptionEffectActor::BeginPlay()
{
	Super::BeginPlay();
	
	Sphere->OnComponentBeginOverlap.AddDynamic(this, &ARedemptionEffectActor::OnOverlap);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &ARedemptionEffectActor::EndOverlap);
}


