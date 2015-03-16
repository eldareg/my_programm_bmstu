#include <stdio.h>
#include <locale>
#include <Windows.h>
#include "resource.h"

BOOL CALLBACK DialogFun(HWND hwnd, UINT message, 
WPARAM wParam, LPARAM lParam)
{
char Text[64];
int x, y, z,o;
setlocale(LC_ALL,"Russian");

switch(message)
{
case WM_COMMAND:
switch(LOWORD(wParam))
{
case IDOK:
case IDCANCEL:
EndDialog(hwnd, LOWORD(wParam));
return TRUE;

case IDC_BUTTON1: // Обработка сообщения от кнопки /

SendDlgItemMessage(hwnd, IDC_EDIT1, WM_GETTEXT, 63, (LPARAM)Text); // Получить текст из текстового поля 1 и записать в массив Text
sscanf_s(Text, "%d", &x);
SendDlgItemMessage(hwnd, IDC_EDIT2, WM_GETTEXT, 63, (LPARAM)Text); // Получить текст из текстового поля 2 и записать в массив Text
sscanf_s(Text, "%d", &y);

char Znak;
if (LOWORD(wParam)==IDC_BUTTON1) { z=x/y; o = x%y; Znak='/'; }
sprintf_s(Text, "Результат: %d Остаток: %d", z,o);
SendDlgItemMessage(hwnd, IDC_EDIT3, WM_SETTEXT, 0, (LPARAM)Text); 
return TRUE;
}
}
return FALSE;
}

int APIENTRY WinMain(HINSTANCE hInstance,
HINSTANCE hPrevInstance,
LPSTR lpCmdLine,
int nCmdShow)
{

DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), 0, DialogFun);

return 0;
}