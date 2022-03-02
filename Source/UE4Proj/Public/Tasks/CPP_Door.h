// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPP_Door.generated.h"

class UBoxComponent;

UCLASS()
class UE4PROJ_API ACPP_Door : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACPP_Door();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Trigger Functions.
	UFUNCTION()
		void OnTriggerBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
		void OnTriggerEndOverlap(class UPrimitiveComponent* OverlappedComp, class AActor* otherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	UFUNCTION()
		void OnTrigger2BeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
		void OnTrigger2EndOverlap(class UPrimitiveComponent* OverlappedComp, class AActor* otherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);


	//Variables.
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* door;

	UPROPERTY(EditAnywhere)
		UBoxComponent* trigger;

	UPROPERTY(EditAnywhere)
		UBoxComponent* trigger2;

	UPROPERTY(EditAnywhere)
		FRotator desiredRotation;//Desired rotation for the door.

private:
	FRotator startingRotation;

	//What direction should the door open.
	bool shouldDoorBeOpen;
	bool shouldDoorBeOpenOtherWay;
};
