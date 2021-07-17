// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

// SomWorks :D // GDI : Graphics Device Interface

#pragma once

#include "Engine/Engine.h"

class SomFramework_SR
{
public:
	SomFramework_SR() = default;
	~SomFramework_SR();

	// SomWorks :D // ����Ʈ ������ �¾�
	static void InitGDI(HWND hWnd);
	static void UpdateGDI(float DeltaTime);
	static void ReleaseGDI(HWND hWnd);

	void BufferClear();
	void BufferSwap();

	// SomWorks :D // ����� �׸���
	void DrawGrid2D();
	
private:
	// SomWorks :D // �̱��� ��ü
	static SomFramework_SR* Instance;

protected:

public:	
	HDC	hScreenDC, hMemoryDC;

	HBITMAP hDefaultBitmap, hDIBitmap;

	BYTE* Bits;
	   
	// SomWorks :D // �̱��� �ν��Ͻ� Getter
	static SomFramework_SR* GetInstance() { return Instance; }
};