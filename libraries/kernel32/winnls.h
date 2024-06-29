#pragma once

#include <windef.h>

#define MAX_DEFAULTCHAR  2
#define MAX_LEADBYTES   12

typedef DWORD LCTYPE;
typedef DWORD LGRPID;
typedef BOOL (*LOCALE_ENUMPROCW)(LPWSTR);

struct NLSVERSIONINFO {
  DWORD dwNLSVersionInfoSize;
  DWORD dwNLSVersion;
  DWORD dwDefinedVersion;
};

struct CPINFO {
  UINT MaxCharSize;
  BYTE DefaultChar[MAX_DEFAULTCHAR];
  BYTE LeadByte[MAX_LEADBYTES];
};

typedef NLSVERSIONINFO* LPNLSVERSIONINFO;

typedef CPINFO* LPCPINFO;
