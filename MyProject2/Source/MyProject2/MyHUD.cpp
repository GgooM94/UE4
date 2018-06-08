// Fill out your copyright notice in the Description page of Project Settings.
#include "MyHUD.h"
#include "Engine.h"
#include "Avatar.h"

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

void AMyHUD::DrawHealthbar()
{
	// ü�¹� ����
	AAvatar *avatar = Cast<AAvatar>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	float barWidth = 200, barHeight = 50, barPad = 12, barMargin = 50;
	float percHp = avatar->Hp/avatar->MaxHp;
	DrawRect(FLinearColor(0, 0, 0, 1), Canvas->SizeX - barWidth - barPad - barMargin,
		Canvas->SizeY - barHeight - barPad - barMargin, barWidth + 2 * barPad, barHeight + 2 * barPad);

	DrawRect(FLinearColor(1 - percHp, percHp, 0, 1), Canvas->SizeX - barWidth - barMargin,
		Canvas->SizeY - barHeight - barMargin, barWidth*percHp, barHeight);
}