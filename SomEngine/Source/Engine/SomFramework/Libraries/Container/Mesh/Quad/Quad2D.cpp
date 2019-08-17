// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#include "Quad2D.h"
#include "Engine/SomFramework/Libraries/Parser/TextureParser_Bmp.h"

FQuad2D::FQuad2D() : StartVertex(0.0f, 0.0f), EndVertex(0.0f, 0.0f)
{
	QuadInitialize();

	DrawQuad();
}

FQuad2D::FQuad2D(FVector2D a, FVector2D b, bool bFillQuad) : StartVertex(a.X, a.Y), EndVertex(b.X, b.Y)
{
	VertexSort(a, b);

	QuadInitialize();

	DrawQuad(true);
}

FQuad2D::FQuad2D(const FTexture2D& Tex, char* FileName)
{
	bUseBarycentricCoordinate = true;

	CurrentTex = Tex;

	FSomTextureParser_BMP::OpenBMP(CurrentTex, FileName);

	StartVertex = FVertex2D(0.0f, 0.0f);
	StartVertex.UV = FVector2D(0, 0);
	EndVertex = FVertex2D(300.0f, -300.0f);
	EndVertex.UV = FVector2D(1, 1);
	//EndVertex = FVector2D(CurrentTex.Width, CurrentTex.Height);

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
		FVector2D::Swap(StartVertex.Location, EndVertex.Location);
	}
}

void FQuad2D::QuadInitialize()
{
	StartVertex_End.Location = FVector2D(EndVertex.Location.X, StartVertex.Location.Y); //	FVector2D V_u = FVector2D(EndVertex.X - StartVertex.X, StartVertex.Y) - StartVertex;
	StartVertex_End.UV = FVector2D(1, 0);
	EndVertex_Start.Location = FVector2D(StartVertex.Location.X, EndVertex.Location.Y); // FVector2D V_v = FVector2D(StartVertex.X, (EndVertex.Y - StartVertex.Y)) - StartVertex;
	EndVertex_Start.UV = FVector2D(0, 1);

	//V_u = StartVertex_End - StartVertex;
	//V_v = EndVertex_Start - StartVertex;

	V_u = StartVertex.Location - StartVertex_End.Location;
	V_v = StartVertex.Location - EndVertex_Start.Location;

	DotUU = FVector2D::DotProduct(V_u, V_u);
	DotVV = FVector2D::DotProduct(V_v, V_v);
	DotUV = FVector2D::DotProduct(V_u, V_v);
	DotVU = FVector2D::DotProduct(V_v, V_u);

	WeightDenominator = DotUU * DotVV - DotUV * DotVU;
}

FVector2D FQuad2D::GetVertexWeight(const FVector2D& Value) const
{
	FVector2D Result;

	FVector2D w = StartVertex.Location - Value;

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
	FPoint a = FPoint(StartVertex.Location.X, StartVertex.Location.Y);
	FPoint b = FPoint(StartVertex_End.Location.X, StartVertex_End.Location.Y);
	FPoint c = FPoint(EndVertex.Location.X, EndVertex.Location.Y);
	FPoint d = FPoint(EndVertex_Start.Location.X, EndVertex_Start.Location.Y);

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
	for (int i = StartVertex.Location.Y; i >= EndVertex.Location.Y; --i)
	{
		for (int j = StartVertex.Location.X; j < EndVertex.Location.X; ++j)
		{
			FVector2D VertexWeight = GetVertexWeight(FVector2D(j, i));
						
			FVector2D Result;

			Result.X = CurrentTex.Width * VertexWeight.X;
			Result.Y = CurrentTex.Height * VertexWeight.Y;

			int Testa = FSomMathLibrary::Clamp(static_cast<int>(Result.X), 0, 300);
			int Testb = FSomMathLibrary::Clamp(static_cast<int>(Result.Y), 0, -300);
			
			FColor QuadColor = bUseBarycentricCoordinate ? GetVertexWeightColor(FVector2D(j, i)) : FSomTextureParser_BMP::GetPixel(Testa, Testb, CurrentTex);

			FSomDrawLibrary::DrawPixel(j, i, QuadColor);
		}
	}
}