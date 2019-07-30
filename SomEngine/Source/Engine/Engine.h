// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#pragma once

// SomWorks :D // WinAPI Windows Setup
#define SomWidth 1280
#define SomHeight 720
#define SomTitle L"SomEngine_Win32"

// SomWorks :D // Renderer Setup
#define bUseSoftRenderer true
#define bUseDX11 false
#define bUseDX12 false

// #pragma comment(lib, "d3dcompiler.lib")
// #pragma comment(lib, "D3D12.lib")
// #pragma comment(lib, "dxgi.lib")

#define WIN32_LEAN_AND_MEAN // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.

// SomWorks :D // Windows SDK Header
#include <windows.h>
#include <wrl.h>
#include <shellapi.h>

// SomWorks :D // C++ Header
#include <stdio.h>
#include <iostream>
#include <string>

// SomWorks :D // C Header, C 스타일 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

using namespace std;

// SomWorks :D // 리소스 파일들
#include "Resource/targetver.h"
#include "Resource/Resource.h"

// SomWorks :D // SomFramework Library
#include "SomLibraries/Math/SomMathLibrary.h"

#if bUseSoftRenderer
#include "Renderer/SoftRenderer/GDIHelper.h"
#include "Renderer/SoftRenderer/SoftRenderer.h"
#endif

#if bUseDX11
#endif

#if bUseDX12
// SomWorks :D // DirectX 12 Library Header
#include <d3d12.h>
#include <dxgi1_4.h>
#include <D3Dcompiler.h>
#include <DirectXMath.h>

using namespace DirectX;

// SomWorks :D // DirectX 12 SDK Header
#include "Engine/DX12/d3dx12.h"
#include "Engine/DX12/DXSampleHelper.h"
#endif