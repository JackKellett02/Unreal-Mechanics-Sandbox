// Fill out your copyright notice in the Description page of Project Settings.


#include "Tasks/CPP_Spinning_Cube.h"

// Sets default values
ACPP_Spinning_Cube::ACPP_Spinning_Cube()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Create and attach static mesh.
	Cube = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cube"));
	Cube->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);

	Cylinder1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cylinder1"));
	Cylinder1->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);

	Cylinder2 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cylinder2"));
	Cylinder2->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);

	//Create and attach actor component for spinning.
	spinningComp = CreateDefaultSubobject<UCPP_Spinning_Comp>(TEXT("SpinningComp"));
}

// Called when the game starts or when spawned
void ACPP_Spinning_Cube::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPP_Spinning_Cube::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

