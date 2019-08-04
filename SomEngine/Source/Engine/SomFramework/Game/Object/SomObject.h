// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#pragma once

#include "Engine/Engine.h"

class SomObject
{
public:
	SomObject();
	~SomObject();

	// 초기화
	virtual void Init() = 0;

	// 업데이트
	virtual void Update(float DeltaTime) = 0;

	// 렌더링
	virtual void Render() = 0;

	// 삭제, 소거
	virtual void Terminate() = 0;

private:

protected:

public:

};