// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#include "Main_SR.h"

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
		
}

void Main_SR::Render()
{
}

void Main_SR::Terminate()
{
}