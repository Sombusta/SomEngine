// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#pragma once

#include "Engine/Engine.h"

class FTriangle2D
{
public:
	FTriangle2D();
	FTriangle2D(FVector2D a, FVector2D b, FVector2D c, bool bFillTriangle = false);
	~FTriangle2D();

private:
	// SomWorks :D // 삼각형 버텍스 소팅
	void VertexSort(FVector2D a, FVector2D b, FVector2D c);

	// SomWorks :D // 삼각형 초기화
	void TriangleInitialize();

	// SomWorks :D // 삼각형 무게중심 좌표 BarycentricCoordinate
	FVector2D GetVertexWeight(const FVector2D& Value) const;

	// SomWorks :D // 무게중심 좌표를 사용한 색상 표현
	FColor GetVertexWeightColor(const FVector2D& Value) const;

	// SomWorks :D // 삼각형 그리기
	void DrawTriangle(bool bFillTriangle = false);

	// SomWorks :D // 삼각형 채우기
	void FillTriangle();

private:
	FVector2D TopVertex;
	FVector2D MiddleVertex;
	FVector2D BottomVertex;
	FVector2D FourthVertex;

	vector<FVector2D> Vertices;

	FVector2D V_u;
	FVector2D V_v;

	float DotUU;
	float DotVV;
	float DotUV;
	float DotVU;
	float WeightDenominator;

protected:

public:
	bool bUseBarycentricCoordinate = true;
	
};