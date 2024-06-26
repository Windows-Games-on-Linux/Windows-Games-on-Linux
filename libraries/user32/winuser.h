#pragma once

#include <windef.h>

typedef void (*TIMERPROC)(HWND, UINT, UINT_PTR, DWORD);
typedef LRESULT (*WNDPROC)(HWND, UINT, WPARAM, LPARAM);

struct PAINTSTRUCT {
  HDC hdc;
  BOOL fErase;
  RECT rcPaint;
  BOOL fRestore;
  BOOL fIncUpdate;
  BYTE rgbReserved[32];
};

struct MSG {
  HWND hwnd;
  UINT message;
  WPARAM wParam;
  LPARAM lParam;
  DWORD time;
  POINT pt;
  DWORD lPrivate;
};

struct WNDCLASSW {
  UINT style;
  WNDPROC lpfnWndProc;
  int cbClsExtra;
  int cbWndExtra;
  HINSTANCE hInstance;
  HICON hIcon;
  HCURSOR hCursor;
  HBRUSH hbrBackground;
  LPCWSTR lpszMenuName;
  LPCWSTR lpszClassName;
};

typedef PAINTSTRUCT* PPAINTSTRUCT;
typedef PAINTSTRUCT* NPPAINTSTRUCT;
typedef PAINTSTRUCT* LPPAINTSTRUCT;

typedef MSG* PMSG;
typedef MSG* NPMSG;
typedef MSG* LPMSG;

typedef WNDCLASSW* PWNDCLASSW;
typedef WNDCLASSW* NPWNDCLASSW;
typedef WNDCLASSW* LPWNDCLASSW;
