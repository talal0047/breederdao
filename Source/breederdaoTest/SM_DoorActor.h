// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "SM_DoorActor.generated.h"

/**
 * 
 */
UCLASS()
class BREEDERDAOTEST_API ASM_DoorActor : public AStaticMeshActor
{
	GENERATED_BODY()

public:
    ASM_DoorActor();
    virtual void Tick(float DeltaTime) override;

    // Functions to control the door
    void OpenDoor();
    void CloseDoor();
    void BeginPlay();

protected:
    bool bIsOpening;
    float OpenProgress;
    float OpenSpeed;

    // Initial and target rotation for the door
    FRotator InitialRotation;
    FRotator TargetRotation;

    // Indicates whether the door is currently moving
    bool bIsMoving = false;

    UPROPERTY(EditAnywhere, Category = "Door")
    float RotationSpeed = 2.0f;

    // Tracks opening or closing of the door
    bool bOpening = true;

    // Whether the door is currently open
    bool bIsOpen;
	
};
