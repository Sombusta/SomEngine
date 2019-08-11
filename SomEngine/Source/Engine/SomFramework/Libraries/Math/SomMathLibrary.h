// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#pragma once

#include "Engine/Engine.h"

class FSomMathLibrary
{
public:
	FSomMathLibrary();
	~FSomMathLibrary();

	// SomWorks :D // 수가 범위 안에 있는지 체크
	static bool IsInRange(int x, int y);

	// SomWorks :D // 선의 크기 체크
	static int GetLineLength(FPoint p1, FPoint p2);

	// SomWorks :D // 직선의 방정식, Equation of a Straight Line
	static int GetEOL(FPoint p1, FPoint p2, int x);

private:

protected:

public:

};