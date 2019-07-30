// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#include "GDIHelper.h"
#include "SoftRenderer.h"

// 변수
ULONG g_CurrentColor;
BYTE *g_pBits;

HDC	hScreenDC, hMemoryDC;
HBITMAP hDefaultBitmap, hDIBitmap;

void BufferSwap()
{
	BitBlt(hScreenDC, 0, 0, SomWidth, SomHeight, hMemoryDC, 0, 0, SRCCOPY);
}

// SomWorks :D // 글로벌 컬러 초기화
void SetColor(BYTE r, BYTE g, BYTE b)
{
	g_CurrentColor = RGB(b, g, r);
}

void Clear()
{
	ULONG* dest = (ULONG*)g_pBits;
	DWORD bytecount = SomWidth * SomHeight * sizeof(ULONG);
	ULONG value = g_CurrentColor;
	bytecount /= 4;
	while (bytecount--)
	{
		*dest++ = value;
	}
	return;
}

void InitGDI(HWND hWnd)
{
	hScreenDC = GetDC(hWnd);
	hMemoryDC = CreateCompatibleDC(hScreenDC);

	BITMAPINFO bmi;
	memset(&bmi, 0, sizeof(BITMAPINFO));
	bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	bmi.bmiHeader.biWidth = SomWidth;
	bmi.bmiHeader.biHeight = -SomHeight;
	bmi.bmiHeader.biPlanes = 1;
	bmi.bmiHeader.biBitCount = 32;
	bmi.bmiHeader.biCompression = BI_RGB;

	hDIBitmap = CreateDIBSection(hMemoryDC, &bmi, DIB_RGB_COLORS, (void**)&g_pBits, NULL, 0);
	hDefaultBitmap = (HBITMAP)SelectObject(hMemoryDC, hDIBitmap);
}

// SomWorks :D // 모든 업데이트는 이곳에서
void UpdateGDI()
{	// Buffer Clear
	SetColor(32, 128, 255); // SetColor(0, 0, 0);
	Clear();

	// SomWorks :D // 소프트 렌더러 업데이트
	UpdateFrame();

	// Buffer Swap 
	BufferSwap();
}

void ReleaseGDI(HWND hWnd)
{
	DeleteObject(hDefaultBitmap);
	DeleteObject(hDIBitmap);
	ReleaseDC(hWnd, hScreenDC);
	ReleaseDC(hWnd, hMemoryDC);
}
