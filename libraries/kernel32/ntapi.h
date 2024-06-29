#pragma once

#include <windef.h>

struct PROC_THREAD_ATTRIBUTE_ENTRY {
  ULONG_PTR Attribute;
  SIZE_T cbSize;
  PVOID lpValue;
};

typedef PROC_THREAD_ATTRIBUTE_ENTRY* LPPROC_THREAD_ATTRIBUTE_ENTRY;
