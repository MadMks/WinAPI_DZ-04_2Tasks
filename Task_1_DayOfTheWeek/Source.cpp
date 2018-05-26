#include <windows.h>
#include <tchar.h>
#include "resource.h"
#include <vector>
using namespace std;

HWND hEditError;
HWND hEditDay, hEditMonth, hEditYear;

BOOL CALLBACK DlgProc(HWND, UINT, WPARAM, LPARAM);

bool CheckFieldsCompletion();
bool CheckingDateForCorrectness(int day, int month, int year);

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
		hEditError = GetDlgItem(hWnd, IDC_STATIC_MessageOfCorrect);
		hEditDay = GetDlgItem(hWnd, IDC_EDIT_Day);
		hEditMonth = GetDlgItem(hWnd, IDC_EDIT_Month);
		hEditYear = GetDlgItem(hWnd, IDC_EDIT_Year);
		return TRUE;
	case WM_COMMAND:

		if (HIWORD(wParam) == EN_CHANGE)
		{
			SetWindowText(hEditError, NULL);
		}

		if (LOWORD(wParam) == IDC_BUTTON_Identify) {

			TCHAR szTextDay[3];
			TCHAR szTextMonth[3];
			TCHAR szTextYear[5];
			int nDay;

			GetWindowText(hEditDay, szTextDay, 3);
			GetWindowText(hEditMonth, szTextMonth, 3);
			GetWindowText(hEditYear, szTextYear, 5);
			//nDay = _wtoi(text);


			if (CheckFieldsCompletion() 
				&& CheckingDateForCorrectness(_wtoi(szTextDay), _wtoi(szTextMonth), _wtoi(szTextYear)))
			{
				// высчитать день недели
				// указать день недели.
				//
				MessageBox(hWnd, L"Дата корректна", L"0",
					MB_OK | MB_ICONINFORMATION);
			}
			else
			{
				SetWindowText(hEditError, L"Дата не корректна!");
			}
		}

		return true;


	}
	return FALSE;
}

bool CheckFieldsCompletion() {

	TCHAR text[6];

	GetWindowText(hEditDay, text, 3);
	if (lstrlen(text) == 0) {
		return FALSE;
	}

	GetWindowText(hEditMonth, text, 3);
	if (lstrlen(text) == 0) {
		return FALSE;
	}

	GetWindowText(hEditYear, text, 6);
	if (lstrlen(text) == 0) {
		return FALSE;
	}
	else if (lstrlen(text) < 4 || lstrlen(text) > 4)
	{
		return FALSE;
	}

	return TRUE;
}

bool CheckingDateForCorrectness(int day, int month, int year) {

	int daysInMonth[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

	if (year % 4 == 0) {
		daysInMonth[2] = 29;
	}

	if ((month < 1) || (month > 12)) {
		return false;
	}
		
	if ((day < 1) || (day > daysInMonth[month])) {
		return false;
	}

	return TRUE;
}
