#pragma once

#include <windef.h>

#define TME_CANCEL    0x80000000
#define TME_HOVER     0x00000001
#define TME_LEAVE     0x00000002
#define TME_NONCLIENT 0x00000010
#define TME_QUERY     0x40000000

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

struct TRACKMOUSEEVENT {
  DWORD cbSize;
  DWORD dwFlags;
  HWND hwndTrack;
  DWORD dwHoverTime;
};

struct WNDCLASSEXA {
  UINT cbSize;
  UINT style;
  WNDPROC lpfnWndProc;
  int cbClsExtra;
  int cbWndExtra;
  HINSTANCE hInstance;
  HICON hIcon;
  HCURSOR hCursor;
  HBRUSH hbrBackground;
  LPCSTR lpszMenuName;
  LPCSTR lpszClassName;
  HICON hIconSm;
};

struct WNDCLASSEXW {
  UINT cbSize;
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
  HICON hIconSm;
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

typedef TRACKMOUSEEVENT* LPTRACKMOUSEEVENT;

typedef WNDCLASSEXA* PWNDCLASSEXA;
typedef WNDCLASSEXA* NPWNDCLASSEXA;
typedef WNDCLASSEXA* LPWNDCLASSEXA;

typedef WNDCLASSEXW* PWNDCLASSEXW;
typedef WNDCLASSEXW* NPWNDCLASSEXW;
typedef WNDCLASSEXW* LPWNDCLASSEXW;

