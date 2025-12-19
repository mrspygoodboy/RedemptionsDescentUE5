// Copyright RedemptionStudios


#include "Player/RedemptionPlayerController.h"

#include "EnhancedInputSubsystems.h"

ARedemptionPlayerController::ARedemptionPlayerController()
{
	bReplicates = true;
}

void ARedemptionPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	check(RedemptionContext);
	
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(Subsystem);
	
	Subsystem->AddMappingContext(RedemptionContext, 0);
	
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Hand;
	
	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	
	SetInputMode(InputModeData);
}
