#pragma once

#include "windef.h"

struct SOCKADDR {
  unsigned short sa_family;
  CHAR sa_data[14];
};

typedef SOCKADDR* PSOCKADDR;
typedef SOCKADDR* LPSOCKADDR;

struct SOCKET_ADDRESS {
  LPSOCKADDR lpSockaddr;
  INT iSockaddrLength;
};

typedef SOCKET_ADDRESS* PSOCKET_ADDRESS;
typedef SOCKET_ADDRESS* LPSOCKET_ADDRESS;
