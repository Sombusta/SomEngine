// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#pragma once

#include "Engine/Engine.h"

class FTriangle2D
{
public:
	FTriangle2D();
	FTriangle2D(FVector2D a, FVector2D b, FVector2D c, bool bFillTriangle = false);
	~FTriangle2D();

private:
	// SomWorks :D // �ﰢ�� ���ؽ� ����
	void VertexSort(FVector2D a, FVector2D b, FVector2D c);

	// SomWorks :D // �ﰢ�� �ʱ�ȭ
	void TriangleInitialize();

	// SomWorks :D // �ﰢ�� �����߽� ��ǥ BarycentricCoordinate
	FVector2D GetVertexWeight(const FVector2D& Value) const;

	// SomWorks :D // �����߽� ��ǥ�� ����� ���� ǥ��
	FColor GetVertexWeightColor(const FVector2D& Value) const;

	// SomWorks :D // �ﰢ�� �׸���
	void DrawTriangle(bool bFillTriangle = false);

	// SomWorks :D // �ﰢ�� ä���
	void FillTriangle();

private:
	FVector2D TopVertex;
	FVector2D MiddleVertex;
	FVector2D BottomVertex;
	FVector2D FourthVertex;

	vector<FVector2D> Vertices;

	FVector2D V_u;
	FVector2D V_v;

	float DotUU;
	float DotVV;
	float DotUV;
	float DotVU;
	float WeightDenominator;

protected:

public:
	bool bUseBarycentricCoordinate = true;
	
};