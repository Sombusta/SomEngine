// Copyright (c) 2014-2020 Sombusta, All Rights Reserved.

// SomWorks :D //

#pragma once

#include "Engine/SomFramework/Rendering/Core/SomFramework.h"

class SomFramework_DX11 : public SomFramework
{
public:
	SomFramework_DX11();
	SomFramework_DX11(UINT width, UINT height, wstring name);
	virtual ~SomFramework_DX11();

	// SomWorks :D // DirectX 11 ·»´õ·¯ ¼Â¾÷
	virtual void Init(HWND hWnd);
	virtual void Update(float DeltaTime);
	virtual void Render();
	virtual void Release(HWND hWnd);

private:
	D3D_DRIVER_TYPE g_driverType;
	D3D_FEATURE_LEVEL g_featureLevel;
	ID3D11Device* g_pd3dDevice;
	ID3D11DeviceContext* g_pImmediateContext;
	IDXGISwapChain* g_pSwapChain;
	ID3D11RenderTargetView* g_pRenderTargetView;

protected:

public:
};