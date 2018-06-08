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
	// �κ��丮
	void ToggleInventory();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerProperties)
		float Hp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerProperties)
		float MaxHp;

	// �÷��̾��� ������ ���� ��
	TMap<FString, int> Backpack;

	// ������ �����ۿ� ����� �����ܵ��̸�, FString�� key ��
	TMap<FString, UTexture2D*> Icons;

	// UI�� �������� �ִ� ������ �˷��ִ� �÷���
	bool inventoryShowing;

	// �ƹ�Ÿ�� �������� �򵵷� �ϴ� ��� �Լ�
	void Pickup(APickupItem *item);





};
