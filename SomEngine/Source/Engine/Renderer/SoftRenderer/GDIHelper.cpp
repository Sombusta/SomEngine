// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#include "GDIHelper.h"
#include "SoftRenderer.h"

HDC	hScreenDC, hMemoryDC;
HBITMAP hDefaultBitmap, hDIBitmap;

SomSoftRenderObject* SomSoftRenderObject::Instance = nullptr;

SomSoftRenderObject::SomSoftRenderObject()
{
}

SomSoftRenderObject::~SomSoftRenderObject()
{
}

// SomWorks :D // GDI 오브젝트 생성
void SomSoftRenderObject::InitGDI(HWND hWnd)
{
	if (Instance == nullptr)
	{
		Instance = new SomSoftRenderObject;

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

		hDIBitmap = CreateDIBSection(hMemoryDC, &bmi, DIB_RGB_COLORS, (void**)&Instance->g_pBits, NULL, 0);
		hDefaultBitmap = (HBITMAP)SelectObject(hMemoryDC, hDIBitmap);
	}
	else
	{
		// SomWorks :D // Already Create Instnace
	}
}

// SomWorks :D // 모든 업데이트는 이곳에서
void SomSoftRenderObject::UpdateGDI()
{
	// Buffer Clear
	Instance->SetColor(32, 128, 255); // SetColor(0, 0, 0);
	Instance->Clear();

	// SomWorks :D // 소프트 렌더러 업데이트
	UpdateFrame();

	// Buffer Swap 
	Instance->BufferSwap();
}

// SomWorks :D // 릴리즈
void SomSoftRenderObject::ReleaseGDI(HWND hWnd)
{
	if (Instance)
	{
		DeleteObject(hDefaultBitmap);
		DeleteObject(hDIBitmap);
		ReleaseDC(hWnd, hScreenDC);
		ReleaseDC(hWnd, hMemoryDC);
		delete Instance;
		Instance = nullptr;
	}
}

// SomWorks :D // 글로벌 컬러 초기화
void SomSoftRenderObject::SetColor(BYTE r, BYTE g, BYTE b)
{
	g_CurrentColor = RGB(b, g, r);
}

void SomSoftRenderObject::Clear()
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

void SomSoftRenderObject::BufferSwap()
{
	BitBlt(hScreenDC, 0, 0, SomWidth, SomHeight, hMemoryDC, 0, 0, SRCCOPY);
}