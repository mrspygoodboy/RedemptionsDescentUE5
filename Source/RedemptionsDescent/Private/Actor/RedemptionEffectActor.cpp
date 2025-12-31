// Copyright RedemptionStudios


#include "Actor/RedemptionEffectActor.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystem/RedemptionAbilitySystemComponent.h"

ARedemptionEffectActor::ARedemptionEffectActor()
{
	PrimaryActorTick.bCanEverTick = false;
	SetRootComponent(CreateDefaultSubobject<USceneComponent>("SceneRoot"));
}

void ARedemptionEffectActor::BeginPlay()
{
	Super::BeginPlay();
}

void ARedemptionEffectActor::ApplyEffectToTarget(AActor* TargetActor, TSubclassOf<UGameplayEffect> GameplayEffectClass)
{
	UAbilitySystemComponent* TargetASC =  UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(TargetActor);
	if (TargetASC == nullptr) return;
	
	check(GameplayEffectClass);
	FGameplayEffectContextHandle EffectContextHandle = TargetASC->MakeEffectContext();
	EffectContextHandle.AddSourceObject(this);
	const FGameplayEffectSpecHandle EffectSpecHandle = TargetASC->MakeOutgoingSpec(GameplayEffectClass, ActorLevel, EffectContextHandle);
	const FActiveGameplayEffectHandle ActiveEffectHandle = TargetASC->ApplyGameplayEffectSpecToSelf(*EffectSpecHandle.Data.Get());
	
	const bool bIsInfinite = EffectSpecHandle.Data.Get()->Def.Get()->DurationPolicy == EGameplayEffectDurationType::Infinite;
	
	if (bIsInfinite && InfiniteEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnOverlap)
	{
		TTuple<UAbilitySystemComponent*, uint32> TargetASCToStackCount = ActiveEffectHandles.FindOrAdd(ActiveEffectHandle,TTuple<UAbilitySystemComponent*, uint32>(TargetASC, 0));
		TargetASCToStackCount.Value++;
		ActiveEffectHandles.Add(ActiveEffectHandle, TargetASCToStackCount);
	}
}

void ARedemptionEffectActor::OnOverlap(AActor* TargetActor)
{
	if (InstantEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnOverlap)
	{
		for (const auto InstantGameplayEffectClass : InstantGameplayEffectClasses)
		{
			ApplyEffectToTarget(TargetActor, InstantGameplayEffectClass);
			UE_LOG(LogTemp, Warning, TEXT("OnOverlap Instant"));
		}
	}
	
	if (DurationEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnOverlap)
	{
		for (const auto DurationGameplayEffectClass : DurationGameplayEffectClasses)
		{
			ApplyEffectToTarget(TargetActor, DurationGameplayEffectClass);
			UE_LOG(LogTemp, Warning, TEXT("OnOverlap Duration"));
		}
	}
	
	if (InfiniteEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnOverlap)
	{
		for (const auto InfiniteGameplayEffectClass : InfiniteGameplayEffectClasses)
		{
			ApplyEffectToTarget(TargetActor, InfiniteGameplayEffectClass);
			UE_LOG(LogTemp, Warning, TEXT("OnOverlap Infinite"));
		}
	}
}

/*
* Remove an array of effects:* Most of the changes are pretty straight forward except the Infinite one due to the stacks.
* What happened is to test it I had to use the FireArea effect multiple times in the same FireArea Actor,
* but since the Handle is the same, even though I apply 2 stacks of the effect, only one is removed (since we are using a map from Handle to TargetASC).
* To solve this I updated the Map to be from Handle to Tuple of TargetASC and Stack count to remove.
* This solves the issue...
 */

void ARedemptionEffectActor::OnEndOverlap(AActor* TargetActor)
{
	if (InstantEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnEndOverlap)
	{
		for (const auto GameplayEffectClass : InstantGameplayEffectClasses)
		{
			ApplyEffectToTarget(TargetActor, GameplayEffectClass);
		}
	}
	
	if (DurationEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnEndOverlap)
	{
		for (const auto DurationGameplayEffectClass : DurationGameplayEffectClasses)
		{
			ApplyEffectToTarget(TargetActor, DurationGameplayEffectClass);
		}
	}
	
	if (InfiniteEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnEndOverlap)
	{
		for (const auto InfiniteGameplayEffectClass : InfiniteGameplayEffectClasses)
		{
			ApplyEffectToTarget(TargetActor, InfiniteGameplayEffectClass);
		}
	}
	
	if (InfiniteEffectRemovalPolicy == EEffectRemovalPolicy::RemoveOnEndOverlap)
	{
		UAbilitySystemComponent* TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(TargetActor);
		if (!IsValid(TargetASC)) return;
		
		TArray<FActiveGameplayEffectHandle> HandlesToRemove;
		
		for (auto HandlePair : ActiveEffectHandles)
		{
			if (TargetASC == HandlePair.Value.Key)
			{
				TargetASC->RemoveActiveGameplayEffect(HandlePair.Key, 1);
				TargetASC->RemoveActiveGameplayEffect(HandlePair.Key, HandlePair.Value.Value);
				HandlesToRemove.Add(HandlePair.Key);
			}
		}
	}
}
	
