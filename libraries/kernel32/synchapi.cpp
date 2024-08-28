#include "synchapi.h"

#include <pthread.h>
#include <iostream>
#include <cstring>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <semaphore.h>

namespace {
  enum ObjectType {
    Mutex
  };

  struct ObjectInfo {
    ObjectType objectType;
  };

  struct MutexInfo : public ObjectInfo {
    pthread_mutex_t* mutex;

    MutexInfo(pthread_mutex_t* mutex) {
      this->objectType = ObjectType::Mutex;
      this->mutex = mutex;
    }
  };
};

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

void WINAPI AcquireSRWLockExclusive(PSRWLOCK SRWLock) {
  pthread_rwlock_wrlock((pthread_rwlock_t*)SRWLock->Ptr);
}

void WINAPI ReleaseSRWLockExclusive(PSRWLOCK SRWLock) {
  pthread_rwlock_unlock((pthread_rwlock_t*)SRWLock->Ptr);
}

HANDLE WINAPI OpenEventW(DWORD dwDesiredAccess, BOOL bInheritHandle, LPCWSTR lpName) {
  std::cout << "OpenEventW: Support for named events is not implemented" << std::endl;
  return nullptr;
}

BOOL WINAPI InitOnceBeginInitialize(LPINIT_ONCE lpInitOnce, DWORD dwFlags, PBOOL fPending, LPVOID* lpContext) {
  pthread_once_t* once = new pthread_once_t();
  *once = PTHREAD_ONCE_INIT;

  lpInitOnce->Ptr = once;

  if (dwFlags & INIT_ONCE_ASYNC) {
    std::cout << "InitOnceBeginInitialize: Unimplemented flag: INIT_ONCE_ASYNC" << std::endl;
  }

  if (dwFlags & INIT_ONCE_CHECK_ONLY) {
    std::cout << "InitOnceBeginInitialize: Unimplemented flag: INIT_ONCE_CHECK_ONLY" << std::endl;
  }

  return 1;
}

HANDLE WINAPI CreateMutexExW(LPSECURITY_ATTRIBUTES lpMutexAttributes, LPCWSTR lpName, DWORD dwFlags, DWORD dwDesiredAccess) {
  pthread_mutex_t* mutex = nullptr;

  if (lpName != nullptr) {
    size_t nameLength = 0;
    for (const char16_t* c = lpName; *c != 0; c++) {
      nameLength++;
    }

    char* name = new char[nameLength + 1];
    for (int i = 0; i < nameLength + 1; i++) {
      name[i] = (char)lpName[i];
      if (name[i] == 0) {
        break;
      }
    }

    std::string shm_path;

    if (memcmp(name, "Global\\", 7) == 0) {
      shm_path = "/mutex-global-";
      shm_path += &name[7];
    } else if (memcmp(name, "Local\\", 6) == 0) {
      shm_path = "/mutex-local-";
      shm_path += &name[6];
    } else {
      shm_path = name;
    }

    int shm_fd = shm_open(shm_path.c_str(), O_RDWR | O_CREAT | O_EXCL, 0666); //TODO: Proper mode?
    delete[] name;

    if (shm_fd == -1) {
      return nullptr;
    }

    int shm_size = sizeof(pthread_mutex_t);
    if (ftruncate(shm_fd, shm_size) == -1) {
      close(shm_fd);
      return nullptr;
    }

    mutex = (pthread_mutex_t*)mmap(nullptr, shm_size, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    if (!mutex) {
      close(shm_fd);
      return nullptr;
    }
  } else {
    mutex = new pthread_mutex_t();
  }

  if (dwFlags & CREATE_MUTEX_INITIAL_OWNER) {
    std::cout << "CreateMutexExW: Unimplemented flag: CREATE_MUTEX_INITIAL_OWNER" << std::endl;
  }

  pthread_mutexattr_t mutexattr;
  pthread_mutexattr_init(&mutexattr);

  pthread_mutexattr_settype(&mutexattr, PTHREAD_MUTEX_RECURSIVE);
  pthread_mutexattr_setpshared(&mutexattr, PTHREAD_PROCESS_SHARED);

  pthread_mutex_init(mutex, &mutexattr);

  pthread_mutexattr_destroy(&mutexattr);

  MutexInfo* mutexInfo = new MutexInfo(mutex);
  return mutexInfo;
}

DWORD WINAPI WaitForSingleObjectEx(HANDLE hHandle, DWORD dwMilliseconds, BOOL bAlertable) {
  ObjectInfo* objectInfo = (ObjectInfo*)hHandle;

  if (objectInfo->objectType == ObjectType::Mutex) {
    MutexInfo* mutexInfo = (MutexInfo*)objectInfo;
    pthread_mutex_t* mutex = mutexInfo->mutex;

    pthread_mutex_lock(mutex);
    pthread_mutex_unlock(mutex);

    return WAIT_OBJECT_0;
  } else {
    std::cout << "WaitForSingleObjectEx: Waiting for objects other than mutexes is not implemented" << std::endl;
    return WAIT_FAILED;
  }

  return 0;
}

HANDLE WINAPI OpenSemaphoreW(DWORD dwDesiredAccess, BOOL bInheritHandle, LPCWSTR lpName) {
  size_t nameLength = 0;
  for (const char16_t* c = lpName; *c != 0; c++) {
    nameLength++;
  }

  char* name = new char[nameLength + 1];
  for (int i = 0; i < nameLength + 1; i++) {
    name[i] = (char)lpName[i];
  }

  std::string sem_path;

  if (memcmp(name, "Global\\", 7) == 0) {
    sem_path = "/semaphore-global-";
    sem_path += &name[7];
  } else if (memcmp(name, "Local\\", 6) == 0) {
    sem_path = "/semaphore-local-";
    sem_path += &name[6];
  } else {
    sem_path = name;
  }

  delete[] name;

  sem_t* sem = sem_open(sem_path.c_str(), 0);
  if (sem == SEM_FAILED) {
    return nullptr;
  }

  return sem;
}

BOOL WINAPI ReleaseMutex(HANDLE hMutex) {
  MutexInfo* mutexInfo = (MutexInfo*)hMutex;

  if (pthread_mutex_unlock(mutexInfo->mutex) != 0) {
    return 0;
  }

  return 1;
}
