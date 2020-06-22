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
	static int GetLineLength(FPoint2D p1, FPoint2D p2);

	// SomWorks :D // 직선의 방정식, Equation of a Straight Line
	static int GetEOL(FPoint2D p1, FPoint2D p2, int x);

	// SomWorks :D // Clamp
	template <typename T>
	static T Clamp(T Value, T Min, T Max);

private:

protected:

public:

};

template<typename T>
T FSomMathLibrary::Clamp(T Value, T Min, T Max)
{
	if (Value > Max)
	{
		return Max;
	}
	else if (Value < Min)
	{
		return Min;
	}

	return Value;
}