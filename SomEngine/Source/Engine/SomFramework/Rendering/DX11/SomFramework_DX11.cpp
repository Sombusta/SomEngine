// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#include "SomFramework_DX11.h"

SomFramework_DX11* SomFramework_DX11::Instance = nullptr;

SomFramework_DX11::SomFramework_DX11()
{
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
	SomManager_Main::GetInstance()->Game_Update(DeltaTime);
	SomManager_Main::GetInstance()->Game_Render();
}

// SomWorks :D // 릴리즈
void SomFramework_DX11::Release(HWND hWnd)
{
	if (Instance)
	{
	

		SomManager_Main::TerminateGameManager();
		SomManager_Texture::TerminateTexManager();

		delete Instance;
		Instance = nullptr;
	}
}