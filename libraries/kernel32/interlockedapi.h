#pragma once

#include "wdm.h"

extern "C" {
  void __attribute__((stdcall)) InitializeSListHead(PSLIST_HEADER ListHead);
};

