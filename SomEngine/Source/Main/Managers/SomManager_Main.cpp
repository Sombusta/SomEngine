// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#include "SomManager_Main.h"
#include "Main/SR_Sample.h"

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
	SampleObject = new SR_Sample;
}

void SomManager_Main::Game_DestroyObjects()
{
	delete SampleObject;
}

void SomManager_Main::Game_Init()
{
	SampleObject->Init();
}

void SomManager_Main::Game_Update(float DeltaTime)
{
	SampleObject->Update(DeltaTime);
}

void SomManager_Main::Game_Render()
{
	SampleObject->Render();
}