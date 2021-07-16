// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#pragma once

#include <windows.h>

typedef struct FColor32
{
public:
	BYTE R = 255;
	BYTE G = 255;
	BYTE B = 255;
	BYTE A = 255;

public:
	FColor32() : R(0), G(0), B(0), A(255) { }
	explicit FColor32(BYTE r, BYTE g, BYTE b, BYTE a = 255) : R(r), G(g), B(b), A(a) {}

	FORCEINLINE ULONG GetColor() const { return RGB(B, G, R); }
	// FORCEINLINE const UINT32& GetColorRef() const { return *((UINT32*)this); }
	// FORCEINLINE UINT32& GetColorRef() { return *((UINT32*)this); }

} FColor;