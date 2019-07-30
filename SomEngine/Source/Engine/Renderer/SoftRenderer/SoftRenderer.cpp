
#include "SoftRenderer.h"

bool IsInRange(int x, int y);
void PutPixel(int x, int y);

bool IsInRange(int x, int y)
{
	return (abs(x) < (SomWidth / 2)) && (abs(y) < (SomHeight / 2));
}

void PutPixel(int x, int y)
{
	if (!IsInRange(x, y)) return;

	ULONG* dest = (ULONG*)g_pBits;
	DWORD offset = SomWidth * SomHeight / 2 + SomWidth / 2 + x + SomWidth * -y; // SomWidth * x + SomHeight * y;
	*(dest + offset) = g_CurrentColor;
}

// SomWorks :D // 직선의 방정식만 가지고 제작된 선 긋기 알고리즘
// y = (x2 - x1)/(y2 - y1) * (x - x1) + y1
void DrawLine(Vector2D v1, Vector2D v2)
{
	int ResultY = 0;
	
	// SomWorks :D // i는 X값 ResultY 는 Y값
	for (int i = v1.x; i < v2.x; i++)
	{
		ResultY = static_cast<int>(((v2.y - v1.y) / (v2.x - v1.x)) * (i - v1.x) + v1.y);
		PutPixel(i, ResultY);
		// cout << Result << endl;
	}
}

// SomWorks :D // 브레젠험 직선 알고리즘
// -W( y - yl ) + H ( x - xl ) < 0
void CalcBresenhamAlgorithm(Vector2D v1, Vector2D v2)
{
	int dx, dy = 0;

	dx = abs(v2.x - v1.x);
	dy = abs(v2.y - v1.y);

	if (dy <= dx)
	{
		
	}
	else
	{

	}
}

void CalcLocation(int a, int b)
{

}

// SomWorks :D // 인터넷 레퍼런스
void Reference(Vector2D v1, Vector2D v2)
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

		PutPixel(v1.x, v1.y);

		//처음 판단 값
		p_value = 2 * dy - dx;

		for (ndx = v1.x; ndx < v2.x; ++ndx) {
			if (0 > p_value) {
				p_value += inc_minus;
			}
			else {
				p_value += inc_plus;
				v1.y += inc_value;
			}

			PutPixel(ndx, v1.y);
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
		PutPixel(v1.x, v1.y);

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

			PutPixel(v1.x, ndx);
		}
	}
}

void UpdateFrame(void)
{
	// Buffer Clear
	SetColor(32, 128, 255); // SetColor(0, 0, 0);
	Clear();

	// Draw
	SetColor(255, 255, 255); // SetColor(255, 0, 0);
	// PutPixel(0, 0);

	//CalcBresenhamAlgorithm(Vector2D(-100, -100), Vector2D(100, 100));
	
	DrawLine(Vector2D(-100, -100), Vector2D(100, 100));
	
	static bool a = false;	

	if (!a)
	{
		DrawLine(Vector2D(-100, -100), Vector2D(100, 100));
		a = true;
	}

	// Buffer Swap 
	BufferSwap();
}