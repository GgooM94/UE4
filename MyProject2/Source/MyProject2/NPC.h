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

	// NPC 대화
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = NPCMessage)
		FString NpcMessage;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Collision)
		USphereComponent* ProxSphere;

	// 블루 프린트에서 함수 호출을 하기위해서 다음과 같이 선언
	UFUNCTION(BlueprintNativeEvent, Category = "Collision")
		void OnProxOverlapBegin(AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

	// 위 휨수의 실제 군현을 위해서 다음과 같이 선언
	// 실제 코드는 이 함수에만 들어간다.
	// 다른 함수와 약간 다르게 생겼지만, 이렇게 해야 블루프린트로 함수로 잘 동작 한다.


};
