// Copyright (c) 2014-2021 Sombusta, All Rights Reserved.

#pragma once

typedef struct FHSVColor
{
public:
	float H = 0.f;
	float S = 1.f;
	float V = 1.f;

public:
	FORCEINLINE FHSVColor() = default;
	FORCEINLINE FHSVColor(float InH, float InS, float InV) : H(InH), S(InS), V(InV) {}
	FORCEINLINE FLinearColor ToLinearColor() const
	{
		float r = 0.f, g = 0.f, b = 0.f;

		int i = FMath::FloorToInt(H * 6.f);
		float f = H * 6.f - i;
		float p = V * (1.f - S);
		float q = V * (1 - f * S);
		float t = V * (1 - (1 - f) * S);

		switch (i % 6) {
		case 0: r = V, g = t, b = p; break;
		case 1: r = q, g = V, b = p; break;
		case 2: r = p, g = V, b = t; break;
		case 3: r = p, g = q, b = V; break;
		case 4: r = t, g = p, b = V; break;
		case 5: r = V, g = p, b = q; break;
		}

		return FLinearColor(r, g, b);
	}
} FHSVColor;