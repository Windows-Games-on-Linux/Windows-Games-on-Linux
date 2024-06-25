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

typedef PAINTSTRUCT* PPAINTSTRUCT;
typedef PAINTSTRUCT* NPPAINTSTRUCT;
typedef PAINTSTRUCT* LPPAINTSTRUCT;
