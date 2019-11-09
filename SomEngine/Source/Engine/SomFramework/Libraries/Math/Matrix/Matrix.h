// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#pragma once

#include "../Vector/Point2D.h"
#include "../Vector/Vector2D.h"
#include "../Vector/Vector.h"
#include "../Vector/Vector4.h"

typedef struct FMatrix4x4
{
public:
	union
	{
		struct
		{
			float _11, _12, _13, _14;
			float _21, _22, _23, _24;
			float _31, _32, _33, _34;
			float _41, _42, _43, _44;
		};
		float M[4][4];
	};

public:

} FMatrix;