#include "heapapi.h"

#include <iostream>
#include <cstdlib>
#include <cstring>

HANDLE __attribute__((stdcall)) GetProcessHeap() {
  //Unlike Windows, Linux only has one global heap and doesn't support multiple heaps natively
  //Let's just return 1 as a handle for the default heap of a process
  return (HANDLE)1;
}

LPVOID __attribute__((stdcall)) HeapAlloc(HANDLE hHeap, DWORD dwFlags, SIZE_T dwBytes) {
  //For now only the default heap is supported
  if (hHeap != (HANDLE)1) {
    return nullptr;
  }

  if (dwFlags & HEAP_GENERATE_EXCEPTIONS) {
    std::cout << "HeapAlloc: Unimplemented Flag: HEAP_GENERATE_EXCEPTIONS" << std::endl;
  }

  if (dwFlags & HEAP_NO_SERIALIZE) {
    std::cout << "HeapAlloc: Unimplemented Flag: HEAP_NO_SERIALIZE" << std::endl;
  }

  void* memory = malloc(dwBytes);
  if (!memory) {
    return nullptr;
  }

  if (dwFlags & HEAP_ZERO_MEMORY) {
    memset(memory, 0, dwBytes);
  }

  return memory;
}

BOOL __attribute__((stdcall)) HeapFree(HANDLE hHeap, DWORD dwFlags, LPVOID lpMem) {
  //For now only the default heap is supported
  if (hHeap != (HANDLE)1) {
    std::cout << "HeapFree: Heaps other than the default one are not supported" << std::endl;
    return 0;
  }

  if (dwFlags & HEAP_NO_SERIALIZE) {
    std::cout << "HeapFree: Unimplemented Flag: HEAP_NO_SERIALIZE" << std::endl;
  }

  free(lpMem);
  return 1;
}

