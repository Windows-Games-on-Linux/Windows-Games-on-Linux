#include "heapapi.h"

HANDLE __attribute__((stdcall)) GetProcessHeap() {
  //Unlike Windows, Linux only has one global heap and doesn't support multiple heaps natively
  //Let's just return 1 as a handle for the default heap of a process
  return (HANDLE)1;
}

