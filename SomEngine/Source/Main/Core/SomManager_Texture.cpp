// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#include "SomManager_Texture.h"
#include "Engine/SomFramework/Libraries/Parser/TextureParser_Bmp.h"

SomManager_Texture* SomManager_Texture::Instance = nullptr;

SomManager_Texture::SomManager_Texture()
{
}

SomManager_Texture::~SomManager_Texture()
{
}

void SomManager_Texture::CreateTexManager()
{
	if (Instance == nullptr)
	{
		Instance = new SomManager_Texture;
	
		Instance->Texture_CreateObjects();
	}
}

void SomManager_Texture::TerminateTexManager()
{
	if (Instance)
	{
		Instance->Texture_DestroyObjects();
		delete Instance;
		Instance = nullptr;
	}
}

void SomManager_Texture::Texture_CreateObjects()
{
	FSomTextureParser_BMP::OpenBMP(T_Test1, const_cast<char*>("../Extras/Test1.bmp"));
	FSomTextureParser_BMP::OpenBMP(T_Test2, const_cast<char*>("../Extras/Img.bmp"));
}

void SomManager_Texture::Texture_DestroyObjects()
{

}