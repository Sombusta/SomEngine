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
			// SomWorks :D // ���� ����
		}
		else
		{
			// SomWorks :D // ���� ����
		}
	}
	else
	{
		// SomWorks :D // �̹� �����Ǿ� ���� ��
	}
}

void FSomSocket::DestroySocket()
{
	if (Instance)
	{
		// closet Socket()
		closesocket(tcp_sock);
		MessageBox(NULL, L"TCP ���� �ݱ� ����", L"�˸�", MB_OK);

		// ���� ����
		WSACleanup();
		MessageBox(NULL, L"TCP ���� ���� ����", L"�˸�", MB_OK);

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

	MessageBox(NULL, L"���� �ʱ�ȭ ����", L"�˸�", MB_OK);

	tcp_sock = socket(AF_INET, SOCK_STREAM, 0); // TCP ���
	
	if (tcp_sock == INVALID_SOCKET)
	{
		err_quit("socket()");
	}

	MessageBox(NULL, L"TCP ���� ���� ����", L"�˸�", MB_OK);

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