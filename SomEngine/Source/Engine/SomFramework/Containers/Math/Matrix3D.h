// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#pragma once

#include "Vector.h"

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

	// SomWorks :D // º¤ÅÍ ¼±Çü º¯È¯
	FORCEINLINE FVector operator*(const FVector& Value) const
	{
		FVector Result;

		Result.X = (_11 * Value.X) + (_12 * Value.Y) + (_13 * Value.Z);
		Result.Y = (_21 * Value.X) + (_22 * Value.Y) + (_23 * Value.Z);
		Result.Z = (_31 * Value.X) + (_32 * Value.Y) + (_33 * Value.Z);

		return Result;
	}

	// SomWorks :D // Çà·Ä°ö
	FORCEINLINE FMatrix3x3 operator*(const FMatrix3x3& Value) const
	{
		FMatrix3x3 Result;

		// SomWorks :D // X Axis
		Result._11 = (this->_11 * Value._11) + (this->_12 * Value._21) + (this->_13 * Value._31);
		Result._21 = (this->_21 * Value._11) + (this->_22 * Value._21) + (this->_23 * Value._31);
		Result._31 = (this->_31 * Value._11) + (this->_32 * Value._21) + (this->_33 * Value._31);

		// SomWorks :D // Y Axis
		Result._12 = (this->_11 * Value._12) + (this->_12 * Value._22) + (this->_13 * Value._32);
		Result._22 = (this->_21 * Value._12) + (this->_22 * Value._22) + (this->_23 * Value._32);
		Result._32 = (this->_31 * Value._12) + (this->_32 * Value._22) + (this->_33 * Value._32);

		// SomWorks :D // Z Axis
		Result._13 = (this->_11 * Value._13) + (this->_12 * Value._23) + (this->_13 * Value._33);
		Result._23 = (this->_21 * Value._13) + (this->_22 * Value._23) + (this->_23 * Value._33);
		Result._33 = (this->_31 * Value._13) + (this->_32 * Value._23) + (this->_33 * Value._33);

		return Result;
	}

} FMatrix3D;