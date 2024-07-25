#pragma once

#include <windef.h>

extern "C" {
  BOOL __attribute__((stdcall)) QueryPerformanceCounter(LARGE_INTEGER* lpPerformanceCount);
};
