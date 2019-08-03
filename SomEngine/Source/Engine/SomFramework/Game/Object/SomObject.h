// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#pragma once

#include "Engine/Engine.h"

class SomObject
{
public:
	SomObject();
	~SomObject();

	virtual void Init() = 0;
	virtual void Update(float DeltaTime) = 0;
	virtual void Render() = 0;
private:

protected:

public:

};