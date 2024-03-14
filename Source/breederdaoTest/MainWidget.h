// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Components/Button.h"
#include "Engine/World.h"
#include "MainWidget.generated.h"

UCLASS()
class BREEDERDAOTEST_API UMainWidget : public UUserWidget
{
	GENERATED_BODY()


public:
	UFUNCTION(BlueprintCallable, Category = "Level")
	void OpenLevelAsDedicatedServer(FName LevelName);

protected:
    virtual void NativeConstruct() override;

    UFUNCTION()
    void OnConnectButtonClicked();

private:
    
    class UButton* ConnectButton;
};

