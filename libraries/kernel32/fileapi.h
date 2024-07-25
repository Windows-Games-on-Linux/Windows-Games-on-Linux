#pragma once

#include <windef.h>

#define FILE_TYPE_CHAR    0x0002
#define FILE_TYPE_DISK    0x0001
#define FILE_TYPE_PIPE    0x0003
#define FILE_TYPE_REMOTE  0x8000
#define FILE_TYPE_UNKNOWN 0x0000

struct BY_HANDLE_FILE_INFORMATION {
  DWORD dwFileAttributes;
  FILETIME ftCreationTime;
  FILETIME ftLastAccessTime;
  FILETIME ftLastWriteTime;
  DWORD dwVolumeSerialNumber;
  DWORD nFileSizeHigh;
  DWORD nFileSizeLow;
  DWORD nNumberOfLinks;
  DWORD nFileIndexHigh;
  DWORD nFileIndexLow;
};

typedef BY_HANDLE_FILE_INFORMATION* PBY_HANDLE_FILE_INFORMATION;
typedef BY_HANDLE_FILE_INFORMATION* LPBY_HANDLE_FILE_INFORMATION;

extern "C" {
  DWORD __attribute__((stdcall)) GetFileType(HANDLE hFile);
};

