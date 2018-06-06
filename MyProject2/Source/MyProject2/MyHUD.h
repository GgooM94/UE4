// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MyHUD.generated.h"


struct Message
{
	FString message;
	float time;
	FColor color;
	Message()
	{
		// �⺻�� ����
		time = 5.f;
		color = FColor::White;
	}
	Message(FString iMessage, float iTime, FColor iColor)
	{
		message = iMessage;
		time = iTime;
		color = iColor;
	}
};
/**
 * 
 */
UCLASS()
class MYPROJECT2_API AMyHUD : public AHUD
{
	GENERATED_BODY()
	
	
public:
	// ��Ʈ�� HUD���� ���ڿ��� ǥ���ϴµ� ���˴ϴ�.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = HUDFont)
		UFont* hudFont;
	// �� �Լ��� �߰��� HUD�� �׸� �� �ֵ��� �Ѵ�.
	virtual void DrawHUD() override;
	
	// ����� �޽����� �迭
	TArray<Message> messages;

	// ����� �޽����� �߰��� �� �ִ� �Լ�
	void addMessage(Message msg);

	void AMyHUD::DrawMessages();
	
};
