// Fill out your copyright notice in the Description page of Project Settings.


#include "Tasks/CPP_PuzzleButton.h"
#include "Tasks/CPP_PushableBox.h"
#include "Components/BoxComponent.h"

// Sets default values
ACPP_PuzzleButton::ACPP_PuzzleButton() : buttonActive(false)
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Create and attach static mesh,
	buttonMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("buttonMesh"));
	buttonMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);

	//Create and attach trigger.
	buttonTrigger = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger"));
	buttonTrigger->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);

	//Connect trigger to overlap function.
	buttonTrigger->OnComponentBeginOverlap.AddDynamic(this, &ACPP_PuzzleButton::OnTriggerBeginOverlap);
	buttonTrigger->OnComponentEndOverlap.AddDynamic(this, &ACPP_PuzzleButton::OnTriggerEndOverlap);
}

// Called when the game starts or when spawned
void ACPP_PuzzleButton::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ACPP_PuzzleButton::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


bool ACPP_PuzzleButton::GetButtonState()
{
	return buttonActive;
}

#pragma region Trigger Functions.
void ACPP_PuzzleButton::OnTriggerBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ACPP_PushableBox* testBox = Cast<ACPP_PushableBox>(OtherActor);
	if (testBox)
	{
		buttonActive = true;
	}
}

void ACPP_PuzzleButton::OnTriggerEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	ACPP_PushableBox* testBox = Cast<ACPP_PushableBox>(OtherActor);
	if (testBox)
	{
		buttonActive = false;
	}
}
#pragma endregion