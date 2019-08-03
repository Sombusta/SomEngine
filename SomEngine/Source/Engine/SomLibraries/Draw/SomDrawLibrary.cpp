// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#include "SomDrawLibrary.h"

FSomDrawLibrary::FSomDrawLibrary()
{
}

FSomDrawLibrary::~FSomDrawLibrary()
{
}

// SomWorks :D // 픽셀 찍기 API
void FSomDrawLibrary::DrawPixel(int x, int y, FColor color)
{
	if (!FSomMathLibrary::IsInRange(x, y)) return;

	ULONG PixelColor = RGB(color.b, color.g, color.r);

	ULONG* dest = (ULONG*)SomFramework_SR::GetInstance()->Bits;
	DWORD offset = SomWidth * SomHeight / 2 + SomWidth / 2 + x + SomWidth * -y; // SomWidth * x + SomHeight * y;
	*(dest + offset) = PixelColor; // SomFramework_SR::GetInstance()->CurrentColor;
}

// SomWorks :D // 직선의 방정식만 가지고 제작된 선 긋기 알고리즘
void FSomDrawLibrary::DrawLine(Point2D Point1, Point2D Point2)
{
	// y = (x2 - x1)/(y2 - y1) * (x - x1) + y1

	int Result = 0;

	int Length = static_cast<int>(sqrt(((Point2.x - Point1.x)*(Point2.x - Point1.x)) + (Point2.y - Point1.y)*(Point2.y - Point1.y)));

	int a = Point2.x < 0 ? -1 : 1;
	int b = Point2.y < 0 ? -1 : 1;
		
	for (int i = 0; i < Length; i++)
	{
		Result = static_cast<int>(((Point2.y - Point1.y) / (Point2.x - Point1.x)) * (i - Point1.x) + Point1.y);
		DrawPixel((Point1.x + i) * a, (Point1.y + i) * b);
	}

	// SomWorks :D // i는 X값 Result는 Y값
/*
	for (int i = Point1.x; i < Point2.x; i++)
	{
		Result = static_cast<int>(((Point2.y - Point1.y) / (Point2.x - Point1.x)) * (i - Point1.x) + Point1.y);
		DrawPixel(i, Result);
	}*/
}

// SomWorks :D // 브레젠험 직선 알고리즘
void FSomDrawLibrary::DrawLine_BresenhamAlgorithm(Point2D Point1, Point2D Point2)
{
	int dx, dy = 0;

	int p_value;
	int inc_minus;
	int inc_plus;
	int inc_value;
	int ndx;

	dx = abs(Point2.x - Point1.x);
	dy = abs(Point2.y - Point1.y);

	//변화폭을 따져 완만한 좌표를 기준으로 점을 찍는다.
	if (dy <= dx)
	{
		// y 보다 x 변화폭이 클 경우
		inc_minus = 2 * dy;
		inc_plus = 2 * (dy - dx);

		//선 x 점을 작은 수부터 그려나가기 위해.
		//Bresenham 공식은 다음점에 대한 위치를 잡는 것이기 때문에도.

		if (Point2.x < Point1.x)
		{
			ndx = Point1.x;
			Point1.x = Point2.x;
			Point2.x = ndx;

			ndx = Point1.y;
			Point1.y = Point2.y;
			Point2.y = ndx;
		}

		//x 값에 따른 y값 변화값 고르기
		if (Point1.y < Point2.y) {
			inc_value = 1;
		}
		else {
			inc_value = -1;
		}

		DrawPixel(Point1.x, Point1.y);

		//처음 판단 값
		p_value = 2 * dy - dx;

		for (ndx = Point1.x; ndx < Point2.x; ++ndx)
		{
			if (0 > p_value) {
				p_value += inc_minus;
			}
			else {
				p_value += inc_plus;
				Point1.y += inc_value;
			}

			DrawPixel(ndx, Point1.y);
		}
	}
	else
	{
		inc_minus = 2 * dx;
		inc_plus = 2 * (dx - dy);

		if (Point2.y < Point1.y) {
			ndx = Point1.y;
			Point1.y = Point2.y;
			Point2.y = ndx;

			ndx = Point1.x;
			Point1.x = Point2.x;
			Point2.x = ndx;
		}

		if (Point1.x < Point2.x) {
			inc_value = 1;
		}
		else {
			inc_value = -1;
		}
		DrawPixel(Point1.x, Point1.y);

		p_value = 2 * dx - dy;

		for (ndx = Point1.y; ndx < Point2.y; ++ndx)
		{
			if (0 > p_value)
			{
				p_value += inc_minus;
			}
			else
			{
				p_value += inc_plus;
				Point1.x += inc_value;
			}

			DrawPixel(Point1.x, ndx);
		}
	}
}

// SomWorks :D // 삼각형 그리기
void FSomDrawLibrary::DrawTriangle(FVector2D a, FVector2D b, FVector2D c, bool bFillTriangle)
{
	Point2D a1 = Point2D(static_cast<int>(a.x), static_cast<int>(a.y));
	Point2D b1 = Point2D(static_cast<int>(b.x), static_cast<int>(b.y));
	Point2D c1 = Point2D(static_cast<int>(c.x), static_cast<int>(c.y));

	DrawLine_BresenhamAlgorithm(a1, b1);
	DrawLine_BresenhamAlgorithm(b1, c1);
	DrawLine_BresenhamAlgorithm(c1, a1);

	// SomWorks :D // 삼각형 채우기
	if (bFillTriangle)
	{		
		FillTriangle(false);
	}
}

// SomWorks :D // 삼각형 채우기
void FSomDrawLibrary::FillTriangle(bool bUseBarycentricCoordinate)
{
	// SomWorks :D // 무게중심 좌표계 사용 그라데이션 처리
	if (bUseBarycentricCoordinate)
	{
	}
	else
	{
		// SomWorks :D // 삼각형 내부 색상 초기화		
	}
	// SomWorks :D // 버텍스 정렬

	// SomWorks :D // 삼각형 제 4의 버텍스 계산

	// SomWorks :D // 위에 삼각형부터 순회

	// SomWorks :D // 삼각형 내부 채우기
}

// SomWorks :D // 원 그리기
void FSomDrawLibrary::DrawCircle(Point2D CenterVec, int r)
{
	int x = 0, y = 0;

	for (x = 0; x <= y; x++)
	{
		// SomWorks :D // y 축 좌표를 계산한다.
		y = (int)(sqrt(r*r - x * x) + 0.5);

		// SomWorks :D // 계산 방법
		// (1) 계산된 (x,y) 좌표에 픽셀을 출력한다.
		// (2) 픽셀의 출력은 원점(cx, cy) 만큼 평행 이동 시킨다.

		FSomDrawLibrary::DrawPixel(CenterVec.x + x, CenterVec.y + y);
		FSomDrawLibrary::DrawPixel(CenterVec.x + x, CenterVec.y - y);
		FSomDrawLibrary::DrawPixel(CenterVec.x - x, CenterVec.y + y);
		FSomDrawLibrary::DrawPixel(CenterVec.x - x, CenterVec.y - y);
		FSomDrawLibrary::DrawPixel(CenterVec.x + y, CenterVec.y + x);
		FSomDrawLibrary::DrawPixel(CenterVec.x + y, CenterVec.y - x);
		FSomDrawLibrary::DrawPixel(CenterVec.x - y, CenterVec.y + x);
		FSomDrawLibrary::DrawPixel(CenterVec.x - y, CenterVec.y - x);
	}
}