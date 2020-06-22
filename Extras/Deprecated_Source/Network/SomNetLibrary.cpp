// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#include "SomNetLibrary.h"
#include "SomSocket.h"

FSomNetLibrary::FSomNetLibrary()
{

}

FSomNetLibrary::~FSomNetLibrary()
{

}

void FSomNetLibrary::CreateSocket()
{
	FSomSocket::GetInstance()->CreateSocket();
}

void FSomNetLibrary::ReleaseSocket()
{
	FSomSocket::GetInstance()->DestroySocket();
}