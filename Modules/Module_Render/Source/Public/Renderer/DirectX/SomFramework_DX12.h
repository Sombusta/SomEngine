// Copyright (c) 2014-2020 Sombusta, All Rights Reserved.

#pragma once

#include "Module_Render.h"
#include "RendererLibrary_DX12.h"

class SomFramework_DX12 : public SomFramework
{
public:
	SomFramework_DX12();
	SomFramework_DX12(UINT width, UINT height, wstring name);
	virtual ~SomFramework_DX12();

	// SomWorks :D // DirectX 11 ·»´õ·¯ ¼Â¾÷
	virtual void OnInit(HWND hWnd);
	virtual void OnUpdate(float DeltaTime);
	virtual void OnRender();
	virtual void OnDestroy(HWND hWnd);

private:

protected:

public:

};