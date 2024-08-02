#include "synchapi.h"

#include <pthread.h>

BOOL WINAPI InitializeCriticalSectionEx(LPCRITICAL_SECTION lpCriticalSection, DWORD dwSpinCount, DWORD Flags) {
  pthread_mutexattr_t mutexattr;
  pthread_mutexattr_init(&mutexattr);

  pthread_mutexattr_settype(&mutexattr, PTHREAD_MUTEX_RECURSIVE);

  pthread_mutex_t* mutex = new pthread_mutex_t();
  pthread_mutex_init(mutex, &mutexattr);

  pthread_mutexattr_destroy(&mutexattr);

  //DebugInfo is supposed to be initialized when a debugger is attached to the process
  //For now let's just assume that it's not
  lpCriticalSection->DebugInfo = nullptr;

  lpCriticalSection->LockCount = 0;
  lpCriticalSection->RecursionCount = 0;
  lpCriticalSection->OwningThread = nullptr;
  lpCriticalSection->LockSemaphore = (PVOID)mutex;
  lpCriticalSection->SpinCount = dwSpinCount;

  return 1;
}
