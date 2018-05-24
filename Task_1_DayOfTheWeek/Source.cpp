#include <windows.h>
#include "resource.h"
#include <vector>
using namespace std;

HWND hEditControl_Err;

BOOL CALLBACK DlgProc(HWND, UINT, WPARAM, LPARAM);

bool CheckFieldsCompletion();
bool CheckingDateForCorrectness();

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrev, LPSTR lpszCmdLine, int nCmdShow)
{

	MSG msg;
	HWND hDialog = CreateDialog(hInst, MAKEINTRESOURCE(IDD_DIALOG_Main), NULL, DlgProc);
	ShowWindow(hDialog, nCmdShow);


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
		DestroyWindow(hWnd);
		PostQuitMessage(0);
		return TRUE;
	
	case WM_INITDIALOG:
		hEditControl_Err = GetDlgItem(hWnd, IDC_STATIC_MessageOfCorrect);
		return true;
	case WM_COMMAND:

		if (HIWORD(wParam) == EN_CHANGE)
		{
			SetWindowText(hEditControl_Err, NULL);
		}

		if (LOWORD(wParam) == IDC_BUTTON_Identify){
			if (CheckFieldsCompletion() && CheckingDateForCorrectness())
			{
				// высчитать день недели
				// указать день недели.
			}
			else
			{
				SetWindowText(hEditControl_Err, L"Дата не корректна!");
			}
		}
	
		return true;


	}
	return FALSE;
}

bool CheckFieldsCompletion() {

	return TRUE;
}

bool CheckingDateForCorrectness() {

	/*
	method check year!?
	month
	day
	*/
	return FALSE;
}
