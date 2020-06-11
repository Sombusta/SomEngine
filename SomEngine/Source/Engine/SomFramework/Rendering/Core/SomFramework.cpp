// Copyright (c) 2014-2020 Sombusta, All Rights Reserved.

#include "SomFramework.h"

SomFramework::SomFramework()
{
	Width = 1920;
	Height = 1080;
	TitleName = L"SomEngine_DX11";
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

	if (TargetHwnd != nullptr) SetWindowText(*TargetHwnd, windowText.c_str());
}