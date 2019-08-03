// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#pragma once

#include "Engine/Engine.h"

class SR_Sample : public SomObject
{
public:
	SR_Sample();
	~SR_Sample();

	virtual void Init() override;
	virtual void Update(float DeltaTime = 0.0f) override;
	virtual void Render() override;

private:

protected:

public:
};