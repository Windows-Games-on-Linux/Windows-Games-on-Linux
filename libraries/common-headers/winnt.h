#pragma once

#include <cstdint>
#include "intsafe.h"

#define VOID void

/*
  winnt.h and windef.h are dependent on each other
  BYTE and all the other types from which new types are derived here,
  will already exist because windef.h will include this header
  after declaring them
*/
typedef BYTE         BOOLEAN;
typedef char         CCHAR;
typedef char         CHAR;
typedef void*        PVOID;
typedef long         LONG;
typedef WORD         LANGID;
typedef DWORD        LCID;
typedef int64_t      LONGLONG;
typedef CONST CHAR*  LPCSTR;
typedef wchar_t      WCHAR;
typedef CONST WCHAR* LPCWSTR;
typedef CHAR*        LPSTR;
typedef WCHAR*       LPWSTR;
typedef CHAR*        PCHAR;
typedef CONST CHAR*  PCSTR;
typedef CONST WCHAR* PCWSTR;
typedef DWORDLONG*   PDWORDLONG;
typedef PDWORD       PLCID;
typedef short        SHORT;
typedef CHAR*        PSTR;
typedef WCHAR*       PWCHAR;
typedef WCHAR*       PWSTR;
typedef uint64_t     ULONGLONG;

typedef PVOID     HANDLE;
typedef LONG      HRESULT;
typedef BOOLEAN*  PBOOLEAN;
typedef LONG*     PLONG;
typedef LONGLONG* PLONGLONG;
typedef SHORT*    PSHORT;
typedef LONGLONG  USN;

typedef HANDLE* PHANDLE;
