// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#pragma once

// SomWorks :D // Vector3D
typedef struct FVector
{
public:
	float X = 0.0f;
	float Y = 0.0f;
	float Z = 0.0f;

public:	
	FVector() : X(0.0f), Y(0.0f), Z(0.0f) {}

	FVector(float x, float y, float z) : X(x), Y(y), Z(z) {}

	FVector(int x, int y, int z) : X(static_cast<float>(x)), Y(static_cast<float>(y)), Z(static_cast<float>(z)) {}

	FORCEINLINE FVector& operator=(const FVector& Value)
	{
		if (this == &Value) {
			return *this;
		}

		this->X = Value.X;
		this->Y = Value.Y;
		this->Z = Value.Z;

		return *this;
	}

	FORCEINLINE FVector operator+(const FVector& Value) const
	{
		FVector Result;
		Result.X = this->X + Value.X;
		Result.Y = this->Y + Value.Y;
		Result.Z = this->Z + Value.Z;
		return Result;
	}

	FORCEINLINE FVector operator-(const FVector& Value) const
	{
		FVector Result;
		Result.X = this->X - Value.X;
		Result.Y = this->Y - Value.Y;
		Result.Z = this->Z - Value.Z;
		return Result;
	}

	FORCEINLINE FVector operator*(const FVector& Value) const
	{
		FVector Result;
		Result.X = this->X * Value.X;
		Result.Y = this->Y * Value.Y;
		Result.Z = this->Z * Value.Z;
		return Result;
	}

	FORCEINLINE FVector operator*(const float& Value) const
	{
		FVector Result;
		Result.X = this->X * Value;
		Result.Y = this->Y * Value;
		Result.Z = this->Z * Value;
		return Result;
	}

	FORCEINLINE void Printf()
	{
		std::cout << X << ", " << Y << ", " << Z << std::endl;
	}
} FVector;