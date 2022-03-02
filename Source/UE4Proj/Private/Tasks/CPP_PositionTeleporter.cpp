// Fill out your copyright notice in the Description page of Project Settings.


#include "Tasks/CPP_PositionTeleporter.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
ACPP_PositionTeleporter::ACPP_PositionTeleporter()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Create teleporter Mesh.
	teleporterMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("teleporter"));
	teleporterMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);

	//Create and attach trigger.
	trigger = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger"));
	trigger->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);

	//Connect trigger to overlap function.
	trigger->OnComponentBeginOverlap.AddDynamic(this, &ACPP_PositionTeleporter::OnTriggerBeginOverlap);
	trigger->OnComponentEndOverlap.AddDynamic(this, &ACPP_PositionTeleporter::OnTriggerEndOverlap);
}

// Called when the game starts or when spawned
void ACPP_PositionTeleporter::BeginPlay()
{
	Super::BeginPlay();
	teleportPos += GetActorLocation();
}

// Called every frame
void ACPP_PositionTeleporter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

#pragma region Trigger Functions.
void ACPP_PositionTeleporter::OnTriggerBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* otherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//Check if the overlapped actor is valid.
	ACharacter* tempChar = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	if (tempChar->GetUniqueID() == otherActor->GetUniqueID())
	{
		//Transport the player to the teleport position.
		tempChar->SetActorLocation(teleportPos);
	}
}

void ACPP_PositionTeleporter::OnTriggerEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* otherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{

}
#pragma endregion