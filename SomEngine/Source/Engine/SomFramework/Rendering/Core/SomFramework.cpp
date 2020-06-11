// Copyright (c) 2014-2020 Sombusta, All Rights Reserved.

#include "SomFramework.h"

SomFramework::SomFramework()
{
	Width = 1280;
	Height = 720;
	TitleName = L"SomEngine_Win32";
	AspectRatio = static_cast<float>(Width) / static_cast<float>(Height);
	TargetHwnd = nullptr;
}

SomFramework::SomFramework(UINT width, UINT height, wstring name) :
	Width(width),
	Height(height),
	TitleName(name)
{
	AspectRatio = static_cast<float>(width) / static_cast<float>(height);
	TargetHwnd = nullptr;
}

void SomFramework::SetCustomWindowText(LPCWSTR text)
{
	std::wstring windowText = TitleName + L": " + text;

	if (TargetHwnd != nullptr) SetWindowText(TargetHwnd, windowText.c_str());
}