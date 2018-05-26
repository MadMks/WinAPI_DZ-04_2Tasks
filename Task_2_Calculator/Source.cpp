#include <windows.h>
#include <tchar.h>
#include "resource.h"
using namespace std;


HWND hLeftOperand, hSign, hRightOperand;
HWND hAnswer;
// TODO
HWND hLabel;

BOOL CALLBACK DlgProc(HWND, UINT, WPARAM, LPARAM);

bool CheckFieldsCompletion();
bool IsANumericalValue();
bool IsASignOfValue();

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrev, LPSTR lpszCmdLine, int nCmdShow)
{

	MSG msg;
	HWND hDialog = CreateDialog(hInst, MAKEINTRESOURCE(IDD_DIALOG_Calculator), NULL, DlgProc);
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

		hLeftOperand = GetDlgItem(hWnd, IDC_EDIT_LeftOperand);
		hSign = GetDlgItem(hWnd, IDC_EDIT_sign);
		hRightOperand = GetDlgItem(hWnd, IDC_EDIT_RightOperand);

		hAnswer = GetDlgItem(hWnd, IDC_STATIC_Answer);

		// TODO
		hLabel = GetDlgItem(hWnd, IDC_STATIC_ForResult);

		return TRUE;

	case WM_COMMAND:

		if (HIWORD(wParam) == EN_CHANGE)
		{
			SetWindowText(hAnswer, NULL);
		}

		if (LOWORD(wParam) == IDC_BUTTON_Compute)
		{
			TCHAR szLeftOperand[10];
			TCHAR szSign[2];
			TCHAR szRightOperand[10];

			GetWindowText(hLeftOperand, szLeftOperand, 10);
			GetWindowText(hSign, szSign, 2);
			GetWindowText(hRightOperand, szRightOperand, 10);

			if (CheckFieldsCompletion() && IsANumericalValue() && IsASignOfValue())
			{
				//SetWindowText(hAnswer, L"Вычисления");
				// TODO
				//SetWindowText(hLabel, szLeftOperand);
			}
			else
			{
				SetWindowText(hAnswer, L"Уравнение не допустимо!");
			}
		}

		return true;


	}
	return FALSE;
}

bool CheckFieldsCompletion() {

	TCHAR text[10];

	GetWindowText(hLeftOperand, text, 10);
	if (lstrlen(text) == 0) {
		return FALSE;
	}

	GetWindowText(hSign, text, 10);
	if (lstrlen(text) == 0) {
		return FALSE;
	}

	GetWindowText(hRightOperand, text, 10);
	if (lstrlen(text) == 0) {
		return FALSE;
	}

	return TRUE;
}

bool IsANumericalValue() {

	TCHAR textLeft[10];
	TCHAR textRight[10];

	GetWindowText(hLeftOperand, textLeft, 10);
	for (int i = 0; i < lstrlen(textLeft); i++)
	{
		if (isdigit(textLeft[i]) == 0)
		{
			return FALSE;
		}
	}

	GetWindowText(hRightOperand, textRight, 10);
	for (int i = 0; i < lstrlen(textRight); i++)
	{
		if (isdigit(textRight[i]) == 0)
		{
			return FALSE;
		}
	}

	return TRUE;
}

bool IsASignOfValue() {

	TCHAR textSign[10];

	GetWindowText(hSign, textSign, 10);

	if (lstrlen(textSign) > 1)
	{
		return FALSE;
	}

	switch (textSign[0])
	{
	case '+':
	case '-':
	case '*':
	case '/':
		return TRUE;
	default:
		break;
	}

	return FALSE;
}