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
	// y = (x2 - x1)/(y2 - y1) * (x - x1) + y1

	// SomWorks :D // i는 X값 Result는 Y값 
	/*int Result = 0;

	for (int i = Point1.x; i < Point2.x; i++)
	{
		Result = static_cast<int>(((Point2.y - Point1.y) / (Point2.x - Point1.x)) * (i - Point1.x) + Point1.y);
		DrawPixel(i, Result);
	}*/

	int Result = 0;

	int Length = FSomMathLibrary::GetLineLength(Point1, Point2);

	int a = Point2.X < 0 ? -1 : 1;
	int b = Point2.Y < 0 ? -1 : 1;
		
	for (int i = 0; i < Length; i++)
	{
		Result = static_cast<int>(((Point2.Y - Point1.Y) / (Point2.X - Point1.X)) * (i - Point1.X) + Point1.Y);
		DrawPixel((Point1.X + i) * a, (Point1.Y + i) * b);
	}
}

// SomWorks :D // 브레젠험 직선 알고리즘
void FSomDrawLibrary::DrawLine_BresenhamAlgorithm(FPoint Point1, FPoint Point2)
{
	int dx, dy = 0;

	int p_value;
	int inc_minus;
	int inc_plus;
	int inc_value;
	int ndx;

	dx = abs(Point2.X - Point1.X);
	dy = abs(Point2.Y - Point1.Y);

	//변화폭을 따져 완만한 좌표를 기준으로 점을 찍는다.
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

		DrawPixel(Point1.X, Point1.Y);

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

			DrawPixel(ndx, Point1.Y);
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

		DrawPixel(Point1.X, Point1.Y);

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

			DrawPixel(Point1.X, ndx);
		}
	}
}

// SomWorks :D // 삼각형 그리기
void FSomDrawLibrary::DrawTriangle(FVector2D a, FVector2D b, FVector2D c, bool bFillTriangle)
{
	FPoint a1 = FPoint(a.X, a.Y);
	FPoint b1 = FPoint(b.X, b.Y);
	FPoint c1 = FPoint(c.X, c.Y);

	DrawLine_BresenhamAlgorithm(a1, b1);
	DrawLine_BresenhamAlgorithm(b1, c1);
	DrawLine_BresenhamAlgorithm(c1, a1);

	// SomWorks :D // 삼각형 채우기
	if (bFillTriangle)
	{		
		FillTriangle(a, b, c, false);
	}
}

// SomWorks :D // 삼각형 채우기
void FSomDrawLibrary::FillTriangle(FVector2D a, FVector2D b, FVector2D c, bool bUseBarycentricCoordinate)
{
	// SomWorks :D // 버텍스 정렬
	FVector2D TopVertex;
	FVector2D MiddleVertex;
	FVector2D BottomVertex;

	if (a.Y >= b.Y)
	{
		TopVertex = a;		
		MiddleVertex = b.Y >= c.Y ? b : c;
		BottomVertex = b.Y >= c.Y ? c : b;

		if (c.Y >= a.Y)
		{
			TopVertex = c;
			MiddleVertex = a.Y >= b.Y ? a : b;
			BottomVertex = a.Y >= b.Y ? b : a;
		}
	}
	else if (b.Y >= a.Y)
	{
		TopVertex = b;
		MiddleVertex = a.Y >= c.Y ? a : c;
		BottomVertex = a.Y >= c.Y ? c : a;

		if (c.Y >= b.Y)
		{
			TopVertex = c;
			MiddleVertex = b.Y >= a.Y ? b : a;
			BottomVertex = b.Y >= a.Y ? a : b;
		}
	}

	// SomWorks :D // 삼각형 제 4의 버텍스 계산
	float x = TopVertex.X - (TopVertex.Y - MiddleVertex.Y) * (TopVertex.X - BottomVertex.X) / (TopVertex.Y - BottomVertex.Y);

	FVector2D d = FVector2D(x, MiddleVertex.Y);
		
	int Length_Y = static_cast<int>(abs(TopVertex.Y - BottomVertex.Y));
	
	// SomWorks :D // 위에 버텍스부터 순회, 삼각형 내부 채우기
	for (int i = static_cast<int>(TopVertex.Y); i >= d.Y; i--) //for (int i = 0; i <= Length_Y; i++)
	{
		// for(int j = 0;)
		

	}
	
	// SomWorks :D // 무게중심 좌표계 사용 그라데이션 처리
	if (bUseBarycentricCoordinate)
	{
	}
	else
	{		
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