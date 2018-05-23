#include <windows.h>
#include "resource.h"
#include <vector>
using namespace std;

// Прототип функции DlgProc.
BOOL CALLBACK DlgProc(HWND, UINT, WPARAM, LPARAM);



int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrev, LPSTR lpszCmdLine, int nCmdShow)
{

	MSG msg;	// структура.
				// создаём главное окно приложения на основе немодального диалога
	HWND hDialog = CreateDialog(hInst, MAKEINTRESOURCE(IDD_DIALOG_Main), NULL, DlgProc);
	// Отображаем окно	
	ShowWindow(hDialog, nCmdShow);


	//Запускаем цикл обработки сообщений
	while (GetMessage(&msg, 0, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}



BOOL CALLBACK DlgProc(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam)
{



	switch (uMessage)
	{
	case WM_CLOSE:
		// Закрываем немодальный диалог.
		DestroyWindow(hWnd); // разрушаем окно.
		PostQuitMessage(0); // останавливаем цикл обработки сообщений.
		return TRUE;

	





	}
	return FALSE;
}