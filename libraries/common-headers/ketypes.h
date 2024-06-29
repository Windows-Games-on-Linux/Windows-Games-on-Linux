#pragma once

#include "windef.h"

struct M128A {
  ULONGLONG Low;
  LONGLONG High;
};

typedef M128A* PM128A;
