// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#include "SomDrawLibrary.h"

FSomDrawLibrary::FSomDrawLibrary()
{
}

FSomDrawLibrary::~FSomDrawLibrary()
{
}

// SomWorks :D // 픽셀 찍기 API
void FSomDrawLibrary::DrawPixel(int x, int y)
{
	if (!FSomMathLibrary::IsInRange(x, y)) return;

	ULONG* dest = (ULONG*)SomFramework_SR::GetInstance()->g_pBits;
	DWORD offset = SomWidth * SomHeight / 2 + SomWidth / 2 + x + SomWidth * -y; // SomWidth * x + SomHeight * y;
	*(dest + offset) = SomFramework_SR::GetInstance()->g_CurrentColor;
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
		//cout << (Point2.y - Point1.y) / (Point2.x - Point1.x) << ", " << Result << endl;
		DrawPixel((Point1.x + i) * a, (Point1.y + i) * b);
		// cout << Result << endl;
	}

	// SomWorks :D // i는 X값 Result는 Y값
/*
	for (int i = Point1.x; i < Point2.x; i++)
	{
		Result = static_cast<int>(((Point2.y - Point1.y) / (Point2.x - Point1.x)) * (i - Point1.x) + Point1.y);
		//cout << (Point2.y - Point1.y) / (Point2.x - Point1.x) << ", " << Result << endl;
		DrawPixel(i, Result);
		// cout << Result << endl;
	}*/
}

// SomWorks :D // 브레젠험 직선 알고리즘
void FSomDrawLibrary::DrawLine_BresenhamAlgorithm(Point2D Point1, Point2D Point2)
{
	// -W( y - yl ) + H ( x - xl ) < 0

	int dx, dy = 0;

	dx = abs(Point2.x - Point1.x);
	dy = abs(Point2.y - Point1.y);

	if (dy <= dx)
	{

	}
	else
	{

	}
}

// SomWorks :D // 삼각형 그리기
void FSomDrawLibrary::DrawTriangle(FVector2D a, FVector2D b, FVector2D c)
{

}

// SomWorks :D // 원 그리기
void FSomDrawLibrary::DrawCircle(Point2D CenterLocation, int r)
{
	int x = 0, y = 0;

	for (x = 0; x <= y; x++)
	{
		// SomWorks :D // y 축 좌표를 계산한다.
		y = (int)(sqrt(r*r - x * x) + 0.5);

		FSomDrawLibrary::DrawPixel(CenterLocation.x + x, CenterLocation.y + y); // (1) 계산된 (x,y) 좌표에 픽셀을 출력한다.
		FSomDrawLibrary::DrawPixel(CenterLocation.x + x, CenterLocation.y - y); // (2) 픽셀의 출력은 원점(cx, cy) 만큼 평행 이동 시킨다.
		FSomDrawLibrary::DrawPixel(CenterLocation.x - x, CenterLocation.y + y);
		FSomDrawLibrary::DrawPixel(CenterLocation.x - x, CenterLocation.y - y);
		FSomDrawLibrary::DrawPixel(CenterLocation.x + y, CenterLocation.y + x);
		FSomDrawLibrary::DrawPixel(CenterLocation.x + y, CenterLocation.y - x);
		FSomDrawLibrary::DrawPixel(CenterLocation.x - y, CenterLocation.y + x);
		FSomDrawLibrary::DrawPixel(CenterLocation.x - y, CenterLocation.y - x);
	}
}