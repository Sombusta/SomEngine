// Copyright (c) 2014-2020 Sombusta, All Rights Reserved.

#include "Win32Application.h"
#include "Engine/SomFramework/Rendering/Core/SomFramework.h"
#include "Engine/SomFramework/Rendering/DX11/SomFramework_DX11.h"

HWND Win32Application::m_hwnd = nullptr;
HINSTANCE Win32Application::m_hInstance = nullptr;
bool Win32Application::bIsActive = false;
SomFramework* Win32Application::TargetFramework = nullptr;
bool Win32Application::bUseSoftRenderer = true;

INT_PTR CALLBACK About(HWND, UINT, WPARAM, LPARAM);

int Win32Application::Run(HINSTANCE hInstance, int nCmdShow, SomFramework* RenderFramework)
{
	m_hInstance = hInstance;
	
	// SomWorks :D // ������ �¾�
	TargetFramework = RenderFramework;
	bUseSoftRenderer = RenderFramework != nullptr ? false : true;

	// Parse the command line parameters
	int argc;
	LPWSTR* argv = CommandLineToArgvW(GetCommandLineW(), &argc);
	LocalFree(argv);

	// SomWorks :D // Initialize the window class. // â Ŭ������ ����մϴ�.
	WNDCLASSEX windowClass = { 0 };
	windowClass.cbSize = sizeof(WNDCLASSEX);
	windowClass.style = CS_HREDRAW | CS_VREDRAW;
	windowClass.lpfnWndProc = WindowProc;
	windowClass.cbClsExtra = 0;
	windowClass.cbWndExtra = 0;
	windowClass.hInstance = hInstance;
	windowClass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_SOMENGINE));
	windowClass.hCursor = LoadCursor(nullptr, IDC_ARROW);
	windowClass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	windowClass.lpszMenuName = MAKEINTRESOURCEW(IDC_SOMENGINE);
	windowClass.lpszClassName = WIN_TITLE;
	windowClass.hIconSm = LoadIcon(windowClass.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	RegisterClassEx(&windowClass);

	// SomWorks :D // Instance Init // �ν��Ͻ� �ڵ��� �����ϰ� �� â�� ����ϴ�.
	m_hInstance = hInstance; // �ν��Ͻ� �ڵ��� ���� ������ �����մϴ�.

	RECT windowRect = { 0, 0, static_cast<LONG>(WIN_WIDTH), static_cast<LONG>(WIN_HEIGHT) };
	AdjustWindowRect(&windowRect, WS_OVERLAPPEDWINDOW, FALSE);

	// SomWorks :D // Screen Location Default
	// CW_USEDEFAULT

	// ���� ����� �ػ󵵿� ������ ���� �����ɴϴ�.
	// ���� ������ �ػ󵵰� 1920 X 1080�̶��
	// screenWidth���� 1920�� screenHeight���� 1080�� ���Ե˴ϴ�.
	int ScreenWidth = GetSystemMetrics(SM_CXSCREEN);
	int ScreenHeight = GetSystemMetrics(SM_CYSCREEN);
	
	// Create the window and store a handle to it.
	m_hwnd = CreateWindow(
		WIN_TITLE,
		WIN_TITLE,
		WS_OVERLAPPEDWINDOW,
		(ScreenWidth - WIN_WIDTH) / 2,
		(ScreenHeight - WIN_HEIGHT) / 2,
		windowRect.right - windowRect.left,
		windowRect.bottom - windowRect.top,
		nullptr,        // We have no parent window.
		nullptr,        // We aren't using menus.
		hInstance,
		nullptr);

	// SomWorks :D // �ʱ�ȭ �ܰ�
	if (bUseSoftRenderer)
	{
		// SomWorks :D // SoftRender GDI Initialize
		SomFramework_SR::InitGDI(m_hwnd);
	}
	else
	{
		TargetFramework->OnInit(m_hwnd);
	}

	ShowWindow(m_hwnd, nCmdShow);
	UpdateWindow(m_hwnd);
	   
	// SomWorks :D // Main sample loop.
	MSG msg = {};

	// SomWorks :D // ���� �ð�
	DWORD PreviousTime = timeGetTime();

	while (msg.message != WM_QUIT)
	{
		// Process any messages in the queue.
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else if (bIsActive)
		{
			// SomWorks :D // ���� �ð�
			DWORD CurrentTime = timeGetTime();

			// SomWorks :D // �и� ������ ����, DeltaTime
			float ElapsedTime = (CurrentTime - PreviousTime) / 1000.f;
			
			PreviousTime = CurrentTime;

			if (bUseSoftRenderer)
			{
				// SomWorks :D // SoftRender ���� ������Ʈ, ���Ŀ� DeltaTime ���� �����ؾ���. ����� 0.01�� ����
				SomFramework_SR::UpdateGDI(0.01f);
			}
			else
			{
				TargetFramework->OnUpdate(0.01f);
				TargetFramework->OnRender();
			}
		}
		else
		{
			WaitMessage();
		}
	}

	if (bUseSoftRenderer)
	{
		// SomWorks :D // SoftRender GDI Release
		SomFramework_SR::ReleaseGDI(m_hwnd);
	}
	else
	{
		TargetFramework->OnDestroy(m_hwnd);
	}

	// Return this part of the WM_QUIT message to Windows.
	return static_cast<char>(msg.wParam);
}

