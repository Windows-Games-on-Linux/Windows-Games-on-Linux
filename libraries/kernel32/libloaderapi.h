#pragma once

#include <windef.h>

extern "C" {
  HMODULE LoadLibraryExW(LPCWSTR lpLibFileName, HANDLE hFile, DWORD dwFlags);
};

