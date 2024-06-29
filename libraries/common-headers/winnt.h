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
typedef DWORD        ACCESS_MASK;

typedef PVOID        HANDLE;
typedef LONG         HRESULT;
typedef BOOLEAN*     PBOOLEAN;
typedef LONG*        PLONG;
typedef LONGLONG*    PLONGLONG;
typedef SHORT*       PSHORT;
typedef LONGLONG     USN;
typedef ACCESS_MASK* PACCESS_MASK;

typedef HANDLE* PHANDLE;

struct SID_IDENTIFIER_AUTHORITY {
  BYTE Value[6];
};

struct SID {
  BYTE Revision;
  BYTE SubAuthorityCount;
  SID_IDENTIFIER_AUTHORITY IdentifierAuthority;
  DWORD SubAuthority[];
};

typedef SID_IDENTIFIER_AUTHORITY* PSID_IDENTIFIER_AUTHORITY;
typedef SID* PSID;

enum TOKEN_INFORMATION_CLASS {
  TokenUser = 1,
  TokenGroups,
  TokenPrivileges,
  TokenOwner,
  TokenPrimaryGroup,
  TokenDefaultDacl,
  TokenSource,
  TokenType,
  TokenImpersonationLevel,
  TokenStatistics,
  TokenRestrictedSids,
  TokenSessionId,
  TokenGroupsAndPrivileges,
  TokenSessionReference,
  TokenSandBoxInert,
  TokenAuditPolicy,
  TokenOrigin,
  TokenElevationType,
  TokenLinkedToken,
  TokenElevation,
  TokenHasRestrictions,
  TokenAccessInformation,
  TokenVirtualizationAllowed,
  TokenVirtualizationEnabled,
  TokenIntegrityLevel,
  TokenUIAccess,
  TokenMandatoryPolicy,
  TokenLogonSid,
  TokenIsAppContainer,
  TokenCapabilities,
  TokenAppContainerSid,
  TokenAppContainerNumber,
  TokenUserClaimAttributes,
  TokenDeviceClaimAttributes,
  TokenRestrictedUserClaimAttributes,
  TokenRestrictedDeviceClaimAttributes,
  TokenDeviceGroups,
  TokenRestrictedDeviceGroups,
  TokenSecurityAttributes,
  TokenIsRestricted,
  TokenProcessTrustLevel,
  TokenPrivateNameSpace,
  TokenSingletonAttributes,
  TokenBnoIsolation,
  TokenChildProcessFlags,
  TokenIsLessPrivilegedAppContainer,
  TokenIsSandboxed,
  TokenIsAppSilo,
  TokenLoggingInformation,
  MaxTokenInfoClass
};

typedef TOKEN_INFORMATION_CLASS* PTOKEN_INFORMATION_CLASS;

union ULARGE_INTEGER {
  struct {
    DWORD LowPart;
    DWORD HighPart;
  } DUMMYSTRUCTNAME;
  struct {
    DWORD LowPart;
    DWORD HighPart;
  } u;
  ULONGLONG QuadPart;
};

union LARGE_INTEGER {
  struct {
    DWORD LowPart;
    LONG HighPart;
  } DUMMYSTRUCTNAME;
  struct {
    DWORD LowPart;
    LONG HighPart;
  } u;
  LONGLONG QuadPart;
};

typedef ULARGE_INTEGER* PULARGE_INTEGER;
typedef LARGE_INTEGER* PLARGE_INTEGER;