LRESULT CALLBACK Win32Application::MessageHandler(HWND hwnd, UINT umsg, WPARAM wparam, LPARAM lparam)
{
	switch (umsg)
	{
		// Ű���尡 Ű�� ���ȴ��� Ȯ���մϴ�.
	case WM_KEYDOWN:
	{
		// Ű�� ���ȴٸ� input��ü�� �� ����� �����Ͽ� ����ϵ��� �մϴ�.
		SomManager_Input::KeyDown((unsigned int)wparam);
		return 0;
	}

	// Ű������ ���� Ű�� ���������� Ȯ���մϴ�.
	case WM_KEYUP:
	{
		// Ű�� �������ٸ� input��ü�� �� ����� �����Ͽ� �� Ű�� ��������մϴ�.
		SomManager_Input::KeyUp((unsigned int)wparam);
		return 0;
	}

	// �ٸ� �޼������� ������� �����Ƿ� �⺻ �޼��� ó���⿡ �����մϴ�.
	default:
	{
		return DefWindowProc(hwnd, umsg, wparam, lparam);
	}
	}
}

// Main message handler for the sample.
LRESULT CALLBACK Win32Application::WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
/*
	switch (message)
	{
	case WM_CREATE:
	{
		// Save the DXSample* passed in to CreateWindow.
		LPCREATESTRUCT pCreateStruct = reinterpret_cast<LPCREATESTRUCT>(lParam);
		SetWindowLongPtr(hWnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(pCreateStruct->lpCreateParams));
	}
	return 0;

	case WM_COMMAND:
	{
		int wmId = LOWORD(wParam);
		// �޴� ������ ���� �м��մϴ�:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(m_hInstance, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
					default:
						return DefWindowProc(hWnd, message, wParam, lParam);
		}
	}
	return 0;

	case WM_KEYDOWN:
		return 0;

	case WM_KEYUP:
		return 0;

	case WM_PAINT:
		return 0;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	// Handle any messages the switch statement didn't.
	return DefWindowProc(hWnd, message, wParam, lParam);*/

	switch (message)
	{
	case WM_COMMAND: // ���� ���α׷� �޴��� ó���մϴ�.
	{
		int wmId = LOWORD(wParam);
		// �޴� ������ ���� �м��մϴ�:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(m_hInstance, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
	}
	break;

	case WM_CREATE:
	{
		// SomWorks :D // ��ǲ �Ŵ���
		SomManager_Input::CreateInputManager();

		bIsActive = true;
	}
	break;

	case WM_PAINT: // �� â�� �׸��ϴ�.
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		// TODO: ���⿡ hdc�� ����ϴ� �׸��� �ڵ带 �߰��մϴ�...
		EndPaint(hWnd, &ps);
	}
	break;

	case WM_DESTROY: // ���� �޽����� �Խ��ϰ� ��ȯ�մϴ�.
	{
		// SomWorks :D // ��ǲ �Ŵ���
		SomManager_Input::TerminateInputManager();

		bIsActive = false;

		PostQuitMessage(0);
	}
	break;

	default:
		return MessageHandler(hWnd, message, wParam, lParam);
	}
	return 0;
}

// SomWorks :D // ���� ��ȭ ������ �޽��� ó�����Դϴ�.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}