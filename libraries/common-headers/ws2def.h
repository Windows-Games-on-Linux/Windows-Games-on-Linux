#pragma once

#include "windef.h"

struct SOCKADDR {
  unsigned short sa_family;
  CHAR sa_data[14];
};

typedef SOCKADDR* PSOCKADDR;
typedef SOCKADDR* LPSOCKADDR;
