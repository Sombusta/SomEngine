// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#include "SomFramework_SR.h"

SomFramework_SR* SomFramework_SR::Instance = nullptr;

SomFramework_SR::SomFramework_SR()
{
}

SomFramework_SR::~SomFramework_SR()
{
}

// SomWorks :D // GDI ������Ʈ ����
void SomFramework_SR::InitGDI(HWND hWnd)
{
	if (Instance == nullptr)
	{
		Instance = new SomFramework_SR;

		Instance->hScreenDC = GetDC(hWnd);
		Instance->hMemoryDC = CreateCompatibleDC(Instance->hScreenDC);

		BITMAPINFO bmi;
		memset(&bmi, 0, sizeof(BITMAPINFO));
		bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
		bmi.bmiHeader.biWidth = SomWidth;
		bmi.bmiHeader.biHeight = -SomHeight;
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

// SomWorks :D // ��� ������Ʈ�� �̰�����
void SomFramework_SR::UpdateGDI(float DeltaTime)
{
	// SomWorks :D // Buffer Clear
	Instance->BufferClear();

	// SomWorks :D // ����Ʈ ������ ������Ʈ
	SomManager_Main::GetInstance()->Game_Update(DeltaTime);
	SomManager_Main::GetInstance()->Game_Render();

	// SomWorks :D // Buffer Swap 
	Instance->BufferSwap();
}

// SomWorks :D // ������
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

// SomWorks :D // ���� Ŭ����
void SomFramework_SR::BufferClear()
{
	// SomWorks :D // ����
	FLinearColor BG_Color = FLinearColor(32, 128, 255);
	ULONG BG_Pixel = BG_Color.GetColor();

	ULONG* dest = (ULONG*)Bits;

	DWORD bytecount = SomWidth * SomHeight * sizeof(ULONG);
	bytecount /= 4;

	while (bytecount--)
	{
		*dest++ = BG_Pixel;
	}

	// SomWorks :D // �׸��� ���ڼ� �׸���
	// Instance->DrawGridLine(true);
}

// SomWorks :D // ���� ����
void SomFramework_SR::BufferSwap()
{
	BitBlt(hScreenDC, 0, 0, SomWidth, SomHeight, hMemoryDC, 0, 0, SRCCOPY);
}

// SomWorks :D // �׸��� ���ڼ� �׸���
void SomFramework_SR::DrawGridLine(bool bActivate)
{
	if (bActivate)
	{
		FSomDrawLibrary::DrawLine_BresenhamAlgorithm(FPoint(0 - SomWidth / 2, 0), FPoint(0 + SomWidth / 2, 0));
		FSomDrawLibrary::DrawLine_BresenhamAlgorithm(FPoint(0, 0 + SomHeight / 2), FPoint(0, 0 - SomHeight / 2));
	}
}