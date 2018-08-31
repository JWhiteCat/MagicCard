// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PVE.generated.h"


/**
 *
 */
UCLASS()
class MAGICCARDS_API UPVE : public UUserWidget
{
	GENERATED_BODY()

public:

	virtual bool Initialize() override;

	virtual void Tick(FGeometry MyGeometry, float InDeltaTime);
	
	//UFUNCTION(BlueprintCallable, Category = "Misc", meta = (WorldContextObject))
	//static bool RandomFunc(UObject* WorldContexObject);

public:

	class UButton* Card1;
	class UButton* Card2;
	class UButton* Card3;
	class UButton* Card4;
	class UButton* Card5;
	class UButton* Card6;

	class UButton* PlayCard;

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Code")
	int32 CurrentClickNumberC = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Code")
	bool CurrentPlayerC = true;
	

	//bool isPlay = false;

	float time = 0.0f;
	float DelayTime = 1500.0f;



public:

	enum FSMState
	{
		Wait,
		SelectCard,
		PushPlayCardButton,
	};

	FSMState CurrentState = FSMState::Wait;


	UFUNCTION(BlueprintCallable, Category = "Code")
	void FSMUpdate();

	void UpdateSelectCard();

	void UpdatePushPlayCardButton();

	void UpdateWait();

	bool Delay(float DelayTime = 1500.0f);
	/*获取蓝图中的变量
	class UPVE* PVE;
	TSubclassOf<class UUserWidget> PVEClass;
	*/
};
