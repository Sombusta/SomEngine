// Copyright (c) 2014-2020 Sombusta, All Rights Reserved.

#pragma once

#include "Engine/SomFramework/Rendering/Core/SomFramework.h"

class SomFramework_DX11 : public SomFramework
{
public:
	SomFramework_DX11();
	SomFramework_DX11(UINT width, UINT height, wstring name);
	virtual ~SomFramework_DX11();

	// SomWorks :D // DirectX 11 ·»´õ·¯ ¼Â¾÷
	virtual void OnInit(HWND hWnd);
	virtual void OnUpdate(float DeltaTime);
	virtual void OnRender();
	virtual void OnDestroy(HWND hWnd);

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