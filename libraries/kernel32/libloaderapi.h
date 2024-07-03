#pragma once

#include <windef.h>

extern "C" {
  HMODULE LoadLibraryExW(LPCWSTR lpLibFileName, HANDLE hFile, DWORD dwFlags);
  FARPROC GetProcAddress(HMODULE hModule, LPCSTR lpProcName);
};

