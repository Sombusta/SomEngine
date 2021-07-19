// Copyright (c) 2014-2021 Sombusta, All Rights Reserved.

#include "pch.h"

FDeltaTimeManager::FDeltaTimeManager()
{
	Frequency = LARGE_INTEGER();
	StartTime = LARGE_INTEGER();

	TickPerMs = 0.0f;

	FramePerSecond = 0;
	FrameTime = 0.0f;
}

FDeltaTimeManager::~FDeltaTimeManager()
{
}

bool FDeltaTimeManager::Initialize()
{
	// 현재 시스템이 QueryPerformanceCounter 를 지원하는 지 확인
	if (QueryPerformanceFrequency(&Frequency) == false) return false;
		
	if (QueryPerformanceCounter(&StartTime) == false) return false;

	TickPerMs = static_cast<float>(Frequency.QuadPart / 1000);

	// SomWorks :D // 이전 시간
	// DWORD PreviousTime = timeGetTime();

	// SomWorks :D // 현재 시간
	// DWORD CurrentTime = timeGetTime();

	// SomWorks :D // 밀리 세컨드 단위, DeltaTime
	// float ElapsedTime = (CurrentTime - PreviousTime) / 1000.f;

	// PreviousTime = CurrentTime;

	// GetTickCount64()) / 1000;

	return true;
}

void FDeltaTimeManager::CalcFrame()
{
	LARGE_INTEGER CurrentTime;
	
	QueryPerformanceCounter(&CurrentTime);

	const float ElapsedTime = static_cast<float>(CurrentTime.QuadPart - StartTime.QuadPart);
	
	FramePerSecond = Frequency.QuadPart / ElapsedTime;	
	FrameTime = ElapsedTime / TickPerMs;

	StartTime = CurrentTime;
}