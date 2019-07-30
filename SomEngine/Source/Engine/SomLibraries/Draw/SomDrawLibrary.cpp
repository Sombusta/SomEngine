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

	ULONG* dest = (ULONG*)SomSoftRenderObject::GetInstance()->g_pBits;
	DWORD offset = SomWidth * SomHeight / 2 + SomWidth / 2 + x + SomWidth * -y; // SomWidth * x + SomHeight * y;
	*(dest + offset) = SomSoftRenderObject::GetInstance()->g_CurrentColor;
}

// SomWorks :D // 직선의 방정식만 가지고 제작된 선 긋기 알고리즘
void FSomDrawLibrary::DrawLine(Point2D Point1, Point2D Point2)
{
	// y = (x2 - x1)/(y2 - y1) * (x - x1) + y1

	int ResultY = 0;

	// SomWorks :D // i는 X값 ResultY 는 Y값
	for (int i = Point1.x; i < Point2.x; i++)
	{
		ResultY = static_cast<int>(((Point2.y - Point1.y) / (Point2.x - Point1.x)) * (i - Point1.x) + Point1.y);
		DrawPixel(i, ResultY);
		// cout << Result << endl;
	}
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