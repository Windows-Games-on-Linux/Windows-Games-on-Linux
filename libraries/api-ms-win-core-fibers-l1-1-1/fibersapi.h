#pragma once

#include <windef.h>

extern "C" {
  DWORD WINAPI FlsAlloc(PFLS_CALLBACK_FUNCTION lpCallback);
  BOOL WINAPI FlsSetValue(DWORD dwFlsIndex, PVOID lpFlsData);
};

