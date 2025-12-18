// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/RedemptionCharacterBase.h"

ARedemptionCharacterBase::ARedemptionCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;
	
	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void ARedemptionCharacterBase::BeginPlay()
{
	Super::BeginPlay();
}
