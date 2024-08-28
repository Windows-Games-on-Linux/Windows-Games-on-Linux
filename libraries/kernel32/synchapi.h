#pragma once

#include <windef.h>
#include <ntddk.h>

#define INIT_ONCE_ASYNC      0x00000002
#define INIT_ONCE_CHECK_ONLY 0x00000001

#define CREATE_MUTEX_INITIAL_OWNER 0x00000001

#define WAIT_ABANDONED     0x00000080
#define WAIT_IO_COMPLETION 0x000000C0
#define WAIT_OBJECT_0      0x00000000
#define WAIT_TIMEOUT       0x00000102
#define WAIT_FAILED        0xFFFFFFFF

typedef RTL_RUN_ONCE           INIT_ONCE;
typedef RTL_CONDITION_VARIABLE CONDITION_VARIABLE;
typedef RTL_SRWLOCK            SRWLOCK;
typedef RTL_CRITICAL_SECTION   CRITICAL_SECTION;

typedef INIT_ONCE* PINIT_ONCE;
typedef INIT_ONCE* LPINIT_ONCE;

typedef CONDITION_VARIABLE* PCONDITION_VARIABLE;

typedef SRWLOCK* PSRWLOCK;

typedef CRITICAL_SECTION* PCRITICAL_SECTION;
typedef CRITICAL_SECTION* LPCRITICAL_SECTION;

typedef void (*PTIMERAPCROUTINE)(LPVOID, DWORD, DWORD);

struct Event {
  bool manualReset;
  bool signaled;
};

extern "C" {
  void WINAPI EnterCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
  void WINAPI LeaveCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
  BOOL WINAPI InitializeCriticalSectionAndSpinCount(LPCRITICAL_SECTION lpCriticalSection, DWORD dwSpinCount);
  HANDLE WINAPI CreateEventW(LPSECURITY_ATTRIBUTES lpEventAttributes, BOOL bManualReset, BOOL bInitialState, LPCWSTR lpName);
  BOOL WINAPI InitializeCriticalSectionEx(LPCRITICAL_SECTION lpCriticalSection, DWORD dwSpinCount, DWORD Flags);
  void WINAPI InitializeSRWLock(PSRWLOCK SRWLock);
  BOOL WINAPI SetEvent(HANDLE hEvent);
  BOOL WINAPI ResetEvent(HANDLE hEvent);
  void WINAPI AcquireSRWLockExclusive(PSRWLOCK SRWLock);
  void WINAPI ReleaseSRWLockExclusive(PSRWLOCK SRWLock);
  HANDLE WINAPI OpenEventW(DWORD dwDesiredAccess, BOOL bInheritHandle, LPCWSTR lpName);
  BOOL WINAPI InitOnceBeginInitialize(LPINIT_ONCE lpInitOnce, DWORD dwFlags, PBOOL fPending, LPVOID* lpContext);
  HANDLE WINAPI CreateMutexExW(LPSECURITY_ATTRIBUTES lpMutexAttributes, LPCWSTR lpName, DWORD dwFlags, DWORD dwDesiredAccess);
  DWORD WINAPI WaitForSingleObjectEx(HANDLE hHandle, DWORD dwMilliseconds, BOOL bAlertable);
  HANDLE WINAPI OpenSemaphoreW(DWORD dwDesiredAccess, BOOL bInheritHandle, LPCWSTR lpName);
  BOOL WINAPI ReleaseMutex(HANDLE hMutex);
};

