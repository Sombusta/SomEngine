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
	
	// SomWorks :D // 렌더러 셋업
	TargetFramework = RenderFramework;
	bUseSoftRenderer = RenderFramework != nullptr ? false : true;

	// Parse the command line parameters
	int argc;
	LPWSTR* argv = CommandLineToArgvW(GetCommandLineW(), &argc);
	LocalFree(argv);

	// SomWorks :D // Initialize the window class. // 창 클래스를 등록합니다.
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

	// SomWorks :D // Instance Init // 인스턴스 핸들을 저장하고 주 창을 만듭니다.
	m_hInstance = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

	RECT windowRect = { 0, 0, static_cast<LONG>(WIN_WIDTH), static_cast<LONG>(WIN_HEIGHT) };
	AdjustWindowRect(&windowRect, WS_OVERLAPPEDWINDOW, FALSE);

	// SomWorks :D // Screen Location Default
	// CW_USEDEFAULT

	// 현재 모니터 해상도에 설정된 값을 가져옵니다.
	// 현재 설정된 해상도가 1920 X 1080이라면
	// screenWidth에는 1920이 screenHeight에는 1080이 대입됩니다.
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

	// SomWorks :D // 초기화 단계
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

	// SomWorks :D // 이전 시간
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
			// SomWorks :D // 현재 시간
			DWORD CurrentTime = timeGetTime();

			// SomWorks :D // 밀리 세컨드 단위, DeltaTime
			float ElapsedTime = (CurrentTime - PreviousTime) / 1000.f;
			
			PreviousTime = CurrentTime;

			if (bUseSoftRenderer)
			{
				// SomWorks :D // SoftRender 메인 업데이트, 향후에 DeltaTime 관련 구현해야함. 현재는 0.01로 고정
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
		// 키보드가 키가 눌렸는지 확인합니다.
	case WM_KEYDOWN:
	{
		// 키가 눌렸다면 input객체에 이 사실을 전달하여 기록하도록 합니다.
		SomManager_Input::KeyDown((unsigned int)wparam);
		return 0;
	}

	// 키보드의 눌린 키가 떼어졌는지 확인합니다.
	case WM_KEYUP:
	{
		// 키가 떼어졌다면 input객체에 이 사실을 전달하여 이 키를 해제토록합니다.
		SomManager_Input::KeyUp((unsigned int)wparam);
		return 0;
	}

	// 다른 메세지들은 사용하지 않으므로 기본 메세지 처리기에 전달합니다.
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
		// 메뉴 선택을 구문 분석합니다:
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
	case WM_COMMAND: // 응용 프로그램 메뉴를 처리합니다.
	{
		int wmId = LOWORD(wParam);
		// 메뉴 선택을 구문 분석합니다:
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
		// SomWorks :D // 인풋 매니저
		SomManager_Input::CreateInputManager();

		bIsActive = true;
	}
	break;

	case WM_PAINT: // 주 창을 그립니다.
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		// TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
		EndPaint(hWnd, &ps);
	}
	break;

	case WM_DESTROY: // 종료 메시지를 게시하고 반환합니다.
	{
		// SomWorks :D // 인풋 매니저
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

// SomWorks :D // 정보 대화 상자의 메시지 처리기입니다.
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