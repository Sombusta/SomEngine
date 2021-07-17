// Copyright (c) 2014-2021 Sombusta, All Rights Reserved.

#pragma once

#include <windows.h>

typedef unsigned char		BYTE;		// 부호 없는 8비트
typedef unsigned int		UINT32;		// 부호 없는 32비트
typedef unsigned long long	UINT64;		// 부호 없는 64비트.
typedef signed long long	INT64;	// 부호 있는 64비트.

#if defined(PLATFORM_WINDOWS)
#define FORCEINLINE __forceinline
#endif

#if !defined(FORCEINLINE)
#define FORCEINLINE inline
#endif