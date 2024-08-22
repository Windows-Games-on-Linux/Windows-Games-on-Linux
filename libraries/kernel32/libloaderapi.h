#pragma once

#include <windef.h>

extern "C" {
  HMODULE WINAPI LoadLibraryExW(LPCWSTR lpLibFileName, HANDLE hFile, DWORD dwFlags);
  FARPROC WINAPI GetProcAddress(HMODULE hModule, LPCSTR lpProcName);
  DWORD WINAPI GetModuleFileNameW(HMODULE hModule, LPWSTR lpFilename, DWORD nSize);
  HMODULE WINAPI GetModuleHandleW(LPCWSTR lpModuleName);
  HMODULE WINAPI GetModuleHandleA(LPCSTR lpModuleName);
};

