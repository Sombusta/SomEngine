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

	DWORD offset = SomWidth * SomHeight / 2 + SomWidth / 2 + x + SomWidth * -y; // SomWidth * x + SomHeight * y;
	*(dest + offset) = PixelColor.GetColor(); // SomFramework_SR::GetInstance()->CurrentColor;
}

// SomWorks :D // ������ �����ĸ� ������ ���۵� �� �߱� �˰���
void FSomDrawLibrary::DrawLine(FPoint Point1, FPoint Point2)
{
	// SomWorks :D // ������ ������
	// 1. x = x1 - (y1 - y) * (x2 - x1) / (y2 - y1)
	// 2. y = (y2 - y1) / (x2 - x1) * (x - x1) + y1

	FPoint StartVertex;
	FPoint EndVertex;

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
void FSomDrawLibrary::DrawLine_BresenhamAlgorithm(FPoint Point1, FPoint Point2, FColor PixelColor)
{	
	// SomWorks :D // X�� ���̿� Y�� ����
	int dx = abs(Point2.X - Point1.X);
	int dy = abs(Point2.Y - Point1.Y);

	// SomWorks :D // ������ ���� ���ϱ�
	//int dc = dy / dx;

	int p_value;
	int inc_minus;
	int inc_plus;
	int inc_value;
	int ndx;

	//��ȭ���� ���� �ϸ��� ��ǥ�� �������� ���� ��´�.
	// SomWorks :D // ���Ⱑ 0 ~ 1
	if (dy <= dx)
	{
		// y ���� x ��ȭ���� Ŭ ���
		inc_minus = 2 * dy;
		inc_plus = 2 * (dy - dx);

		//�� x ���� ���� ������ �׷������� ����.
		//Bresenham ������ �������� ���� ��ġ�� ��� ���̱� ��������.

		if (Point2.X < Point1.X)
		{
			ndx = Point1.X;
			Point1.X = Point2.X;
			Point2.X = ndx;

			ndx = Point1.Y;
			Point1.Y = Point2.Y;
			Point2.Y = ndx;
		}

		// SomWorks :D // x���� ���� y�� ��ȭ�� ����
		if (Point1.Y < Point2.Y) {
			inc_value = 1;
		}
		else {
			inc_value = -1;
		}

		DrawPixel(Point1.X, Point1.Y, PixelColor);

		//ó�� �Ǵ� ��
		p_value = 2 * dy - dx;

		for (ndx = Point1.X; ndx < Point2.X; ++ndx)
		{
			if (0 > p_value)
			{
				p_value += inc_minus;
			}
			else
			{
				p_value += inc_plus;
				Point1.Y += inc_value;
			}

			DrawPixel(ndx, Point1.Y, PixelColor);
		}
	}
	else
	{
		inc_minus = 2 * dx;
		inc_plus = 2 * (dx - dy);

		if (Point2.Y < Point1.Y)
		{
			ndx = Point1.Y;
			Point1.Y = Point2.Y;
			Point2.Y = ndx;

			ndx = Point1.X;
			Point1.X = Point2.X;
			Point2.X = ndx;
		}

		if (Point1.X < Point2.X)
		{
			inc_value = 1;
		}
		else
		{
			inc_value = -1;
		}

		DrawPixel(Point1.X, Point1.Y, PixelColor);

		p_value = 2 * dx - dy;

		for (ndx = Point1.Y; ndx < Point2.Y; ++ndx)
		{
			if (0 > p_value)
			{
				p_value += inc_minus;
			}
			else
			{
				p_value += inc_plus;
				Point1.X += inc_value;
			}

			DrawPixel(Point1.X, ndx, PixelColor);
		}
	}
}

// SomWorks :D // �� �׸���
void FSomDrawLibrary::DrawCircle(FPoint CenterVec, int r)
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