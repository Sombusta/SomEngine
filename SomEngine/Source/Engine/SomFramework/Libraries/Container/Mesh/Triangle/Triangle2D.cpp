// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#include "Triangle2D.h"

FTriangle2D::FTriangle2D() : TopVertex(FVector2D(0.0f, 0.0f)), MiddleVertex(FVector2D(0.0f, 0.0f)), BottomVertex(FVector2D(0.0f, 0.0f))
{
	TriangleInitialize();
}

FTriangle2D::FTriangle2D(FVector2D a, FVector2D b, FVector2D c, bool bFillTriangle) : TopVertex(a), MiddleVertex(b), BottomVertex(c)
{
	VertexSort(a, b, c);

	TriangleInitialize();

	DrawTriangle(bFillTriangle);
}

FTriangle2D::~FTriangle2D()
{
}

void FTriangle2D::VertexSort(FVector2D a, FVector2D b, FVector2D c)
{
	// SomWorks :D // 삼각형 버텍스 Y 축 정렬
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
}

void FTriangle2D::TriangleInitialize()
{
	// SomWorks :D // 삼각형 제 4의 버텍스 계산 // x = x1 - (y1 - y) * (x1 - x2) / (y1 - y2)
	FourthVertex = FVector2D(TopVertex.X - (TopVertex.Y - MiddleVertex.Y) * (TopVertex.X - BottomVertex.X) / (TopVertex.Y - BottomVertex.Y), MiddleVertex.Y);

	V_u = TopVertex - MiddleVertex;
	V_v = TopVertex - BottomVertex;

	DotUU = FVector2D::DotProduct(V_u, V_u);
	DotVV = FVector2D::DotProduct(V_v, V_v);
	DotUV = FVector2D::DotProduct(V_u, V_v);
	DotVU = FVector2D::DotProduct(V_v, V_u);

	WeightDenominator = DotUU * DotVV - DotUV * DotVU;
}

FVector2D FTriangle2D::GetVertexWeight(const FVector2D& Value) const
{
	FVector2D Result;
	
	FVector2D w = TopVertex - Value;

	Result.X = (FVector2D::DotProduct(w, V_u) * DotVV - FVector2D::DotProduct(w, V_v) * DotVU) / WeightDenominator;
	Result.Y = (FVector2D::DotProduct(w, V_v) * DotUU - FVector2D::DotProduct(w, V_u) * DotUV) / WeightDenominator;

	return Result;
}

FColor FTriangle2D::GetVertexWeightColor(const FVector2D& Value) const
{
	FVector2D VertexWeight = GetVertexWeight(Value);

	FColor Result;

	Result.r = (1 - VertexWeight.X - VertexWeight.Y) * 255;
	Result.b = VertexWeight.X * 255;
	Result.g = VertexWeight.Y * 255;

	return Result;
}

void FTriangle2D::DrawTriangle(bool bFillTriangle)
{
	FPoint a1 = FPoint(TopVertex.X, TopVertex.Y);
	FPoint b1 = FPoint(MiddleVertex.X, MiddleVertex.Y);
	FPoint c1 = FPoint(BottomVertex.X, BottomVertex.Y);

	if (bFillTriangle)
	{
		FillTriangle();

		// SomWorks :D // Draw Outline
		/*FSomDrawLibrary::DrawLine_BresenhamAlgorithm(a1, b1); //DrawLine(a1, b1);
		FSomDrawLibrary::DrawLine_BresenhamAlgorithm(b1, c1); //DrawLine(b1, c1);
		FSomDrawLibrary::DrawLine_BresenhamAlgorithm(c1, a1); //DrawLine(c1, a1);*/
	}
	else
	{
		FSomDrawLibrary::DrawLine_BresenhamAlgorithm(a1, b1); //DrawLine(a1, b1);
		FSomDrawLibrary::DrawLine_BresenhamAlgorithm(b1, c1); //DrawLine(b1, c1);
		FSomDrawLibrary::DrawLine_BresenhamAlgorithm(c1, a1); //DrawLine(c1, a1);
	}
}

void FTriangle2D::FillTriangle()
{
	// SomWorks :D // 위에 버텍스부터 순회, 삼각형 내부 채우기
	for (int i = static_cast<int>(TopVertex.Y); i >= FourthVertex.Y; i--) //for (int i = 0; i <= Length_Y; i++)
	{
		// SomWorks :D // 유레카!!!!
		float x1 = TopVertex.X - (TopVertex.Y - i) * (TopVertex.X - MiddleVertex.X) / (TopVertex.Y - MiddleVertex.Y);
		float x2 = TopVertex.X - (TopVertex.Y - i) * (TopVertex.X - FourthVertex.X) / (TopVertex.Y - FourthVertex.Y);

		// DrawPixel(static_cast<int>(x1), i);
		// DrawPixel(static_cast<int>(x2), i);

		FVector2D StartVertex = FVector2D(static_cast<int>(x1), i);
		FVector2D EndVertex = FVector2D(static_cast<int>(x2), i);

		if (StartVertex.X > EndVertex.X)
		{
			FVector2D::Swap(StartVertex, EndVertex);
		}

		for (int j = static_cast<int>(StartVertex.X); j < EndVertex.X; j++)
		{
			float testy = (EndVertex.Y - StartVertex.Y) / (EndVertex.X - StartVertex.X) * (j - StartVertex.X) + StartVertex.Y;

			FColor TriangleColor = bUseBarycentricCoordinate ? GetVertexWeightColor(FVector2D(j, static_cast<int>(testy))) : FColor(255, 255, 255);

			FSomDrawLibrary::DrawPixel(j, static_cast<int>(testy), TriangleColor);
		}

		//DrawLine_BresenhamAlgorithm(FPoint(static_cast<int>(x1), i), FPoint(static_cast<int>(x2), i), Test);
	}

	for (int i = static_cast<int>(BottomVertex.Y); i <= MiddleVertex.Y; i++)
	{
		float x1 = BottomVertex.X - (BottomVertex.Y - i) * (BottomVertex.X - MiddleVertex.X) / (BottomVertex.Y - MiddleVertex.Y);
		float x2 = BottomVertex.X - (BottomVertex.Y - i) * (BottomVertex.X - FourthVertex.X) / (BottomVertex.Y - FourthVertex.Y);

		FVector2D StartVertex = FVector2D(static_cast<int>(x1), i);
		FVector2D EndVertex = FVector2D(static_cast<int>(x2), i);

		if (StartVertex.X > EndVertex.X)
		{
			FVector2D::Swap(StartVertex, EndVertex);
		}

		for (int j = static_cast<int>(StartVertex.X); j < EndVertex.X; j++)
		{
			float testy = (EndVertex.Y - StartVertex.Y) / (EndVertex.X - StartVertex.X) * (j - StartVertex.X) + StartVertex.Y;

			FVector2D w = TopVertex - FVector2D(j, static_cast<int>(testy));

			FColor TriangleColor = bUseBarycentricCoordinate ? GetVertexWeightColor(FVector2D(j, static_cast<int>(testy))) : FColor(255, 255, 255);

			FSomDrawLibrary::DrawPixel(j, static_cast<int>(testy), TriangleColor);
		}

		//DrawLine_BresenhamAlgorithm(FPoint(static_cast<int>(x1), i), FPoint(static_cast<int>(x2), i), Test1);
	}
}