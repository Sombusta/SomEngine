// Copyright (c) 2014-2020 Sombusta, All Rights Reserved.

#include "SomFramework_DX12.h"

SomFramework_DX12::SomFramework_DX12() : SomFramework()
{
	CurrentFrameworkType = SomFrameworkSetup::DX12;
}

SomFramework_DX12::SomFramework_DX12(UINT width, UINT height, wstring name) : SomFramework(width, height, name)
{
	CurrentFrameworkType = SomFrameworkSetup::DX12;
}

SomFramework_DX12::~SomFramework_DX12()
{
}

// SomWorks :D // GDI 오브젝트 생성
void SomFramework_DX12::OnInit(HWND hWnd)
{
}

// SomWorks :D // 모든 업데이트는 이곳에서
void SomFramework_DX12::OnUpdate(float DeltaTime)
{
	// SomWorks :D // DirectX 12 렌더러 업데이트

}

void SomFramework_DX12::OnRender()
{

}

// SomWorks :D // 릴리즈
void SomFramework_DX12::OnDestroy(HWND hWnd)
{

}