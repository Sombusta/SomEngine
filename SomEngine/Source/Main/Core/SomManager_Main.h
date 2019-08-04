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
	
	// SomWorks :D // 오브젝트 생성 및 소거
	void Game_CreateObjects();

	void Game_DestroyObjects();

	// SomWorks :D // 게임 플레이
	void Game_Init();

	void Game_Update(float DeltaTime);

	void Game_Render();
	
private:
	// SomWorks :D // 싱글턴 객체
	static SomManager_Main* Instance;

protected:

public:
	// SomWorks :D // 전방선언
	class SR_Sample* SampleObject;

	// SomWorks :D // 싱글턴 인스턴스 Getter
	static SomManager_Main* GetInstance() { return Instance; }
};