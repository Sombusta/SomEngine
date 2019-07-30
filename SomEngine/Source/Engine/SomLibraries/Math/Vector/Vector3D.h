// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#pragma once

// SomWorks :D // Vector3D
typedef struct FVector
{
	FVector()
	{
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
	}

	FVector(float x1, float y1, float z1) : x(x1), y(y1), z(z1) {}

	void Printf()
	{
		cout << x << ", " << y << ", " << z << endl;
	}

	float x = 0.0f;
	float y = 0.0f;
	float z = 0.0f;
} Vector3D;