// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#pragma once

// SomWorks :D // Vector
typedef struct FPoint
{
public:
	int X = 0;
	int Y = 0;

public:
	FPoint() : X(0), Y(0) {}

	FPoint(int x, int y) : X(x), Y(y) {}

	FPoint(float x, float y) : X(static_cast<int>(x)), Y(static_cast<int>(y)) {}

	FORCEINLINE FPoint& operator=(const FPoint& Value)
	{
		if (this == &Value) {
			return *this;
		}

		this->X = Value.X;
		this->Y = Value.Y;

		return *this;
	}

	FORCEINLINE FPoint operator+(const FPoint& Value) const
	{
		FPoint Result;
		Result.X = this->X + Value.X;
		Result.Y = this->Y + Value.Y;
		return Result;
	}

	FORCEINLINE FPoint operator-(const FPoint& Value) const
	{
		FPoint Result;
		Result.X = this->X - Value.X;
		Result.Y = this->Y - Value.Y;
		return Result;
	}

	FORCEINLINE FPoint operator*(const FPoint& Value) const
	{
		FPoint Result;
		Result.X = this->X * Value.X;
		Result.Y = this->Y * Value.Y;
		return Result;
	}

	FORCEINLINE FPoint operator*(const int& Value) const
	{
		FPoint Result;
		Result.X = this->X * Value;
		Result.Y = this->Y * Value;
		return Result;
	}

	FORCEINLINE void Printf()
	{
		std::cout << X << ", " << Y << std::endl;
	}
} FPoint;
