#pragma once

#include <cstdint>

#define POINTER_32
#define POINTER_64
#define POINTER_SIGNED
#define POINTER_UNSIGNED

typedef unsigned long  ULONG_PTR;
typedef unsigned int   DWORD32;
typedef uint64_t       DWORD64;
typedef short          HALF_PTR;
typedef int            INT_PTR;
typedef signed char    INT8;
typedef signed short   INT16;
typedef signed int     INT32;
typedef int64_t        INT64;
typedef long           LONG_PTR;
typedef signed int     LONG32;
typedef int64_t        LONG64;
typedef unsigned short UHALF_PTR;
typedef unsigned int   UINT_PTR;
typedef unsigned char  UINT8;
typedef unsigned short UINT16;
typedef unsigned int   UINT32;
typedef uint64_t       UINT64;
typedef unsigned int   ULONG32;
typedef uint64_t       ULONG64;

typedef ULONG_PTR  DWORD_PTR;
typedef DWORD32*   PDWORD32;
typedef DWORD64*   PDWORD64;
typedef HALF_PTR*  PHALF_PTR;
typedef INT_PTR*   PINT_PTR;
typedef INT8*      PINT8;
typedef INT16*     PINT16;
typedef INT32*     PINT32;
typedef INT64*     PINT64;
typedef LONG_PTR*  PLONG_PTR;
typedef LONG32*    PLONG32;
typedef LONG64*    PLONG64;
typedef ULONG_PTR  SIZE_T;
typedef LONG_PTR   SSIZE_T;
typedef UHALF_PTR* PUHALF_PTR;
typedef UINT_PTR*  PUINT_PTR;
typedef UINT8*     PUINT8;
typedef UINT16*    PUINT16;
typedef UINT32*    PUINT32;
typedef UINT64*    PUINT64;
typedef ULONG_PTR* PULONG_PTR;
typedef ULONG32*   PULONG32;
typedef ULONG64*   PULONG64;

typedef DWORD_PTR* PDWORD_PTR;
typedef SIZE_T*    PSIZE_T;
typedef SSIZE_T*   PSSIZE_T;