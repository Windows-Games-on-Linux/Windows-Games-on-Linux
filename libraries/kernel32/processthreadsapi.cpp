#include "processthreadsapi.h"

#include <pthread.h>

DWORD GetCurrentThreadId() {
  return pthread_self();
}
