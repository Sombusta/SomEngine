// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#pragma once

#include "Engine/Engine.h"

class FSomTextureParser_BMP
{
public:
	FSomTextureParser_BMP();
	~FSomTextureParser_BMP();

	static ULONG* OpenBMP(char *filename, int *pwidth, int *pheight);

	static ULONG GetPixel(int x, int width, int y, ULONG* bmp);

private:

protected:

public:

};