// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#pragma once

// SomWorks :D // Vertex2D
typedef struct FVertex2D
{
public:
	FVector2D Location;
	FLinearColor Color;
	FVector2D UV;	

public:
	FVertex2D() : Location(FVector2D(0.0f,0.0f)), UV(FVector2D(0.0f, 0.0f)) {}

	FVertex2D(float x, float y) : Location(x, y), UV(FVector2D(0.0f, 0.0f)) {}

	FVertex2D(int x, int y) : Location(static_cast<float>(x), static_cast<float>(y)), UV(FVector2D(0.0f, 0.0f)) {}

	FORCEINLINE FVertex2D& operator=(const FVertex2D& Value)
	{
		if (this == &Value) {
			return *this;
		}

		this->Location = Value.Location;
		this->Color = Value.Color;
		this->UV = Value.UV;

		return *this;
	}

} FVertex2D;

// SomWorks :D // Vertex3D
typedef struct FVertex
{
public:
	FVector Location;
	FLinearColor Color;
	FVector UV;

public:
	FVertex() : Location(FVector(0.0f, 0.0f, 0.0f)), UV(FVector(0.0f, 0.0f, 0.0f)) {}

	FVertex(float x, float y, float z) : Location(x, y, z), UV(FVector(0.0f, 0.0f, 0.0f)) {}

	FVertex(int x, int y, int z) : Location(static_cast<float>(x), static_cast<float>(y), static_cast<float>(z)), UV(FVector(0.0f, 0.0f, 0.0f)) {}

	FORCEINLINE FVertex& operator=(const FVertex& Value)
	{
		if (this == &Value) {
			return *this;
		}

		this->Location = Value.Location;
		this->Color = Value.Color;
		this->UV = Value.UV;

		return *this;
	}

} FVertex;