#pragma once

// SomWorks :D // Vector2D
typedef struct FVector2D
{
	FVector2D()
	{
		x = 0;
		y = 0;
	}

	FVector2D(int x1, int y1)
	{
		x = x1;
		y = y1;
	}

	int x = 0;
	int y = 0;
} Vector2D;

// SomWorks :D // Vector3D
typedef struct FVector
{
	FVector()
	{
		x = 0;
		y = 0;
		z = 0;
	}

	FVector(int x1, int y1, int z1)
	{
		x = x1;
		y = y1;
		z = z1;
	}

	int x = 0;
	int y = 0;
	int z = 0;
} Vector3D;