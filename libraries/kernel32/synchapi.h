#pragma once

#include <windef.h>
#include <ntddk.h>

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
};

