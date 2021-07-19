// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#pragma once

#include "Engine/Engine.h"

class FSomDrawLibrary
{
public:
	FSomDrawLibrary();
	~FSomDrawLibrary();

	// SomWorks :D // 픽셀 그리기 함수
	static void DrawPixel(int x, int y, FColor PixelColor = FColor(255, 255, 255));
	
	static void DrawPixel(FPoint2D PointLocation, FColor PixelColor = FColor(255, 255, 255));

	// SomWorks :D // 직선의 방정식만 가지고 제작된 선 긋기 알고리즘
	static void DrawLine(FPoint2D Point1, FPoint2D Point2);

	// SomWorks :D // 브레젠험 직선 알고리즘 사용 (Bresenham Algorithm)
	static void DrawLine_BA(const FPoint2D& StartPoint, const FPoint2D& EndPoint, FLinearColor PixelColor = FLinearColor::White);

	// SomWorks :D // 원 그리기
	static void DrawCircle(FPoint2D CenterVec, int r);

private:	

protected:

public:

};