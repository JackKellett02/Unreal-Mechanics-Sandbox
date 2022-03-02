// Fill out your copyright notice in the Description page of Project Settings.


#include "Tasks/CPP_PuzzleDoor.h"
#include "Tasks/CPP_PuzzleButton.h"

// Sets default values
ACPP_PuzzleDoor::ACPP_PuzzleDoor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Create and attach static mesh,
	doorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door"));
	doorMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);
}

// Called when the game starts or when spawned
void ACPP_PuzzleDoor::BeginPlay()
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
void ACPP_PuzzleDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Set desired position correctly.
	if (thisDoorsButton->GetButtonState())
	{
		moveToPos = endPos;

	}
	else
	{
		moveToPos = startPos;
	}

	//Check if the door is at the desired location.
	FVector dirVector = moveToPos - GetActorLocation();
	float distance = dirVector.Size();
	bool atLocation = (distance <= 5.0f);

	//Move the door.
	if (!atLocation)
	{
		//Calculate direction to desired pos.
		FVector dirToPos = moveToPos - GetActorLocation();
		dirToPos.Normalize();
		dirToPos *= speed;

		//Calculate new position for door.
		FVector newPos = GetActorLocation() + dirToPos;

		//Set the location to the new position.
		SetActorLocation(newPos);
	}
}

