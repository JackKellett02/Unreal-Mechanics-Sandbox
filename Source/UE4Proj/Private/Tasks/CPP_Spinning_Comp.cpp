// Fill out your copyright notice in the Description page of Project Settings.


#include "Tasks/CPP_Spinning_Comp.h"

// Sets default values for this component's properties
UCPP_Spinning_Comp::UCPP_Spinning_Comp() : rotationValue(360.0f), changeTimer(10.0f)
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UCPP_Spinning_Comp::BeginPlay()
{
	Super::BeginPlay();

	// ...
	rotationValue = publicRotation;
	changeTimer = publicTimer;
}


// Called every frame
void UCPP_Spinning_Comp::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	changeTimer -= DeltaTime;
	if (changeTimer <= 0)
	{
		rotationValue *= -1.0f;
		changeTimer = 3.0f;
	}
	else
	{
		AActor* owner = GetOwner();
		FRotator newRotation = owner->GetActorRotation();
		newRotation.Yaw += rotationValue * DeltaTime;
		owner->SetActorRotation(newRotation);
	}
}

