#pragma once

#include <windef.h>

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
