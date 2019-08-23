// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#pragma once

#include "Engine/Engine.h"

class FQuad2D
{
public:
	FQuad2D();
	FQuad2D(FVertex2D a, FVertex2D b, FVertex2D c, FVertex2D d, const FTexture2D& Tex, bool bUseTextrue = true);
	~FQuad2D();

private:
	// SomWorks :D // Äõµå ±×¸®±â
	void DrawQuad(bool bUseTexture = false);

private:
	vector<FVertex2D> Vertices;
	
	FVertex2D v1;
	FVertex2D v2;
	FVertex2D v3;
	FVertex2D v4;

	FTexture2D CurrentTex;

protected:

public:

};