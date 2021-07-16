// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#pragma once

#include <iostream>
#include <math.h>

#define FORCEINLINE __forceinline

// SomWorks :D // Vector
typedef struct FPoint2D
{
public:
	int X = 0;
	int Y = 0;

public:
	FPoint2D() : X(0), Y(0) {}

	FPoint2D(int x, int y) : X(x), Y(y) {}

	FPoint2D(float x, float y) : X(static_cast<int>(x)), Y(static_cast<int>(y)) {}

	FORCEINLINE FPoint2D& operator=(const FPoint2D& Value)
	{
		if (this == &Value) {
			return *this;
		}

		this->X = Value.X;
		this->Y = Value.Y;

		return *this;
	}

	FORCEINLINE FPoint2D operator+(const FPoint2D& Value) const
	{
		FPoint2D Result;
		Result.X = this->X + Value.X;
		Result.Y = this->Y + Value.Y;
		return Result;
	}

	FORCEINLINE FPoint2D operator-(const FPoint2D& Value) const
	{
		FPoint2D Result;
		Result.X = this->X - Value.X;
		Result.Y = this->Y - Value.Y;
		return Result;
	}

	FORCEINLINE FPoint2D operator*(const FPoint2D& Value) const
	{
		FPoint2D Result;
		Result.X = this->X * Value.X;
		Result.Y = this->Y * Value.Y;
		return Result;
	}

	FORCEINLINE FPoint2D operator*(const int& Value) const
	{
		FPoint2D Result;
		Result.X = this->X * Value;
		Result.Y = this->Y * Value;
		return Result;
	}
	
	FORCEINLINE void Printf()
	{
		std::cout << X << ", " << Y << std::endl;
	}

	// SomWorks :D // º¤ÅÍ ½º¿Ò
	FORCEINLINE static void Swap(FPoint2D& v1, FPoint2D& v2)
	{
		FPoint2D Temp;
		Temp = v1;
		v1 = v2;
		v2 = Temp;
	}
} FPoint2D;