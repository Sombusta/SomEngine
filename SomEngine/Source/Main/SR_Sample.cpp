// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#include "SR_Sample.h"
#include <time.h>

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
}

void SR_Sample::Render()
{
	// clock_t begin, end;

	// begin = clock(); // 시간설정

	// FSomDrawLibrary::DrawPixel(0, 0);

	FPoint p1 = FPoint(0, 0);
	FPoint p2 = FPoint(-100, 100);
	
	/*
	Points.push_back(p1);
	Points.push_back(p2);
	
	for (vector<FPoint>::iterator it = Points.begin(); it != Points.end(); it++)
	{
		it->Printf();
	}

	Points.clear();
*/

	// FSomDrawLibrary::DrawLine_BresenhamAlgorithm(FPoint(0, 0), FPoint(100, 0));	
	FSomDrawLibrary::DrawTriangle(FVector2D(-100, -100), FVector2D(-50, 100), FVector2D(80, -50), true);

	// end = clock(); // 시간설정
	// cout << "수행시간 : " << ((float)(end - begin) / CLOCKS_PER_SEC) << endl;
}

void SR_Sample::Terminate()
{
}