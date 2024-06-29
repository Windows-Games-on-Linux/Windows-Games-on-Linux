#pragma once

#include <windef.h>

struct LIST_ENTRY {
  LIST_ENTRY* Flink;
  LIST_ENTRY* Blink;
};

typedef LIST_ENTRY* PLIST_ENTRY;

struct RTL_CRITICAL_SECTION_DEBUG {
  WORD Type;
  WORD CreatorBackTraceIndex;
  PVOID CriticalSection;
  LIST_ENTRY ProcessLocksList;
  ULONG EntryCount;
  ULONG ContentionCount;
  ULONG Flags;
  WORD CreatorBackTraceIndexHigh;
  WORD SpareUSHORT;
};

typedef RTL_CRITICAL_SECTION_DEBUG* PRTL_CRITICAL_SECTION_DEBUG;

struct RTL_CRITICAL_SECTION {
  PRTL_CRITICAL_SECTION_DEBUG DebugInfo;
  LONG LockCount;
  LONG RecursionCount;
  PVOID OwningThread;
  PVOID LockSemaphore;
  ULONG SpinCount;
};

typedef RTL_CRITICAL_SECTION* PRTL_CRITICAL_SECTION;

union RTL_RUN_ONCE {
  PVOID Ptr;
};

union RTL_CONDITION_VARIABLE {
  PVOID Ptr;
};

union RTL_SRWLOCK {
  PVOID Ptr;
};

typedef RTL_RUN_ONCE* PRTL_RUN_ONCE;

typedef RTL_CONDITION_VARIABLE* PRTL_CONDITION_VARIABLE;

typedef RTL_SRWLOCK* PRTL_SRWLOCK;
