// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#include "TextureParser_Bmp.h"

FSomTextureParser_BMP::FSomTextureParser_BMP()
{
}

FSomTextureParser_BMP::~FSomTextureParser_BMP()
{
}

bool FSomTextureParser_BMP::OpenBMP(FTexture2D& TargetTexture, char *filename)
{
	FILE* fp;
	errno_t err;

	err = fopen_s(&fp, filename, "rb");
	if (!fp)
	{
		err = fopen_s(&fp, "Source/Engine/Resource/NoTexture.bmp", "rb");
		if(!fp)	return false;
	}		

	BITMAPFILEHEADER bmpfh;
	size_t size = fread(&bmpfh, 1, sizeof(BITMAPFILEHEADER), fp);
	if (size != sizeof(BITMAPFILEHEADER)) return false;

	BITMAPINFOHEADER bmpih;
	size = fread(&bmpih, 1, sizeof(BITMAPINFOHEADER), fp);
	if (size != sizeof(BITMAPINFOHEADER)) return false;

	int bytePerLine = ((bmpih.biWidth * 3) + 3) &~3;
	size_t imageSize = bytePerLine * bmpih.biHeight;
	BYTE *pBmp = new BYTE[imageSize];
	if (!pBmp) return false;

	TargetTexture.Width = bmpih.biWidth;
	TargetTexture.Height = bmpih.biHeight;
	size = fread(pBmp, 1, imageSize, fp);
	if (size != imageSize)
	{
		delete[] pBmp;
		return false;
	}

	fclose(fp);

	// SomWorks :D // 텍스처 버퍼
	TargetTexture.TexBuffer = new FColor[bmpih.biWidth * bmpih.biHeight]; // ULONG* pImageBuf = new ULONG[bmpih.biWidth * bmpih.biHeight];

	for (int j = 0; j < bmpih.biHeight; j++)
	{
		for (int i = 0; i < bmpih.biWidth; i++)
		{
			int ColorIndex = bytePerLine * (bmpih.biHeight - j - 1) + (i * 3);
			BYTE BValue = pBmp[ColorIndex];
			BYTE GValue = pBmp[ColorIndex + 1];
			BYTE RValue = pBmp[ColorIndex + 2];

			int DestIndex = j * bmpih.biWidth + i;

			// BYTE* CurrentColor = (BYTE*)(pImageBuf + DestIndex);
			// pImageBuf[DestIndex] = RGB(RValue, GValue, BValue);
			TargetTexture.TexBuffer[DestIndex] = FColor(RValue, GValue, BValue);
		}
	}

	if (pBmp)
	{
		delete[] pBmp;
	}

	return true; // return (ULONG*)pImageBuf;
}

FColor FSomTextureParser_BMP::GetPixel(int x, int y, FTexture2D& bmp)
{
	int Result_X = FSomMathLibrary::Clamp(x, 0, bmp.Width - 1);
	int Result_Y = FSomMathLibrary::Clamp(y, 0, bmp.Height - 1);

	// return bmp.TexBuffer[y * width + x];
	return bmp.TexBuffer[Result_X + Result_Y * bmp.Width];
}