#pragma once

#include "intsafe.h"

struct FILETIME {
  DWORD dwLodDateTime;
  DWORD dwHighDateTime;
};

typedef FILETIME* PFILETIME;
typedef FILETIME* LPFILETIME;
