// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#pragma once

#include "Engine/Engine.h"

class SomManager_Texture
{
public:
	SomManager_Texture();
	~SomManager_Texture();

	static void CreateTexManager();
	static void TerminateTexManager();

	// SomWorks :D // 오브젝트 생성 및 소거
	void Texture_CreateObjects();

	void Texture_DestroyObjects();

private:
	// SomWorks :D // 싱글턴 객체
	static SomManager_Texture* Instance;

protected:

public:
	FTexture2D T_Test1;
	FTexture2D T_Test2;

	// SomWorks :D // 싱글턴 인스턴스 Getter
	static SomManager_Texture* GetInstance() { return Instance; }
};