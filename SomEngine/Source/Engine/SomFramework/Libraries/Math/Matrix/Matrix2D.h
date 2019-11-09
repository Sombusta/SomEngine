// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#pragma once

#include "../Vector/Point2D.h"
#include "../Vector/Vector2D.h"

typedef struct FMatrix2x2
{
public:
	union
	{
		struct
		{
			float _11, _12;
			float _21, _22;
		};
		float M[2][2];
	};

public:
	FMatrix2x2() : M{ 0.0f } {}

} FMatrix2D;