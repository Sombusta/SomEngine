// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#pragma once

#include "Engine/Engine.h"

class FTriangle2D
{
public:
	FTriangle2D();
	FTriangle2D(FVertex2D a, FVertex2D b, FVertex2D c, bool bFillTriangle = false);
	FTriangle2D(FVertex2D a, FVertex2D b, FVertex2D c, const FTexture2D& Tex, bool bUseTextrue = true);
	~FTriangle2D();

private:
	// SomWorks :D // �ﰢ�� ���ؽ� ����
	void VertexSort(FVertex2D a, FVertex2D b, FVertex2D c);
	
	// SomWorks :D // �ﰢ�� �ʱ�ȭ
	void TriangleInitialize();

	// SomWorks :D // �ﰢ�� �����߽� ��ǥ BarycentricCoordinate
	FVector GetVertexWeight(const FVector& Value) const;

	// SomWorks :D // �����߽� ��ǥ�� ����� ���� ǥ��
	FColor GetVertexWeightColor(const FVector2D& Value) const;

	// SomWorks :D // �ﰢ�� �׸���
	void DrawTriangle(bool bFillTriangle = false, bool bUseTexture = false);

	// SomWorks :D // �ﰢ�� ä���
	void FillTriangle(bool bUseTexture = false);

public:
	vector<FVertex2D> Vertices;
	
	FVertex2D TopVertex;
	FVertex2D MiddleVertex;
	FVertex2D BottomVertex;
	FVector2D FourthVertex;

	FVector2D V_u;
	FVector2D V_v;

	float DotUU = 0.0f;
	float DotVV = 0.0f;
	float DotUV = 0.0f;
	float DotVU = 0.0f;
	float WeightDenominator = 0.0f;

	FTexture2D CurrentTex;

protected:

public:
	bool bUseBarycentricCoordinate = false;
	
};