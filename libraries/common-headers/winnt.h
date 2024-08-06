#pragma once

#include <cstdint>
#include <cuchar>
#include "intsafe.h"

#define VOID void

#define CONTEXT_AMD64 0x00100000
#define CONTEXT_i386  0x00010000

#define EXCEPTION_MAXIMUM_PARAMETERS 15

#define EXCEPTION_ACCESS_VIOLATION         0xC0000005
#define EXCEPTION_ARRAY_BOUNDS_EXCEEDED    0xC000008C
#define EXCEPTION_BREAKPOINT               0x80000003
#define EXCEPTION_DATATYPE_MISALIGNMENT    0x80000002
#define EXCEPTION_FLT_DENORMAL_OPERAND     0xC000008D
#define EXCEPTION_FLT_DIVIDE_BY_ZERO       0xC000008E
#define EXCEPTION_FLT_INEXACT_RESULT       0xC000008F
#define EXCEPTION_FLT_INVALID_OPERATION    0xC0000090
#define EXCEPTION_FLT_OVERFLOW             0xC0000091
#define EXCEPTION_FLT_STACK_CHECK          0xC0000092
#define EXCEPTION_FLT_UNDERFLOW            0xC0000093
#define EXCEPTION_ILLEGAL_INSTRUCTION      0xC000001D
#define EXCEPTION_IN_PAGE_ERROR            0xC0000006
#define EXCEPTION_INT_DIVIDE_BY_ZERO       0xC0000094
#define EXCEPTION_INT_OVERFLOW             0xC0000095
#define EXCEPTION_INVALID_DISPOSITION      0xC0000026
#define EXCEPTION_NONCONTINUABLE_EXCEPTION 0xC0000025
#define EXCEPTION_PRIV_INSTRUCTION         0xC0000096
#define EXCEPTION_SINGLE_STEP              0x80000004
#define EXCEPTION_STACK_OVERFLOW           0xC00000FD

#define EXCEPTION_NONCONTINUABLE     0x01
#define EXCEPTION_SOFTWARE_ORIGINATE 0x80

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
typedef char16_t     WCHAR;
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
typedef WCHAR*       LPWCH;
typedef CONST WCHAR* LPCWCH;
typedef CONST CHAR*  LPCCH;

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

struct SLIST_ENTRY {
  SLIST_ENTRY* Next;
};

struct MEMORY_BASIC_INFORMATION {
  PVOID BaseAddress;
  PVOID AllocationBase;
  DWORD AllocationProtect;
  WORD PartitionId;
  SIZE_T RegionSize;
  DWORD State;
  DWORD Protect;
  DWORD Type;
};

struct OSVERSIONINFOEXW {
  DWORD dwOSVersionInfoSize;
  DWORD dwMajorVersion;
  DWORD dwMinorVersion;
  DWORD dwBuildNumber;
  DWORD dwPlatformId;
  WCHAR szCSDVersion[128];
  WORD wServicePackMajor;
  WORD wServicePackMinor;
  WORD wSuiteMask;
  BYTE wProductType;
  BYTE wReserved;
};

struct OSVERSIONINFOA {
  DWORD dwOSVersionInfoSize;
  DWORD dwMajorVersion;
  DWORD dwMinorVersion;
  DWORD dwBuildNumber;
  DWORD dwPlatformId;
  CHAR szCSDVersion[128];
};

struct OSVERSIONINFOW {
  DWORD dwOSVersionInfoSize;
  DWORD dwMajorVersion;
  DWORD dwMinorVersion;
  DWORD dwBuildNumber;
  DWORD dwPlatformId;
  WCHAR szCSDVersion[128];
};

#include "ke.h"

struct EXCEPTION_RECORD {
  DWORD ExceptionCode;
  DWORD ExceptionFlags;
  EXCEPTION_RECORD* ExceptionRecord;
  PVOID ExceptionAddress;
  DWORD NumberParameters;
  ULONG_PTR ExceptionInformation[EXCEPTION_MAXIMUM_PARAMETERS];
};

struct NEON128 {
  ULONGLONG Low;
  LONGLONG High;
};

typedef EXCEPTION_RECORD* PEXCEPTION_RECORD;
typedef NEON128* PNEON128;

