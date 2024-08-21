#include "heapapi.h"

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <malloc.h>

HANDLE WINAPI GetProcessHeap() {
  //Unlike Windows, Linux only has one global heap and doesn't support multiple heaps natively
  //Let's just return 1 as a handle for the default heap of a process
  return (HANDLE)1;
}

LPVOID WINAPI HeapAlloc(HANDLE hHeap, DWORD dwFlags, SIZE_T dwBytes) {
  //For now only the default heap is supported
  if (hHeap != (HANDLE)1) {
    std::cout << "HeapAlloc: Heaps other than the default one are not supported" << std::endl;
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

BOOL WINAPI HeapFree(HANDLE hHeap, DWORD dwFlags, LPVOID lpMem) {
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

SIZE_T WINAPI HeapSize(HANDLE hHeap, DWORD dwFlags, LPCVOID lpMem) {
  if (hHeap != (HANDLE)1) {
    std::cout << "HeapSize: Heaps other than the default one are not supported" << std::endl;
    return 0;
  }

  if (dwFlags & HEAP_NO_SERIALIZE) {
    std::cout << "HeapSize: Unimplemented Flag: HEAP_NO_SERIALIZE" << std::endl;
  }

  return malloc_usable_size((void*)lpMem);
}

