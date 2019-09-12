// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#include "SomDrawLibrary.h"

FSomDrawLibrary::FSomDrawLibrary()
{
}

FSomDrawLibrary::~FSomDrawLibrary()
{
}

// SomWorks :D // 픽셀 찍기 API
void FSomDrawLibrary::DrawPixel(int x, int y, FColor PixelColor)
{
	if (!FSomMathLibrary::IsInRange(x, y)) return;

	ULONG* dest = (ULONG*)SomFramework_SR::GetInstance()->Bits;

	DWORD offset = SomWidth * SomHeight / 2 + SomWidth / 2 + x + SomWidth * -y; // SomWidth * x + SomHeight * y;
	*(dest + offset) = PixelColor.GetColor(); // SomFramework_SR::GetInstance()->CurrentColor;
}

// SomWorks :D // 직선의 방정식만 가지고 제작된 선 긋기 알고리즘
void FSomDrawLibrary::DrawLine(FPoint Point1, FPoint Point2)
{
	// SomWorks :D // 직선의 방정식
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

// SomWorks :D // 브레젠험 직선 알고리즘
void FSomDrawLibrary::DrawLine_BresenhamAlgorithm(FPoint Point1, FPoint Point2, FColor PixelColor)
{	
	// SomWorks :D // X의 길이와 Y의 길이
	int dx = abs(Point2.X - Point1.X);
	int dy = abs(Point2.Y - Point1.Y);

	// SomWorks :D // 직선의 기울기 구하기
	//int dc = dy / dx;

	int p_value;
	int inc_minus;
	int inc_plus;
	int inc_value;
	int ndx;

	//변화폭을 따져 완만한 좌표를 기준으로 점을 찍는다.
	// SomWorks :D // 기울기가 0 ~ 1
	if (dy <= dx)
	{
		// y 보다 x 변화폭이 클 경우
		inc_minus = 2 * dy;
		inc_plus = 2 * (dy - dx);

		//선 x 점을 작은 수부터 그려나가기 위해.
		//Bresenham 공식은 다음점에 대한 위치를 잡는 것이기 때문에도.

		if (Point2.X < Point1.X)
		{
			ndx = Point1.X;
			Point1.X = Point2.X;
			Point2.X = ndx;

			ndx = Point1.Y;
			Point1.Y = Point2.Y;
			Point2.Y = ndx;
		}

		// SomWorks :D // x값에 따른 y값 변화값 고르기
		if (Point1.Y < Point2.Y) {
			inc_value = 1;
		}
		else {
			inc_value = -1;
		}

		DrawPixel(Point1.X, Point1.Y, PixelColor);

		//처음 판단 값
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

// SomWorks :D // 원 그리기
void FSomDrawLibrary::DrawCircle(FPoint CenterVec, int r)
{
	int x = 0, y = 0;

	for (x = 0; x <= y; x++)
	{
		// SomWorks :D // y 축 좌표를 계산한다.
		y = (int)(sqrt(r*r - x * x) + 0.5);

		// SomWorks :D // 계산 방법
		// (1) 계산된 (x,y) 좌표에 픽셀을 출력한다.
		// (2) 픽셀의 출력은 원점(cx, cy) 만큼 평행 이동 시킨다.

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