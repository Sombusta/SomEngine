// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#pragma once

// SomWorks :D // 리소스 파일들
#include "Resource/targetver.h"
#include "Resource/Resource.h"

// SomWorks :D // WinAPI Windows Setup
#define SomWidth 1280
#define SomHeight 720
#define SomTitle L"SomEngine_Win32"

// SomWorks :D // Rendering Framework Setup
#define bUseSR true
#define bUseDX11 false
#define bUseDX12 false

// SomWorks :D // 프레임워크 셋업 enum
enum SomFrameworkSetup
{
	None,
	SR,
	DX11,
	DX12
};

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
#include <algorithm>

using namespace std;
using std::vector;
using std::list;

// SomWorks :D // 컨테이너
#include "SomFramework/Libraries/Container/Vector/Point.h"
#include "SomFramework/Libraries/Container/Vector/Vector2D.h"
#include "SomFramework/Libraries/Container/Vector/Vector.h"
#include "SomFramework/Libraries/Container/Color/Color.h"
#include "SomFramework/Libraries/Container/Mesh/Triangle/Triangle2D.h"

// SomWorks :D // SomFramework Library
#include "SomFramework/Libraries/Math/SomMathLibrary.h"
#include "SomFramework/Libraries/Draw/SomDrawLibrary.h"

// SomWorks :D // SomInterface Library
#include "SomFramework/Libraries/Interface/SomInterface_Actor.h"

// SomWorks :D // SomFramework GamePlay
#include "SomFramework/Game/Object/SomObject.h"
#include "Main/Core/SomManager_Main.h"

#if bUseSR
#include "SomFramework/Rendering/SoftRenderer/SomFramework_SR.h"
#endif

#if bUseDX11
// #include "SomFramework/Rendering/DX11/SomFramework_DX11.h"
#endif

#if bUseDX12
// SomWorks :D // DirectX 12 Library Header

// #pragma comment(lib, "d3dcompiler.lib")
// #pragma comment(lib, "D3D12.lib")
// #pragma comment(lib, "dxgi.lib")

// #include "SomFramework/Rendering/DX12/SomFramework_DX12.h"
#include <d3d12.h>
#include <dxgi1_4.h>
#include <D3Dcompiler.h>
#include <DirectXMath.h>

using namespace DirectX;

// SomWorks :D // DirectX 12 SDK Header
#include "Engine/DX12/d3dx12.h"
#include "Engine/DX12/DXSampleHelper.h"
#endif