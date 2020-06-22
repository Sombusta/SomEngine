// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#pragma once

#include "Engine/Engine.h"

typedef struct FTexture2D
{
public:
	FTexture2D() : Width(0), Height(0) {}
	FTexture2D(int TexWidth, int TexHeight, FLinearColor* TargetTex) : Width(TexWidth), Height(TexHeight), TexBuffer(TargetTex) {}

	FLinearColor* TexBuffer = nullptr;
	int Width = 0;
	int Height = 0;
	char* FilePath = nullptr;

} FTexture2D;