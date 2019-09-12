// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#include "SomSocket.h"

FSomSocket* FSomSocket::Instance = nullptr;

FSomSocket::FSomSocket()
{

}

FSomSocket::~FSomSocket()
{

}

void FSomSocket::CreateSocket()
{
	if (Instance == nullptr)
	{
		Instance = new FSomSocket;

		if (Instance->ConnectSocket())
		{
			// SomWorks :D // 생성 성공
		}
		else
		{
			// SomWorks :D // 생성 실패
		}
	}
	else
	{
		// SomWorks :D // 이미 생성되어 있을 때
	}
}

void FSomSocket::DestroySocket()
{
	if (Instance)
	{
		// closet Socket()
		closesocket(tcp_sock);
		MessageBox(NULL, L"TCP 소켓 닫기 성공", L"알림", MB_OK);

		// 윈속 종료
		WSACleanup();
		MessageBox(NULL, L"TCP 소켓 종료 성공", L"알림", MB_OK);

		delete Instance;
		Instance = nullptr;
	}
}

bool FSomSocket::ConnectSocket()
{
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		return false;
	}

	MessageBox(NULL, L"윈속 초기화 성공", L"알림", MB_OK);

	tcp_sock = socket(AF_INET, SOCK_STREAM, 0); // TCP 방식
	
	if (tcp_sock == INVALID_SOCKET)
	{
		err_quit("socket()");
	}

	MessageBox(NULL, L"TCP 소켓 생성 성공", L"알림", MB_OK);

	return true;
}

void FSomSocket::err_quit(const char* msg)
{
	LPVOID lpMsgBuf;

	FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, WSAGetLastError(),
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPTSTR)& lpMsgBuf, 0, NULL);

	MessageBox(NULL, (LPCTSTR)lpMsgBuf, (LPCWSTR)msg, MB_ICONERROR);
	LocalFree(lpMsgBuf);
	exit(1);
}