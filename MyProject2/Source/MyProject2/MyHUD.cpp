// Fill out your copyright notice in the Description page of Project Settings.

#include "MyHUD.h"
#include "Engine.h"

void AMyHUD::DrawMessages()
{
	for (int c = messages.Num() - 1; c >= 0; c--)
	{
		// 메시지를 출력할 올바른 장소에 배경 박스를 그린다.
		float outputWidth, outputHeight, pad = 10.f;
		GetTextSize(messages[c].message, outputWidth, outputHeight, hudFont, 1.f);
		float messageH = outputHeight + 2.f *pad;
		float x = 0.f, y = c * messageH;

		// 배경을 검정색으로 칠한다
		DrawRect(FLinearColor::Black, x, y, Canvas->SizeX, messageH);

		// hudFoint를 사용해 메시지를 그린다
		DrawText(messages[c].message, messages[c].color, x + pad, y + pad, hudFont);

		// 출력시간을 이전 프레임부터 지난 시간만큼 뺀다.
		messages[c].time -= GetWorld()->GetDeltaSeconds();

		// 시간이 다 되었다면 삭제한다.
		if (messages[c].time < 0)
		{
			messages.RemoveAt(c);
		}
	}
}

void AMyHUD::DrawHUD()
{
	// 부모의 DrawHUD() 함수를 먼저 호출합니다.
	Super::DrawHUD();

	// 이제 필요한 것을 그리는 과정 진행
	DrawLine(200, 300, 400, 500, FLinearColor::Blue);



	DrawMessages();
}

void AMyHUD::addMessage(Message msg)
{
	messages.Add(msg);
}