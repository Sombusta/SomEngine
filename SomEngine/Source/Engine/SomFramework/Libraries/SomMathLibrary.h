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
	static int GetLineLength(FPoint2D p1, FPoint2D p2);

	// SomWorks :D // ������ ������, Equation of a Straight Line
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