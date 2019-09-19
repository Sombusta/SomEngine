// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

// SomWorks :D //

#pragma once

#include "Engine/Engine.h"

class SomFramework_DX11
{
public:
	SomFramework_DX11();
	~SomFramework_DX11();

	// SomWorks :D // DirectX 11 ������ �¾�
	static void Init(HWND hWnd);
	static void Update(float DeltaTime);
	static void Release(HWND hWnd);

private:
	// SomWorks :D // �̱��� ��ü
	static SomFramework_DX11* Instance;

protected:

public:

	// SomWorks :D // �̱��� �ν��Ͻ� Getter
	static SomFramework_DX11* GetInstance() { return Instance; }
};