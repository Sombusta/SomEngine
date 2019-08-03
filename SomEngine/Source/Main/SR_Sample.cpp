// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#include "SR_Sample.h"

SR_Sample::SR_Sample()
{
}

SR_Sample::~SR_Sample()
{
}

void SR_Sample::Init()
{
	cout << "Initialize" << endl;
}

void SR_Sample::Update(float DeltaTime)
{
	// FSomDrawLibrary::DrawPixel(0, 0);

	Point2D p1 = Point2D(0, 0);
	
	Point2D p2 = Point2D(-100, 100);
	
	// FSomDrawLibrary::DrawLine_BresenhamAlgorithm(Point2D(0, 0), Point2D(100, 0));	
}

void SR_Sample::Render()
{
	FSomDrawLibrary::DrawTriangle(FVector2D(-100, -100), FVector2D(-50, 100), FVector2D(80, -50));
}