// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#pragma once

#include "Engine/Engine.h"

typedef struct FColor
{
public:
	FColor() : r(255), g(255), b(255) {}

	FColor(BYTE R, BYTE G, BYTE B) : r(R), g(G), b(B) {}
	
	BYTE r = 255;
	BYTE g = 255;
	BYTE b = 255;

	FORCEINLINE ULONG GetColor() const { return RGB(b, g, r); }
} FColor;