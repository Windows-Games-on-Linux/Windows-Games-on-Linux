#pragma once

#include <windef.h>

typedef void (*TIMERPROC)(HWND, UINT, UINT_PTR, DWORD);

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

typedef PAINTSTRUCT* PPAINTSTRUCT;
typedef PAINTSTRUCT* NPPAINTSTRUCT;
typedef PAINTSTRUCT* LPPAINTSTRUCT;

typedef MSG* PMSG;
typedef MSG* NPMSG;
typedef MSG* LPMSG;
