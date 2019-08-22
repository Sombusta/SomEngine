// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#pragma once

#include "Engine/Engine.h"

class FQuad2D
{
public:
	FQuad2D();
	FQuad2D(FVector2D a, FVector2D b, bool bFillQuad = false);
	FQuad2D(const FTexture2D& Tex);
	~FQuad2D();

private:
	// SomWorks :D // 쿼드 버텍스 소팅
	void VertexSort(FVector2D a, FVector2D b);

	// SomWorks :D // 쿼드 초기화
	void QuadInitialize();

	// SomWorks :D // 쿼드 무게중심 좌표 BarycentricCoordinate
	FVector2D GetVertexWeight(const FVector2D& Value) const;

	// SomWorks :D // 무게중심 좌표를 사용한 색상 표현
	FColor GetVertexWeightColor(const FVector2D& Value) const;

	// SomWorks :D // 쿼드 그리기
	void DrawQuad(bool bFillQuad = false);

	// SomWorks :D // 쿼드 채우기
	void FillQuad();

private:
	FVertex2D StartVertex;
	FVertex2D EndVertex;

	FVertex2D StartVertex_End;
	FVertex2D EndVertex_Start;

	vector<FVertex2D> Vertices;

	FVector2D V_u;
	FVector2D V_v;
	FVector2D V_w;

	float DotUU;
	float DotVV;
	float DotWW;
	float DotUV;
	float DotVU;	
	float WeightDenominator;

	FTexture2D CurrentTex;

protected:

public:
	bool bUseBarycentricCoordinate = false;

};