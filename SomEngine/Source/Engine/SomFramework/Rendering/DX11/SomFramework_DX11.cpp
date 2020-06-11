// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#include "SomFramework_DX11.h"

SomFramework_DX11* SomFramework_DX11::Instance = nullptr;

SomFramework_DX11::SomFramework_DX11()
{
	g_driverType = D3D_DRIVER_TYPE_NULL;
	g_featureLevel = D3D_FEATURE_LEVEL_11_0;
	g_pd3dDevice = nullptr;
	g_pImmediateContext = nullptr;
	g_pSwapChain = nullptr;
	g_pRenderTargetView = nullptr;
}

SomFramework_DX11::~SomFramework_DX11()
{
}

// SomWorks :D // GDI 오브젝트 생성
void SomFramework_DX11::Init(HWND hWnd)
{
	if (Instance == nullptr)
	{
		Instance = new SomFramework_DX11;

		HRESULT hr = S_OK;

		RECT rc;
		GetClientRect(hWnd, &rc);
		UINT width = rc.right - rc.left;
		UINT height = rc.bottom - rc.top;

		UINT createDeviceFlags = 0;
#ifdef _DEBUG
		createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif

		D3D_DRIVER_TYPE driverTypes[] =
		{
			D3D_DRIVER_TYPE_HARDWARE,
			D3D_DRIVER_TYPE_WARP,
			D3D_DRIVER_TYPE_REFERENCE,
		};
		UINT numDriverTypes = ARRAYSIZE(driverTypes);

		D3D_FEATURE_LEVEL featureLevels[] =
		{
			D3D_FEATURE_LEVEL_11_0,
			D3D_FEATURE_LEVEL_10_1,
			D3D_FEATURE_LEVEL_10_0,
		};
		UINT numFeatureLevels = ARRAYSIZE(featureLevels);

		DXGI_SWAP_CHAIN_DESC sd;
		ZeroMemory(&sd, sizeof(sd));
		sd.BufferCount = 1;
		sd.BufferDesc.Width = width;
		sd.BufferDesc.Height = height;
		sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
		sd.BufferDesc.RefreshRate.Numerator = 60;
		sd.BufferDesc.RefreshRate.Denominator = 1;
		sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
		sd.OutputWindow = hWnd;
		sd.SampleDesc.Count = 1;
		sd.SampleDesc.Quality = 0;
		sd.Windowed = TRUE;

		for (UINT driverTypeIndex = 0; driverTypeIndex < numDriverTypes; driverTypeIndex++)
		{
			Instance->g_driverType = driverTypes[driverTypeIndex];
			
			hr = D3D11CreateDeviceAndSwapChain(NULL, Instance->g_driverType, NULL, createDeviceFlags, featureLevels, numFeatureLevels,
				D3D11_SDK_VERSION, &sd, &Instance->g_pSwapChain, &Instance->g_pd3dDevice, &Instance->g_featureLevel, &Instance->g_pImmediateContext);
			
			if (SUCCEEDED(hr)) break;
		}

		// Create a render target view
		ID3D11Texture2D* pBackBuffer = NULL;
		hr = Instance->g_pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);

		hr = Instance->g_pd3dDevice->CreateRenderTargetView(pBackBuffer, NULL, &Instance->g_pRenderTargetView);
		pBackBuffer->Release();

		Instance->g_pImmediateContext->OMSetRenderTargets(1, &Instance->g_pRenderTargetView, NULL);

		// Setup the viewport
		D3D11_VIEWPORT vp;
		vp.Width = (FLOAT)width;
		vp.Height = (FLOAT)height;
		vp.MinDepth = 0.0f;
		vp.MaxDepth = 1.0f;
		vp.TopLeftX = 0;
		vp.TopLeftY = 0;
		Instance->g_pImmediateContext->RSSetViewports(1, &vp);

		SomManager_Main::CreateGameManager();
		SomManager_Texture::CreateTexManager();
	}
	else
	{
		// SomWorks :D // Already Create Instnace
	}
}

// SomWorks :D // 모든 업데이트는 이곳에서
void SomFramework_DX11::Update(float DeltaTime)
{
	// SomWorks :D // DirectX 11 렌더러 업데이트
	//SomManager_Main::GetInstance()->Game_Update(DeltaTime);
	//SomManager_Main::GetInstance()->Game_Render();
}

void SomFramework_DX11::Render()
{
	// Just clear the backbuffer
	float ClearColor[4] = { 0.0f, 0.125f, 0.3f, 1.0f }; //red,green,blue,alpha
	Instance->g_pImmediateContext->ClearRenderTargetView(Instance->g_pRenderTargetView, ClearColor);
	Instance->g_pSwapChain->Present(0, 0);
}

// SomWorks :D // 릴리즈
void SomFramework_DX11::Release(HWND hWnd)
{
	if (Instance)
	{	
		if (Instance->g_pImmediateContext) Instance->g_pImmediateContext->ClearState();

		if (Instance->g_pRenderTargetView) Instance->g_pRenderTargetView->Release();
		if (Instance->g_pSwapChain) Instance->g_pSwapChain->Release();
		if (Instance->g_pImmediateContext) Instance->g_pImmediateContext->Release();
		if (Instance->g_pd3dDevice) Instance->g_pd3dDevice->Release();

		SomManager_Main::TerminateGameManager();
		SomManager_Texture::TerminateTexManager();

		delete Instance;
		Instance = nullptr;
	}
}