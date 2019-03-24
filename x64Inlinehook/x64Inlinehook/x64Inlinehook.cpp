// x64Inlinehook.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "APIHook64Class.h"
#include <windows.h>
int WINAPI MyMessageBoxW(HWND hWnd, LPCWSTR lpText, LPCWSTR lpCaption, UINT uType)
{
	printf("hWnd %x lpText %s lpCaption %s  uType %d\n",   hWnd,   lpText,   lpCaption,   uType);
	return MessageBoxA(hWnd, "hook", "hook", uType);
}

int main()
{
	APIHook64 temp;
	temp.Hook("User32.dll", "MessageBoxW", (long long)MyMessageBoxW, 1);
	MessageBoxW(NULL, L"test", L"test", NULL);
	getchar();
    return 0;
}

