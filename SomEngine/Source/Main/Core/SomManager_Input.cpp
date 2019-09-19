// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#include "SomManager_Input.h"

SomManager_Input* SomManager_Input::Instance = nullptr;

SomManager_Input::SomManager_Input()
{
}

SomManager_Input::~SomManager_Input()
{
}

void SomManager_Input::CreateInputManager()
{
	if (Instance == nullptr)
	{
		Instance = new SomManager_Input;

		for (int i = 0; i < 256; i++)
		{
			Instance->m_keys[i] = false;
		}
	}
}

void SomManager_Input::TerminateInputManager()
{
	if (Instance)
	{
		
		delete Instance;
		Instance = nullptr;
	}
}

void SomManager_Input::KeyDown(unsigned int Input)
{
	// 키가 눌렸다면 그 상태를 배열에 저장합니다.
	Instance->m_keys[Input] = true;
}

void SomManager_Input::KeyUp(unsigned int Input)
{
	// 키가 떼어졌다면 그 상태를 배열에 저장합니다.
	Instance->m_keys[Input] = false;
}

bool SomManager_Input::IsKeyDown(unsigned int Key)
{
	return Instance->m_keys[Key];
}
