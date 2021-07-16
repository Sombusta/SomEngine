// Copyright (c) 2014-2020 Sombusta, All Rights Reserved.

#include "SomManager_Main.h"
#include "Runtime/SR_Sample.h"
#include "Runtime/SR_Test1.h"

SomManager_Main* SomManager_Main::Instance = nullptr;

SomManager_Main::SomManager_Main()
{
}

SomManager_Main::~SomManager_Main()
{
}

void SomManager_Main::CreateGameManager()
{
	if (Instance == nullptr)
	{
		Instance = new SomManager_Main;

		Instance->Game_CreateObjects();
		Instance->Game_Init();
	}
}

void SomManager_Main::TerminateGameManager()
{
	if (Instance)
	{
		Instance->Game_DestroyObjects();
		delete Instance;
		Instance = nullptr;
	}
}

void SomManager_Main::Game_CreateObjects()
{
	//SR_Sample* SampleObject = new SR_Sample;
	SR_Test1* SR_Test1Object = new SR_Test1;

	//GameObjects.push_back(SampleObject);
	GameObjects.push_back(SR_Test1Object);
}

void SomManager_Main::Game_DestroyObjects()
{
	for (vector<GameObject*>::iterator it = GameObjects.begin(); it != GameObjects.end(); it++)
	{
		delete *it;
	}
}

void SomManager_Main::Game_Init()
{
	for (vector<GameObject*>::iterator it = GameObjects.begin(); it != GameObjects.end(); it++)
	{
		(*it)->Init();
	}
}

void SomManager_Main::Game_Update(float DeltaTime)
{
	for (vector<GameObject*>::iterator it = GameObjects.begin(); it != GameObjects.end(); it++)
	{
		(*it)->Update(DeltaTime);
	}
}

void SomManager_Main::Game_Render()
{
	for (vector<GameObject*>::iterator it = GameObjects.begin(); it != GameObjects.end(); it++)
	{
		(*it)->Render();
	}
}