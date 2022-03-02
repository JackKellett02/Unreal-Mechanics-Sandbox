// Fill out your copyright notice in the Description page of Project Settings.


#include "Tasks/CPP_LevelTeleporter.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"

// Sets default values 
ACPP_LevelTeleporter::ACPP_LevelTeleporter()
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
	trigger->OnComponentBeginOverlap.AddDynamic(this, &ACPP_LevelTeleporter::OnTriggerBeginOverlap);
	trigger->OnComponentEndOverlap.AddDynamic(this, &ACPP_LevelTeleporter::OnTriggerEndOverlap);
}

// Called when the game starts or when spawned
void ACPP_LevelTeleporter::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ACPP_LevelTeleporter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

#pragma region Trigger Functions.
void ACPP_LevelTeleporter::OnTriggerBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("Overlap began1"));
	ACharacter* tempChar = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	if (tempChar->GetUniqueID() == OtherActor->GetUniqueID())
	{
		UE_LOG(LogTemp, Warning, TEXT("Overlap began2"));
		UGameplayStatics::OpenLevel(GetWorld(), levelName);
	}
}

void ACPP_LevelTeleporter::OnTriggerEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* otherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{

}
#pragma endregion