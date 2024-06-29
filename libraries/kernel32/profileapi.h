#pragma once

#include <windef.h>

extern "C" {
  BOOL QueryPerformanceCounter(LARGE_INTEGER* lpPerformanceCount);
};
