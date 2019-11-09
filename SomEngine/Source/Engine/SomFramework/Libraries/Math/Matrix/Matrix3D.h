// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#pragma once

#include "../Vector/Point2D.h"
#include "../Vector/Vector2D.h"
#include "../Vector/Vector.h"

typedef struct FMatrix3x3
{
public:
	union
	{
		struct
		{
			float _11, _12, _13;
			float _21, _22, _23;
			float _31, _32, _33;
		};
		float M[3][3];
	};

public:

} FMatrix3D;