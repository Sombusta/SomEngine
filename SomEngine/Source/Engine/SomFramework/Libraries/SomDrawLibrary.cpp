// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#include "SomDrawLibrary.h"

FSomDrawLibrary::FSomDrawLibrary()
{
}

FSomDrawLibrary::~FSomDrawLibrary()
{
}

// SomWorks :D // �ȼ� ��� API
void FSomDrawLibrary::DrawPixel(int x, int y, FColor PixelColor)
{
	if (!FSomMathLibrary::IsInRange(x, y)) return;

	ULONG* dest = (ULONG*)SomFramework_SR::GetInstance()->Bits;

	DWORD offset = WIN_WIDTH * WIN_HEIGHT / 2 + WIN_WIDTH / 2 + x + WIN_WIDTH * -y; // SomWidth * x + SomHeight * y;
	*(dest + offset) = PixelColor.GetColor(); // SomFramework_SR::GetInstance()->CurrentColor;
}

// SomWorks :D // ������ �����ĸ� ������ ���۵� �� �߱� �˰���
void FSomDrawLibrary::DrawLine(FPoint2D Point1, FPoint2D Point2)
{
	// SomWorks :D // ������ ������
	// 1. x = x1 - (y1 - y) * (x2 - x1) / (y2 - y1)
	// 2. y = (y2 - y1) / (x2 - x1) * (x - x1) + y1

	FPoint2D StartVertex;
	FPoint2D EndVertex;

	if (Point1.Y >= Point2.Y)
	{
		StartVertex = Point2;
		EndVertex = Point1;

		for (int i = static_cast<int>(StartVertex.Y); i <= EndVertex.Y; i++)
		{
			int x1 = EndVertex.X - (EndVertex.Y - i) * (EndVertex.X - StartVertex.X) / (EndVertex.Y - StartVertex.Y);
			// float x1 = ((EndVertex.Y - StartVertex.Y) / (EndVertex.X - StartVertex.X)) * (i - StartVertex.X) + StartVertex.Y;

			DrawPixel(x1, i);
		}
	}
	else
	{
		StartVertex = Point1;
		EndVertex = Point2;

		for (int i = static_cast<int>(StartVertex.Y); i <= EndVertex.Y; i++)
		{
			int x1 = EndVertex.X - (EndVertex.Y - i) * (EndVertex.X - StartVertex.X) / (EndVertex.Y - StartVertex.Y);

			DrawPixel(x1, i);
		}
	}
}

// SomWorks :D // �극���� ���� �˰���
void FSomDrawLibrary::DrawLine_BA(const FPoint2D& StartPoint, const FPoint2D& EndPoint, FLinearColor PixelColor)
{	
	FPoint2D TempStart = StartPoint;
	FPoint2D TempEnd = EndPoint;

	// SomWorks :D // �غ��� ���� ���ϱ�
	int Width = abs(EndPoint.X - StartPoint.X);
	int Height = abs(EndPoint.Y - StartPoint.Y);

	int p_value;
	int inc_minus;
	int inc_plus;
	int inc_value;

	// SomWorks :D // ���Ⱑ 0 ~ 1, ��ȭ���� ���� �ϸ��� ��ǥ�� �������� ���� ��´�.
	if (Height <= Width)
	{
		// SomWorks :D // x ���� ���� ������ �׷������� ����.		
		if (TempEnd.X < TempStart.X) 
		{
			FPoint2D::Swap(TempStart, TempEnd);
		}

		DrawPixel(TempStart.X, TempStart.Y, PixelColor.ToColor32());

		// y ���� x ��ȭ���� Ŭ ���
		inc_minus = 2 * Height;
		inc_plus = 2 * (Height - Width);
			   
		// SomWorks :D // �� ��ǥ�� ��ġ�� ���� ������ 1 or -1
		inc_value = TempStart.Y < TempEnd.Y ? 1 : -1;

		// SomWorks :D // �Ǻ��� �ʱ�ȭ
		p_value = (2 * Height) - Width;		

		for (int i = TempStart.X; i < TempEnd.X; i++)
		{
			if (p_value < 0)
			{
				p_value += inc_minus;
			}
			else
			{
				p_value += inc_plus;
				TempStart.Y += inc_value;
			}

			DrawPixel(i, TempStart.Y, PixelColor.ToColor32());

			/*if (i < TempEnd.X - 10)
			{
				DrawPixel(i, TempStart.Y, PixelColor);
			}
			else
			{
				DrawPixel(i, TempStart.Y, FLinearColor(255, 0, 0));
			}*/
		}
	}
	else // SomWorks :D // ���Ⱑ 1 �ʰ�, X�� Y���� �����ؼ� ���
	{
		if (TempEnd.Y < TempStart.Y) {
			FPoint2D::Swap(TempStart, TempEnd);
		}

		DrawPixel(TempStart.X, TempStart.Y, PixelColor.ToColor32());

		inc_minus = 2 * Width;
		inc_plus = 2 * (Width - Height);
		inc_value = TempStart.X < TempEnd.X ? 1 : -1;
		p_value = (2 * Width) - Height;		
		
		for (int i = TempStart.Y; i < TempEnd.Y; i++)
		{
			if (p_value < 0)
			{
				p_value += inc_minus;
			}
			else
			{
				p_value += inc_plus;
				TempStart.X += inc_value;
			}

			DrawPixel(TempStart.X, i, PixelColor.ToColor32());
		}
	}
}

// SomWorks :D // �� �׸���
void FSomDrawLibrary::DrawCircle(FPoint2D CenterVec, int r)
{
	int x = 0, y = 0;

	for (x = 0; x <= y; x++)
	{
		// SomWorks :D // y �� ��ǥ�� ����Ѵ�.
		y = (int)(sqrt(r*r - x * x) + 0.5);

		// SomWorks :D // ��� ���
		// (1) ���� (x,y) ��ǥ�� �ȼ��� ����Ѵ�.
		// (2) �ȼ��� ����� ����(cx, cy) ��ŭ ���� �̵� ��Ų��.

		FSomDrawLibrary::DrawPixel(CenterVec.X + x, CenterVec.Y + y);
		FSomDrawLibrary::DrawPixel(CenterVec.X + x, CenterVec.Y - y);
		FSomDrawLibrary::DrawPixel(CenterVec.X - x, CenterVec.Y + y);
		FSomDrawLibrary::DrawPixel(CenterVec.X - x, CenterVec.Y - y);
		FSomDrawLibrary::DrawPixel(CenterVec.X + y, CenterVec.Y + x);
		FSomDrawLibrary::DrawPixel(CenterVec.X + y, CenterVec.Y - x);
		FSomDrawLibrary::DrawPixel(CenterVec.X - y, CenterVec.Y + x);
		FSomDrawLibrary::DrawPixel(CenterVec.X - y, CenterVec.Y - x);
	}
}