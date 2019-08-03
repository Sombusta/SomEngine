// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

// SomWorks :D // GDI : Graphics Device Interface

#pragma once

#include "Engine/Engine.h"

class SomFramework_SR
{
public:
	SomFramework_SR();
	~SomFramework_SR();

	// SomWorks :D // 소프트 렌더러 셋업
	static void InitGDI(HWND hWnd);
	static void UpdateGDI(float DeltaTime);
	static void ReleaseGDI(HWND hWnd);

	void BufferClear();
	void BufferSwap();

	// SomWorks :D // 디버그 그리드
	void DrawGridLine(bool bActivate);

	// SomWorks :D // 게임 플레이 셋업
	void GamePlayInit();
	void GamePlayUpdate(float DeltaTime);
	void GamePlayRelease();

private:
	// SomWorks :D // 싱글턴 객체
	static SomFramework_SR* Instance;

protected:

public:	
	HDC	hScreenDC, hMemoryDC;

	HBITMAP hDefaultBitmap, hDIBitmap;

	BYTE* Bits;

	// SomWorks :D // 전방선언
	class SR_Sample* SampleObject;

	// SomWorks :D // 싱글턴 인스턴스 Getter
	static SomFramework_SR* GetInstance() { return Instance; }
};