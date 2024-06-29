#pragma once

#include <windef.h>

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
