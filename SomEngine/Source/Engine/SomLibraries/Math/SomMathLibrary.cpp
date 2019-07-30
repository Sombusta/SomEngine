// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#include "Engine/Engine.h"

FSomMathLibrary::FSomMathLibrary()
{
}

FSomMathLibrary::~FSomMathLibrary()
{
}

bool FSomMathLibrary::IsInRange(int x, int y)
{
	return (abs(x) < (SomWidth / 2)) && (abs(y) < (SomHeight / 2));
}