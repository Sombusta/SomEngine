// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#pragma once

// SomWorks :D // Vector2D
typedef struct FVector2D
{
public:
	FVector2D() : x(0.0f), y(0.0f) {}
	
	FVector2D(float X, float Y) : x(X), y(Y) {}
	
	void Printf()
	{
		cout << x << ", " << y << endl;
	}

	float x = 0.0f;
	float y = 0.0f;
} Vector2D;