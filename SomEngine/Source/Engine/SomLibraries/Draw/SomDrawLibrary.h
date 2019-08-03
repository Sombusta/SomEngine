// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#pragma once

#include "Engine/Engine.h"

class FSomDrawLibrary
{
public:
	FSomDrawLibrary();
	~FSomDrawLibrary();

	// SomWorks :D // 픽셀 그리기 함수
	static void DrawPixel(int x, int y, FColor color = FColor(255, 255, 255));

	// SomWorks :D // 직선의 방정식만 가지고 제작된 선 긋기 알고리즘
	static void DrawLine(Point2D Point1, Point2D Point2);

	// SomWorks :D // 브레젠험 직선 알고리즘 사용
	static void DrawLine_BresenhamAlgorithm(Point2D Point1, Point2D Point2);

	// SomWorks :D // 삼각형 그리기
	static void DrawTriangle(FVector2D a, FVector2D b, FVector2D c, bool bFillTriangle = false);

	// SomWorks :D // 삼각형 채우기
	static void FillTriangle(bool bUseBarycentricCoordinate = false);

	// SomWorks :D // 원 그리기
	static void DrawCircle(Point2D CenterVec, int r);
private:	

protected:

public:

};