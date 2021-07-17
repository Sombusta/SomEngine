﻿// Copyright (c) 2014-2021 Sombusta, All Rights Reserved.

//! $(ProjectDir)\Source

//! $(WindowsSDK_IncludePath)
//! $(WindowsSDK_LibraryPath_x86)

//! $(DXSDK_DIR)Include
//! $(DXSDK_DIR)Lib\x86

#pragma once

// Somworks :D // Winmm Library
#pragma  comment(lib, "winmm.lib")

// SomWorks :D // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다
// #define WIN32_LEAN_AND_MEAN // Time 관련 함수를 쓰기 위해서는 Define하면 안됩니다.

// SomWorks :D // Windows SDK Header
#include <windows.h>
#include <wrl.h>
#include <shellapi.h>

// SomWorks :D // C++ Header
#include <stdio.h>
#include <iostream>

// SomWorks :D // C Header, C 스타일 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

// SomWorks :D // Using STL
#include <string>
#include <vector>
#include <list>
#include <map>
#include <algorithm>

using namespace std;
using std::vector;
using std::list;

typedef unsigned char		BYTE;		// 부호 없는 8비트
typedef unsigned int		UINT32;		// 부호 없는 32비트
typedef unsigned long long	UINT64;		// 부호 없는 64비트.
typedef signed long long	INT64;	// 부호 있는 64비트.

#if defined(PLATFORM_WINDOWS)
#define FORCEINLINE __forceinline
#endif

#if !defined(FORCEINLINE)
#define FORCEINLINE inline
#endif

// SomWorks :D // Som Framework Setup
#include "Renderer/Core/SomFramework.h"

// SomWorks :D // Rendering Framework Setup
#define bUseDX12 false

#if bUseDX12
// SomWorks :D // DirectX 12 Library Header

// #pragma comment(lib, "d3dcompiler.lib")
// #pragma comment(lib, "D3D12.lib")
// #pragma comment(lib, "dxgi.lib")

#include <d3d12.h>
#include <dxgi1_4.h>
#include <D3Dcompiler.h>
#include <DirectXMath.h>

using namespace DirectX;

// SomWorks :D // DirectX 12 SDK Header
#include "Engine/DX12/d3dx12.h"
#include "Engine/DX12/DXSampleHelper.h"

// #include "SomFramework/Rendering/DX12/SomFramework_DX12.h"
#endif