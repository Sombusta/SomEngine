// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

// SomWorks :D // GDI : Graphics Device Interface

#pragma once

#include "Engine/Engine.h"

class SomFramework_SR
{
public:
	SomFramework_SR();
	~SomFramework_SR();

	// SomWorks :D // ����Ʈ ������ �¾�
	static void InitGDI(HWND hWnd);
	static void UpdateGDI(float DeltaTime);
	static void ReleaseGDI(HWND hWnd);

	void BufferClear();
	void BufferSwap();

	// SomWorks :D // ����� �׸���
	void DrawGridLine(bool bActivate);

	// SomWorks :D // ���� �÷��� �¾�
	void GamePlayInit();
	void GamePlayUpdate(float DeltaTime);
	void GamePlayRelease();

private:
	// SomWorks :D // �̱��� ��ü
	static SomFramework_SR* Instance;

protected:

public:	
	HDC	hScreenDC, hMemoryDC;

	HBITMAP hDefaultBitmap, hDIBitmap;

	BYTE* Bits;

	// SomWorks :D // ���漱��
	class SR_Sample* SampleObject;

	// SomWorks :D // �̱��� �ν��Ͻ� Getter
	static SomFramework_SR* GetInstance() { return Instance; }
};