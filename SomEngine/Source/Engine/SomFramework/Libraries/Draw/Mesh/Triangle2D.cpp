// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#include "Triangle2D.h"
#include "Engine/SomFramework/Libraries/Draw/Texture/TextureParser_Bmp.h"

FTriangle2D::FTriangle2D() : TopVertex(0.0f, 0.0f), MiddleVertex(0.0f, 0.0f), BottomVertex(0.0f, 0.0f)
{
	TriangleInitialize();
}

FTriangle2D::FTriangle2D(FVertex2D a, FVertex2D b, FVertex2D c, bool bFillTriangle) : TopVertex(a), MiddleVertex(b), BottomVertex(c)
{
	VertexSort(a, b, c);

	TriangleInitialize();

	DrawTriangle(bFillTriangle);
}

FTriangle2D::FTriangle2D(FVertex2D a, FVertex2D b, FVertex2D c, const FTexture2D& Tex, bool bUseTextrue) : TopVertex(a), MiddleVertex(b), BottomVertex(c)
{
	VertexSort(a, b, c);

	CurrentTex = Tex;

	//EndVertex = FVector2D(CurrentTex.Width, CurrentTex.Height);

	TriangleInitialize();

	DrawTriangle(true, bUseTextrue);
}

FTriangle2D::~FTriangle2D()
{
}

void FTriangle2D::VertexSort(FVertex2D a, FVertex2D b, FVertex2D c)
{
	// SomWorks :D // 삼각형 버텍스 Y 축 정렬
	if (a.Location.Y >= b.Location.Y)
	{
		TopVertex = a;
		BottomVertex = b.Location.Y >= c.Location.Y ? c : b;
		MiddleVertex = b.Location.Y >= c.Location.Y ? b : c;

		if (c.Location.Y >= a.Location.Y)
		{
			TopVertex = c;
			MiddleVertex = a.Location.Y >= b.Location.Y ? a : b;
			BottomVertex = a.Location.Y >= b.Location.Y ? b : a;
		}
	}
	else if (b.Location.Y >= a.Location.Y)
	{
		TopVertex = b;
		MiddleVertex = a.Location.Y >= c.Location.Y ? a : c;
		BottomVertex = a.Location.Y >= c.Location.Y ? c : a;

		if (c.Location.Y >= b.Location.Y)
		{
			TopVertex = c;
			MiddleVertex = b.Location.Y >= a.Location.Y ? b : a;
			BottomVertex = b.Location.Y >= a.Location.Y ? a : b;
		}
	}
}

void FTriangle2D::TriangleInitialize()
{
	// SomWorks :D // 삼각형 제 4의 버텍스 계산 // x = x1 - (y1 - y) * (x1 - x2) / (y1 - y2)
	FourthVertex = FVector2D(TopVertex.Location.X - (TopVertex.Location.Y - MiddleVertex.Location.Y) * (TopVertex.Location.X - BottomVertex.Location.X) / (TopVertex.Location.Y - BottomVertex.Location.Y), MiddleVertex.Location.Y);

	V_u = TopVertex.Location - MiddleVertex.Location;
	V_v = TopVertex.Location - BottomVertex.Location;

	DotUU = FVector2D::DotProduct(V_u, V_u);
	DotVV = FVector2D::DotProduct(V_v, V_v);
	DotUV = FVector2D::DotProduct(V_u, V_v);
	DotVU = FVector2D::DotProduct(V_v, V_u);

	WeightDenominator = DotUU * DotVV - DotUV * DotVU;
}

FVector FTriangle2D::GetVertexWeight(const FVector& Value) const
{
	FVector Result;
	
	FVector2D w = TopVertex.Location - FVector2D(Value.X, Value.Y);

	Result.Y = (FVector2D::DotProduct(w, V_u) * DotVV - FVector2D::DotProduct(w, V_v) * DotVU) / WeightDenominator;
	Result.Z = (FVector2D::DotProduct(w, V_v) * DotUU - FVector2D::DotProduct(w, V_u) * DotUV) / WeightDenominator;
	Result.X = (1 - Result.Y - Result.Z);

	return Result;
}

FColor FTriangle2D::GetVertexWeightColor(const FVector2D& Value) const
{
	FVector VertexWeight = GetVertexWeight(FVector(Value.X, Value.Y, 0.0f));

	FColor Result;

	Result.r = VertexWeight.X * 255;
	Result.g = VertexWeight.Y * 255;

	Result.b = VertexWeight.Z * 255;

	return Result;
}

void FTriangle2D::DrawTriangle(bool bFillTriangle, bool bUseTexture)
{
	FPoint2D a1 = FPoint2D(TopVertex.Location.X, TopVertex.Location.Y);
	FPoint2D b1 = FPoint2D(MiddleVertex.Location.X, MiddleVertex.Location.Y);
	FPoint2D c1 = FPoint2D(BottomVertex.Location.X, BottomVertex.Location.Y);

	if (bFillTriangle)
	{
		FillTriangle(bUseTexture);

		// SomWorks :D // Draw Outline
		FSomDrawLibrary::DrawLine_BresenhamAlgorithm(a1, b1); //DrawLine(a1, b1);
		FSomDrawLibrary::DrawLine_BresenhamAlgorithm(b1, c1); //DrawLine(b1, c1);
		FSomDrawLibrary::DrawLine_BresenhamAlgorithm(c1, a1); //DrawLine(c1, a1);
	}
	else
	{
		FSomDrawLibrary::DrawLine_BresenhamAlgorithm(a1, b1); //DrawLine(a1, b1);
		FSomDrawLibrary::DrawLine_BresenhamAlgorithm(b1, c1); //DrawLine(b1, c1);
		FSomDrawLibrary::DrawLine_BresenhamAlgorithm(c1, a1); //DrawLine(c1, a1);
	}
}

