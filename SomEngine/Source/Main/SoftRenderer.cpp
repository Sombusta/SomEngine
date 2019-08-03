// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#include "SoftRenderer.h"

void UpdateFrame(void)
{
	// FSomDrawLibrary::DrawPixel(0, 0);

	Point2D p1;
	p1.x = 0;
	p1.y = 0;

	Point2D p2;
	p2.x = -100;
	p2.y = 100;

	// FSomDrawLibrary::DrawLine_BresenhamAlgorithm(Point2D(0, 0), Point2D(100, 0));

	FSomDrawLibrary::DrawTriangle(FVector2D(-100, -100), FVector2D(-50, 100), FVector2D(80, -50));
}