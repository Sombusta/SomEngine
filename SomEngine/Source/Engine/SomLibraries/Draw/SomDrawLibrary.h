// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#pragma once

#include "Engine/Engine.h"

class FSomDrawLibrary
{
public:
	FSomDrawLibrary();
	~FSomDrawLibrary();

	// SomWorks :D // �ȼ� �׸��� �Լ�
	static void DrawPixel(int x, int y);

	// SomWorks :D // ������ �����ĸ� ������ ���۵� �� �߱� �˰�����
	static void DrawLine(Point2D Point1, Point2D Point2);

	// SomWorks :D // �극���� ���� �˰����� ���
	static void DrawLine_BresenhamAlgorithm(Point2D Point1, Point2D Point2);

	// SomWorks :D // �ﰢ�� �׸���
	static void DrawTriangle(FVector2D a, FVector2D b, FVector2D c);

	// SomWorks :D // �� �׸���
	static void DrawCircle(Point2D CenterLocation, int r);
private:

protected:

public:

};