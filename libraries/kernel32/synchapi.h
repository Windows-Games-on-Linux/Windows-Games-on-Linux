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

typedef SRWLOCK PSRWLOCK;

typedef CRITICAL_SECTION* PCRITICAL_SECTION;
typedef CRITICAL_SECTION* LPCRITICAL_SECTION;

typedef void (*PTIMERAPCROUTINE)(LPVOID, DWORD, DWORD);

extern "C" {
  void __attribute__((stdcall)) EnterCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
};

