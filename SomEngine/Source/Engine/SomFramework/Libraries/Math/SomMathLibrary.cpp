// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#include "Engine/Engine.h"

FSomMathLibrary::FSomMathLibrary()
{
}

FSomMathLibrary::~FSomMathLibrary()
{
}

bool FSomMathLibrary::IsInRange(int x, int y)
{
	return (abs(x) < (SomWidth / 2)) && (abs(y) < (SomHeight / 2));
}

int FSomMathLibrary::GetLineLength(FPoint p1, FPoint p2)
{
	return static_cast<int>(sqrt(((p2.X - p1.X)*(p2.X - p1.X)) + (p2.Y - p1.Y)*(p2.Y - p1.Y)));
}

int FSomMathLibrary::GetEOL(FPoint p1, FPoint p2, int x)
{
	// SomWorks :D // 직선의 방정식
	// y = (x2 - x1)/(y2 - y1) * (x - x1) + y1

	// SomWorks :D // y 값 리턴
	
	return ((p2.Y - p1.Y) / (p2.X - p1.X)) * (x - p1.Y) + p1.Y;
}