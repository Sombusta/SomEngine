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

	void SetBackgroundColor(FColor rgb);

	void Clear();

	void BufferSwap();

	void DrawGridLine(bool bActivate);

private:
	// SomWorks :D // ½Ì±ÛÅÏ °´Ã¼
	static SomFramework_SR* Instance;

	// SomWorks :D // ¹è°æ»ö
	ULONG BackgroundColor;

protected:

public:	
	BYTE* Bits;

	static SomFramework_SR* GetInstance() { return Instance; }
};