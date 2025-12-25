// Copyright RedemptionStudios

#include "Character/RedemptionCharacter.h"

#include "AbilitySystemComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Player/RedemptionPlayerState.h"
#include "UI/HUD/RedemptionHUD.h"

ARedemptionCharacter::ARedemptionCharacter()
{
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 400.0f, 0.0f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;
	
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
}

void ARedemptionCharacter::InitAbilityActorInfo()
{
	ARedemptionPlayerState* RedemptionPlayerState = GetPlayerState<ARedemptionPlayerState>();
	check(RedemptionPlayerState);
	RedemptionPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(RedemptionPlayerState, this);
	AbilitySystemComponent = RedemptionPlayerState->GetAbilitySystemComponent();
	AttributeSet = RedemptionPlayerState->GetAttributeSet();
	
	if (APlayerController* RedemptionPlayerController = Cast<APlayerController>(GetController()))
	{
		ARedemptionHUD* RedemptionHUD = Cast<ARedemptionHUD>(RedemptionPlayerController->GetHUD());
		if (RedemptionHUD)
			RedemptionHUD->InitOverlay(RedemptionPlayerController, RedemptionPlayerState, AbilitySystemComponent, AttributeSet);
	} else
	{
		UE_LOG(LogTemp, Warning, TEXT("HUD is null?"));
	}
}

void ARedemptionCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	
	/* Init ability actor for the server */
	InitAbilityActorInfo();
}

void ARedemptionCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	
	/* Init ability actor for the client */
	InitAbilityActorInfo();
}
