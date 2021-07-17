// Copyright (c) 2014-2021 Sombusta, All Rights Reserved.

#pragma once

typedef unsigned char		BYTE;		// ��ȣ ���� 8��Ʈ
typedef unsigned int		UINT32;		// ��ȣ ���� 32��Ʈ
typedef unsigned long long	UINT64;		// ��ȣ ���� 64��Ʈ.
typedef signed long long	INT64;	// ��ȣ �ִ� 64��Ʈ.

#define SMALL_NUMBER		(1.e-8f)
#define KINDA_SMALL_NUMBER	(1.e-4f)

#if defined(PLATFORM_WINDOWS)
// #include "Windows/WindowsPlatform.h"
#define FORCEINLINE __forceinline
#endif

#if !defined(FORCEINLINE)
#define FORCEINLINE inline
#endif