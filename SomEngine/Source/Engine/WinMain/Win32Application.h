// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#pragma once

#include "Engine/Engine.h"

#define SomWidth 1280
#define SomHeight 720
#define SomTitle L"SomEngine"

extern int g_nClientWidth = SomWidth;
extern int g_nClientHeight = SomHeight;
extern bool g_bIsActive;

/*
class SomEngine
{
public:
	SomEngine(UINT width, UINT height, std::wstring name);
	virtual ~SomEngine();

	// virtual void OnInit() = 0;
	// virtual void OnUpdate() = 0;
	// virtual void OnRender() = 0;
	// virtual void OnDestroy() = 0;

	// Samples override the event handlers to handle specific messages.
	virtual void OnKeyDown(UINT8 / *key* /) {}
	virtual void OnKeyUp(UINT8 / *key* /) {}

private:
	// Root assets path.
	std::wstring m_assetsPath;

	// Window title.
	std::wstring m_title;

protected:
	void SetCustomWindowText(LPCWSTR text);

	// Viewport dimensions.
	UINT m_width;
	UINT m_height;
	float m_aspectRatio;

	// Adapter info.
	bool m_useWarpDevice;

public:
	// Accessors.
	UINT GetWidth() const { return m_width; }
	UINT GetHeight() const { return m_height; }
	const WCHAR* GetTitle() const { return m_title.c_str(); }
};
*/

class Win32Application
{
public:
	static int Run(HINSTANCE hInstance, int nCmdShow);

private:
	static HWND m_hwnd;
	static HINSTANCE m_hInstance;

protected:
	static LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

public:
	static HWND GetHwnd() { return m_hwnd; }
	static HINSTANCE GetHInstnace() { return m_hInstance; }
};