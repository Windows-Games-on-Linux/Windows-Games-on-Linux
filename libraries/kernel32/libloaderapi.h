#pragma once

#include <windef.h>

extern "C" {
  HMODULE __attribute__((stdcall)) LoadLibraryExW(LPCWSTR lpLibFileName, HANDLE hFile, DWORD dwFlags);
  FARPROC __attribute__((stdcall)) GetProcAddress(HMODULE hModule, LPCSTR lpProcName);
};

