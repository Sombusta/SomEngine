// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#pragma once

#include "Engine/Engine.h"

class GameObject : public ISomInterface_Actor
{
public:
	GameObject();
	virtual ~GameObject();

	// 초기화
	virtual void Init() = 0;

	// 업데이트
	virtual void Update(float DeltaTime) = 0;

	// 렌더링
	virtual void Render() = 0;

	// 삭제, 소거
	virtual void Terminate() = 0;

	// SomWorks :D // SomInterface
	virtual void SetActive(bool bActivate);
		
private:
	bool bIsActive = false;

protected:

public:

};