// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#include "SoftRenderer.h"

// SomWorks :D // 인터넷 레퍼런스
void Reference(Point2D v1, Point2D v2)
{
	int dx, dy;
	int p_value;
	int inc_minus;
	int inc_plus;
	int inc_value;
	int ndx;

	dx = abs(v2.x - v1.x);
	dy = abs(v2.y - v1.y);

	//변화폭을 따져 완만한 좌표를 기준으로 점을 찍는다.
	if (dy <= dx)
	{
		// y 보다 x 변화폭이 클 경우
		inc_minus = 2 * dy;
		inc_plus = 2 * (dy - dx);

		//선 x 점을 작은 수부터 그려나가기 위해.
		//Bresenham 공식은 다음점에 대한 위치를 잡는 것이기 때문에도.

		if (v2.x < v1.x)
		{
			ndx = v1.x;
			v1.x = v2.x;
			v2.x = ndx;

			ndx = v1.y;
			v1.y = v2.y;
			v2.y = ndx;
		}

		//x 값에 따른 y값 변화값 고르기
		if (v1.y < v2.y) {
			inc_value = 1;
		}
		else {
			inc_value = -1;
		}

		FSomDrawLibrary::DrawPixel(v1.x, v1.y);

		//처음 판단 값
		p_value = 2 * dy - dx;

		for (ndx = v1.x; ndx < v2.x; ++ndx)
		{
			if (0 > p_value) {
				p_value += inc_minus;
			}
			else {
				p_value += inc_plus;
				v1.y += inc_value;
			}
		
			FSomDrawLibrary::DrawPixel(ndx, v1.y);
		}
	}
	else
	{
		inc_minus = 2 * dx;
		inc_plus = 2 * (dx - dy);

		if (v2.y < v1.y) {
			ndx = v1.y;
			v1.y = v2.y;
			v2.y = ndx;

			ndx = v1.x;
			v1.x = v2.x;
			v2.x = ndx;
		}

		if (v1.x < v2.x) {
			inc_value = 1;
		}
		else {
			inc_value = -1;
		}
		FSomDrawLibrary::DrawPixel(v1.x, v1.y);

		p_value = 2 * dx - dy;

		for (ndx = v1.y; ndx < v2.y; ++ndx)
		{
			if (0 > p_value)
			{
				p_value += inc_minus;
			}
			else
			{
				p_value += inc_plus;
				v1.x += inc_value;
			}

			FSomDrawLibrary::DrawPixel(v1.x, ndx);
		}
	}
}

void UpdateFrame(void)
{
	// Draw
	SomSoftRenderObject::GetInstance()->SetColor(255, 255, 255); // SetColor(255, 0, 0);
	// FSomDrawLibrary::DrawPixel(0, 0);

	Point2D p1;
	p1.x = 0;
	p1.y = 0;

	Point2D p2;
	p2.x = -100;
	p2.y = 100;
	
	Reference(p1, p2); // FSomDrawLibrary::DrawLine(p1, p2);
		
	// =================================================================

	static bool a = false;

	if (!a)
	{
		FSomDrawLibrary::DrawLine(Point2D(-100, -100), Point2D(100, 100));		
		a = true;
	}
}