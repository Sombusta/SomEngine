﻿// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

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
	
	/*FPoint2D p1(0, 0);
	FPoint2D p2(100, 100);
	Points.push_back(p1);
	Points.push_back(p2);*/

	FMatrix2D Test1;
	FMatrix2D Test2;

	FVector2D VTest(5, 7);

	Test1._11 = 1;
	Test1._12 = 2;
	Test1._21 = 3;
	Test1._22 = 4;

	Test2._11 = 5;
	Test2._12 = 6;
	Test2._21 = 7;
	Test2._22 = 8;

	FMatrix2D Result = Test1 * Test2;

	cout << Result._11 << ", " << Result._12 << endl;
	cout << Result._21 << ", " << Result._22 << endl;

	FVector2D RV = Test1 * VTest;
	cout << VTest.X << ", " << VTest.Y << endl;

	cout << RV.X << ", " << RV.Y << endl;

}

void SR_Sample::Update(float DeltaTime)
{	
	// SomWorks :D  // 시작 시간설정
	// clock_t begin = clock();
		
	// SomWorks :D  // 끝 시간설정
	// clock_t end = clock();
	// cout << "수행시간 : " << ((float)(end - begin) / CLOCKS_PER_SEC) << endl;
}

// SomWorks :D // 텍스처 테스트용 define
#define TextureTEST 1

void SR_Sample::Render()
{
	// FSomDrawLibrary::DrawPixel(0, 0);
			
	/*for (vector<FPoint2D>::iterator it = Points.begin(); it != Points.end(); it++)
	{
		it->Printf();
	}*/
	   
	/*FSomDrawLibrary::DrawLine_BA(FPoint2D(10, 10), FPoint2D(120, 50));
	FSomDrawLibrary::DrawLine_BA(FPoint2D(10, 10), FPoint2D(50, 120));

	FSomDrawLibrary::DrawLine_BA(FPoint2D(10, -10), FPoint2D(120, -50));
	FSomDrawLibrary::DrawLine_BA(FPoint2D(10, -10), FPoint2D(50, -120));

	FSomDrawLibrary::DrawLine_BA(FPoint2D(-10, 10), FPoint2D(-120, 50));
	FSomDrawLibrary::DrawLine_BA(FPoint2D(-10, 10), FPoint2D(-50, 120));

	FSomDrawLibrary::DrawLine_BA(FPoint2D(-10, -10), FPoint2D(-120, -50));
	FSomDrawLibrary::DrawLine_BA(FPoint2D(-10, -10), FPoint2D(-50, -120));*/

/*
	FMatrix2D Rot45;
	Rot45._11 = 0;
	Rot45._21 = 1;
	Rot45._12 = -1;
	Rot45._22 = 0;
	
	FVector2D a = Rot45 * FVector2D(10, 10);
	FVector2D b = Rot45 * FVector2D(120, 50);
	FVector2D c = Rot45 * FVector2D(50, 120);
	
	FPoint2D Test1 = FPoint2D(a.X, a.Y);
	FPoint2D Test2 = FPoint2D(b.X, b.Y);
	FPoint2D Test3 = FPoint2D(c.X, c.Y);
	
	FSomDrawLibrary::DrawLine_BA(Test1, Test2);
	FSomDrawLibrary::DrawLine_BA(Test1, Test3);*/

#ifdef TextureTEST
#if TextureTEST
	// SomWorks :D // 텍스처 쿼드 테스트 1
	FVertex2D a(-100, -100);
	a.UV = FVector2D(0, 1);

	FVertex2D b(-50, 100);
	b.UV = FVector2D(0, 0);

	FVertex2D c(80, -50);
	c.UV = FVector2D(1, 0);

	FVertex2D d(80, -200);
	d.UV = FVector2D(1, 1);

	FTriangle2D MyTriangle(a, b, c, SomManager_Texture::GetInstance()->T_Test1, true);
	FTriangle2D MyTriangle2(a, d, c, SomManager_Texture::GetInstance()->T_Test1, true);

#else
	// SomWorks :D // 텍스처 쿼드 테스트 2
	FVertex2D a(-200, 200);
	a.UV = FVector2D(0, 0);

	FVertex2D b(200, 200);
	b.UV = FVector2D(1, 0);

	FVertex2D c(-200, -200);
	c.UV = FVector2D(0, 1);

	FVertex2D d(200, -200);
	d.UV = FVector2D(1, 1);

	FTriangle2D MyTriangle(a, b, c, SomManager_Texture::GetInstance()->T_Test1, true);
	FTriangle2D MyTriangle2(b, c, d, SomManager_Texture::GetInstance()->T_Test1, true);

#endif
#endif

	//FQuad2D Texting(a, b, c, d, SomManager_Texture::GetInstance()->T_Test1);
}

void SR_Sample::Terminate()
{
	// Points.clear();
}