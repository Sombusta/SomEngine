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

	FORCEINLINE FVector2D operator/(const FVector2D& Value) const
	{
		FVector2D Result;
		Result.X = this->X / Value.X;
		Result.Y = this->Y / Value.Y;
		return Result;
	}

	FORCEINLINE FVector2D operator*(const float& Value) const
	{
		FVector2D Result;
		Result.X = this->X * Value;
		Result.Y = this->Y * Value;
		return Result;
	}

	FORCEINLINE FVector2D operator*(const int& Value) const
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

	FORCEINLINE static void Swap(FVector2D& v1, FVector2D& v2)
	{
		FVector2D Temp;
		Temp = v1;
		v1 = v2;
		v2 = Temp;
	}

	// SomWorks :D // º¤ÅÍÀÇ ±æÀÌ ±¸ÇÏ±â °ø½Ä, ·çÆ®(x Á¦°ö + y Á¦°ö)
	FORCEINLINE static float GetLength(const FVector2D& Value)
	{		
		return std::sqrtf(std::powf(Value.X, 2) + std::powf(Value.Y, 2));
	}

	FORCEINLINE static FVector2D Normalize(const FVector2D& Value)
	{
		FVector2D Result;

		float VectorLength = GetLength(Value);

		if (VectorLength <= 0.001f)
		{
			return Value;
		}

		Result.X = Value.X / VectorLength;
		Result.Y = Value.Y / VectorLength;

		return Result;
	}

	// SomWorks :D // º¤ÅÍÀÇ ³»Àû
	FORCEINLINE static float DotProduct(const FVector2D& v1, const FVector2D& v2)
	{
		return v1.X * v2.X + v1.Y * v2.Y;
	}

} FVector2D;