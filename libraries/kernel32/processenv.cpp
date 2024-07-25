#include "processenv.h"

HANDLE __attribute__((stdcall)) GetStdHandle(DWORD nStdHandle) {
  //Let's assume the following handle values:
  // - STD_INPUT_HANDLE: 2
  // - STD_OUTPUT_HANDLE: 3
  // - STD_ERROR_HANDLE: 4

  if (nStdHandle == STD_INPUT_HANDLE) {
    return (HANDLE)2;
  }

  if (nStdHandle == STD_OUTPUT_HANDLE) {
    return (HANDLE)3;
  }

  if (nStdHandle == STD_ERROR_HANDLE) {
    return (HANDLE)4;
  }

  return nullptr;
}

