// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#pragma once

#include "Engine/Engine.h"

class SomManager_Main
{
public:
	SomManager_Main();
	~SomManager_Main();

	static void CreateGameManager();
	static void TerminateGameManager();
	
	// SomWorks :D // ������Ʈ ���� �� �Ұ�
	void Game_CreateObjects();

	void Game_DestroyObjects();

	// SomWorks :D // ���� �÷���
	void Game_Init();

	void Game_Update(float DeltaTime);

	void Game_Render();
	
private:
	// SomWorks :D // �̱��� ��ü
	static SomManager_Main* Instance;

protected:

public:
	// SomWorks :D // ���漱��
	class SR_Sample* SampleObject;

	// SomWorks :D // �̱��� �ν��Ͻ� Getter
	static SomManager_Main* GetInstance() { return Instance; }
};