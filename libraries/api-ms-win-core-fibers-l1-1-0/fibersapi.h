#pragma once

#include <windef.h>

extern "C" {
  DWORD __attribute__((stdcall)) FlsAlloc(PFLS_CALLBACK_FUNCTION lpCallback);
  PVOID __attribute__((stdcall)) FlsGetValue(DWORD dwFlsIndex);
};

