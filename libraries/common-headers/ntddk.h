#pragma once

#include <windef.h>

union RTL_RUN_ONCE {
  PVOID Ptr;
};

union RTL_CONDITION_VARIABLE {
  PVOID Ptr;
};

typedef RTL_RUN_ONCE* PRTL_RUN_ONCE;

typedef RTL_CONDITION_VARIABLE* PRTL_CONDITION_VARIABLE;
