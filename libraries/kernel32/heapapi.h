#pragma once

#include <windef.h>

#define HEAP_GENERATE_EXCEPTIONS   0x00000004
#define HEAP_NO_SERIALIZE          0x00000001
#define HEAP_ZERO_MEMORY           0x00000008
#define HEAP_REALLOC_IN_PLACE_ONLY 0x00000010

extern "C" {
  HANDLE WINAPI GetProcessHeap();
  LPVOID WINAPI HeapAlloc(HANDLE hHeap, DWORD dwFlags, SIZE_T dwBytes);
  BOOL WINAPI HeapFree(HANDLE hHeap, DWORD dwFlags, LPVOID lpMem);
  SIZE_T WINAPI HeapSize(HANDLE hHeap, DWORD dwFlags, LPCVOID lpMem);
  LPVOID WINAPI HeapReAlloc(HANDLE hHeap, DWORD dwFlags, LPVOID lpMem, SIZE_T dwBytes);
};

