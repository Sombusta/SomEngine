// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#pragma once

// SomWorks :D // Vector4D
typedef struct FVector4
{
public:
	float X = 0.0f;
	float Y = 0.0f;
	float Z = 0.0f;
	float W = 0.0f;

public:
	FVector4() : X(0.0f), Y(0.0f), Z(0.0f), W(0.0f) {}

	FVector4(float x, float y, float z, float w) : X(x), Y(y), Z(z), W(w) {}

	FVector4(int x, int y, int z, int w) : X(static_cast<float>(x)), Y(static_cast<float>(y)), Z(static_cast<float>(z)), W(static_cast<float>(w)) {}

	FORCEINLINE FVector4& operator=(const FVector4& Value)
	{
		if (this == &Value) {
			return *this;
		}

		this->X = Value.X;
		this->Y = Value.Y;
		this->Z = Value.Z;
		this->W = Value.W;

		return *this;
	}

	FORCEINLINE FVector4 operator+(const FVector4& Value) const
	{
		FVector4 Result;
		Result.X = this->X + Value.X;
		Result.Y = this->Y + Value.Y;
		Result.Z = this->Z + Value.Z;
		Result.W = this->W + Value.W;
		return Result;
	}

	FORCEINLINE FVector4 operator-(const FVector4& Value) const
	{
		FVector4 Result;
		Result.X = this->X - Value.X;
		Result.Y = this->Y - Value.Y;
		Result.Z = this->Z - Value.Z;
		Result.W = this->W - Value.W;
		return Result;
	}

	FORCEINLINE FVector4 operator*(const FVector4& Value) const
	{
		FVector4 Result;
		Result.X = this->X * Value.X;
		Result.Y = this->Y * Value.Y;
		Result.Z = this->Z * Value.Z;
		Result.W = this->W * Value.W;
		return Result;
	}

	FORCEINLINE FVector4 operator*(const float& Value) const
	{
		FVector4 Result;
		Result.X = this->X * Value;
		Result.Y = this->Y * Value;
		Result.Z = this->Z * Value;
		Result.W = this->W * Value;
		return Result;
	}

	FORCEINLINE void Printf()
	{
		std::cout << X << ", " << Y << ", " << Z << ", " >> W << std::endl;
	}
} FVector;