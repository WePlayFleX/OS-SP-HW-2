#include <Windows.h>

#define STEP 300
#define SIZE 9
#define WIDTH 300
#define HEIGHT 300

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

HINSTANCE hInstance;
HWND hwnds[SIZE];

int WINAPI WinMain(
	HINSTANCE hInst,
	HINSTANCE prevIst,
	LPSTR cmdArgs,
	int typeShow)

{
	hInstance = hInst;

	LPCWSTR classes[] = { L"FirstWindow", L"SecondWindow", L"ThirdWindow",
						L"FourthWindow", L"FifthWindow", L"SixthWindow", 
						L"SeventhWindow", L"EighthWindow", L"NinthWindow"};

	for (int i = 0; i < SIZE; i++)
	{
		WNDCLASS wndclass;

		wndclass.cbClsExtra = 0;
		wndclass.cbWndExtra = 0;
		wndclass.hInstance = hInst;
		wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
		wndclass.hCursor = LoadCursor(NULL, IDC_HAND);
		wndclass.hbrBackground = CreateSolidBrush(RGB(255, 255, 255));
		wndclass.lpszMenuName = NULL;
		wndclass.lpszClassName = classes[i];
		wndclass.style = CS_DBLCLKS;
		wndclass.lpfnWndProc = WndProc;

		RegisterClass(&wndclass);
	}

	int posX = 10;
	int posY = 10;

	for (int i = 0; i < SIZE; i++)
	{
		if (i == 3)
		{
			posX = posX - 900;
			posY = 310;
		}

		if (i == 6)
		{
			posX = posX - 900;
			posY = 610;
		}

		hwnds[i] = CreateWindow(
			classes[i],
			classes[i],
			WS_OVERLAPPEDWINDOW,
			posX + (i * STEP), posY,
			WIDTH, HEIGHT,
			NULL,
			NULL,
			hInst,
			NULL);

		if (!hwnds[i])
		{
			return -1;
		}
	}

	for (int i = 0; i < SIZE; i++)
	{
		int red = rand() % 256;
		int green = rand() % 256;
		int blue = rand() % 256;

		SetClassLong(hwnds[i], GCL_HBRBACKGROUND, (LONG)CreateSolidBrush(RGB(red, green, blue)));

		ShowWindow(hwnds[i], typeShow);
		UpdateWindow(hwnds[i]);
		Sleep(2000);
	}

	MSG msg;

	while (GetMessage(&msg, NULL, 0, 0) == TRUE)
	{
		DispatchMessage(&msg);
	}
	return 0;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_KEYDOWN:
		switch (wParam)
		{
		case MOD_CONTROL + 1:
			{
				DestroyWindow(hwnd);
			}
			break;
		case MOD_CONTROL + 2:
		{
			DestroyWindow(hwnd);
		}
		break;
		case MOD_CONTROL + 3:
		{
			DestroyWindow(hwnd);
		}
		break;
		case MOD_CONTROL + 4:
		{
			DestroyWindow(hwnd);
		}
		break;
		case MOD_CONTROL + 5:
		{
			DestroyWindow(hwnd);
		}
		break;
		case MOD_CONTROL + 6:
		{
			DestroyWindow(hwnd);
		}
		break;
		case MOD_CONTROL + 7:
		{
			DestroyWindow(hwnd);
		}
		break;
		case MOD_CONTROL + 8:
		{
			DestroyWindow(hwnd);
		}
		break;
		case MOD_CONTROL + 9:
		{
			DestroyWindow(hwnd);
		}
		break;
		}
	break;
	case WM_RBUTTONDOWN:
	{
		for (int i = 0; i < SIZE; i++)
		{
			if (hwnds[i] == hwnd)
			{
				SetTimer(hwnd, 1000 + i, 1000, NULL);
			}
		}
	}
	break;


	case WM_LBUTTONDOWN:
	{
		for (int i = 0; i < SIZE; i++)
		{
			if (hwnds[i] == hwnd)
			{
				KillTimer(hwnd, 1000 + i);
			}
		}
	}
	break;


	case WM_TIMER:
	{
		int red = rand() % 256;
		int green = rand() % 256;
		int blue = rand() % 256;

		SetClassLong(hwnd, GCL_HBRBACKGROUND, (LONG)CreateSolidBrush(RGB(red, green, blue)));

		InvalidateRect(hwnd, NULL, TRUE);
	}
	break;


	case WM_DESTROY:
	{
		/*PostQuitMessage(0);*/
	}
	break;

	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}
	return TRUE;
}
