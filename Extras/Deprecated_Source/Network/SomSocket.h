// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#pragma once

#pragma comment(lib, "ws2_32")
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <WinSock2.h>

class FSomSocket
{
public:
	FSomSocket();
	~FSomSocket();

	void CreateSocket();
	void DestroySocket();

	bool ConnectSocket();

	void err_quit(const char* msg);

private:
	static FSomSocket* Instance;

	// 윈속 초기화
	WSADATA wsa;

	// Socket()
	SOCKET tcp_sock;

public:
	static FORCEINLINE FSomSocket* GetInstance() { return Instance; }
};