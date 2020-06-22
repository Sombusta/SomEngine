// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#include "Quad2D.h"
#include "Engine/SomFramework/Containers/Render/Texture/TextureParser_Bmp.h"

FQuad2D::FQuad2D() : v1(-200, 200), v2(200, 200), v3(-200, -200), v4(200, -200)
{
	v1.UV = FVector2D(0, 0);
	v2.UV = FVector2D(1, 0);
	v3.UV = FVector2D(0, 1);
	v4.UV = FVector2D(1, 1);
	
	CurrentTex = SomManager_Texture::GetInstance()->T_Test1;

	DrawQuad(false);
}

FQuad2D::FQuad2D(FVertex2D a, FVertex2D b, FVertex2D c, FVertex2D d, const FTexture2D& Tex, bool bUseTextrue) : v1(a), v2(b), v3(c), v4(d)
{
	CurrentTex = Tex;

	DrawQuad(bUseTextrue);
}

FQuad2D::~FQuad2D()
{
}

void FQuad2D::DrawQuad(bool bUseTexture)
{
	FTriangle2D MyTriangle(v1, v2, v3, CurrentTex, bUseTexture);
	FTriangle2D MyTriangle2(v2, v3, v4, CurrentTex, bUseTexture);
}