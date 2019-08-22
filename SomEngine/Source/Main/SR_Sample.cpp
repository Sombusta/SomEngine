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

	/*
	Points.push_back(p1);
	Points.push_back(p2);
	
	for (vector<FPoint>::iterator it = Points.begin(); it != Points.end(); it++)
	{
		it->Printf();
	}

	Points.clear();
*/
	FQuad2D Texting(SomManager_Texture::GetInstance()->T_Test1);
	// FSomDrawLibrary::DrawLine_BresenhamAlgorithm(FPoint(0, 0), FPoint(100, 0));	

	FVertex2D a(-100, -100);
	a.UV = FVector2D(0, 1);

	FVertex2D b(-50, 100);
	b.UV = FVector2D(0, 0);

	FVertex2D c(80, -50);
	c.UV = FVector2D(1, 0);

	FVertex2D d(80, -200);
	d.UV = FVector2D(1, 1);
	
	FTriangle2D MyTriangle(a, b, c, SomManager_Texture::GetInstance()->T_Test1, true);
	FTriangle2D MyTriangle2(a, d, c, SomManager_Texture::GetInstance()->T_Test1, false);

	// end = clock(); // 시간설정
	// cout << "수행시간 : " << ((float)(end - begin) / CLOCKS_PER_SEC) << endl;
}

void SR_Sample::Terminate()
{
}