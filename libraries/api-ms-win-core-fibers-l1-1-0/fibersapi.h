#pragma once

#include <windef.h>

extern "C" {
  DWORD __attribute__((stdcall)) FlsAlloc(PFLS_CALLBACK_FUNCTION lpCallback);
};

