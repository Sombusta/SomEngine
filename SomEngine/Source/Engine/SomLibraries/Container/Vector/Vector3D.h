// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#pragma once

// SomWorks :D // Vector3D
typedef struct FVector
{
public:
	FVector() : x(0.0f), y(0.0f), z(0.0f) {}

	FVector(float X, float Y, float Z) : x(X), y(Y), z(Z) {}

	float x = 0.0f;
	float y = 0.0f;
	float z = 0.0f;

	FORCEINLINE void Printf()
	{
		cout << x << ", " << y << ", " << z << endl;
	}
} Vector3D;