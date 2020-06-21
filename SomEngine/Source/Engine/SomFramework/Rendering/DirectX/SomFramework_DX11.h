// Copyright (c) 2014-2020 Sombusta, All Rights Reserved.

#pragma once

#include "Engine/SomFramework/Rendering/Core/SomFramework.h"
#include "RendererLibrary_DX11.h"

class SomFramework_DX11 : public SomFramework
{
public:
	SomFramework_DX11();
	SomFramework_DX11(UINT width, UINT height, wstring name);
	virtual ~SomFramework_DX11();

	// SomWorks :D // DirectX 11 ������ �¾�
	virtual void OnInit(HWND hWnd);
	virtual void OnUpdate(float DeltaTime);
	virtual void OnRender();
	virtual void OnDestroy(HWND hWnd);
	
	void GetProjectionMatrix(XMMATRIX&);
	void GetWorldMatrix(XMMATRIX&);
	void GetOrthoMatrix(XMMATRIX&);

private:
	D3D_DRIVER_TYPE g_driverType;
	D3D_FEATURE_LEVEL g_featureLevel;

	// Device // ���� ����̽�
	ID3D11Device* g_pd3dDevice;

	// Immediate Context // ����� ó���ϴ� ���ؽ�Ʈ
	ID3D11DeviceContext* g_pImmediateContext;

	// SwapChain // ����� ����ü��
	IDXGISwapChain* g_pSwapChain;

	// Render Target View 
	ID3D11RenderTargetView* g_pRenderTargetView;
	
	// Depth Stencil View
	ID3D11DepthStencilView* m_DepthStencilView;
	ID3D11DepthStencilState* m_DepthStencilState;

	// Resterizer
	ID3D11RasterizerState* m_RasterState;

	//----------------------------------------------

	ID3D11VertexShader* g_pVertexShader;
	ID3D11PixelShader* g_pPixelShader;
	ID3D11InputLayout* g_pVertexLayout;
	ID3D11Buffer* g_pVertexBuffer;

	//----------------------------------------------

	XMMATRIX m_projectionMatrix;
	XMMATRIX m_worldMatrix;
	XMMATRIX m_orthoMatrix;

	bool m_vsync_enabled;
	int m_videoCardMemory;
	char m_videoCardDescription[128];

protected:

public:

	ID3D11Device* GetDevice();
	ID3D11DeviceContext* GetDeviceContext();
};