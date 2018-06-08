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

	// �𸮾� ��ü �ʱ�ȭ
	ProxSphere = CreateDefaultSubobject<USphereComponent>(TEXT("ProxSphere"));
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));

	// ��Ʈ ��ü�� �޽÷� �����.
	RootComponent = Mesh;
	Mesh->SetSimulatePhysics(true);

	// �� ��ü�� �浹 ��ü�� �ٸ� ���Ϳ� ��ġ�� APickupItem::OnProxOverlapBegin() �� ����

	ProxSphere->OnComponentBeginOverlap.AddDynamic(this, &APickupItem::OnProxOverlapBegin);
	ProxSphere->AttachTo(Mesh);
}
