// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#include "TextureParser_Bmp.h"

ULONG* OpenBMP(char *filename, int *width, int *height)
{
	FILE* fp;
	errno_t err;

	err = fopen_s(&fp, filename, "rb");
	if (!fp) return NULL;

	BITMAPFILEHEADER bmpfh;
	size_t size = fread(&bmpfh, 1, sizeof(BITMAPFILEHEADER), fp);
	if (size != sizeof(BITMAPFILEHEADER)) return NULL;

	BITMAPINFOHEADER bmpih;
	size = fread(&bmpih, 1, sizeof(BITMAPINFOHEADER), fp);
	if (size != sizeof(BITMAPINFOHEADER)) return NULL;

	int bytePerLine = ((bmpih.biWidth * 3) + 3) &~3;
	size_t imageSize = bytePerLine * bmpih.biHeight;
	BYTE *pBmp = new BYTE[imageSize];
	if (!pBmp) return NULL;

	*width = bmpih.biWidth;
	*height = bmpih.biHeight;
	size = fread(pBmp, 1, imageSize, fp);
	if (size != imageSize)
	{
		delete[] pBmp;
		return NULL;
	}

	fclose(fp);

	ULONG *pImageBuf = new ULONG[bmpih.biWidth * bmpih.biHeight];

	for (int j = 0; j < bmpih.biHeight; j++)
	{
		for (int i = 0; i < bmpih.biWidth; i++)
		{
			int ColorIndex = bytePerLine * (bmpih.biHeight - j - 1) + (i * 3);
			BYTE BValue = pBmp[ColorIndex];
			BYTE GValue = pBmp[ColorIndex + 1];
			BYTE RValue = pBmp[ColorIndex + 2];

			int DestIndex = j * bmpih.biWidth + i;
			
			BYTE *CurrentColor = (BYTE *)(pImageBuf + DestIndex);
			pImageBuf[DestIndex] = RGB(RValue, GValue, BValue);
		}
	}

	if (pBmp)
	{
		delete[] pBmp;
	}
	return (ULONG*)pImageBuf;
}

ULONG GetPixel(int x, int width, int y, ULONG* bmp)
{
	return bmp[y * width + x];
}