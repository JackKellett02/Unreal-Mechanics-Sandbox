// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPP_PushableBox.generated.h"

//Forward Declarations.
class UBoxComponent;
class UPhysicsConstraintComponent;
class ACPP_Character;

//A class to describe a box that can exist in the world that can be pushed by a player.
UCLASS()
class UE4PROJ_API ACPP_PushableBox : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACPP_PushableBox();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Y Axis Triggers.
	UFUNCTION()
		void OnTriggerBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
		void OnTriggerEndOverlap(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	///X Axis Triggers.
	UFUNCTION()
		void OnTrigger2BeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
		void OnTrigger2EndOverlap(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	//Editor Variables.
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* pushableBoxMesh;

	UPROPERTY(EditAnywhere)
		UPhysicsConstraintComponent* physicsConstraint;

	UPROPERTY(EditAnywhere)
		UBoxComponent* YAxisCollisionTrigger;

	UPROPERTY(EditAnywhere)
		UBoxComponent* XAxisCollisionTrigger;
};
