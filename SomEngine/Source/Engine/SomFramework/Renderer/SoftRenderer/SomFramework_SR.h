// Copyright (c) 2014-2021 Sombusta, All Rights Reserved.

// SomWorks :D // GDI : Graphics Device Interface

#pragma once

#include "Engine/Engine.h"

class SomFramework_SR
{
public:
	SomFramework_SR();
	~SomFramework_SR();

	// SomWorks :D // ����Ʈ ������ �¾�
	static void InitGDI(HWND hWnd, int width, int height);
	static void UpdateGDI(float DeltaTime);
	static void ReleaseGDI(HWND hWnd);

	void BufferClear();
	void BufferSwap();

	// SomWorks :D // ����� �׸���
	void DrawGrid2D();
	
private:
	// SomWorks :D // �̱��� ��ü
	static SomFramework_SR* Instance;
	
	int Width;
	int Height;

protected:

public:	
	HDC	hScreenDC, hMemoryDC;

	HBITMAP hDefaultBitmap, hDIBitmap;

	BYTE* Bits;
	   
	// SomWorks :D // �̱��� �ν��Ͻ� Getter
	static SomFramework_SR* GetInstance() { return Instance; }
};