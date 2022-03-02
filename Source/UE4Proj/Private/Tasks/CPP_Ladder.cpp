// Fill out your copyright notice in the Description page of Project Settings.


#include "Tasks/CPP_Ladder.h"
#include "Tasks/CPP_Character.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ACPP_Ladder::ACPP_Ladder()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Create teleporter Mesh.
	ladderMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ladder"));
	ladderMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);

	//Create and attach trigger.
	trigger = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger"));
	trigger->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);

	//Connect trigger to overlap function.
	trigger->OnComponentBeginOverlap.AddDynamic(this, &ACPP_Ladder::OnTriggerBeginOverlap);
	trigger->OnComponentEndOverlap.AddDynamic(this, &ACPP_Ladder::OnTriggerEndOverlap);
}

// Called when the game starts or when spawned
void ACPP_Ladder::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ACPP_Ladder::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

#pragma region Trigger Functions.
void ACPP_Ladder::OnTriggerBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ACPP_Character* tempChar = Cast<ACPP_Character>(OtherActor);
	if (tempChar)
	{
		tempChar->cppIsOnLadder = true;
	}
}

void ACPP_Ladder::OnTriggerEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	ACPP_Character* tempChar1 = Cast<ACPP_Character>(OtherActor);
	if (tempChar1) {
		tempChar1->cppIsOnLadder = false;
		ACharacter* tempChar2 = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
		tempChar2->GetCharacterMovement()->SetMovementMode(EMovementMode::MOVE_Walking, 0);//Allow the player to walk again when they get off the ladder.
	}
}
#pragma endregion