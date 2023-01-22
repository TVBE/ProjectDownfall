// Copyright 2023 Barrelhouse


#include "PlayerMovementSpline.h"
#include "ProjectDownfall/ProjectDownfall.h"
#include "Kismet/GameplayStatics.h"
#include "Components/SplineComponent.h"
#include "GameFramework/PawnMovementComponent.h"
#include "PlayerCharacter/PlayerCharacter.h"


// Sets default values
APlayerMovementSpline::APlayerMovementSpline()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	mySpline = CreateDefaultSubobject<USplineComponent>("MySpline",true);

}

//construction
void APlayerMovementSpline::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
}

// Called when the game starts or when spawned
void APlayerMovementSpline::BeginPlay()
{
	Super::BeginPlay();
	Player = UGameplayStatics::GetPlayerCharacter(GetWorld(),0);
	
}


// Called every frame
void APlayerMovementSpline::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	FVector ClosestPoint = mySpline->FindLocationClosestToWorldLocation(Player->GetActorLocation(),ESplineCoordinateSpace::World);
	FString ClosestPointString = ClosestPoint.ToCompactString();
	
	UE_LOG(LogPlayerSpline,Display,TEXT("%s"),*ClosestPointString);


	if(ShouldFollowSpline)
	{
		float Distance = ClosestPoint.DistXY(ClosestPoint,Player->GetActorLocation());
		if(Distance >= MaxMovementOffset)
		{
		Player->GetMovementComponent()->Velocity = FVector(0,0,0);
			
		}
	}

}

