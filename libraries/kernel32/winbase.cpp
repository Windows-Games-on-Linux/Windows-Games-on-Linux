#include "winbase.h"

namespace {
  bool safeSearchEnabled = false;
  bool safeSearchPermanent = false;
};

PVOID WINAPI EncodePointer(PVOID Ptr) {
  //Currently for simplicity this implementation simply increments the pointer by a constant value
  #if defined(__x86_64__)
    return (PVOID)((uint64_t)Ptr + 0x123456789ABCDEF12ULL);
  #else
    return (PVOID)((uint32_t)Ptr + 0x12345678);
  #endif
}

BOOL WINAPI SetSearchPathMode(DWORD Flags) {
  if (safeSearchPermanent) {
    return 0;
  }

  if (Flags & BASE_SEARCH_PATH_ENABLE_SAFE_SEARCHMODE && Flags & BASE_SEARCH_PATH_DISABLE_SAFE_SEARCHMODE) {
    return 0;
  }

  if (Flags & BASE_SEARCH_PATH_ENABLE_SAFE_SEARCHMODE) {
    safeSearchEnabled = true;

    if (Flags & BASE_SEARCH_PATH_PERMANENT) {
      safeSearchPermanent = true;
    }

    return 1;
  }

  if (Flags & BASE_SEARCH_PATH_DISABLE_SAFE_SEARCHMODE) {
    if (Flags & BASE_SEARCH_PATH_PERMANENT) {
      return 0;
    }

    safeSearchEnabled = false;
    return 1;
  }

  return 0;
}

