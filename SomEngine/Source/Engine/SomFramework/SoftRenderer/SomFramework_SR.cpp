// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#include "SomFramework_SR.h"
#include "SoftRenderer.h"

HDC	hScreenDC, hMemoryDC;
HBITMAP hDefaultBitmap, hDIBitmap;

SomFramework_SR* SomFramework_SR::Instance = nullptr;

SomFramework_SR::SomFramework_SR()
{
}

SomFramework_SR::~SomFramework_SR()
{
}

// SomWorks :D // GDI 오브젝트 생성
void SomFramework_SR::InitGDI(HWND hWnd)
{
	if (Instance == nullptr)
	{
		Instance = new SomFramework_SR;

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

		hDIBitmap = CreateDIBSection(hMemoryDC, &bmi, DIB_RGB_COLORS, (void**)&Instance->Bits, NULL, 0);
		hDefaultBitmap = (HBITMAP)SelectObject(hMemoryDC, hDIBitmap);
	}
	else
	{
		// SomWorks :D // Already Create Instnace
	}
}

// SomWorks :D // 모든 업데이트는 이곳에서
void SomFramework_SR::UpdateGDI()
{
	// SomWorks :D // Buffer Clear
	Instance->SetBackgroundColor(FColor(32, 128, 255)); // SetBackgroundColor(0, 0, 0);
	Instance->Clear();

	// SomWorks :D // 그리드 십자선 그리기
	// Instance->DrawGridLine(true);

	// SomWorks :D // 소프트 렌더러 업데이트
	UpdateFrame();

	// SomWorks :D // Buffer Swap 
	Instance->BufferSwap();
}

// SomWorks :D // 릴리즈
void SomFramework_SR::ReleaseGDI(HWND hWnd)
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
void SomFramework_SR::SetBackgroundColor(FColor rgb)
{
	BackgroundColor = RGB(rgb.b, rgb.g, rgb.r);
}

void SomFramework_SR::Clear()
{
	ULONG* dest = (ULONG*)Bits;
	DWORD bytecount = SomWidth * SomHeight * sizeof(ULONG);
	ULONG value = BackgroundColor;
	bytecount /= 4;

	while (bytecount--)
	{
		*dest++ = value;
	}
	return;
}

// SomWorks :D // 버퍼 스왑
void SomFramework_SR::BufferSwap()
{
	BitBlt(hScreenDC, 0, 0, SomWidth, SomHeight, hMemoryDC, 0, 0, SRCCOPY);
}

// SomWorks :D // 그리드 십자선 그리기
void SomFramework_SR::DrawGridLine(bool bActivate)
{
	if (bActivate)
	{
		FSomDrawLibrary::DrawLine_BresenhamAlgorithm(Point2D(0 - SomWidth / 2, 0), Point2D(0 + SomWidth / 2, 0));
		FSomDrawLibrary::DrawLine_BresenhamAlgorithm(Point2D(0, 0 + SomHeight / 2), Point2D(0, 0 - SomHeight / 2));
	}
}