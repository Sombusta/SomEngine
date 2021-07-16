// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#pragma once

#include "Engine/Engine.h"

class SR_Test1 : public GameObject
{
public:
	SR_Test1();
	~SR_Test1();

	virtual void Init() override;
	virtual void Update(float DeltaTime) override;
	virtual void Render() override;
	virtual void Terminate() override;

private:
	vector<FPoint2D> Points;

protected:

public:
};