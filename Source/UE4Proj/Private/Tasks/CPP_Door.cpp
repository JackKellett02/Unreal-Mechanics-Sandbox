// Fill out your copyright notice in the Description page of Project Settings.


#include "Tasks/CPP_Door.h"

#include "Components/BoxComponent.h"

// Sets default values
ACPP_Door::ACPP_Door()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Create and attach static mesh,
	door = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door"));
	door->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);

	//Create and attach trigger.
	trigger = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger"));
	trigger->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);

	//Create and attach trigger2.
	trigger2 = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger2"));
	trigger2->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);

	//Connect trigger to overlap function.
	trigger->OnComponentBeginOverlap.AddDynamic(this, &ACPP_Door::OnTriggerBeginOverlap);
	trigger->OnComponentEndOverlap.AddDynamic(this, &ACPP_Door::OnTriggerEndOverlap);

	//Connect trigger2 to overlap function.
	trigger2->OnComponentBeginOverlap.AddDynamic(this, &ACPP_Door::OnTrigger2BeginOverlap);
	trigger2->OnComponentEndOverlap.AddDynamic(this, &ACPP_Door::OnTrigger2EndOverlap);
}

// Called when the game starts or when spawned
void ACPP_Door::BeginPlay()
{
	Super::BeginPlay();

	//Should door open.
	shouldDoorBeOpen = false;
	shouldDoorBeOpenOtherWay = false;

	//Set the starting rotation.
	startingRotation = GetActorRotation();

	//Set the desired rotation.
	desiredRotation = startingRotation;
	desiredRotation.Yaw += 90.0f;
}

// Called every frame
void ACPP_Door::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (shouldDoorBeOpen)
	{
		//Open door in direction 1.
		FRotator tempRotator = GetActorRotation();
		tempRotator = FMath::Lerp(tempRotator, desiredRotation, 0.1f);
		SetActorRotation(tempRotator);
	}
	else if (shouldDoorBeOpenOtherWay)
	{
		//Open door in the other direction.
		FRotator tempRotator = GetActorRotation();
		FRotator otherDir = desiredRotation;
		otherDir.Yaw = -otherDir.Yaw;
		tempRotator = FMath::Lerp(tempRotator, otherDir, 0.1f);
		SetActorRotation(tempRotator);
	}
	else
	{
		//Close the door.
		FRotator tempRotator = GetActorRotation();
		tempRotator = FMath::Lerp(tempRotator, startingRotation, 0.1f);
		SetActorRotation(tempRotator);
	}
}

#pragma region Trigger functions for the door.
void ACPP_Door::OnTriggerBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	shouldDoorBeOpen = true;
}

void ACPP_Door::OnTriggerEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* otherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	shouldDoorBeOpen = false;
}

void ACPP_Door::OnTrigger2BeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	shouldDoorBeOpenOtherWay = true;
}

void ACPP_Door::OnTrigger2EndOverlap(UPrimitiveComponent* OverlappedComp, AActor* otherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	shouldDoorBeOpenOtherWay = false;
}
#pragma endregion