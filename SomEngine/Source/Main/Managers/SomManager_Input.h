// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#pragma once

#include "Engine/Engine.h"

class SomManager_Input
{
public:
	SomManager_Input();
	~SomManager_Input();
	
	static void CreateInputManager();
	static void TerminateInputManager();

	static void KeyDown(unsigned int Input);
	static void KeyUp(unsigned int Input);

	static bool IsKeyDown(unsigned int Key);

private:
	// SomWorks :D // ΩÃ±€≈œ ∞¥√º
	static SomManager_Input* Instance;

	bool m_keys[256];

protected:

public:

	// SomWorks :D // ΩÃ±€≈œ ¿ŒΩ∫≈œΩ∫ Getter
	static SomManager_Input* GetInstance() { return Instance; }
};