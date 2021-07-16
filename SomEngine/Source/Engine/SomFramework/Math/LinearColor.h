// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#pragma once

#include "MathUtility.h"
#include "Color32.h"

typedef struct FLinearColor
{
public:
	float R = 0.0f;
	float G = 0.0f;
	float B = 0.0f;
	float A = 1.0f;

public:
	FLinearColor() = default;
	explicit FLinearColor(float InR, float InG, float InB, float InA = 1.f) : R(InR), G(InG), B(InB), A(InA) {}
	explicit FLinearColor(const FColor32& InColor32)
	{
		R = static_cast<float>(InColor32.R) * OneOver255;
		G = static_cast<float>(InColor32.G) * OneOver255;
		B = static_cast<float>(InColor32.B) * OneOver255;
		A = static_cast<float>(InColor32.A) * OneOver255;
	}

	FORCEINLINE FColor32 ToColor32() const;

	static const float OneOver255;
	static const FLinearColor Error;
	static const FLinearColor White;
	static const FLinearColor Black;
	static const FLinearColor Gray;
	static const FLinearColor Red;
	static const FLinearColor Green;
	static const FLinearColor Blue;
	static const FLinearColor Yellow;
	static const FLinearColor Cyan;
	static const FLinearColor Magenta;
	
} FLinearColor;

FColor32 FLinearColor::ToColor32() const
{
	const float FloatR = FMath::Clamp(R, 0.f, 1.f);
	const float FloatG = FMath::Clamp(G, 0.f, 1.f);
	const float FloatB = FMath::Clamp(B, 0.f, 1.f);
	const float FloatA = FMath::Clamp(A, 0.f, 1.f);

	return FColor32(
		(int)(FloatR * 255.999f),
		(int)(FloatG * 255.999f),
		(int)(FloatB * 255.999f),
		(int)(FloatA * 255.999f)
	);
}