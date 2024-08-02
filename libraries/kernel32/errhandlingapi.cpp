#include "errhandlingapi.h"

__thread DWORD lastError = 0;

DWORD WINAPI GetLastError() {
  return lastError;
}

void WINAPI SetLastError(DWORD dwErrorCode) {
  lastError = dwErrorCode;
}

