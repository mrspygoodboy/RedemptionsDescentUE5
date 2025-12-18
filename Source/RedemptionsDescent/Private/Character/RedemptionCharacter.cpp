// Fill out your copyright notice in the Description page of Project Settings.

#include "Character/RedemptionCharacter.h"

ARedemptionCharacter::ARedemptionCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ARedemptionCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ARedemptionCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ARedemptionCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

