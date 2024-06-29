#pragma once

#include <windef.h>

struct NLSVERSIONINFO {
  DWORD dwNLSVersionInfoSize;
  DWORD dwNLSVersion;
  DWORD dwDefinedVersion;
};

typedef NLSVERSIONINFO* LPNLSVERSIONINFO;
