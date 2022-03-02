// Fill out your copyright notice in the Description page of Project Settings.


#include "Tasks/CPP_PushableBox.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"
#include "Tasks/CPP_Character.h"
#include "PhysicsEngine/PhysicsConstraintComponent.h"

// Sets default values
ACPP_PushableBox::ACPP_PushableBox()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Create teleporter Mesh.
	pushableBoxMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BoxMesh"));
	pushableBoxMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);

	//Create and attach constraint.
	physicsConstraint = CreateDefaultSubobject<UPhysicsConstraintComponent>(TEXT("Physics Constraint"));
	physicsConstraint->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);

	//Create and attach trigger.
	YAxisCollisionTrigger = CreateDefaultSubobject<UBoxComponent>(TEXT("YAxisCollisionTrigger"));
	YAxisCollisionTrigger->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);

	//Connect trigger to overlap function.
	YAxisCollisionTrigger->OnComponentBeginOverlap.AddDynamic(this, &ACPP_PushableBox::OnTriggerBeginOverlap);
	YAxisCollisionTrigger->OnComponentEndOverlap.AddDynamic(this, &ACPP_PushableBox::OnTriggerEndOverlap);

	//Create and attach trigger.
	XAxisCollisionTrigger = CreateDefaultSubobject<UBoxComponent>(TEXT("XAxisCollisionTrigger"));
	XAxisCollisionTrigger->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);

	//Connect trigger to overlap function.
	XAxisCollisionTrigger->OnComponentBeginOverlap.AddDynamic(this, &ACPP_PushableBox::OnTrigger2BeginOverlap);
	XAxisCollisionTrigger->OnComponentEndOverlap.AddDynamic(this, &ACPP_PushableBox::OnTrigger2EndOverlap);
}

// Called when the game starts or when spawned
void ACPP_PushableBox::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ACPP_PushableBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

#pragma region Y Axis Triggers.
void ACPP_PushableBox::OnTriggerBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ACPP_Character* tempChar = Cast<ACPP_Character>(OtherActor);
	if (tempChar)
	{
		pushableBoxMesh->SetSimulatePhysics(true);
	}
}

void ACPP_PushableBox::OnTriggerEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	ACPP_Character* tempChar = Cast<ACPP_Character>(OtherActor);
	if (tempChar)
	{
		//pushableBoxMesh->SetSimulatePhysics(false);
	}
}
#pragma endregion

#pragma region X Axis Triggers.
void ACPP_PushableBox::OnTrigger2BeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ACPP_Character* tempChar = Cast<ACPP_Character>(OtherActor);
	if (tempChar)
	{
		pushableBoxMesh->SetSimulatePhysics(true);
	}
}

void ACPP_PushableBox::OnTrigger2EndOverlap(UPrimitiveComponent* OverlappedComp, AActor* otherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	ACPP_Character* tempChar = Cast<ACPP_Character>(otherActor);
	if (tempChar)
	{
		//pushableBoxMesh->SetSimulatePhysics(false);
	}
}
#pragma endregion