#include "errhandlingapi.h"

__thread DWORD lastError = 0;

DWORD __attribute__((stdcall)) GetLastError() {
  return lastError;
}

