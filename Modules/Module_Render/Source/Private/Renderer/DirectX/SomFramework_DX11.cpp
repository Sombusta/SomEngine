// Copyright (c) 2014-2020 Sombusta, All Rights Reserved.

#include "pch.h"
#include "Renderer/DirectX/SomFramework_DX11.h"

SomFramework_DX11::SomFramework_DX11() : SomFramework()
{
	g_driverType = D3D_DRIVER_TYPE_NULL;
	g_featureLevel = D3D_FEATURE_LEVEL_11_0;

	g_pd3dDevice = nullptr;
	g_pImmediateContext = nullptr;
	g_pSwapChain = nullptr;
	g_pRenderTargetView = nullptr;

	m_DepthStencilView = nullptr;
	m_DepthStencilState = nullptr;
	m_RasterState = nullptr;

	g_pVertexShader = nullptr;
	g_pPixelShader = nullptr;
	g_pVertexLayout = nullptr;
	g_pVertexBuffer = nullptr;
	
	CurrentFrameworkType = SomFrameworkSetup::DX11;

	memset(m_videoCardDescription, 0, sizeof(m_videoCardDescription));
}

SomFramework_DX11::SomFramework_DX11(UINT width, UINT height, wstring name) : SomFramework(width, height, name)
{
	g_driverType = D3D_DRIVER_TYPE_NULL;
	g_featureLevel = D3D_FEATURE_LEVEL_11_0;

	g_pd3dDevice = nullptr;
	g_pImmediateContext = nullptr;
	g_pSwapChain = nullptr;
	g_pRenderTargetView = nullptr;

	m_DepthStencilView = nullptr;
	m_DepthStencilState = nullptr;
	m_RasterState = nullptr;

	g_pVertexShader = nullptr;
	g_pPixelShader = nullptr;
	g_pVertexLayout = nullptr;
	g_pVertexBuffer = nullptr;

	CurrentFrameworkType = SomFrameworkSetup::DX11;

	memset(m_videoCardDescription, 0, sizeof(m_videoCardDescription));
}

SomFramework_DX11::~SomFramework_DX11()
{
}

