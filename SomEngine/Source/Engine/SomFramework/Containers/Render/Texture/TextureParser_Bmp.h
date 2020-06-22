// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#pragma once

#include "Engine/Engine.h"

class FSomTextureParser_BMP
{
public:
	FSomTextureParser_BMP();
	~FSomTextureParser_BMP();

	static bool OpenBMP(FTexture2D& TargetTexture, char *filename);

	static FLinearColor GetPixel(int x, int y, FTexture2D& bmp);
private:

protected:

public:

};