// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine.h"
#include "PickupItem.generated.h"

class AMyHUD;
UCLASS()
class MYPROJECT2_API APickupItem : public AActor
{
	GENERATED_BODY()
	

public:	
	// Sets default values for this actor's properties
	APickupItem();
	
	// 얻는 아이템의 이름
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item)
		FString Name;

	//얻는 개수
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item)
		int32 Quantity;

	// 아이템을 줍는데 사용되는 충돌 구체
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Item)
		USphereComponent* ProxSphere;

	// 아이템 메시
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Item)
		UStaticMeshComponent* Mesh;

	// UI 캔버스에서 보여지는 캑체의 아이콘
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item)
		UTexture2D * Icon;

	// ProxSphere 안으로 무안가 들어오면 이 함수가 실행된다.
	UFUNCTION(BlueprintNAtiveEvent, Category = Collision)
		void OnProxOverlapBegin(AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBOdyIndex, bool bFromSweep, const FHitResult & SweepResult);

	virtual void OnProxOverlapBegin_Implementation(AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);	
};
