// Copyright (c) 2014-2021 Sombusta, All Rights Reserved.

//! $(ProjectDir)\Source

//! $(WindowsSDK_IncludePath)
//! $(WindowsSDK_LibraryPath_x86)

//! $(DXSDK_DIR)Include
//! $(DXSDK_DIR)Lib\x86

#pragma once

// SomWorks :D // ���ҽ� ���ϵ�
#include "Resource/targetver.h"
#include "Resource/Resource.h"

// Somworks :D // Winmm Library
#pragma  comment(lib, "winmm.lib")

// SomWorks :D // ���� ������ �ʴ� ������ Windows ������� �����մϴ�
// #define WIN32_LEAN_AND_MEAN // Time ���� �Լ��� ���� ���ؼ��� Define�ϸ� �ȵ˴ϴ�.

// SomWorks :D // Windows SDK Header
#include <windows.h>
#include <wrl.h>
#include <shellapi.h>

// SomWorks :D // C++ Header
#include <stdio.h>
#include <iostream>

// SomWorks :D // C Header, C ��Ÿ�� ��Ÿ�� ��� �����Դϴ�.
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

// SomWorks :D // WinAPI Windows Setup
#define WIN_WIDTH 1280
#define WIN_HEIGHT 720
#define WIN_TITLE L"SomEngine_Win32"

// SomWorks :D // Math
#include "Module_Math.h"

// SomWorks :D // �����̳�
#include "SomFramework/Containers/Render/Texture/Texture2D.h"
#include "SomFramework/Containers/Render/Mesh/Triangle2D.h"
#include "SomFramework/Containers/Render/Mesh/Quad2D.h"

// SomWorks :D // SomFramework Library
#include "SomFramework/Libraries/SomMathLibrary.h"
#include "SomFramework/Libraries/SomDrawLibrary.h"

// SomWorks :D // SomInterface Library
#include "SomFramework/Libraries/Interface/SomInterface_Actor.h"

// SomWorks :D // SomFramework GamePlay
#include "SomFramework/GameObject/Object/GameObject.h"
#include "SomFramework/Managers/SomManager_Input.h"
#include "SomFramework/Managers/SomManager_Main.h"
#include "SomFramework/Managers/SomManager_Texture.h"

#include "SomFramework/Renderer/SoftRenderer/SomFramework_SR.h"

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

typedef unsigned char		BYTE;		// ��ȣ ���� 8��Ʈ
typedef unsigned int		UINT32;		// ��ȣ ���� 32��Ʈ
typedef unsigned long long	UINT64;		// ��ȣ ���� 64��Ʈ.
typedef signed long long	INT64;		// ��ȣ �ִ� 64��Ʈ.