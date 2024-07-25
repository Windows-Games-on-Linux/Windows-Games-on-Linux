#include "errhandlingapi.h"

__thread DWORD lastError = 0;

DWORD __attribute__((stdcall)) GetLastError() {
  return lastError;
}

void __attribute__((stdcall)) SetLastError(DWORD dwErrorCode) {
  lastError = dwErrorCode;
}

