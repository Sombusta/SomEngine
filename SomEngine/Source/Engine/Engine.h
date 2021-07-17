// Copyright (c) 2014-2021 Sombusta, All Rights Reserved.

//! $(ProjectDir)\Source

//! $(WindowsSDK_IncludePath)
//! $(WindowsSDK_LibraryPath_x86)

//! $(DXSDK_DIR)Include
//! $(DXSDK_DIR)Lib\x86

#pragma once

// SomWorks :D // 리소스 파일들
#include "Resource/targetver.h"
#include "Resource/Resource.h"

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

// SomWorks :D // WinAPI Windows Setup
#define WIN_WIDTH 1280
#define WIN_HEIGHT 720
#define WIN_TITLE L"SomEngine_Win32"

// SomWorks :D // Module
#include "Module_Math.h"
#include "Module_Render.h"

// SomWorks :D // 컨테이너
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