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
	// ���� �ý����� QueryPerformanceCounter �� �����ϴ� �� Ȯ��
	if (QueryPerformanceFrequency(&Frequency) == false) return false;
		
	if (QueryPerformanceCounter(&StartTime) == false) return false;

	TickPerMs = static_cast<float>(Frequency.QuadPart / 1000);

	// SomWorks :D // ���� �ð�
	// DWORD PreviousTime = timeGetTime();

	// SomWorks :D // ���� �ð�
	// DWORD CurrentTime = timeGetTime();

	// SomWorks :D // �и� ������ ����, DeltaTime
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