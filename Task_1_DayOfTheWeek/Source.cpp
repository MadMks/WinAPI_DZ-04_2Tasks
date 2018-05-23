#include <windows.h>
#include <tchar.h>


// Прототип оконной процедуры.
LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);


TCHAR szClassWindow[] = TEXT("Каркасное приложение");	// Имя класса окна.


														// Main.

INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpszCmdLine, int nCmdShow)
{
	HWND hWnd;	// храним дескриптор окна.
	MSG lpMsg;	// экземпляр структуры MSG для обработки сообщений.
	WNDCLASSEX wcl;	// структура определения класса окна.

					// 1. Определяем класс окна.
	wcl.cbSize = sizeof(wcl);	// размер структуры WNDCLASSEX
								// Перерисовать всё окно, если изменён размер по горизонтали или по вертикали
	wcl.style = CS_HREDRAW | CS_VREDRAW;	// CS (Class Style) - стиль класса окна
	wcl.lpfnWndProc = WindowProc;	// адрес оконной процедуры
	wcl.cbClsExtra = 0;		// используется Windows 
	wcl.cbWndExtra = 0; 	// используется Windows 
	wcl.hInstance = hInst;	// дескриптор данного приложения
	wcl.hIcon = LoadIcon(NULL, IDI_APPLICATION);	// загрузка стандартной иконки
	wcl.hCursor = LoadCursor(NULL, IDC_ARROW);	// загрузка стандартного курсора	
	wcl.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// заполнение окна белым цветом
	wcl.lpszMenuName = NULL;	// приложение не содержит меню
	wcl.lpszClassName = szClassWindow;	// имя класса окна
	wcl.hIconSm = NULL;	// отсутствие маленькой иконки для связи с классом окна


						// 2. Регистрируем класс окна.
						// Если отсутствует регистрация класса
	if (!RegisterClassEx(&wcl)) {
		MessageBox(
			NULL,
			L"Не получилось зарегистрировать Класс!", L"Ошибка",
			MB_OK | MB_ICONSTOP
		);
		return NULL; // при неудачной регистрации - выход
	}


	// 3. Создаем окно.
	// создается окно и  переменной hWnd присваивается дескриптор окна
	hWnd = CreateWindowEx(
		0,		// расширенный стиль окна
		szClassWindow,	//имя класса окна
		TEXT("Каркас Windows приложения"), // заголовок окна
		WS_OVERLAPPEDWINDOW,				// стиль окна
											/* Заголовок, рамка, позволяющая менять размеры, системное меню, кнопки развёртывания и свёртывания окна  */
		CW_USEDEFAULT,	// х-координата левого верхнего угла окна
		CW_USEDEFAULT,	// y-координата левого верхнего угла окна
		CW_USEDEFAULT,	// ширина окна
		CW_USEDEFAULT,	// высота окна
		NULL,			// дескриптор родительского окна
		NULL,			// дескриптор меню окна
		hInst,		// идентификатор приложения, создавшего окно
		NULL		// указатель на область данных приложения
	);
	// Если окно не создалось (если неверные параметры)
	if (!hWnd) {
		MessageBox(
			NULL,
			L"Не получилось создать окно!", L"Ошибка",
			MB_OK | MB_ICONSTOP
		);
		return NULL;
	}


	// 4. Отображаем окно.
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd); // перерисовка окна


						// 5. Запускаем цикл обработки сообщений.
						// Получаем очередное сообщение из очереди сообщений.
	while (GetMessage(&lpMsg, NULL, 0, 0))
	{
		TranslateMessage(&lpMsg);	// трансляция сообщения
		DispatchMessage(&lpMsg);	// передаем структуру обратно в Windows.
	}
	return lpMsg.wParam;
}



// Оконная процедура.
LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam)
{
	switch (uMessage)
	{
	case WM_DESTROY: // сообщение о завершении программы
		PostQuitMessage(0); // посылка сообщения WM_QUIT
		break;
	default:
		// все сообщения, которые не обрабатываются в данной оконной функции 
		// направляются обратно Windows на обработку по умолчанию
		return DefWindowProc(hWnd, uMessage, wParam, lParam);
	}
	return 0;
}
