// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#pragma once

#include "Engine/Engine.h"

class FSomMathLibrary
{
public:
	FSomMathLibrary();
	~FSomMathLibrary();

	// SomWorks :D // ���� ���� �ȿ� �ִ��� üũ
	static bool IsInRange(int x, int y);

	// SomWorks :D // ���� ũ�� üũ
	static int GetLineLength(FPoint p1, FPoint p2);

	// SomWorks :D // ������ ������, Equation of a Straight Line
	static int GetEOL(FPoint p1, FPoint p2, int x);

private:

protected:

public:

};