// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "CustomHUD.generated.h"

/**
 * 
 */
UCLASS()
class MAGICCARDS_API ACustomHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	ACustomHUD();

	class UPVE* PVE;
	TSubclassOf<class UUserWidget> PVEClass;

	/*
	class UMainMenuC* MainMenuC;
	TSubclassOf<class UUserWidget> MainMenuC;
	*/
};
