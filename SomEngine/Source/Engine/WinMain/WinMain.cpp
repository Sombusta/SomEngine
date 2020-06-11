// Copyright (c) 2014-2020 Sombusta, All Rights Reserved.

#include "Win32Application.h"
#include "Engine/SomFramework/Rendering/Core/SomFramework.h"
#include "Engine/SomFramework/Rendering/SoftRenderer/SomFramework_SR.h"
#include "Engine/SomFramework/Rendering/DX11/SomFramework_DX11.h"

#ifdef _DEBUG // SomWorks :D // Debug Console
#pragma comment(linker, "/entry:WinMainCRTStartup")
#pragma comment(linker, "/subsystem:console")
#endif

// SomWorks :D // WINAPI or APIENTRY
_Use_decl_annotations_
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow)
{
	SomFramework_DX11 SomRenderer_DX11(1280, 720, L"D3D11 Hello Window");
	return Win32Application::Run(hInstance, nCmdShow, &SomRenderer_DX11);
}