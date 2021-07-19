// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#pragma once

#include "Engine/Engine.h"

class FSomDrawLibrary
{
public:
	FSomDrawLibrary();
	~FSomDrawLibrary();

	// SomWorks :D // �ȼ� �׸��� �Լ�
	static void DrawPixel(int x, int y, FColor PixelColor = FColor(255, 255, 255));
	
	static void DrawPixel(FPoint2D PointLocation, FColor PixelColor = FColor(255, 255, 255));

	// SomWorks :D // ������ �����ĸ� ������ ���۵� �� �߱� �˰���
	static void DrawLine(FPoint2D Point1, FPoint2D Point2);

	// SomWorks :D // �극���� ���� �˰��� ��� (Bresenham Algorithm)
	static void DrawLine_BA(const FPoint2D& StartPoint, const FPoint2D& EndPoint, FLinearColor PixelColor = FLinearColor::White);

	// SomWorks :D // �� �׸���
	static void DrawCircle(FPoint2D CenterVec, int r);

private:	

protected:

public:

};