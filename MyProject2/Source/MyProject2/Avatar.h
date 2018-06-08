// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Avatar.generated.h"

class APickupItem;

UCLASS()
class MYPROJECT2_API AAvatar : public ACharacter
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Sets default values for this character's properties
	AAvatar();
	void MoveFoward(float amount);
	void MoveRight(float amount);
	void Yaw(float amount);
	void Pitch(float amount);
	// 인벤토리
	void ToggleInventory();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerProperties)
		float Hp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerProperties)
		float MaxHp;

	// 플레이어의 백팩을 위한 맵
	TMap<FString, int> Backpack;

	// 백팩의 아이템에 사용할 아이콘들이며, FString이 key 값
	TMap<FString, UTexture2D*> Icons;

	// UI가 보여지고 있는 중인지 알려주는 플래그
	bool inventoryShowing;

	// 아바타가 아이템을 얻도록 하는 멤버 함수
	void Pickup(APickupItem *item);





};
