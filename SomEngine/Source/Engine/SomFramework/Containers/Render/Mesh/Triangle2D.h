// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#pragma once

#include "Engine/Engine.h"

class FTriangle2D
{
public:
	FTriangle2D();
	FTriangle2D(FVertex2D a, FVertex2D b, FVertex2D c, bool bFillTriangle = false);
	FTriangle2D(FVertex2D a, FVertex2D b, FVertex2D c, const FTexture2D& Tex, bool bUseTextrue = true);
	~FTriangle2D();

private:
	// SomWorks :D // 삼각형 버텍스 소팅
	void VertexSort(FVertex2D a, FVertex2D b, FVertex2D c);
	
	// SomWorks :D // 삼각형 초기화
	void TriangleInitialize();

	// SomWorks :D // 삼각형 무게중심 좌표 BarycentricCoordinate
	FVector GetVertexWeight(const FVector& Value) const;

	// SomWorks :D // 무게중심 좌표를 사용한 색상 표현
	FColor GetVertexWeightColor(const FVector2D& Value) const;

	// SomWorks :D // 삼각형 그리기
	void DrawTriangle(bool bFillTriangle = false, bool bUseTexture = false);

	// SomWorks :D // 삼각형 채우기
	void FillTriangle(bool bUseTexture = false);

public:
	vector<FVertex2D> Vertices;
	
	FVertex2D TopVertex;
	FVertex2D MiddleVertex;
	FVertex2D BottomVertex;
	FVector2D FourthVertex;

	FVector2D V_u;
	FVector2D V_v;

	float DotUU = 0.0f;
	float DotVV = 0.0f;
	float DotUV = 0.0f;
	float DotVU = 0.0f;
	float WeightDenominator = 0.0f;

	FTexture2D CurrentTex;

protected:

public:
	bool bUseBarycentricCoordinate = false;
	
};