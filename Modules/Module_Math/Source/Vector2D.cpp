// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#include "pch.h"

const FVector2D FVector2D::UnitX(1.f, 0.f);
const FVector2D FVector2D::UnitY(0.f, 1.f);
const FVector2D FVector2D::Zero(0.f, 0.f);
const FVector2D FVector2D::One(1.f, 1.f);
const FVector2D FVector2D::Infinity(INFINITY, INFINITY);
const FVector2D FVector2D::InfinityNeg(-INFINITY, -INFINITY);

/*std::string FVector2D::ToString() const
{
	char result[64];
	std::snprintf(result, sizeof(result), "(%.3f, %.3f)", X, Y);
	return result;
}*/