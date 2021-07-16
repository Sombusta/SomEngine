// Copyright (c) 2014-2021 Sombusta, All Rights Reserved.

#pragma once

#include <windows.h>

#include <cassert>

#include <math.h>

#include <intrin.h>

#include <iostream>

#include <string>
#include <vector>
#include <iterator>

typedef unsigned char		BYTE;		// 부호 없는 8비트
typedef unsigned int		UINT32;		// 부호 없는 32비트
typedef unsigned long long	UINT64;		// 부호 없는 64비트.
typedef signed long long	INT64;	// 부호 있는 64비트.

#define SMALL_NUMBER		(1.e-8f)
#define KINDA_SMALL_NUMBER	(1.e-4f)

#if defined(PLATFORM_WINDOWS)
#define FORCEINLINE __forceinline
#endif

#if !defined(FORCEINLINE)
#define FORCEINLINE inline
#endif

// SomWorks :D // Math Headers
#include "MathUtility.h"
#include "Point2D.h"
#include "Vector2D.h"
#include "Vector.h"
#include "Vector4.h"
#include "Matrix2D.h"
#include "Matrix3D.h"
#include "Matrix.h"
#include "Color32.h"
#include "LinearColor.h"
#include "Vertex.h"