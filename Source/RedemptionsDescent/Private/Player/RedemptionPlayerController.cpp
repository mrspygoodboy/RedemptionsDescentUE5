// Copyright RedemptionStudios


#include "Player/RedemptionPlayerController.h"

#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Interaction/EnemyInterface.h"

ARedemptionPlayerController::ARedemptionPlayerController()
{
	bReplicates = true;
}

void ARedemptionPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
	CursorTrace();
}

void ARedemptionPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	check(RedemptionContext);
	
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	
	if (Subsystem)
		Subsystem->AddMappingContext(RedemptionContext, 0);
	
	
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Hand;
	
	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	
	SetInputMode(InputModeData);
}

void ARedemptionPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	
	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);
	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ARedemptionPlayerController::Move);
}

void ARedemptionPlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();
	
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);
	
	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	
	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
	}
}

void ARedemptionPlayerController::CursorTrace()
{
	FHitResult CursorHit;
	GetHitResultUnderCursor(ECC_Visibility, false, CursorHit);
	
	if (!CursorHit.bBlockingHit) return;
	
	LastActor = ThisActor;
	
	ThisActor = CursorHit.GetActor();
	
	/*
	 * Line trace from cursor, There are several scenarios:
	 * A. LastActor is null && ThisActor is null
	 *		- Do nothing
	 * B. LastActor is null && ThisActor is valid (If LastActor is null we know that this is the first frame that we are hovering over this actor)
	 *		- Highlight () This Actor
	 * C. LastActor is valid && ThisActor is null  (LastActor is valid but ThisActor is not which means we were hovering over this Actor, but now we're not)
	 *		- UnHighlight() LastActor
	 * D. Both are valid, but LastActor != ThisActor (We were hovering over some enemy, but now we're highlighting over some other enemy)
	 *		- UnHighlight LastActor, and Highlight ThisActor
	 * E. Both are valid, and are the same actor?
	 *      - Do nothing
 	 */
	
	if (LastActor == nullptr)
	{
		if (ThisActor != nullptr)
		{
			// Case B
			ThisActor->HighlightActor();
		} else { /* Case A */ }
	} else // LastActor is valid
	{
		if (ThisActor == nullptr)
		{
			// Case C
			LastActor->UnHighlightActor();
		} else 
		{
			if (LastActor != ThisActor)
			{
				// Case D
				LastActor->UnHighlightActor();
				ThisActor->HighlightActor();
			} else
			{
				// Case E - Do nothing
			}
		}
	}
}
