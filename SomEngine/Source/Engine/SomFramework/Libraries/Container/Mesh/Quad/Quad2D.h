// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#pragma once

#include "Engine/Engine.h"

class FQuad2D
{
public:
	FQuad2D();
	FQuad2D(FVector2D a, FVector2D b, bool bFillQuad = false);
	FQuad2D(const FTexture2D& Tex, char* FileName);
	~FQuad2D();

private:
	// SomWorks :D // ���� ���ؽ� ����
	void VertexSort(FVector2D a, FVector2D b);

	// SomWorks :D // ���� �ʱ�ȭ
	void QuadInitialize();

	// SomWorks :D // ���� �����߽� ��ǥ BarycentricCoordinate
	FVector2D GetVertexWeight(const FVector2D& Value) const;

	// SomWorks :D // �����߽� ��ǥ�� ����� ���� ǥ��
	FColor GetVertexWeightColor(const FVector2D& Value) const;

	// SomWorks :D // ���� �׸���
	void DrawQuad(bool bFillQuad = false);

	// SomWorks :D // ���� ä���
	void FillQuad();

private:
	FVector2D StartVertex;
	FVector2D EndVertex;

	FVector2D StartVertex_End;
	FVector2D EndVertex_Start;

	vector<FVector2D> Vertices;

	FVector2D V_u;
	FVector2D V_v;

	float DotUU;
	float DotVV;
	float DotUV;
	float DotVU;
	float WeightDenominator;

	FTexture2D CurrentTex;

protected:

public:
	bool bUseBarycentricCoordinate = false;

};