void FTriangle2D::FillTriangle(bool bUseTexture)
{
	// SomWorks :D // 위에 버텍스부터 순회, 삼각형 내부 채우기
	for (int i = static_cast<int>(TopVertex.Location.Y); i >= FourthVertex.Y; --i) //for (int i = 0; i <= Length_Y; i++)
	{
		// SomWorks :D // 유레카!!!!
		float x1 = TopVertex.Location.X - (TopVertex.Location.Y - i) * (TopVertex.Location.X - MiddleVertex.Location.X) / (TopVertex.Location.Y - MiddleVertex.Location.Y);
		float x2 = TopVertex.Location.X - (TopVertex.Location.Y - i) * (TopVertex.Location.X - FourthVertex.X) / (TopVertex.Location.Y - FourthVertex.Y);

		// DrawPixel(static_cast<int>(x1), i);
		// DrawPixel(static_cast<int>(x2), i);

		FVector2D StartVertex = FVector2D(static_cast<int>(x1), i);
		FVector2D EndVertex = FVector2D(static_cast<int>(x2), i);

		if (StartVertex.X > EndVertex.X)
		{
			FVector2D::Swap(StartVertex, EndVertex);
		}

		for (int j = static_cast<int>(StartVertex.X); j <= EndVertex.X; ++j)
		{
			float testy = (EndVertex.Y - StartVertex.Y) / (EndVertex.X - StartVertex.X) * (j - StartVertex.X) + StartVertex.Y;

			FColor TriangleColor;

			if (bUseTexture)
			{
				FVector VertexWeight = GetVertexWeight(FVector(j, static_cast<int>(testy), 0));

				FVector2D TextureUV =
					TopVertex.UV * VertexWeight.X +
					MiddleVertex.UV * VertexWeight.Y + 
					BottomVertex.UV * VertexWeight.Z;

				FVector2D Result;
				Result.X = CurrentTex.Width * TextureUV.X;
				Result.Y = CurrentTex.Height * TextureUV.Y;

				FColor Test;
				Test.r = TextureUV.X * 255;
				Test.g = TextureUV.Y * 255;
				Test.b = 0;

				//TriangleColor = Test;

				TriangleColor = bUseBarycentricCoordinate? Test : FSomTextureParser_BMP::GetPixel(Result.X, Result.Y, CurrentTex);
			}
			else
			{
				TriangleColor = bUseBarycentricCoordinate ? GetVertexWeightColor(FVector2D(j, static_cast<int>(testy))) : FColor(255, 255, 255);
			}

			FSomDrawLibrary::DrawPixel(j, static_cast<int>(testy), TriangleColor);
		}

		//DrawLine_BresenhamAlgorithm(FPoint2D(static_cast<int>(x1), i), FPoint2D(static_cast<int>(x2), i), Test);
	}

	for (int i = static_cast<int>(BottomVertex.Location.Y); i <= MiddleVertex.Location.Y; ++i)
	{
		float x1 = BottomVertex.Location.X - (BottomVertex.Location.Y - i) * (BottomVertex.Location.X - MiddleVertex.Location.X) / (BottomVertex.Location.Y - MiddleVertex.Location.Y);
		float x2 = BottomVertex.Location.X - (BottomVertex.Location.Y - i) * (BottomVertex.Location.X - FourthVertex.X) / (BottomVertex.Location.Y - FourthVertex.Y);

		FVector2D StartVertex = FVector2D(static_cast<int>(x1), i);
		FVector2D EndVertex = FVector2D(static_cast<int>(x2), i);

		if (StartVertex.X > EndVertex.X)
		{
			FVector2D::Swap(StartVertex, EndVertex);
		}

		for (int j = static_cast<int>(StartVertex.X); j <= EndVertex.X; ++j)
		{
			float testy = (EndVertex.Y - StartVertex.Y) / (EndVertex.X - StartVertex.X) * (j - StartVertex.X) + StartVertex.Y;

			FVector2D w = TopVertex.Location - FVector2D(j, static_cast<int>(testy));

			FColor TriangleColor;

			if (bUseTexture)
			{
				FVector VertexWeight = GetVertexWeight(FVector(j, static_cast<int>(testy), 0));

				FVector2D TextureUV =
					TopVertex.UV * VertexWeight.X +
					MiddleVertex.UV * VertexWeight.Y +
					BottomVertex.UV * VertexWeight.Z;

				FVector2D Result;
				Result.X = CurrentTex.Width * TextureUV.X;
				Result.Y = CurrentTex.Height * TextureUV.Y;

				FColor Test;
				Test.r = TextureUV.X * 255;
				Test.g = TextureUV.Y * 255;
				Test.b = 0;

				//TriangleColor = Test;

				TriangleColor = bUseBarycentricCoordinate ? Test : FSomTextureParser_BMP::GetPixel(Result.X, Result.Y, CurrentTex);
			}
			else
			{
				TriangleColor = bUseBarycentricCoordinate ? GetVertexWeightColor(FVector2D(j, static_cast<int>(testy))) : FColor(255, 255, 255);
			}

			FSomDrawLibrary::DrawPixel(j, static_cast<int>(testy), TriangleColor);
		}

		//DrawLine_BresenhamAlgorithm(FPoint2D(static_cast<int>(x1), i), FPoint2D(static_cast<int>(x2), i), Test1);
	}
}