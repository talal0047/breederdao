// Fill out your copyright notice in the Description page of Project Settings.


#include "SwitchToggle.h"
#include "Engine/Engine.h"
#include "GameFramework/Character.h"
#include "breederdaoTestCharacter.h"

// Sets default values
ASwitchToggle::ASwitchToggle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    // Set up the static mesh component
    SwitchMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SwitchMesh"));
    RootComponent = SwitchMesh;

    // Set up the box collision component
    BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
    BoxCollision->SetupAttachment(RootComponent);
    BoxCollision->SetCollisionProfileName(TEXT("Trigger"));

    // Bind the overlap events
    BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &ASwitchToggle::OnOverlapBegin);
    BoxCollision->OnComponentEndOverlap.AddDynamic(this, &ASwitchToggle::OnOverlapEnd);

    bReplicates = true;

}

// Called when the game starts or when spawned
void ASwitchToggle::BeginPlay()
{
	Super::BeginPlay();

    // Set the initial material
    SwitchMesh->SetMaterial(0, OffMaterial);

}

// Called every frame
void ASwitchToggle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASwitchToggle::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    AbreederdaoTestCharacter* Character = Cast<AbreederdaoTestCharacter>(OtherActor);

    // If the cast is successful and the overlapped actor is a AbreederdaoTestCharacter
    if (Character && GEngine && ControlledDoor)
    {
        ControlledDoor->OpenDoor();

        // Set the material when player enter the switch
        SwitchMesh->SetMaterial(0, OnMaterial);
    }
}

void ASwitchToggle::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
    AbreederdaoTestCharacter* Character = Cast<AbreederdaoTestCharacter>(OtherActor);

    // If the cast is successful and the overlapped actor is a AbreederdaoTestCharacter
    if (Character && GEngine && ControlledDoor)
    {
        ControlledDoor->CloseDoor();

        // Set the material when player leave the switch
        SwitchMesh->SetMaterial(0, OffMaterial);
    }
}

