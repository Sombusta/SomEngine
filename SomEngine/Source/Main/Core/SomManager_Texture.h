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

	// SomWorks :D // ������Ʈ ���� �� �Ұ�
	void Texture_CreateObjects();

	void Texture_DestroyObjects();

private:
	// SomWorks :D // �̱��� ��ü
	static SomManager_Texture* Instance;

protected:

public:
	FTexture2D T_Test1;
	FTexture2D T_Test2;

	// SomWorks :D // �̱��� �ν��Ͻ� Getter
	static SomManager_Texture* GetInstance() { return Instance; }
};