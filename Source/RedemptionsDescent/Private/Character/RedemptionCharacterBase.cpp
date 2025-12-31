// Copyright RedemptionStudios

#include "Character/RedemptionCharacterBase.h"

ARedemptionCharacterBase::ARedemptionCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;
	
	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

UAbilitySystemComponent* ARedemptionCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

UAttributeSet* ARedemptionCharacterBase::GetAttributeSet() const
{
	return AttributeSet;
}

void ARedemptionCharacterBase::BeginPlay()
{
	Super::BeginPlay();
}

void ARedemptionCharacterBase::InitAbilityActorInfo()
{
}
