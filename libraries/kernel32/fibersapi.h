#pragma once

#include <windef.h>

extern "C" {
  DWORD WINAPI FlsAlloc(PFLS_CALLBACK_FUNCTION lpCallback);
  PVOID WINAPI FlsGetValue(DWORD dwFlsIndex);
  BOOL WINAPI FlsSetValue(DWORD dwFlsIndex, PVOID lpFlsData);
};

