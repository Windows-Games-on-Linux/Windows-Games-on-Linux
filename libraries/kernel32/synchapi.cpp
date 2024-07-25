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

