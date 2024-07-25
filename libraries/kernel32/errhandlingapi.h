#pragma once

#include <windef.h>
#include "_winnt.h"

typedef LONG (*PTOP_LEVEL_EXCEPTION_FILTER)(EXCEPTION_POINTERS* ExceptionInfo);
typedef PTOP_LEVEL_EXCEPTION_FILTER LPTOP_LEVEL_EXCEPTION_FILTER;

extern "C" {
  DWORD __attribute__((stdcall)) GetLastError();
};

