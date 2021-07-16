// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#pragma once

#include "Vector2D.h"

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

	// SomWorks :D // º¤ÅÍ ¼±Çü º¯È¯
	FORCEINLINE FVector2D operator*(const FVector2D& Value) const
	{
		FVector2D Result;

		Result.X = (_11 * Value.X) + (_12 * Value.Y);
		Result.Y = (_21 * Value.X) + (_22 * Value.Y);

		return Result;
	}

	// SomWorks :D // Çà·Ä°ö
	FORCEINLINE FMatrix2x2 operator*(const FMatrix2x2& Value) const
	{
		FMatrix2x2 Result;

		// SomWorks :D // X Axis
		Result._11 = (this->_11 * Value._11) + (this->_12 * Value._21);
		Result._21 = (this->_21 * Value._11) + (this->_22 * Value._21);

		// SomWorks :D // Y Axis
		Result._12 = (this->_11 * Value._12) + (this->_12 * Value._22);
		Result._22 = (this->_21 * Value._12) + (this->_22 * Value._22);
		
		return Result;
	}

} FMatrix2D;