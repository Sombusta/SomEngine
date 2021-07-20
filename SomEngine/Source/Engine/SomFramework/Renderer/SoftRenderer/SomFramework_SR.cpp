// Copyright (c) 2014-2021 Sombusta, All Rights Reserved.

#include "SomFramework_SR.h"

SomFramework_SR* SomFramework_SR::Instance = nullptr;

SomFramework_SR::SomFramework_SR()
{
}

SomFramework_SR::~SomFramework_SR()
{
}

// SomWorks :D // GDI 오브젝트 생성
void SomFramework_SR::InitGDI(HWND hWnd, int width, int height)
{
	if (Instance == nullptr)
	{
		Instance = new SomFramework_SR;

		Instance->hScreenDC = GetDC(hWnd);
		Instance->hMemoryDC = CreateCompatibleDC(Instance->hScreenDC);

		Instance->Width = width;
		Instance->Height = height;

		BITMAPINFO bmi;
		memset(&bmi, 0, sizeof(BITMAPINFO));
		bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
		bmi.bmiHeader.biWidth = width;
		bmi.bmiHeader.biHeight = -height;
		bmi.bmiHeader.biPlanes = 1;
		bmi.bmiHeader.biBitCount = 32;
		bmi.bmiHeader.biCompression = BI_RGB;

		Instance->hDIBitmap = CreateDIBSection(Instance->hMemoryDC, &bmi, DIB_RGB_COLORS, (void**)&Instance->Bits, NULL, 0);
		Instance->hDefaultBitmap = (HBITMAP)SelectObject(Instance->hMemoryDC, Instance->hDIBitmap);

		SomManager_Main::CreateGameManager();
		SomManager_Texture::CreateTexManager();
	}
	else
	{
		// SomWorks :D // Already Create Instnace
	}
}

// SomWorks :D // 모든 업데이트는 이곳에서
void SomFramework_SR::UpdateGDI(float DeltaTime)
{
	// SomWorks :D // Buffer Clear
	Instance->BufferClear();

	// SomWorks :D // 소프트 렌더러 업데이트
	SomManager_Main::GetInstance()->Game_Update(DeltaTime);
	SomManager_Main::GetInstance()->Game_Render();

	// SomWorks :D // Buffer Swap 
	Instance->BufferSwap();
}

// SomWorks :D // 릴리즈
void SomFramework_SR::ReleaseGDI(HWND hWnd)
{
	if (Instance)
	{
		DeleteObject(Instance->hDefaultBitmap);
		DeleteObject(Instance->hDIBitmap);
		ReleaseDC(hWnd, Instance->hScreenDC);
		ReleaseDC(hWnd, Instance->hMemoryDC);

		SomManager_Main::TerminateGameManager();
		SomManager_Texture::TerminateTexManager();

		delete Instance;
		Instance = nullptr;
	}
}

// SomWorks :D // 버퍼 클리어
void SomFramework_SR::BufferClear()
{
	// SomWorks :D // 배경색
	//FColor BG_Color = FColor(32, 128, 255);
		
	FColor BG_Color = FLinearColor::Black.ToColor32();
	
	ULONG BG_Pixel = BG_Color.GetColor();

	ULONG* dest = (ULONG*)Bits;

	DWORD bytecount = Width * Height * sizeof(ULONG);
	bytecount /= 4;

	while (bytecount--)
	{
		*dest++ = BG_Pixel;
	}

	// SomWorks :D // 그리드 십자선 그리기
	// Instance->DrawGrid2D();
}

// SomWorks :D // 버퍼 스왑
void SomFramework_SR::BufferSwap()
{
	BitBlt(hScreenDC, 0, 0, Width, Height, hMemoryDC, 0, 0, SRCCOPY);
}

// SomWorks :D // 그리드 십자선 그리기
void SomFramework_SR::DrawGrid2D()
{
	FSomDrawLibrary::DrawLine_BA(FPoint2D(0 - Width / 2, 0), FPoint2D(0 + Width / 2, 0), FLinearColor::Red);
	FSomDrawLibrary::DrawLine_BA(FPoint2D(0, 0 + Height / 2), FPoint2D(0, 0 - Height / 2), FLinearColor::Green);

	// 그리드 색상
	FLinearColor GridColor(FLinearColor(0.8f, 0.8f, 0.8f));

	int Grid2DUnit = 10;

	// 가로 세로 라인 그리기
	/*FPoint2D screenHalfSize = FPoint2D(WIN_WIDTH / 2, WIN_HEIGHT / 2);

	for (int x = screenHalfSize.X; x <= _ScreenSize.X; x += Grid2DUnit)
	{
		_RSI->DrawFullVerticalLine(x, GridColor);
		if (x > screenHalfSize.X)
		{
			_RSI->DrawFullVerticalLine(2 * screenHalfSize.X - x, gridColor);
		}
	}

	for (int y = screenHalfSize.Y; y <= _ScreenSize.Y; y += Grid2DUnit)
	{
		_RSI->DrawFullHorizontalLine(y, GridColor);
		if (y > screenHalfSize.Y)
		{
			_RSI->DrawFullHorizontalLine(2 * screenHalfSize.Y - y, gridColor);
		}
	}

	// 월드 축 그리기
	_RSI->DrawFullHorizontalLine(screenHalfSize.Y, FLinearColor::Red);
	_RSI->DrawFullVerticalLine(screenHalfSize.X, FLinearColor::Green);*/
}