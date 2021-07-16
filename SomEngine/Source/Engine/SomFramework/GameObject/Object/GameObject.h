// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#pragma once

#include "Engine/Engine.h"

class GameObject : public ISomInterface_Actor
{
public:
	GameObject();
	virtual ~GameObject();

	// �ʱ�ȭ
	virtual void Init() = 0;

	// ������Ʈ
	virtual void Update(float DeltaTime) = 0;

	// ������
	virtual void Render() = 0;

	// ����, �Ұ�
	virtual void Terminate() = 0;

	// SomWorks :D // SomInterface
	virtual void SetActive(bool bActivate);
		
private:
	bool bIsActive = false;

protected:

public:

};