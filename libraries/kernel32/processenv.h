#pragma once

#include <windef.h>

#define STD_INPUT_HANDLE  ((DWORD)-10)
#define STD_OUTPUT_HANDLE ((DWORD)-11)
#define STD_ERROR_HANDLE  ((DWORD)-12)

extern "C" {
  HANDLE __attribute__((stdcall)) GetStdHandle(DWORD nStdHandle);
  LPSTR __attribute__((stdcall)) GetCommandLineA();
  LPWSTR __attribute__((stdcall)) GetCommandLineW();
  LPWCH __attribute__((stdcall)) GetEnvironmentStringsW();
};

