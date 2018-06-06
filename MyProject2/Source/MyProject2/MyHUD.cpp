// Fill out your copyright notice in the Description page of Project Settings.

#include "MyHUD.h"
#include "Engine.h"

void AMyHUD::DrawMessages()
{
	for (int c = messages.Num() - 1; c >= 0; c--)
	{
		// �޽����� ����� �ùٸ� ��ҿ� ��� �ڽ��� �׸���.
		float outputWidth, outputHeight, pad = 10.f;
		GetTextSize(messages[c].message, outputWidth, outputHeight, hudFont, 1.f);
		float messageH = outputHeight + 2.f *pad;
		float x = 0.f, y = c * messageH;

		// ����� ���������� ĥ�Ѵ�
		DrawRect(FLinearColor::Black, x, y, Canvas->SizeX, messageH);

		// hudFoint�� ����� �޽����� �׸���
		DrawText(messages[c].message, messages[c].color, x + pad, y + pad, hudFont);

		// ��½ð��� ���� �����Ӻ��� ���� �ð���ŭ ����.
		messages[c].time -= GetWorld()->GetDeltaSeconds();

		// �ð��� �� �Ǿ��ٸ� �����Ѵ�.
		if (messages[c].time < 0)
		{
			messages.RemoveAt(c);
		}
	}
}

void AMyHUD::DrawHUD()
{
	// �θ��� DrawHUD() �Լ��� ���� ȣ���մϴ�.
	Super::DrawHUD();

	// ���� �ʿ��� ���� �׸��� ���� ����
	DrawLine(200, 300, 400, 500, FLinearColor::Blue);



	DrawMessages();
}

void AMyHUD::addMessage(Message msg)
{
	messages.Add(msg);
}