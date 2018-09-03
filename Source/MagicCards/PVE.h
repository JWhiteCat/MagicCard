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
	

public:

	class UButton* Card1;
	class UButton* Card2;
	class UButton* Card3;
	class UButton* Card4;
	class UButton* Card5;
	class UButton* Card6;

	class UButton* PlayCard;
	class UButton* DisCard;
	class UButton* SwitchCard;

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Code")
	int32 CurrentClickNumberC = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Code")
	bool CurrentPlayerC = false;


	
	UFUNCTION(BlueprintCallable, Category = "Code")
	void FSMUpdate();

	void UpdateSelectCard();

	void UpdatePushPlayCardButton();

	void UpdateWait();

	void UpdatePushDisCardButton();

	void UpdatePushSwitchCardButton();

public:

	float time = 0.0f;
	int NextCardButton = 1;
	int RemainCardNumber = 1;

	enum FSMState
	{
		Wait,

		SelectCard,

		PushPlayCardButton,

		PushDisCardButton,

		PushSwitchCardButton

	};
	FSMState CurrentState = FSMState::Wait;

	bool Delay(float DelayTime = 1000.0f);



	/*获取蓝图中的变量
	class UPVE* PVE;
	TSubclassOf<class UUserWidget> PVEClass;
	*/
};
