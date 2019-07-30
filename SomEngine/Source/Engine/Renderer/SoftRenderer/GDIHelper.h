// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

// SomWorks :D // GDI : Graphics Device Interface

#pragma once

#include "Engine/Engine.h"

class SomSoftRenderObject
{
public:
	SomSoftRenderObject();
	~SomSoftRenderObject();

	static void InitGDI(HWND hWnd);
	static void UpdateGDI();
	static void ReleaseGDI(HWND hWnd);

	void SetColor(BYTE r, BYTE g, BYTE b);
	void Clear();
	void BufferSwap();

private:
	static SomSoftRenderObject* Instance;

protected:

public:
	ULONG g_CurrentColor;
	BYTE* g_pBits;

	static SomSoftRenderObject* GetInstance() { return Instance; }
};