#include "processthreadsapi.h"

#include <pthread.h>
#include <unistd.h>

DWORD GetCurrentThreadId() {
  return pthread_self();
}

DWORD GetCurrentProcessId() {
  return getpid();
}
