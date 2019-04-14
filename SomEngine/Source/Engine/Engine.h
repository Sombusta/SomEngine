// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#pragma once

// #pragma comment(lib, "d3dcompiler.lib")
// #pragma comment(lib, "D3D12.lib")
// #pragma comment(lib, "dxgi.lib")

// SomWorks :D // C++ Header
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

// SomWorks :D // Windows SDK Header
#include <windows.h>
#include <wrl.h>
#include <shellapi.h>

using namespace Microsoft::WRL;
using Microsoft::WRL::ComPtr;

// SomWorks :D // DirectX 12 Library Header
#include <d3d12.h>
#include <dxgi1_4.h>
#include <D3Dcompiler.h>
#include <DirectXMath.h>

using namespace DirectX;

// SomWorks :D // DirectX 12 SDK Header
#include "Engine/DX12/d3dx12.h"
#include "Engine/DX12/DXSampleHelper.h"