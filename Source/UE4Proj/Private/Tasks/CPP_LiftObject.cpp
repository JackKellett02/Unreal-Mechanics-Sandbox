// Fill out your copyright notice in the Description page of Project Settings.


#include "Tasks/CPP_LiftObject.h"

#include <string>

#include "Components/BoxComponent.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ACPP_LiftObject::ACPP_LiftObject()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Create and attach static mesh,
	lift = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Lift"));
	lift->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);

	//Create and attach trigger.
	trigger = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger"));
	trigger->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);

	//Connect trigger to overlap function.
	trigger->OnComponentBeginOverlap.AddDynamic(this, &ACPP_LiftObject::OnTriggerBeginOverlap);
	trigger->OnComponentEndOverlap.AddDynamic(this, &ACPP_LiftObject::OnTriggerEndOverlap);
}

// Called when the game starts or when spawned
void ACPP_LiftObject::BeginPlay()
{
	Super::BeginPlay();

	//Set up start position.
	startPos = GetActorLocation();

	//Set up end pos.
	endPos = GetActorLocation() + endPos;

	//Set up move to pos.
	moveToPos = endPos;
}

// Called every frame
void ACPP_LiftObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Set desired position correctly.
	if (moveToEndPos)
	{
		moveToPos = endPos;

	}
	else
	{
		moveToPos = startPos;
	}

	//Check if the lift is at the desired location.
	FVector dirVector = moveToPos - GetActorLocation();
	float distance = dirVector.Size();
	bool atLocation = (distance <= 5.0f);

	//Move the lift.
	if (isMoving && !atLocation)
	{
		//Calculate direction to desired pos.
		FVector dirToPos = moveToPos - GetActorLocation();
		dirToPos.Normalize();
		dirToPos *= speed;

		//Calculate new position for lift.
		FVector newPos = GetActorLocation() + dirToPos;

		//Set the location to the new position.
		SetActorLocation(newPos);
	}
}

#pragma region Trigger Functions.
void ACPP_LiftObject::OnTriggerBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//Check if the overlapped actor is valid.
	ACharacter* tempChar = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	if (tempChar->GetUniqueID() == OtherActor->GetUniqueID())
	{
		isMoving = true;//Allow the lift to move.
	}
}

void ACPP_LiftObject::OnTriggerEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* otherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	//Check if the overlapped actor is valid.
	ACharacter* tempChar = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	float tempDist = FVector::Dist(lift->GetComponentLocation(), moveToPos);
	bool tempBool = (tempDist < 5.0f);
	if (tempChar->GetUniqueID() == otherActor->GetUniqueID() && tempBool)
	{
		//Stop the lift from moving and switch the target position for when the player gets back on the lift.
		isMoving = false;
		moveToEndPos = !moveToEndPos;
	}
}
#pragma endregion