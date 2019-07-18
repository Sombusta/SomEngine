// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#pragma once

#include "Engine/Engine.h"

class Win32Application
{
public:
	// SomWorks :D // WinAPI Setup
	static int Run(HINSTANCE hInstance, int nCmdShow);

	// SomWorks :D // 초기화 성공 여부
	static bool bIsActive;

private:
	static HWND m_hwnd;
	static HINSTANCE m_hInstance;

protected:
	static LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

public:
	static HWND GetHwnd() { return m_hwnd; }
	static HINSTANCE GetHInstnace() { return m_hInstance; }
};