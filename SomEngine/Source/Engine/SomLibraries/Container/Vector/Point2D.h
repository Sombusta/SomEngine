// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#pragma once

// SomWorks :D // Vector2D
typedef struct FPoint2D
{
public:
	FPoint2D() : x(0), y(0) {}

	FPoint2D(int X, int Y) : x(X), y(Y) {}
		
	// SomWorks :D // ���� ���۷����� �߰�
	// +
	// -
	// *

	void Printf()
	{
		cout << x << ", " << y << endl;
	}

	int x = 0;
	int y = 0;
} Point2D;
