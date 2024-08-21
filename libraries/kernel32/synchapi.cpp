#include "synchapi.h"

#include <pthread.h>
#include <iostream>

void WINAPI EnterCriticalSection(LPCRITICAL_SECTION lpCriticalSection) {
  //TODO: Implement the EXCEPTION_POSSIBLE_DEADLOCK exception
  //This exception requires a timeout specified in the following registry value:
  //HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\SessionManager\CriticalSectionTimeout
  //A properly written application shouldn't raise this exception, so for now let's skip this part
  pthread_mutex_lock((pthread_mutex_t*)lpCriticalSection->LockSemaphore);

  lpCriticalSection->LockCount++;
}

void WINAPI LeaveCriticalSection(LPCRITICAL_SECTION lpCriticalSection) {
  lpCriticalSection->LockCount--;
  pthread_mutex_unlock((pthread_mutex_t*)lpCriticalSection->LockSemaphore);
}

BOOL WINAPI InitializeCriticalSectionAndSpinCount(LPCRITICAL_SECTION lpCriticalSection, DWORD dwSpinCount) {
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

HANDLE WINAPI CreateEventW(LPSECURITY_ATTRIBUTES lpEventAttributes, BOOL bManualReset, BOOL bInitialState, LPCWSTR lpName) {
  if (lpEventAttributes) {
    std::cout << "CreateEventW: lpEventAttributes is not implemented" << std::endl;
  }

  if (!bManualReset) {
    std::cout << "CreateEventW: Auto-reset event objects are not implemented" << std::endl;
  }

  if (lpName) {
    std::cout << "CreateEventW: Named events are not implemented" << std::endl;
  }

  Event* event = new Event();
  event->manualReset = bManualReset;
  event->signaled = bInitialState;

  return event;
}

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

void WINAPI InitializeSRWLock(PSRWLOCK SRWLock) {
  pthread_rwlock_t* rwlock = new pthread_rwlock_t();
  pthread_rwlock_init(rwlock, nullptr);

  SRWLock->Ptr = rwlock;
}

BOOL WINAPI SetEvent(HANDLE hEvent) {
  Event* event = (Event*)hEvent;
  event->signaled = true;

  return 1;
}

BOOL WINAPI ResetEvent(HANDLE hEvent) {
  Event* event = (Event*)hEvent;
  event->signaled = false;

  return 1;
}

