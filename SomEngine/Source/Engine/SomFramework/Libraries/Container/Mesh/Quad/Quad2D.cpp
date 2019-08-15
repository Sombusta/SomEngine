// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#include "Quad2D.h"
#include "Engine/SomFramework/Libraries/Parser/TextureParser_Bmp.h"

FQuad2D::FQuad2D() : StartVertex(FVector2D(0.0f, 0.0f)), EndVertex(FVector2D(0.0f, 0.0f))
{
	QuadInitialize();

	DrawQuad();
}

FQuad2D::FQuad2D(FVector2D a, FVector2D b, bool bFillQuad) : StartVertex(a), EndVertex(b)
{
	VertexSort(a, b);

	QuadInitialize();

	DrawQuad(true);
}

FQuad2D::FQuad2D(const FTexture2D& Tex, char* FileName)
{
	CurrentTex = Tex;

	FSomTextureParser_BMP::OpenBMP(CurrentTex, FileName);

	StartVertex = FVector2D(0.0f, 0.0f);
	EndVertex = FVector2D(CurrentTex.Width/3, CurrentTex.Height/3);

	QuadInitialize();

	DrawQuad(true);
}

FQuad2D::~FQuad2D()
{
}

void FQuad2D::VertexSort(FVector2D a, FVector2D b)
{
	if (a.X > b.X)
	{
		FVector2D::Swap(StartVertex, EndVertex);
	}
}

void FQuad2D::QuadInitialize()
{
	StartVertex_End = FVector2D(EndVertex.X, StartVertex.Y); //	FVector2D V_u = FVector2D(EndVertex.X - StartVertex.X, StartVertex.Y) - StartVertex;
	EndVertex_Start = FVector2D(StartVertex.X, EndVertex.Y); // FVector2D V_v = FVector2D(StartVertex.X, (EndVertex.Y - StartVertex.Y)) - StartVertex;

	//V_u = StartVertex_End - StartVertex;
	//V_v = EndVertex_Start - StartVertex;

	V_u = StartVertex - StartVertex_End;
	V_v = StartVertex - EndVertex_Start;


	DotUU = FVector2D::DotProduct(V_u, V_u);
	DotVV = FVector2D::DotProduct(V_v, V_v);
	DotUV = FVector2D::DotProduct(V_u, V_v);
	DotVU = FVector2D::DotProduct(V_v, V_u);

	WeightDenominator = DotUU * DotVV - DotUV * DotVU;
}

FVector2D FQuad2D::GetVertexWeight(const FVector2D& Value) const
{
	FVector2D Result;

	FVector2D w = StartVertex - Value;

	Result.X = (FVector2D::DotProduct(w, V_u) * DotVV - FVector2D::DotProduct(w, V_v) * DotVU) / WeightDenominator;
	Result.Y = (FVector2D::DotProduct(w, V_v) * DotUU - FVector2D::DotProduct(w, V_u) * DotUV) / WeightDenominator;

	return Result;
}

FColor FQuad2D::GetVertexWeightColor(const FVector2D& Value) const
{
	FVector2D VertexWeight = GetVertexWeight(Value);

	FColor Result;

	Result.r = VertexWeight.X * 255;
	Result.g = VertexWeight.Y * 255;
	Result.b = 0;

	return Result;
}

void FQuad2D::DrawQuad(bool bFillQuad)
{
	FPoint a = FPoint(StartVertex.X, StartVertex.Y);
	FPoint b = FPoint(StartVertex_End.X, StartVertex_End.Y);
	FPoint c = FPoint(EndVertex.X, EndVertex.Y);
	FPoint d = FPoint(EndVertex_Start.X, EndVertex_Start.Y);

	if (bFillQuad)
	{
		FillQuad();
	}
	else
	{
		FSomDrawLibrary::DrawLine_BresenhamAlgorithm(a, b);
		FSomDrawLibrary::DrawLine_BresenhamAlgorithm(a, d);
		FSomDrawLibrary::DrawLine_BresenhamAlgorithm(b, c);
		FSomDrawLibrary::DrawLine_BresenhamAlgorithm(d, c);
	}
}

void FQuad2D::FillQuad()
{
	// SomWorks :D // 무게중심 UV
	FVector2D Result;

	for (int i = StartVertex.Y; i < EndVertex.Y; i++)
	{
		for (int j = StartVertex.X; j < EndVertex.Y; j++)
		{
			FVector2D w = StartVertex - FVector2D(j, i);

			Result.X = (FVector2D::DotProduct(w, V_u) * DotVV - FVector2D::DotProduct(w, V_v) * DotVU) / WeightDenominator;
			Result.Y = (FVector2D::DotProduct(w, V_v) * DotUU - FVector2D::DotProduct(w, V_u) * DotUV) / WeightDenominator;

			FColor QuadColor = bUseBarycentricCoordinate ? GetVertexWeightColor(FVector2D(j, i)) : FSomTextureParser_BMP::GetPixel(j, 800, i, CurrentTex);

			FSomDrawLibrary::DrawPixel(j, i, QuadColor);
		}
	}
}