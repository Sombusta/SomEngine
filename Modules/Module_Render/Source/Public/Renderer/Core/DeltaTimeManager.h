// Copyright (c) 2014-2021 Sombusta, All Rights Reserved.

#pragma once

#include <windows.h>

class FDeltaTimeManager
{
public:
	FDeltaTimeManager();
	~FDeltaTimeManager();

	bool Initialize();
	void CalcFrame();

private:
	LARGE_INTEGER Frequency;
	LARGE_INTEGER StartTime;

	float TickPerMs;
	
	// ms
	float FrameTime;
	
	// FPS
	float FramePerSecond;

public:
	FORCEINLINE float GetFPS() { return FramePerSecond; }
	FORCEINLINE float GetMs() { return FrameTime; }
	FORCEINLINE float GetDeltaTime() { return FrameTime / 1000; }
};