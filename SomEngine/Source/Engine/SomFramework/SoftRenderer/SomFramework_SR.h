// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

// SomWorks :D // GDI : Graphics Device Interface

#pragma once

#include "Engine/Engine.h"

class SomFramework_SR
{
public:
	SomFramework_SR();
	~SomFramework_SR();

	static void InitGDI(HWND hWnd);
	static void UpdateGDI();
	static void ReleaseGDI(HWND hWnd);

	void SetColor(BYTE r, BYTE g, BYTE b);
	void Clear();
	void BufferSwap();

private:
	static SomFramework_SR* Instance;

protected:

public:
	ULONG g_CurrentColor;
	BYTE* g_pBits;

	static SomFramework_SR* GetInstance() { return Instance; }
};