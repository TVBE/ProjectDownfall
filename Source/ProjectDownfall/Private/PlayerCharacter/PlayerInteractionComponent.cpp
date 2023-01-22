// Copyright 2023 Barrelhouse


#include "PlayerInteractionComponent.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"


// Sets default values for this component's properties
UPlayerInteractionComponent::UPlayerInteractionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPlayerInteractionComponent::BeginPlay()
{
	Super::BeginPlay();

	Controller = UGameplayStatics::GetPlayerController(GetWorld(),0);
	
}


// Called every frame
void UPlayerInteractionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	InteractionTrace();
}

FHitResult UPlayerInteractionComponent::InteractionTrace()
{
	
	const FVector StartTrace {Controller->GetPawn()->GetActorLocation()};
	const FVector EndTrace = StartTrace + InteractDistance;
	FCollisionShape Sphere = FCollisionShape::MakeSphere(InteractDistance);

	FHitResult HitResult;
	bool HasHit = GetWorld()->SweepSingleByChannel(
		HitResult,
		StartTrace,
		EndTrace,
		FQuat::Identity,
		ECC_GameTraceChannel1,
		Sphere
		);
	if(HasHit)
	{
		//UE_LOG(LogTemp,Display,TEXT("Interaction possible"));
		return HitResult;
	}
	else
	{
		//UE_LOG(LogTemp,Warning,TEXT("Nothing to interact"));
		return FHitResult(false);
	}
}


