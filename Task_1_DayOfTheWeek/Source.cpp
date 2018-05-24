#include <windows.h>
#include "resource.h"
#include <vector>
using namespace std;

// Ïðîòîòèï ôóíêöèè DlgProc.
BOOL CALLBACK DlgProc(HWND, UINT, WPARAM, LPARAM);



int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrev, LPSTR lpszCmdLine, int nCmdShow)
{

	MSG msg;	// ñòðóêòóðà.
				// ñîçäà¸ì ãëàâíîå îêíî ïðèëîæåíèÿ íà îñíîâå íåìîäàëüíîãî äèàëîãà
	HWND hDialog = CreateDialog(hInst, MAKEINTRESOURCE(IDD_DIALOG_Main), NULL, DlgProc);
	// Îòîáðàæàåì îêíî	
	ShowWindow(hDialog, nCmdShow);


	//Çàïóñêàåì öèêë îáðàáîòêè ñîîáùåíèé
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
		// Çàêðûâàåì íåìîäàëüíûé äèàëîã.
		DestroyWindow(hWnd); // ðàçðóøàåì îêíî.
		PostQuitMessage(0); // îñòàíàâëèâàåì öèêë îáðàáîòêè ñîîáùåíèé.
		return TRUE;
	
	case WM_INITDIALOG:
		return true;
	case WM_COMMAND:
		if (LOWORD(wParam) == /* button */){
			// if
			// TODO method check empty string
			// TODO method check date
			// https://lifehacker.ru/kakoj-den-nedeli/
			/*
				method check year!?
				month
				day
			*/
			// {}
			// else{ 
				// data not correct
			//}
		}
	
		return true;




	}
	return FALSE;
}
