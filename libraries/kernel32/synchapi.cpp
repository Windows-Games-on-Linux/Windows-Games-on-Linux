#include "synchapi.h"

#include <pthread.h>

void __attribute__((stdcall)) EnterCriticalSection(LPCRITICAL_SECTION lpCriticalSection) {
  //TODO: Implement the EXCEPTION_POSSIBLE_DEADLOCK exception
  //This exception requires a timeout specified in the following registry value:
  //HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\SessionManager\CriticalSectionTimeout
  //A properly written application shouldn't raise this exception, so for now let's skip this part
  pthread_mutex_lock((pthread_mutex_t*)lpCriticalSection->LockSemaphore);

  lpCriticalSection->LockCount++;
}

void __attribute__((stdcall)) LeaveCriticalSection(LPCRITICAL_SECTION lpCriticalSection) {
  lpCriticalSection->LockCount--;
  pthread_mutex_unlock((pthread_mutex_t*)lpCriticalSection->LockSemaphore);
}

BOOL __attribute__((stdcall)) InitializeCriticalSectionAndSpinCount(LPCRITICAL_SECTION lpCriticalSection, DWORD dwSpinCount) {
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

