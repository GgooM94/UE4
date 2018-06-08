// Fill out your copyright notice in the Description page of Project Settings.

#include "GameModeGoldenEgg.h"
#include "PickupItem.h"
#include "Engine.h"
#include "Avatar.h"
#include "MyHUD.h"

// Sets default values
APickupItem::APickupItem()
{
	Name = "UNKNOWN ITEM";
	Quantity = 0;

	// 언리얼 객체 초기화
	ProxSphere = CreateDefaultSubobject<USphereComponent>(TEXT("ProxSphere"));
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));

	// 루트 객체를 메시로 만든다.
	RootComponent = Mesh;
	Mesh->SetSimulatePhysics(true);

	// 이 객체의 충돌 구체가 다른 액터와 겹치면 APickupItem::OnProxOverlapBegin() 이 실행

	ProxSphere->OnComponentBeginOverlap.AddDynamic(this, &APickupItem::OnProxOverlapBegin);
	ProxSphere->AttachTo(Mesh);
}
