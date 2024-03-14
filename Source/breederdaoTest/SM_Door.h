// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/Actor.h"
#include "SM_Door.generated.h"
UCLASS()
class BREEDERDAOTEST_API ASM_Door : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASM_Door();

	virtual void Tick(float DeltaTime) override;
	// Functions to control the door
	void OpenDoor();
	void CloseDoor();
	void BeginPlay();

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* SwitchMesh;

protected:

	bool bIsOpening;
	float OpenProgress;
	float OpenSpeed;

	// Initial and target rotation for the open state
	FRotator InitialRotation;
	FRotator TargetRotation;

	// Indicates whether the door is currently moving
	bool bIsMoving = false;

	UPROPERTY(EditAnywhere, Category = "Door")
	float RotationSpeed = 2.0f;

	// Tracks whether we're opening or closing the door
	bool bOpening = true;

	// Whether the door is currently open
	bool bIsOpen;
};
