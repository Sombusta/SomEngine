// Copyright (c) 2014-2021 Sombusta, All Rights Reserved.

#include "Win32Application.h"
#include "Engine/SomFramework/Renderer/DirectX/SomFramework_DX11.h"
#include "Engine/SomFramework/Renderer/DirectX/SomFramework_DX12.h"

#ifdef _DEBUG // SomWorks :D // Debug Console
#pragma comment(linker, "/entry:WinMainCRTStartup")
#pragma comment(linker, "/subsystem:console")
#endif

// SomWorks :D // WINAPI or APIENTRY
_Use_decl_annotations_
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow)
{
	// SomFramework_DX11 SomRenderer_DX11(1280, 720, L"SomEngine_DX11");
	// SomFramework_DX12 SomRenderer_DX12(1280, 720, L"SomEngine_DX12");

	return Win32Application::Run(hInstance, nCmdShow, nullptr); // nullptr : Use SoftRenderer or &SomRenderer_DX11 : Use Dx11
}