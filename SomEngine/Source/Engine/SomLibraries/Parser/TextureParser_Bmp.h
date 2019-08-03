// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#pragma once

#include "Engine/Engine.h"

ULONG* OpenBMP(char *filename, int *pwidth, int *pheight);
ULONG GetPixel(int x, int width, int y, ULONG* bmp);