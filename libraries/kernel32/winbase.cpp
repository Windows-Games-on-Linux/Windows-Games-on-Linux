#include "winbase.h"

PVOID WINAPI EncodePointer(PVOID Ptr) {
  //Currently for simplicity this implementation simply increments the pointer by a constant value
  #if defined(__x86_64__)
    return (PVOID)((uint64_t)Ptr + 0x123456789ABCDEF12ULL);
  #else
    return (PVOID)((uint32_t)Ptr + 0x12345678);
  #endif
}

