#pragma once

#include <ntddk.h>
#include <windef.h>

#define CRITICAL_SECTION_NO_DEBUG_INFO 0x01000000

typedef RTL_CRITICAL_SECTION CRITICAL_SECTION;

typedef CRITICAL_SECTION* PCRITICAL_SECTION;
typedef CRITICAL_SECTION* LPCRITICAL_SECTION;

extern "C" {
  BOOL WINAPI InitializeCriticalSectionEx(LPCRITICAL_SECTION lpCriticalSection, DWORD dwSpinCount, DWORD Flags);
};