struct CONTEXT {
  DWORD64 P1Home;
  DWORD64 P2Home;
  DWORD64 P3Home;
  DWORD64 P4Home;
  DWORD64 P5Home;
  DWORD64 P6Home;
  DWORD ContextFlags;
  DWORD MxCsr;
  WORD SegCs;
  WORD SegDs;
  WORD SegEs;
  WORD SegFs;
  WORD SegGs;
  WORD SegSs;
  DWORD EFlags;
  DWORD64 Dr0;
  DWORD64 Dr1;
  DWORD64 Dr2;
  DWORD64 Dr3;
  DWORD64 Dr6;
  DWORD64 Dr7;
  DWORD64 Rax;
  DWORD64 Rcx;
  DWORD64 Rdx;
  DWORD64 Rbx;
  DWORD64 Rsp;
  DWORD64 Rbp;
  DWORD64 Rsi;
  DWORD64 Rdi;
  DWORD64 R8;
  DWORD64 R9;
  DWORD64 R10;
  DWORD64 R11;
  DWORD64 R12;
  DWORD64 R13;
  DWORD64 R14;
  DWORD64 R15;
  DWORD64 Rip;
  union {
    XMM_SAVE_AREA32 FltSave;
    NEON128 Q[16];
    ULONGLONG D[32];
    struct {
      M128A Header[2];
      M128A Legacy[8];
      M128A Xmm0;
      M128A Xmm1;
      M128A Xmm2;
      M128A Xmm3;
      M128A Xmm4;
      M128A Xmm5;
      M128A Xmm6;
      M128A Xmm7;
      M128A Xmm8;
      M128A Xmm9;
      M128A Xmm10;
      M128A Xmm11;
      M128A Xmm12;
      M128A Xmm13;
      M128A Xmm14;
      M128A Xmm15;
    } DUMMYSTRUCTNAME;
    DWORD S[32];
  } DUMMYUNIONNAME;
  M128A VectorRegister[26];
  DWORD64 VectorControl;
  DWORD64 DebugControl;
  DWORD64 LastBranchToRip;
  DWORD64 LastBranchFromRip;
  DWORD64 LastExceptionToRip;
  DWORD64 LastExceptionFromRip;
};

typedef CONTEXT* PCONTEXT;

struct EXCEPTION_POINTERS {
  PEXCEPTION_RECORD ExceptionRecord;
  PCONTEXT ContextRecord;
};

typedef EXCEPTION_POINTERS* PEXCEPTION_POINTERS;

#include "excpt.h"

struct RUNTIME_FUNCTION {
  ULONG BeginAddress;
  ULONG EndAddress;
  ULONG UnwindInfoAddress;
};

typedef RUNTIME_FUNCTION* PRUNTIME_FUNCTION;

struct UNWIND_HISTORY_TABLE_ENTRY {
  ULONG64 ImageBase;
  PRUNTIME_FUNCTION FunctionEntry;
};

struct UNWIND_HISTORY_TABLE {
  ULONG Count;
  UCHAR Search;
  ULONG64 LowAddress;
  ULONG64 HighAddress;
  UNWIND_HISTORY_TABLE_ENTRY Entry[];
};

typedef SID_IDENTIFIER_AUTHORITY* PSID_IDENTIFIER_AUTHORITY;
typedef SID* PSID;

typedef SLIST_ENTRY* PSLIST_ENTRY;

typedef MEMORY_BASIC_INFORMATION* PMEMORY_BASIC_INFORMATION;

typedef OSVERSIONINFOEXW* POSVERSIONINFOEXW;
typedef OSVERSIONINFOEXW* LPOSVERSIONINFOEXW;

typedef OSVERSIONINFOA* POSVERSIONINFOA;
typedef OSVERSIONINFOA* LPOSVERSIONINFOA;

typedef OSVERSIONINFOW* POSVERSIONINFOW;
typedef OSVERSIONINFOW* LPOSVERSIONINFOW;

typedef UNWIND_HISTORY_TABLE_ENTRY* PUNWIND_HISTORY_TABLE_ENTRY;
typedef UNWIND_HISTORY_TABLE*       PUNWIND_HISTORY_TABLE;

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

typedef void (*PFLS_CALLBACK_FUNCTION)(PVOID);

