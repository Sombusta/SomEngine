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
	// ���� �������� ����ϴ� ����
	static float moveSpeed = 100.f;
	static float scaleMin = 3.f;
	static float scaleMax = 15.f;
	static float scaleSpeed = 20.f;
	static float duration = 3.f;
	static float rotateSpeed = 180.f;

	// ��� �ð��� ���� ���� ���� �̸� ����� [0,1]���� ����
	_CurrentTime += DeltaTime;
	_CurrentTime = FMath::FMod(_CurrentTime, duration);
	float currentRad = (_CurrentTime / duration) * FMath::TwoPI;
	float alpha = (sinf(currentRad) + 1) * 0.5f;

	// [0,1]�� Ȱ���� �ֱ������� ũ�⸦ �ݺ��ϱ�
	_CurrentScale = FMath::Lerp(scaleMin, scaleMax, alpha);
		
}

void Main_SR::Render()
{
}

void Main_SR::Terminate()
{
}