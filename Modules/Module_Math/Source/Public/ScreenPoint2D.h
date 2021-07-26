// Copyright (c) 2014-2021 Sombusta, All Rights Reserved.

#pragma once

// SomWorks :D // ScreenPoint2D
typedef struct ScreenPoint
{
public:
	int X = 0;
	int Y = 0;

public:
	FORCEINLINE constexpr ScreenPoint() = default;
	FORCEINLINE explicit constexpr ScreenPoint(int InX, int InY) : X(InX), Y(InY) { }
	FORCEINLINE explicit constexpr ScreenPoint(float InX, float InY) : X(FMath::FloorToInt(InX)), Y(FMath::FloorToInt(InY)) { }
	FORCEINLINE explicit constexpr ScreenPoint(const FVector2D& InPos) : ScreenPoint(InPos.X, InPos.Y) {}

	constexpr ScreenPoint GetHalf() const { return ScreenPoint(FMath::FloorToInt(0.5f * X), FMath::FloorToInt(0.5f * Y)); }
	constexpr float AspectRatio() const { return (float)X / (float)Y; } // Y축 기준으로 측정
	FORCEINLINE constexpr bool HasZero() const { return (X == 0 || Y == 0); }

	FORCEINLINE static constexpr ScreenPoint ToScreenCoordinate(const ScreenPoint & InScreenSize, const FVector2D& InPos)
	{
		return ScreenPoint(InPos.X + InScreenSize.X * 0.5f, -InPos.Y + InScreenSize.Y * 0.5f);
	}

	FORCEINLINE FVector2D ToCartesianCoordinate(const ScreenPoint & InScreenSize)
	{
		return FVector2D(X - InScreenSize.X * 0.5f + 0.5f, -(Y + 0.5f) + InScreenSize.Y * 0.5f);
	}
	
	FORCEINLINE constexpr ScreenPoint operator-(const ScreenPoint & InPoint) const;
	FORCEINLINE constexpr ScreenPoint operator+(const ScreenPoint & InPoint) const;

} FScreenPoint2D;

FORCEINLINE constexpr ScreenPoint ScreenPoint::operator-(const ScreenPoint& InPoint) const
{
	return ScreenPoint(X - InPoint.X, Y - InPoint.Y);
}

FORCEINLINE constexpr ScreenPoint ScreenPoint::operator+(const ScreenPoint& InPoint) const
{
	return ScreenPoint(X + InPoint.X, Y + InPoint.Y);
}