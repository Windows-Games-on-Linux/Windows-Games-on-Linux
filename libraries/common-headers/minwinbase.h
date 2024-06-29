#pragma once

//This file will be included by windef.h after all necessary types are defined

#define IO_REPARSE_TAG_CSV         0x80000009
#define IO_REPARSE_TAG_DEDUP       0x80000013
#define IO_REPARSE_TAG_DFS         0x8000000A
#define IO_REPARSE_TAG_DFSR        0x80000012
#define IO_REPARSE_TAG_HSM         0xC0000004
#define IO_REPARSE_TAG_HSM2        0x80000006
#define IO_REPARSE_TAG_MOUNT_POINT 0xA0000003
#define IO_REPARSE_TAG_NFS         0x80000014
#define IO_REPARSE_TAG_SIS         0x80000007
#define IO_REPARSE_TAG_SYMLINK     0xA000000C
#define IO_REPARSE_TAG_WIM         0x80000008

struct FILETIME {
  DWORD dwLodDateTime;
  DWORD dwHighDateTime;
};

struct SYSTEMTIME {
  WORD wYear;
  WORD wMonth;
  WORD wDayOfWeek;
  WORD wDay;
  WORD wHour;
  WORD wMinute;
  WORD wSecond;
  WORD wMilliseconds;
};

struct WIN32_FIND_DATAW {
  DWORD dwFileAttributes;
  FILETIME ftCreationTime;
  FILETIME ftLastAccessTime;
  FILETIME ftLastWriteTime;
  DWORD nFileSizeHigh;
  DWORD nFileSizeLow;
  DWORD dwReserved0;
  DWORD dwReserved1;
  CHAR cFileName[MAX_PATH];
  CHAR cAlternateFileName[14];
  DWORD dwFileType;
  DWORD dwCreatorType;
  WORD wFinderFlags;
};

struct OVERLAPPED {
  ULONG_PTR Internal;
  ULONG_PTR InternalHigh;
  union {
    struct {
      DWORD Offset;
      DWORD OffsetHigh;
    };
    PVOID Pointer;
  } DUMMYUNIONNAME;
  HANDLE hEvent;
};

typedef FILETIME* PFILETIME;
typedef FILETIME* LPFILETIME;

typedef SYSTEMTIME* PSYSTEMTIME;
typedef SYSTEMTIME* LPSYSTEMTIME;

typedef WIN32_FIND_DATAW* PWIN32_FIND_DATAW;
typedef WIN32_FIND_DATAW* LPWIN32_FIND_DATAW;

typedef OVERLAPPED* LPOVERLAPPED;

enum GET_FILEEX_INFO_LEVELS {
  GetFileExInfoStandard,
  GetFileExMaxInfoLevel
};

enum FINDEX_INFO_LEVELS {
  FindExInfoStandard,
  FindExInfoBasic,
  FindExInfoMaxInfoLevel
};
