#pragma once

#include <windef.h>

extern "C" {
  DWORD __attribute__((stdcall)) FlsAlloc(PFLS_CALLBACK_FUNCTION lpCallback);
  PVOID __attribute__((stdcall)) FlsGetValue(DWORD dwFlsIndex);
  BOOL __attribute__((stdcall)) FlsSetValue(DWORD dwFlsIndex, PVOID lpFlsData);
};

