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

// SomWorks :D // GDI ������Ʈ ����
void SomFramework_DX12::OnInit(HWND hWnd)
{
}

// SomWorks :D // ��� ������Ʈ�� �̰�����
void SomFramework_DX12::OnUpdate(float DeltaTime)
{
	// SomWorks :D // DirectX 12 ������ ������Ʈ

}

void SomFramework_DX12::OnRender()
{

}

// SomWorks :D // ������
void SomFramework_DX12::OnDestroy(HWND hWnd)
{

}