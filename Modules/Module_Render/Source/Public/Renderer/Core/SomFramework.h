// Copyright (c) 2014-2020 Sombusta, All Rights Reserved.

#pragma once

#include "Module_Render.h"

// SomWorks :D // 프레임워크 셋업 enum
enum class SomFrameworkSetup
{
	None = 0,
	SR,
	DX11,
	DX12
};

class SomFramework
{
public:
	SomFramework();
	SomFramework(UINT width, UINT height, wstring name);
	virtual ~SomFramework() {}

	virtual void OnInit(HWND hWnd) = 0;
	virtual void OnUpdate(float DeltaTime) = 0;
	virtual void OnRender() = 0;
	virtual void OnDestroy(HWND hWnd) = 0;

	// Samples override the event handlers to handle specific messages.
	virtual void OnKeyDown(UINT8 /*key*/) {}
	virtual void OnKeyUp(UINT8 /*key*/) {}

	void SetCustomWindowText(LPCWSTR text);
	void SetHwnd(HWND NewHwnd) { TargetHwnd = NewHwnd; }
	
protected:
	// Viewport dimensions.
	UINT Width;
	UINT Height;
	float AspectRatio;

	HWND TargetHwnd;

	SomFrameworkSetup CurrentFrameworkType;

private:
	// Window title.
	wstring TitleName;

public:
	// Accessors.
	UINT GetWidth() const { return Width; }
	UINT GetHeight() const { return Height; }
	const WCHAR* GetTitle() const { return TitleName.c_str(); }
	SomFrameworkSetup GetFrameworkType() const { return CurrentFrameworkType; }
};