// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

// SomWorks :D //

#pragma once

#include "Engine/Engine.h"

class SomFramework_DX11
{
public:
	SomFramework_DX11();
	~SomFramework_DX11();

	// SomWorks :D // DirectX 11 ∑ª¥ı∑Ø º¬æ˜
	static void Init(HWND hWnd);
	static void Update(float DeltaTime);
	static void Render();
	static void Release(HWND hWnd);

private:
	// SomWorks :D // ΩÃ±€≈œ ∞¥√º
	static SomFramework_DX11* Instance;

	D3D_DRIVER_TYPE g_driverType = D3D_DRIVER_TYPE_NULL;
	D3D_FEATURE_LEVEL g_featureLevel = D3D_FEATURE_LEVEL_11_0;
	ID3D11Device* g_pd3dDevice = NULL;
	ID3D11DeviceContext* g_pImmediateContext = NULL;
	IDXGISwapChain* g_pSwapChain = NULL;
	ID3D11RenderTargetView* g_pRenderTargetView = NULL;

protected:

public:

	// SomWorks :D // ΩÃ±€≈œ ¿ŒΩ∫≈œΩ∫ Getter
	static SomFramework_DX11* GetInstance() { return Instance; }
};