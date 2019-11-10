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

	FORCEINLINE FVector operator*(const int& Value) const
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

	// SomWorks :D // º¤ÅÍ ½º¿Ò
	FORCEINLINE static void Swap(FVector& v1, FVector& v2)
	{
		FVector Temp;
		Temp = v1;
		v1 = v2;
		v2 = Temp;
	}

	// SomWorks :D // º¤ÅÍÀÇ ±æÀÌ ±¸ÇÏ±â °ø½Ä, ·çÆ®(x Á¦°ö + y Á¦°ö + z Á¦°ö)
	FORCEINLINE static float GetLength(const FVector& Value)
	{
		return std::sqrtf(std::powf(Value.X, 2) + std::powf(Value.Y, 2) + std::powf(Value.Z, 2));
	}

	// SomWorks :D // º¤ÅÍ Á¤±ÔÈ­
	FORCEINLINE static FVector Normalize(const FVector& Value)
	{
		FVector Result;

		float VectorLength = GetLength(Value);

		if (VectorLength <= 0.001f)
		{
			return Value;
		}

		Result.X = Value.X / VectorLength;
		Result.Y = Value.Y / VectorLength;
		Result.Z = Value.Z / VectorLength;

		return Result;
	}

	// SomWorks :D // º¤ÅÍ ³»Àû
	FORCEINLINE static float DotProduct(const FVector& v1, const FVector& v2)
	{
		return (v1.X * v2.X) + (v1.Y * v2.Y) + (v1.Z * v2.Z);
	}

	// SomWorks :D // º¤ÅÍ ¿ÜÀû // w = u x v = Result(uy * vz - uz * vy, uz * vx - ux * vz, ux * vy - uy * vx)
	FORCEINLINE static FVector CrossProduct(const FVector& v1, const FVector& v2)
	{
		FVector Result;

		Result.X = (v1.Y * v2.Z) - (v1.Z * v2.Y);
		Result.Y = (v1.Z * v2.X) - (v1.X * v1.Z);
		Result.Z = (v1.X * v2.Y) - (v1.Y * v2.X);

		return Result;
	}

} FVector;