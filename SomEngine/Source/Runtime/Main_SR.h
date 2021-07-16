// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#pragma once

#include "Engine/Engine.h"

class Main_SR : public GameObject
{
public:
	Main_SR();
	~Main_SR();

	virtual void Init() override;
	virtual void Update(float DeltaTime) override;
	virtual void Render() override;
	virtual void Terminate() override;

private:
	vector<FPoint2D> Points;

	// 로직 구현을 위한 멤버 변수
	float _CurrentScale = 5.f;
	float _CurrentTime = 0.f;
	float _CurrentDegree = 0.f;
	FVector2D _CurrentPosition = FVector2D::Zero;

protected:

public:
};