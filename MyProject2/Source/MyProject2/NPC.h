// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "NPC.generated.h"

UCLASS()
class MYPROJECT2_API ANPC : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ANPC();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// NPC ��ȭ
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = NPCMessage)
		FString NpcMessage;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Collision)
		USphereComponent* ProxSphere;

	// ���� ����Ʈ���� �Լ� ȣ���� �ϱ����ؼ� ������ ���� ����
	UFUNCTION(BlueprintNativeEvent, Category = "Collision")
		void OnProxOverlapBegin(AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

	// �� �ڼ��� ���� ������ ���ؼ� ������ ���� ����
	// ���� �ڵ�� �� �Լ����� ����.
	// �ٸ� �Լ��� �ణ �ٸ��� ��������, �̷��� �ؾ� ��������Ʈ�� �Լ��� �� ���� �Ѵ�.


};