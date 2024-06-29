#pragma once

#include <windef.h>

typedef DWORD LCTYPE;
typedef DWORD LGRPID;

struct NLSVERSIONINFO {
  DWORD dwNLSVersionInfoSize;
  DWORD dwNLSVersion;
  DWORD dwDefinedVersion;
};

typedef NLSVERSIONINFO* LPNLSVERSIONINFO;
