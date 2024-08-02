#pragma once

#include <windef.h>

extern "C" {
  BOOL WINAPI QueryPerformanceCounter(LARGE_INTEGER* lpPerformanceCount);
  BOOL WINAPI QueryPerformanceFrequency(LARGE_INTEGER* lpFrequency);
};

