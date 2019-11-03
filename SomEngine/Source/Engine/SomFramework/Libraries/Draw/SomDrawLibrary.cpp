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
void FSomDrawLibrary::DrawLine_BresenhamAlgorithm(FPoint2D StartPoint, FPoint2D EndPoint, FColor PixelColor)
{	
	FPoint2D TempStart = StartPoint;
	FPoint2D TempEnd = EndPoint;

	// SomWorks :D // �غ��� ���� ���ϱ�
	int Width = abs(EndPoint.X - StartPoint.X);
	int Height = abs(EndPoint.Y - StartPoint.Y);

	// SomWorks :D // ������ ���� ���ϱ�
	//int dc = Height / Width;
	   
	int p_value;
	int inc_minus;
	int inc_plus;
	int inc_value;

	//��ȭ���� ���� �ϸ��� ��ǥ�� �������� ���� ��´�.
	// SomWorks :D // ���Ⱑ 0 ~ 1
	if (Height <= Width)
	{
		// y ���� x ��ȭ���� Ŭ ���
		inc_minus = 2 * Height;
		inc_plus = 2 * (Height - Width);

		//�� x ���� ���� ������ �׷������� ����.
		//Bresenham ������ �������� ���� ��ġ�� ��� ���̱� ��������.

		if (TempEnd.X < TempStart.X) {
			FPoint2D::Swap(TempStart, TempEnd);
		}

		// SomWorks :D // x���� ���� y�� ��ȭ�� ����
		inc_value = TempStart.Y < TempEnd.Y ? 1 : -1;

		DrawPixel(TempStart.X, TempStart.Y, PixelColor);
				
		//ó�� �Ǵ� ��
		p_value = (2 * Height) - Width;

		for (int i = TempStart.X; i < TempEnd.X; i++)
		{
			if (0 > p_value)
			{
				p_value += inc_minus;
			}
			else
			{
				p_value += inc_plus;
				TempStart.Y += inc_value;
			}
			if (i < TempEnd.X - 10)
			{
				DrawPixel(i, TempStart.Y, PixelColor);
			}
			else
			{
				DrawPixel(i, TempStart.Y, FLinearColor(255, 0, 0));
			}
			
		}
	}
	else
	{
		inc_minus = 2 * Width;
		inc_plus = 2 * (Width - Height);

		if (TempEnd.Y < TempStart.Y) {
			FPoint2D::Swap(TempStart, TempEnd);
		}

		inc_value = TempStart.X < TempEnd.X ? 1 : -1;

		DrawPixel(TempStart.X, TempStart.Y, PixelColor);

		p_value = (2 * Width) - Height;

		for (int i = TempStart.Y; i < TempEnd.Y; i++)
		{
			if (0 > p_value)
			{
				p_value += inc_minus;
			}
			else
			{
				p_value += inc_plus;
				TempStart.X += inc_value;
			}
			DrawPixel(TempStart.X, i, FLinearColor(0, 255, 0));
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