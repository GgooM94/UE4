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
	
	// ��� �������� �̸�
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item)
		FString Name;

	//��� ����
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item)
		int32 Quantity;

	// �������� �ݴµ� ���Ǵ� �浹 ��ü
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Item)
		USphereComponent* ProxSphere;

	// ������ �޽�
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Item)
		UStaticMeshComponent* Mesh;

	// UI ĵ�������� �������� Ĵü�� ������
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item)
		UTexture2D * Icon;

	// ProxSphere ������ ���Ȱ� ������ �� �Լ��� ����ȴ�.
	UFUNCTION(BlueprintNAtiveEvent, Category = Collision)
		void OnProxOverlapBegin(AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBOdyIndex, bool bFromSweep, const FHitResult & SweepResult);

	virtual void OnProxOverlapBegin_Implementation(AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);	
};
