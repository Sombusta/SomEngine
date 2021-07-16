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

protected:

public:
};