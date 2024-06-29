#pragma once

#include <windef.h>

union RTL_RUN_ONCE {
  PVOID Ptr;
};

typedef RTL_RUN_ONCE* PRTL_RUN_ONCE;
