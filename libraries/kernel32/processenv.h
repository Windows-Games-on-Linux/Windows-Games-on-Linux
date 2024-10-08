#pragma once

#include <windef.h>

#define STD_INPUT_HANDLE  ((DWORD)-10)
#define STD_OUTPUT_HANDLE ((DWORD)-11)
#define STD_ERROR_HANDLE  ((DWORD)-12)

extern "C" {
  HANDLE WINAPI GetStdHandle(DWORD nStdHandle);
  LPSTR WINAPI GetCommandLineA();
  LPWSTR WINAPI GetCommandLineW();
  LPWCH WINAPI GetEnvironmentStringsW();
  BOOL WINAPI FreeEnvironmentStringsW(LPWCH penv);
  DWORD WINAPI GetEnvironmentVariableW(LPCWSTR lpName, LPWSTR lpBuffer, DWORD nSize);
};