// SomWorks :D // GDI ������Ʈ ����
void SomFramework_DX11::OnInit(HWND hWnd)
{
	SetHwnd(hWnd);

	HRESULT hr = S_OK;

	RECT rc;
	GetClientRect(hWnd, &rc);
	UINT width = rc.right - rc.left;
	UINT height = rc.bottom - rc.top;

	// Release Flag
	UINT createDeviceFlags = 0;

#ifdef _DEBUG
	createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif

	// ����̹� Ÿ�� ������
	// DX11�� �������� �ʴ� �ϵ������� ���۷��� ����
	// �۵��ϰ� �ϱ� ���ؼ� �迭�� �����Ͽ�,
	// �ϳ��� �����غ��� �����ϴ� ����̹��� ����Ѵ�.
	D3D_DRIVER_TYPE driverTypes[] =
	{
		D3D_DRIVER_TYPE_HARDWARE,
		D3D_DRIVER_TYPE_WARP,
		D3D_DRIVER_TYPE_REFERENCE,
	};

	// ����̹� Ÿ�� ����
	UINT numDriverTypes = ARRAYSIZE(driverTypes);

	// DX ���� ��ó
	D3D_FEATURE_LEVEL featureLevels[] =
	{
		D3D_FEATURE_LEVEL_11_0,
		D3D_FEATURE_LEVEL_10_1,
		D3D_FEATURE_LEVEL_10_0,
	};

	// ��ó ����
	UINT numFeatureLevels = ARRAYSIZE(featureLevels);

	// ����ü���� �����ϱ� ���� ����
	DXGI_SWAP_CHAIN_DESC sd;
	ZeroMemory(&sd, sizeof(sd)); // �ʱ�ȭ
	// memset(&sd, 0, sizeof(sd));

	sd.BufferCount = 1;									// ����� ī��Ʈ
	sd.BufferDesc.Width = width;						// ����� �ػ�
	sd.BufferDesc.Height = height;						// ����� �ػ�
	sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;	// ����� �÷� ����, r8g8b8a8 32��Ʈ �÷�����
	sd.BufferDesc.RefreshRate.Numerator = 60;			// ȭ�� �ֻ���
	sd.BufferDesc.RefreshRate.Denominator = 1;
	sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;	// ���� ��� �뵵 ����
	sd.OutputWindow = hWnd;								// ���۸� ����� ������ �ڵ�
	sd.SampleDesc.Count = 1;							// ��Ƽ���ø� ��� ����
	sd.SampleDesc.Quality = 0;							// 0 ���� �����ϸ� ��Ƽ���ø� ����� ��������ʴ´ٴ� �ǹ�
	sd.Windowed = TRUE;									// Ǯ��ũ�� ����

	// ��ġ �� ���� ü�� ����
	for (UINT driverTypeIndex = 0; driverTypeIndex < numDriverTypes; driverTypeIndex++)
	{
		g_driverType = driverTypes[driverTypeIndex];

		hr = D3D11CreateDeviceAndSwapChain(nullptr,
			g_driverType,				// ����̹� Ÿ��
			NULL,
			createDeviceFlags,			// ����̽� �÷���
			featureLevels,				// ��ó ���� �迭
			numFeatureLevels,			// ��ó ���� ī��Ʈ
			D3D11_SDK_VERSION,			// SDK ����
			&sd,						// ����ü�� ���� ����ü
			&g_pSwapChain,				// ������ ����ü�� ��ü
			&g_pd3dDevice,				// ������ ����̽� ��ü
			&g_featureLevel,			// ������ ��ó ���� ����
			&g_pImmediateContext);		// ������ ����̽� ���ؽ�Ʈ ��ü

		if (SUCCEEDED(hr)) break;
	}

	// Create a render target view, ����۸� ����ü�ο��� ������
	ID3D11Texture2D* pBackBuffer = nullptr;
	hr = g_pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);

	// ����ۿ� ���� �������� ���� Ÿ�� �並 �����ؼ� ���ε�
	hr = g_pd3dDevice->CreateRenderTargetView(pBackBuffer, NULL, &g_pRenderTargetView);

	// ���� Ÿ�� �並 ������ ���Ŀ��� ���� ������ �����ʰ� ���� Ÿ�� �並 ����ؼ� �����Ѵ�.
	pBackBuffer->Release();

	// OM = Ouput Merge
	// ���� Ÿ�� ��� �ִ� 8������ ���� ����
	g_pImmediateContext->OMSetRenderTargets(1, &g_pRenderTargetView, nullptr); // ���� ���� ���ٽ� ��� ���� ���� ����

	// Setup the viewport
	D3D11_VIEWPORT vp;
	vp.Width = (FLOAT)width;
	vp.Height = (FLOAT)height;
	vp.MinDepth = 0.0f;
	vp.MaxDepth = 1.0f;
	vp.TopLeftX = 0;
	vp.TopLeftY = 0;

	// RS = �����Ͷ����� ��������
	g_pImmediateContext->RSSetViewports(1, &vp);
}

// SomWorks :D // ��� ������Ʈ�� �̰�����
void SomFramework_DX11::OnUpdate(float DeltaTime)
{
	// SomWorks :D // DirectX 11 ������ ������Ʈ

}

void SomFramework_DX11::OnRender()
{
	// Just clear the backbuffer
	float ClearColor[4] = { 0.0f, 0.125f, 0.3f, 1.0f }; // Red, Green, Blue, Alpha
	g_pImmediateContext->ClearRenderTargetView(g_pRenderTargetView, ClearColor);
	g_pSwapChain->Present(0, 0);
}

// SomWorks :D // ������
void SomFramework_DX11::OnDestroy(HWND hWnd)
{
	if (g_pImmediateContext) g_pImmediateContext->ClearState();
	if (g_pRenderTargetView) g_pRenderTargetView->Release();
	if (g_pSwapChain) g_pSwapChain->Release();
	if (g_pImmediateContext) g_pImmediateContext->Release();
	if (g_pd3dDevice) g_pd3dDevice->Release();
}