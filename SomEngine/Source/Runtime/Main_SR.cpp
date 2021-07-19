// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#include "Main_SR.h"
#include <cstdlib>
#include <time.h>
#include <random>

Main_SR::Main_SR()
{
}

Main_SR::~Main_SR()
{
}

void Main_SR::Init()
{
	cout << "Initialize" << endl;
}

void Main_SR::Update(float DeltaTime)
{
	// 게임 로직에만 사용하는 변수
	static float moveSpeed = 100.f;
	static float scaleMin = 3.f;
	static float scaleMax = 15.f;
	static float scaleSpeed = 20.f;
	static float duration = 3.f;
	static float rotateSpeed = 180.f;

	// 경과 시간에 따른 현재 각과 이를 사용한 [0,1]값의 생성
	_CurrentTime += DeltaTime;
	_CurrentTime = FMath::FMod(_CurrentTime, duration);
	float currentRad = (_CurrentTime / duration) * FMath::TwoPI;
	float alpha = (sinf(currentRad) + 1) * 0.5f;

	// [0,1]을 활용해 주기적으로 크기를 반복하기
	_CurrentScale = FMath::Lerp(scaleMin, scaleMax, alpha);		

	_UpdateLerpValue = FMath::Lerp(0.0f, 1.0f, alpha);
}

void Main_SR::Render()
{
	static float increment = 0.001f;
	float rad = 0.f;
	static std::vector<FVector2D> hearts;
	static std::vector<FVector2D> RandomLocs;

	if (hearts.empty())
	{
		for (rad = 0.f; rad < FMath::TwoPI; rad += increment)
		{
			float sin = sinf(rad);
			float cos = cosf(rad);
			float cos2 = cosf(2 * rad);
			float cos3 = cosf(3 * rad);
			float cos4 = cosf(4 * rad);
			float x = 16.f * sin * sin * sin;
			float y = 13 * cos - 5 * cos2 - 2 * cos3 - cos4;
			hearts.push_back(FVector2D(x, y));
		}
	}

	if (RandomLocs.empty())
	{
		// Random
		std::random_device MyRandomDevice;
		std::uniform_real_distribution<float> RandomDist(-30.0f, 30.0f);

		for (auto const& v : hearts)
		{
			float RandomX = RandomDist(MyRandomDevice);
			float RandomY = RandomDist(MyRandomDevice);

			RandomLocs.push_back(FVector2D(RandomX, RandomY));
		}
	}

	static int i = 0;

	// 각 값 초기화
	rad = 0.f;
	FHSVColor hsv(0.f, 1.f, 0.85f); // 잘 보이도록 채도를 조금만 줄였음. 

	for (auto const& v : hearts)
	{
		float sin, cos;
		FMath::GetSinCos(sin, cos, _CurrentDegree);
		// FVector2D target = v * _CurrentScale;

		// 하트에 이동, 회전 값을 적용하기
		//Vector2 rotatedTarget = target;  // 코드 수정
		// FVector2D rotatedTarget(target.X * cos - target.Y * sin, target.X * sin + target.Y * cos);
		
		//rotatedTarget += _CurrentPosition;

		hsv.H += (increment * FMath::InvPI * 0.5f);

		// FSomDrawLibrary::DrawPixel(rotatedTarget.X, rotatedTarget.Y, hsv.ToLinearColor().ToColor32());

		FVector2D TargetLocation;
		TargetLocation.X = FMath::Lerp(v.X, RandomLocs[i].X, _UpdateLerpValue);
		TargetLocation.Y = FMath::Lerp(v.Y, RandomLocs[i].Y, _UpdateLerpValue);

		FSomDrawLibrary::DrawPixel((TargetLocation * _CurrentScale).ToPoint2D(), hsv.ToLinearColor().ToColor32());

		i++;

		// rad += increment;
	}

	i = 0;
}

void Main_SR::Terminate()
{
}