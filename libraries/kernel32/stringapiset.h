#pragma once

#include <windef.h>

#define MB_COMPOSITE         0x00000002
#define MB_ERR_INVALID_CHARS 0x00000008
#define MB_PRECOMPOSED       0x00000001
#define MB_USEGLYPHCHARS     0x00000004

extern "C" {
  int __attribute__((stdcall)) MultiByteToWideChar(UINT CodePage, DWORD dwFlags, LPCCH lpMultiByteStr, int cbMultiByte, LPWSTR lpWideCharStr, int cchWideChar);
};

