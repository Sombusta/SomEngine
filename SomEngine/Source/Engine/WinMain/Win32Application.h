// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#pragma once

#include "Engine/Engine.h"

class Win32Application
{
public:
	static int Run(class SomRender_DX12* pSample, HINSTANCE hInstance, int nCmdShow);
	static HWND GetHwnd() { return m_hwnd; }
	static void SetHWND(HWND hWnd) { m_hwnd = hWnd; };

private:
	static HWND m_hwnd;

protected:
	static LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

public:
};

/*
class SomEngine
{
public:
	SomEngine();
	~SomEngine();

};*/