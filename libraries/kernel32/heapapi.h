#pragma once

#include <windef.h>

extern "C" {
  HANDLE __attribute__((stdcall)) GetProcessHeap();
};

