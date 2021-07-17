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

// SomWorks :D // GDI 오브젝트 생성
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

	// 드라이버 타입 프리셋
	// DX11을 지원하지 않는 하드웨어에서는 레퍼런스 모드로
	// 작동하게 하기 위해서 배열로 선언하여,
	// 하나씩 생성해봐서 성공하는 드라이버를 사용한다.
	D3D_DRIVER_TYPE driverTypes[] =
	{
		D3D_DRIVER_TYPE_HARDWARE,
		D3D_DRIVER_TYPE_WARP,
		D3D_DRIVER_TYPE_REFERENCE,
	};

	// 드라이버 타입 갯수
	UINT numDriverTypes = ARRAYSIZE(driverTypes);

	// DX 버전 피처
	D3D_FEATURE_LEVEL featureLevels[] =
	{
		D3D_FEATURE_LEVEL_11_0,
		D3D_FEATURE_LEVEL_10_1,
		D3D_FEATURE_LEVEL_10_0,
	};

	// 피처 갯수
	UINT numFeatureLevels = ARRAYSIZE(featureLevels);

	// 스왑체인을 생성하기 위한 정보
	DXGI_SWAP_CHAIN_DESC sd;
	ZeroMemory(&sd, sizeof(sd)); // 초기화
	// memset(&sd, 0, sizeof(sd));

	sd.BufferCount = 1;									// 백버퍼 카운트
	sd.BufferDesc.Width = width;						// 백버퍼 해상도
	sd.BufferDesc.Height = height;						// 백버퍼 해상도
	sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;	// 백버퍼 컬러 포맷, r8g8b8a8 32비트 컬러포맷
	sd.BufferDesc.RefreshRate.Numerator = 60;			// 화면 주사율
	sd.BufferDesc.RefreshRate.Denominator = 1;
	sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;	// 버퍼 사용 용도 설정
	sd.OutputWindow = hWnd;								// 버퍼를 출력할 윈도우 핸들
	sd.SampleDesc.Count = 1;							// 멀티샘플링 사용 여부
	sd.SampleDesc.Quality = 0;							// 0 으로 설명하면 멀티샘플링 기능을 사용하지않는다는 의미
	sd.Windowed = TRUE;									// 풀스크린 여부

	// 장치 및 스왑 체인 생성
	for (UINT driverTypeIndex = 0; driverTypeIndex < numDriverTypes; driverTypeIndex++)
	{
		g_driverType = driverTypes[driverTypeIndex];

		hr = D3D11CreateDeviceAndSwapChain(nullptr,
			g_driverType,				// 드라이버 타입
			NULL,
			createDeviceFlags,			// 디바이스 플래그
			featureLevels,				// 피처 레벨 배열
			numFeatureLevels,			// 피처 레벨 카운트
			D3D11_SDK_VERSION,			// SDK 버전
			&sd,						// 스왑체인 생성 구조체
			&g_pSwapChain,				// 생성된 스왑체인 객체
			&g_pd3dDevice,				// 생성된 디바이스 객체
			&g_featureLevel,			// 생성된 피처 레벨 정보
			&g_pImmediateContext);		// 생성된 디바이스 컨텍스트 객체

		if (SUCCEEDED(hr)) break;
	}

	// Create a render target view, 백버퍼를 스왑체인에서 가져옴
	ID3D11Texture2D* pBackBuffer = nullptr;
	hr = g_pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);

	// 백버퍼에 실제 렌더링할 렌더 타겟 뷰를 생성해서 바인딩
	hr = g_pd3dDevice->CreateRenderTargetView(pBackBuffer, NULL, &g_pRenderTargetView);

	// 렌더 타겟 뷰를 가져온 이후에는 직접 접근을 하지않고 렌더 타겟 뷰를 사용해서 접근한다.
	pBackBuffer->Release();

	// OM = Ouput Merge
	// 렌더 타겟 뷰는 최대 8개까지 설정 가능
	g_pImmediateContext->OMSetRenderTargets(1, &g_pRenderTargetView, nullptr); // 현재 뎁스 스텐실 뷰는 생성 하지 않음

	// Setup the viewport
	D3D11_VIEWPORT vp;
	vp.Width = (FLOAT)width;
	vp.Height = (FLOAT)height;
	vp.MinDepth = 0.0f;
	vp.MaxDepth = 1.0f;
	vp.TopLeftX = 0;
	vp.TopLeftY = 0;

	// RS = 레스터라이저 스테이지
	g_pImmediateContext->RSSetViewports(1, &vp);
}

// SomWorks :D // 모든 업데이트는 이곳에서
void SomFramework_DX11::OnUpdate(float DeltaTime)
{
	// SomWorks :D // DirectX 11 렌더러 업데이트

}

void SomFramework_DX11::OnRender()
{
	// Just clear the backbuffer
	float ClearColor[4] = { 0.0f, 0.125f, 0.3f, 1.0f }; // Red, Green, Blue, Alpha
	g_pImmediateContext->ClearRenderTargetView(g_pRenderTargetView, ClearColor);
	g_pSwapChain->Present(0, 0);
}

// SomWorks :D // 릴리즈
void SomFramework_DX11::OnDestroy(HWND hWnd)
{
	if (g_pImmediateContext) g_pImmediateContext->ClearState();
	if (g_pRenderTargetView) g_pRenderTargetView->Release();
	if (g_pSwapChain) g_pSwapChain->Release();
	if (g_pImmediateContext) g_pImmediateContext->Release();
	if (g_pd3dDevice) g_pd3dDevice->Release();
}