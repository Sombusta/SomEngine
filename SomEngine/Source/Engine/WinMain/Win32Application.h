// Copyright (c) 2014-2020 Sombusta, All Rights Reserved.

#pragma once

#include "Engine/Engine.h"

class Win32Application
{
public:
	// SomWorks :D // WinAPI Setup
	static int Run(HINSTANCE hInstance, int nCmdShow, class SomFramework* RenderFramework); // SomFrameworkSetup RenderType

	// SomWorks :D // �ʱ�ȭ ���� ����
	static bool bIsActive;
	
private:
	static HWND m_hwnd;
	static HINSTANCE m_hInstance;
	static class SomFramework* TargetFramework;
	
	static bool bUseSoftRenderer;

protected:	
	static LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

public:
	static HWND GetHwnd() { return m_hwnd; }
	static HINSTANCE GetHInstnace() { return m_hInstance; }
};