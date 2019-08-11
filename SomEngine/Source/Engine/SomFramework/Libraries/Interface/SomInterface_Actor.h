// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#pragma once

class ISomInterface_Actor
{
public:
	ISomInterface_Actor();
	virtual ~ISomInterface_Actor();

	virtual void SetActive(bool bActivate = false) = 0;
};