// Copyright RedemptionStudios

#include "Character/RedemptionCharacter.h"

#include "AbilitySystemComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Player/RedemptionPlayerState.h"

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

void ARedemptionCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	
	/* Init ability actor for the server */
	ARedemptionPlayerState* RedemptionPlayerState = GetPlayerState<ARedemptionPlayerState>();
	check(RedemptionPlayerState);
	RedemptionPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(RedemptionPlayerState, this);
	AbilitySystemComponent = RedemptionPlayerState->GetAbilitySystemComponent();
	AttributeSet = RedemptionPlayerState->GetAttributeSet();
}

void ARedemptionCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	
	/* Init ability actor for the client */
	ARedemptionPlayerState* RedemptionPlayerState = GetPlayerState<ARedemptionPlayerState>();
	check(RedemptionPlayerState);
	RedemptionPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(RedemptionPlayerState, this);
	AbilitySystemComponent = RedemptionPlayerState->GetAbilitySystemComponent();
	AttributeSet = RedemptionPlayerState->GetAttributeSet();
}
