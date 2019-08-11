// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#pragma once

// SomWorks :D // Vector2D
typedef struct FVector2D
{
public:	
	float X = 0.0f;
	float Y = 0.0f;

public:
	FVector2D() : X(0.0f), Y(0.0f) {}
	
	FVector2D(float x, float y) : X(x), Y(y) {}

	FVector2D(int x, int y) : X(static_cast<float>(x)), Y(static_cast<float>(y)) {}

	FORCEINLINE FVector2D& operator=(const FVector2D& Value)
	{
		if (this == &Value) {
			return *this;
		}

		this->X = Value.X;
		this->Y = Value.Y;

		return *this;
	}

	FORCEINLINE FVector2D operator+(const FVector2D& Value) const
	{
		FVector2D Result;
		Result.X = this->X + Value.X;
		Result.Y = this->Y + Value.Y;
		return Result;
	}

	FORCEINLINE FVector2D operator-(const FVector2D& Value) const
	{
		FVector2D Result;
		Result.X = this->X - Value.X;
		Result.Y = this->Y - Value.Y;
		return Result;
	}

	FORCEINLINE FVector2D operator*(const FVector2D& Value) const
	{
		FVector2D Result;
		Result.X = this->X * Value.X;
		Result.Y = this->Y * Value.Y;
		return Result;
	}

	FORCEINLINE FVector2D operator*(const float& Value) const
	{
		FVector2D Result;
		Result.X = this->X * Value;
		Result.Y = this->Y * Value;
		return Result;
	}

	FORCEINLINE void Printf()
	{
		std::cout << X << ", " << Y << std::endl;
	}
} FVector2D;