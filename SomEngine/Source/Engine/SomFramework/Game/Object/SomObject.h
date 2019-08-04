// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#pragma once

#include "Engine/Engine.h"

class SomObject
{
public:
	SomObject();
	~SomObject();

	// �ʱ�ȭ
	virtual void Init() = 0;

	// ������Ʈ
	virtual void Update(float DeltaTime) = 0;

	// ������
	virtual void Render() = 0;

	// ����, �Ұ�
	virtual void Terminate() = 0;

private:

protected:

public:

};